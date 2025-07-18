/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INDENT = 258,
     DEDENT = 259,
     NEWLINE = 260,
     IF = 261,
     ELIF = 262,
     ELSE = 263,
     FOR = 264,
     WHILE = 265,
     BREAK = 266,
     CONTINUE = 267,
     DEF = 268,
     RETURN = 269,
     PRINT = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     EQ = 274,
     NEQ = 275,
     LT = 276,
     GT = 277,
     LTE = 278,
     GTE = 279,
     PLUS = 280,
     MINUS = 281,
     MULT = 282,
     DIV = 283,
     MOD = 284,
     LBRACK = 285,
     RBRACK = 286,
     LPAREN = 287,
     RPAREN = 288,
     COMMA = 289,
     COLON = 290,
     IN = 291,
     RANGE = 292,
     IDENTIFIER = 293,
     STRING = 294,
     INTEGER = 295,
     FLOAT = 296,
     BOOLEAN = 297,
     VAR = 298,
     CONST = 299,
     TYPE_INT = 300,
     TYPE_FLOAT = 301,
     TYPE_STR = 302,
     TYPE_BOOL = 303,
     TYPE_ARRAY = 304
   };
#endif
/* Tokens.  */
#define INDENT 258
#define DEDENT 259
#define NEWLINE 260
#define IF 261
#define ELIF 262
#define ELSE 263
#define FOR 264
#define WHILE 265
#define BREAK 266
#define CONTINUE 267
#define DEF 268
#define RETURN 269
#define PRINT 270
#define AND 271
#define OR 272
#define NOT 273
#define EQ 274
#define NEQ 275
#define LT 276
#define GT 277
#define LTE 278
#define GTE 279
#define PLUS 280
#define MINUS 281
#define MULT 282
#define DIV 283
#define MOD 284
#define LBRACK 285
#define RBRACK 286
#define LPAREN 287
#define RPAREN 288
#define COMMA 289
#define COLON 290
#define IN 291
#define RANGE 292
#define IDENTIFIER 293
#define STRING 294
#define INTEGER 295
#define FLOAT 296
#define BOOLEAN 297
#define VAR 298
#define CONST 299
#define TYPE_INT 300
#define TYPE_FLOAT 301
#define TYPE_STR 302
#define TYPE_BOOL 303
#define TYPE_ARRAY 304




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "symbol_table.hpp"
#include "type_checker.hpp"
extern int yylex(void);
extern int yylineno;

// Variables globales
SymbolTable symTable;
TypeChecker typeChecker(symTable);
int currentScope = 0;
std::stringstream jsCode;  // Acumula el código JavaScript generado

// Prototipos
void yyerror(const char *s);
std::string translateExpression(const std::string& pyExpr);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "parser.y"
{
    std::string* str;
    int int_val;
    double float_val;
    bool bool_val;
}
/* Line 193 of yacc.c.  */
#line 222 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 235 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,     2,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      20,    24,    29,    40,    42,    45,    46,    48,    52,    60,
      69,    76,    85,    95,   108,   116,   118,   121,   123,   127,
     131,   133,   137,   141,   145,   147,   149,   151,   153,   155,
     157,   159,   163,   167,   168,   170,   174,   179,   184,   185,
     187
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    55,    56,    -1,    57,    -1,    58,
      -1,    61,    -1,    63,    -1,    64,    -1,    66,     5,    -1,
      14,    66,     5,    -1,    38,    50,    66,     5,    -1,    13,
      38,    51,    60,    52,    53,     5,     3,    59,     4,    -1,
      56,    -1,    59,    56,    -1,    -1,    38,    -1,    60,    34,
      38,    -1,     6,    66,    53,     5,     3,    65,     4,    -1,
       6,    66,    53,     5,     3,    65,     4,    62,    -1,     8,
      53,     5,     3,    65,     4,    -1,     7,    66,    53,     5,
       3,    65,     4,    62,    -1,     9,    38,    36,    38,    53,
       5,     3,    65,     4,    -1,     9,    38,    36,    37,    51,
      40,    52,    53,     5,     3,    65,     4,    -1,    10,    66,
      53,     5,     3,    65,     4,    -1,    56,    -1,    65,    56,
      -1,    67,    -1,    66,    25,    67,    -1,    66,    26,    67,
      -1,    68,    -1,    67,    27,    68,    -1,    67,    28,    68,
      -1,    67,    29,    68,    -1,    40,    -1,    41,    -1,    39,
      -1,    42,    -1,    38,    -1,    69,    -1,    71,    -1,    51,
      66,    52,    -1,    30,    70,    31,    -1,    -1,    66,    -1,
      70,    34,    66,    -1,    38,    51,    72,    52,    -1,    15,
      51,    72,    52,    -1,    -1,    66,    -1,    72,    34,    66,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    56,    60,    61,    62,    63,    64,    65,
      70,    77,    89,    99,   100,   104,   105,   110,   120,   126,
     136,   140,   149,   156,   166,   175,   176,   180,   181,   182,
     186,   187,   188,   189,   193,   194,   195,   196,   197,   198,
     199,   200,   204,   208,   209,   210,   214,   215,   219,   220,
     221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INDENT", "DEDENT", "NEWLINE", "IF",
  "ELIF", "ELSE", "FOR", "WHILE", "BREAK", "CONTINUE", "DEF", "RETURN",
  "PRINT", "AND", "OR", "NOT", "EQ", "NEQ", "LT", "GT", "LTE", "GTE",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "LBRACK", "RBRACK", "LPAREN",
  "RPAREN", "COMMA", "COLON", "IN", "RANGE", "IDENTIFIER", "STRING",
  "INTEGER", "FLOAT", "BOOLEAN", "VAR", "CONST", "TYPE_INT", "TYPE_FLOAT",
  "TYPE_STR", "TYPE_BOOL", "TYPE_ARRAY", "'='", "'('", "')'", "':'",
  "$accept", "program", "statement", "var_declaration", "function_def",
  "function_body", "params", "if_statement", "else_clause", "for_loop",
  "while_loop", "block", "expression", "term", "factor", "array_literal",
  "elements", "function_call", "arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      61,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    65,    65,    66,    66,    66,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    72,
      72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     2,
       3,     4,    10,     1,     2,     0,     1,     3,     7,     8,
       6,     8,     9,    12,     7,     1,     2,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     0,     1,     3,     4,     4,     0,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,    43,
      38,    36,    34,    35,    37,     0,     3,     4,     5,     6,
       7,     8,     0,    27,    30,    39,    40,    38,     0,     0,
       0,     0,     0,    48,    44,     0,     0,    48,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    10,
      49,     0,    42,     0,     0,     0,    41,    28,    29,    31,
      32,    33,     0,     0,     0,     0,    16,     0,     0,    47,
      45,    11,    46,     0,     0,     0,     0,     0,     0,    50,
      25,     0,     0,     0,     0,    17,     0,    18,    26,     0,
       0,    24,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    22,    13,     0,     0,     0,     0,    12,    14,
       0,     0,     0,     0,     0,    23,     0,    20,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    80,    17,    18,   104,    67,    19,    95,    20,
      21,    81,    22,    23,    24,    25,    35,    26,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int16 yypact[] =
{
     -44,     2,   -44,   115,   -34,   115,   -24,   115,   -27,   115,
     -21,   -44,   -44,   -44,   -44,   115,   -44,   -44,   -44,   -44,
     -44,   -44,     1,    44,   -44,   -44,   -44,   -15,   -16,     9,
      -7,    14,    34,   115,    56,    -6,   115,   115,    -3,   -44,
     115,   115,   115,   115,   115,    45,    63,    64,    39,   -44,
      56,     4,   -44,   115,    50,    33,   -44,    44,    44,   -44,
     -44,   -44,    76,    47,    31,    99,   -44,    40,   115,   -44,
      56,   -44,   -44,   267,    68,   104,   267,    72,    67,    56,
     -44,    48,    73,   113,   108,   -44,   114,    97,   -44,    71,
     267,   -44,   124,   115,    80,   -44,   129,   122,   267,    -5,
     134,   126,   -44,   -44,   161,   135,   138,   267,   -44,   -44,
     139,   267,   175,   267,   214,   -44,   228,   -44,    97,   -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,    -1,   -44,   -44,   -44,   -44,   -44,    25,   -44,
     -44,   -43,    -2,    66,    51,   -44,   -44,   -44,   107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      16,    28,     2,    30,    29,    32,    39,    34,     3,    40,
      41,     4,     5,    38,    31,     6,     7,     8,    40,    41,
      40,    41,    40,    41,    33,    52,    40,    41,    53,    36,
      37,    50,     9,    84,    54,    50,    37,    45,    68,    49,
      10,    11,    12,    13,    14,    46,    47,    97,   105,    56,
      62,    70,    87,    15,     3,    71,    69,     4,     5,    40,
      41,     6,     7,     8,   112,    48,    79,    68,   114,    65,
     116,    42,    43,    44,    77,    40,    41,    66,     9,    73,
      88,    40,    41,    88,    75,    72,    10,    11,    12,    13,
      14,    99,    78,    59,    60,    61,    88,   103,    74,    15,
      63,    64,    76,   109,    93,    94,    57,    58,    82,    83,
      85,    88,    91,    88,     3,    88,    90,     4,     5,    92,
      86,     6,     7,     8,    96,    89,   102,    98,     3,   107,
       8,     4,     5,   100,   101,     6,     7,     8,     9,   106,
     110,   111,   113,   119,    55,     9,    10,    11,    12,    13,
      14,     0,     9,    27,    11,    12,    13,    14,     0,    15,
      10,    11,    12,    13,    14,   108,    15,     3,     0,     0,
       4,     5,     0,    15,     6,     7,     8,     0,     0,   115,
       0,     3,     0,     0,     4,     5,     0,     0,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,     0,     9,     0,     0,     0,     0,
       0,     0,    15,    10,    11,    12,    13,    14,   117,     0,
       3,     0,     0,     4,     5,     0,    15,     6,     7,     8,
       0,     0,   118,     0,     3,     0,     0,     4,     5,     0,
       0,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,     0,     9,     0,
       0,     0,     0,     0,     0,    15,    10,    11,    12,    13,
      14,     0,     0,     3,     0,     0,     4,     5,     0,    15,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,    15
};

static const yytype_int8 yycheck[] =
{
       1,     3,     0,     5,    38,     7,     5,     9,     6,    25,
      26,     9,    10,    15,    38,    13,    14,    15,    25,    26,
      25,    26,    25,    26,    51,    31,    25,    26,    34,    50,
      51,    33,    30,    76,    36,    37,    51,    53,    34,     5,
      38,    39,    40,    41,    42,    36,    53,    90,    53,    52,
       5,    53,     4,    51,     6,     5,    52,     9,    10,    25,
      26,    13,    14,    15,   107,    51,    68,    34,   111,     5,
     113,    27,    28,    29,    34,    25,    26,    38,    30,     3,
      81,    25,    26,    84,    53,    52,    38,    39,    40,    41,
      42,    93,    52,    42,    43,    44,    97,    98,    51,    51,
      37,    38,     3,   104,     7,     8,    40,    41,    40,     5,
      38,   112,     4,   114,     6,   116,     3,     9,    10,     5,
      53,    13,    14,    15,    53,    52,     4,     3,     6,     3,
      15,     9,    10,    53,     5,    13,    14,    15,    30,     5,
       5,     3,     3,   118,    37,    30,    38,    39,    40,    41,
      42,    -1,    30,    38,    39,    40,    41,    42,    -1,    51,
      38,    39,    40,    41,    42,     4,    51,     6,    -1,    -1,
       9,    10,    -1,    51,    13,    14,    15,    -1,    -1,     4,
      -1,     6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    38,    39,    40,    41,    42,     4,    -1,
       6,    -1,    -1,     9,    10,    -1,    51,    13,    14,    15,
      -1,    -1,     4,    -1,     6,    -1,    -1,     9,    10,    -1,
      -1,    13,    14,    15,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    38,    39,    40,    41,
      42,    -1,    -1,     6,    -1,    -1,     9,    10,    -1,    51,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     6,     9,    10,    13,    14,    15,    30,
      38,    39,    40,    41,    42,    51,    56,    57,    58,    61,
      63,    64,    66,    67,    68,    69,    71,    38,    66,    38,
      66,    38,    66,    51,    66,    70,    50,    51,    66,     5,
      25,    26,    27,    28,    29,    53,    36,    53,    51,     5,
      66,    72,    31,    34,    66,    72,    52,    67,    67,    68,
      68,    68,     5,    37,    38,     5,    38,    60,    34,    52,
      66,     5,    52,     3,    51,    53,     3,    34,    52,    66,
      56,    65,    40,     5,    65,    38,    53,     4,    56,    52,
       3,     4,     5,     7,     8,    62,    53,    65,     3,    66,
      53,     5,     4,    56,    59,    53,     5,     3,     4,    56,
       5,     3,    65,     3,    65,     4,    65,     4,     4,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "parser.y"
    { (yyval.str) = new std::string(""); ;}
    break;

  case 3:
#line 56 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str)); delete (yyvsp[(1) - (2)].str); delete (yyvsp[(2) - (2)].str); ;}
    break;

  case 4:
#line 60 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 5:
#line 61 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 6:
#line 62 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 7:
#line 63 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 8:
#line 64 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 9:
#line 65 "parser.y"
    {
        jsCode << *(yyvsp[(1) - (2)].str) << ";\n";
        (yyval.str) = new std::string(*(yyvsp[(1) - (2)].str) + ";\n");
        delete (yyvsp[(1) - (2)].str);
    ;}
    break;

  case 10:
#line 70 "parser.y"
    {
        jsCode << "return " << *(yyvsp[(2) - (3)].str) << ";\n";
        (yyval.str) = new std::string("return " + *(yyvsp[(2) - (3)].str) + ";\n");
        delete (yyvsp[(2) - (3)].str);
    ;}
    break;

  case 11:
#line 77 "parser.y"
    {
        if (!symTable.exists(*(yyvsp[(1) - (4)].str))) {
            symTable.addSymbol(*(yyvsp[(1) - (4)].str), "auto");
        }
        (yyval.str) = new std::string("let " + *(yyvsp[(1) - (4)].str) + " = " + *(yyvsp[(3) - (4)].str) + ";\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(1) - (4)].str);
        delete (yyvsp[(3) - (4)].str);
    ;}
    break;

  case 12:
#line 89 "parser.y"
    {
        (yyval.str) = new std::string("function " + *(yyvsp[(2) - (10)].str) + "(" + *(yyvsp[(4) - (10)].str) + ") {\n" + *(yyvsp[(9) - (10)].str) + "}\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(2) - (10)].str);
        delete (yyvsp[(4) - (10)].str);
        delete (yyvsp[(9) - (10)].str);
    ;}
    break;

  case 13:
#line 99 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (1)].str)); delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 14:
#line 100 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str)); delete (yyvsp[(1) - (2)].str); delete (yyvsp[(2) - (2)].str); ;}
    break;

  case 15:
#line 104 "parser.y"
    { (yyval.str) = new std::string(""); ;}
    break;

  case 16:
#line 105 "parser.y"
    { 
        (yyval.str) = new std::string(*(yyvsp[(1) - (1)].str));
        symTable.addSymbol(*(yyvsp[(1) - (1)].str), "param");
        delete (yyvsp[(1) - (1)].str);
      ;}
    break;

  case 17:
#line 110 "parser.y"
    { 
        (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + ", " + *(yyvsp[(3) - (3)].str));
        symTable.addSymbol(*(yyvsp[(3) - (3)].str), "param");
        delete (yyvsp[(1) - (3)].str);
        delete (yyvsp[(3) - (3)].str);
      ;}
    break;

  case 18:
#line 120 "parser.y"
    {
        (yyval.str) = new std::string("if (" + *(yyvsp[(2) - (7)].str) + ") {\n" + *(yyvsp[(6) - (7)].str) + "}\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(2) - (7)].str);
        delete (yyvsp[(6) - (7)].str);
    ;}
    break;

  case 19:
#line 126 "parser.y"
    {
        (yyval.str) = new std::string("if (" + *(yyvsp[(2) - (8)].str) + ") {\n" + *(yyvsp[(6) - (8)].str) + "} " + *(yyvsp[(8) - (8)].str) + "\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(2) - (8)].str);
        delete (yyvsp[(6) - (8)].str);
        delete (yyvsp[(8) - (8)].str);
    ;}
    break;

  case 20:
#line 136 "parser.y"
    {
        (yyval.str) = new std::string("else {\n" + *(yyvsp[(5) - (6)].str) + "}");
        delete (yyvsp[(5) - (6)].str);
    ;}
    break;

  case 21:
#line 140 "parser.y"
    {
        (yyval.str) = new std::string("else if (" + *(yyvsp[(2) - (8)].str) + ") {\n" + *(yyvsp[(6) - (8)].str) + "} " + *(yyvsp[(8) - (8)].str));
        delete (yyvsp[(2) - (8)].str);
        delete (yyvsp[(6) - (8)].str);
        delete (yyvsp[(8) - (8)].str);
    ;}
    break;

  case 22:
#line 149 "parser.y"
    {
        (yyval.str) = new std::string("for (let " + *(yyvsp[(2) - (9)].str) + " of " + *(yyvsp[(4) - (9)].str) + ") {\n" + *(yyvsp[(8) - (9)].str) + "}\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(2) - (9)].str);
        delete (yyvsp[(4) - (9)].str);
        delete (yyvsp[(8) - (9)].str);
    ;}
    break;

  case 23:
#line 156 "parser.y"
    {
        (yyval.str) = new std::string("for (let " + *(yyvsp[(2) - (12)].str) + " = 0; " + *(yyvsp[(2) - (12)].str) + " < " + std::to_string((yyvsp[(6) - (12)].int_val)) + "; " 
               + *(yyvsp[(2) - (12)].str) + "++) {\n" + *(yyvsp[(11) - (12)].str) + "}\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(2) - (12)].str);
        delete (yyvsp[(11) - (12)].str);
    ;}
    break;

  case 24:
#line 166 "parser.y"
    {
        (yyval.str) = new std::string("while (" + *(yyvsp[(2) - (7)].str) + ") {\n" + *(yyvsp[(6) - (7)].str) + "}\n");
        jsCode << *(yyval.str);
        delete (yyvsp[(2) - (7)].str);
        delete (yyvsp[(6) - (7)].str);
    ;}
    break;

  case 25:
#line 175 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (1)].str)); delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 26:
#line 176 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (2)].str) + *(yyvsp[(2) - (2)].str)); delete (yyvsp[(1) - (2)].str); delete (yyvsp[(2) - (2)].str); ;}
    break;

  case 27:
#line 180 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 28:
#line 181 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + " + " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;

  case 29:
#line 182 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + " - " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;

  case 30:
#line 186 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 31:
#line 187 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + " * " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;

  case 32:
#line 188 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + " / " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;

  case 33:
#line 189 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + " % " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;

  case 34:
#line 193 "parser.y"
    { (yyval.str) = new std::string(std::to_string((yyvsp[(1) - (1)].int_val))); ;}
    break;

  case 35:
#line 194 "parser.y"
    { (yyval.str) = new std::string(std::to_string((yyvsp[(1) - (1)].float_val))); ;}
    break;

  case 36:
#line 195 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (1)].str)); delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 37:
#line 196 "parser.y"
    { (yyval.str) = new std::string((*(yyvsp[(1) - (1)].bool_val) == "True") ? "true" : "false"); delete (yyvsp[(1) - (1)].bool_val); ;}
    break;

  case 38:
#line 197 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (1)].str)); delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 39:
#line 198 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 40:
#line 199 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 41:
#line 200 "parser.y"
    { (yyval.str) = new std::string("(" + *(yyvsp[(2) - (3)].str) + ")"); delete (yyvsp[(2) - (3)].str); ;}
    break;

  case 42:
#line 204 "parser.y"
    { (yyval.str) = new std::string("[" + *(yyvsp[(2) - (3)].str) + "]"); delete (yyvsp[(2) - (3)].str); ;}
    break;

  case 43:
#line 208 "parser.y"
    { (yyval.str) = new std::string(""); ;}
    break;

  case 44:
#line 209 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 45:
#line 210 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + ", " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;

  case 46:
#line 214 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (4)].str) + "(" + *(yyvsp[(3) - (4)].str) + ")"); delete (yyvsp[(1) - (4)].str); delete (yyvsp[(3) - (4)].str); ;}
    break;

  case 47:
#line 215 "parser.y"
    { (yyval.str) = new std::string("console.log(" + *(yyvsp[(3) - (4)].str) + ")"); delete (yyvsp[(3) - (4)].str); ;}
    break;

  case 48:
#line 219 "parser.y"
    { (yyval.str) = new std::string(""); ;}
    break;

  case 49:
#line 220 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 50:
#line 221 "parser.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str) + ", " + *(yyvsp[(3) - (3)].str)); delete (yyvsp[(1) - (3)].str); delete (yyvsp[(3) - (3)].str); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1881 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 240 "parser.y"


void yyerror(const char *s) {
    std::cerr << "Error de sintaxis: " << s << " en la línea " << yylineno << std::endl;
}

std::string translateExpression(const std::string& pyExpr) {
    // Conversiones específicas Python→JS
    if (pyExpr == "True") return "true";
    if (pyExpr == "False") return "false";
    if (pyExpr == "None") return "null";
    return pyExpr;
}

int main() {
    yyparse();
    std::cout << "// Código generado:\n";
    std::cout << jsCode.str();
    return 0;
}

