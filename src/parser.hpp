/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    TBOOLEAN = 260,                /* TBOOLEAN  */
    FBOOLEAN = 261,                /* FBOOLEAN  */
    FLOAT = 262,                   /* FLOAT  */
    STRING = 263,                  /* STRING  */
    CHAR = 264,                    /* CHAR  */
    DOUBLE = 265,                  /* DOUBLE  */
    CONSTANT = 266,                /* CONSTANT  */
    EQUALS = 267,                  /* EQUALS  */
    PLUS = 268,                    /* PLUS  */
    MINUS = 269,                   /* MINUS  */
    TIMES = 270,                   /* TIMES  */
    DIVIDEDBY = 271,               /* DIVIDEDBY  */
    EQ = 272,                      /* EQ  */
    NEQ = 273,                     /* NEQ  */
    GT = 274,                      /* GT  */
    GTE = 275,                     /* GTE  */
    LT = 276,                      /* LT  */
    LTE = 277,                     /* LTE  */
    RETURN = 278,                  /* RETURN  */
    INDENT = 279,                  /* INDENT  */
    DEDENT = 280,                  /* DEDENT  */
    NEWLINE = 281,                 /* NEWLINE  */
    IF = 282,                      /* IF  */
    COLON = 283,                   /* COLON  */
    AND = 284,                     /* AND  */
    BREAK = 285,                   /* BREAK  */
    ELIF = 286,                    /* ELIF  */
    ELSE = 287,                    /* ELSE  */
    FOR = 288,                     /* FOR  */
    IN = 289,                      /* IN  */
    RANGE = 290,                   /* RANGE  */
    NOT = 291,                     /* NOT  */
    OR = 292,                      /* OR  */
    WHILE = 293,                   /* WHILE  */
    DEF = 294,                     /* DEF  */
    SEMICOLON = 295,               /* SEMICOLON  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    COMMA = 298,                   /* COMMA  */
    LBRACK = 299,                  /* LBRACK  */
    RBRACK = 300,                  /* RBRACK  */
    PRINT = 301,                   /* PRINT  */
    UNKNOWN = 302                  /* UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "parser.y"

  float value;
  std::string* str;
  int token;

#line 117 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
