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
#include <vector>
#include "parser.hpp"

std::map<std::string, std::map<std::string, std::string>> symbol_table; // Tabla de símbolos
std::string* goalStr;
std::string* functionDeclarationsStr;
std::vector<std::string> current_scope;



extern int yylex();
extern int yylineno;

void yyerror(const char* err) {
  std::cerr << "Error de sintaxis: " << err << " en la línea " << yylineno << std::endl;
}

int tipo_actual = 0;
int tipo_actual2 = 0;
int tipo_actual3 = 0;
int es_id = 0;


#line 102 "parser.cpp"

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
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_CONSTANT = 10,                  /* CONSTANT  */
  YYSYMBOL_EQUALS = 11,                    /* EQUALS  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_TIMES = 14,                     /* TIMES  */
  YYSYMBOL_DIVIDEDBY = 15,                 /* DIVIDEDBY  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GTE = 19,                       /* GTE  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_LTE = 21,                       /* LTE  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_INDENT = 23,                    /* INDENT  */
  YYSYMBOL_DEDENT = 24,                    /* DEDENT  */
  YYSYMBOL_NEWLINE = 25,                   /* NEWLINE  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_ELIF = 30,                      /* ELIF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_IN = 33,                        /* IN  */
  YYSYMBOL_RANGE = 34,                     /* RANGE  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_DEF = 38,                       /* DEF  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 40,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 41,                    /* RPAREN  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_LBRACK = 43,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 44,                    /* RBRACK  */
  YYSYMBOL_PRINT = 45,                     /* PRINT  */
  YYSYMBOL_UNKNOWN = 46,                   /* UNKNOWN  */
  YYSYMBOL_ENDMARKER = 47,                 /* ENDMARKER  */
  YYSYMBOL_POW = 48,                       /* POW  */
  YYSYMBOL_CLASS = 49,                     /* CLASS  */
  YYSYMBOL_ARROW = 50,                     /* ARROW  */
  YYSYMBOL_MOD = 51,                       /* MOD  */
  YYSYMBOL_NONE = 52,                      /* NONE  */
  YYSYMBOL_NAME = 53,                      /* NAME  */
  YYSYMBOL_UMINUS = 54,                    /* UMINUS  */
  YYSYMBOL_55_ = 55,                       /* '|'  */
  YYSYMBOL_56_ = 56,                       /* '&'  */
  YYSYMBOL_57_ = 57,                       /* "<<"  */
  YYSYMBOL_58_ = 58,                       /* ">>"  */
  YYSYMBOL_59_ = 59,                       /* "//"  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* '['  */
  YYSYMBOL_63_ = 63,                       /* ']'  */
  YYSYMBOL_64_ = 64,                       /* '.'  */
  YYSYMBOL_65_ = 65,                       /* ','  */
  YYSYMBOL_66_ = 66,                       /* ':'  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_program = 69,                   /* program  */
  YYSYMBOL_stmt_or_newline_list_opt = 70,  /* stmt_or_newline_list_opt  */
  YYSYMBOL_stmt_or_newline = 71,           /* stmt_or_newline  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_simple_stmt = 73,               /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 74,           /* small_stmt_list  */
  YYSYMBOL_small_stmt = 75,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 76,                 /* expr_stmt  */
  YYSYMBOL_annasign = 77,                  /* annasign  */
  YYSYMBOL_augassign = 78,                 /* augassign  */
  YYSYMBOL_flow_stmt = 79,                 /* flow_stmt  */
  YYSYMBOL_compound_stmt = 80,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 81,                   /* if_stmt  */
  YYSYMBOL_elif_clauses = 82,              /* elif_clauses  */
  YYSYMBOL_else_clause_opt = 83,           /* else_clause_opt  */
  YYSYMBOL_suite = 84,                     /* suite  */
  YYSYMBOL_stmt_list = 85,                 /* stmt_list  */
  YYSYMBOL_while_stmt = 86,                /* while_stmt  */
  YYSYMBOL_for_stmt = 87,                  /* for_stmt  */
  YYSYMBOL_funcdef = 88,                   /* funcdef  */
  YYSYMBOL_parameters = 89,                /* parameters  */
  YYSYMBOL_parameter_list = 90,            /* parameter_list  */
  YYSYMBOL_return_type_opt = 91,           /* return_type_opt  */
  YYSYMBOL_test = 92,                      /* test  */
  YYSYMBOL_or_test = 93,                   /* or_test  */
  YYSYMBOL_and_test = 94,                  /* and_test  */
  YYSYMBOL_not_test = 95,                  /* not_test  */
  YYSYMBOL_comparison = 96,                /* comparison  */
  YYSYMBOL_comp_op = 97,                   /* comp_op  */
  YYSYMBOL_expr = 98,                      /* expr  */
  YYSYMBOL_arith_expr = 99,                /* arith_expr  */
  YYSYMBOL_term = 100,                     /* term  */
  YYSYMBOL_factor = 101,                   /* factor  */
  YYSYMBOL_power = 102,                    /* power  */
  YYSYMBOL_atom_expr = 103,                /* atom_expr  */
  YYSYMBOL_atom = 104,                     /* atom  */
  YYSYMBOL_list = 105,                     /* list  */
  YYSYMBOL_testlist = 106,                 /* testlist  */
  YYSYMBOL_trailer = 107,                  /* trailer  */
  YYSYMBOL_subscriptlist = 108,            /* subscriptlist  */
  YYSYMBOL_subscript = 109,                /* subscript  */
  YYSYMBOL_sliceop = 110,                  /* sliceop  */
  YYSYMBOL_argument = 111,                 /* argument  */
  YYSYMBOL_arglist = 112                   /* arglist  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
      60,    61,     2,     2,    65,     2,    64,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
       2,    67,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    55,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    92,    93,    98,    99,   103,   104,   109,
     115,   117,   118,   122,   123,   129,   131,   133,   135,   137,
     141,   145,   146,   147,   148,   152,   153,   155,   159,   160,
     161,   162,   166,   189,   190,   205,   206,   210,   211,   216,
     217,   222,   235,   244,   256,   270,   271,   279,   280,   288,
     289,   293,   294,   302,   303,   311,   312,   320,   325,   329,
     330,   335,   346,   347,   348,   349,   350,   351,   355,   356,
     364,   365,   370,   378,   379,   384,   389,   394,   399,   404,
     409,   417,   418,   423,   427,   428,   436,   437,   444,   451,
     452,   453,   454,   455,   456,   457,   461,   469,   470,   471,
     479,   480,   481,   482,   486,   487,   494,   495,   496,   500,
     507,   508,   512,   513,   520,   522
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
  "INTEGER", "BOOLEAN", "FLOAT", "STRING", "CHAR", "DOUBLE", "CONSTANT",
  "EQUALS", "PLUS", "MINUS", "TIMES", "DIVIDEDBY", "EQ", "NEQ", "GT",
  "GTE", "LT", "LTE", "RETURN", "INDENT", "DEDENT", "NEWLINE", "IF",
  "COLON", "AND", "BREAK", "ELIF", "ELSE", "FOR", "IN", "RANGE", "NOT",
  "OR", "WHILE", "DEF", "SEMICOLON", "LPAREN", "RPAREN", "COMMA", "LBRACK",
  "RBRACK", "PRINT", "UNKNOWN", "ENDMARKER", "POW", "CLASS", "ARROW",
  "MOD", "NONE", "NAME", "UMINUS", "'|'", "'&'", "\"<<\"", "\">>\"",
  "\"//\"", "'('", "')'", "'['", "']'", "'.'", "','", "':'", "'='",
  "$accept", "program", "stmt_or_newline_list_opt", "stmt_or_newline",
  "stmt", "simple_stmt", "small_stmt_list", "small_stmt", "expr_stmt",
  "annasign", "augassign", "flow_stmt", "compound_stmt", "if_stmt",
  "elif_clauses", "else_clause_opt", "suite", "stmt_list", "while_stmt",
  "for_stmt", "funcdef", "parameters", "parameter_list", "return_type_opt",
  "test", "or_test", "and_test", "not_test", "comparison", "comp_op",
  "expr", "arith_expr", "term", "factor", "power", "atom_expr", "atom",
  "list", "testlist", "trailer", "subscriptlist", "subscript", "sliceop",
  "argument", "arglist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -143,     7,   155,  -143,  -143,  -143,  -143,  -143,  -143,   123,
     123,   380,  -143,   380,  -143,    16,   380,   380,    45,   123,
     380,  -143,  -143,  -143,  -143,  -143,   -16,    12,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,   249,    -6,    28,  -143,   203,
       4,    34,    62,  -143,  -143,    17,     6,  -143,  -143,  -143,
    -143,    46,    41,  -143,    55,    47,   -31,  -143,    -5,  -143,
     328,  -143,   380,    78,    80,    81,    83,   380,    87,   380,
     380,   380,   380,  -143,  -143,  -143,  -143,  -143,  -143,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,    29,     9,    96,  -143,   287,   339,   287,     2,
      50,  -143,   380,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,   380,  -143,    14,    28,  -143,     4,     4,     4,    62,
      62,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
      44,  -143,   -36,   380,    35,   -25,  -143,  -143,    89,  -143,
    -143,    74,    88,  -143,  -143,  -143,    13,   380,    90,  -143,
    -143,   380,   380,   380,  -143,  -143,   380,  -143,     9,   246,
      -4,   380,   287,  -143,   113,  -143,   287,  -143,  -143,  -143,
      56,  -143,  -143,   205,   380,    98,  -143,    21,  -143,  -143,
    -143,   380,  -143,  -143,  -143,   104,   107,   106,  -143,   109,
     287,   287,   287,  -143,  -143,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    88,    89,    92,    90,    91,     0,
       0,    27,     6,     0,    25,     0,     0,     0,     0,     0,
      97,     2,    93,     4,     5,     7,     0,    12,    13,    14,
       8,    28,    29,    30,    31,    19,    51,    53,    55,    58,
      59,    68,    70,    73,    83,    84,    86,    94,    81,    82,
      26,     0,     0,    57,     0,     0,     0,    98,     0,     9,
       0,    11,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    62,    63,    65,    67,    64,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
      49,    95,     0,    96,    10,    18,    21,    22,    23,    24,
      20,     0,    17,     0,    54,    56,    61,    60,    69,    71,
      72,    74,    75,    76,    77,    78,    79,    80,    85,   100,
     112,   114,     0,     0,   106,     0,   104,   103,     0,    37,
      33,     0,     0,    41,    47,    45,     0,     0,     0,    99,
      16,     0,     0,     0,   101,   107,     0,   102,     0,     0,
      35,    97,     0,    46,     0,    50,     0,    52,   113,   115,
     108,   105,    39,     0,     0,     0,    32,     0,    42,    48,
      44,   110,   109,    38,    40,     0,     0,     0,   111,     0,
       0,     0,     0,    36,    43,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,  -142,    -2,  -143,    63,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   -95,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,    -9,    67,    68,   -15,  -143,  -143,
      -1,  -143,     3,    19,  -143,  -143,  -143,  -143,   -21,  -143,
    -143,   -17,  -143,    -8,  -143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    23,    24,   139,    26,    27,    28,    68,
      69,    29,    30,    31,   160,   176,   140,   173,    32,    33,
      34,   100,   146,   148,    35,    36,    37,    38,    39,    80,
      40,    41,    42,    43,    44,    45,    46,    47,    58,    95,
     135,   136,   182,   131,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    53,    50,   143,    51,   144,   153,     3,    54,    59,
     101,    57,     4,     5,     6,     7,     8,   172,    56,    52,
      70,     9,    10,    60,    81,   154,   174,   175,    48,    49,
      71,   184,     4,     5,     6,     7,     8,   102,   157,   103,
     158,     9,    10,   145,    16,   151,    82,    83,    55,    19,
      71,    61,    20,   105,   163,   164,    72,   115,   110,    81,
     112,    22,   187,   102,    16,    91,    92,   178,    93,    19,
      94,   180,    20,    96,    97,   133,    84,    85,   116,   117,
     118,    22,    98,   130,   134,   119,   120,    99,   142,   106,
     129,   107,   108,   149,   109,   193,   194,   195,   111,   137,
     147,   156,   150,   121,   122,   123,   124,   125,   126,   127,
     128,   152,   159,    86,   161,   162,   179,   166,    87,    88,
      89,    90,   181,   104,   155,   186,     4,     5,     6,     7,
       8,   189,   190,   191,   192,     9,    10,   113,   165,   114,
     177,   171,   167,   168,   130,   169,     0,   170,     0,   134,
       0,     0,    57,     0,     0,     0,     0,    25,     4,     5,
       6,     7,     8,    19,     0,   185,    20,     9,    10,     0,
       0,    25,   188,     0,     0,    22,     0,    11,     0,     0,
      12,    13,     0,     0,    14,     0,     0,    15,     0,     0,
      16,     0,    17,    18,     0,    19,     0,     0,    20,     0,
       0,     0,    21,     0,     0,     0,     0,    22,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,    10,    73,
      74,    75,    76,    77,    78,     0,     0,    11,     0,   183,
       0,    13,     0,     0,    14,     0,    79,    15,     0,     0,
      16,     0,    17,    18,     0,    19,     0,     0,    20,     4,
       5,     6,     7,     8,     0,     0,     0,    22,     9,    10,
      62,    63,    64,    65,    66,     0,     0,     0,    11,     0,
       0,     0,    13,     0,     0,    14,    67,     0,    15,     0,
       0,    16,     0,    17,    18,     0,    19,     0,     0,    20,
       4,     5,     6,     7,     8,     0,     0,     0,    22,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,   138,     0,     0,     0,    14,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,    19,     0,     0,
      20,     4,     5,     6,     7,     8,     0,     0,     0,    22,
       9,    10,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     9,    10,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,    19,     0,
       0,    20,     0,   141,    16,     0,     0,     0,     0,    19,
      22,     0,    20,     4,     5,     6,     7,     8,     0,     0,
       0,    22,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
      19,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,    22
};

static const yytype_int16 yycheck[] =
{
       2,    16,    11,    98,    13,     3,    42,     0,    17,    25,
      41,    20,     3,     4,     5,     6,     7,   159,    19,     3,
      26,    12,    13,    39,    55,    61,    30,    31,     9,    10,
      36,   173,     3,     4,     5,     6,     7,    42,    63,    44,
      65,    12,    13,    41,    35,    31,    12,    13,     3,    40,
      36,    39,    43,    62,    41,    42,    28,    72,    67,    55,
      69,    52,    41,    42,    35,    48,    60,   162,    62,    40,
      64,   166,    43,    27,    33,    66,    14,    15,    79,    80,
      81,    52,    27,    92,    93,    82,    83,    40,    97,    11,
      61,    11,    11,   102,    11,   190,   191,   192,    11,     3,
      50,    66,   111,    84,    85,    86,    87,    88,    89,    90,
      91,    67,    23,    51,    40,    27,     3,    27,    56,    57,
      58,    59,    66,    60,   133,    27,     3,     4,     5,     6,
       7,    27,    25,    27,    25,    12,    13,    70,   147,    71,
     161,   158,   151,   152,   153,   153,    -1,   156,    -1,   158,
      -1,    -1,   161,    -1,    -1,    -1,    -1,   159,     3,     4,
       5,     6,     7,    40,    -1,   174,    43,    12,    13,    -1,
      -1,   173,   181,    -1,    -1,    52,    -1,    22,    -1,    -1,
      25,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    -1,    37,    38,    -1,    40,    -1,    -1,    43,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    16,
      17,    18,    19,    20,    21,    -1,    -1,    22,    -1,    24,
      -1,    26,    -1,    -1,    29,    -1,    33,    32,    -1,    -1,
      35,    -1,    37,    38,    -1,    40,    -1,    -1,    43,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    52,    12,    13,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    26,    -1,    -1,    29,    27,    -1,    32,    -1,
      -1,    35,    -1,    37,    38,    -1,    40,    -1,    -1,    43,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    52,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,     3,     4,     5,     6,     7,    -1,    -1,    -1,    52,
      12,    13,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      22,    12,    13,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,
      52,    -1,    43,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    52,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,    70,     0,     3,     4,     5,     6,     7,    12,
      13,    22,    25,    26,    29,    32,    35,    37,    38,    40,
      43,    47,    52,    71,    72,    73,    74,    75,    76,    79,
      80,    81,    86,    87,    88,    92,    93,    94,    95,    96,
      98,    99,   100,   101,   102,   103,   104,   105,   101,   101,
      92,    92,     3,    95,    92,     3,    98,    92,   106,    25,
      39,    39,    11,    12,    13,    14,    15,    27,    77,    78,
      26,    36,    28,    16,    17,    18,    19,    20,    21,    33,
      97,    55,    12,    13,    14,    15,    51,    56,    57,    58,
      59,    48,    60,    62,    64,   107,    27,    33,    27,    40,
      89,    41,    42,    44,    75,    92,    11,    11,    11,    11,
      92,    11,    92,    93,    94,    95,    98,    98,    98,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,    61,
      92,   111,   112,    66,    92,   108,   109,     3,    25,    73,
      84,    34,    92,    84,     3,    41,    90,    50,    91,    92,
      92,    31,    67,    42,    61,    92,    66,    63,    65,    23,
      82,    40,    27,    41,    42,    92,    27,    92,    92,   111,
      92,   109,    72,    85,    30,    31,    83,   106,    84,     3,
      84,    66,   110,    24,    72,    92,    27,    41,    92,    27,
      25,    27,    25,    84,    84,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      77,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      80,    80,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   106,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   109,   109,   109,
     110,   110,   111,   111,   112,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       3,     2,     1,     1,     1,     2,     4,     3,     3,     1,
       2,     2,     2,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     6,     0,     6,     0,     4,     1,     4,     1,
       2,     4,     6,     9,     6,     2,     3,     1,     3,     0,
       2,     1,     5,     1,     3,     1,     3,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     0,     1,     3,
       2,     3,     3,     2,     1,     3,     1,     2,     3,     4,
       1,     2,     1,     3,     1,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmt_or_newline_list_opt ENDMARKER  */
#line 88 "parser.y"
                                       { goalStr = new std::string(*(yyvsp[-1].str)); 
                              delete (yyvsp[-1].str); }
#line 1394 "parser.cpp"
    break;

  case 3: /* stmt_or_newline_list_opt: %empty  */
#line 92 "parser.y"
                { (yyval.str) = new std::string(""); }
#line 1400 "parser.cpp"
    break;

  case 4: /* stmt_or_newline_list_opt: stmt_or_newline_list_opt stmt_or_newline  */
#line 93 "parser.y"
                                             { (yyval.str) = new std::string(*(yyvsp[-1].str) + "\n"+ *(yyvsp[0].str));
                                    delete (yyvsp[-1].str); delete (yyvsp[0].str); }
#line 1407 "parser.cpp"
    break;

  case 6: /* stmt_or_newline: NEWLINE  */
#line 99 "parser.y"
            { (yyval.str) = new std::string("\n"); }
#line 1413 "parser.cpp"
    break;

  case 9: /* simple_stmt: small_stmt_list NEWLINE  */
#line 109 "parser.y"
                            { (yyval.str) = new std::string(*(yyvsp[-1].str) + ";");
                              delete (yyvsp[-1].str); }
#line 1420 "parser.cpp"
    break;

  case 10: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 115 "parser.y"
                                         { (yyval.str) = new std::string(*(yyvsp[-2].str) + *(yyvsp[0].str));
                                           delete (yyvsp[-2].str); /*delete $2; verificar luego con gabriel */}
#line 1427 "parser.cpp"
    break;

  case 11: /* small_stmt_list: small_stmt SEMICOLON  */
#line 117 "parser.y"
                         { (yyval.str) = (yyvsp[-1].str); }
#line 1433 "parser.cpp"
    break;

  case 15: /* expr_stmt: test annasign  */
#line 129 "parser.y"
                  { (yyval.str) = new std::string(*(yyvsp[-1].str));              // No asigna
                    delete (yyvsp[-1].str); }
#line 1440 "parser.cpp"
    break;

  case 16: /* expr_stmt: test annasign EQUALS test  */
#line 131 "parser.y"
                              { (yyval.str) = new std::string(*(yyvsp[-3].str) + "=" + *(yyvsp[0].str));  // Asigna
                    delete (yyvsp[-3].str); delete (yyvsp[0].str); }
#line 1447 "parser.cpp"
    break;

  case 17: /* expr_stmt: test augassign test  */
#line 133 "parser.y"
                        { (yyval.str) = new std::string(*(yyvsp[-2].str) + *(yyvsp[-1].str) + *(yyvsp[0].str));  // Asigna
                    delete (yyvsp[-2].str); delete (yyvsp[-1].str); delete (yyvsp[0].str);}
#line 1454 "parser.cpp"
    break;

  case 18: /* expr_stmt: test EQUALS test  */
#line 135 "parser.y"
                     { (yyval.str) = new std::string(*(yyvsp[-2].str) + "=" + *(yyvsp[0].str));     // Asigna
                    delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1461 "parser.cpp"
    break;

  case 19: /* expr_stmt: test  */
#line 137 "parser.y"
         { (yyval.str) = new std::string("");}
#line 1467 "parser.cpp"
    break;

  case 20: /* annasign: COLON test  */
#line 141 "parser.y"
               { delete (yyvsp[0].str); }
#line 1473 "parser.cpp"
    break;

  case 21: /* augassign: PLUS EQUALS  */
#line 145 "parser.y"
                { (yyval.str) = new std::string("+=");}
#line 1479 "parser.cpp"
    break;

  case 22: /* augassign: MINUS EQUALS  */
#line 146 "parser.y"
                 { (yyval.str) = new std::string("-=");}
#line 1485 "parser.cpp"
    break;

  case 23: /* augassign: TIMES EQUALS  */
#line 147 "parser.y"
                 { (yyval.str) = new std::string("*=");}
#line 1491 "parser.cpp"
    break;

  case 24: /* augassign: DIVIDEDBY EQUALS  */
#line 148 "parser.y"
                     { (yyval.str) = new std::string("/=");}
#line 1497 "parser.cpp"
    break;

  case 25: /* flow_stmt: BREAK  */
#line 152 "parser.y"
          { (yyval.str) = new std::string("break"); }
#line 1503 "parser.cpp"
    break;

  case 26: /* flow_stmt: RETURN test  */
#line 153 "parser.y"
                { (yyval.str) = new std::string("return" + *(yyvsp[0].str));
                  delete (yyvsp[0].str); }
#line 1510 "parser.cpp"
    break;

  case 27: /* flow_stmt: RETURN  */
#line 155 "parser.y"
           { (yyval.str) = new std::string("return"); }
#line 1516 "parser.cpp"
    break;

  case 32: /* if_stmt: IF test COLON suite elif_clauses else_clause_opt  */
#line 167 "parser.y"
      {
        // base if
        std::stringstream ss;
        ss << "if (" << *(yyvsp[-4].str) << ") {\n\t" << *(yyvsp[-1].str) << "}\n";

        // elif
        if ((yyvsp[-1].str)) {
          ss << *(yyvsp[-1].str);
          delete (yyvsp[-1].str);
        }

        // else
        if ((yyvsp[0].str)) {
          ss << *(yyvsp[0].str);
          delete (yyvsp[0].str);
        }

        (yyval.str) = new std::string(ss.str());
        delete (yyvsp[-4].str); delete (yyvsp[-2].str);
      }
#line 1541 "parser.cpp"
    break;

  case 33: /* elif_clauses: %empty  */
#line 189 "parser.y"
                { (yyval.str) = nullptr; }
#line 1547 "parser.cpp"
    break;

  case 34: /* elif_clauses: elif_clauses ELIF test COLON NEWLINE suite  */
#line 191 "parser.y"
      {
        std::stringstream ss;
        if ((yyvsp[-5].str)) {
          ss << *(yyvsp[-5].str);
          delete (yyvsp[-5].str);
        }
        ss << "else if (" << *(yyvsp[-3].str) << ") {\n" << *(yyvsp[0].str) << "}\n";
        (yyval.str) = new std::string(ss.str());
        delete (yyvsp[-3].str); delete (yyvsp[0].str);
      }
#line 1562 "parser.cpp"
    break;

  case 35: /* else_clause_opt: %empty  */
#line 205 "parser.y"
                { (yyval.str) = nullptr; }
#line 1568 "parser.cpp"
    break;

  case 36: /* else_clause_opt: ELSE COLON NEWLINE suite  */
#line 206 "parser.y"
                             { (yyval.str) = new std::string("else {\n" + *(yyvsp[0].str) + "}\n"); delete (yyvsp[0].str); }
#line 1574 "parser.cpp"
    break;

  case 38: /* suite: NEWLINE INDENT stmt_list DEDENT  */
#line 211 "parser.y"
                                    { (yyval.str) = new std::string(*(yyvsp[-1].str));
                                      delete (yyvsp[-1].str);}
#line 1581 "parser.cpp"
    break;

  case 40: /* stmt_list: stmt_list stmt  */
#line 217 "parser.y"
                   { (yyval.str) = new std::string(*(yyvsp[-1].str) +*(yyvsp[0].str)); 
                     delete (yyvsp[-1].str); delete (yyvsp[0].str); }
#line 1588 "parser.cpp"
    break;

  case 41: /* while_stmt: WHILE test COLON suite  */
#line 223 "parser.y"
      {
        std::stringstream ss;

        // generar el while
        ss << "while (" << *(yyvsp[-2].str) << ") {\n" << *(yyvsp[0].str) << "}\n";

        (yyval.str) = new std::string(ss.str());
        delete (yyvsp[-2].str);
        delete (yyvsp[0].str);
      }
#line 1603 "parser.cpp"
    break;

  case 42: /* for_stmt: FOR IDENTIFIER IN test COLON suite  */
#line 236 "parser.y"
      {
        // esto es para "for x in lista"
        std::stringstream ss;
        ss << "for (let " << *(yyvsp[-4].str) << " of " << *(yyvsp[-2].str) << ") {\n"
           << *(yyvsp[0].str) << "}\n";
        (yyval.str) = new std::string(ss.str());
        delete (yyvsp[-4].str); delete (yyvsp[-2].str); delete (yyvsp[0].str);
      }
#line 1616 "parser.cpp"
    break;

  case 43: /* for_stmt: FOR IDENTIFIER IN RANGE LPAREN testlist RPAREN COLON suite  */
#line 245 "parser.y"
      {
        // esto es para "for x in range(n)"
        std::stringstream ss;
        ss << "for (let " << *(yyvsp[-7].str) << " = 0; "
           << *(yyvsp[-7].str) << " < " << *(yyvsp[-3].str) << "; " << *(yyvsp[-7].str) << "++) {\n"
           << *(yyvsp[0].str) << "}\n";
        (yyval.str) = new std::string(ss.str());
        delete (yyvsp[-7].str); delete (yyvsp[-3].str); delete (yyvsp[0].str);
      }
#line 1630 "parser.cpp"
    break;

  case 44: /* funcdef: DEF IDENTIFIER parameters return_type_opt COLON suite  */
#line 257 "parser.y"
      {
        std::stringstream ss;

        // función en JavaScript con parámetros
        ss << "function " << *(yyvsp[-4].str) << *(yyvsp[-3].str) << " {\n" << *(yyvsp[0].str) << "}\n";

        // en JS no hay anotaciones de tipo de retorno, así que ignoramos $4
        (yyval.str) = new std::string(ss.str());

        delete (yyvsp[-4].str); delete (yyvsp[-3].str); delete (yyvsp[-2].str); delete (yyvsp[0].str);
      }
#line 1646 "parser.cpp"
    break;

  case 45: /* parameters: LPAREN RPAREN  */
#line 270 "parser.y"
                  { (yyval.str) = new std::string("()"); }
#line 1652 "parser.cpp"
    break;

  case 46: /* parameters: LPAREN parameter_list RPAREN  */
#line 272 "parser.y"
      {
        (yyval.str) = new std::string("(" + *(yyvsp[-1].str) + ")");
        delete (yyvsp[-1].str);
      }
#line 1661 "parser.cpp"
    break;

  case 47: /* parameter_list: IDENTIFIER  */
#line 279 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1667 "parser.cpp"
    break;

  case 48: /* parameter_list: parameter_list COMMA IDENTIFIER  */
#line 281 "parser.y"
      {
        (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str));
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
      }
#line 1676 "parser.cpp"
    break;

  case 49: /* return_type_opt: %empty  */
#line 288 "parser.y"
                { /*En JavaScript no hay tipado de retorno, por eso solo parseamos, pero no lo incluimos en la salida. */ (yyval.str) = new std::string(""); }
#line 1682 "parser.cpp"
    break;

  case 50: /* return_type_opt: ARROW test  */
#line 289 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1688 "parser.cpp"
    break;

  case 51: /* test: or_test  */
#line 293 "parser.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1694 "parser.cpp"
    break;

  case 52: /* test: or_test IF or_test ELSE test  */
#line 295 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " ? " + *(yyvsp[-4].str) + " : " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-4].str); delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1703 "parser.cpp"
    break;

  case 53: /* or_test: and_test  */
#line 302 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1709 "parser.cpp"
    break;

  case 54: /* or_test: or_test OR and_test  */
#line 304 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " || " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1718 "parser.cpp"
    break;

  case 55: /* and_test: not_test  */
#line 311 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1724 "parser.cpp"
    break;

  case 56: /* and_test: and_test AND not_test  */
#line 313 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " && " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1733 "parser.cpp"
    break;

  case 57: /* not_test: NOT not_test  */
#line 321 "parser.y"
    {
        (yyval.str) = new std::string("!(" + *(yyvsp[0].str) + ")");
        delete (yyvsp[0].str);
    }
#line 1742 "parser.cpp"
    break;

  case 58: /* not_test: comparison  */
#line 325 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1748 "parser.cpp"
    break;

  case 59: /* comparison: expr  */
#line 329 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1754 "parser.cpp"
    break;

  case 60: /* comparison: comparison comp_op expr  */
#line 331 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " " + *(yyvsp[-1].str) + " " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[-1].str); delete (yyvsp[0].str);
    }
#line 1763 "parser.cpp"
    break;

  case 61: /* comparison: comparison IN expr  */
#line 336 "parser.y"
    {
        // JS: arrays → includes(), objetos → in
        (yyval.str) = new std::string("(Array.isArray(" + *(yyvsp[0].str) + ") ? " + 
                             *(yyvsp[0].str) + ".includes(" + *(yyvsp[-2].str) + ") : " +
                             "(" + *(yyvsp[-2].str) + " in " + *(yyvsp[0].str) + "))");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1775 "parser.cpp"
    break;

  case 62: /* comp_op: EQ  */
#line 346 "parser.y"
         { (yyval.str) = new std::string("==="); }
#line 1781 "parser.cpp"
    break;

  case 63: /* comp_op: NEQ  */
#line 347 "parser.y"
          { (yyval.str) = new std::string("!=="); }
#line 1787 "parser.cpp"
    break;

  case 64: /* comp_op: LT  */
#line 348 "parser.y"
         { (yyval.str) = new std::string("<"); }
#line 1793 "parser.cpp"
    break;

  case 65: /* comp_op: GT  */
#line 349 "parser.y"
         { (yyval.str) = new std::string(">"); }
#line 1799 "parser.cpp"
    break;

  case 66: /* comp_op: LTE  */
#line 350 "parser.y"
          { (yyval.str) = new std::string("<="); }
#line 1805 "parser.cpp"
    break;

  case 67: /* comp_op: GTE  */
#line 351 "parser.y"
          { (yyval.str) = new std::string(">="); }
#line 1811 "parser.cpp"
    break;

  case 68: /* expr: arith_expr  */
#line 355 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1817 "parser.cpp"
    break;

  case 69: /* expr: expr '|' expr  */
#line 357 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " | " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1826 "parser.cpp"
    break;

  case 70: /* arith_expr: term  */
#line 364 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1832 "parser.cpp"
    break;

  case 71: /* arith_expr: arith_expr PLUS term  */
#line 366 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " + " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1841 "parser.cpp"
    break;

  case 72: /* arith_expr: arith_expr MINUS term  */
#line 371 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " - " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1850 "parser.cpp"
    break;

  case 73: /* term: factor  */
#line 378 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1856 "parser.cpp"
    break;

  case 74: /* term: term TIMES factor  */
#line 380 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " * " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1865 "parser.cpp"
    break;

  case 75: /* term: term DIVIDEDBY factor  */
#line 385 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " / " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1874 "parser.cpp"
    break;

  case 76: /* term: term MOD factor  */
#line 390 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " % " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1883 "parser.cpp"
    break;

  case 77: /* term: term '&' factor  */
#line 395 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " & " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1892 "parser.cpp"
    break;

  case 78: /* term: term "<<" factor  */
#line 400 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " << " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1901 "parser.cpp"
    break;

  case 79: /* term: term ">>" factor  */
#line 405 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " >> " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1910 "parser.cpp"
    break;

  case 80: /* term: term "//" factor  */
#line 410 "parser.y"
    {
        (yyval.str) = new std::string("Math.floor(" + *(yyvsp[-2].str) + " / " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1919 "parser.cpp"
    break;

  case 81: /* factor: PLUS factor  */
#line 417 "parser.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 1925 "parser.cpp"
    break;

  case 82: /* factor: MINUS factor  */
#line 419 "parser.y"
    {
        (yyval.str) = new std::string("-(" + *(yyvsp[0].str) + ")");
        delete (yyvsp[0].str);
    }
#line 1934 "parser.cpp"
    break;

  case 83: /* factor: power  */
#line 423 "parser.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1940 "parser.cpp"
    break;

  case 84: /* power: atom_expr  */
#line 427 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1946 "parser.cpp"
    break;

  case 85: /* power: atom_expr POW factor  */
#line 429 "parser.y"
    {
        (yyval.str) = new std::string("(" + *(yyvsp[-2].str) + " ** " + *(yyvsp[0].str) + ")");
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 1955 "parser.cpp"
    break;

  case 86: /* atom_expr: atom  */
#line 436 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1961 "parser.cpp"
    break;

  case 87: /* atom_expr: atom trailer  */
#line 437 "parser.y"
                   { 
        (yyval.str) = new std::string(*(yyvsp[-1].str) + *(yyvsp[0].str)); 
        delete (yyvsp[-1].str); delete (yyvsp[0].str);
    }
#line 1970 "parser.cpp"
    break;

  case 88: /* atom: IDENTIFIER  */
#line 444 "parser.y"
                 { 
        // Verificar existencia en tabla de símbolos
        if (symbol_table[current_scope.back()].find(*(yyvsp[0].str)) == symbol_table[current_scope.back()].end()) {
            yyerror(("Variable no declarada: " + *(yyvsp[0].str)).c_str());
        }
        (yyval.str) = (yyvsp[0].str);
    }
#line 1982 "parser.cpp"
    break;

  case 89: /* atom: INTEGER  */
#line 451 "parser.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1988 "parser.cpp"
    break;

  case 90: /* atom: FLOAT  */
#line 452 "parser.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1994 "parser.cpp"
    break;

  case 91: /* atom: STRING  */
#line 453 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 2000 "parser.cpp"
    break;

  case 92: /* atom: BOOLEAN  */
#line 454 "parser.y"
              { (yyval.str) = new std::string((yyvsp[0].str) ? "true" : "false"); }
#line 2006 "parser.cpp"
    break;

  case 93: /* atom: NONE  */
#line 455 "parser.y"
           { (yyval.str) = new std::string("null"); }
#line 2012 "parser.cpp"
    break;

  case 94: /* atom: list  */
#line 456 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2018 "parser.cpp"
    break;

  case 95: /* atom: LPAREN expr RPAREN  */
#line 457 "parser.y"
                         { (yyval.str) = new std::string("(" + *(yyvsp[-1].str) + ")"); delete (yyvsp[-1].str); }
#line 2024 "parser.cpp"
    break;

  case 96: /* list: LBRACK testlist RBRACK  */
#line 462 "parser.y"
    { 
        (yyval.str) = new std::string("[" + *(yyvsp[-1].str) + "]"); 
        delete (yyvsp[-1].str);
    }
#line 2033 "parser.cpp"
    break;

  case 97: /* testlist: %empty  */
#line 469 "parser.y"
                   { (yyval.str) = new std::string(""); }
#line 2039 "parser.cpp"
    break;

  case 98: /* testlist: test  */
#line 470 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2045 "parser.cpp"
    break;

  case 99: /* testlist: testlist COMMA test  */
#line 472 "parser.y"
    { 
        (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str)); 
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 2054 "parser.cpp"
    break;

  case 100: /* trailer: '(' ')'  */
#line 479 "parser.y"
              { (yyval.str) = new std::string("()"); }
#line 2060 "parser.cpp"
    break;

  case 101: /* trailer: '(' arglist ')'  */
#line 480 "parser.y"
                      { (yyval.str) = new std::string("(" + *(yyvsp[-1].str) + ")"); delete (yyvsp[-1].str); }
#line 2066 "parser.cpp"
    break;

  case 102: /* trailer: '[' subscriptlist ']'  */
#line 481 "parser.y"
                            { (yyval.str) = new std::string("[" + *(yyvsp[-1].str) + "]"); delete (yyvsp[-1].str); }
#line 2072 "parser.cpp"
    break;

  case 103: /* trailer: '.' IDENTIFIER  */
#line 482 "parser.y"
                     { (yyval.str) = new std::string("." + *(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2078 "parser.cpp"
    break;

  case 104: /* subscriptlist: subscript  */
#line 486 "parser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 2084 "parser.cpp"
    break;

  case 105: /* subscriptlist: subscriptlist ',' subscript  */
#line 487 "parser.y"
                                  { 
        (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str)); 
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 2093 "parser.cpp"
    break;

  case 106: /* subscript: test  */
#line 494 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2099 "parser.cpp"
    break;

  case 107: /* subscript: ':' test  */
#line 495 "parser.y"
               { (yyval.str) = new std::string(":" + *(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2105 "parser.cpp"
    break;

  case 108: /* subscript: test ':' test  */
#line 496 "parser.y"
                    { 
        (yyval.str) = new std::string(*(yyvsp[-2].str) + ":" + *(yyvsp[0].str)); 
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 2114 "parser.cpp"
    break;

  case 109: /* subscript: test ':' test sliceop  */
#line 500 "parser.y"
                            {
        (yyval.str) = new std::string(*(yyvsp[-3].str) + ":" + *(yyvsp[-1].str) + *(yyvsp[0].str)); 
        delete (yyvsp[-3].str); delete (yyvsp[-1].str); delete (yyvsp[0].str);
    }
#line 2123 "parser.cpp"
    break;

  case 110: /* sliceop: ':'  */
#line 507 "parser.y"
          { (yyval.str) = new std::string(":"); }
#line 2129 "parser.cpp"
    break;

  case 111: /* sliceop: ':' test  */
#line 508 "parser.y"
               { (yyval.str) = new std::string(":" + *(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2135 "parser.cpp"
    break;

  case 112: /* argument: test  */
#line 512 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 2141 "parser.cpp"
    break;

  case 113: /* argument: test '=' test  */
#line 513 "parser.y"
                    { 
        (yyval.str) = new std::string(*(yyvsp[-2].str) + " = " + *(yyvsp[0].str)); 
        delete (yyvsp[-2].str); delete (yyvsp[0].str);
    }
#line 2150 "parser.cpp"
    break;

  case 114: /* arglist: argument  */
#line 520 "parser.y"
               { (yyval.str) = new std::string(*(yyvsp[0].str));
                 delete (yyvsp[0].str);}
#line 2157 "parser.cpp"
    break;

  case 115: /* arglist: arglist COMMA argument  */
#line 522 "parser.y"
                             { (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str));
                 delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 2164 "parser.cpp"
    break;


#line 2168 "parser.cpp"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 525 "parser.y"



