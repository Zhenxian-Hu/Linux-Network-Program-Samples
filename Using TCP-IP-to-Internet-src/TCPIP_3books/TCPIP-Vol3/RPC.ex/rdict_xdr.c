/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rdict.h"

bool_t
xdr_example(xdrs, objp)
	register XDR *xdrs;
	example *objp;
{

	register long *buf;

	if (!xdr_int(xdrs, &objp->exfield1))
		return (FALSE);
	if (!xdr_char(xdrs, &objp->exfield2))
		return (FALSE);
	return (TRUE);
}
