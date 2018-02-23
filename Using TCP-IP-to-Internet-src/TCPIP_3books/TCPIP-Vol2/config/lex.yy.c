/* A lexical scanner generated by flex */

/* Scanner skeleton version:
 * $Header: /usr/home/dls/books/v2/xinu/config/RCS/lex.yy.c,v 1.1 1997/09/21 19:24:14 dls Dist dls $
 */

#define FLEX_SCANNER

#include <stdio.h>


/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif


#ifdef __cplusplus

#include <stdlib.h>
#include <unistd.h>

/* Use prototypes in function declarations. */
#define YY_USE_PROTOS

/* The "const" storage-class-modifier is valid. */
#define YY_USE_CONST

#else	/* ! __cplusplus */

#ifdef __STDC__

#define YY_USE_PROTOS
#define YY_USE_CONST

#endif	/* __STDC__ */
#endif	/* ! __cplusplus */


#ifdef __TURBOC__
#define YY_USE_CONST
#endif


#ifndef YY_USE_CONST
#ifndef const
#define const
#endif
#endif


#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif

/* Returned upon end-of-file. */
#define YY_NULL 0

/* Promotes a possibly negative, possibly signed char to an unsigned
 * integer for use as an array index.  If the signed char is negative,
 * we want to instead treat it as an 8-bit unsigned char, hence the
 * double cast.
 */
#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)

/* Enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN.
 */
#define BEGIN yy_start = 1 + 2 *

/* Translate the current start state into a value that can be later handed
 * to BEGIN to return to the state.
 */
#define YY_START ((yy_start - 1) / 2)

/* Action number for EOF rule of a given start state. */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* Special action meaning "start processing a new file".  Now included
 * only for backward compatibility with previous versions of flex.
 */
#define YY_NEW_FILE yyrestart( yyin )

#define YY_END_OF_BUFFER_CHAR 0

/* Size of default input buffer. */
#define YY_BUF_SIZE 16384

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyleng;
extern FILE *yyin, *yyout;

#ifdef __cplusplus
extern "C" {
#endif
	extern int yywrap YY_PROTO(( void ));
#ifdef __cplusplus
	}
#endif

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* The funky do-while in the following #define is used to turn the definition
 * int a single C statement (which needs a semi-colon terminator).  This
 * avoids problems with code like:
 *
 * 	if ( condition_holds )
 *		yyless( 5 );
 *	else
 *		do_something_else();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the yyless() call.
 */

/* Return all but the first 'n' matched characters back to the input stream. */

#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		*yy_cp = yy_hold_char; \
		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yytext_ptr )


struct yy_buffer_state
	{
	FILE *yy_input_file;

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	int yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	int yy_n_chars;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	/* Whether we've seen an EOF on this buffer. */
	int yy_eof_status;
#define EOF_NOT_SEEN 0
	/* "Pending" happens when the EOF has been seen but there's still
	 * some text to process.  Note that when we actually see the EOF,
	 * we switch the status back to "not seen" (via yyrestart()), so
	 * that the user can continue scanning by just pointing yyin at
	 * a new input file.
	 */
#define EOF_PENDING 1
	};

static YY_BUFFER_STATE yy_current_buffer = 0;

/* We provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state".
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed. */
static char yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */


int yyleng;

/* Points to current character in buffer. */
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* Flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

static void yyunput YY_PROTO(( int c, char *buf_ptr ));
void yyrestart YY_PROTO(( FILE *input_file ));
void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));
void yy_load_buffer_state YY_PROTO(( void ));
YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));
void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));
void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));

static int yy_start_stack_ptr = 0;
static int yy_start_stack_depth = 0;
static int *yy_start_stack = 0;
static void yy_push_state YY_PROTO(( int new_state ));
static void yy_pop_state YY_PROTO(( void ));
static int yy_top_state YY_PROTO(( void ));

#ifndef yytext_ptr
static void yy_flex_strcpy YY_PROTO(( char *, const char * ));
#endif

static void *yy_flex_alloc YY_PROTO(( unsigned int ));
static void *yy_flex_realloc YY_PROTO(( void *ptr, unsigned int ));
static void yy_flex_free YY_PROTO(( void * ));

#define yy_new_buffer yy_create_buffer

#define INITIAL 0
typedef unsigned char YY_CHAR;
typedef int yy_state_type;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
extern char *yytext;
#define yytext_ptr yytext

#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif

static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
static int yy_get_next_buffer YY_PROTO(( void ));
static void yy_fatal_error YY_PROTO(( const char msg[] ));

/* Done after the current pattern has been matched and before the
 * corresponding action - sets up yytext.
 */
#define YY_DO_BEFORE_ACTION \
	yytext_ptr = yy_bp; \
	yyleng = yy_cp - yy_bp; \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define YY_END_OF_BUFFER 31
static const short int yy_accept[77] =
    {   0,
        0,    0,   31,   29,   26,   27,    3,   29,   29,   29,
        6,    5,    4,   10,   28,   19,   21,   17,   25,   18,
       22,   20,   24,   23,   26,    2,   19,   21,   17,   25,
       18,   22,   20,   24,   23,    1,    6,    0,    5,   28,
       28,   28,   28,    8,   28,   28,    9,   28,    0,    0,
        0,    0,    0,    0,    7,   13,   28,   15,   28,   28,
       28,   13,    0,   15,    0,    0,    0,   11,   14,   12,
       16,   11,   14,   12,   16,    0
    } ;

static const int yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    1,    1,    1,    1,    4,    1,    1,    1,
        1,    5,    1,    1,    6,    1,    7,    8,    9,    9,
        9,    9,    9,    9,    9,   10,   10,   11,    1,    1,
       12,    1,    1,    1,   13,   13,   13,   13,   13,   13,
       14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
       14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
        1,    1,    1,    1,   14,    1,   13,   13,   15,   13,

       16,   13,   17,   14,   18,   14,   14,   14,   14,   19,
       20,   21,   22,   23,   24,   25,   14,   26,   27,   28,
       14,   14,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static const int yy_meta[29] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    2,    2,    2,
        1,    1,    2,    3,    2,    2,    3,    3,    3,    3,
        3,    3,    3,    3,    3,    3,    3,    3
    } ;

static const short int yy_base[79] =
    {   0,
        0,    0,   90,   91,   87,   91,   91,   81,   14,   82,
       31,   34,   91,   91,    0,   62,    0,   27,    0,   28,
        0,    0,    0,    0,   83,   91,   60,   91,   34,   91,
       30,   91,   91,   91,   91,   91,   53,    0,   55,    0,
       60,   63,   59,    0,   64,   60,    0,   62,   54,   57,
       53,   58,   54,   56,    0,    0,   46,    0,   55,   44,
       53,   91,   33,   91,   40,   24,   21,    0,    0,    0,
        0,   91,   91,   91,   91,   91,   64,   28
    } ;

static const short int yy_def[79] =
    {   0,
       76,    1,   76,   76,   76,   76,   76,   76,   76,   76,
       76,   76,   76,   76,   77,   77,   77,   77,   77,   77,
       77,   77,   77,   77,   76,   76,   76,   76,   76,   76,
       76,   76,   76,   76,   76,   76,   76,   78,   76,   77,
       77,   77,   77,   77,   77,   77,   77,   77,   76,   76,
       76,   76,   76,   76,   78,   77,   77,   77,   77,   77,
       77,   76,   76,   76,   76,   76,   76,   77,   77,   77,
       77,   76,   76,   76,   76,    0,   76,   76
    } ;

static const short int yy_nxt[120] =
    {   0,
        4,    5,    6,    7,    8,    9,   10,   11,   12,   12,
       13,   14,   15,   15,   16,   15,   17,   18,   19,   20,
       21,   15,   22,   23,   15,   15,   24,   15,   27,   55,
       28,   29,   30,   31,   32,   75,   33,   34,   37,   37,
       35,   39,   39,   39,   42,   46,   47,   53,   74,   43,
       44,   50,   45,   48,   73,   54,   51,   72,   38,   52,
       37,   37,   39,   39,   39,   40,   40,   71,   70,   69,
       68,   67,   66,   65,   64,   63,   62,   61,   60,   59,
       58,   57,   56,   49,   25,   41,   36,   26,   25,   76,
        3,   76,   76,   76,   76,   76,   76,   76,   76,   76,

       76,   76,   76,   76,   76,   76,   76,   76,   76,   76,
       76,   76,   76,   76,   76,   76,   76,   76,   76
    } ;

static const short int yy_chk[120] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    9,   78,
        9,    9,    9,    9,    9,   67,    9,    9,   11,   11,
        9,   12,   12,   12,   18,   20,   20,   31,   66,   18,
       18,   29,   18,   20,   65,   31,   29,   63,   11,   29,
       37,   37,   39,   39,   39,   77,   77,   61,   60,   59,
       57,   54,   53,   52,   51,   50,   49,   48,   46,   45,
       43,   42,   41,   27,   25,   16,   10,    8,    5,    3,
       76,   76,   76,   76,   76,   76,   76,   76,   76,   76,

       76,   76,   76,   76,   76,   76,   76,   76,   76,   76,
       76,   76,   76,   76,   76,   76,   76,   76,   76
    } ;

static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;

/* The intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed.
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
char *yytext;
# line 1 "config.l"
int skipping;

/* Macros after this point can all be overridden by user definitions in
 * section 1.
 */

#ifdef YY_MALLOC_DECL
YY_MALLOC_DECL
#else
#if __STDC__
#ifndef __cplusplus
#include <stdlib.h>
#endif
#else
/* Just try to get by without declaring the routines.  This will fail
 * miserably on non-ANSI systems for which sizeof(size_t) != sizeof(int)
 * or sizeof(void*) != sizeof(int).
 */
#endif
#endif

/* Amount of stuff to slurp up with each read. */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* Copy whatever the last rule matched to the standard output. */

#ifndef ECHO
/* This used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite().
 */
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#endif

/* Gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( yy_current_buffer->yy_is_interactive ) \
		{ \
		int c = getc( yyin ); \
		result = c == EOF ? 0 : 1; \
		buf[0] = (char) c; \
		} \
	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
		  && ferror( yyin ) ) \
		YY_FATAL_ERROR( "input in flex scanner failed" );
#endif

/* No semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#ifndef yyterminate
#define yyterminate() return YY_NULL
#endif

/* Number of entries by which start-condition stack grows. */
#ifndef YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#endif

/* Report a fatal error. */
#ifndef YY_FATAL_ERROR
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
#endif

/* Default declaration of generated scanner - a define so the user can
 * easily add parameters.
 */
#ifndef YY_DECL
#define YY_DECL int yylex YY_PROTO(( void ))
#endif

/* Code executed at the beginning of each rule, after yytext and yyleng
 * have been set up.
 */
#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

/* Code executed at the end of each rule. */
#ifndef YY_BREAK
#define YY_BREAK break;
#endif

YY_DECL
	{
	register yy_state_type yy_current_state;
	register char *yy_cp, *yy_bp;
	register int yy_act;

# line 4 "config.l"


	if ( yy_init )
		{
#ifdef YY_USER_INIT
		YY_USER_INIT;
#endif

		if ( ! yy_start )
			yy_start = 1;	/* first start state */

		if ( ! yyin )
			yyin = stdin;

		if ( ! yyout )
			yyout = stdout;

		if ( yy_current_buffer )
			yy_init_buffer( yy_current_buffer, yyin );
		else
			yy_current_buffer =
				yy_create_buffer( yyin, YY_BUF_SIZE );

		yy_load_buffer_state();

		yy_init = 0;
		}

	while ( 1 )		/* loops until end-of-file is reached */
		{
		yy_cp = yy_c_buf_p;

		/* Support of yytext. */
		*yy_cp = yy_hold_char;

		/* yy_bp points to the position in yy_ch_buf of the start of
		 * the current run.
		 */
		yy_bp = yy_cp;

		yy_current_state = yy_start;
yy_match:
		do
			{
			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
			if ( yy_accept[yy_current_state] )
				{
				yy_last_accepting_state = yy_current_state;
				yy_last_accepting_cpos = yy_cp;
				}
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 77 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			++yy_cp;
			}
		while ( yy_base[yy_current_state] != 91 );

yy_find_action:
		yy_act = yy_accept[yy_current_state];

		YY_DO_BEFORE_ACTION;


do_action:	/* This label is used only to access EOF actions. */


		switch ( yy_act )
	{ /* beginning of action switch */
			case 0: /* must back up */
			/* undo the effects of YY_DO_BEFORE_ACTION */
			*yy_cp = yy_hold_char;
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			goto yy_find_action;

case 1:
YY_USER_ACTION
# line 5 "config.l"
{skipping = 1;}
	YY_BREAK
case 2:
YY_USER_ACTION
# line 6 "config.l"
{skipping = 0;}
	YY_BREAK
case 3:
YY_USER_ACTION
# line 7 "config.l"
{extern	int	brkcount;
			 if (! skipping)
				if (++brkcount == 2)
					return 0; /* end-of-file */
				else
					return DEFBRK;
			}
	YY_BREAK
case 4:
YY_USER_ACTION
# line 14 "config.l"
{if (! skipping) return COLON;}
	YY_BREAK
case 5:
YY_USER_ACTION
# line 15 "config.l"
{if (! skipping) return INTEGER;}
	YY_BREAK
case 6:
YY_USER_ACTION
# line 16 "config.l"
{if (! skipping) return INTEGER;}
	YY_BREAK
case 7:
YY_USER_ACTION
# line 17 "config.l"
{if (! skipping) return INTEGER;}
	YY_BREAK
case 8:
YY_USER_ACTION
# line 18 "config.l"
{if (! skipping) return IS;}
	YY_BREAK
case 9:
YY_USER_ACTION
# line 19 "config.l"
{if (! skipping) return ON;}
	YY_BREAK
case 10:
YY_USER_ACTION
# line 20 "config.l"
;
	YY_BREAK
case 11:
YY_USER_ACTION
# line 21 "config.l"
{if (! skipping) return IINT;}
	YY_BREAK
case 12:
YY_USER_ACTION
# line 22 "config.l"
{if (! skipping) return OINT;}
	YY_BREAK
case 13:
YY_USER_ACTION
# line 23 "config.l"
{if (! skipping) return CSR;}
	YY_BREAK
case 14:
YY_USER_ACTION
# line 24 "config.l"
{if (! skipping) return IVEC;}
	YY_BREAK
case 15:
YY_USER_ACTION
# line 25 "config.l"
{if (! skipping) return IRQ;}
	YY_BREAK
case 16:
YY_USER_ACTION
# line 26 "config.l"
{if (! skipping) return OVEC;}
	YY_BREAK
case 17:
YY_USER_ACTION
# line 27 "config.l"
{if (! skipping) return INIT;}
	YY_BREAK
case 18:
YY_USER_ACTION
# line 28 "config.l"
{if (! skipping) return OPEN;}
	YY_BREAK
case 19:
YY_USER_ACTION
# line 29 "config.l"
{if (! skipping) return CLOSE;}
	YY_BREAK
case 20:
YY_USER_ACTION
# line 30 "config.l"
{if (! skipping) return READ;}
	YY_BREAK
case 21:
YY_USER_ACTION
# line 31 "config.l"
{if (! skipping) return GETC;}
	YY_BREAK
case 22:
YY_USER_ACTION
# line 32 "config.l"
{if (! skipping) return PUTC;}
	YY_BREAK
case 23:
YY_USER_ACTION
# line 33 "config.l"
{if (! skipping) return WRITE;}
	YY_BREAK
case 24:
YY_USER_ACTION
# line 34 "config.l"
{if (! skipping) return SEEK;}
	YY_BREAK
case 25:
YY_USER_ACTION
# line 35 "config.l"
{if (! skipping) return CNTL;}
	YY_BREAK
case 26:
YY_USER_ACTION
# line 36 "config.l"
;
	YY_BREAK
case 27:
YY_USER_ACTION
# line 37 "config.l"
{extern int linectr;
			 linectr++;
			}
	YY_BREAK
case 28:
YY_USER_ACTION
# line 40 "config.l"
{if (! skipping) return IDENT;}
	YY_BREAK
case 29:
YY_USER_ACTION
# line 41 "config.l"
{if (! skipping) return yytext[0];}
	YY_BREAK
case 30:
YY_USER_ACTION
# line 42 "config.l"
ECHO;
	YY_BREAK
case YY_STATE_EOF(INITIAL):
	yyterminate();

	case YY_END_OF_BUFFER:
		{
		/* Amount of text matched not including the EOB char. */
		int yy_amount_of_matched_text = yy_cp - yytext_ptr - 1;

		/* Undo the effects of YY_DO_BEFORE_ACTION. */
		*yy_cp = yy_hold_char;

		if ( yy_current_buffer->yy_input_file != yyin )
			{
			/* This can happen if we scan a file, yywrap() returns
			 * 1, and then later the user points yyin at a new
			 * file to resume scanning.  We have to assure
			 * consistency between yy_current_buffer and our
			 * globals.  Here is the right place to do so, because
			 * this is the first action (other than possibly a
			 * back-up) that will match for the new input file.
			 */
			yy_current_buffer->yy_input_file = yyin;
			yy_n_chars = yy_current_buffer->yy_n_chars;
			}

		/* Note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the
		 * end-of-buffer state).  Contrast this with the test
		 * in input().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			{ /* This was really a NUL. */
			yy_state_type yy_next_state;

			yy_c_buf_p = yytext_ptr + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			/* Okay, we're now positioned to make the NUL
			 * transition.  We couldn't have
			 * yy_get_previous_state() go ahead and do it
			 * for us because it doesn't know how to deal
			 * with the possibility of jamming (and we don't
			 * want to build jamming into it because then it
			 * will run more slowly).
			 */

			yy_next_state = yy_try_NUL_trans( yy_current_state );

			yy_bp = yytext_ptr + YY_MORE_ADJ;

			if ( yy_next_state )
				{
				/* Consume the NUL. */
				yy_cp = ++yy_c_buf_p;
				yy_current_state = yy_next_state;
				goto yy_match;
				}

			else
				{
				goto yy_find_action;
				}
			}

		else switch ( yy_get_next_buffer() )
			{
			case EOB_ACT_END_OF_FILE:
				{
				yy_did_buffer_switch_on_eof = 0;

				if ( yywrap() )
					{
					/* Note: because we've taken care in
					 * yy_get_next_buffer() to have set up
					 * yytext, we can now set up
					 * yy_c_buf_p so that if some total
					 * hoser (like flex itself) wants to
					 * call the scanner after we return the
					 * YY_NULL, it'll still work - another
					 * YY_NULL will get returned.
					 */
					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;

					yy_act = YY_STATE_EOF(YY_START);
					goto do_action;
					}

				else
					{
					if ( ! yy_did_buffer_switch_on_eof )
						YY_NEW_FILE;
					}
				break;
				}

			case EOB_ACT_CONTINUE_SCAN:
				yy_c_buf_p =
					yytext_ptr + yy_amount_of_matched_text;

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_match;

			case EOB_ACT_LAST_MATCH:
				yy_c_buf_p =
				&yy_current_buffer->yy_ch_buf[yy_n_chars];

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_find_action;
			}
		break;
		}

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} /* end of action switch */
		} /* end of scanning one token */
	} /* end of yylex */


/* yy_get_next_buffer - try to read in a new buffer
 *
 * Returns a code representing an action:
 *	EOB_ACT_LAST_MATCH -
 *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *	EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer()
	{
	register char *dest = yy_current_buffer->yy_ch_buf;
	register char *source = yytext_ptr - 1; /* copy prev. char, too */
	register int number_to_move, i;
	int ret_val;

	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
		YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

	if ( yy_current_buffer->yy_fill_buffer == 0 )
		{ /* Don't try to fill the buffer, so this is an EOF. */
		if ( yy_c_buf_p - yytext_ptr - YY_MORE_ADJ == 1 )
			{
			/* We matched a singled characater, the EOB, so
			 * treat this as a final EOF.
			 */
			return EOB_ACT_END_OF_FILE;
			}

		else
			{
			/* We matched some text prior to the EOB, first
			 * process it.
			 */
			return EOB_ACT_LAST_MATCH;
			}
		}

	/* Try to read more data. */

	/* First move last chars to start of buffer. */
	number_to_move = yy_c_buf_p - yytext_ptr;

	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);

	if ( yy_current_buffer->yy_eof_status != EOF_NOT_SEEN )
		/* don't do the read, it's not guaranteed to return an EOF,
		 * just force an EOF
		 */
		yy_n_chars = 0;

	else
		{
		int num_to_read =
			yy_current_buffer->yy_buf_size - number_to_move - 1;

		while ( num_to_read <= 0 )
			{ /* Not enough room in the buffer - grow it. */
#ifdef YY_USES_REJECT
			YY_FATAL_ERROR(
"input buffer overflow, can't enlarge buffer because scanner uses REJECT" );
#else

			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = yy_current_buffer;

			int yy_c_buf_p_offset = yy_c_buf_p - b->yy_ch_buf;

			b->yy_buf_size *= 2;
			b->yy_ch_buf = (char *)
				yy_flex_realloc( (void *) b->yy_ch_buf,
						 b->yy_buf_size );

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = yy_current_buffer->yy_buf_size -
						number_to_move - 1;
#endif
			}

		if ( num_to_read > YY_READ_BUF_SIZE )
			num_to_read = YY_READ_BUF_SIZE;

		/* Read in more data. */
		YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
			yy_n_chars, num_to_read );
		}

	if ( yy_n_chars == 0 )
		{
		if ( number_to_move - YY_MORE_ADJ == 1 )
			{
			ret_val = EOB_ACT_END_OF_FILE;
			yyrestart( yyin );
			}

		else
			{
			ret_val = EOB_ACT_LAST_MATCH;
			yy_current_buffer->yy_eof_status = EOF_PENDING;
			}
		}

	else
		ret_val = EOB_ACT_CONTINUE_SCAN;

	yy_n_chars += number_to_move;
	yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

	/* yytext begins at the second character in yy_ch_buf; the first
	 * character is the one which preceded it before reading in the latest
	 * buffer; it needs to be kept around in case it's a newline, so
	 * yy_get_previous_state() will have with '^' rules active.
	 */

	yytext_ptr = &yy_current_buffer->yy_ch_buf[1];

	return ret_val;
	}


/* yy_get_previous_state - get the state just before the EOB char was reached */

static yy_state_type yy_get_previous_state()
	{
	register yy_state_type yy_current_state;
	register char *yy_cp;

	yy_current_state = yy_start;

	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
		{
		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
		if ( yy_accept[yy_current_state] )
			{
			yy_last_accepting_state = yy_current_state;
			yy_last_accepting_cpos = yy_cp;
			}
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
			{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 77 )
				yy_c = yy_meta[(unsigned int) yy_c];
			}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
		}

	return yy_current_state;
	}


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *	next_state = yy_try_NUL_trans( current_state );
 */

#ifdef YY_USE_PROTOS
static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )
#else
static yy_state_type yy_try_NUL_trans( yy_current_state )
yy_state_type yy_current_state;
#endif
	{
	register int yy_is_jam;
	register char *yy_cp = yy_c_buf_p;

	register YY_CHAR yy_c = 1;
	if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 77 )
			yy_c = yy_meta[(unsigned int) yy_c];
		}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	yy_is_jam = (yy_current_state == 76);

	return yy_is_jam ? 0 : yy_current_state;
	}


#ifdef YY_USE_PROTOS
static void yyunput( int c, register char *yy_bp )
#else
static void yyunput( c, yy_bp )
int c;
register char *yy_bp;
#endif
	{
	register char *yy_cp = yy_c_buf_p;

	/* undo effects of setting up yytext */
	*yy_cp = yy_hold_char;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
		{ /* need to shift things up to make room */
		/* +2 for EOB chars. */
		register int number_to_move = yy_n_chars + 2;
		register char *dest = &yy_current_buffer->yy_ch_buf[
					yy_current_buffer->yy_buf_size + 2];
		register char *source =
				&yy_current_buffer->yy_ch_buf[number_to_move];

		while ( source > yy_current_buffer->yy_ch_buf )
			*--dest = *--source;

		yy_cp += dest - source;
		yy_bp += dest - source;
		yy_n_chars = yy_current_buffer->yy_buf_size;

		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
			YY_FATAL_ERROR( "flex scanner push-back overflow" );
		}

	if ( yy_cp > yy_bp && yy_cp[-1] == '\n' )
		yy_cp[-2] = '\n';

	*--yy_cp = (char) c;


	/* Note: the formal parameter *must* be called "yy_bp" for this
	 * macro to now work correctly.
	 */
	YY_DO_BEFORE_ACTION; /* set up yytext again */
	}


#ifdef __cplusplus
static int yyinput()
#else
static int input()
#endif
	{
	int c;

	*yy_c_buf_p = yy_hold_char;

	if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
		{
		/* yy_c_buf_p now points to the character we want to return.
		 * If this occurs *before* the EOB characters, then it's a
		 * valid NUL; if not, then we've hit the end of the buffer.
		 */
		if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			/* This was really a NUL. */
			*yy_c_buf_p = '\0';

		else
			{ /* need more input */
			yytext_ptr = yy_c_buf_p;
			++yy_c_buf_p;

			switch ( yy_get_next_buffer() )
				{
				case EOB_ACT_END_OF_FILE:
					{
					if ( yywrap() )
						{
						yy_c_buf_p =
						yytext_ptr + YY_MORE_ADJ;
						return EOF;
						}

					YY_NEW_FILE;
#ifdef __cplusplus
					return yyinput();
#else
					return input();
#endif
					}

				case EOB_ACT_CONTINUE_SCAN:
					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;
					break;

				case EOB_ACT_LAST_MATCH:
#ifdef __cplusplus
					YY_FATAL_ERROR(
					"unexpected last match in yyinput()" );
#else
					YY_FATAL_ERROR(
					"unexpected last match in input()" );
#endif
				}
			}
		}

	c = *yy_c_buf_p;
	*yy_c_buf_p = '\0';	/* preserve yytext */
	yy_hold_char = *++yy_c_buf_p;

	return c;
	}


#ifdef YY_USE_PROTOS
void yyrestart( FILE *input_file )
#else
void yyrestart( input_file )
FILE *input_file;
#endif
	{
	if ( ! yy_current_buffer )
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );

	yy_init_buffer( yy_current_buffer, input_file );
	yy_load_buffer_state();
	}


#ifdef YY_USE_PROTOS
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
#else
void yy_switch_to_buffer( new_buffer )
YY_BUFFER_STATE new_buffer;
#endif
	{
	if ( yy_current_buffer == new_buffer )
		return;

	if ( yy_current_buffer )
		{
		/* Flush out information for old buffer. */
		*yy_c_buf_p = yy_hold_char;
		yy_current_buffer->yy_buf_pos = yy_c_buf_p;
		yy_current_buffer->yy_n_chars = yy_n_chars;
		}

	yy_current_buffer = new_buffer;
	yy_load_buffer_state();

	/* We don't actually know whether we did this switch during
	 * EOF (yywrap()) processing, but the only time this flag
	 * is looked at is after yywrap() is called, so it's safe
	 * to go ahead and always set it.
	 */
	yy_did_buffer_switch_on_eof = 1;
	}


#ifdef YY_USE_PROTOS
void yy_load_buffer_state( void )
#else
void yy_load_buffer_state()
#endif
	{
	yy_n_chars = yy_current_buffer->yy_n_chars;
	yytext_ptr = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
	yyin = yy_current_buffer->yy_input_file;
	yy_hold_char = *yy_c_buf_p;
	}


#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
#else
YY_BUFFER_STATE yy_create_buffer( file, size )
FILE *file;
int size;
#endif
	{
	YY_BUFFER_STATE b;

	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );

	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_buf_size = size;

	/* yy_ch_buf has to be 2 characters longer than the size given because
	 * we need to put in 2 end-of-buffer characters.
	 */
	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );

	if ( ! b->yy_ch_buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	yy_init_buffer( b, file );

	return b;
	}


#ifdef YY_USE_PROTOS
void yy_delete_buffer( YY_BUFFER_STATE b )
#else
void yy_delete_buffer( b )
YY_BUFFER_STATE b;
#endif
	{
	if ( b == yy_current_buffer )
		yy_current_buffer = (YY_BUFFER_STATE) 0;

	yy_flex_free( (void *) b->yy_ch_buf );
	yy_flex_free( (void *) b );
	}


#ifdef YY_USE_PROTOS
void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
#else
void yy_init_buffer( b, file )
YY_BUFFER_STATE b;
FILE *file;
#endif
	{
	b->yy_input_file = file;

	/* We put in the '\n' and start reading from [1] so that an
	 * initial match-at-newline will be true.
	 */

	b->yy_ch_buf[0] = '\n';
	b->yy_n_chars = 1;

	/* We always need two end-of-buffer characters.  The first causes
	 * a transition to the end-of-buffer state.  The second causes
	 * a jam in that state.
	 */
	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;
	b->yy_ch_buf[2] = YY_END_OF_BUFFER_CHAR;

	b->yy_buf_pos = &b->yy_ch_buf[1];

	b->yy_is_interactive = file ? isatty( fileno(file) ) : 0;

	b->yy_fill_buffer = 1;

	b->yy_eof_status = EOF_NOT_SEEN;
	}


#ifdef YY_USE_PROTOS
static void yy_push_state( int new_state )
#else
static void yy_push_state( new_state )
int new_state;
#endif
	{
	if ( yy_start_stack_ptr >= yy_start_stack_depth )
		{
		int new_size;

		yy_start_stack_depth += YY_START_STACK_INCR;
		new_size = yy_start_stack_depth * sizeof( int );

		if ( ! yy_start_stack )
			yy_start_stack = (int *) yy_flex_alloc( new_size );

		else
			yy_start_stack = (int *) yy_flex_realloc(
					(void *) yy_start_stack, new_size );

		if ( ! yy_start_stack )
			YY_FATAL_ERROR(
			"out of memory expanding start-condition stack" );
		}

	yy_start_stack[yy_start_stack_ptr++] = YY_START;

	BEGIN(new_state);
	}


static void yy_pop_state()
	{
	if ( --yy_start_stack_ptr < 0 )
		YY_FATAL_ERROR( "start-condition stack underflow" );

	BEGIN(yy_start_stack[yy_start_stack_ptr]);
	}


static int yy_top_state()
	{
	return yy_start_stack[yy_start_stack_ptr - 1];
	}


#ifdef YY_USE_PROTOS
static void yy_fatal_error( const char msg[] )
#else
static void yy_fatal_error( msg )
char msg[];
#endif
	{
	(void) fprintf( stderr, "%s\n", msg );
	exit( 1 );
	}



/* Redefine yyless() so it works in section 3 code. */

#undef yyless
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		yytext[yyleng] = yy_hold_char; \
		yy_c_buf_p = yytext + n - YY_MORE_ADJ; \
		yy_hold_char = *yy_c_buf_p; \
		*yy_c_buf_p = '\0'; \
		yyleng = n; \
		} \
	while ( 0 )


/* Internal utility routines. */

#ifndef yytext_ptr
#ifdef YY_USE_PROTOS
static void yy_flex_strcpy( char *s1, const char *s2 )
#else
static void yy_flex_strcpy( s1, s2 )
char *s1;
const char *s2;
#endif
	{
	while ( (*(s1++) = *(s2++)) )
		;
	}
#endif


#ifdef YY_USE_PROTOS
static void *yy_flex_alloc( unsigned int size )
#else
static void *yy_flex_alloc( size )
unsigned int size;
#endif
	{
	return (void *) malloc( size );
	}

#ifdef YY_USE_PROTOS
static void *yy_flex_realloc( void *ptr, unsigned int size )
#else
static void *yy_flex_realloc( ptr, size )
void *ptr;
unsigned int size;
#endif
	{
	return (void *) realloc( ptr, size );
	}

#ifdef YY_USE_PROTOS
static void yy_flex_free( void *ptr )
#else
static void yy_flex_free( ptr )
void *ptr;
#endif
	{
	free( ptr );
	}
# line 42 "config.l"
