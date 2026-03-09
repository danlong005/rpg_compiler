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
    KW_IND = 274,                  /* KW_IND  */
    KW_POINTER = 275,              /* KW_POINTER  */
    KW_NULL = 276,                 /* KW_NULL  */
    KW_DAYS = 277,                 /* KW_DAYS  */
    KW_MONTHS = 278,               /* KW_MONTHS  */
    KW_YEARS = 279,                /* KW_YEARS  */
    KW_HOURS = 280,                /* KW_HOURS  */
    KW_MINUTES = 281,              /* KW_MINUTES  */
    KW_SECONDS = 282,              /* KW_SECONDS  */
    KW_MSECONDS = 283,             /* KW_MSECONDS  */
    KW_CONST = 284,                /* KW_CONST  */
    KW_INZ = 285,                  /* KW_INZ  */
    KW_DSPLY = 286,                /* KW_DSPLY  */
    KW_EVAL = 287,                 /* KW_EVAL  */
    KW_EVAL_CORR = 288,            /* KW_EVAL_CORR  */
    KW_EVALR = 289,                /* KW_EVALR  */
    KW_CALLP = 290,                /* KW_CALLP  */
    KW_LEAVESR = 291,              /* KW_LEAVESR  */
    KW_ON_EXIT = 292,              /* KW_ON_EXIT  */
    KW_DEALLOC = 293,              /* KW_DEALLOC  */
    KW_TEST = 294,                 /* KW_TEST  */
    KW_STATIC = 295,               /* KW_STATIC  */
    KW_TEMPLATE = 296,             /* KW_TEMPLATE  */
    KW_BASED = 297,                /* KW_BASED  */
    KW_OPTIONS = 298,              /* KW_OPTIONS  */
    KW_NOPASS = 299,               /* KW_NOPASS  */
    KW_OMIT = 300,                 /* KW_OMIT  */
    KW_EXPORT = 301,               /* KW_EXPORT  */
    KW_IMPORT = 302,               /* KW_IMPORT  */
    KW_EXTPGM = 303,               /* KW_EXTPGM  */
    KW_EXTPROC = 304,              /* KW_EXTPROC  */
    KW_CTLOPT = 305,               /* KW_CTLOPT  */
    KW_RETURN = 306,               /* KW_RETURN  */
    KW_INLR = 307,                 /* KW_INLR  */
    KW_ON = 308,                   /* KW_ON  */
    KW_BLANKS = 309,               /* KW_BLANKS  */
    KW_ZEROS = 310,                /* KW_ZEROS  */
    KW_HIVAL = 311,                /* KW_HIVAL  */
    KW_LOVAL = 312,                /* KW_LOVAL  */
    KW_IF = 313,                   /* KW_IF  */
    KW_ELSEIF = 314,               /* KW_ELSEIF  */
    KW_ELSE = 315,                 /* KW_ELSE  */
    KW_ENDIF = 316,                /* KW_ENDIF  */
    KW_DOW = 317,                  /* KW_DOW  */
    KW_DOU = 318,                  /* KW_DOU  */
    KW_ENDDO = 319,                /* KW_ENDDO  */
    KW_FOR = 320,                  /* KW_FOR  */
    KW_ENDFOR = 321,               /* KW_ENDFOR  */
    KW_TO = 322,                   /* KW_TO  */
    KW_DOWNTO = 323,               /* KW_DOWNTO  */
    KW_BY = 324,                   /* KW_BY  */
    KW_SELECT = 325,               /* KW_SELECT  */
    KW_WHEN = 326,                 /* KW_WHEN  */
    KW_OTHER = 327,                /* KW_OTHER  */
    KW_ENDSL = 328,                /* KW_ENDSL  */
    KW_ITER = 329,                 /* KW_ITER  */
    KW_LEAVE = 330,                /* KW_LEAVE  */
    KW_MONITOR = 331,              /* KW_MONITOR  */
    KW_ON_ERROR = 332,             /* KW_ON_ERROR  */
    KW_ENDMON = 333,               /* KW_ENDMON  */
    KW_BEGSR = 334,                /* KW_BEGSR  */
    KW_ENDSR = 335,                /* KW_ENDSR  */
    KW_EXSR = 336,                 /* KW_EXSR  */
    KW_OFF = 337,                  /* KW_OFF  */
    KW_RESET = 338,                /* KW_RESET  */
    KW_CLEAR = 339,                /* KW_CLEAR  */
    KW_SORTA = 340,                /* KW_SORTA  */
    INDICATOR = 341,               /* INDICATOR  */
    KW_AND = 342,                  /* KW_AND  */
    KW_OR = 343,                   /* KW_OR  */
    KW_NOT = 344,                  /* KW_NOT  */
    KW_DCL_PROC = 345,             /* KW_DCL_PROC  */
    KW_END_PROC = 346,             /* KW_END_PROC  */
    KW_DCL_PI = 347,               /* KW_DCL_PI  */
    KW_END_PI = 348,               /* KW_END_PI  */
    KW_DCL_PR = 349,               /* KW_DCL_PR  */
    KW_END_PR = 350,               /* KW_END_PR  */
    KW_VALUE = 351,                /* KW_VALUE  */
    KW_DCL_DS = 352,               /* KW_DCL_DS  */
    KW_END_DS = 353,               /* KW_END_DS  */
    KW_QUALIFIED = 354,            /* KW_QUALIFIED  */
    KW_DIM = 355,                  /* KW_DIM  */
    KW_LIKEDS = 356,               /* KW_LIKEDS  */
    KW_LIKE = 357,                 /* KW_LIKE  */
    KW_DCL_SUBF = 358,             /* KW_DCL_SUBF  */
    KW_DCL_PARM = 359,             /* KW_DCL_PARM  */
    DOT = 360,                     /* DOT  */
    BIF_CHAR = 361,                /* BIF_CHAR  */
    BIF_TRIM = 362,                /* BIF_TRIM  */
    BIF_TRIML = 363,               /* BIF_TRIML  */
    BIF_TRIMR = 364,               /* BIF_TRIMR  */
    BIF_LEN = 365,                 /* BIF_LEN  */
    BIF_SUBST = 366,               /* BIF_SUBST  */
    BIF_SCAN = 367,                /* BIF_SCAN  */
    BIF_SCANRPL = 368,             /* BIF_SCANRPL  */
    BIF_XLATE = 369,               /* BIF_XLATE  */
    BIF_DEC = 370,                 /* BIF_DEC  */
    BIF_INT = 371,                 /* BIF_INT  */
    BIF_ELEM = 372,                /* BIF_ELEM  */
    BIF_FOUND = 373,               /* BIF_FOUND  */
    BIF_EOF = 374,                 /* BIF_EOF  */
    BIF_ABS = 375,                 /* BIF_ABS  */
    BIF_DIV = 376,                 /* BIF_DIV  */
    BIF_REM = 377,                 /* BIF_REM  */
    BIF_SIZE = 378,                /* BIF_SIZE  */
    BIF_ADDR = 379,                /* BIF_ADDR  */
    BIF_PARMS = 380,               /* BIF_PARMS  */
    BIF_STATUS = 381,              /* BIF_STATUS  */
    BIF_ERROR = 382,               /* BIF_ERROR  */
    BIF_MAX = 383,                 /* BIF_MAX  */
    BIF_MIN = 384,                 /* BIF_MIN  */
    BIF_LOOKUP = 385,              /* BIF_LOOKUP  */
    BIF_DATE = 386,                /* BIF_DATE  */
    BIF_TIME = 387,                /* BIF_TIME  */
    BIF_TIMESTAMP = 388,           /* BIF_TIMESTAMP  */
    BIF_DIFF = 389,                /* BIF_DIFF  */
    BIF_DAYS = 390,                /* BIF_DAYS  */
    BIF_MONTHS = 391,              /* BIF_MONTHS  */
    BIF_YEARS = 392,               /* BIF_YEARS  */
    BIF_EDITC = 393,               /* BIF_EDITC  */
    BIF_EDITW = 394,               /* BIF_EDITW  */
    BIF_REPLACE = 395,             /* BIF_REPLACE  */
    BIF_CHECK = 396,               /* BIF_CHECK  */
    BIF_CHECKR = 397,              /* BIF_CHECKR  */
    BIF_LOWER = 398,               /* BIF_LOWER  */
    BIF_UPPER = 399,               /* BIF_UPPER  */
    BIF_SUBDT = 400,               /* BIF_SUBDT  */
    BIF_FLOAT = 401,               /* BIF_FLOAT  */
    BIF_SQRT = 402,                /* BIF_SQRT  */
    BIF_ALLOC = 403,               /* BIF_ALLOC  */
    BIF_REALLOC = 404,             /* BIF_REALLOC  */
    BIF_XFOOT = 405,               /* BIF_XFOOT  */
    BIF_SUBARR = 406,              /* BIF_SUBARR  */
    BIF_SPLIT = 407,               /* BIF_SPLIT  */
    BIF_UNS = 408,                 /* BIF_UNS  */
    BIF_INTH = 409,                /* BIF_INTH  */
    BIF_DECH = 410,                /* BIF_DECH  */
    BIF_DECPOS = 411,              /* BIF_DECPOS  */
    BIF_CONCATARR = 412,           /* BIF_CONCATARR  */
    BIF_LEFT = 413,                /* BIF_LEFT  */
    BIF_RIGHT = 414,               /* BIF_RIGHT  */
    BIF_STR = 415,                 /* BIF_STR  */
    BIF_MAXARR = 416,              /* BIF_MAXARR  */
    BIF_MINARR = 417,              /* BIF_MINARR  */
    BIF_LIST = 418,                /* BIF_LIST  */
    BIF_RANGE = 419,               /* BIF_RANGE  */
    BIF_LOOKUPLT = 420,            /* BIF_LOOKUPLT  */
    BIF_LOOKUPGE = 421,            /* BIF_LOOKUPGE  */
    BIF_LOOKUPLE = 422,            /* BIF_LOOKUPLE  */
    BIF_LOOKUPGT = 423,            /* BIF_LOOKUPGT  */
    BIF_HOURS = 424,               /* BIF_HOURS  */
    BIF_MINUTES = 425,             /* BIF_MINUTES  */
    BIF_SECONDS = 426,             /* BIF_SECONDS  */
    BIF_MSECONDS = 427,            /* BIF_MSECONDS  */
    BIF_PADDR = 428,               /* BIF_PADDR  */
    BIF_PROC = 429,                /* BIF_PROC  */
    BIF_PASSED = 430,              /* BIF_PASSED  */
    BIF_OMITTED = 431,             /* BIF_OMITTED  */
    BIF_OCCUR = 432,               /* BIF_OCCUR  */
    KW_ALL = 433,                  /* KW_ALL  */
    KW_UNS = 434,                  /* KW_UNS  */
    KW_FLOAT_TYPE = 435,           /* KW_FLOAT_TYPE  */
    KW_BINDEC = 436,               /* KW_BINDEC  */
    KW_UCS2 = 437,                 /* KW_UCS2  */
    KW_GRAPH = 438,                /* KW_GRAPH  */
    KW_OBJECT = 439,               /* KW_OBJECT  */
    KW_JAVA = 440,                 /* KW_JAVA  */
    KW_OCCURS = 441,               /* KW_OCCURS  */
    KW_OVERLAY = 442,              /* KW_OVERLAY  */
    KW_POS = 443,                  /* KW_POS  */
    KW_PREFIX = 444,               /* KW_PREFIX  */
    KW_DATFMT = 445,               /* KW_DATFMT  */
    KW_TIMFMT = 446,               /* KW_TIMFMT  */
    KW_EXTNAME = 447,              /* KW_EXTNAME  */
    KW_RTNPARM = 448,              /* KW_RTNPARM  */
    KW_OPDESC = 449,               /* KW_OPDESC  */
    KW_ASCEND = 450,               /* KW_ASCEND  */
    KW_DESCEND = 451,              /* KW_DESCEND  */
    KW_NULLIND = 452,              /* KW_NULLIND  */
    KW_VARSIZE = 453,              /* KW_VARSIZE  */
    KW_STRING_OPT = 454,           /* KW_STRING_OPT  */
    KW_TRIM_OPT = 455,             /* KW_TRIM_OPT  */
    KW_FOR_EACH = 456,             /* KW_FOR_EACH  */
    KW_IN = 457,                   /* KW_IN  */
    IDENTIFIER = 458,              /* IDENTIFIER  */
    INTEGER_LITERAL = 459,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 460,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 461,          /* STRING_LITERAL  */
    SEMICOLON = 462,               /* SEMICOLON  */
    EQUALS = 463,                  /* EQUALS  */
    LPAREN = 464,                  /* LPAREN  */
    RPAREN = 465,                  /* RPAREN  */
    COLON = 466,                   /* COLON  */
    PLUS = 467,                    /* PLUS  */
    MINUS = 468,                   /* MINUS  */
    STAR = 469,                    /* STAR  */
    SLASH = 470,                   /* SLASH  */
    NE = 471,                      /* NE  */
    LE = 472,                      /* LE  */
    GE = 473,                      /* GE  */
    LT = 474,                      /* LT  */
    GT = 475                       /* GT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "src/parser.y"

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

#line 334 "build/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_H_INCLUDED  */
