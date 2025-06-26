/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <map>
#include <algorithm> // Incluir para std::find
#include <cstring>
#include <sstream> // Para usar std::stringstream
#include <string>  // Para usar std::string

#include "parser.hpp"

std::map<std::string, std::string> symbol_table; // Tabla de símbolos
std::string* goalStr;
std::string* functionDeclarationsStr;



void yyerror(const char* err) {
  std::cerr << "Error de sintaxis: " << err << std::endl;
}
extern int yylex();
extern int yylineno;

int tipo_actual = 0;
int tipo_actual2 = 0;
int tipo_actual3 = 0;
int es_id = 0;


#line 100 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_TBOOLEAN = 5,                   /* TBOOLEAN  */
  YYSYMBOL_FBOOLEAN = 6,                   /* FBOOLEAN  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 10,                    /* DOUBLE  */
  YYSYMBOL_CONSTANT = 11,                  /* CONSTANT  */
  YYSYMBOL_EQUALS = 12,                    /* EQUALS  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_TIMES = 15,                     /* TIMES  */
  YYSYMBOL_DIVIDEDBY = 16,                 /* DIVIDEDBY  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NEQ = 18,                       /* NEQ  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_GTE = 20,                       /* GTE  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_LTE = 22,                       /* LTE  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_INDENT = 24,                    /* INDENT  */
  YYSYMBOL_DEDENT = 25,                    /* DEDENT  */
  YYSYMBOL_NEWLINE = 26,                   /* NEWLINE  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_COLON = 28,                     /* COLON  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_ELIF = 31,                      /* ELIF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_IN = 34,                        /* IN  */
  YYSYMBOL_RANGE = 35,                     /* RANGE  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_DEF = 39,                       /* DEF  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_LBRACK = 44,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 45,                    /* RBRACK  */
  YYSYMBOL_PRINT = 46,                     /* PRINT  */
  YYSYMBOL_UNKNOWN = 47,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_goal = 49,                      /* goal  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_parameter_list = 52,            /* parameter_list  */
  YYSYMBOL_argument_list = 53,             /* argument_list  */
  YYSYMBOL_argument = 54,                  /* argument  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_expression_for = 56,            /* expression_for  */
  YYSYMBOL_list = 57,                      /* list  */
  YYSYMBOL_elements = 58,                  /* elements  */
  YYSYMBOL_conditionalExpr = 59,           /* conditionalExpr  */
  YYSYMBOL_conditional = 60,               /* conditional  */
  YYSYMBOL_ifelse = 61,                    /* ifelse  */
  YYSYMBOL_flowcontrol = 62                /* flowcontrol  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    65,    69,    73,    74,    75,    76,    77,
      79,    80,   155,   196,   203,   225,   238,   274,   278,   285,
     286,   287,   294,   295,   297,   304,   305,   306,   307,   308,
     309,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   337,   338,   341,   342,
     345,   346,   349,   350,   351,   352,   353,   354,   355,   356,
     360,   361,   362,   363,   364,   368,   369,   373,   374,   375,
     379
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "TBOOLEAN", "FBOOLEAN", "FLOAT", "STRING", "CHAR", "DOUBLE",
  "CONSTANT", "EQUALS", "PLUS", "MINUS", "TIMES", "DIVIDEDBY", "EQ", "NEQ",
  "GT", "GTE", "LT", "LTE", "RETURN", "INDENT", "DEDENT", "NEWLINE", "IF",
  "COLON", "AND", "BREAK", "ELIF", "ELSE", "FOR", "IN", "RANGE", "NOT",
  "OR", "WHILE", "DEF", "SEMICOLON", "LPAREN", "RPAREN", "COMMA", "LBRACK",
  "RBRACK", "PRINT", "UNKNOWN", "$accept", "goal", "program", "statement",
  "parameter_list", "argument_list", "argument", "expression",
  "expression_for", "list", "elements", "conditionalExpr", "conditional",
  "ifelse", "flowcontrol", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -24,    -4,    -7,    51,    13,    88,    88,   -15,    14,
      88,    26,     2,    20,    47,     3,   -35,   -35,   -35,   -35,
     130,   147,   130,   -35,   -35,    27,    76,   -35,   -35,   -35,
     -35,   -35,   -35,    88,   158,   170,    29,    -8,   182,    22,
     130,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   130,   121,   129,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -27,   -35,   133,    55,    61,   194,    88,
      88,    88,    88,    88,    88,    42,    73,   -35,    67,    78,
     102,     6,    43,   -35,    97,   -34,   130,   130,   130,   130,
     -35,    80,   147,   -35,    91,    93,   194,   194,   194,   194,
     194,   194,   -35,   -35,    79,   -35,   -35,   -18,    95,   -35,
     130,   -35,    23,    23,   -35,   -35,   -35,   -35,   -35,   -35,
      57,   128,   116,   -35,    97,   -35,   -35,   118,   132,   -35,
     135,   -35,   138,   -35
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,    65,    18,
       0,    22,     0,    70,     9,     0,     0,    52,    53,    55,
      56,    54,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     1,     3,    36,    31,    34,    35,    32,    38,
      39,    33,    37,     0,     0,     0,    45,    30,    25,    28,
      29,    26,    27,     0,    23,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
      19,     0,     0,    48,    50,     0,     0,     0,     0,     0,
      11,     0,     0,    12,     0,     7,    63,    62,    59,    61,
      58,    60,    67,    69,     0,    66,    20,     0,     0,    40,
       0,    49,    41,    42,    43,    44,    15,    24,    10,     6,
       0,     0,     0,    16,    51,    47,    46,     0,     0,    21,
       0,    14,     0,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   -35,    -3,   -35,   -35,    69,   -22,   -35,   -35,
     -35,     0,   162,   -35,   -35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    14,    15,    16,   107,    63,    64,    55,   127,    56,
      85,    34,    17,    18,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    24,    19,    -2,     1,    22,     2,    35,    20,   110,
      38,   111,    43,    36,     3,    91,    92,    37,    81,    86,
      87,    88,    89,    67,   121,   122,    78,     4,     5,    39,
       6,    82,    84,    68,     7,     8,     9,    21,    88,    89,
       6,    10,    11,    40,     7,     8,    41,    42,   108,    12,
      13,    10,     1,    66,     2,    77,    86,    87,    88,    89,
     125,   126,     3,    80,   112,   113,   114,   115,   102,    96,
      97,    98,    99,   100,   101,     4,     5,     1,     6,     2,
      94,    23,     7,     8,     9,   109,    95,     3,   124,    10,
      11,    27,    28,    29,    30,    31,    32,    12,    13,   103,
       4,     5,   104,     6,   105,   106,   116,     7,     8,     9,
      86,    87,    88,    89,    10,    11,   118,    33,   119,   129,
     120,   123,    12,    13,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    86,    87,    88,    89,    86,    87,    88,    89,
      57,    58,    59,    60,    61,    90,   128,    62,   131,    93,
     130,   117,    53,   132,   133,    54,    83,    26,     0,     0,
       0,    53,     0,     0,    54,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,    75,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,    76,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
      79,    69,    70,    71,    72,    73,    74
};

static const yytype_int8 yycheck[] =
{
      22,     4,    26,     0,     1,    12,     3,     7,    12,    43,
      10,    45,    15,    28,    11,    42,    43,     3,    40,    13,
      14,    15,    16,    26,    42,    43,    34,    24,    25,     3,
      27,    53,    54,    33,    31,    32,    33,    41,    15,    16,
      27,    38,    39,    41,    31,    32,    26,     0,    42,    46,
      47,    38,     1,    26,     3,    26,    13,    14,    15,    16,
       3,     4,    11,    41,    86,    87,    88,    89,    26,    69,
      70,    71,    72,    73,    74,    24,    25,     1,    27,     3,
      25,    30,    31,    32,    33,    42,    25,    11,   110,    38,
      39,     3,     4,     5,     6,     7,     8,    46,    47,    26,
      24,    25,    35,    27,    26,     3,    26,    31,    32,    33,
      13,    14,    15,    16,    38,    39,    25,    29,    25,     3,
      41,    26,    46,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    13,    14,    15,    16,    13,    14,    15,    16,
       3,     4,     5,     6,     7,    26,    28,    10,    26,    26,
      42,    92,    41,    28,    26,    44,    45,     5,    -1,    -1,
      -1,    41,    -1,    -1,    44,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      28,    17,    18,    19,    20,    21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    11,    24,    25,    27,    31,    32,    33,
      38,    39,    46,    47,    49,    50,    51,    60,    61,    26,
      12,    41,    12,    30,    51,    62,    60,     3,     4,     5,
       6,     7,     8,    29,    59,    59,    28,     3,    59,     3,
      41,    26,     0,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    41,    44,    55,    57,     3,     4,     5,
       6,     7,    10,    53,    54,    55,    26,    51,    59,    17,
      18,    19,    20,    21,    22,    28,    28,    26,    34,    28,
      41,    55,    55,    45,    55,    58,    13,    14,    15,    16,
      26,    42,    43,    26,    25,    25,    59,    59,    59,    59,
      59,    59,    26,    26,    35,    26,     3,    52,    42,    42,
      43,    45,    55,    55,    55,    55,    26,    54,    25,    25,
      41,    42,    43,    26,    55,     3,     4,    56,    28,     3,
      42,    26,    28,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    61,
      62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     4,     1,     2,
       5,     4,     4,     9,     7,     5,     5,     2,     2,     0,
       1,     3,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     1,     1,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     4,     4,     3,     4,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* goal: program  */
#line 62 "parser.y"
            { }
#line 1368 "parser.cpp"
    break;

  case 3: /* program: program statement  */
#line 65 "parser.y"
                      {(yyval.str) = new std::string(*(yyvsp[-1].str) + *(yyvsp[0].str));
                      goalStr = new std::string(*(yyval.str));
                      delete (yyvsp[-1].str); delete (yyvsp[0].str); 
                       }
#line 1377 "parser.cpp"
    break;

  case 4: /* program: statement  */
#line 69 "parser.y"
              { (yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1383 "parser.cpp"
    break;

  case 5: /* statement: conditional  */
#line 73 "parser.y"
                {(yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str);}
#line 1389 "parser.cpp"
    break;

  case 6: /* statement: DEDENT conditional statement DEDENT DEDENT  */
#line 74 "parser.y"
                                               { (yyval.str) = new std::string("} " + *(yyvsp[-3].str) + "\n" + *(yyvsp[-2].str) + "}\n}\n"); delete (yyvsp[-3].str); delete (yyvsp[-2].str); }
#line 1395 "parser.cpp"
    break;

  case 7: /* statement: DEDENT conditional statement DEDENT  */
#line 75 "parser.y"
                                        { (yyval.str) = new std::string("} " + *(yyvsp[-2].str) + "\n" + *(yyvsp[-1].str) + "}\n"); delete (yyvsp[-2].str); delete (yyvsp[-1].str); }
#line 1401 "parser.cpp"
    break;

  case 8: /* statement: DEDENT  */
#line 76 "parser.y"
           { (yyval.str) = new std::string("}\n"); }
#line 1407 "parser.cpp"
    break;

  case 9: /* statement: INDENT statement  */
#line 77 "parser.y"
                     {(yyval.str) = new std::string("\t" + *(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1413 "parser.cpp"
    break;

  case 10: /* statement: INDENT flowcontrol NEWLINE DEDENT DEDENT  */
#line 79 "parser.y"
                                            { (yyval.str) = new std::string("break; \n}\n}\n"); delete (yyvsp[-3].str); }
#line 1419 "parser.cpp"
    break;

  case 11: /* statement: IDENTIFIER EQUALS expression NEWLINE  */
#line 80 "parser.y"
                                         {
        //std::cerr << "Entro a ID EQUALS statement \n";
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*(yyvsp[-3].str)) == symbol_table.end()) {
            // Determina el tipo del identificador
            std::string type;
            if (tipo_actual == 1 | tipo_actual == 6 ) type = "int";
            else if (tipo_actual == 2) type = "float";
            else if (tipo_actual == 3) type = "bool";
            else if (tipo_actual == 4) type = "char";
            else if (tipo_actual == 5) type = "lista";
            else if (tipo_actual == 7) type = "double";
            else {
                std::cerr << "Error: Tipo no reconocido para el identificador '" << *(yyvsp[-3].str) << "'. En linea: " << yylineno << std::endl;
                exit(1);
            }
            // Agrega el identificador a la tabla de símbolos con su tipo
            symbol_table[*(yyvsp[-3].str)] = type;
            // Construye la cadena de asignación para el output.c
            std::stringstream ss;
            if (type == "char"){ // Es una cadena char str[] = "GeeksforGeeks";
                ss << type << " " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 1){ // ES UN ARRAY INT
                ss << "int " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 2){ // ES UN ARRAY FLOAT
                ss << "float " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }
            else if(type == "lista" && tipo_actual2 == 3){ // ES UN CHARACTER ARRAY
                ss << "char " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }
            else{
                ss << type << " " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }

        } else { 
          // MANEJO DE ASIGNACIONES A VARIABLES DE DISTINTOS TIPOS

          // SI EL ID ES UN INT o UN FLOAT o un BOOL o un DOUBLE
          if(symbol_table[*(yyvsp[-3].str)] == "int" | symbol_table[*(yyvsp[-3].str)] == "float" | symbol_table[*(yyvsp[-3].str)] == "bool" | symbol_table[*(yyvsp[-3].str)] == "double" ){

              // Si la asignacion es a un INT, FLOAT, DOUBLE, BOOL (TRUE OR FALSE) --> la realizo sin prob
              if(tipo_actual == 1 | tipo_actual == 2 | tipo_actual == 7 | tipo_actual == 3){
                  (yyval.str) = new std::string(*(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + ";\n"); 
              }else if(tipo_actual == 6 && tipo_actual3 == 0){ // Si la asignacion es a otro IDENTIFIER
                  // Si la asignacion es a un INT, FLOAT, DOUBLE, BOOL (TRUE OR FALSE) --> la realizo sin prob
                  if(symbol_table[*(yyvsp[-1].str)] == "int" | symbol_table[*(yyvsp[-1].str)] == "float"| symbol_table[*(yyvsp[-1].str)] == "double"| symbol_table[*(yyvsp[-1].str)] == "bool"){
                    (yyval.str) = new std::string(*(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + ";\n"); }
                  else{
                    std::cerr << "WARNING: No se puede realizar la traduccion de esta asignacion en C"<< std::endl;
                    (yyval.str) = new std::string("// " + *(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
                }
              }else if(tipo_actual3 == 1 && tipo_actual != 4 && tipo_actual != 9){ // asignaciones a operaciones de suma resta etc
                  (yyval.str) = new std::string(*(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + ";\n"); 
                  tipo_actual3 = 0;
              }
              else{ 
                  std::cerr << "WARNING: No se puede realizar la traduccion de esta asignacion en C"<< std::endl;
                  (yyval.str) = new std::string("// " + *(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
              }

          }else{
              std::cerr << "WARNING: No se puede realizar la traduccion de esta asignacion en C"<< std::endl;
              (yyval.str) = new std::string("// " + *(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
          }
        }
        tipo_actual = 0;
        tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        delete (yyvsp[-3].str); delete (yyvsp[-1].str);
    }
#line 1499 "parser.cpp"
    break;

  case 12: /* statement: CONSTANT EQUALS expression NEWLINE  */
#line 155 "parser.y"
                                         {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*(yyvsp[-3].str)) == symbol_table.end()) {
            // Determina el tipo de la constante
            std::string type;
            std::stringstream ss;
            if(tipo_actual2 == 1){ 
                type = "const int";
                ss << "const int " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*(yyvsp[-3].str)] = type;
            }else if(tipo_actual2 == 2){ 
                type = "const float";
                ss << "const float " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*(yyvsp[-3].str)] = type;
            }
            else if(tipo_actual2 == 3){ 
                type = "const char";
                ss << "const char " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*(yyvsp[-3].str)] = type;
            }
            else{
              std::cerr << "Error: Asignacion no valida a constante " << *(yyvsp[-3].str) << ". En linea: " << yylineno << std::endl;
            }
            delete (yyvsp[-3].str); delete (yyvsp[-1].str);
        }else{
          // Si existe no se puede modificar
          (yyval.str) = new std::string("// " + *(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + "; // Asignacion no valida en C, revisar si afecta el flujo \n");
          std::cerr << "Error: Modificacion no valida a constante " << *(yyvsp[-3].str) << ". En linea: " << yylineno << std::endl;
          delete (yyvsp[-3].str); delete (yyvsp[-1].str);
        }
        tipo_actual = 0;
        tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        
    }
#line 1545 "parser.cpp"
    break;

  case 13: /* statement: FOR IDENTIFIER IN RANGE LPAREN expression_for RPAREN COLON NEWLINE  */
#line 196 "parser.y"
                                                                        {
      // realizar verificacion, si es_id == 1, entonces verificar que su tipo sea int en la tabla de simbolos, sino error
      // verificar si ya se declaro o no la variable
        (yyval.str) = new std::string("for (int " + *(yyvsp[-7].str) + " = 0; " + *(yyvsp[-7].str) + " <  " + *(yyvsp[-3].str) + "; " + *(yyvsp[-7].str) + "++) {\n"); 
        delete (yyvsp[-7].str); delete (yyvsp[-3].str);
        //std::cerr << "Entro a FIR statement \n";
    }
#line 1557 "parser.cpp"
    break;

  case 14: /* statement: DEF IDENTIFIER LPAREN parameter_list RPAREN COLON NEWLINE  */
#line 203 "parser.y"
                                                                {
      std::string funcName = *(yyvsp[-5].str);
      //std::cerr << "Entro a DEF procedure \n";
      // Verificar si la función ya existe en la tabla de símbolos
      if (symbol_table.find(funcName) != symbol_table.end()) {
          std::cerr << "Error: La función '" << funcName << "' ya ha sido declarada. Línea: " << (yylsp[-5]).first_line << std::endl;
          //YYERROR;
      } else {
          std::string funcDecl = "void " + funcName + "(" + *(yyvsp[-3].str) + ");\n";
          
          // Guardar la función en la tabla de símbolos
          symbol_table[funcName] = "function";

          if (functionDeclarationsStr == nullptr) {
              functionDeclarationsStr = new std::string(funcDecl);
          } else {
              *functionDeclarationsStr += funcDecl;
          }
          (yyval.str) = new std::string("// Se deberia trasladar esta declaracion fuera del main \nvoid " + funcName + "(" + *(yyvsp[-3].str) + ") {\n");
      }
      delete (yyvsp[-5].str); delete (yyvsp[-3].str);
    }
#line 1584 "parser.cpp"
    break;

  case 15: /* statement: IDENTIFIER LPAREN argument_list RPAREN NEWLINE  */
#line 225 "parser.y"
                                                    {
      std::string funcName = *(yyvsp[-4].str);
      //std::cerr << "Entro a llamada Proc \n";
      //std::cerr << "argument list: " << *$3 << " \n";
      if (symbol_table.find(funcName) == symbol_table.end()) {
        std::cerr << "Error: La función '" << funcName << "' no ha sido declarada. Línea: " << (yylsp[-4]).first_line << std::endl;
        YYERROR;
      } else {
        //std::cerr << "Entro a la escritura de la llamada \n";
        (yyval.str) = new std::string(*(yyvsp[-4].str) + "(" + *(yyvsp[-2].str) + ");\n");
      }
      delete (yyvsp[-4].str); delete (yyvsp[-2].str);
    }
#line 1602 "parser.cpp"
    break;

  case 16: /* statement: PRINT LPAREN expression RPAREN NEWLINE  */
#line 238 "parser.y"
                                            {
        //std::cerr << "Entro a PRINT \n";      
        std::string printFormat;
        std::string expressionStr = *(yyvsp[-2].str);
            
        if (tipo_actual == 4) { // Es un STRING
            printFormat = "printf(" + expressionStr + ");\n";
            //std::cerr << "Entro a es un string\n";   
        } else if (tipo_actual == 6) { // Es un IDENTIFIER
              //std::cerr << "Entro a es un ID \n";           
            if (symbol_table.find(expressionStr) != symbol_table.end()) {
                std::string type = symbol_table[expressionStr];
                if (type == "int" || type == "const int") {
                    printFormat = "printf(\"%d\", " + expressionStr + ");\n";
                } else if (type == "float") {
                    printFormat = "printf(\"%f\", " + expressionStr + ");\n";
                } else if (type == "double") {
                    printFormat = "printf(\"%lf\", " + expressionStr + ");\n";
                }else{
                  std::cerr << "WARNING: No se puede imprimir la variable \"" << expressionStr << "\"." << ". En linea: " << yylineno << std::endl;
                  printFormat = "// printf(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
                }
            } else {
                std::cerr << "WARNING: Variable " << expressionStr << " no encontrada en la tabla de símbolos." << ". En linea: " << yylineno << std::endl;
                printFormat = "// printf(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
            }
        } else {
                  std::cerr << "WARNING: No se puede imprimir la variable \"" << expressionStr << "\"." << ". En linea: " << yylineno << std::endl;
                  printFormat = "// printf(\"%?\", " + expressionStr + "); // Print no valido en C, revisar si afecta el flujo \n";
          }
        tipo_actual = 0;
        tipo_actual2 = 0;
        tipo_actual3 = 0;
        (yyval.str) = new std::string(printFormat);
        delete (yyvsp[-2].str);
    }
#line 1643 "parser.cpp"
    break;

  case 17: /* statement: UNKNOWN NEWLINE  */
#line 274 "parser.y"
                     {
      std::cerr << "Error: Simbolo desconocido: " << (yyvsp[-1].token) << ". En linea: " << yylineno << std::endl;
      std::cerr << "No se traslado a la traduccion " << std::endl;
    }
#line 1652 "parser.cpp"
    break;

  case 18: /* statement: error NEWLINE  */
#line 279 "parser.y"
    {
      std::cerr << "Error de sintaxis en la línea " << ". En linea: " << yylineno << std::endl;
    }
#line 1660 "parser.cpp"
    break;

  case 19: /* parameter_list: %empty  */
#line 285 "parser.y"
                { (yyval.str) = new std::string(""); }
#line 1666 "parser.cpp"
    break;

  case 20: /* parameter_list: IDENTIFIER  */
#line 286 "parser.y"
               { (yyval.str) = new std::string("int " + *(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1672 "parser.cpp"
    break;

  case 21: /* parameter_list: parameter_list COMMA IDENTIFIER  */
#line 287 "parser.y"
                                    {
      (yyval.str) = new std::string(*(yyvsp[-2].str) + ", int " + *(yyvsp[0].str));
      delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1681 "parser.cpp"
    break;

  case 22: /* argument_list: %empty  */
#line 294 "parser.y"
    { (yyval.str) = new std::string(""); }
#line 1687 "parser.cpp"
    break;

  case 23: /* argument_list: argument  */
#line 296 "parser.y"
    { (yyval.str) = (yyvsp[0].str); }
#line 1693 "parser.cpp"
    break;

  case 24: /* argument_list: argument_list COMMA argument  */
#line 298 "parser.y"
    {
      (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str));
      delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1702 "parser.cpp"
    break;

  case 25: /* argument: INTEGER  */
#line 304 "parser.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1708 "parser.cpp"
    break;

  case 26: /* argument: FLOAT  */
#line 305 "parser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1714 "parser.cpp"
    break;

  case 27: /* argument: DOUBLE  */
#line 306 "parser.y"
           {  (yyval.str) = (yyvsp[0].str); }
#line 1720 "parser.cpp"
    break;

  case 28: /* argument: TBOOLEAN  */
#line 307 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1726 "parser.cpp"
    break;

  case 29: /* argument: FBOOLEAN  */
#line 308 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1732 "parser.cpp"
    break;

  case 30: /* argument: IDENTIFIER  */
#line 310 "parser.y"
    {
      if (symbol_table.find(*(yyvsp[0].str)) == symbol_table.end()) {
        std::cerr << "Error: La variable '" << *(yyvsp[0].str) << "' no ha sido declarada. Línea: " << (yylsp[0]).first_line << std::endl;
        YYERROR;
      } else {
        (yyval.str) = (yyvsp[0].str);
      }
    }
#line 1745 "parser.cpp"
    break;

  case 31: /* expression: INTEGER  */
#line 320 "parser.y"
            { tipo_actual = 1; tipo_actual2 = 1; (yyval.str) = (yyvsp[0].str); }
#line 1751 "parser.cpp"
    break;

  case 32: /* expression: FLOAT  */
#line 321 "parser.y"
          { tipo_actual = 2; tipo_actual2 = 2; (yyval.str) = (yyvsp[0].str); }
#line 1757 "parser.cpp"
    break;

  case 33: /* expression: DOUBLE  */
#line 322 "parser.y"
           { tipo_actual = 7; (yyval.str) = (yyvsp[0].str); }
#line 1763 "parser.cpp"
    break;

  case 34: /* expression: TBOOLEAN  */
#line 323 "parser.y"
             { tipo_actual = 3; (yyval.str) = (yyvsp[0].str); }
#line 1769 "parser.cpp"
    break;

  case 35: /* expression: FBOOLEAN  */
#line 324 "parser.y"
             { tipo_actual = 3; (yyval.str) = (yyvsp[0].str); }
#line 1775 "parser.cpp"
    break;

  case 36: /* expression: IDENTIFIER  */
#line 325 "parser.y"
               {tipo_actual = 6;(yyval.str) = (yyvsp[0].str); }
#line 1781 "parser.cpp"
    break;

  case 37: /* expression: CONSTANT  */
#line 326 "parser.y"
             {tipo_actual = 8;(yyval.str) = (yyvsp[0].str); }
#line 1787 "parser.cpp"
    break;

  case 38: /* expression: STRING  */
#line 327 "parser.y"
           {  tipo_actual = 4; (yyval.str) = (yyvsp[0].str); }
#line 1793 "parser.cpp"
    break;

  case 39: /* expression: CHAR  */
#line 328 "parser.y"
         {  tipo_actual = 9; tipo_actual2 = 3; (yyval.str) = (yyvsp[0].str); }
#line 1799 "parser.cpp"
    break;

  case 40: /* expression: LPAREN expression RPAREN  */
#line 329 "parser.y"
                             {  (yyval.str) = new std::string("(" + *(yyvsp[-1].str) + ")"); delete (yyvsp[-1].str);}
#line 1805 "parser.cpp"
    break;

  case 41: /* expression: expression PLUS expression  */
#line 330 "parser.y"
                               { tipo_actual3 = 1;(yyval.str) =  new std::string(*(yyvsp[-2].str) + " + " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1811 "parser.cpp"
    break;

  case 42: /* expression: expression MINUS expression  */
#line 331 "parser.y"
                                { tipo_actual3 = 1;(yyval.str) =  new std::string(*(yyvsp[-2].str) + " - " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1817 "parser.cpp"
    break;

  case 43: /* expression: expression TIMES expression  */
#line 332 "parser.y"
                                { tipo_actual3 = 1;(yyval.str) =  new std::string(*(yyvsp[-2].str) + " * " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1823 "parser.cpp"
    break;

  case 44: /* expression: expression DIVIDEDBY expression  */
#line 333 "parser.y"
                                    { tipo_actual3 = 1;(yyval.str) =  new std::string(*(yyvsp[-2].str) + " / " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1829 "parser.cpp"
    break;

  case 45: /* expression: list  */
#line 334 "parser.y"
         { tipo_actual = 5; (yyval.str) = (yyvsp[0].str); }
#line 1835 "parser.cpp"
    break;

  case 46: /* expression_for: INTEGER  */
#line 337 "parser.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1841 "parser.cpp"
    break;

  case 47: /* expression_for: IDENTIFIER  */
#line 338 "parser.y"
               {es_id = 1; (yyval.str) = (yyvsp[0].str); }
#line 1847 "parser.cpp"
    break;

  case 48: /* list: LBRACK RBRACK  */
#line 341 "parser.y"
                  { (yyval.str) = new std::string("[]"); }
#line 1853 "parser.cpp"
    break;

  case 49: /* list: LBRACK elements RBRACK  */
#line 342 "parser.y"
                           { (yyval.str) = new std::string("{" + *(yyvsp[-1].str) + "}"); delete (yyvsp[-1].str); }
#line 1859 "parser.cpp"
    break;

  case 50: /* elements: expression  */
#line 345 "parser.y"
               { (yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1865 "parser.cpp"
    break;

  case 51: /* elements: elements COMMA expression  */
#line 346 "parser.y"
                              { (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str); }
#line 1871 "parser.cpp"
    break;

  case 52: /* conditionalExpr: IDENTIFIER  */
#line 349 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1877 "parser.cpp"
    break;

  case 53: /* conditionalExpr: INTEGER  */
#line 350 "parser.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1883 "parser.cpp"
    break;

  case 54: /* conditionalExpr: FLOAT  */
#line 351 "parser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1889 "parser.cpp"
    break;

  case 55: /* conditionalExpr: TBOOLEAN  */
#line 352 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1895 "parser.cpp"
    break;

  case 56: /* conditionalExpr: FBOOLEAN  */
#line 353 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1901 "parser.cpp"
    break;

  case 57: /* conditionalExpr: STRING  */
#line 354 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1907 "parser.cpp"
    break;

  case 58: /* conditionalExpr: conditionalExpr LT conditionalExpr  */
#line 355 "parser.y"
                                       { (yyval.str) = new std::string(*(yyvsp[-2].str) + " < " + *(yyvsp[0].str));  delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1913 "parser.cpp"
    break;

  case 59: /* conditionalExpr: conditionalExpr GT conditionalExpr  */
#line 356 "parser.y"
                                       { 
                                        (yyval.str) = new std::string(*(yyvsp[-2].str) + " > " + *(yyvsp[0].str));
                                        delete (yyvsp[-2].str); delete (yyvsp[0].str);
                                      }
#line 1922 "parser.cpp"
    break;

  case 60: /* conditionalExpr: conditionalExpr LTE conditionalExpr  */
#line 360 "parser.y"
                                        {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " <= " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1928 "parser.cpp"
    break;

  case 61: /* conditionalExpr: conditionalExpr GTE conditionalExpr  */
#line 361 "parser.y"
                                        {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " >= " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1934 "parser.cpp"
    break;

  case 62: /* conditionalExpr: conditionalExpr NEQ conditionalExpr  */
#line 362 "parser.y"
                                        {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " != " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1940 "parser.cpp"
    break;

  case 63: /* conditionalExpr: conditionalExpr EQ conditionalExpr  */
#line 363 "parser.y"
                                       {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " == " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1946 "parser.cpp"
    break;

  case 64: /* conditionalExpr: AND conditionalExpr  */
#line 364 "parser.y"
                        {  (yyval.str) = new std::string(" && " + *(yyvsp[0].str) ); delete (yyvsp[0].str);}
#line 1952 "parser.cpp"
    break;

  case 66: /* conditional: WHILE conditionalExpr COLON NEWLINE  */
#line 369 "parser.y"
                                        { (yyval.str) = new std::string("while (" + *(yyvsp[-2].str) + ") {\n"); delete (yyvsp[-2].str);}
#line 1958 "parser.cpp"
    break;

  case 67: /* ifelse: IF conditionalExpr COLON NEWLINE  */
#line 373 "parser.y"
                                     {  (yyval.str) = new std::string("if(" + *(yyvsp[-2].str) + ") {\n"); delete (yyvsp[-2].str);}
#line 1964 "parser.cpp"
    break;

  case 68: /* ifelse: ELSE COLON NEWLINE  */
#line 374 "parser.y"
                       { (yyval.str) = new std::string("else {\n");}
#line 1970 "parser.cpp"
    break;

  case 69: /* ifelse: ELIF conditionalExpr COLON NEWLINE  */
#line 375 "parser.y"
                                       {  (yyval.str) = new std::string("else if(" + *(yyvsp[-2].str) + ") {"); delete (yyvsp[-2].str);}
#line 1976 "parser.cpp"
    break;

  case 70: /* flowcontrol: BREAK  */
#line 379 "parser.y"
          { (yyval.str) = new std::string("break"); }
#line 1982 "parser.cpp"
    break;


#line 1986 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 382 "parser.y"


void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error de sintaxis en la línea "  << yylineno << std::endl;
  //exit(1);
}
