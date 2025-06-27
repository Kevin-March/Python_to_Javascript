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
    BOOLEAN = 260,                 /* BOOLEAN  */
    FLOAT = 261,                   /* FLOAT  */
    STRING = 262,                  /* STRING  */
    CHAR = 263,                    /* CHAR  */
    DOUBLE = 264,                  /* DOUBLE  */
    CONSTANT = 265,                /* CONSTANT  */
    EQUALS = 266,                  /* EQUALS  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    TIMES = 269,                   /* TIMES  */
    DIVIDEDBY = 270,               /* DIVIDEDBY  */
    EQ = 271,                      /* EQ  */
    NEQ = 272,                     /* NEQ  */
    GT = 273,                      /* GT  */
    GTE = 274,                     /* GTE  */
    LT = 275,                      /* LT  */
    LTE = 276,                     /* LTE  */
    RETURN = 277,                  /* RETURN  */
    INDENT = 278,                  /* INDENT  */
    DEDENT = 279,                  /* DEDENT  */
    NEWLINE = 280,                 /* NEWLINE  */
    IF = 281,                      /* IF  */
    COLON = 282,                   /* COLON  */
    AND = 283,                     /* AND  */
    BREAK = 284,                   /* BREAK  */
    ELIF = 285,                    /* ELIF  */
    ELSE = 286,                    /* ELSE  */
    FOR = 287,                     /* FOR  */
    IN = 288,                      /* IN  */
    RANGE = 289,                   /* RANGE  */
    NOT = 290,                     /* NOT  */
    OR = 291,                      /* OR  */
    WHILE = 292,                   /* WHILE  */
    DEF = 293,                     /* DEF  */
    SEMICOLON = 294,               /* SEMICOLON  */
    LPAREN = 295,                  /* LPAREN  */
    RPAREN = 296,                  /* RPAREN  */
    COMMA = 297,                   /* COMMA  */
    LBRACK = 298,                  /* LBRACK  */
    RBRACK = 299,                  /* RBRACK  */
    PRINT = 300,                   /* PRINT  */
    UNKNOWN = 301,                 /* UNKNOWN  */
    ENDMARKER = 302,               /* ENDMARKER  */
    POW = 303,                     /* POW  */
    CLASS = 304,                   /* CLASS  */
    ARROW = 305,                   /* ARROW  */
    MOD = 306,                     /* MOD  */
    NONE = 307,                    /* NONE  */
    NAME = 308,                    /* NAME  */
    UMINUS = 309                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

  float value;
  std::string* str;
  int token;

#line 124 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
