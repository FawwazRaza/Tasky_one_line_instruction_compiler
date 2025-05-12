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

#ifndef YY_YY_TASKY_TAB_H_INCLUDED
# define YY_YY_TASKY_TAB_H_INCLUDED
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
    MAKE = 258,                    /* MAKE  */
    NEW = 259,                     /* NEW  */
    FOLDER = 260,                  /* FOLDER  */
    FILEKW = 261,                  /* FILEKW  */
    INSIDE = 262,                  /* INSIDE  */
    NAMED = 263,                   /* NAMED  */
    PLACE = 264,                   /* PLACE  */
    ADD = 265,                     /* ADD  */
    AT = 266,                      /* AT  */
    END = 267,                     /* END  */
    REMOVE = 268,                  /* REMOVE  */
    SHOW = 269,                    /* SHOW  */
    IN = 270,                      /* IN  */
    ALL = 271,                     /* ALL  */
    CONTAINING = 272,              /* CONTAINING  */
    DELETE = 273,                  /* DELETE  */
    IF = 274,                      /* IF  */
    CONTAIN = 275,                 /* CONTAIN  */
    CONTENT = 276,                 /* CONTENT  */
    OF = 277,                      /* OF  */
    CHANGE = 278,                  /* CHANGE  */
    EXTENSION = 279,               /* EXTENSION  */
    INTO = 280,                    /* INTO  */
    REPEAT = 281,                  /* REPEAT  */
    FROM = 282,                    /* FROM  */
    UNTIL = 283,                   /* UNTIL  */
    COMPRESS = 284,                /* COMPRESS  */
    RENAME = 285,                  /* RENAME  */
    WITH = 286,                    /* WITH  */
    PREFIX = 287,                  /* PREFIX  */
    COUNT = 288,                   /* COUNT  */
    RUN = 289,                     /* RUN  */
    WRITE = 290,                   /* WRITE  */
    TO = 291,                      /* TO  */
    APPEND = 292,                  /* APPEND  */
    SEARCH = 293,                  /* SEARCH  */
    FOR = 294,                     /* FOR  */
    TEMPLATE = 295,                /* TEMPLATE  */
    VARIABLES = 296,               /* VARIABLES  */
    BATCH = 297,                   /* BATCH  */
    PROCESS = 298,                 /* PROCESS  */
    STATS = 299,                   /* STATS  */
    LARGER = 300,                  /* LARGER  */
    THAN = 301,                    /* THAN  */
    TRANSFORM = 302,               /* TRANSFORM  */
    USING = 303,                   /* USING  */
    REGEX = 304,                   /* REGEX  */
    REPLACE = 305,                 /* REPLACE  */
    EVERY = 306,                   /* EVERY  */
    LINES = 307,                   /* LINES  */
    SIZE = 308,                    /* SIZE  */
    WHEN = 309,                    /* WHEN  */
    MOVE = 310,                    /* MOVE  */
    SORT = 311,                    /* SORT  */
    BY = 312,                      /* BY  */
    DATE = 313,                    /* DATE  */
    CREATE = 314,                  /* CREATE  */
    SUBTRACT = 315,                /* SUBTRACT  */
    MULTIPLY = 316,                /* MULTIPLY  */
    DIVIDE = 317,                  /* DIVIDE  */
    CALCULATE = 318,               /* CALCULATE  */
    STORE = 319,                   /* STORE  */
    RESULT = 320,                  /* RESULT  */
    VALUE = 321,                   /* VALUE  */
    PRINT = 322,                   /* PRINT  */
    AND = 323,                     /* AND  */
    MOD = 324,                     /* MOD  */
    POWER = 325,                   /* POWER  */
    EQUALS = 326,                  /* EQUALS  */
    PLUS = 327,                    /* PLUS  */
    MINUS = 328,                   /* MINUS  */
    TIMES = 329,                   /* TIMES  */
    DIV = 330,                     /* DIV  */
    MODULO = 331,                  /* MODULO  */
    POW = 332,                     /* POW  */
    STRING = 333,                  /* STRING  */
    IDENTIFIER = 334,              /* IDENTIFIER  */
    NUMBER = 335                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "tasky.y"

    char *str;
    int num;
    ASTNode *node;

#line 150 "tasky.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TASKY_TAB_H_INCLUDED  */
