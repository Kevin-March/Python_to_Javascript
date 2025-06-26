/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "parser.y"
{
    std::string* str;
    int int_val;
    double float_val;
    bool bool_val;
}
/* Line 1529 of yacc.c.  */
#line 154 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

