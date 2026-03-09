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

#ifndef YY_YY_BUILD_PARSER_H_INCLUDED
# define YY_YY_BUILD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

#include <memory>
#include <vector>
#include <string>
#include "ast.h"

struct StmtList {
    std::vector<rpg::Statement*> stmts;
};

struct ElseIfData {
    rpg::Expression* cond;
    std::vector<rpg::Statement*> body;
};

struct WhenData {
    rpg::Expression* cond;
    std::vector<rpg::Statement*> body;
};

struct ParamList {
    std::vector<rpg::ParamDecl> params;
};

struct DSFieldList {
    std::vector<rpg::DSField> fields;
};

#line 78 "build/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_FREE = 258,                 /* KW_FREE  */
    KW_DCL_F = 259,                /* KW_DCL_F  */
    KW_DCL_S = 260,                /* KW_DCL_S  */
    KW_DCL_C = 261,                /* KW_DCL_C  */
    KW_DISK = 262,                 /* KW_DISK  */
    KW_PRINTER = 263,              /* KW_PRINTER  */
    KW_WORKSTN = 264,              /* KW_WORKSTN  */
    KW_USAGE = 265,                /* KW_USAGE  */
    KW_CHAR = 266,                 /* KW_CHAR  */
    KW_VARCHAR = 267,              /* KW_VARCHAR  */
    KW_INT = 268,                  /* KW_INT  */
    KW_PACKED = 269,               /* KW_PACKED  */
    KW_ZONED = 270,                /* KW_ZONED  */
    KW_DATE = 271,                 /* KW_DATE  */
    KW_TIME = 272,                 /* KW_TIME  */
    KW_TIMESTAMP = 273,            /* KW_TIMESTAMP  */
    KW_POINTER = 274,              /* KW_POINTER  */
    KW_NULL = 275,                 /* KW_NULL  */
    KW_DAYS = 276,                 /* KW_DAYS  */
    KW_MONTHS = 277,               /* KW_MONTHS  */
    KW_YEARS = 278,                /* KW_YEARS  */
    KW_CONST = 279,                /* KW_CONST  */
    KW_INZ = 280,                  /* KW_INZ  */
    KW_DSPLY = 281,                /* KW_DSPLY  */
    KW_EVAL = 282,                 /* KW_EVAL  */
    KW_EVAL_CORR = 283,            /* KW_EVAL_CORR  */
    KW_RETURN = 284,               /* KW_RETURN  */
    KW_INLR = 285,                 /* KW_INLR  */
    KW_ON = 286,                   /* KW_ON  */
    KW_IF = 287,                   /* KW_IF  */
    KW_ELSEIF = 288,               /* KW_ELSEIF  */
    KW_ELSE = 289,                 /* KW_ELSE  */
    KW_ENDIF = 290,                /* KW_ENDIF  */
    KW_DOW = 291,                  /* KW_DOW  */
    KW_DOU = 292,                  /* KW_DOU  */
    KW_ENDDO = 293,                /* KW_ENDDO  */
    KW_FOR = 294,                  /* KW_FOR  */
    KW_ENDFOR = 295,               /* KW_ENDFOR  */
    KW_TO = 296,                   /* KW_TO  */
    KW_DOWNTO = 297,               /* KW_DOWNTO  */
    KW_BY = 298,                   /* KW_BY  */
    KW_SELECT = 299,               /* KW_SELECT  */
    KW_WHEN = 300,                 /* KW_WHEN  */
    KW_OTHER = 301,                /* KW_OTHER  */
    KW_ENDSL = 302,                /* KW_ENDSL  */
    KW_ITER = 303,                 /* KW_ITER  */
    KW_LEAVE = 304,                /* KW_LEAVE  */
    KW_MONITOR = 305,              /* KW_MONITOR  */
    KW_ON_ERROR = 306,             /* KW_ON_ERROR  */
    KW_ENDMON = 307,               /* KW_ENDMON  */
    KW_BEGSR = 308,                /* KW_BEGSR  */
    KW_ENDSR = 309,                /* KW_ENDSR  */
    KW_EXSR = 310,                 /* KW_EXSR  */
    KW_OFF = 311,                  /* KW_OFF  */
    KW_RESET = 312,                /* KW_RESET  */
    KW_CLEAR = 313,                /* KW_CLEAR  */
    KW_SORTA = 314,                /* KW_SORTA  */
    INDICATOR = 315,               /* INDICATOR  */
    KW_AND = 316,                  /* KW_AND  */
    KW_OR = 317,                   /* KW_OR  */
    KW_NOT = 318,                  /* KW_NOT  */
    KW_DCL_PROC = 319,             /* KW_DCL_PROC  */
    KW_END_PROC = 320,             /* KW_END_PROC  */
    KW_DCL_PI = 321,               /* KW_DCL_PI  */
    KW_END_PI = 322,               /* KW_END_PI  */
    KW_DCL_PR = 323,               /* KW_DCL_PR  */
    KW_END_PR = 324,               /* KW_END_PR  */
    KW_VALUE = 325,                /* KW_VALUE  */
    KW_DCL_DS = 326,               /* KW_DCL_DS  */
    KW_END_DS = 327,               /* KW_END_DS  */
    KW_QUALIFIED = 328,            /* KW_QUALIFIED  */
    KW_DIM = 329,                  /* KW_DIM  */
    KW_LIKEDS = 330,               /* KW_LIKEDS  */
    KW_LIKE = 331,                 /* KW_LIKE  */
    KW_DCL_SUBF = 332,             /* KW_DCL_SUBF  */
    KW_DCL_PARM = 333,             /* KW_DCL_PARM  */
    DOT = 334,                     /* DOT  */
    BIF_CHAR = 335,                /* BIF_CHAR  */
    BIF_TRIM = 336,                /* BIF_TRIM  */
    BIF_TRIML = 337,               /* BIF_TRIML  */
    BIF_TRIMR = 338,               /* BIF_TRIMR  */
    BIF_LEN = 339,                 /* BIF_LEN  */
    BIF_SUBST = 340,               /* BIF_SUBST  */
    BIF_SCAN = 341,                /* BIF_SCAN  */
    BIF_SCANRPL = 342,             /* BIF_SCANRPL  */
    BIF_XLATE = 343,               /* BIF_XLATE  */
    BIF_DEC = 344,                 /* BIF_DEC  */
    BIF_INT = 345,                 /* BIF_INT  */
    BIF_ELEM = 346,                /* BIF_ELEM  */
    BIF_FOUND = 347,               /* BIF_FOUND  */
    BIF_EOF = 348,                 /* BIF_EOF  */
    BIF_ABS = 349,                 /* BIF_ABS  */
    BIF_DIV = 350,                 /* BIF_DIV  */
    BIF_REM = 351,                 /* BIF_REM  */
    BIF_SIZE = 352,                /* BIF_SIZE  */
    BIF_ADDR = 353,                /* BIF_ADDR  */
    BIF_PARMS = 354,               /* BIF_PARMS  */
    BIF_STATUS = 355,              /* BIF_STATUS  */
    BIF_ERROR = 356,               /* BIF_ERROR  */
    BIF_MAX = 357,                 /* BIF_MAX  */
    BIF_MIN = 358,                 /* BIF_MIN  */
    BIF_LOOKUP = 359,              /* BIF_LOOKUP  */
    BIF_DATE = 360,                /* BIF_DATE  */
    BIF_TIME = 361,                /* BIF_TIME  */
    BIF_TIMESTAMP = 362,           /* BIF_TIMESTAMP  */
    BIF_DIFF = 363,                /* BIF_DIFF  */
    BIF_DAYS = 364,                /* BIF_DAYS  */
    BIF_MONTHS = 365,              /* BIF_MONTHS  */
    BIF_YEARS = 366,               /* BIF_YEARS  */
    BIF_EDITC = 367,               /* BIF_EDITC  */
    BIF_EDITW = 368,               /* BIF_EDITW  */
    BIF_REPLACE = 369,             /* BIF_REPLACE  */
    BIF_CHECK = 370,               /* BIF_CHECK  */
    BIF_CHECKR = 371,              /* BIF_CHECKR  */
    IDENTIFIER = 372,              /* IDENTIFIER  */
    INTEGER_LITERAL = 373,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 374,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 375,          /* STRING_LITERAL  */
    SEMICOLON = 376,               /* SEMICOLON  */
    EQUALS = 377,                  /* EQUALS  */
    LPAREN = 378,                  /* LPAREN  */
    RPAREN = 379,                  /* RPAREN  */
    COLON = 380,                   /* COLON  */
    PLUS = 381,                    /* PLUS  */
    MINUS = 382,                   /* MINUS  */
    STAR = 383,                    /* STAR  */
    SLASH = 384,                   /* SLASH  */
    NE = 385,                      /* NE  */
    LE = 386,                      /* LE  */
    GE = 387,                      /* GE  */
    LT = 388,                      /* LT  */
    GT = 389                       /* GT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 74 "src/parser.y"

    int ival;
    double fval;
    char* sval;
    rpg::Expression* expr;
    rpg::Statement* stmt;
    rpg::Program* program;
    std::vector<rpg::Expression*>* expr_list;
    StmtList* stmt_list;
    std::vector<ElseIfData*>* elseif_list;
    ElseIfData* elseif_data;
    std::vector<WhenData*>* when_list;
    WhenData* when_data;
    ParamList* param_list;
    rpg::ParamDecl* param_decl;
    DSFieldList* ds_field_list;
    rpg::DSField* ds_field;

#line 248 "build/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_H_INCLUDED  */
