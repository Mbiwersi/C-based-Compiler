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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    Ident = 258,                   /* Ident  */
    IntLit = 259,                  /* IntLit  */
    Int = 260,                     /* Int  */
    BoolLit = 261,                 /* BoolLit  */
    Bool = 262,                    /* Bool  */
    Write = 263,                   /* Write  */
    Printlines = 264,              /* Printlines  */
    Printspaces = 265,             /* Printspaces  */
    PrintString = 266,             /* PrintString  */
    StringLit = 267,               /* StringLit  */
    IF = 268,                      /* IF  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    EQ = 271,                      /* EQ  */
    NEQ = 272,                     /* NEQ  */
    NOT = 273,                     /* NOT  */
    LT = 274,                      /* LT  */
    LTE = 275,                     /* LTE  */
    GT = 276,                      /* GT  */
    GTE = 277                      /* GTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define Ident 258
#define IntLit 259
#define Int 260
#define BoolLit 261
#define Bool 262
#define Write 263
#define Printlines 264
#define Printspaces 265
#define PrintString 266
#define StringLit 267
#define IF 268
#define AND 269
#define OR 270
#define EQ 271
#define NEQ 272
#define NOT 273
#define LT 274
#define LTE 275
#define GT 276
#define GTE 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "ExprEval.y"

  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;

#line 118 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
