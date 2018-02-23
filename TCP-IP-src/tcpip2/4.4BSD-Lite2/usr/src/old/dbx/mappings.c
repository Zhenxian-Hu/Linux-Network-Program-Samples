/*
 * Copyright (c) 1983 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef lint
static char sccsid[] = "@(#)mappings.c	5.5 (Berkeley) 6/1/90";
#endif /* not lint */

/*
 * Source-to-object and vice versa mappings.
 */

#include "defs.h"
#include "mappings.h"
#include "symbols.h"
#include "source.h"
#include "object.h"
#include "machine.h"

#ifndef public
#include "machine.h"
#include "source.h"
#include "symbols.h"

typedef struct {
    Address addr;
    String filename;
    Lineno lineindex;		/* index to first linetab entry */
} Filetab;

typedef struct {
    Lineno line;
    Address addr;
} Linetab;

Filetab *filetab;
Linetab *linetab;

#define NOADDR ((Address) -1)	/* no address for line or procedure */

#endif

/*
 * Get the source file name associated with a given address.
 */

public String srcfilename(addr)
Address addr;
{
    register Address i, j, k;
    Address a;
    Filetab *ftp;
    String s;

    s = nil;
    if (nlhdr.nfiles != 0 and addr >= filetab[0].addr) {
	i = 0;
	j = nlhdr.nfiles - 1;
	while (i < j) {
	    k = (i + j) / 2;
	    ftp = &filetab[k];
	    a = ftp->addr;
	    if (a == addr) {
		s = ftp->filename;
		break;
	    } else if (addr > a) {
		i = k + 1;
	    } else {
		j = k - 1;
	    }
	}
	if (s == nil) {
	    if (addr >= filetab[i].addr) {
		s = filetab[i].filename;
	    } else {
		s = filetab[i-1].filename;
	    }
	}
    }
    return s;
}

/*
 * Find the line associated with the given address.
 * If the second parameter is true, then the address must match
 * a source line exactly.  Otherwise the nearest source line
 * below the given address is returned.
 *
 * Return the index of the line table entry or -1 if none suitable.
 */

private integer findline (addr, exact)
Address addr;
Boolean exact;
{
    register Address i, j, k;
    register Lineno r;
    register Address a;

    if (nlhdr.nlines == 0 or addr < linetab[0].addr) {
	r = -1;
    } else {
	i = 0;
	j = nlhdr.nlines - 1;
	if (addr == linetab[i].addr) {
	    r = i;
	} else if (addr == linetab[j].addr) {
	    r = j;
	} else if (addr > linetab[j].addr) {
	    r = exact ? -1 : j;
	} else {
	    do {
		k = (i + j) div 2;
		a = linetab[k].addr;
	    if (a == addr) break;
		if (addr > a) {
		    i = k + 1;
		} else {
		    j = k - 1;
		}
	    } while (i <= j);
	    if (a == addr) {
		r = k;
	    } else if (exact) {
		r = -1;
	    } else if (addr > linetab[i].addr) {
		r = i;
	    } else {
		r = i - 1;
	    }
	}
    }
    return r;
}

/*
 * Lookup the source line number nearest (from below) to an address.
 *
 * It is possible (unfortunately) that the compiler will generate
 * code before line number for a procedure.  Therefore we check
 * to see that the found line is in the same procedure as the given address.
 * If it isn't, then we walk forward until the first suitable line is found.
 */

public Lineno srcline (addr)
Address addr;
{
    Lineno i, r;
    Symbol f1, f2;
    Address a;

    i = findline(addr, false);
    if (i == -1) {
	f1 = whatblock(addr);
	if (f1 == nil or nosource(f1)) {
	    r = 0;
	} else {
	    a = codeloc(f1);
	    for (;;) {
		r = linelookup(a);
		if (r != 0 or a >= CODESTART + objsize) {
		    break;
		}
		++a;
	    }
	}
    } else {
	r = linetab[i].line;
	if (linetab[i].addr != addr) {
	    f1 = whatblock(addr);
	    if (nosource(f1)) {
		r = 0;
	    } else {
		f2 = whatblock(linetab[i].addr + 1);
		if (f1 != f2) {
		    do {
			++i;
		    } while (linetab[i].addr < addr and i < nlhdr.nlines);
		    r = linetab[i].line;
		}
	    }
	}
    }
    return r;
}

/*
 * Look for a line exactly corresponding to the given address.
 */

public Lineno linelookup(addr)
Address addr;
{
    integer i;
    Lineno r;

    i = findline(addr, true);
    if (i == -1) {
	r = 0;
    } else {
	r = linetab[i].line;
    }
    return r;
}

/*
 * Lookup the object address of a given line from the named file.
 *
 * Potentially all files in the file table need to be checked
 * until the line is found since a particular file name may appear
 * more than once in the file table (caused by includes).
 */

public Address objaddr(line, name)
Lineno line;
String name;
{
    register Filetab *ftp;
    register Lineno i, j;
    Boolean foundfile;

    if (nlhdr.nlines == 0) {
	return NOADDR;
    }
    if (name == nil) {
	name = cursource;
    }
    foundfile = false;
    for (ftp = &filetab[0]; ftp < &filetab[nlhdr.nfiles]; ftp++) {
	if (streq(ftp->filename, name)) {
	    foundfile = true;
	    i = ftp->lineindex;
	    if (ftp == &filetab[nlhdr.nfiles-1]) {
		j = nlhdr.nlines;
	    } else {
		j = (ftp + 1)->lineindex;
	    }
	    while (i < j) {
		if (linetab[i].line == line) {
		    return linetab[i].addr;
		}
		i++;
	    }
	}
    }
    if (not foundfile) {
	error("source file \"%s\" not compiled with -g", name);
    }
    return NOADDR;
}

/*
 * Table for going from object addresses to the functions in which they belong.
 */

#define NFUNCS 500	/* initial size of function table */

typedef struct {
    Symbol func;
    Address addr;
} AddrOfFunc;

private AddrOfFunc *functab;
private int nfuncs = 0;
private int functablesize = 0;

/*
 * Insert a new function into the table.
 */

public newfunc(f, addr)
Symbol f;
Address addr;
{
    register AddrOfFunc *af;
    register int i;
    AddrOfFunc *newfunctab;

    if (nfuncs >= functablesize) {
	if (functablesize == 0) {
	    functab = newarr(AddrOfFunc, NFUNCS);
	    functablesize = NFUNCS;
	} else {
	    functablesize *= 2;
	    newfunctab = newarr(AddrOfFunc, functablesize);
	    bcopy(functab, newfunctab, nfuncs * sizeof(AddrOfFunc));
	    dispose(functab);
	    functab = newfunctab;
	}
    }
    af = &functab[nfuncs];
    af->func = f;
    af->addr = addr;
    ++nfuncs;
}

/*
 * Return the function that begins at the given address.
 */

public Symbol whatblock(addr)
Address addr;
{
    register int i, j, k;
    Address a;

    i = 0;
    j = nfuncs - 1;
    if (addr < functab[i].addr) {
	return program;
    } else if (addr == functab[i].addr) {
	return functab[i].func;
    } else if (addr >= functab[j].addr) {
	return functab[j].func;
    }
    while (i <= j) {
	k = (i + j) / 2;
	a = functab[k].addr;
	if (a == addr) {
	    return functab[k].func;
	} else if (addr > a) {
	    i = k+1;
	} else {
	    j = k-1;
	}
    }
    if (addr > functab[i].addr) {
	return functab[i].func;
    } else {
	return functab[i-1].func;
    }
    /* NOTREACHED */
}

/*
 * Order the functab.
 */

private int cmpfunc(f1, f2)
AddrOfFunc *f1, *f2;
{
    register Address a1, a2;

    a1 = (*f1).addr;
    a2 = (*f2).addr;
    return ( (a1 < a2) ? -1 : ( (a1 == a2) ? 0 : 1 ) );
}

public ordfunctab()
{
    qsort(functab, nfuncs, sizeof(AddrOfFunc), cmpfunc);
}

/*
 * Clear out the functab, used when re-reading the object information.
 */

public clrfunctab()
{
    nfuncs = 0;
}

public dumpfunctab()
{
    int i;

    for (i = 0; i < nfuncs; i++) { 
	psym(functab[i].func);
    }
}
