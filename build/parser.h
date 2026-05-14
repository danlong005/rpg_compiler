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
    KW_IF = 316,                   /* KW_IF  */
    KW_ELSEIF = 317,               /* KW_ELSEIF  */
    KW_ELSE = 318,                 /* KW_ELSE  */
    KW_ENDIF = 319,                /* KW_ENDIF  */
    KW_DOW = 320,                  /* KW_DOW  */
    KW_DOU = 321,                  /* KW_DOU  */
    KW_ENDDO = 322,                /* KW_ENDDO  */
    KW_FOR = 323,                  /* KW_FOR  */
    KW_ENDFOR = 324,               /* KW_ENDFOR  */
    KW_TO = 325,                   /* KW_TO  */
    KW_DOWNTO = 326,               /* KW_DOWNTO  */
    KW_BY = 327,                   /* KW_BY  */
    KW_SELECT = 328,               /* KW_SELECT  */
    KW_WHEN = 329,                 /* KW_WHEN  */
    KW_OTHER = 330,                /* KW_OTHER  */
    KW_ENDSL = 331,                /* KW_ENDSL  */
    KW_ITER = 332,                 /* KW_ITER  */
    KW_LEAVE = 333,                /* KW_LEAVE  */
    KW_MONITOR = 334,              /* KW_MONITOR  */
    KW_ON_ERROR = 335,             /* KW_ON_ERROR  */
    KW_ENDMON = 336,               /* KW_ENDMON  */
    KW_BEGSR = 337,                /* KW_BEGSR  */
    KW_ENDSR = 338,                /* KW_ENDSR  */
    KW_EXSR = 339,                 /* KW_EXSR  */
    KW_OFF = 340,                  /* KW_OFF  */
    KW_RESET = 341,                /* KW_RESET  */
    KW_CLEAR = 342,                /* KW_CLEAR  */
    KW_SORTA = 343,                /* KW_SORTA  */
    INDICATOR = 344,               /* INDICATOR  */
    KW_AND = 345,                  /* KW_AND  */
    KW_OR = 346,                   /* KW_OR  */
    KW_NOT = 347,                  /* KW_NOT  */
    KW_DCL_PROC = 348,             /* KW_DCL_PROC  */
    KW_END_PROC = 349,             /* KW_END_PROC  */
    KW_DCL_PI = 350,               /* KW_DCL_PI  */
    KW_END_PI = 351,               /* KW_END_PI  */
    KW_DCL_PR = 352,               /* KW_DCL_PR  */
    KW_END_PR = 353,               /* KW_END_PR  */
    KW_VALUE = 354,                /* KW_VALUE  */
    KW_DCL_DS = 355,               /* KW_DCL_DS  */
    KW_END_DS = 356,               /* KW_END_DS  */
    KW_QUALIFIED = 357,            /* KW_QUALIFIED  */
    KW_DIM = 358,                  /* KW_DIM  */
    KW_LIKEDS = 359,               /* KW_LIKEDS  */
    KW_LIKE = 360,                 /* KW_LIKE  */
    KW_DCL_SUBF = 361,             /* KW_DCL_SUBF  */
    KW_DCL_PARM = 362,             /* KW_DCL_PARM  */
    DOT = 363,                     /* DOT  */
    BIF_CHAR = 364,                /* BIF_CHAR  */
    BIF_TRIM = 365,                /* BIF_TRIM  */
    BIF_TRIML = 366,               /* BIF_TRIML  */
    BIF_TRIMR = 367,               /* BIF_TRIMR  */
    BIF_LEN = 368,                 /* BIF_LEN  */
    BIF_SUBST = 369,               /* BIF_SUBST  */
    BIF_SCAN = 370,                /* BIF_SCAN  */
    BIF_SCANRPL = 371,             /* BIF_SCANRPL  */
    BIF_XLATE = 372,               /* BIF_XLATE  */
    BIF_DEC = 373,                 /* BIF_DEC  */
    BIF_INT = 374,                 /* BIF_INT  */
    BIF_ELEM = 375,                /* BIF_ELEM  */
    BIF_FOUND = 376,               /* BIF_FOUND  */
    BIF_EOF = 377,                 /* BIF_EOF  */
    BIF_ABS = 378,                 /* BIF_ABS  */
    BIF_DIV = 379,                 /* BIF_DIV  */
    BIF_REM = 380,                 /* BIF_REM  */
    BIF_SIZE = 381,                /* BIF_SIZE  */
    BIF_ADDR = 382,                /* BIF_ADDR  */
    BIF_PARMS = 383,               /* BIF_PARMS  */
    BIF_STATUS = 384,              /* BIF_STATUS  */
    BIF_ERROR = 385,               /* BIF_ERROR  */
    BIF_MAX = 386,                 /* BIF_MAX  */
    BIF_MIN = 387,                 /* BIF_MIN  */
    BIF_LOOKUP = 388,              /* BIF_LOOKUP  */
    BIF_DATE = 389,                /* BIF_DATE  */
    BIF_TIME = 390,                /* BIF_TIME  */
    BIF_TIMESTAMP = 391,           /* BIF_TIMESTAMP  */
    BIF_DIFF = 392,                /* BIF_DIFF  */
    BIF_DAYS = 393,                /* BIF_DAYS  */
    BIF_MONTHS = 394,              /* BIF_MONTHS  */
    BIF_YEARS = 395,               /* BIF_YEARS  */
    BIF_EDITC = 396,               /* BIF_EDITC  */
    BIF_EDITW = 397,               /* BIF_EDITW  */
    BIF_REPLACE = 398,             /* BIF_REPLACE  */
    BIF_CHECK = 399,               /* BIF_CHECK  */
    BIF_CHECKR = 400,              /* BIF_CHECKR  */
    BIF_LOWER = 401,               /* BIF_LOWER  */
    BIF_UPPER = 402,               /* BIF_UPPER  */
    BIF_SUBDT = 403,               /* BIF_SUBDT  */
    BIF_FLOAT = 404,               /* BIF_FLOAT  */
    BIF_SQRT = 405,                /* BIF_SQRT  */
    BIF_ALLOC = 406,               /* BIF_ALLOC  */
    BIF_REALLOC = 407,             /* BIF_REALLOC  */
    BIF_XFOOT = 408,               /* BIF_XFOOT  */
    BIF_SUBARR = 409,              /* BIF_SUBARR  */
    BIF_SPLIT = 410,               /* BIF_SPLIT  */
    BIF_UNS = 411,                 /* BIF_UNS  */
    BIF_INTH = 412,                /* BIF_INTH  */
    BIF_DECH = 413,                /* BIF_DECH  */
    BIF_DECPOS = 414,              /* BIF_DECPOS  */
    BIF_CONCAT = 415,              /* BIF_CONCAT  */
    BIF_CONCATARR = 416,           /* BIF_CONCATARR  */
    BIF_LEFT = 417,                /* BIF_LEFT  */
    BIF_RIGHT = 418,               /* BIF_RIGHT  */
    BIF_STR = 419,                 /* BIF_STR  */
    BIF_MAXARR = 420,              /* BIF_MAXARR  */
    BIF_MINARR = 421,              /* BIF_MINARR  */
    BIF_LIST = 422,                /* BIF_LIST  */
    BIF_RANGE = 423,               /* BIF_RANGE  */
    BIF_LOOKUPLT = 424,            /* BIF_LOOKUPLT  */
    BIF_LOOKUPGE = 425,            /* BIF_LOOKUPGE  */
    BIF_LOOKUPLE = 426,            /* BIF_LOOKUPLE  */
    BIF_LOOKUPGT = 427,            /* BIF_LOOKUPGT  */
    BIF_TLOOKUP = 428,             /* BIF_TLOOKUP  */
    BIF_TLOOKUPLT = 429,           /* BIF_TLOOKUPLT  */
    BIF_TLOOKUPGT = 430,           /* BIF_TLOOKUPGT  */
    BIF_TLOOKUPLE = 431,           /* BIF_TLOOKUPLE  */
    BIF_TLOOKUPGE = 432,           /* BIF_TLOOKUPGE  */
    BIF_HOURS = 433,               /* BIF_HOURS  */
    BIF_MINUTES = 434,             /* BIF_MINUTES  */
    BIF_SECONDS = 435,             /* BIF_SECONDS  */
    BIF_MSECONDS = 436,            /* BIF_MSECONDS  */
    BIF_PADDR = 437,               /* BIF_PADDR  */
    BIF_PROC = 438,                /* BIF_PROC  */
    BIF_PASSED = 439,              /* BIF_PASSED  */
    BIF_OMITTED = 440,             /* BIF_OMITTED  */
    BIF_BITAND = 441,              /* BIF_BITAND  */
    BIF_BITNOT = 442,              /* BIF_BITNOT  */
    BIF_BITOR = 443,               /* BIF_BITOR  */
    BIF_BITXOR = 444,              /* BIF_BITXOR  */
    BIF_SCANR = 445,               /* BIF_SCANR  */
    BIF_EDITFLT = 446,             /* BIF_EDITFLT  */
    BIF_UNSH = 447,                /* BIF_UNSH  */
    BIF_PARMNUM = 448,             /* BIF_PARMNUM  */
    BIF_GETENV = 449,              /* BIF_GETENV  */
    BIF_XML = 450,                 /* BIF_XML  */
    BIF_DATA = 451,                /* BIF_DATA  */
    BIF_PARSER = 452,              /* BIF_PARSER  */
    KW_ALL = 453,                  /* KW_ALL  */
    KW_UNS = 454,                  /* KW_UNS  */
    KW_FLOAT_TYPE = 455,           /* KW_FLOAT_TYPE  */
    KW_BINDEC = 456,               /* KW_BINDEC  */
    KW_UCS2 = 457,                 /* KW_UCS2  */
    KW_GRAPH = 458,                /* KW_GRAPH  */
    KW_OBJECT = 459,               /* KW_OBJECT  */
    KW_JAVA = 460,                 /* KW_JAVA  */
    KW_OVERLAY = 461,              /* KW_OVERLAY  */
    KW_POS = 462,                  /* KW_POS  */
    KW_PREFIX = 463,               /* KW_PREFIX  */
    KW_DATFMT = 464,               /* KW_DATFMT  */
    KW_TIMFMT = 465,               /* KW_TIMFMT  */
    KW_EXTNAME = 466,              /* KW_EXTNAME  */
    KW_PSDS = 467,                 /* KW_PSDS  */
    KW_SDS = 468,                  /* KW_SDS  */
    KW_DTAARA = 469,               /* KW_DTAARA  */
    KW_OUT = 470,                  /* KW_OUT  */
    KW_UNLOCK = 471,               /* KW_UNLOCK  */
    KW_RTNPARM = 472,              /* KW_RTNPARM  */
    KW_OPDESC = 473,               /* KW_OPDESC  */
    KW_ASCEND = 474,               /* KW_ASCEND  */
    KW_DESCEND = 475,              /* KW_DESCEND  */
    KW_NULLIND = 476,              /* KW_NULLIND  */
    KW_VARSIZE = 477,              /* KW_VARSIZE  */
    KW_STRING_OPT = 478,           /* KW_STRING_OPT  */
    KW_TRIM_OPT = 479,             /* KW_TRIM_OPT  */
    KW_DCL_ENUM = 480,             /* KW_DCL_ENUM  */
    KW_END_ENUM = 481,             /* KW_END_ENUM  */
    KW_BOOLEAN = 482,              /* KW_BOOLEAN  */
    EXEC_SQL_TEXT = 483,           /* EXEC_SQL_TEXT  */
    POWER = 484,                   /* POWER  */
    KW_DIM_VAR = 485,              /* KW_DIM_VAR  */
    KW_DIM_AUTO = 486,             /* KW_DIM_AUTO  */
    KW_FOR_EACH = 487,             /* KW_FOR_EACH  */
    KW_IN = 488,                   /* KW_IN  */
    KW_XML_INTO = 489,             /* KW_XML_INTO  */
    KW_DATA_INTO = 490,            /* KW_DATA_INTO  */
    KW_DATA_GEN = 491,             /* KW_DATA_GEN  */
    IDENTIFIER = 492,              /* IDENTIFIER  */
    INTEGER_LITERAL = 493,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 494,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 495,          /* STRING_LITERAL  */
    SEMICOLON = 496,               /* SEMICOLON  */
    EQUALS = 497,                  /* EQUALS  */
    LPAREN = 498,                  /* LPAREN  */
    RPAREN = 499,                  /* RPAREN  */
    COLON = 500,                   /* COLON  */
    PLUS = 501,                    /* PLUS  */
    MINUS = 502,                   /* MINUS  */
    STAR = 503,                    /* STAR  */
    SLASH = 504,                   /* SLASH  */
    NE = 505,                      /* NE  */
    LE = 506,                      /* LE  */
    GE = 507,                      /* GE  */
    LT = 508,                      /* LT  */
    GT = 509                       /* GT  */
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

#line 369 "build/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_H_INCLUDED  */
