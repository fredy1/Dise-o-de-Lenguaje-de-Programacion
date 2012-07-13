
/*  A Bison parser, made from sintactico.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	PRINICIO	257
#define	PRFINAL	258
#define	PRSI	259
#define	PRSINO	260
#define	PRFINSI	261
#define	PRPARA	262
#define	PRFINPARA	263
#define	PRENTERO	264
#define	PRCADENA	265
#define	PRARRAY	266
#define	PRIMPRIMIR	267
#define	CAD	268
#define	CAR	269
#define	ARR	270
#define	ENT	271
#define	REA	272
#define	COM	273
#define	PUNCOM	274
#define	DIF	275
#define	COMA	276
#define	IGU	277
#define	MAIGO	278
#define	MEIGO	279
#define	APAR	280
#define	CPAR	281
#define	MAY	282
#define	MEN	283
#define	ALLA	284
#define	CLLA	285
#define	SUM	286
#define	RES	287
#define	MUL	288
#define	DIV	289
#define	YY	290
#define	OO	291
#define	ERROR	292

#line 1 "sintactico.y"
  
int yystopparser=0;  
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		129
#define	YYFLAG		-32768
#define	YYNTBASE	39

#define YYTRANSLATE(x) ((unsigned)(x) <= 292 ? yytranslate[x] : 58)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     7,    11,    17,    20,    25,    29,    35,    38,
    43,    48,    57,    61,    69,    71,    75,    79,    83,    87,
    88,    95,    96,   105,   111,   117,   121,   125,   129,   133,
   137,   141,   145,   149,   150,   155,   159,   161,   165,   167,
   171,   175,   179,   183,   187,   191,   196,   199,   204,   209,
   214,   215,   228,   232,   236,   240,   244,   246,   247,   249
};

static const short yyrhs[] = {    40,
    43,     0,    30,    41,    31,     0,    10,    15,    41,     0,
    10,    15,    23,    17,    41,     0,    10,    15,     0,    10,
    15,    23,    17,     0,    11,    15,    41,     0,    11,    15,
    23,    14,    41,     0,    11,    15,     0,    11,    15,    23,
    14,     0,    12,    15,    16,    41,     0,    12,    15,    16,
    23,    30,    42,    31,    41,     0,    12,    15,    16,     0,
    12,    15,    16,    23,    30,    42,    31,     0,    17,     0,
    17,    22,    42,     0,     3,    44,     4,     0,     3,    52,
     4,     0,     3,    50,     4,     0,     0,     5,    47,    49,
     7,    45,    57,     0,     0,     5,    47,    49,     6,    49,
     7,    46,    57,     0,    26,    48,    27,    36,    47,     0,
    26,    48,    27,    37,    47,     0,    26,    48,    27,     0,
    15,    19,    15,     0,    15,    19,    17,     0,    17,    19,
    17,     0,    17,    19,    15,     0,    30,    44,    31,     0,
    30,    52,    31,     0,    30,    50,    31,     0,     0,    15,
    23,    51,    50,     0,    15,    32,    51,     0,    15,     0,
    17,    32,    51,     0,    17,     0,    15,    33,    51,     0,
    17,    33,    51,     0,    15,    34,    51,     0,    17,    34,
    51,     0,    15,    35,    51,     0,    17,    35,    51,     0,
    15,    16,    32,    51,     0,    15,    16,     0,    15,    16,
    33,    51,     0,    15,    16,    34,    51,     0,    15,    16,
    35,    51,     0,     0,     8,    26,    54,    22,    55,    22,
    56,    27,    49,     9,    53,    57,     0,    15,    23,    17,
     0,    15,    19,    17,     0,    15,    32,    32,     0,    15,
    33,    33,     0,    50,     0,     0,    44,     0,    52,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
     9,    12,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25,    27,    28,    30,    31,    32,    36,
    37,    37,    38,    39,    40,    41,    43,    44,    45,    46,
    48,    49,    50,    52,    53,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    73,    74,    75,    77,    79,    80,    81,    83,    84,    85
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","PRINICIO",
"PRFINAL","PRSI","PRSINO","PRFINSI","PRPARA","PRFINPARA","PRENTERO","PRCADENA",
"PRARRAY","PRIMPRIMIR","CAD","CAR","ARR","ENT","REA","COM","PUNCOM","DIF","COMA",
"IGU","MAIGO","MEIGO","APAR","CPAR","MAY","MEN","ALLA","CLLA","SUM","RES","MUL",
"DIV","YY","OO","ERROR","inicio","estruc","declaracion","terarr","cuerpo","cond",
"@1","@2","res","con","sentencia","oper","we","bucl","@3","inc","cdc","paso",
"r", NULL
};
#endif

static const short yyr1[] = {     0,
    39,    40,    41,    41,    41,    41,    41,    41,    41,    41,
    41,    41,    41,    41,    42,    42,    43,    43,    43,    45,
    44,    46,    44,    47,    47,    47,    48,    48,    48,    48,
    49,    49,    49,    50,    50,    51,    51,    51,    51,    51,
    51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
    53,    52,    54,    55,    56,    56,    56,    57,    57,    57
};

static const short yyr2[] = {     0,
     2,     3,     3,     5,     2,     4,     3,     5,     2,     4,
     4,     8,     3,     7,     1,     3,     3,     3,     3,     0,
     6,     0,     8,     5,     5,     3,     3,     3,     3,     3,
     3,     3,     3,     0,     4,     3,     1,     3,     1,     3,
     3,     3,     3,     3,     3,     4,     2,     4,     4,     4,
     0,    12,     3,     3,     3,     3,     1,     0,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,    34,     1,     5,     9,
     0,     2,     0,     0,     0,     0,     0,     0,     0,     3,
     0,     7,    13,     0,     0,     0,     0,    17,    19,    18,
     6,    10,     0,    11,     0,     0,     0,    34,     0,     0,
     0,    37,    39,    34,     4,     8,     0,     0,     0,    26,
     0,     0,     0,     0,    20,     0,     0,    47,     0,     0,
     0,     0,     0,     0,     0,     0,    35,    15,     0,    27,
    28,    30,    29,     0,     0,    31,    33,    32,     0,    58,
    53,     0,     0,     0,     0,     0,     0,    36,    40,    42,
    44,    38,    41,    43,    45,     0,    14,    24,    25,    22,
    59,    60,    21,     0,    34,    46,    48,    49,    50,    16,
    12,    58,    54,     0,    57,     0,    23,     0,     0,     0,
    55,    56,     0,    51,    58,    52,     0,     0,     0
};

static const short yydefgoto[] = {   127,
     2,     6,    69,     8,   101,    80,   112,    25,    37,    39,
    17,    44,   102,   125,    41,    83,   116,   103
};

static const short yypact[] = {   -19,
    66,    10,     0,    17,    46,   -11,     2,-32768,    31,    34,
    52,-32768,    59,    60,    67,    83,    85,    87,    75,-32768,
    79,-32768,    48,     1,    68,    80,    18,-32768,-32768,-32768,
    66,    66,    69,-32768,    77,    78,    73,     2,    41,    71,
    81,     5,    32,    86,-32768,-32768,    88,    64,    65,    19,
    76,    82,    84,    68,-32768,    89,    93,    40,    18,    18,
    18,    18,    18,    18,    18,    18,-32768,    90,    91,-32768,
-32768,-32768,-32768,    59,    59,-32768,-32768,-32768,    95,     4,
-32768,    92,    94,    18,    18,    18,    18,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    88,    66,-32768,-32768,-32768,
-32768,-32768,-32768,    97,   102,-32768,-32768,-32768,-32768,-32768,
-32768,     4,-32768,    30,-32768,    96,-32768,    72,    98,    68,
-32768,-32768,   100,-32768,     4,-32768,   110,   118,-32768
};

static const short yypgoto[] = {-32768,
-32768,    -9,    23,-32768,    -4,-32768,-32768,     9,-32768,   -50,
   -36,   -35,    -2,-32768,-32768,-32768,-32768,  -106
};


#define	YYLAST		131


static const short yytable[] = {    20,
    22,    52,    16,    79,    18,   117,    13,    67,    13,    14,
     1,    14,     7,    34,     9,    35,    15,    36,   126,    12,
    58,    45,    46,    88,    89,    90,    91,    92,    93,    94,
    95,    10,    42,    51,    43,    53,    59,    60,    61,    62,
     3,     4,     5,     3,     4,     5,    54,    55,   106,   107,
   108,   109,    27,    19,    74,    75,    21,     3,     4,     5,
    11,   118,   119,    63,    64,    65,    66,    23,   115,   123,
    33,    84,    85,    86,    87,     3,     4,     5,    70,    72,
    71,    73,    98,    99,    24,    26,    28,   111,    29,    27,
    30,    31,    32,    56,    40,    48,    49,    38,    47,    50,
    15,   100,    57,   121,    68,    81,    76,    82,   124,   128,
   104,    96,    77,   113,    78,   105,   114,   129,   110,     0,
     0,    97,   120,     0,     0,     0,     0,     0,     0,     0,
   122
};

static const short yycheck[] = {     9,
    10,    38,     7,    54,     7,   112,     5,    44,     5,     8,
    30,     8,     3,    23,    15,    15,    15,    17,   125,    31,
    16,    31,    32,    59,    60,    61,    62,    63,    64,    65,
    66,    15,    15,    38,    17,    38,    32,    33,    34,    35,
    10,    11,    12,    10,    11,    12,     6,     7,    84,    85,
    86,    87,    23,    23,    36,    37,    23,    10,    11,    12,
    15,    32,    33,    32,    33,    34,    35,    16,   105,   120,
    23,    32,    33,    34,    35,    10,    11,    12,    15,    15,
    17,    17,    74,    75,    26,    26,     4,    97,     4,    23,
     4,    17,    14,    23,    15,    19,    19,    30,    30,    27,
    15,     7,    22,    32,    17,    17,    31,    15,     9,     0,
    19,    22,    31,    17,    31,    22,    15,     0,    96,    -1,
    -1,    31,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    33
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/dev/env/DJDIR/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (__MSDOS__)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not __MSDOS__, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not __MSDOS__, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/dev/env/DJDIR/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 2:
#line 12 "sintactico.y"
{printf("ESTRCTURA CORRECTA\n");;
    break;}
case 3:
#line 14 "sintactico.y"
{printf("DECLARACION ENTERO\n");;
    break;}
case 4:
#line 15 "sintactico.y"
{printf("DECLARACION ENTERO\n");;
    break;}
case 5:
#line 16 "sintactico.y"
{printf("DECLARACION ENTERO\n");;
    break;}
case 6:
#line 17 "sintactico.y"
{printf("DECLARACION ENTERO\n");;
    break;}
case 7:
#line 18 "sintactico.y"
{printf("DECLARACION CADENA\n");;
    break;}
case 8:
#line 19 "sintactico.y"
{printf("DECLARACION CADENA\n");;
    break;}
case 9:
#line 20 "sintactico.y"
{printf("DECLARACION CADENA\n");;
    break;}
case 10:
#line 21 "sintactico.y"
{printf("DECLARACIOON CADENA\n");;
    break;}
case 11:
#line 22 "sintactico.y"
{printf("DECLARACION ARRAY\n");;
    break;}
case 12:
#line 23 "sintactico.y"
{printf("DECLARACION ARRAY\n");;
    break;}
case 13:
#line 24 "sintactico.y"
{printf("DECLARACION ARRAY\n");;
    break;}
case 14:
#line 25 "sintactico.y"
{printf("DECLARACION ARRAY\n");;
    break;}
case 17:
#line 30 "sintactico.y"
{printf("PROGRAMA CORRECTO\n");;
    break;}
case 18:
#line 31 "sintactico.y"
{printf("PROGRAMA CORRECTO\n");;
    break;}
case 19:
#line 32 "sintactico.y"
{printf("PROGRAMA CORRECTO\n");;
    break;}
case 20:
#line 36 "sintactico.y"
{printf("SENTENCIA SI CORRECTA\n");;
    break;}
case 22:
#line 37 "sintactico.y"
{printf("SENTENCIA SI CORRECTA\n");;
    break;}
case 35:
#line 53 "sintactico.y"
{printf("OPERACION CORECTA\n");;
    break;}
case 37:
#line 57 "sintactico.y"
{printf("OPERACION CORECTA\n");;
    break;}
case 39:
#line 59 "sintactico.y"
{printf("OPERACION CORECTA\n");;
    break;}
case 47:
#line 67 "sintactico.y"
{printf("OPERACION CORECTA\n");;
    break;}
case 51:
#line 73 "sintactico.y"
{printf("SENTENCIA PARA CORRECTA\n");;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/dev/env/DJDIR/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 88 "sintactico.y"
