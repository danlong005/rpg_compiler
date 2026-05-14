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
    KW_EVAL_EXT = 295,             /* KW_EVAL_EXT  */
    KW_EVALR_EXT = 296,            /* KW_EVALR_EXT  */
    KW_CALLP_EXT = 297,            /* KW_CALLP_EXT  */
    KW_STATIC = 298,               /* KW_STATIC  */
    KW_TEMPLATE = 299,             /* KW_TEMPLATE  */
    KW_BASED = 300,                /* KW_BASED  */
    KW_OPTIONS = 301,              /* KW_OPTIONS  */
    KW_NOPASS = 302,               /* KW_NOPASS  */
    KW_OMIT = 303,                 /* KW_OMIT  */
    KW_EXPORT = 304,               /* KW_EXPORT  */
    KW_IMPORT = 305,               /* KW_IMPORT  */
    KW_EXTPGM = 306,               /* KW_EXTPGM  */
    KW_EXTPROC = 307,              /* KW_EXTPROC  */
    KW_CTLOPT = 308,               /* KW_CTLOPT  */
    KW_RETURN = 309,               /* KW_RETURN  */
    KW_INLR = 310,                 /* KW_INLR  */
    KW_ON = 311,                   /* KW_ON  */
    KW_BLANKS = 312,               /* KW_BLANKS  */
    KW_ZEROS = 313,                /* KW_ZEROS  */
    KW_HIVAL = 314,                /* KW_HIVAL  */
    KW_LOVAL = 315,                /* KW_LOVAL  */
    KW_USER = 316,                 /* KW_USER  */
    KW_IF = 317,                   /* KW_IF  */
    KW_ELSEIF = 318,               /* KW_ELSEIF  */
    KW_ELSE = 319,                 /* KW_ELSE  */
    KW_ENDIF = 320,                /* KW_ENDIF  */
    KW_DOW = 321,                  /* KW_DOW  */
    KW_DOU = 322,                  /* KW_DOU  */
    KW_ENDDO = 323,                /* KW_ENDDO  */
    KW_FOR = 324,                  /* KW_FOR  */
    KW_ENDFOR = 325,               /* KW_ENDFOR  */
    KW_TO = 326,                   /* KW_TO  */
    KW_DOWNTO = 327,               /* KW_DOWNTO  */
    KW_BY = 328,                   /* KW_BY  */
    KW_SELECT = 329,               /* KW_SELECT  */
    KW_WHEN = 330,                 /* KW_WHEN  */
    KW_OTHER = 331,                /* KW_OTHER  */
    KW_ENDSL = 332,                /* KW_ENDSL  */
    KW_ITER = 333,                 /* KW_ITER  */
    KW_LEAVE = 334,                /* KW_LEAVE  */
    KW_MONITOR = 335,              /* KW_MONITOR  */
    KW_ON_ERROR = 336,             /* KW_ON_ERROR  */
    KW_ENDMON = 337,               /* KW_ENDMON  */
    KW_BEGSR = 338,                /* KW_BEGSR  */
    KW_ENDSR = 339,                /* KW_ENDSR  */
    KW_EXSR = 340,                 /* KW_EXSR  */
    KW_OFF = 341,                  /* KW_OFF  */
    KW_RESET = 342,                /* KW_RESET  */
    KW_CLEAR = 343,                /* KW_CLEAR  */
    KW_SORTA = 344,                /* KW_SORTA  */
    INDICATOR = 345,               /* INDICATOR  */
    KW_AND = 346,                  /* KW_AND  */
    KW_OR = 347,                   /* KW_OR  */
    KW_NOT = 348,                  /* KW_NOT  */
    KW_DCL_PROC = 349,             /* KW_DCL_PROC  */
    KW_END_PROC = 350,             /* KW_END_PROC  */
    KW_DCL_PI = 351,               /* KW_DCL_PI  */
    KW_END_PI = 352,               /* KW_END_PI  */
    KW_DCL_PR = 353,               /* KW_DCL_PR  */
    KW_END_PR = 354,               /* KW_END_PR  */
    KW_VALUE = 355,                /* KW_VALUE  */
    KW_DCL_DS = 356,               /* KW_DCL_DS  */
    KW_END_DS = 357,               /* KW_END_DS  */
    KW_QUALIFIED = 358,            /* KW_QUALIFIED  */
    KW_DIM = 359,                  /* KW_DIM  */
    KW_LIKEDS = 360,               /* KW_LIKEDS  */
    KW_LIKE = 361,                 /* KW_LIKE  */
    KW_DCL_SUBF = 362,             /* KW_DCL_SUBF  */
    KW_DCL_PARM = 363,             /* KW_DCL_PARM  */
    DOT = 364,                     /* DOT  */
    BIF_CHAR = 365,                /* BIF_CHAR  */
    BIF_TRIM = 366,                /* BIF_TRIM  */
    BIF_TRIML = 367,               /* BIF_TRIML  */
    BIF_TRIMR = 368,               /* BIF_TRIMR  */
    BIF_LEN = 369,                 /* BIF_LEN  */
    BIF_SUBST = 370,               /* BIF_SUBST  */
    BIF_SCAN = 371,                /* BIF_SCAN  */
    BIF_SCANRPL = 372,             /* BIF_SCANRPL  */
    BIF_XLATE = 373,               /* BIF_XLATE  */
    BIF_DEC = 374,                 /* BIF_DEC  */
    BIF_INT = 375,                 /* BIF_INT  */
    BIF_ELEM = 376,                /* BIF_ELEM  */
    BIF_FOUND = 377,               /* BIF_FOUND  */
    BIF_EOF = 378,                 /* BIF_EOF  */
    BIF_ABS = 379,                 /* BIF_ABS  */
    BIF_DIV = 380,                 /* BIF_DIV  */
    BIF_REM = 381,                 /* BIF_REM  */
    BIF_SIZE = 382,                /* BIF_SIZE  */
    BIF_ADDR = 383,                /* BIF_ADDR  */
    BIF_PARMS = 384,               /* BIF_PARMS  */
    BIF_STATUS = 385,              /* BIF_STATUS  */
    BIF_ERROR = 386,               /* BIF_ERROR  */
    BIF_MAX = 387,                 /* BIF_MAX  */
    BIF_MIN = 388,                 /* BIF_MIN  */
    BIF_LOOKUP = 389,              /* BIF_LOOKUP  */
    BIF_DATE = 390,                /* BIF_DATE  */
    BIF_TIME = 391,                /* BIF_TIME  */
    BIF_TIMESTAMP = 392,           /* BIF_TIMESTAMP  */
    BIF_DIFF = 393,                /* BIF_DIFF  */
    BIF_DAYS = 394,                /* BIF_DAYS  */
    BIF_MONTHS = 395,              /* BIF_MONTHS  */
    BIF_YEARS = 396,               /* BIF_YEARS  */
    BIF_EDITC = 397,               /* BIF_EDITC  */
    BIF_EDITW = 398,               /* BIF_EDITW  */
    BIF_REPLACE = 399,             /* BIF_REPLACE  */
    BIF_CHECK = 400,               /* BIF_CHECK  */
    BIF_CHECKR = 401,              /* BIF_CHECKR  */
    BIF_LOWER = 402,               /* BIF_LOWER  */
    BIF_UPPER = 403,               /* BIF_UPPER  */
    BIF_SUBDT = 404,               /* BIF_SUBDT  */
    BIF_FLOAT = 405,               /* BIF_FLOAT  */
    BIF_SQRT = 406,                /* BIF_SQRT  */
    BIF_ALLOC = 407,               /* BIF_ALLOC  */
    BIF_REALLOC = 408,             /* BIF_REALLOC  */
    BIF_XFOOT = 409,               /* BIF_XFOOT  */
    BIF_SUBARR = 410,              /* BIF_SUBARR  */
    BIF_SPLIT = 411,               /* BIF_SPLIT  */
    BIF_UNS = 412,                 /* BIF_UNS  */
    BIF_INTH = 413,                /* BIF_INTH  */
    BIF_DECH = 414,                /* BIF_DECH  */
    BIF_DECPOS = 415,              /* BIF_DECPOS  */
    BIF_CONCAT = 416,              /* BIF_CONCAT  */
    BIF_CONCATARR = 417,           /* BIF_CONCATARR  */
    BIF_LEFT = 418,                /* BIF_LEFT  */
    BIF_RIGHT = 419,               /* BIF_RIGHT  */
    BIF_STR = 420,                 /* BIF_STR  */
    BIF_MAXARR = 421,              /* BIF_MAXARR  */
    BIF_MINARR = 422,              /* BIF_MINARR  */
    BIF_LIST = 423,                /* BIF_LIST  */
    BIF_RANGE = 424,               /* BIF_RANGE  */
    BIF_LOOKUPLT = 425,            /* BIF_LOOKUPLT  */
    BIF_LOOKUPGE = 426,            /* BIF_LOOKUPGE  */
    BIF_LOOKUPLE = 427,            /* BIF_LOOKUPLE  */
    BIF_LOOKUPGT = 428,            /* BIF_LOOKUPGT  */
    BIF_TLOOKUP = 429,             /* BIF_TLOOKUP  */
    BIF_TLOOKUPLT = 430,           /* BIF_TLOOKUPLT  */
    BIF_TLOOKUPGT = 431,           /* BIF_TLOOKUPGT  */
    BIF_TLOOKUPLE = 432,           /* BIF_TLOOKUPLE  */
    BIF_TLOOKUPGE = 433,           /* BIF_TLOOKUPGE  */
    BIF_HOURS = 434,               /* BIF_HOURS  */
    BIF_MINUTES = 435,             /* BIF_MINUTES  */
    BIF_SECONDS = 436,             /* BIF_SECONDS  */
    BIF_MSECONDS = 437,            /* BIF_MSECONDS  */
    BIF_PADDR = 438,               /* BIF_PADDR  */
    BIF_PROC = 439,                /* BIF_PROC  */
    BIF_PASSED = 440,              /* BIF_PASSED  */
    BIF_OMITTED = 441,             /* BIF_OMITTED  */
    BIF_BITAND = 442,              /* BIF_BITAND  */
    BIF_BITNOT = 443,              /* BIF_BITNOT  */
    BIF_BITOR = 444,               /* BIF_BITOR  */
    BIF_BITXOR = 445,              /* BIF_BITXOR  */
    BIF_SCANR = 446,               /* BIF_SCANR  */
    BIF_EDITFLT = 447,             /* BIF_EDITFLT  */
    BIF_UNSH = 448,                /* BIF_UNSH  */
    BIF_PARMNUM = 449,             /* BIF_PARMNUM  */
    BIF_GETENV = 450,              /* BIF_GETENV  */
    BIF_XML = 451,                 /* BIF_XML  */
    BIF_DATA = 452,                /* BIF_DATA  */
    BIF_PARSER = 453,              /* BIF_PARSER  */
    KW_ALL = 454,                  /* KW_ALL  */
    KW_UNS = 455,                  /* KW_UNS  */
    KW_FLOAT_TYPE = 456,           /* KW_FLOAT_TYPE  */
    KW_BINDEC = 457,               /* KW_BINDEC  */
    KW_UCS2 = 458,                 /* KW_UCS2  */
    KW_GRAPH = 459,                /* KW_GRAPH  */
    KW_OBJECT = 460,               /* KW_OBJECT  */
    KW_JAVA = 461,                 /* KW_JAVA  */
    KW_OVERLAY = 462,              /* KW_OVERLAY  */
    KW_POS = 463,                  /* KW_POS  */
    KW_PREFIX = 464,               /* KW_PREFIX  */
    KW_DATFMT = 465,               /* KW_DATFMT  */
    KW_TIMFMT = 466,               /* KW_TIMFMT  */
    KW_EXTNAME = 467,              /* KW_EXTNAME  */
    KW_PSDS = 468,                 /* KW_PSDS  */
    KW_SDS = 469,                  /* KW_SDS  */
    KW_DTAARA = 470,               /* KW_DTAARA  */
    KW_OUT = 471,                  /* KW_OUT  */
    KW_UNLOCK = 472,               /* KW_UNLOCK  */
    KW_RTNPARM = 473,              /* KW_RTNPARM  */
    KW_OPDESC = 474,               /* KW_OPDESC  */
    KW_ASCEND = 475,               /* KW_ASCEND  */
    KW_DESCEND = 476,              /* KW_DESCEND  */
    KW_NULLIND = 477,              /* KW_NULLIND  */
    KW_VARSIZE = 478,              /* KW_VARSIZE  */
    KW_STRING_OPT = 479,           /* KW_STRING_OPT  */
    KW_TRIM_OPT = 480,             /* KW_TRIM_OPT  */
    KW_DCL_ENUM = 481,             /* KW_DCL_ENUM  */
    KW_END_ENUM = 482,             /* KW_END_ENUM  */
    KW_BOOLEAN = 483,              /* KW_BOOLEAN  */
    EXEC_SQL_TEXT = 484,           /* EXEC_SQL_TEXT  */
    POWER = 485,                   /* POWER  */
    KW_DIM_VAR = 486,              /* KW_DIM_VAR  */
    KW_DIM_AUTO = 487,             /* KW_DIM_AUTO  */
    KW_FOR_EACH = 488,             /* KW_FOR_EACH  */
    KW_IN = 489,                   /* KW_IN  */
    KW_XML_INTO = 490,             /* KW_XML_INTO  */
    KW_DATA_INTO = 491,            /* KW_DATA_INTO  */
    KW_DATA_GEN = 492,             /* KW_DATA_GEN  */
    IDENTIFIER = 493,              /* IDENTIFIER  */
    INTEGER_LITERAL = 494,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 495,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 496,          /* STRING_LITERAL  */
    SEMICOLON = 497,               /* SEMICOLON  */
    EQUALS = 498,                  /* EQUALS  */
    LPAREN = 499,                  /* LPAREN  */
    RPAREN = 500,                  /* RPAREN  */
    COLON = 501,                   /* COLON  */
    PLUS = 502,                    /* PLUS  */
    MINUS = 503,                   /* MINUS  */
    STAR = 504,                    /* STAR  */
    SLASH = 505,                   /* SLASH  */
    NE = 506,                      /* NE  */
    LE = 507,                      /* LE  */
    GE = 508,                      /* GE  */
    LT = 509,                      /* LT  */
    GT = 510                       /* GT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "src/parser.y"

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
    std::vector<rpg::EnumConstant>* enum_const_list;

#line 370 "build/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_H_INCLUDED  */
