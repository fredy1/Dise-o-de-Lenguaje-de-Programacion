This is bison.info, produced by makeinfo version 4.0 from bison.texinfo.

START-INFO-DIR-ENTRY
* bison: (bison).	GNU Project parser generator (yacc replacement).
END-INFO-DIR-ENTRY

   This file documents the Bison parser generator.

   Copyright (C) 1988, 89, 90, 91, 92, 93, 95, 98, 1999 Free Software
Foundation, Inc.

   Permission is granted to make and distribute verbatim copies of this
manual provided the copyright notice and this permission notice are
preserved on all copies.

   Permission is granted to copy and distribute modified versions of
this manual under the conditions for verbatim copying, provided also
that the sections entitled "GNU General Public License" and "Conditions
for Using Bison" are included exactly as in the original, and provided
that the entire resulting derived work is distributed under the terms
of a permission notice identical to this one.

   Permission is granted to copy and distribute translations of this
manual into another language, under the above conditions for modified
versions, except that the sections entitled "GNU General Public
License", "Conditions for Using Bison" and this permission notice may be
included in translations approved by the Free Software Foundation
instead of in the original English.


File: bison.info,  Node: Mid-Rule Actions,  Prev: Action Types,  Up: Semantics

Actions in Mid-Rule
-------------------

   Occasionally it is useful to put an action in the middle of a rule.
These actions are written just like usual end-of-rule actions, but they
are executed before the parser even recognizes the following components.

   A mid-rule action may refer to the components preceding it using
`$N', but it may not refer to subsequent components because it is run
before they are parsed.

   The mid-rule action itself counts as one of the components of the
rule.  This makes a difference when there is another action later in
the same rule (and usually there is another at the end): you have to
count the actions along with the symbols when working out which number
N to use in `$N'.

   The mid-rule action can also have a semantic value.  The action can
set its value with an assignment to `$$', and actions later in the rule
can refer to the value using `$N'.  Since there is no symbol to name
the action, there is no way to declare a data type for the value in
advance, so you must use the `$<...>' construct to specify a data type
each time you refer to this value.

   There is no way to set the value of the entire rule with a mid-rule
action, because assignments to `$$' do not have that effect.  The only
way to set the value for the entire rule is with an ordinary action at
the end of the rule.

   Here is an example from a hypothetical compiler, handling a `let'
statement that looks like `let (VARIABLE) STATEMENT' and serves to
create a variable named VARIABLE temporarily for the duration of
STATEMENT.  To parse this construct, we must put VARIABLE into the
symbol table while STATEMENT is parsed, then remove it afterward.  Here
is how it is done:

     stmt:   LET '(' var ')'
                     { $<context>$ = push_context ();
                       declare_variable ($3); }
             stmt    { $$ = $6;
                       pop_context ($<context>5); }

As soon as `let (VARIABLE)' has been recognized, the first action is
run.  It saves a copy of the current semantic context (the list of
accessible variables) as its semantic value, using alternative
`context' in the data-type union.  Then it calls `declare_variable' to
add the new variable to that list.  Once the first action is finished,
the embedded statement `stmt' can be parsed.  Note that the mid-rule
action is component number 5, so the `stmt' is component number 6.

   After the embedded statement is parsed, its semantic value becomes
the value of the entire `let'-statement.  Then the semantic value from
the earlier action is used to restore the prior list of variables.  This
removes the temporary `let'-variable from the list so that it won't
appear to exist while the rest of the program is parsed.

   Taking action before a rule is completely recognized often leads to
conflicts since the parser must commit to a parse in order to execute
the action.  For example, the following two rules, without mid-rule
actions, can coexist in a working parser because the parser can shift
the open-brace token and look at what follows before deciding whether
there is a declaration or not:

     compound: '{' declarations statements '}'
             | '{' statements '}'
             ;

But when we add a mid-rule action as follows, the rules become
nonfunctional:

     compound: { prepare_for_local_variables (); }
               '{' declarations statements '}'
             | '{' statements '}'
             ;

Now the parser is forced to decide whether to run the mid-rule action
when it has read no farther than the open-brace.  In other words, it
must commit to using one rule or the other, without sufficient
information to do it correctly.  (The open-brace token is what is called
the "look-ahead" token at this time, since the parser is still deciding
what to do about it.  *Note Look-Ahead Tokens: Look-Ahead.)

   You might think that you could correct the problem by putting
identical actions into the two rules, like this:

     compound: { prepare_for_local_variables (); }
               '{' declarations statements '}'
             | { prepare_for_local_variables (); }
               '{' statements '}'
             ;

But this does not help, because Bison does not realize that the two
actions are identical.  (Bison never tries to understand the C code in
an action.)

   If the grammar is such that a declaration can be distinguished from a
statement by the first token (which is true in C), then one solution
which does work is to put the action after the open-brace, like this:

     compound: '{' { prepare_for_local_variables (); }
               declarations statements '}'
             | '{' statements '}'
             ;

Now the first token of the following declaration or statement, which
would in any case tell Bison which rule to use, can still do so.

   Another solution is to bury the action inside a nonterminal symbol
which serves as a subroutine:

     subroutine: /* empty */
               { prepare_for_local_variables (); }
             ;
     
     compound: subroutine
               '{' declarations statements '}'
             | subroutine
               '{' statements '}'
             ;

Now Bison can execute the action in the rule for `subroutine' without
deciding which rule for `compound' it will eventually use.  Note that
the action is now at the end of its rule.  Any mid-rule action can be
converted to an end-of-rule action in this way, and this is what Bison
actually does to implement mid-rule actions.


File: bison.info,  Node: Declarations,  Next: Multiple Parsers,  Prev: Semantics,  Up: Grammar File

Bison Declarations
==================

   The "Bison declarations" section of a Bison grammar defines the
symbols used in formulating the grammar and the data types of semantic
values.  *Note Symbols::.

   All token type names (but not single-character literal tokens such as
`'+'' and `'*'') must be declared.  Nonterminal symbols must be
declared if you need to specify which data type to use for the semantic
value (*note More Than One Value Type: Multiple Types.).

   The first rule in the file also specifies the start symbol, by
default.  If you want some other symbol to be the start symbol, you
must declare it explicitly (*note Languages and Context-Free Grammars:
Language and Grammar.).

* Menu:

* Token Decl::        Declaring terminal symbols.
* Precedence Decl::   Declaring terminals with precedence and associativity.
* Union Decl::        Declaring the set of all semantic value types.
* Type Decl::         Declaring the choice of type for a nonterminal symbol.
* Expect Decl::       Suppressing warnings about shift/reduce conflicts.
* Start Decl::        Specifying the start symbol.
* Pure Decl::         Requesting a reentrant parser.
* Decl Summary::      Table of all Bison declarations.


File: bison.info,  Node: Token Decl,  Next: Precedence Decl,  Up: Declarations

Token Type Names
----------------

   The basic way to declare a token type name (terminal symbol) is as
follows:

     %token NAME

   Bison will convert this into a `#define' directive in the parser, so
that the function `yylex' (if it is in this file) can use the name NAME
to stand for this token type's code.

   Alternatively, you can use `%left', `%right', or `%nonassoc' instead
of `%token', if you wish to specify precedence.  *Note Operator
Precedence: Precedence Decl.

   You can explicitly specify the numeric code for a token type by
appending an integer value in the field immediately following the token
name:

     %token NUM 300

It is generally best, however, to let Bison choose the numeric codes for
all token types.  Bison will automatically select codes that don't
conflict with each other or with ASCII characters.

   In the event that the stack type is a union, you must augment the
`%token' or other token declaration to include the data type
alternative delimited by angle-brackets (*note More Than One Value
Type: Multiple Types.).

   For example:

     %union {              /* define stack type */
       double val;
       symrec *tptr;
     }
     %token <val> NUM      /* define token NUM and its type */

   You can associate a literal string token with a token type name by
writing the literal string at the end of a `%token' declaration which
declares the name.  For example:

     %token arrow "=>"

For example, a grammar for the C language might specify these names with
equivalent literal string tokens:

     %token  <operator>  OR      "||"
     %token  <operator>  LE 134  "<="
     %left  OR  "<="

Once you equate the literal string and the token name, you can use them
interchangeably in further declarations or the grammar rules.  The
`yylex' function can use the token name or the literal string to obtain
the token type code number (*note Calling Convention::).


File: bison.info,  Node: Precedence Decl,  Next: Union Decl,  Prev: Token Decl,  Up: Declarations

Operator Precedence
-------------------

   Use the `%left', `%right' or `%nonassoc' declaration to declare a
token and specify its precedence and associativity, all at once.  These
are called "precedence declarations".  *Note Operator Precedence:
Precedence, for general information on operator precedence.

   The syntax of a precedence declaration is the same as that of
`%token': either

     %left SYMBOLS...

or

     %left <TYPE> SYMBOLS...

   And indeed any of these declarations serves the purposes of `%token'.
But in addition, they specify the associativity and relative precedence
for all the SYMBOLS:

   * The associativity of an operator OP determines how repeated uses
     of the operator nest: whether `X OP Y OP Z' is parsed by grouping
     X with Y first or by grouping Y with Z first.  `%left' specifies
     left-associativity (grouping X with Y first) and `%right'
     specifies right-associativity (grouping Y with Z first).
     `%nonassoc' specifies no associativity, which means that `X OP Y
     OP Z' is considered a syntax error.

   * The precedence of an operator determines how it nests with other
     operators.  All the tokens declared in a single precedence
     declaration have equal precedence and nest together according to
     their associativity.  When two tokens declared in different
     precedence declarations associate, the one declared later has the
     higher precedence and is grouped first.


File: bison.info,  Node: Union Decl,  Next: Type Decl,  Prev: Precedence Decl,  Up: Declarations

The Collection of Value Types
-----------------------------

   The `%union' declaration specifies the entire collection of possible
data types for semantic values.  The keyword `%union' is followed by a
pair of braces containing the same thing that goes inside a `union' in
C.

   For example:

     %union {
       double val;
       symrec *tptr;
     }

This says that the two alternative types are `double' and `symrec *'.
They are given names `val' and `tptr'; these names are used in the
`%token' and `%type' declarations to pick one of the types for a
terminal or nonterminal symbol (*note Nonterminal Symbols: Type Decl.).

   Note that, unlike making a `union' declaration in C, you do not write
a semicolon after the closing brace.


File: bison.info,  Node: Type Decl,  Next: Expect Decl,  Prev: Union Decl,  Up: Declarations

Nonterminal Symbols
-------------------

When you use `%union' to specify multiple value types, you must declare
the value type of each nonterminal symbol for which values are used.
This is done with a `%type' declaration, like this:

     %type <TYPE> NONTERMINAL...

Here NONTERMINAL is the name of a nonterminal symbol, and TYPE is the
name given in the `%union' to the alternative that you want (*note The
Collection of Value Types: Union Decl.).  You can give any number of
nonterminal symbols in the same `%type' declaration, if they have the
same value type.  Use spaces to separate the symbol names.

   You can also declare the value type of a terminal symbol.  To do
this, use the same `<TYPE>' construction in a declaration for the
terminal symbol.  All kinds of token declarations allow `<TYPE>'.


File: bison.info,  Node: Expect Decl,  Next: Start Decl,  Prev: Type Decl,  Up: Declarations

Suppressing Conflict Warnings
-----------------------------

   Bison normally warns if there are any conflicts in the grammar
(*note Shift/Reduce Conflicts: Shift/Reduce.), but most real grammars
have harmless shift/reduce conflicts which are resolved in a
predictable way and would be difficult to eliminate.  It is desirable
to suppress the warning about these conflicts unless the number of
conflicts changes.  You can do this with the `%expect' declaration.

   The declaration looks like this:

     %expect N

   Here N is a decimal integer.  The declaration says there should be no
warning if there are N shift/reduce conflicts and no reduce/reduce
conflicts.  The usual warning is given if there are either more or fewer
conflicts, or if there are any reduce/reduce conflicts.

   In general, using `%expect' involves these steps:

   * Compile your grammar without `%expect'.  Use the `-v' option to
     get a verbose list of where the conflicts occur.  Bison will also
     print the number of conflicts.

   * Check each of the conflicts to make sure that Bison's default
     resolution is what you really want.  If not, rewrite the grammar
     and go back to the beginning.

   * Add an `%expect' declaration, copying the number N from the number
     which Bison printed.

   Now Bison will stop annoying you about the conflicts you have
checked, but it will warn you again if changes in the grammar result in
additional conflicts.


File: bison.info,  Node: Start Decl,  Next: Pure Decl,  Prev: Expect Decl,  Up: Declarations

The Start-Symbol
----------------

   Bison assumes by default that the start symbol for the grammar is
the first nonterminal specified in the grammar specification section.
The programmer may override this restriction with the `%start'
declaration as follows:

     %start SYMBOL


File: bison.info,  Node: Pure Decl,  Next: Decl Summary,  Prev: Start Decl,  Up: Declarations

A Pure (Reentrant) Parser
-------------------------

   A "reentrant" program is one which does not alter in the course of
execution; in other words, it consists entirely of "pure" (read-only)
code.  Reentrancy is important whenever asynchronous execution is
possible; for example, a nonreentrant program may not be safe to call
from a signal handler.  In systems with multiple threads of control, a
nonreentrant program must be called only within interlocks.

   Normally, Bison generates a parser which is not reentrant.  This is
suitable for most uses, and it permits compatibility with YACC.  (The
standard YACC interfaces are inherently nonreentrant, because they use
statically allocated variables for communication with `yylex',
including `yylval' and `yylloc'.)

   Alternatively, you can generate a pure, reentrant parser.  The Bison
declaration `%pure_parser' says that you want the parser to be
reentrant.  It looks like this:

     %pure_parser

   The result is that the communication variables `yylval' and `yylloc'
become local variables in `yyparse', and a different calling convention
is used for the lexical analyzer function `yylex'.  *Note Calling
Conventions for Pure Parsers: Pure Calling, for the details of this.
The variable `yynerrs' also becomes local in `yyparse' (*note The Error
Reporting Function `yyerror': Error Reporting.).  The convention for
calling `yyparse' itself is unchanged.

   Whether the parser is pure has nothing to do with the grammar rules.
You can generate either a pure parser or a nonreentrant parser from any
valid grammar.


File: bison.info,  Node: Decl Summary,  Prev: Pure Decl,  Up: Declarations

Bison Declaration Summary
-------------------------

   Here is a summary of all Bison declarations:

`%union'
     Declare the collection of data types that semantic values may have
     (*note The Collection of Value Types: Union Decl.).

`%token'
     Declare a terminal symbol (token type name) with no precedence or
     associativity specified (*note Token Type Names: Token Decl.).

`%right'
     Declare a terminal symbol (token type name) that is
     right-associative (*note Operator Precedence: Precedence Decl.).

`%left'
     Declare a terminal symbol (token type name) that is
     left-associative (*note Operator Precedence: Precedence Decl.).

`%nonassoc'
     Declare a terminal symbol (token type name) that is nonassociative
     (using it in a way that would be associative is a syntax error)
     (*note Operator Precedence: Precedence Decl.).

`%type'
     Declare the type of semantic values for a nonterminal symbol
     (*note Nonterminal Symbols: Type Decl.).

`%start'
     Specify the grammar's start symbol (*note The Start-Symbol: Start
     Decl.).

`%expect'
     Declare the expected number of shift-reduce conflicts (*note
     Suppressing Conflict Warnings: Expect Decl.).

`%pure_parser'
     Request a pure (reentrant) parser program (*note A Pure
     (Reentrant) Parser: Pure Decl.).

`%no_lines'
     Don't generate any `#line' preprocessor commands in the parser
     file.  Ordinarily Bison writes these commands in the parser file
     so that the C compiler and debuggers will associate errors and
     object code with your source file (the grammar file).  This
     directive causes them to associate errors with the parser file,
     treating it an independent source file in its own right.

`%raw'
     The output file `NAME.h' normally defines the tokens with
     Yacc-compatible token numbers.  If this option is specified, the
     internal Bison numbers are used instead.  (Yacc-compatible numbers
     start at 257 except for single character tokens; Bison assigns
     token numbers sequentially for all tokens starting at 3.)

`%token_table'
     Generate an array of token names in the parser file.  The name of
     the array is `yytname'; `yytname[I]' is the name of the token
     whose internal Bison token code number is I.  The first three
     elements of `yytname' are always `"$"', `"error"', and
     `"$illegal"'; after these come the symbols defined in the grammar
     file.

     For single-character literal tokens and literal string tokens, the
     name in the table includes the single-quote or double-quote
     characters: for example, `"'+'"' is a single-character literal and
     `"\"<=\""' is a literal string token.  All the characters of the
     literal string token appear verbatim in the string found in the
     table; even double-quote characters are not escaped.  For example,
     if the token consists of three characters `*"*', its string in
     `yytname' contains `"*"*"'.  (In C, that would be written as
     `"\"*\"*\""').

     When you specify `%token_table', Bison also generates macro
     definitions for macros `YYNTOKENS', `YYNNTS', and `YYNRULES', and
     `YYNSTATES':

    `YYNTOKENS'
          The highest token number, plus one.

    `YYNNTS'
          The number of non-terminal symbols.

    `YYNRULES'
          The number of grammar rules,

    `YYNSTATES'
          The number of parser states (*note Parser States::).


File: bison.info,  Node: Multiple Parsers,  Prev: Declarations,  Up: Grammar File

Multiple Parsers in the Same Program
====================================

   Most programs that use Bison parse only one language and therefore
contain only one Bison parser.  But what if you want to parse more than
one language with the same program?  Then you need to avoid a name
conflict between different definitions of `yyparse', `yylval', and so
on.

   The easy way to do this is to use the option `-p PREFIX' (*note
Invoking Bison: Invocation.).  This renames the interface functions and
variables of the Bison parser to start with PREFIX instead of `yy'.
You can use this to give each parser distinct names that do not
conflict.

   The precise list of symbols renamed is `yyparse', `yylex',
`yyerror', `yynerrs', `yylval', `yychar' and `yydebug'.  For example,
if you use `-p c', the names become `cparse', `clex', and so on.

   *All the other variables and macros associated with Bison are not
renamed.* These others are not global; there is no conflict if the same
name is used in different parsers.  For example, `YYSTYPE' is not
renamed, but defining this in different ways in different parsers causes
no trouble (*note Data Types of Semantic Values: Value Type.).

   The `-p' option works by adding macro definitions to the beginning
of the parser source file, defining `yyparse' as `PREFIXparse', and so
on.  This effectively substitutes one name for the other in the entire
parser file.


File: bison.info,  Node: Interface,  Next: Algorithm,  Prev: Grammar File,  Up: Top

Parser C-Language Interface
***************************

   The Bison parser is actually a C function named `yyparse'.  Here we
describe the interface conventions of `yyparse' and the other functions
that it needs to use.

   Keep in mind that the parser uses many C identifiers starting with
`yy' and `YY' for internal purposes.  If you use such an identifier
(aside from those in this manual) in an action or in additional C code
in the grammar file, you are likely to run into trouble.

* Menu:

* Parser Function::   How to call `yyparse' and what it returns.
* Lexical::           You must supply a function `yylex'
                        which reads tokens.
* Error Reporting::   You must supply a function `yyerror'.
* Action Features::   Special features for use in actions.


File: bison.info,  Node: Parser Function,  Next: Lexical,  Up: Interface

The Parser Function `yyparse'
=============================

   You call the function `yyparse' to cause parsing to occur.  This
function reads tokens, executes actions, and ultimately returns when it
encounters end-of-input or an unrecoverable syntax error.  You can also
write an action which directs `yyparse' to return immediately without
reading further.

   The value returned by `yyparse' is 0 if parsing was successful
(return is due to end-of-input).

   The value is 1 if parsing failed (return is due to a syntax error).

   In an action, you can cause immediate return from `yyparse' by using
these macros:

`YYACCEPT'
     Return immediately with value 0 (to report success).

`YYABORT'
     Return immediately with value 1 (to report failure).


File: bison.info,  Node: Lexical,  Next: Error Reporting,  Prev: Parser Function,  Up: Interface

The Lexical Analyzer Function `yylex'
=====================================

   The "lexical analyzer" function, `yylex', recognizes tokens from the
input stream and returns them to the parser.  Bison does not create
this function automatically; you must write it so that `yyparse' can
call it.  The function is sometimes referred to as a lexical scanner.

   In simple programs, `yylex' is often defined at the end of the Bison
grammar file.  If `yylex' is defined in a separate source file, you
need to arrange for the token-type macro definitions to be available
there.  To do this, use the `-d' option when you run Bison, so that it
will write these macro definitions into a separate header file
`NAME.tab.h' which you can include in the other source files that need
it.  *Note Invoking Bison: Invocation.

* Menu:

* Calling Convention::  How `yyparse' calls `yylex'.
* Token Values::      How `yylex' must return the semantic value
                        of the token it has read.
* Token Positions::   How `yylex' must return the text position
                        (line number, etc.) of the token, if the
                        actions want that.
* Pure Calling::      How the calling convention differs
                        in a pure parser (*note A Pure (Reentrant) Parser: Pure Decl.).


File: bison.info,  Node: Calling Convention,  Next: Token Values,  Up: Lexical

Calling Convention for `yylex'
------------------------------

   The value that `yylex' returns must be the numeric code for the type
of token it has just found, or 0 for end-of-input.

   When a token is referred to in the grammar rules by a name, that name
in the parser file becomes a C macro whose definition is the proper
numeric code for that token type.  So `yylex' can use the name to
indicate that type.  *Note Symbols::.

   When a token is referred to in the grammar rules by a character
literal, the numeric code for that character is also the code for the
token type.  So `yylex' can simply return that character code.  The
null character must not be used this way, because its code is zero and
that is what signifies end-of-input.

   Here is an example showing these things:

     yylex ()
     {
       ...
       if (c == EOF)     /* Detect end of file. */
         return 0;
       ...
       if (c == '+' || c == '-')
         return c;      /* Assume token type for `+' is '+'. */
       ...
       return INT;      /* Return the type of the token. */
       ...
     }

This interface has been designed so that the output from the `lex'
utility can be used without change as the definition of `yylex'.

   If the grammar uses literal string tokens, there are two ways that
`yylex' can determine the token type codes for them:

   * If the grammar defines symbolic token names as aliases for the
     literal string tokens, `yylex' can use these symbolic names like
     all others.  In this case, the use of the literal string tokens in
     the grammar file has no effect on `yylex'.

   * `yylex' can find the multi-character token in the `yytname' table.
     The index of the token in the table is the token type's code.
     The name of a multi-character token is recorded in `yytname' with a
     double-quote, the token's characters, and another double-quote.
     The token's characters are not escaped in any way; they appear
     verbatim in the contents of the string in the table.

     Here's code for looking up a token in `yytname', assuming that the
     characters of the token are stored in `token_buffer'.

          for (i = 0; i < YYNTOKENS; i++)
            {
              if (yytname[i] != 0
                  && yytname[i][0] == '"'
                  && strncmp (yytname[i] + 1, token_buffer,
                              strlen (token_buffer))
                  && yytname[i][strlen (token_buffer) + 1] == '"'
                  && yytname[i][strlen (token_buffer) + 2] == 0)
                break;
            }

     The `yytname' table is generated only if you use the
     `%token_table' declaration.  *Note Decl Summary::.


File: bison.info,  Node: Token Values,  Next: Token Positions,  Prev: Calling Convention,  Up: Lexical

Semantic Values of Tokens
-------------------------

   In an ordinary (nonreentrant) parser, the semantic value of the
token must be stored into the global variable `yylval'.  When you are
using just one data type for semantic values, `yylval' has that type.
Thus, if the type is `int' (the default), you might write this in
`yylex':

       ...
       yylval = value;  /* Put value onto Bison stack. */
       return INT;      /* Return the type of the token. */
       ...

   When you are using multiple data types, `yylval''s type is a union
made from the `%union' declaration (*note The Collection of Value
Types: Union Decl.).  So when you store a token's value, you must use
the proper member of the union.  If the `%union' declaration looks like
this:

     %union {
       int intval;
       double val;
       symrec *tptr;
     }

then the code in `yylex' might look like this:

       ...
       yylval.intval = value; /* Put value onto Bison stack. */
       return INT;          /* Return the type of the token. */
       ...


File: bison.info,  Node: Token Positions,  Next: Pure Calling,  Prev: Token Values,  Up: Lexical

Textual Positions of Tokens
---------------------------

   If you are using the `@N'-feature (*note Special Features for Use in
Actions: Action Features.) in actions to keep track of the textual
locations of tokens and groupings, then you must provide this
information in `yylex'.  The function `yyparse' expects to find the
textual location of a token just parsed in the global variable
`yylloc'.  So `yylex' must store the proper data in that variable.  The
value of `yylloc' is a structure and you need only initialize the
members that are going to be used by the actions.  The four members are
called `first_line', `first_column', `last_line' and `last_column'.
Note that the use of this feature makes the parser noticeably slower.

   The data type of `yylloc' has the name `YYLTYPE'.


File: bison.info,  Node: Pure Calling,  Prev: Token Positions,  Up: Lexical

Calling Conventions for Pure Parsers
------------------------------------

   When you use the Bison declaration `%pure_parser' to request a pure,
reentrant parser, the global communication variables `yylval' and
`yylloc' cannot be used.  (*Note A Pure (Reentrant) Parser: Pure Decl.)
In such parsers the two global variables are replaced by pointers
passed as arguments to `yylex'.  You must declare them as shown here,
and pass the information back by storing it through those pointers.

     yylex (lvalp, llocp)
          YYSTYPE *lvalp;
          YYLTYPE *llocp;
     {
       ...
       *lvalp = value;  /* Put value onto Bison stack.  */
       return INT;      /* Return the type of the token.  */
       ...
     }

   If the grammar file does not use the `@' constructs to refer to
textual positions, then the type `YYLTYPE' will not be defined.  In
this case, omit the second argument; `yylex' will be called with only
one argument.

   If you use a reentrant parser, you can optionally pass additional
parameter information to it in a reentrant way.  To do so, define the
macro `YYPARSE_PARAM' as a variable name.  This modifies the `yyparse'
function to accept one argument, of type `void *', with that name.

   When you call `yyparse', pass the address of an object, casting the
address to `void *'.  The grammar actions can refer to the contents of
the object by casting the pointer value back to its proper type and
then dereferencing it.  Here's an example.  Write this in the parser:

     %{
     struct parser_control
     {
       int nastiness;
       int randomness;
     };
     
     #define YYPARSE_PARAM parm
     %}

Then call the parser like this:

     struct parser_control
     {
       int nastiness;
       int randomness;
     };
     
     ...
     
     {
       struct parser_control foo;
       ...  /* Store proper data in `foo'.  */
       value = yyparse ((void *) &foo);
       ...
     }

In the grammar actions, use expressions like this to refer to the data:

     ((struct parser_control *) parm)->randomness

   If you wish to pass the additional parameter data to `yylex', define
the macro `YYLEX_PARAM' just like `YYPARSE_PARAM', as shown here:

     %{
     struct parser_control
     {
       int nastiness;
       int randomness;
     };
     
     #define YYPARSE_PARAM parm
     #define YYLEX_PARAM parm
     %}

   You should then define `yylex' to accept one additional
argument--the value of `parm'.  (This makes either two or three
arguments in total, depending on whether an argument of type `YYLTYPE'
is passed.)  You can declare the argument as a pointer to the proper
object type, or you can declare it as `void *' and access the contents
as shown above.

   You can use `%pure_parser' to request a reentrant parser without
also using `YYPARSE_PARAM'.  Then you should call `yyparse' with no
arguments, as usual.


File: bison.info,  Node: Error Reporting,  Next: Action Features,  Prev: Lexical,  Up: Interface

The Error Reporting Function `yyerror'
======================================

   The Bison parser detects a "parse error" or "syntax error" whenever
it reads a token which cannot satisfy any syntax rule.  A action in the
grammar can also explicitly proclaim an error, using the macro
`YYERROR' (*note Special Features for Use in Actions: Action Features.).

   The Bison parser expects to report the error by calling an error
reporting function named `yyerror', which you must supply.  It is
called by `yyparse' whenever a syntax error is found, and it receives
one argument.  For a parse error, the string is normally
`"parse error"'.

   If you define the macro `YYERROR_VERBOSE' in the Bison declarations
section (*note The Bison Declarations Section: Bison Declarations.),
then Bison provides a more verbose and specific error message string
instead of just plain `"parse error"'.  It doesn't matter what
definition you use for `YYERROR_VERBOSE', just whether you define it.

   The parser can detect one other kind of error: stack overflow.  This
happens when the input contains constructions that are very deeply
nested.  It isn't likely you will encounter this, since the Bison
parser extends its stack automatically up to a very large limit.  But
if overflow happens, `yyparse' calls `yyerror' in the usual fashion,
except that the argument string is `"parser stack overflow"'.

   The following definition suffices in simple programs:

     yyerror (s)
          char *s;
     {
       fprintf (stderr, "%s\n", s);
     }

   After `yyerror' returns to `yyparse', the latter will attempt error
recovery if you have written suitable error recovery grammar rules
(*note Error Recovery::).  If recovery is impossible, `yyparse' will
immediately return 1.

   The variable `yynerrs' contains the number of syntax errors
encountered so far.  Normally this variable is global; but if you
request a pure parser (*note A Pure (Reentrant) Parser: Pure Decl.)
then it is a local variable which only the actions can access.


File: bison.info,  Node: Action Features,  Prev: Error Reporting,  Up: Interface

Special Features for Use in Actions
===================================

   Here is a table of Bison constructs, variables and macros that are
useful in actions.

`$$'
     Acts like a variable that contains the semantic value for the
     grouping made by the current rule.  *Note Actions::.

`$N'
     Acts like a variable that contains the semantic value for the Nth
     component of the current rule.  *Note Actions::.

`$<TYPEALT>$'
     Like `$$' but specifies alternative TYPEALT in the union specified
     by the `%union' declaration.  *Note Data Types of Values in
     Actions: Action Types.

`$<TYPEALT>N'
     Like `$N' but specifies alternative TYPEALT in the union specified
     by the `%union' declaration.  *Note Data Types of Values in
     Actions: Action Types.

`YYABORT;'
     Return immediately from `yyparse', indicating failure.  *Note The
     Parser Function `yyparse': Parser Function.

`YYACCEPT;'
     Return immediately from `yyparse', indicating success.  *Note The
     Parser Function `yyparse': Parser Function.

`YYBACKUP (TOKEN, VALUE);'
     Unshift a token.  This macro is allowed only for rules that reduce
     a single value, and only when there is no look-ahead token.  It
     installs a look-ahead token with token type TOKEN and semantic
     value VALUE; then it discards the value that was going to be
     reduced by this rule.

     If the macro is used when it is not valid, such as when there is a
     look-ahead token already, then it reports a syntax error with a
     message `cannot back up' and performs ordinary error recovery.

     In either case, the rest of the action is not executed.

`YYEMPTY'
     Value stored in `yychar' when there is no look-ahead token.

`YYERROR;'
     Cause an immediate syntax error.  This statement initiates error
     recovery just as if the parser itself had detected an error;
     however, it does not call `yyerror', and does not print any
     message.  If you want to print an error message, call `yyerror'
     explicitly before the `YYERROR;' statement.  *Note Error
     Recovery::.

`YYRECOVERING'
     This macro stands for an expression that has the value 1 when the
     parser is recovering from a syntax error, and 0 the rest of the
     time.  *Note Error Recovery::.

`yychar'
     Variable containing the current look-ahead token.  (In a pure
     parser, this is actually a local variable within `yyparse'.)  When
     there is no look-ahead token, the value `YYEMPTY' is stored in the
     variable.  *Note Look-Ahead Tokens: Look-Ahead.

`yyclearin;'
     Discard the current look-ahead token.  This is useful primarily in
     error rules.  *Note Error Recovery::.

`yyerrok;'
     Resume generating error messages immediately for subsequent syntax
     errors.  This is useful primarily in error rules.  *Note Error
     Recovery::.

`@N'
     Acts like a structure variable containing information on the line
     numbers and column numbers of the Nth component of the current
     rule.  The structure has four members, like this:

          struct {
            int first_line, last_line;
            int first_column, last_column;
          };

     Thus, to get the starting line number of the third component, you
     would use `@3.first_line'.

     In order for the members of this structure to contain valid
     information, you must make `yylex' supply this information about
     each token.  If you need only certain members, then `yylex' need
     only fill in those members.

     The use of this feature makes the parser noticeably slower.


File: bison.info,  Node: Algorithm,  Next: Error Recovery,  Prev: Interface,  Up: Top

The Bison Parser Algorithm
**************************

   As Bison reads tokens, it pushes them onto a stack along with their
semantic values.  The stack is called the "parser stack".  Pushing a
token is traditionally called "shifting".

   For example, suppose the infix calculator has read `1 + 5 *', with a
`3' to come.  The stack will have four elements, one for each token
that was shifted.

   But the stack does not always have an element for each token read.
When the last N tokens and groupings shifted match the components of a
grammar rule, they can be combined according to that rule.  This is
called "reduction".  Those tokens and groupings are replaced on the
stack by a single grouping whose symbol is the result (left hand side)
of that rule.  Running the rule's action is part of the process of
reduction, because this is what computes the semantic value of the
resulting grouping.

   For example, if the infix calculator's parser stack contains this:

     1 + 5 * 3

and the next input token is a newline character, then the last three
elements can be reduced to 15 via the rule:

     expr: expr '*' expr;

Then the stack contains just these three elements:

     1 + 15

At this point, another reduction can be made, resulting in the single
value 16.  Then the newline token can be shifted.

   The parser tries, by shifts and reductions, to reduce the entire
input down to a single grouping whose symbol is the grammar's
start-symbol (*note Languages and Context-Free Grammars: Language and
Grammar.).

   This kind of parser is known in the literature as a bottom-up parser.

* Menu:

* Look-Ahead::        Parser looks one token ahead when deciding what to do.
* Shift/Reduce::      Conflicts: when either shifting or reduction is valid.
* Precedence::        Operator precedence works by resolving conflicts.
* Contextual Precedence::  When an operator's precedence depends on context.
* Parser States::     The parser is a finite-state-machine with stack.
* Reduce/Reduce::     When two rules are applicable in the same situation.
* Mystery Conflicts::  Reduce/reduce conflicts that look unjustified.
* Stack Overflow::    What happens when stack gets full.  How to avoid it.


File: bison.info,  Node: Look-Ahead,  Next: Shift/Reduce,  Up: Algorithm

Look-Ahead Tokens
=================

   The Bison parser does _not_ always reduce immediately as soon as the
last N tokens and groupings match a rule.  This is because such a
simple strategy is inadequate to handle most languages.  Instead, when a
reduction is possible, the parser sometimes "looks ahead" at the next
token in order to decide what to do.

   When a token is read, it is not immediately shifted; first it
becomes the "look-ahead token", which is not on the stack.  Now the
parser can perform one or more reductions of tokens and groupings on
the stack, while the look-ahead token remains off to the side.  When no
more reductions should take place, the look-ahead token is shifted onto
the stack.  This does not mean that all possible reductions have been
done; depending on the token type of the look-ahead token, some rules
may choose to delay their application.

   Here is a simple case where look-ahead is needed.  These three rules
define expressions which contain binary addition operators and postfix
unary factorial operators (`!'), and allow parentheses for grouping.

     expr:     term '+' expr
             | term
             ;
     
     term:     '(' expr ')'
             | term '!'
             | NUMBER
             ;

   Suppose that the tokens `1 + 2' have been read and shifted; what
should be done?  If the following token is `)', then the first three
tokens must be reduced to form an `expr'.  This is the only valid
course, because shifting the `)' would produce a sequence of symbols
`term ')'', and no rule allows this.

   If the following token is `!', then it must be shifted immediately so
that `2 !' can be reduced to make a `term'.  If instead the parser were
to reduce before shifting, `1 + 2' would become an `expr'.  It would
then be impossible to shift the `!' because doing so would produce on
the stack the sequence of symbols `expr '!''.  No rule allows that
sequence.

   The current look-ahead token is stored in the variable `yychar'.
*Note Special Features for Use in Actions: Action Features.


File: bison.info,  Node: Shift/Reduce,  Next: Precedence,  Prev: Look-Ahead,  Up: Algorithm

Shift/Reduce Conflicts
======================

   Suppose we are parsing a language which has if-then and if-then-else
statements, with a pair of rules like this:

     if_stmt:
               IF expr THEN stmt
             | IF expr THEN stmt ELSE stmt
             ;

Here we assume that `IF', `THEN' and `ELSE' are terminal symbols for
specific keyword tokens.

   When the `ELSE' token is read and becomes the look-ahead token, the
contents of the stack (assuming the input is valid) are just right for
reduction by the first rule.  But it is also legitimate to shift the
`ELSE', because that would lead to eventual reduction by the second
rule.

   This situation, where either a shift or a reduction would be valid,
is called a "shift/reduce conflict".  Bison is designed to resolve
these conflicts by choosing to shift, unless otherwise directed by
operator precedence declarations.  To see the reason for this, let's
contrast it with the other alternative.

   Since the parser prefers to shift the `ELSE', the result is to attach
the else-clause to the innermost if-statement, making these two inputs
equivalent:

     if x then if y then win (); else lose;
     
     if x then do; if y then win (); else lose; end;

   But if the parser chose to reduce when possible rather than shift,
the result would be to attach the else-clause to the outermost
if-statement, making these two inputs equivalent:

     if x then if y then win (); else lose;
     
     if x then do; if y then win (); end; else lose;

   The conflict exists because the grammar as written is ambiguous:
either parsing of the simple nested if-statement is legitimate.  The
established convention is that these ambiguities are resolved by
attaching the else-clause to the innermost if-statement; this is what
Bison accomplishes by choosing to shift rather than reduce.  (It would
ideally be cleaner to write an unambiguous grammar, but that is very
hard to do in this case.)  This particular ambiguity was first
encountered in the specifications of Algol 60 and is called the
"dangling `else'" ambiguity.

   To avoid warnings from Bison about predictable, legitimate
shift/reduce conflicts, use the `%expect N' declaration.  There will be
no warning as long as the number of shift/reduce conflicts is exactly N.
*Note Suppressing Conflict Warnings: Expect Decl.

   The definition of `if_stmt' above is solely to blame for the
conflict, but the conflict does not actually appear without additional
rules.  Here is a complete Bison input file that actually manifests the
conflict:

     %token IF THEN ELSE variable
     %%
     stmt:     expr
             | if_stmt
             ;
     
     if_stmt:
               IF expr THEN stmt
             | IF expr THEN stmt ELSE stmt
             ;
     
     expr:     variable
             ;


File: bison.info,  Node: Precedence,  Next: Contextual Precedence,  Prev: Shift/Reduce,  Up: Algorithm

Operator Precedence
===================

   Another situation where shift/reduce conflicts appear is in
arithmetic expressions.  Here shifting is not always the preferred
resolution; the Bison declarations for operator precedence allow you to
specify when to shift and when to reduce.

* Menu:

* Why Precedence::    An example showing why precedence is needed.
* Using Precedence::  How to specify precedence in Bison grammars.
* Precedence Examples::  How these features are used in the previous example.
* How Precedence::    How they work.


File: bison.info,  Node: Why Precedence,  Next: Using Precedence,  Up: Precedence

When Precedence is Needed
-------------------------

   Consider the following ambiguous grammar fragment (ambiguous because
the input `1 - 2 * 3' can be parsed in two different ways):

     expr:     expr '-' expr
             | expr '*' expr
             | expr '<' expr
             | '(' expr ')'
             ...
             ;

Suppose the parser has seen the tokens `1', `-' and `2'; should it
reduce them via the rule for the addition operator?  It depends on the
next token.  Of course, if the next token is `)', we must reduce;
shifting is invalid because no single rule can reduce the token
sequence `- 2 )' or anything starting with that.  But if the next token
is `*' or `<', we have a choice: either shifting or reduction would
allow the parse to complete, but with different results.

   To decide which one Bison should do, we must consider the results.
If the next operator token OP is shifted, then it must be reduced first
in order to permit another opportunity to reduce the sum.  The result
is (in effect) `1 - (2 OP 3)'.  On the other hand, if the subtraction
is reduced before shifting OP, the result is `(1 - 2) OP 3'.  Clearly,
then, the choice of shift or reduce should depend on the relative
precedence of the operators `-' and OP: `*' should be shifted first,
but not `<'.

   What about input such as `1 - 2 - 5'; should this be `(1 - 2) - 5'
or should it be `1 - (2 - 5)'?  For most operators we prefer the
former, which is called "left association".  The latter alternative,
"right association", is desirable for assignment operators.  The choice
of left or right association is a matter of whether the parser chooses
to shift or reduce when the stack contains `1 - 2' and the look-ahead
token is `-': shifting makes right-associativity.


File: bison.info,  Node: Using Precedence,  Next: Precedence Examples,  Prev: Why Precedence,  Up: Precedence

Specifying Operator Precedence
------------------------------

   Bison allows you to specify these choices with the operator
precedence declarations `%left' and `%right'.  Each such declaration
contains a list of tokens, which are operators whose precedence and
associativity is being declared.  The `%left' declaration makes all
those operators left-associative and the `%right' declaration makes
them right-associative.  A third alternative is `%nonassoc', which
declares that it is a syntax error to find the same operator twice "in a
row".

   The relative precedence of different operators is controlled by the
order in which they are declared.  The first `%left' or `%right'
declaration in the file declares the operators whose precedence is
lowest, the next such declaration declares the operators whose
precedence is a little higher, and so on.


File: bison.info,  Node: Precedence Examples,  Next: How Precedence,  Prev: Using Precedence,  Up: Precedence

Precedence Examples
-------------------

   In our example, we would want the following declarations:

     %left '<'
     %left '-'
     %left '*'

   In a more complete example, which supports other operators as well,
we would declare them in groups of equal precedence.  For example,
`'+'' is declared with `'-'':

     %left '<' '>' '=' NE LE GE
     %left '+' '-'
     %left '*' '/'

(Here `NE' and so on stand for the operators for "not equal" and so on.
We assume that these tokens are more than one character long and
therefore are represented by names, not character literals.)

