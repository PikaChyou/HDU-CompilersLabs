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
# define YYDEBUG 1
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
    ID = 258,                      /* ID  */
    INT_LIT = 259,                 /* INT_LIT  */
    FLOAT_LIT = 260,               /* FLOAT_LIT  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    VOID = 263,                    /* VOID  */
    CONST = 264,                   /* CONST  */
    RETURN = 265,                  /* RETURN  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    BREAK = 269,                   /* BREAK  */
    CONTINUE = 270,                /* CONTINUE  */
    LP = 271,                      /* LP  */
    RP = 272,                      /* RP  */
    LB = 273,                      /* LB  */
    RB = 274,                      /* RB  */
    LC = 275,                      /* LC  */
    RC = 276,                      /* RC  */
    COMMA = 277,                   /* COMMA  */
    SEMICN = 278,                  /* SEMICN  */
    MINUS = 279,                   /* MINUS  */
    NOT = 280,                     /* NOT  */
    ASSIGN = 281,                  /* ASSIGN  */
    PLUS = 282,                    /* PLUS  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    LT = 290,                      /* LT  */
    LE = 291,                      /* LE  */
    GT = 292,                      /* GT  */
    GE = 293                       /* GE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT_LIT 259
#define FLOAT_LIT 260
#define INT 261
#define FLOAT 262
#define VOID 263
#define CONST 264
#define RETURN 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define BREAK 269
#define CONTINUE 270
#define LP 271
#define RP 272
#define LB 273
#define RB 274
#define LC 275
#define RC 276
#define COMMA 277
#define SEMICN 278
#define MINUS 279
#define NOT 280
#define ASSIGN 281
#define PLUS 282
#define MUL 283
#define DIV 284
#define MOD 285
#define AND 286
#define OR 287
#define EQ 288
#define NE 289
#define LT 290
#define LE 291
#define GT 292
#define GE 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "ss.y"

    int int_val;
    float float_val;
    char *str_val;
    struct Node *node_val;

#line 150 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
