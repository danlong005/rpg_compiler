/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 30 "src/parser.y"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>
#include <string>
#include "ast.h"
#include "sql_utils.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

static rpg::Program* g_program = nullptr;
static int g_error_count = 0;

rpg::Program* get_parsed_program();
int get_parse_error_count();

// CTL-OPT values extracted by lexer
extern char ctlopt_main_proc[256];
extern char ctlopt_datfmt[64];
extern char ctlopt_timfmt[64];
extern bool ctlopt_nomain;

// Set line number on AST node
#define SET_LINE(node) do { if (node) (node)->line = yylineno; } while(0)

static rpg::BIFCall* make_bif(const char* name, std::vector<rpg::Expression*>* raw_args) {
    std::vector<std::unique_ptr<rpg::Expression>> args;
    for (auto* e : *raw_args) {
        args.emplace_back(e);
    }
    delete raw_args;
    return new rpg::BIFCall(name, std::move(args));
}

static rpg::FuncCall* make_func(const char* name, std::vector<rpg::Expression*>* raw_args) {
    std::vector<std::unique_ptr<rpg::Expression>> args;
    if (raw_args) {
        for (auto* e : *raw_args) {
            args.emplace_back(e);
        }
        delete raw_args;
    }
    return new rpg::FuncCall(name, std::move(args));
}

#line 122 "build/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_FREE = 3,                    /* KW_FREE  */
  YYSYMBOL_KW_DCL_F = 4,                   /* KW_DCL_F  */
  YYSYMBOL_KW_DCL_S = 5,                   /* KW_DCL_S  */
  YYSYMBOL_KW_DCL_C = 6,                   /* KW_DCL_C  */
  YYSYMBOL_KW_DISK = 7,                    /* KW_DISK  */
  YYSYMBOL_KW_PRINTER = 8,                 /* KW_PRINTER  */
  YYSYMBOL_KW_WORKSTN = 9,                 /* KW_WORKSTN  */
  YYSYMBOL_KW_USAGE = 10,                  /* KW_USAGE  */
  YYSYMBOL_KW_CHAR = 11,                   /* KW_CHAR  */
  YYSYMBOL_KW_VARCHAR = 12,                /* KW_VARCHAR  */
  YYSYMBOL_KW_INT = 13,                    /* KW_INT  */
  YYSYMBOL_KW_PACKED = 14,                 /* KW_PACKED  */
  YYSYMBOL_KW_ZONED = 15,                  /* KW_ZONED  */
  YYSYMBOL_KW_DATE = 16,                   /* KW_DATE  */
  YYSYMBOL_KW_TIME = 17,                   /* KW_TIME  */
  YYSYMBOL_KW_TIMESTAMP = 18,              /* KW_TIMESTAMP  */
  YYSYMBOL_KW_IND = 19,                    /* KW_IND  */
  YYSYMBOL_KW_POINTER = 20,                /* KW_POINTER  */
  YYSYMBOL_KW_NULL = 21,                   /* KW_NULL  */
  YYSYMBOL_KW_DAYS = 22,                   /* KW_DAYS  */
  YYSYMBOL_KW_MONTHS = 23,                 /* KW_MONTHS  */
  YYSYMBOL_KW_YEARS = 24,                  /* KW_YEARS  */
  YYSYMBOL_KW_HOURS = 25,                  /* KW_HOURS  */
  YYSYMBOL_KW_MINUTES = 26,                /* KW_MINUTES  */
  YYSYMBOL_KW_SECONDS = 27,                /* KW_SECONDS  */
  YYSYMBOL_KW_MSECONDS = 28,               /* KW_MSECONDS  */
  YYSYMBOL_KW_CONST = 29,                  /* KW_CONST  */
  YYSYMBOL_KW_INZ = 30,                    /* KW_INZ  */
  YYSYMBOL_KW_DSPLY = 31,                  /* KW_DSPLY  */
  YYSYMBOL_KW_EVAL = 32,                   /* KW_EVAL  */
  YYSYMBOL_KW_EVAL_CORR = 33,              /* KW_EVAL_CORR  */
  YYSYMBOL_KW_EVALR = 34,                  /* KW_EVALR  */
  YYSYMBOL_KW_CALLP = 35,                  /* KW_CALLP  */
  YYSYMBOL_KW_LEAVESR = 36,                /* KW_LEAVESR  */
  YYSYMBOL_KW_ON_EXIT = 37,                /* KW_ON_EXIT  */
  YYSYMBOL_KW_DEALLOC = 38,                /* KW_DEALLOC  */
  YYSYMBOL_KW_TEST = 39,                   /* KW_TEST  */
  YYSYMBOL_KW_EVAL_EXT = 40,               /* KW_EVAL_EXT  */
  YYSYMBOL_KW_EVALR_EXT = 41,              /* KW_EVALR_EXT  */
  YYSYMBOL_KW_CALLP_EXT = 42,              /* KW_CALLP_EXT  */
  YYSYMBOL_KW_STATIC = 43,                 /* KW_STATIC  */
  YYSYMBOL_KW_TEMPLATE = 44,               /* KW_TEMPLATE  */
  YYSYMBOL_KW_BASED = 45,                  /* KW_BASED  */
  YYSYMBOL_KW_OPTIONS = 46,                /* KW_OPTIONS  */
  YYSYMBOL_KW_NOPASS = 47,                 /* KW_NOPASS  */
  YYSYMBOL_KW_OMIT = 48,                   /* KW_OMIT  */
  YYSYMBOL_KW_EXPORT = 49,                 /* KW_EXPORT  */
  YYSYMBOL_KW_IMPORT = 50,                 /* KW_IMPORT  */
  YYSYMBOL_KW_EXTPGM = 51,                 /* KW_EXTPGM  */
  YYSYMBOL_KW_EXTPROC = 52,                /* KW_EXTPROC  */
  YYSYMBOL_KW_CTLOPT = 53,                 /* KW_CTLOPT  */
  YYSYMBOL_KW_RETURN = 54,                 /* KW_RETURN  */
  YYSYMBOL_KW_INLR = 55,                   /* KW_INLR  */
  YYSYMBOL_KW_ON = 56,                     /* KW_ON  */
  YYSYMBOL_KW_BLANKS = 57,                 /* KW_BLANKS  */
  YYSYMBOL_KW_ZEROS = 58,                  /* KW_ZEROS  */
  YYSYMBOL_KW_HIVAL = 59,                  /* KW_HIVAL  */
  YYSYMBOL_KW_LOVAL = 60,                  /* KW_LOVAL  */
  YYSYMBOL_KW_USER = 61,                   /* KW_USER  */
  YYSYMBOL_KW_IF = 62,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 63,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 64,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 65,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 66,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 67,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 68,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 69,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 70,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 71,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 72,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 73,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 74,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 75,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 76,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 77,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 78,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 79,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 80,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 81,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 82,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 83,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 84,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 85,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 86,                    /* KW_OFF  */
  YYSYMBOL_KW_RESET = 87,                  /* KW_RESET  */
  YYSYMBOL_KW_CLEAR = 88,                  /* KW_CLEAR  */
  YYSYMBOL_KW_SORTA = 89,                  /* KW_SORTA  */
  YYSYMBOL_INDICATOR = 90,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 91,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 92,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 93,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 94,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 95,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 96,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 97,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 98,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 99,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 100,                 /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 101,                /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 102,                /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 103,             /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 104,                   /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 105,                /* KW_LIKEDS  */
  YYSYMBOL_KW_LIKE = 106,                  /* KW_LIKE  */
  YYSYMBOL_KW_DCL_SUBF = 107,              /* KW_DCL_SUBF  */
  YYSYMBOL_KW_DCL_PARM = 108,              /* KW_DCL_PARM  */
  YYSYMBOL_DOT = 109,                      /* DOT  */
  YYSYMBOL_BIF_CHAR = 110,                 /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 111,                 /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 112,                /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 113,                /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 114,                  /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 115,                /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 116,                 /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 117,              /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 118,                /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 119,                  /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 120,                  /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 121,                 /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 122,                /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 123,                  /* BIF_EOF  */
  YYSYMBOL_BIF_ABS = 124,                  /* BIF_ABS  */
  YYSYMBOL_BIF_DIV = 125,                  /* BIF_DIV  */
  YYSYMBOL_BIF_REM = 126,                  /* BIF_REM  */
  YYSYMBOL_BIF_SIZE = 127,                 /* BIF_SIZE  */
  YYSYMBOL_BIF_ADDR = 128,                 /* BIF_ADDR  */
  YYSYMBOL_BIF_PARMS = 129,                /* BIF_PARMS  */
  YYSYMBOL_BIF_STATUS = 130,               /* BIF_STATUS  */
  YYSYMBOL_BIF_ERROR = 131,                /* BIF_ERROR  */
  YYSYMBOL_BIF_MAX = 132,                  /* BIF_MAX  */
  YYSYMBOL_BIF_MIN = 133,                  /* BIF_MIN  */
  YYSYMBOL_BIF_LOOKUP = 134,               /* BIF_LOOKUP  */
  YYSYMBOL_BIF_DATE = 135,                 /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 136,                 /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 137,            /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 138,                 /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 139,                 /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 140,               /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 141,                /* BIF_YEARS  */
  YYSYMBOL_BIF_EDITC = 142,                /* BIF_EDITC  */
  YYSYMBOL_BIF_EDITW = 143,                /* BIF_EDITW  */
  YYSYMBOL_BIF_REPLACE = 144,              /* BIF_REPLACE  */
  YYSYMBOL_BIF_CHECK = 145,                /* BIF_CHECK  */
  YYSYMBOL_BIF_CHECKR = 146,               /* BIF_CHECKR  */
  YYSYMBOL_BIF_LOWER = 147,                /* BIF_LOWER  */
  YYSYMBOL_BIF_UPPER = 148,                /* BIF_UPPER  */
  YYSYMBOL_BIF_SUBDT = 149,                /* BIF_SUBDT  */
  YYSYMBOL_BIF_FLOAT = 150,                /* BIF_FLOAT  */
  YYSYMBOL_BIF_SQRT = 151,                 /* BIF_SQRT  */
  YYSYMBOL_BIF_ALLOC = 152,                /* BIF_ALLOC  */
  YYSYMBOL_BIF_REALLOC = 153,              /* BIF_REALLOC  */
  YYSYMBOL_BIF_XFOOT = 154,                /* BIF_XFOOT  */
  YYSYMBOL_BIF_SUBARR = 155,               /* BIF_SUBARR  */
  YYSYMBOL_BIF_SPLIT = 156,                /* BIF_SPLIT  */
  YYSYMBOL_BIF_UNS = 157,                  /* BIF_UNS  */
  YYSYMBOL_BIF_INTH = 158,                 /* BIF_INTH  */
  YYSYMBOL_BIF_DECH = 159,                 /* BIF_DECH  */
  YYSYMBOL_BIF_DECPOS = 160,               /* BIF_DECPOS  */
  YYSYMBOL_BIF_CONCAT = 161,               /* BIF_CONCAT  */
  YYSYMBOL_BIF_CONCATARR = 162,            /* BIF_CONCATARR  */
  YYSYMBOL_BIF_LEFT = 163,                 /* BIF_LEFT  */
  YYSYMBOL_BIF_RIGHT = 164,                /* BIF_RIGHT  */
  YYSYMBOL_BIF_STR = 165,                  /* BIF_STR  */
  YYSYMBOL_BIF_MAXARR = 166,               /* BIF_MAXARR  */
  YYSYMBOL_BIF_MINARR = 167,               /* BIF_MINARR  */
  YYSYMBOL_BIF_LIST = 168,                 /* BIF_LIST  */
  YYSYMBOL_BIF_RANGE = 169,                /* BIF_RANGE  */
  YYSYMBOL_BIF_LOOKUPLT = 170,             /* BIF_LOOKUPLT  */
  YYSYMBOL_BIF_LOOKUPGE = 171,             /* BIF_LOOKUPGE  */
  YYSYMBOL_BIF_LOOKUPLE = 172,             /* BIF_LOOKUPLE  */
  YYSYMBOL_BIF_LOOKUPGT = 173,             /* BIF_LOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUP = 174,              /* BIF_TLOOKUP  */
  YYSYMBOL_BIF_TLOOKUPLT = 175,            /* BIF_TLOOKUPLT  */
  YYSYMBOL_BIF_TLOOKUPGT = 176,            /* BIF_TLOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUPLE = 177,            /* BIF_TLOOKUPLE  */
  YYSYMBOL_BIF_TLOOKUPGE = 178,            /* BIF_TLOOKUPGE  */
  YYSYMBOL_BIF_HOURS = 179,                /* BIF_HOURS  */
  YYSYMBOL_BIF_MINUTES = 180,              /* BIF_MINUTES  */
  YYSYMBOL_BIF_SECONDS = 181,              /* BIF_SECONDS  */
  YYSYMBOL_BIF_MSECONDS = 182,             /* BIF_MSECONDS  */
  YYSYMBOL_BIF_PADDR = 183,                /* BIF_PADDR  */
  YYSYMBOL_BIF_PROC = 184,                 /* BIF_PROC  */
  YYSYMBOL_BIF_PASSED = 185,               /* BIF_PASSED  */
  YYSYMBOL_BIF_OMITTED = 186,              /* BIF_OMITTED  */
  YYSYMBOL_BIF_BITAND = 187,               /* BIF_BITAND  */
  YYSYMBOL_BIF_BITNOT = 188,               /* BIF_BITNOT  */
  YYSYMBOL_BIF_BITOR = 189,                /* BIF_BITOR  */
  YYSYMBOL_BIF_BITXOR = 190,               /* BIF_BITXOR  */
  YYSYMBOL_BIF_SCANR = 191,                /* BIF_SCANR  */
  YYSYMBOL_BIF_EDITFLT = 192,              /* BIF_EDITFLT  */
  YYSYMBOL_BIF_UNSH = 193,                 /* BIF_UNSH  */
  YYSYMBOL_BIF_PARMNUM = 194,              /* BIF_PARMNUM  */
  YYSYMBOL_BIF_GETENV = 195,               /* BIF_GETENV  */
  YYSYMBOL_BIF_XML = 196,                  /* BIF_XML  */
  YYSYMBOL_BIF_DATA = 197,                 /* BIF_DATA  */
  YYSYMBOL_BIF_PARSER = 198,               /* BIF_PARSER  */
  YYSYMBOL_KW_ALL = 199,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 200,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 201,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 202,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 203,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 204,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 205,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 206,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 207,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 208,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 209,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 210,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 211,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 212,               /* KW_EXTNAME  */
  YYSYMBOL_KW_PSDS = 213,                  /* KW_PSDS  */
  YYSYMBOL_KW_SDS = 214,                   /* KW_SDS  */
  YYSYMBOL_KW_DTAARA = 215,                /* KW_DTAARA  */
  YYSYMBOL_KW_OUT = 216,                   /* KW_OUT  */
  YYSYMBOL_KW_UNLOCK = 217,                /* KW_UNLOCK  */
  YYSYMBOL_KW_RTNPARM = 218,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 219,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 220,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 221,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 222,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 223,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 224,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 225,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 226,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 227,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 228,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 229,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 230,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 231,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 232,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 233,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 234,                    /* KW_IN  */
  YYSYMBOL_KW_XML_INTO = 235,              /* KW_XML_INTO  */
  YYSYMBOL_KW_DATA_INTO = 236,             /* KW_DATA_INTO  */
  YYSYMBOL_KW_DATA_GEN = 237,              /* KW_DATA_GEN  */
  YYSYMBOL_KW_SND_MSG = 238,               /* KW_SND_MSG  */
  YYSYMBOL_KW_STAR_INFO = 239,             /* KW_STAR_INFO  */
  YYSYMBOL_KW_STAR_DIAG = 240,             /* KW_STAR_DIAG  */
  YYSYMBOL_KW_STAR_ESCAPE = 241,           /* KW_STAR_ESCAPE  */
  YYSYMBOL_KW_TYPE = 242,                  /* KW_TYPE  */
  YYSYMBOL_IDENTIFIER = 243,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 244,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 245,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 246,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 247,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 248,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 249,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 250,                   /* RPAREN  */
  YYSYMBOL_COLON = 251,                    /* COLON  */
  YYSYMBOL_PLUS = 252,                     /* PLUS  */
  YYSYMBOL_MINUS = 253,                    /* MINUS  */
  YYSYMBOL_STAR = 254,                     /* STAR  */
  YYSYMBOL_SLASH = 255,                    /* SLASH  */
  YYSYMBOL_NE = 256,                       /* NE  */
  YYSYMBOL_LE = 257,                       /* LE  */
  YYSYMBOL_GE = 258,                       /* GE  */
  YYSYMBOL_LT = 259,                       /* LT  */
  YYSYMBOL_GT = 260,                       /* GT  */
  YYSYMBOL_YYACCEPT = 261,                 /* $accept  */
  YYSYMBOL_program = 262,                  /* program  */
  YYSYMBOL_statements_opt = 263,           /* statements_opt  */
  YYSYMBOL_statement_list = 264,           /* statement_list  */
  YYSYMBOL_statement = 265,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 266,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 267,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 268,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 269,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 270,              /* eval_target  */
  YYSYMBOL_eval_stmt = 271,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 272,           /* eval_corr_stmt  */
  YYSYMBOL_xml_into_stmt = 273,            /* xml_into_stmt  */
  YYSYMBOL_data_into_stmt = 274,           /* data_into_stmt  */
  YYSYMBOL_data_gen_stmt = 275,            /* data_gen_stmt  */
  YYSYMBOL_snd_msg_stmt = 276,             /* snd_msg_stmt  */
  YYSYMBOL_in_da_stmt = 277,               /* in_da_stmt  */
  YYSYMBOL_out_da_stmt = 278,              /* out_da_stmt  */
  YYSYMBOL_unlock_da_stmt = 279,           /* unlock_da_stmt  */
  YYSYMBOL_evalr_stmt = 280,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 281,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 282,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 283,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 284,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 285,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 286,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 287,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 288,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 289,              /* proc_export  */
  YYSYMBOL_pi_return_type = 290,           /* pi_return_type  */
  YYSYMBOL_pi_params = 291,                /* pi_params  */
  YYSYMBOL_pi_param = 292,                 /* pi_param  */
  YYSYMBOL_pr_params = 293,                /* pr_params  */
  YYSYMBOL_pr_param = 294,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 295,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 296,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 297,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 298,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 299,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 300,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 301,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 302,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 303,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 304,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 305,           /* enum_constants  */
  YYSYMBOL_enum_constant = 306,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 307,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 308,                /* ds_fields  */
  YYSYMBOL_psds_kw = 309,                  /* psds_kw  */
  YYSYMBOL_ds_field = 310,                 /* ds_field  */
  YYSYMBOL_if_stmt = 311,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 312,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 313,            /* elseif_clause  */
  YYSYMBOL_else_clause = 314,              /* else_clause  */
  YYSYMBOL_dow_stmt = 315,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 316,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 317,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 318,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 319,              /* select_stmt  */
  YYSYMBOL_when_clauses = 320,             /* when_clauses  */
  YYSYMBOL_when_clause = 321,              /* when_clause  */
  YYSYMBOL_other_clause = 322,             /* other_clause  */
  YYSYMBOL_iter_stmt = 323,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 324,               /* leave_stmt  */
  YYSYMBOL_expression = 325,               /* expression  */
  YYSYMBOL_or_expr = 326,                  /* or_expr  */
  YYSYMBOL_and_expr = 327,                 /* and_expr  */
  YYSYMBOL_not_expr = 328,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 329,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 330,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 331,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 332,               /* power_expr  */
  YYSYMBOL_unary_expr = 333,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 334,             /* postfix_expr  */
  YYSYMBOL_ident = 335,                    /* ident  */
  YYSYMBOL_primary_expr = 336,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 337,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 338,            /* call_arg_list  */
  YYSYMBOL_arg_list = 339                  /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  489
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1611

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   515


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   199,   199,   202,   207,   209,   214,   223,   226,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     280,   284,   288,   292,   300,   305,   310,   315,   320,   325,
     330,   335,   340,   345,   350,   355,   361,   367,   373,   377,
     381,   385,   389,   393,   397,   401,   405,   409,   413,   419,
     425,   431,   437,   444,   449,   455,   460,   465,   470,   475,
     480,   485,   490,   495,   500,   505,   510,   515,   520,   525,
     530,   538,   539,   540,   541,   542,   547,   554,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   575,   581,   585,   591,   597,   603,   609,
     620,   628,   634,   643,   650,   657,   664,   673,   680,   687,
     694,   703,   706,   709,   712,   715,   718,   721,   727,   734,
     741,   748,   754,   765,   768,   775,   781,   787,   793,   796,
     803,   814,   831,   851,   866,   890,   915,   942,   972,   973,
     978,   979,   980,   981,   982,   987,   990,   998,  1002,  1006,
    1010,  1014,  1018,  1022,  1026,  1031,  1035,  1039,  1043,  1047,
    1051,  1055,  1059,  1063,  1069,  1074,  1079,  1084,  1090,  1095,
    1100,  1105,  1111,  1116,  1121,  1130,  1133,  1141,  1145,  1149,
    1153,  1157,  1161,  1165,  1169,  1174,  1178,  1182,  1186,  1190,
    1194,  1198,  1202,  1206,  1212,  1217,  1222,  1227,  1233,  1238,
    1243,  1248,  1254,  1259,  1264,  1274,  1285,  1295,  1303,  1311,
    1318,  1326,  1334,  1345,  1355,  1363,  1374,  1377,  1385,  1393,
    1408,  1417,  1426,  1436,  1446,  1457,  1468,  1479,  1490,  1498,
    1507,  1517,  1528,  1539,  1549,  1559,  1569,  1579,  1589,  1592,
    1600,  1601,  1605,  1609,  1613,  1617,  1622,  1626,  1630,  1634,
    1639,  1645,  1651,  1658,  1665,  1672,  1678,  1686,  1692,  1703,
    1726,  1727,  1735,  1744,  1745,  1751,  1760,  1769,  1779,  1789,
    1799,  1812,  1822,  1841,  1845,  1852,  1861,  1862,  1868,  1872,
    1878,  1882,  1883,  1891,  1892,  1900,  1901,  1907,  1908,  1913,
    1918,  1923,  1928,  1933,  1938,  1946,  1947,  1952,  1960,  1961,
    1966,  1974,  1975,  1983,  1984,  1992,  1993,  2000,  2001,  2002,
    2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,  2012,
    2013,  2014,  2015,  2019,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,  2040,
    2043,  2047,  2051,  2054,  2057,  2060,  2063,  2066,  2069,  2072,
    2075,  2078,  2081,  2084,  2087,  2091,  2094,  2097,  2100,  2103,
    2106,  2109,  2112,  2115,  2121,  2127,  2133,  2139,  2145,  2151,
    2154,  2157,  2160,  2163,  2167,  2171,  2174,  2177,  2180,  2183,
    2186,  2189,  2193,  2196,  2200,  2203,  2207,  2214,  2221,  2228,
    2233,  2238,  2243,  2247,  2251,  2254,  2257,  2260,  2263,  2266,
    2269,  2272,  2275,  2278,  2281,  2284,  2287,  2290,  2293,  2296,
    2299,  2302,  2305,  2308,  2311,  2314,  2317,  2320,  2323,  2326,
    2329,  2332,  2337,  2342,  2347,  2352,  2358,  2362,  2366,  2373,
    2380,  2387,  2393,  2399,  2405,  2408,  2411,  2414,  2417,  2420,
    2423,  2426,  2432,  2435,  2438,  2441,  2444,  2447,  2450,  2454,
    2457,  2460,  2463,  2466,  2473,  2474,  2478,  2482,  2490,  2494
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_FREE", "KW_DCL_F",
  "KW_DCL_S", "KW_DCL_C", "KW_DISK", "KW_PRINTER", "KW_WORKSTN",
  "KW_USAGE", "KW_CHAR", "KW_VARCHAR", "KW_INT", "KW_PACKED", "KW_ZONED",
  "KW_DATE", "KW_TIME", "KW_TIMESTAMP", "KW_IND", "KW_POINTER", "KW_NULL",
  "KW_DAYS", "KW_MONTHS", "KW_YEARS", "KW_HOURS", "KW_MINUTES",
  "KW_SECONDS", "KW_MSECONDS", "KW_CONST", "KW_INZ", "KW_DSPLY", "KW_EVAL",
  "KW_EVAL_CORR", "KW_EVALR", "KW_CALLP", "KW_LEAVESR", "KW_ON_EXIT",
  "KW_DEALLOC", "KW_TEST", "KW_EVAL_EXT", "KW_EVALR_EXT", "KW_CALLP_EXT",
  "KW_STATIC", "KW_TEMPLATE", "KW_BASED", "KW_OPTIONS", "KW_NOPASS",
  "KW_OMIT", "KW_EXPORT", "KW_IMPORT", "KW_EXTPGM", "KW_EXTPROC",
  "KW_CTLOPT", "KW_RETURN", "KW_INLR", "KW_ON", "KW_BLANKS", "KW_ZEROS",
  "KW_HIVAL", "KW_LOVAL", "KW_USER", "KW_IF", "KW_ELSEIF", "KW_ELSE",
  "KW_ENDIF", "KW_DOW", "KW_DOU", "KW_ENDDO", "KW_FOR", "KW_ENDFOR",
  "KW_TO", "KW_DOWNTO", "KW_BY", "KW_SELECT", "KW_WHEN", "KW_OTHER",
  "KW_ENDSL", "KW_ITER", "KW_LEAVE", "KW_MONITOR", "KW_ON_ERROR",
  "KW_ENDMON", "KW_BEGSR", "KW_ENDSR", "KW_EXSR", "KW_OFF", "KW_RESET",
  "KW_CLEAR", "KW_SORTA", "INDICATOR", "KW_AND", "KW_OR", "KW_NOT",
  "KW_DCL_PROC", "KW_END_PROC", "KW_DCL_PI", "KW_END_PI", "KW_DCL_PR",
  "KW_END_PR", "KW_VALUE", "KW_DCL_DS", "KW_END_DS", "KW_QUALIFIED",
  "KW_DIM", "KW_LIKEDS", "KW_LIKE", "KW_DCL_SUBF", "KW_DCL_PARM", "DOT",
  "BIF_CHAR", "BIF_TRIM", "BIF_TRIML", "BIF_TRIMR", "BIF_LEN", "BIF_SUBST",
  "BIF_SCAN", "BIF_SCANRPL", "BIF_XLATE", "BIF_DEC", "BIF_INT", "BIF_ELEM",
  "BIF_FOUND", "BIF_EOF", "BIF_ABS", "BIF_DIV", "BIF_REM", "BIF_SIZE",
  "BIF_ADDR", "BIF_PARMS", "BIF_STATUS", "BIF_ERROR", "BIF_MAX", "BIF_MIN",
  "BIF_LOOKUP", "BIF_DATE", "BIF_TIME", "BIF_TIMESTAMP", "BIF_DIFF",
  "BIF_DAYS", "BIF_MONTHS", "BIF_YEARS", "BIF_EDITC", "BIF_EDITW",
  "BIF_REPLACE", "BIF_CHECK", "BIF_CHECKR", "BIF_LOWER", "BIF_UPPER",
  "BIF_SUBDT", "BIF_FLOAT", "BIF_SQRT", "BIF_ALLOC", "BIF_REALLOC",
  "BIF_XFOOT", "BIF_SUBARR", "BIF_SPLIT", "BIF_UNS", "BIF_INTH",
  "BIF_DECH", "BIF_DECPOS", "BIF_CONCAT", "BIF_CONCATARR", "BIF_LEFT",
  "BIF_RIGHT", "BIF_STR", "BIF_MAXARR", "BIF_MINARR", "BIF_LIST",
  "BIF_RANGE", "BIF_LOOKUPLT", "BIF_LOOKUPGE", "BIF_LOOKUPLE",
  "BIF_LOOKUPGT", "BIF_TLOOKUP", "BIF_TLOOKUPLT", "BIF_TLOOKUPGT",
  "BIF_TLOOKUPLE", "BIF_TLOOKUPGE", "BIF_HOURS", "BIF_MINUTES",
  "BIF_SECONDS", "BIF_MSECONDS", "BIF_PADDR", "BIF_PROC", "BIF_PASSED",
  "BIF_OMITTED", "BIF_BITAND", "BIF_BITNOT", "BIF_BITOR", "BIF_BITXOR",
  "BIF_SCANR", "BIF_EDITFLT", "BIF_UNSH", "BIF_PARMNUM", "BIF_GETENV",
  "BIF_XML", "BIF_DATA", "BIF_PARSER", "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE",
  "KW_BINDEC", "KW_UCS2", "KW_GRAPH", "KW_OBJECT", "KW_JAVA", "KW_OVERLAY",
  "KW_POS", "KW_PREFIX", "KW_DATFMT", "KW_TIMFMT", "KW_EXTNAME", "KW_PSDS",
  "KW_SDS", "KW_DTAARA", "KW_OUT", "KW_UNLOCK", "KW_RTNPARM", "KW_OPDESC",
  "KW_ASCEND", "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE", "KW_STRING_OPT",
  "KW_TRIM_OPT", "KW_DCL_ENUM", "KW_END_ENUM", "KW_BOOLEAN",
  "EXEC_SQL_TEXT", "POWER", "KW_DIM_VAR", "KW_DIM_AUTO", "KW_FOR_EACH",
  "KW_IN", "KW_XML_INTO", "KW_DATA_INTO", "KW_DATA_GEN", "KW_SND_MSG",
  "KW_STAR_INFO", "KW_STAR_DIAG", "KW_STAR_ESCAPE", "KW_TYPE",
  "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL",
  "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS",
  "STAR", "SLASH", "NE", "LE", "GE", "LT", "GT", "$accept", "program",
  "statements_opt", "statement_list", "statement", "dcl_f_stmt",
  "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "xml_into_stmt", "data_into_stmt", "data_gen_stmt",
  "snd_msg_stmt", "in_da_stmt", "out_da_stmt", "unlock_da_stmt",
  "evalr_stmt", "callp_stmt", "leavesr_stmt", "dsply_stmt", "inlr_stmt",
  "return_stmt", "expr_stmt", "dcl_pr_stmt", "dcl_proc_stmt",
  "proc_export", "pi_return_type", "pi_params", "pi_param", "pr_params",
  "pr_param", "monitor_stmt", "begsr_stmt", "exsr_stmt", "sorta_stmt",
  "reset_stmt", "clear_stmt", "dealloc_stmt", "test_stmt", "exec_sql_stmt",
  "dcl_enum_stmt", "enum_constants", "enum_constant", "dcl_ds_stmt",
  "ds_fields", "psds_kw", "ds_field", "if_stmt", "elseif_clauses",
  "elseif_clause", "else_clause", "dow_stmt", "dou_stmt", "for_stmt",
  "for_each_stmt", "select_stmt", "when_clauses", "when_clause",
  "other_clause", "iter_stmt", "leave_stmt", "expression", "or_expr",
  "and_expr", "not_expr", "comparison_expr", "additive_expr",
  "multiplicative_expr", "power_expr", "unary_expr", "postfix_expr",
  "ident", "primary_expr", "call_args_opt", "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-882)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-308)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      91,  -882,   124,    42,   474,  -882,  -113,  -106,   369,   -83,
    4695,   281,   369,   281,  4695,   -70,   369,    -8,   281,   281,
    4695,  -882,  3995,    36,  4695,  4695,  4695,   369,   -34,   -23,
       9,    39,    49,   369,   369,   369,   369,  -882,    55,    64,
      70,    73,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,    82,    85,  -882,  -882,  -882,  -882,  -882,    89,  -882,
     369,   100,   369,   369,   369,  3820,   -21,  -882,  -882,  -882,
    -882,    97,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     421,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,   133,  4695,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  4870,
     104,   111,   115,   135,   146,   154,   158,   177,   200,   212,
     215,   217,   228,   277,   293,   295,   302,   309,   311,   318,
     322,   325,   337,   345,   353,   360,   362,   364,   412,   453,
     457,   467,   514,   530,   551,   563,   567,   570,   582,   591,
     598,   611,   626,   629,   630,   631,   632,   633,   634,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   652,   654,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   241,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,   676,  -882,  -882,  -882,  4695,  5045,   171,   544,   835,
    -882,   238,   170,  -148,  -882,   459,   818,  -882,     8,   476,
     680,   681,   683,  -882,   684,   369,   685,   686,   688,  -882,
     689,   876,   690,   691,   692,   693,   865,  -882,  -882,  -882,
     695,   696,   697,   698,   699,   898,   387,   169,  4695,   701,
     702,   -32,   716,   704,   756,   757,   759,  4695,  4695,  4695,
     708,   711,   717,  4695,  4695,    -9,   712,   714,   713,   719,
     720,   727,   729,  -124,  -108,   718,   740,   741,   737,   742,
     744,   745,   746,   753,   754,   743,   758,   238,  4695,  4695,
    4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,
     760,   761,  4695,  4695,  4695,  4695,  4695,   764,   765,   766,
    4695,  4695,  4695,  4170,  4345,  4520,  4695,  4695,  4695,  4695,
    4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,
    4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,
    4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,
    4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,  4695,
    4695,   723,   767,   369,   369,  4695,  4695,  4695,  4695,  4695,
    4695,  4695,   369,  4695,  -882,  4695,   769,   818,  -882,  4695,
    4695,  4870,  4870,  4870,  4870,  4870,  4870,  4870,  4870,  4870,
    4870,  4870,  4870,   770,  4695,  4695,   369,  4695,  -882,  -882,
     772,  4695,  4695,  -882,  -882,   762,  -882,  -882,  -882,  4695,
    4695,    94,  -882,  1675,  -882,  -882,  -882,  -882,  -882,  -882,
     773,   755,   775,   776,   777,   778,    -7,   103,   779,   780,
     781,  -882,  -882,  -882,    -3,  -882,   -59,  -882,  -882,   784,
     789,  4695,  -882,   785,   786,   787,   790,   791,   792,   229,
    -882,  -882,   783,   793,   794,   795,   797,  -882,  -882,  -882,
     796,   800,   803,   804,   805,   801,  -882,   802,  -882,  -882,
    -882,  -882,   798,   809,   810,   812,   813,   814,   846,  -882,
    -882,   186,   195,   208,   233,   271,   280,   284,   296,   299,
     305,   315,   342,  -882,  -882,   357,   384,   392,   394,   396,
    -882,  -882,  -882,   398,   400,   402,  -882,   404,  -882,   407,
    -882,   409,   815,   817,   819,   821,   415,   417,   419,   426,
     429,   437,   447,   823,   454,   464,   468,   470,   472,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   505,   507,   509,   511,   515,   520,
     522,   524,   526,   825,   826,   827,   828,   829,  -882,   830,
     831,   532,   534,   536,   538,   540,   542,   556,   833,   558,
    -882,   834,  -882,   835,  -882,   220,   220,   220,   220,   220,
     220,   220,  -148,  -148,  -882,  -882,  -882,  -882,   783,   816,
     841,   842,   369,   843,   844,  -882,   763,  1901,  1972,   739,
     848,   849,  -882,   930,   851,  -882,  2198,   912,   855,   857,
     858,   859,   847,   806,  -882,   856,   860,  -882,   863,  -118,
     861,   864,    26,   871,   270,  -882,  4695,   789,   424,   -25,
    -882,   877,  4695,  4695,  4695,  -882,  -882,  -882,   875,   878,
     879,   950,   880,  4695,  -882,   807,   881,   882,   883,   886,
     887,   891,   896,   890,   892,   894,   895,   899,   901,   902,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  4695,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   600,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   905,  -882,  -882,   455,   907,   915,
    4695,  4695,  -882,  -882,   916,  -882,   918,    12,   917,   922,
     923,   925,   924,   884,   -29,   142,   903,    78,  -882,   926,
     927,   931,   933,   564,   937,   942,   328,  -882,  -882,    80,
    -882,    40,  -882,  4695,   939,  -882,  -882,   573,   583,   588,
    4695,  4695,  4695,   944,  -882,  -882,   929,   252,   129,   261,
     862,   897,   938,   940,   945,   371,   371,   371,   371,   371,
     943,   946,   941,   948,   951,   953,   954,   955,  -882,  4695,
     947,  -882,   995,  -882,  -882,   -39,   -36,  1081,  2269,  -882,
    2495,  -882,   571,   949,  -882,  -882,  -882,   956,   959,   957,
     961,   952,   355,  -882,   958,   960,   962,   594,   963,    87,
     969,   970,   965,     1,   968,   972,  -882,   399,   971,   973,
     974,   975,   976,    88,   979,   980,   981,  -882,  2566,   982,
    4695,  -137,  4695,  -132,  4695,   983,   984,   985,  -882,   872,
    1032,   986,  -882,  -882,   987,  1034,  -882,   988,   989,   992,
     991,  -882,   993,   994,   997,  1035,   996,   998,  1040,   999,
    1000,  1003,   967,  1001,  1005,  1007,  -882,  1009,  1010,  1011,
    1012,  1013,  1014,   606,  -882,  -882,  -882,  -882,  -882,  -882,
    1015,  -882,  1016,  4695,  -882,  4695,  -882,  1018,  1019,  -882,
    1017,  -882,  1021,  -882,   585,  1020,  1022,  1023,  1024,  1025,
     977,   990,  1028,  1029,  1002,  -882,  1030,  1033,  1036,  1031,
    1038,  -882,  -882,  1044,  1046,  1047,  1055,  1056,  1057,  1026,
    1065,  1076,  1077,  1037,  1075,  -882,  -882,  -882,  1078,  -882,
    1073,  1079,  -882,  1080,  1082,  -882,  1083,  -882,  -882,  -882,
    1084,  1086,  4695,  1041,  1087,  1085,  1089,  -882,  4695,   162,
    1094,  -882,  1095,  4695,  1107,  1102,   203,  1109,  -882,   112,
     371,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  1106,  1104,
    1105,  1108,  1110,  1113,  1114,  -882,  2792,  -882,  1112,  2863,
    1118,  3089,  -882,  -882,    -6,  -882,    75,  -882,  1117,  1119,
    1126,  1128,  1123,  1134,  1136,  1144,  1146,  1141,  1143,  -882,
    -882,  1148,  -882,  1090,  1115,  -882,  1155,   119,  1116,  1156,
    1158,  1159,  1160,  1163,  1157,  1171,  1172,  1173,  1175,  -882,
    -882,  1176,  4695,   -22,  4695,    19,  1179,  4695,  1177,  1180,
    4695,  1181,  1184,  1185,  1178,  1186,  1188,  1189,  4695,  1191,
    1192,  4695,  1195,  1197,  1193,  1199,  1042,  1187,  1201,  1202,
    1206,  1207,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  1307,
    -882,  1208,  -882,  1212,     4,  1213,  1219,   440,  -882,  1217,
      76,  1225,  1226,  1227,  1230,  1228,  1231,  1232,  1224,  1233,
    1237,  1238,   120,   201,  1239,  1240,  1241,   207,  1242,  1243,
    1244,  1245,  1246,  1247,  1229,  1248,  -109,  1253,   172,  1249,
    1254,  -882,  1252,  1255,  -882,  1256,  1260,  -882,  -882,  1262,
    1258,  1263,  1270,  -128,  1266,  1274,  1250,  1259,  1275,  1283,
    1281,  1285,  1287,  1288,  1291,  1293,    79,  1292,  1297,  4695,
    1303,  1234,  -882,  -882,  3160,  -882,  3386,  -882,  1301,  -882,
     627,  1300,  1302,  1304,  1305,  1306,  -882,  1309,  1308,  1310,
    1311,  1312,   -44,   -43,   -38,  1313,  1315,  -882,  -882,  1317,
    1318,  -882,  -882,  -882,  1319,  1320,  -882,  -882,  1321,  1322,
    1323,  1327,  1325,  1324,  1326,  -882,  -882,  1328,  1331,  -882,
    1333,  -882,  1329,  4695,  1334,  4695,  1337,  -882,  -882,  1344,
    1345,  1346,  -882,  -882,  -882,  1351,  1352,  -882,  -882,  1356,
    -882,  -882,  1359,  1367,  1368,  1372,  1373,  -882,  -882,  4695,
    1374,  1375,  1376,  1380,  1381,  -882,  1378,  1382,  1383,  1384,
    1385,  1330,  1379,  1386,  1403,  1316,  -882,   -51,   -50,   -49,
    1404,  1400,   -35,  -882,  1401,   -27,  -882,  1402,   -24,  -882,
    1405,  -882,   213,   222,  -882,  -882,   268,   274,   289,  -882,
    -882,   290,  -882,  -882,  -882,  1406,  -882,  1409,  1410,  1414,
    1416,   -54,  -882,  1411,  -882,  1412,  -882,  -882,  -882,  -882,
    1417,  1418,  -882,  -882,  1420,  1421,  -882,  -882,  1413,  1422,
    1425,  1427,  -882,  -882,  1604,  1428,  1430,  1441,  1442,  1444,
    1446,  1445,  1447,  1450,  1371,  1451,  1449,  -882,  1456,  -882,
    1457,  -882,  1462,   788,  1469,  -882,   808,  1470,  -882,   811,
    1471,  -882,   -37,  1474,  1475,  1476,  1477,  1479,  1480,  1481,
     612,  1482,   615,  1483,  1485,  -882,  1484,  1488,  -882,  -882,
    -882,  -882,  1489,  -882,  -882,  -882,  1491,  1492,  -882,  -882,
    1490,  1493,  1495,  1496,   -28,   -15,   -13,  1502,  1501,  -882,
    -882,  -882,   -48,  1499,  1507,  1194,  1500,  1509,  1214,  1510,
    1516,  1279,  1503,   -18,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  1520,  1524,  1523,  1525,  1527,  1528,  1530,  -882,
    -882,  -882,  -882,  -882,  3457,   -47,   -46,   -42,  1533,  1529,
     -17,  -882,  1531,   -16,  -882,  1532,    -2,  -882,  1534,  -882,
    1535,  -882,  1504,  1536,  1537,  1581,  1538,  1539,  1605,  1541,
    1540,  1731,  1542,  -882,  -882,  1543,  -882,  -882,  1544,  -882,
    1545,  3683,  1550,  1551,  -882,  1552,  -882,  1553,  -882,  1556,
     820,  1554,  -882,   822,  1558,  -882,   824,  1560,  -882,   -11,
    -882,  1567,  -882,  1555,  1568,  -882,  1563,  1569,  -882,  1580,
    1578,  1280,  1582,  1584,  1585,  1587,  -882,  -882,  -882,  -882,
     -41,  1592,  1586,  1739,  1593,  1595,  1745,  1597,  1596,  1754,
    1600,    18,  -882,  1588,  -882,  1603,  -882,  1606,  -882,  1607,
    1601,  -882,  -882,  -882,  -882,  1608,  -882,  1804,  1609,  1610,
    1809,  1611,  1612,  1811,  1614,  1613,  1816,  1616,  -882,  -882,
    -882,  -882,  -882,  1619,  -882,  1617,  -882,  1621,  1620,  -882,
    1622,  1623,  -882,  1624,  1627,  1825,  -882,  1631,  -882,  1633,
    -882,  1634,  -882,  1641,  1639,  -882,  -882,  -882,  -882,  1643,
    -882
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,     0,   111,   112,   113,   109,   108,   110,   119,   120,
     121,     0,     0,   116,   117,   114,   115,   118,     0,   243,
       0,     0,     0,     0,     0,     0,   107,     5,     9,    10,
      11,     0,    12,    13,    41,    42,    43,    44,    45,    46,
      47,    35,    36,    37,    14,    15,    16,    48,    26,    25,
      29,    30,    31,    34,    32,    33,    38,    39,    40,    28,
      27,    17,    18,    19,    20,    21,    22,    23,    24,    49,
       0,   338,   339,   340,   350,   351,   352,   347,   348,   349,
     344,   345,   341,   342,   346,   343,   337,     0,     0,   476,
     477,   474,   479,   480,   481,   482,   478,   475,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   355,   356,
     363,   364,   365,   362,   366,   367,   359,   360,   357,   358,
     361,   353,   368,   369,   370,     0,     0,     0,   310,   311,
     313,   315,   317,   325,   328,   331,   333,   335,   107,     0,
       0,     0,     0,   155,     0,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,   308,   309,     7,
       0,     0,     0,     0,     0,   168,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   316,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   461,   484,     0,   334,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   241,
       0,     0,     0,   154,   158,     0,     7,     7,     7,     0,
       0,   306,   303,     0,     7,   237,   239,   240,   238,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   271,   268,     0,   488,     0,   149,   150,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
     147,   123,   486,     0,   485,     0,     0,    50,    51,    52,
       0,     0,     0,     0,     0,     0,    70,     0,    71,    72,
      68,    73,     0,     0,     0,     0,     0,     0,     0,    69,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   422,   423,     0,     0,     0,     0,     0,
     384,   403,   404,     0,     0,     0,   411,     0,   413,     0,
     415,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,   483,   312,   314,   318,   319,   322,   323,   320,
     321,   324,   326,   327,   329,   330,   332,   336,     0,     0,
       0,     0,     0,     0,     0,   157,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,   268,     0,     0,
       0,     0,     0,     0,   267,   126,     0,     0,     0,     0,
     246,     0,     0,     0,     0,   142,   143,   141,     0,     0,
       0,   124,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   407,   408,   409,   405,   406,   401,   402,   385,
     410,   412,   414,     0,   419,   420,   421,   386,   387,   388,
     389,   390,   391,   392,     0,   399,   400,   424,   425,   426,
     437,   431,   427,   428,   429,   430,   432,   433,   434,   435,
     436,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     371,   128,   130,   151,     0,   129,   152,   293,     0,     0,
       0,     0,     7,     7,     0,     7,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   268,     0,
     489,     0,   248,     0,     0,   247,     7,     0,     0,     0,
       0,     0,     0,     0,   160,   487,     0,   101,   101,   101,
       0,     0,     0,     0,     0,   101,   101,   101,   101,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   242,     0,
       0,   291,     0,   295,   296,     0,     0,     0,     0,   302,
       0,   236,   170,     0,   172,   173,   171,     0,     0,     0,
       0,     0,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,   102,   103,     0,   104,   105,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,   395,   394,   393,   396,   397,   398,
       0,     7,     0,     0,     7,     0,     7,     0,     0,   175,
       0,   205,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,   258,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   244,   249,     0,   132,
       0,     0,   136,     0,     0,   140,     0,   145,   146,   144,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,    56,   101,
     101,    95,    96,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     7,     0,   289,     0,     0,
       0,     0,   235,   175,     0,   174,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     268,     0,   265,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,   416,   417,   418,   458,   459,   460,     0,
       7,     0,     7,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   134,     0,     0,   138,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    58,     0,   297,     0,   299,     0,     7,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   268,     0,
       0,   268,   268,   268,     0,     0,   263,   268,     0,     0,
       0,     0,     0,     0,     0,   273,   274,     0,     0,   272,
       0,   287,     0,     0,     0,     0,     0,    63,    90,     0,
       0,     0,    75,    97,    65,     0,     0,    76,    98,     0,
      62,    89,     0,     0,     0,     0,     0,    74,    99,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,   209,     0,     0,   211,     0,     0,   207,
       0,   223,     0,     0,   253,   260,     0,     0,     0,   252,
     259,     0,   277,   278,   276,     0,   288,     0,     0,     0,
       0,     0,   135,     0,   139,     0,    60,    67,    93,    94,
       0,     0,    59,    66,     0,     0,    91,    92,     0,     0,
       0,     0,   298,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,     0,   219,
       0,   215,     0,     0,     0,   210,     0,     0,   212,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,    80,    81,
      78,    79,     0,    64,    77,   100,     0,     0,     7,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
     220,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   255,   257,   262,   254,   256,
     261,   279,     0,     0,     0,     0,     0,     0,     0,   133,
     137,    61,     7,   165,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,   181,     0,     0,   177,     0,   193,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,   283,     0,   280,   285,     0,   281,
       0,     0,     0,     0,   187,     0,   189,     0,   185,     0,
       0,     0,   180,     0,     0,   182,     0,     0,   178,     0,
     222,     0,   229,     0,     0,   230,     0,     0,   228,     0,
       0,     0,     0,     0,     0,     0,   166,   188,   190,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,     0,   225,     0,   226,     0,   224,     0,
       0,   284,   286,   282,   167,     0,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   233,
     234,   232,   231,     0,   192,     0,   199,     0,     0,   200,
       0,     0,   198,     0,     0,     0,   227,     0,   195,     0,
     196,     0,   194,     0,     0,   203,   204,   202,   201,     0,
     197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -882,  -882,  1072,  -441,   870,  -882,  -882,  -681,  -882,   444,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -737,
     294,  -882,  -881,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   566,  -633,  -882,  -637,   889,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    1423,  -882,  -882,  -882,   -10,  -882,  1070,  1478,  1760,   194,
     448,   107,  -882,  1654,     5,  -882,  1505,  -882,  4967
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   453,   645,    68,    69,   929,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   460,   466,
    1064,  1148,   804,   883,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   669,   670,   100,   662,   474,   817,
     101,   787,   861,   862,   102,   103,   104,   105,   106,   451,
     452,   643,   107,   108,   475,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   127,   257,   493,   494,   476
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     247,   496,  1311,  1314,   262,   636,   637,   638,  1317,  1442,
     268,  1384,   270,   646,   272,   273,   274,   260,  1469,  1387,
     807,   264,  1390,   461,   462,   463,   464,   819,  1492,  1511,
    1514,  1472,   275,  1475,   963,  1550,   825,   965,   281,   282,
     283,   284,    -3,     6,  1517,   653,     7,     8,     9,  1376,
    1378,  1380,  1480,  1503,  1505,   301,  1312,  1315,  1507,  1565,
     873,  1011,  1318,  1443,  1577,   292,  1014,   294,   295,   296,
     880,   479,  1470,    10,    11,    12,    13,    14,    15,   881,
      16,    17,    18,    19,    20,  1473,   505,  1476,   302,  1551,
    1066,  1145,  1270,  1271,     1,    21,    22,    23,  1253,  1254,
     663,  1218,  1146,   507,    24,   990,   430,   431,    25,    26,
    1012,    27,  1146,   809,   810,  1015,    28,   302,   326,  1272,
      29,    30,    31,   506,     5,    32,   811,    33,   814,    34,
      35,    36,    37,   815,   109,   968,    38,   110,  1255,   508,
      39,  1126,  1127,    40,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,  1404,   922,   923,   934,   941,   930,
     128,   931,   926,    41,   947,   948,   949,   950,   951,   450,
     641,   889,   922,   923,  1149,  1227,  1183,   263,   931,   926,
     888,   903,   904,   881,   881,   815,  1150,   815,   825,   986,
    1004,   665,   666,  1405,   815,   815,  1377,  1379,  1381,  1481,
    1504,  1506,   824,  1313,  1316,  1508,  1566,   655,   964,  1319,
    1444,   966,  1385,   276,   882,   480,  1128,  1186,   668,  1471,
    1388,  1169,  1239,  1391,   277,  1184,   815,   815,   303,  1493,
    1512,  1515,  1474,   932,  1477,   416,  1552,  1147,   497,   318,
     654,   265,    42,    43,   664,  1518,    44,  1147,   991,    45,
      46,    47,    48,    49,    50,   872,   278,   434,    51,    52,
      53,    54,    55,    56,    57,  1578,  1187,   905,    58,   816,
     440,    59,   467,   468,   469,    60,    61,    62,    63,    64,
      65,   920,   921,   668,   271,    66,   279,   486,   487,   488,
     935,   936,   280,   492,   495,   922,   923,   924,   285,  1285,
    1286,   925,   926,  1240,   922,   923,   937,   286,   815,  1244,
     938,   926,   656,   287,   815,  1393,   471,   472,   882,   882,
     815,   816,   288,   816,  1394,   289,  1287,  1129,   290,   815,
     816,   816,   291,   319,   320,   321,   322,   323,   324,   898,
     899,   900,   901,   293,   933,   304,   552,   553,   554,   555,
     657,   867,   868,   328,   870,  1087,   927,   563,  1130,  1131,
     329,   325,   816,   816,   330,   939,   975,   976,   977,   978,
    1395,    37,  -268,   884,   885,   815,  1396,  -268,   470,  1257,
    1258,   815,   471,   472,   331,   908,   886,   593,   594,   595,
     596,  1397,  1398,  1114,  1115,   332,   815,   815,   461,   462,
     463,   464,    41,   333,   427,   610,  1116,   334,   599,   600,
     994,   995,   996,   997,   922,   923,   473,   608,   418,  1259,
     931,   926,   428,   429,   628,   629,   335,   631,   305,   306,
     307,   633,   634,   902,  1122,  1123,   700,   666,   465,   639,
     640,   630,  1162,  1163,   816,   701,   666,  1124,  1167,   336,
     816,  1221,  1222,  1223,  1224,   259,   816,   261,   702,   666,
     979,   337,   266,   267,   338,   816,   339,   928,   678,   679,
     680,   671,   428,   429,    -2,     6,   940,   340,     7,     8,
       9,    42,    43,   703,   666,    44,   421,   414,    45,    46,
      47,    48,    49,    50,   422,   423,   424,   425,   426,    53,
      54,    55,    56,    57,   998,    10,    11,    12,    13,    14,
      15,   816,    16,    17,    18,    19,    20,   816,   859,   860,
    1056,   704,   666,  1059,   258,  1061,   341,    21,    22,    23,
     705,   666,   816,   816,   706,   666,    24,   624,   625,   626,
      25,    26,   342,    27,   343,  1225,   707,   666,    28,   708,
     666,   344,    29,    30,    31,   709,   666,    32,   345,    33,
     346,    34,    35,    36,    37,   710,   666,   347,    38,   111,
     112,   348,    39,   113,   349,    40,   114,   115,   116,   117,
     118,   119,   461,   462,   463,   464,   350,   120,   121,   122,
     123,   124,   711,   666,   351,    41,  1068,  1069,  1070,  1071,
    1322,  1323,   352,   125,  1326,  1327,  1328,   712,   666,   353,
    1331,   354,   126,   355,  1139,   615,   616,   617,   618,   619,
     620,   621,   852,   853,   854,   855,   856,   857,  1049,  1050,
    1051,  1052,  1053,  1054,   713,   666,   419,   784,  1297,  1298,
    1299,  1300,   714,   666,   715,   666,   716,   666,   717,   666,
     718,   666,   719,   666,   720,   666,   820,   721,   666,   722,
     666,   356,   827,   828,   829,   727,   666,   728,   666,   729,
     666,   822,   823,   835,    42,    43,   730,   666,    44,   731,
     666,    45,    46,    47,    48,    49,    50,   732,   666,   432,
      51,    52,    53,    54,    55,    56,    57,   733,   666,  1214,
      58,  1216,   357,    59,   735,   666,   358,    60,    61,    62,
      63,    64,    65,   851,   736,   666,   359,    66,   737,   666,
     738,   666,   739,   666,   435,   740,   666,   741,   666,   742,
     666,   743,   666,   744,   666,   745,   666,   746,   666,   747,
     666,   748,   666,   749,   666,   750,   666,   751,   666,   752,
     666,   753,   666,   754,   666,   755,   666,   756,   666,   757,
     666,   758,   666,   360,     6,   759,   666,     7,     8,     9,
     760,   666,   761,   666,   762,   666,   763,   666,  1296,   361,
     865,   866,   771,   666,   772,   666,   773,   666,   774,   666,
     775,   666,   776,   666,    10,    11,    12,    13,    14,    15,
     362,    16,    17,    18,    19,    20,   777,   666,   779,   666,
     790,   791,   363,   906,   894,   895,   364,    22,    23,   365,
     915,   916,   917,   909,   910,    24,  -290,  -290,  -290,    25,
      26,   366,    27,   911,   912,  1433,  1434,    28,   913,   914,
     367,    29,    30,    31,   983,   984,    32,   368,    33,   960,
      34,    35,    36,    37,  1364,  1436,  1437,    38,  1439,  1440,
     369,    39,  1452,  1453,    40,  1455,  1456,  1541,  1542,  1544,
    1545,  1547,  1548,    67,    67,   370,   622,   623,   371,   372,
     373,   374,   375,   376,    41,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
    1010,   392,  1013,   393,  1016,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   415,   420,   433,   436,   437,
     438,   439,   445,   441,   442,   443,   444,   446,   447,   448,
     450,   449,   454,   455,   456,   457,   458,   459,   477,   478,
     481,   482,   483,  1058,   484,  1060,   485,   489,   490,   498,
     491,   499,   500,    42,    43,   509,   597,    44,   501,   502,
      45,    46,    47,    48,    49,    50,   503,  1464,   504,    51,
      52,    53,    54,    55,    56,    57,   512,   510,   511,    58,
     519,   513,    59,   514,   515,   516,    60,    61,    62,    63,
      64,    65,   517,   518,   648,   520,    66,   794,   797,   635,
     533,   534,  1108,   627,   540,   541,   542,   598,  1113,   612,
     647,  1501,   632,  1119,   649,   650,   651,   652,   659,   660,
     661,   667,   668,   681,   672,   673,   674,   675,   676,   677,
     686,   693,   684,   682,   687,   683,   685,   688,   689,   690,
     691,   692,   699,   694,   695,   803,   696,   697,   698,   833,
     962,   836,  1021,   781,  1024,  1032,   723,   724,   989,   725,
    1035,   726,  1208,     4,   734,   764,   765,   766,   767,   768,
     769,   770,     6,   778,   780,     7,     8,     9,   782,   783,
     785,   786,  1182,   802,  1185,   792,   793,  1189,   795,   798,
    1192,   799,   800,   801,   812,   805,   942,   813,  1200,   806,
     808,  1203,    10,    11,    12,    13,    14,    15,   818,    16,
      17,    18,    19,    20,   826,   830,  1020,   834,   831,   832,
     879,   837,   838,   839,   842,    22,    23,   840,   841,   843,
     844,   943,   845,    24,   846,   847,   887,    25,    26,   848,
      27,   849,   858,   850,   863,    28,  -305,  -305,  -305,    29,
      30,    31,   864,   869,    32,   871,    33,   874,    34,    35,
      36,    37,   875,   876,   878,    38,   877,   890,   891,    39,
     919,   892,    40,   893,   896,   897,   907,   918,   944,   952,
     945,   954,   946,  1165,   961,   974,   969,   953,   955,  1290,
     970,   956,    41,   957,   958,   959,   971,   972,   973,   980,
     985,   981,   982,   987,   988,   992,   993,  1039,  1166,  1170,
     999,  1077,  1000,  1001,  1002,  1003,  1005,  1006,  1007,  1009,
    1017,  1018,  1019,   821,  1078,  1022,  1023,  1025,  1026,  1027,
    1028,  1484,  1029,  1030,  1031,  1033,  1081,  1034,  1036,  1037,
    1038,  1040,  1041,  1343,  1042,  1345,  1043,  1044,  1045,  1046,
    1047,  1487,  1055,  1057,  1048,  1062,  1063,  1065,  1067,  1072,
    1094,  1073,  1074,  1075,  1076,  1079,  1080,  1082,  1085,  1358,
    1098,    42,    43,  1083,  1109,    44,  1084,  1086,    45,    46,
      47,    48,    49,    50,  1088,  1089,  1090,    51,    52,    53,
      54,    55,    56,    57,  1091,  1092,  1093,    58,     6,  1095,
      59,     7,     8,     9,    60,    61,    62,    63,    64,    65,
    1096,  1097,  1099,  1101,    66,  1100,  1490,  1560,  1102,  1111,
    1103,  1104,  1112,  1105,  1106,  1107,  1110,  1117,    10,    11,
      12,    13,    14,    15,  1118,    16,    17,    18,    19,    20,
    1120,  1121,  1125,  1132,  1133,  1134,   658,  1144,  1135,  1140,
    1136,    22,    23,  1137,  1138,  1142,  1151,  1155,  1152,    24,
    -292,  -292,  -292,    25,    26,  1153,    27,  1154,  1156,     6,
    1157,    28,     7,     8,     9,    29,    30,    31,  1158,  1159,
      32,  1160,    33,  1161,    34,    35,    36,    37,  1164,  1168,
    1171,    38,  1172,  1173,  1174,    39,  1175,  1176,    40,    10,
      11,    12,    13,    14,    15,  1365,    16,    17,    18,    19,
      20,  1177,  1178,  1181,  1179,  1180,  1188,  1190,    41,  1196,
    1191,  1193,    22,    23,  1194,  1195,  1209,  1197,  1198,  1199,
      24,  1201,  1202,  1206,    25,    26,  1204,    27,  1205,  1207,
    1210,  1211,    28,  1212,  1213,  1215,    29,    30,    31,  1217,
    1219,    32,  1220,    33,  1226,    34,    35,    36,    37,  1228,
    1229,  1230,    38,  1366,  1231,  1235,    39,  1292,  1232,    40,
    1251,  1233,  1234,  1236,  1237,  1238,  1241,  1242,  1243,   613,
    1246,  1247,  1245,  1260,  1275,  1248,  1249,  1250,  1252,    41,
    1256,  1261,  1262,  1276,  1263,  1267,  1264,    42,    43,  1265,
    1268,    44,  1266,  1273,    45,    46,    47,    48,    49,    50,
    1269,  1274,  1277,    51,    52,    53,    54,    55,    56,    57,
    1278,  1279,  1280,    58,  1281,  1283,    59,  1284,  1282,  1288,
      60,    61,    62,    63,    64,    65,  1289,  1291,  1295,  1301,
      66,  1302,  1521,  1303,  1304,  1305,  1306,  1320,  1307,  1375,
    1308,  1309,  1321,  1310,  1324,  1325,  1329,  1330,  1332,  1333,
    1334,  1335,  1336,  1337,  1371,  1338,  1342,  1339,    42,    43,
    1340,  1344,    44,  1341,  1346,    45,    46,    47,    48,    49,
      50,  1347,  1348,  1349,    51,    52,    53,    54,    55,    56,
      57,  1350,  1351,  1352,    58,     6,  1353,    59,     7,     8,
       9,    60,    61,    62,    63,    64,    65,  1354,  1355,  1356,
    1357,    66,  1427,  1372,  1359,  1360,  1361,  1362,  1363,  1524,
    1373,  1367,  1368,  1369,  1370,    10,    11,    12,    13,    14,
      15,  1416,    16,    17,    18,    19,    20,  1374,  1382,  1383,
    1386,  1389,  1400,  1527,  1401,  1392,  1399,  1402,    22,    23,
    1403,  1406,  1407,  1412,  1408,  1409,    24,  1410,  1411,  1413,
      25,    26,  1414,    27,  1415,  1418,     6,  1419,    28,     7,
       8,     9,    29,    30,    31,  1420,  1421,    32,  1422,    33,
    1423,    34,    35,    36,    37,  1424,  1429,  1425,    38,  1417,
    1426,  1428,    39,  1430,  1431,    40,    10,    11,    12,    13,
      14,    15,  1432,    16,    17,    18,    19,    20,  1435,  1438,
    1441,  1445,  1446,  1447,  1448,    41,  1449,  1450,  1451,    22,
      23,  1459,  1454,  1457,  1458,  1460,  1461,    24,  1462,  1463,
    1465,    25,    26,  1466,    27,  1467,  1478,  1468,  1479,    28,
    1482,  1485,  1491,    29,    30,    31,   644,  1483,    32,  1486,
      33,  1488,    34,    35,    36,    37,  1489,  1494,  1495,    38,
    1496,  1498,  1497,    39,  1500,  1499,    40,  1509,  1510,  1530,
    1513,  1516,  1520,  1522,  1519,  1525,  1569,  1523,  1528,  1526,
    1529,  1531,  1572,  1532,  1533,  1534,    41,  1536,  1537,  1538,
    1539,  1575,  1554,  1543,    42,    43,  1540,  1546,    44,  1549,
    1556,    45,    46,    47,    48,    49,    50,  1553,  1555,  1557,
      51,    52,    53,    54,    55,    56,    57,  1558,  1559,  1561,
      58,  1562,  1563,    59,  1564,  1579,  1568,    60,    61,    62,
      63,    64,    65,  1567,  1570,  1571,  1574,    66,  1573,  1576,
    1580,  1583,  1585,  1581,  1582,  1584,  1586,  1588,  1589,  1591,
    1587,  1592,  1590,  1593,  1594,  1595,  1596,  1597,  1598,  1600,
    1599,  1602,  1604,  1601,   642,    42,    43,  1603,  1605,    44,
    1606,  1607,    45,    46,    47,    48,    49,    50,  1608,  1609,
    1610,    51,    52,    53,    54,    55,    56,    57,   614,   327,
     417,    58,     6,     0,    59,     7,     8,     9,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,    66,     0,
     611,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,   788,
      27,     0,     0,     6,     0,    28,     7,     8,     9,    29,
      30,    31,     0,     0,    32,     0,    33,     0,    34,    35,
      36,    37,     0,     0,     0,    38,     0,     0,     0,    39,
       0,     0,    40,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
     789,    27,     0,     0,     0,     0,    28,     0,     0,     0,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
      39,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,    42,    43,     0,     0,    44,     0,     0,    45,    46,
      47,    48,    49,    50,     0,     0,     0,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,    58,     0,     0,
      59,     0,     0,     0,    60,    61,    62,    63,    64,    65,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     6,
       0,    59,     7,     8,     9,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,    25,    26,     0,    27,     0,     0,
       6,     0,    28,     7,     8,     9,    29,    30,    31,     0,
       0,    32,   796,    33,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,    39,     0,     0,    40,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,    26,     0,    27,     0,
       0,     0,     0,    28,     0,     0,  -307,    29,    30,    31,
       0,     0,    32,     0,    33,     0,    34,    35,    36,    37,
       0,     0,     0,    38,     0,     0,     0,    39,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,    42,    43,
       0,     0,    44,     0,     0,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,    58,     0,     0,    59,     0,     0,
       0,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,     6,     0,    59,     7,
       8,     9,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
      14,    15,     0,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,     0,    27,     0,     0,     6,     0,    28,
       7,     8,     9,    29,    30,    31,     0,   967,    32,     0,
      33,     0,    34,    35,    36,    37,     0,     0,     0,    38,
       0,     0,     0,    39,     0,     0,    40,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,    26,     0,    27,  1008,     0,     0,     0,
      28,     0,     0,     0,    29,    30,    31,     0,     0,    32,
       0,    33,     0,    34,    35,    36,    37,     0,     0,     0,
      38,     0,     0,     0,    39,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,    42,    43,     0,     0,    44,
       0,     0,    45,    46,    47,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,    58,     0,     0,    59,     0,     0,     0,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     6,     0,    59,     7,     8,     9,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,  -294,    25,    26,
       0,    27,     0,     0,     6,     0,    28,     7,     8,     9,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
      39,     0,     0,    40,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,     0,    27,  1141,     0,     0,     0,    28,     0,     0,
       0,    29,    30,    31,     0,     0,    32,     0,    33,     0,
      34,    35,    36,    37,     0,     0,     0,    38,     0,     0,
       0,    39,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     0,
       0,    59,     0,     0,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
       6,     0,    59,     7,     8,     9,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,    26,     0,    27,  1143,
       0,     6,     0,    28,     7,     8,     9,    29,    30,    31,
       0,     0,    32,     0,    33,     0,    34,    35,    36,    37,
       0,     0,     0,    38,     0,     0,     0,    39,     0,     0,
      40,    10,    11,    12,    13,    14,    15,     0,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,     0,    27,
    1293,     0,     0,     0,    28,     0,     0,     0,    29,    30,
      31,     0,     0,    32,     0,    33,     0,    34,    35,    36,
      37,     0,     0,     0,    38,     0,     0,     0,    39,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,     0,     0,    59,     0,
       0,     0,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,     0,    44,     0,     0,    45,    46,    47,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,    58,     6,     0,    59,
       7,     8,     9,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,    26,     0,    27,  1294,     0,     6,     0,
      28,     7,     8,     9,    29,    30,    31,     0,     0,    32,
       0,    33,     0,    34,    35,    36,    37,     0,     0,     0,
      38,     0,     0,     0,    39,     0,     0,    40,    10,    11,
      12,    13,    14,    15,     0,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    22,    23,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,  1502,     0,     0,    39,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     0,     0,    59,     0,     0,     0,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,    44,     0,     0,    45,    46,    47,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    58,     6,     0,    59,     7,     8,     9,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,     0,    27,     0,     0,     0,     0,    28,     0,     0,
       0,    29,    30,    31,     0,     0,    32,     0,    33,     0,
      34,    35,    36,    37,     0,     0,     0,    38,  1535,     0,
       0,    39,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,   137,     0,     0,    58,
     138,     0,    59,   139,     0,     0,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,    66,     0,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   129,     0,     0,   226,
     227,   228,     0,     0,   229,     0,     0,   230,   231,   232,
     233,   234,   235,     0,     0,     0,     0,     0,   236,   237,
     238,   239,   240,   130,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,   134,   135,   136,     0,     0,   297,
     298,   299,   300,   241,   242,   243,   244,     0,     0,   245,
       0,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   138,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   129,     0,     0,   226,   227,   228,     0,     0,   229,
       0,     0,   230,   231,   232,   233,   234,   235,     0,     0,
       0,     0,     0,   236,   237,   238,   239,   240,   130,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,   241,   242,
     243,   244,   269,     0,   245,     0,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
     138,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   129,     0,     0,   226,
     227,   228,     0,     0,   229,     0,     0,   230,   231,   232,
     233,   234,   235,     0,     0,     0,     0,     0,   236,   237,
     238,   239,   240,   130,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,   241,   242,   243,   244,     0,     0,   245,
     546,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   138,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   129,     0,     0,   226,   227,   228,     0,     0,   229,
       0,     0,   230,   231,   232,   233,   234,   235,     0,     0,
       0,     0,     0,   236,   237,   238,   239,   240,   130,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,   241,   242,
     243,   244,     0,     0,   245,   548,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
     138,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   129,     0,     0,   226,
     227,   228,     0,     0,   229,     0,     0,   230,   231,   232,
     233,   234,   235,     0,     0,     0,     0,     0,   236,   237,
     238,   239,   240,   130,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,   241,   242,   243,   244,     0,     0,   245,
     550,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   138,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   129,     0,     0,   226,   227,   228,     0,     0,   229,
       0,     0,   230,   231,   232,   233,   234,   235,     0,     0,
       0,     0,     0,   236,   237,   238,   239,   240,   130,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,   241,   242,
     243,   244,     0,     0,   245,     0,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   129,     0,     0,   226,
     227,   228,     0,     0,   229,     0,     0,   230,   231,   232,
     233,   234,   235,     0,     0,     0,     0,     0,   236,   237,
     238,   239,   240,   130,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,   241,   242,   243,   244,     0,     0,   245,
       0,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,   226,   227,   228,     0,     0,   229,
       0,     0,   230,   231,   232,   233,   234,   235,     0,     0,
       0,     0,     0,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,   244,     0,     0,   245,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,     0,     0,   535,
     536,   537,   538,   539,     0,     0,     0,   543,   544,   545,
     547,   549,   551,     0,     0,     0,     0,   556,   557,   558,
     559,   560,   561,   562,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,     0,     0,     0,     0,     0,     0,
       0,     0,   601,   602,   603,   604,   605,   606,   607,     0,
     609
};

static const yytype_int16 yycheck[] =
{
      10,    10,    46,    46,    14,   446,   447,   448,    46,    46,
      20,    46,    22,   454,    24,    25,    26,    12,    46,    46,
     657,    16,    46,    11,    12,    13,    14,   664,    46,    46,
      46,    46,    27,    46,    73,    46,   669,    73,    33,    34,
      35,    36,     0,     1,    46,    52,     4,     5,     6,   100,
     100,   100,   100,   100,   100,    65,   100,   100,   100,   100,
     797,   198,   100,   100,    46,    60,   198,    62,    63,    64,
      99,   103,   100,    31,    32,    33,    34,    35,    36,   108,
      38,    39,    40,    41,    42,   100,   210,   100,   109,   100,
     971,    97,   220,   221,     3,    53,    54,    55,   207,   208,
     103,    97,   108,   211,    62,   104,   254,   255,    66,    67,
     247,    69,   108,   231,   232,   247,    74,   109,   128,   247,
      78,    79,    80,   247,     0,    83,   244,    85,   102,    87,
      88,    89,    90,   107,   247,   872,    94,   243,   247,   247,
      98,    29,    30,   101,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   208,    43,    44,   838,   839,    30,
     243,    49,    50,   121,   845,   846,   847,   848,   849,    75,
      76,   808,    43,    44,    99,    99,   198,   247,    49,    50,
     102,   818,   102,   108,   108,   107,  1067,   107,   821,   102,
     102,   250,   251,   247,   107,   107,   247,   247,   247,   247,
     247,   247,   227,   247,   247,   247,   247,   104,   247,   247,
     247,   247,   247,   247,   243,   247,   104,   198,   243,   247,
     247,   102,   102,   247,   247,   247,   107,   107,   249,   247,
     247,   247,   247,   104,   247,   245,   247,   243,   247,   106,
     247,   249,   200,   201,   247,   247,   204,   243,   247,   207,
     208,   209,   210,   211,   212,   243,   247,   249,   216,   217,
     218,   219,   220,   221,   222,   247,   247,   227,   226,   243,
     265,   229,   103,   104,   105,   233,   234,   235,   236,   237,
     238,    29,    30,   243,   248,   243,   247,   297,   298,   299,
      29,    30,   243,   303,   304,    43,    44,    45,   243,   220,
     221,    49,    50,   102,    43,    44,    45,   243,   107,   102,
      49,    50,   209,   243,   107,   102,   213,   214,   243,   243,
     107,   243,   249,   243,   102,   243,   247,   215,   243,   107,
     243,   243,   243,   200,   201,   202,   203,   204,   205,    11,
      12,    13,    14,   243,   215,   248,   356,   357,   358,   359,
     247,   792,   793,   249,   795,   992,   104,   367,  1039,  1040,
     249,   228,   243,   243,   249,   104,    11,    12,    13,    14,
     102,    90,   102,   231,   232,   107,   102,   107,   209,   207,
     208,   107,   213,   214,   249,   826,   244,   397,   398,   399,
     400,   102,   102,   231,   232,   249,   107,   107,    11,    12,
      13,    14,   121,   249,   234,   415,   244,   249,   403,   404,
      11,    12,    13,    14,    43,    44,   247,   412,   247,   247,
      49,    50,   252,   253,   434,   435,   249,   437,     7,     8,
       9,   441,   442,   105,   231,   232,   250,   251,    51,   449,
     450,   436,  1079,  1080,   243,   250,   251,   244,  1085,   249,
     243,    11,    12,    13,    14,    11,   243,    13,   250,   251,
     105,   249,    18,    19,   249,   243,   249,   215,   239,   240,
     241,   481,   252,   253,     0,     1,   215,   249,     4,     5,
       6,   200,   201,   250,   251,   204,   248,   246,   207,   208,
     209,   210,   211,   212,   256,   257,   258,   259,   260,   218,
     219,   220,   221,   222,   105,    31,    32,    33,    34,    35,
      36,   243,    38,    39,    40,    41,    42,   243,    63,    64,
     961,   250,   251,   964,   243,   966,   249,    53,    54,    55,
     250,   251,   243,   243,   250,   251,    62,   430,   431,   432,
      66,    67,   249,    69,   249,   105,   250,   251,    74,   250,
     251,   249,    78,    79,    80,   250,   251,    83,   249,    85,
     249,    87,    88,    89,    90,   250,   251,   249,    94,   200,
     201,   249,    98,   204,   249,   101,   207,   208,   209,   210,
     211,   212,    11,    12,    13,    14,   249,   218,   219,   220,
     221,   222,   250,   251,   249,   121,    11,    12,    13,    14,
    1237,  1238,   249,   234,  1241,  1242,  1243,   250,   251,   249,
    1247,   249,   243,   249,  1055,   421,   422,   423,   424,   425,
     426,   427,    22,    23,    24,    25,    26,    27,    22,    23,
      24,    25,    26,    27,   250,   251,    92,   632,    11,    12,
      13,    14,   250,   251,   250,   251,   250,   251,   250,   251,
     250,   251,   250,   251,   250,   251,   666,   250,   251,   250,
     251,   249,   672,   673,   674,   250,   251,   250,   251,   250,
     251,   247,   248,   683,   200,   201,   250,   251,   204,   250,
     251,   207,   208,   209,   210,   211,   212,   250,   251,   230,
     216,   217,   218,   219,   220,   221,   222,   250,   251,  1140,
     226,  1142,   249,   229,   250,   251,   249,   233,   234,   235,
     236,   237,   238,   723,   250,   251,   249,   243,   250,   251,
     250,   251,   250,   251,   248,   250,   251,   250,   251,   250,
     251,   250,   251,   250,   251,   250,   251,   250,   251,   250,
     251,   250,   251,   250,   251,   250,   251,   250,   251,   250,
     251,   250,   251,   250,   251,   250,   251,   250,   251,   250,
     251,   250,   251,   249,     1,   250,   251,     4,     5,     6,
     250,   251,   250,   251,   250,   251,   250,   251,  1219,   249,
     790,   791,   250,   251,   250,   251,   250,   251,   250,   251,
     250,   251,   250,   251,    31,    32,    33,    34,    35,    36,
     249,    38,    39,    40,    41,    42,   250,   251,   250,   251,
      71,    72,   249,   823,   250,   251,   249,    54,    55,   249,
     830,   831,   832,   250,   251,    62,    63,    64,    65,    66,
      67,   249,    69,   250,   251,    47,    48,    74,   250,   251,
     249,    78,    79,    80,   250,   251,    83,   249,    85,   859,
      87,    88,    89,    90,  1295,    47,    48,    94,    47,    48,
     249,    98,   250,   251,   101,   250,   251,    47,    48,    47,
      48,    47,    48,     3,     4,   249,   428,   429,   249,   249,
     249,   249,   249,   249,   121,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     910,   249,   912,   249,   914,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,    91,   109,   248,   248,
     247,   247,    56,   248,   248,   247,   247,   247,   247,   247,
      75,   248,   247,   247,   247,   247,   247,    49,   247,   247,
     234,   247,   196,   963,   197,   965,   197,   249,   247,   247,
     243,   247,   249,   200,   201,   247,   243,   204,   249,   249,
     207,   208,   209,   210,   211,   212,   249,  1418,   249,   216,
     217,   218,   219,   220,   221,   222,   249,   247,   247,   226,
     247,   249,   229,   249,   249,   249,   233,   234,   235,   236,
     237,   238,   249,   249,   249,   247,   243,    77,    96,   247,
     250,   250,  1022,   243,   250,   250,   250,   250,  1028,   250,
     247,  1462,   250,  1033,   249,   249,   249,   249,   249,   249,
     249,   247,   243,   250,   249,   249,   249,   247,   247,   247,
     244,   243,   247,   250,   244,   251,   249,   244,   244,   244,
     249,   249,   206,   244,   244,   249,   244,   244,   244,   109,
      65,   254,    30,   247,    30,    30,   251,   250,   103,   250,
      30,   250,    30,     1,   251,   250,   250,   250,   250,   250,
     250,   250,     1,   250,   250,     4,     5,     6,   247,   247,
     247,   247,  1102,   246,  1104,   247,   247,  1107,   247,   244,
    1110,   244,   244,   244,   243,   249,   244,   243,  1118,   249,
     247,  1121,    31,    32,    33,    34,    35,    36,   247,    38,
      39,    40,    41,    42,   247,   250,   254,   247,   250,   250,
     246,   250,   250,   250,   243,    54,    55,   251,   251,   243,
     250,   244,   250,    62,   250,   250,   243,    66,    67,   250,
      69,   250,   247,   251,   247,    74,    75,    76,    77,    78,
      79,    80,   247,   247,    83,   247,    85,   250,    87,    88,
      89,    90,   250,   250,   250,    94,   251,   251,   251,    98,
     251,   250,   101,   250,   247,   243,   247,   243,   250,   246,
     250,   250,   247,   103,   247,   243,   247,   251,   250,  1209,
     244,   250,   121,   250,   250,   250,   247,   250,   247,   251,
     247,   251,   250,   244,   244,   247,   244,   250,   103,   103,
     249,   244,   249,   249,   249,   249,   247,   247,   247,   247,
     247,   247,   247,   667,   244,   249,   249,   249,   249,   247,
     249,    47,   249,   249,   247,   249,   244,   249,   249,   249,
     247,   250,   247,  1263,   247,  1265,   247,   247,   247,   247,
     247,    47,   247,   247,   250,   247,   247,   250,   247,   249,
     244,   249,   249,   249,   249,   247,   247,   247,   247,  1289,
     243,   200,   201,   250,   243,   204,   250,   249,   207,   208,
     209,   210,   211,   212,   250,   249,   249,   216,   217,   218,
     219,   220,   221,   222,   249,   249,   249,   226,     1,   244,
     229,     4,     5,     6,   233,   234,   235,   236,   237,   238,
     244,   244,   247,   250,   243,   247,    47,    47,   249,   244,
     250,   249,   243,   250,   250,   249,   249,   243,    31,    32,
      33,    34,    35,    36,   249,    38,    39,    40,    41,    42,
     243,   249,   243,   247,   250,   250,   467,  1063,   250,   247,
     250,    54,    55,   250,   250,   247,   249,   244,   249,    62,
      63,    64,    65,    66,    67,   249,    69,   249,   244,     1,
     244,    74,     4,     5,     6,    78,    79,    80,   244,   243,
      83,   250,    85,   250,    87,    88,    89,    90,   250,   244,
     244,    94,   244,   244,   244,    98,   243,   250,   101,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   250,   250,   247,   251,   250,   247,   250,   121,   251,
     250,   250,    54,    55,   250,   250,   249,   251,   250,   250,
      62,   250,   250,   250,    66,    67,   251,    69,   251,   250,
     249,   249,    74,   247,   247,   247,    78,    79,    80,   247,
     247,    83,   243,    85,   247,    87,    88,    89,    90,   244,
     244,   244,    94,    95,   244,   251,    98,   243,   250,   101,
     251,   250,   250,   250,   247,   247,   247,   247,   247,   419,
     247,   247,   250,   244,   244,   250,   250,   250,   250,   121,
     247,   247,   250,   244,   249,   247,   250,   200,   201,   249,
     247,   204,   250,   247,   207,   208,   209,   210,   211,   212,
     250,   247,   247,   216,   217,   218,   219,   220,   221,   222,
     247,   250,   247,   226,   247,   244,   229,   244,   250,   247,
     233,   234,   235,   236,   237,   238,   249,   244,   247,   249,
     243,   249,    48,   249,   249,   249,   247,   244,   250,   243,
     250,   250,   247,   251,   247,   247,   247,   247,   247,   247,
     247,   244,   247,   249,   244,   249,   247,   249,   200,   201,
     249,   247,   204,   250,   247,   207,   208,   209,   210,   211,
     212,   247,   247,   247,   216,   217,   218,   219,   220,   221,
     222,   250,   250,   247,   226,     1,   247,   229,     4,     5,
       6,   233,   234,   235,   236,   237,   238,   250,   250,   247,
     247,   243,   251,   244,   250,   250,   250,   247,   247,    48,
     244,   249,   249,   249,   249,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   244,   244,   249,
     249,   249,   243,    48,   244,   250,   250,   243,    54,    55,
     244,   250,   250,   250,   247,   247,    62,   247,   247,   247,
      66,    67,   247,    69,   247,   247,     1,   247,    74,     4,
       5,     6,    78,    79,    80,   244,   244,    83,   244,    85,
     244,    87,    88,    89,    90,   250,   247,   250,    94,    95,
     250,   250,    98,   247,   247,   101,    31,    32,    33,    34,
      35,    36,   250,    38,    39,    40,    41,    42,   249,   249,
     249,   247,   247,   247,   247,   121,   247,   247,   247,    54,
      55,   247,   250,   250,   249,   247,   247,    62,   247,   247,
     250,    66,    67,   250,    69,   250,   244,   251,   247,    74,
     251,   251,   249,    78,    79,    80,    81,   250,    83,   250,
      85,   251,    87,    88,    89,    90,   250,   247,   244,    94,
     247,   244,   247,    98,   244,   247,   101,   244,   249,    48,
     249,   249,   247,   247,   250,   247,    47,   250,   247,   250,
     250,   249,    47,   250,   250,   250,   121,   247,   247,   247,
     247,    47,   247,   249,   200,   201,   250,   249,   204,   249,
     247,   207,   208,   209,   210,   211,   212,   250,   250,   250,
     216,   217,   218,   219,   220,   221,   222,   247,   250,   247,
     226,   247,   247,   229,   247,   247,   250,   233,   234,   235,
     236,   237,   238,   251,   251,   250,   250,   243,   251,   249,
     247,   250,    48,   247,   247,   247,   247,    48,   247,    48,
     250,   247,   250,   250,    48,   249,   247,   250,   247,   247,
     250,   247,    47,   250,   451,   200,   201,   250,   247,   204,
     247,   247,   207,   208,   209,   210,   211,   212,   247,   250,
     247,   216,   217,   218,   219,   220,   221,   222,   420,   139,
     246,   226,     1,    -1,   229,     4,     5,     6,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,     1,    -1,    74,     4,     5,     6,    78,
      79,    80,    -1,    -1,    83,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,   101,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,
     229,    -1,    -1,    -1,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,   226,     1,
      -1,   229,     4,     5,     6,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,
       1,    -1,    74,     4,     5,     6,    78,    79,    80,    -1,
      -1,    83,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,
      -1,    -1,   204,    -1,    -1,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,   229,    -1,    -1,
      -1,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,   226,     1,    -1,   229,     4,
       5,     6,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    66,    67,    -1,    69,    -1,    -1,     1,    -1,    74,
       4,     5,     6,    78,    79,    80,    -1,    82,    83,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,   101,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    83,
      -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,   226,    -1,    -1,   229,    -1,    -1,    -1,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,     1,    -1,   229,     4,     5,     6,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    66,    67,
      -1,    69,    -1,    -1,     1,    -1,    74,     4,     5,     6,
      78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,   101,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,   229,    -1,    -1,    -1,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,   226,
       1,    -1,   229,     4,     5,     6,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,     1,    -1,    74,     4,     5,     6,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
     101,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    83,    -1,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,   229,    -1,
      -1,    -1,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,   226,     1,    -1,   229,
       4,     5,     6,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,     1,    -1,
      74,     4,     5,     6,    78,    79,    80,    -1,    -1,    83,
      -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,   101,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      83,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,   229,    -1,    -1,    -1,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,
      -1,   204,    -1,    -1,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,   226,     1,    -1,   229,     4,     5,     6,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,
      67,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,    86,    -1,    -1,   226,
      90,    -1,   229,    93,    -1,    -1,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    21,    -1,    -1,   199,
     200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,   239,
     240,   241,   242,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    21,    -1,    -1,   199,   200,   201,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,   247,    -1,   249,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    21,    -1,    -1,   199,
     200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
     250,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    21,    -1,    -1,   199,   200,   201,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,   250,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    21,    -1,    -1,   199,
     200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
     250,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    21,    -1,    -1,   199,   200,   201,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    21,    -1,    -1,   199,
     200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,   200,   201,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,    -1,    -1,   342,
     343,   344,   345,   346,    -1,    -1,    -1,   350,   351,   352,
     353,   354,   355,    -1,    -1,    -1,    -1,   360,   361,   362,
     363,   364,   365,   366,    -1,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   405,   406,   407,   408,   409,   410,   411,    -1,
     413
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   262,   263,   263,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    53,    54,    55,    62,    66,    67,    69,    74,    78,
      79,    80,    83,    85,    87,    88,    89,    90,    94,    98,
     101,   121,   200,   201,   204,   207,   208,   209,   210,   211,
     212,   216,   217,   218,   219,   220,   221,   222,   226,   229,
     233,   234,   235,   236,   237,   238,   243,   265,   266,   267,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     307,   311,   315,   316,   317,   318,   319,   323,   324,   247,
     243,   200,   201,   204,   207,   208,   209,   210,   211,   212,
     218,   219,   220,   221,   222,   234,   243,   335,   243,    21,
      48,    56,    57,    58,    59,    60,    61,    86,    90,    93,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   199,   200,   201,   204,
     207,   208,   209,   210,   211,   212,   218,   219,   220,   221,
     222,   243,   244,   245,   246,   249,   253,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   336,   243,   270,
     335,   270,   325,   247,   335,   249,   270,   270,   325,   247,
     325,   248,   325,   325,   325,   335,   247,   247,   247,   247,
     243,   335,   335,   335,   335,   243,   243,   243,   249,   243,
     243,   243,   335,   243,   335,   335,   335,   239,   240,   241,
     242,   325,   109,   249,   248,     7,     8,     9,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   106,   200,
     201,   202,   203,   204,   205,   228,   325,   329,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   246,   249,   325,   334,   247,    92,
      91,   248,   256,   257,   258,   259,   260,   234,   252,   253,
     254,   255,   230,   109,   249,   248,   248,   248,   247,   247,
     335,   248,   248,   247,   247,    56,   247,   247,   247,   248,
      75,   320,   321,   264,   247,   247,   247,   247,   247,    49,
     289,    11,    12,    13,    14,    51,   290,   103,   104,   105,
     209,   213,   214,   247,   309,   325,   339,   247,   247,   103,
     247,   234,   247,   196,   197,   197,   325,   325,   325,   249,
     247,   243,   325,   337,   338,   325,    10,   247,   247,   247,
     249,   249,   249,   249,   249,   210,   247,   211,   247,   247,
     247,   247,   249,   249,   249,   249,   249,   249,   249,   247,
     247,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   250,   250,   339,   339,   339,   339,   339,
     250,   250,   250,   339,   339,   339,   250,   339,   250,   339,
     250,   339,   325,   325,   325,   325,   339,   339,   339,   339,
     339,   339,   339,   325,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   325,   325,   325,   325,   243,   250,   335,
     335,   339,   339,   339,   339,   339,   339,   339,   335,   339,
     325,   337,   250,   327,   328,   330,   330,   330,   330,   330,
     330,   330,   331,   331,   332,   332,   332,   243,   325,   325,
     335,   325,   250,   325,   325,   247,   264,   264,   264,   325,
     325,    76,   321,   322,    81,   265,   264,   247,   249,   249,
     249,   249,   249,    52,   247,   104,   209,   247,   309,   249,
     249,   249,   308,   103,   247,   250,   251,   247,   243,   305,
     306,   325,   249,   249,   249,   247,   247,   247,   239,   240,
     241,   250,   250,   251,   247,   249,   244,   244,   244,   244,
     244,   249,   249,   243,   244,   244,   244,   244,   244,   206,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   251,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   251,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   247,   247,   247,   335,   247,   247,   312,    68,    68,
      71,    72,   247,   247,    77,   247,    84,    96,   244,   244,
     244,   244,   246,   249,   293,   249,   249,   308,   247,   231,
     232,   244,   243,   243,   102,   107,   243,   310,   247,   308,
     325,   305,   247,   248,   227,   306,   247,   325,   325,   325,
     250,   250,   250,   109,   247,   325,   254,   250,   250,   250,
     251,   251,   243,   243,   250,   250,   250,   250,   250,   250,
     251,   325,    22,    23,    24,    25,    26,    27,   247,    63,
      64,   313,   314,   247,   247,   325,   325,   264,   264,   247,
     264,   247,   243,   290,   250,   250,   250,   251,   250,   246,
      99,   108,   243,   294,   231,   232,   244,   243,   102,   308,
     251,   251,   250,   250,   250,   251,   247,   243,    11,    12,
      13,    14,   105,   308,   102,   227,   325,   247,   264,   250,
     251,   250,   251,   250,   251,   325,   325,   325,   243,   251,
      29,    30,    43,    44,    45,    49,    50,   104,   215,   268,
      30,    49,   104,   215,   268,    29,    30,    45,    49,   104,
     215,   268,   244,   244,   250,   250,   247,   268,   268,   268,
     268,   268,   246,   251,   250,   250,   250,   250,   250,   250,
     325,   247,    65,    73,   247,    73,   247,    82,   290,   247,
     244,   247,   250,   247,   243,    11,    12,    13,    14,   105,
     251,   251,   250,   250,   251,   247,   102,   244,   244,   103,
     104,   247,   247,   244,    11,    12,    13,    14,   105,   249,
     249,   249,   249,   249,   102,   247,   247,   247,    70,   247,
     325,   198,   247,   325,   198,   247,   325,   247,   247,   247,
     254,    30,   249,   249,    30,   249,   249,   247,   249,   249,
     249,   247,    30,   249,   249,    30,   249,   249,   247,   250,
     250,   247,   247,   247,   247,   247,   247,   247,   250,    22,
      23,    24,    25,    26,    27,   247,   264,   247,   325,   264,
     325,   264,   247,   247,   291,   250,   293,   247,    11,    12,
      13,    14,   249,   249,   249,   249,   249,   244,   244,   247,
     247,   244,   247,   250,   250,   247,   249,   308,   250,   249,
     249,   249,   249,   249,   244,   244,   244,   244,   243,   247,
     247,   250,   249,   250,   249,   250,   250,   249,   325,   243,
     249,   244,   243,   325,   231,   232,   244,   243,   249,   325,
     243,   249,   231,   232,   244,   243,    29,    30,   104,   215,
     268,   268,   247,   250,   250,   250,   250,   250,   250,   264,
     247,    70,   247,    70,   291,    97,   108,   243,   292,    99,
     293,   249,   249,   249,   249,   244,   244,   244,   244,   243,
     250,   250,   308,   308,   250,   103,   103,   308,   244,   102,
     103,   244,   244,   244,   244,   243,   250,   250,   250,   251,
     250,   247,   325,   198,   247,   325,   198,   247,   247,   325,
     250,   250,   325,   250,   250,   250,   251,   251,   250,   250,
     325,   250,   250,   325,   251,   251,   250,   250,    30,   249,
     249,   249,   247,   247,   264,   247,   264,   247,    97,   247,
     243,    11,    12,    13,    14,   105,   247,    99,   244,   244,
     244,   244,   250,   250,   250,   251,   250,   247,   247,   102,
     102,   247,   247,   247,   102,   250,   247,   247,   250,   250,
     250,   251,   250,   207,   208,   247,   247,   207,   208,   247,
     244,   247,   250,   249,   250,   249,   250,   247,   247,   250,
     220,   221,   247,   247,   247,   244,   244,   247,   247,   250,
     247,   247,   250,   244,   244,   220,   221,   247,   247,   249,
     325,   244,   243,    70,    70,   247,   264,    11,    12,    13,
      14,   249,   249,   249,   249,   249,   247,   250,   250,   250,
     251,    46,   100,   247,    46,   100,   247,    46,   100,   247,
     244,   247,   308,   308,   247,   247,   308,   308,   308,   247,
     247,   308,   247,   247,   247,   244,   247,   249,   249,   249,
     249,   250,   247,   325,   247,   325,   247,   247,   247,   247,
     250,   250,   247,   247,   250,   250,   247,   247,   325,   250,
     250,   250,   247,   247,   264,    37,    95,   249,   249,   249,
     249,   244,   244,   244,   244,   243,   100,   247,   100,   247,
     100,   247,   244,   249,    46,   247,   249,    46,   247,   249,
      46,   247,   250,   102,   102,   102,   102,   102,   102,   250,
     243,   244,   243,   244,   208,   247,   250,   250,   247,   247,
     247,   247,   250,   247,   247,   247,    37,    95,   247,   247,
     244,   244,   244,   244,   250,   250,   250,   251,   250,   247,
     247,   247,   250,    47,    48,   249,    47,    48,   249,    47,
      48,   249,    46,   100,   247,   247,   247,   247,   247,   247,
     247,   247,   250,   251,   250,   250,   251,   250,   249,   247,
     247,   247,   247,   247,   264,   250,   250,   250,   251,    46,
     100,   247,    46,   100,   247,    46,   100,   247,   244,   247,
     100,   247,   251,   250,    47,   251,   250,    47,   251,   250,
      47,   249,    46,   247,   247,   244,   247,   247,   244,   247,
     244,   264,    95,   100,   247,   100,   247,   100,   247,   244,
     249,    46,   247,   249,    46,   247,   249,    46,   247,   250,
     247,    48,   247,   250,    48,   247,   250,    48,   247,   250,
      48,   249,   250,   250,   250,    95,   247,   247,   247,   247,
     250,    47,    48,   249,    47,    48,   249,    47,    48,   249,
      46,   100,   247,   250,   247,   250,   247,   250,   247,   250,
      47,   247,   247,   247,   247,   100,   247,   251,   250,    47,
     251,   250,    47,   251,   250,    47,   249,    46,   247,   247,
     247,   247,   247,   250,   247,    48,   247,   250,    48,   247,
     250,    48,   247,   250,    48,   249,   247,   250,   247,   250,
     247,   250,   247,   250,    47,   247,   247,   247,   247,   250,
     247
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   261,   262,   262,   263,   263,   263,   264,   264,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     266,   266,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   268,   268,   268,   268,   269,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   271,   271,   271,
     272,   273,   273,   274,   274,   274,   274,   275,   275,   275,
     275,   276,   276,   276,   276,   276,   276,   276,   277,   278,
     279,   280,   280,   281,   281,   282,   283,   284,   285,   285,
     286,   287,   287,   287,   288,   288,   288,   288,   289,   289,
     290,   290,   290,   290,   290,   291,   291,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   304,   305,   305,   306,   306,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   308,   308,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   311,
     312,   312,   313,   314,   314,   315,   316,   317,   317,   317,
     317,   318,   319,   320,   320,   321,   322,   322,   323,   324,
     325,   326,   326,   327,   327,   328,   328,   329,   329,   329,
     329,   329,   329,   329,   329,   330,   330,   330,   331,   331,
     331,   332,   332,   333,   333,   334,   334,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   337,   337,   338,   338,   339,   339
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,    10,     8,     8,     8,    10,    10,    12,
      12,    14,    11,    11,    13,    11,    12,    12,     4,     4,
       4,     4,     4,     4,    11,    11,    11,    13,    13,    13,
      13,    13,     7,     8,     8,     8,     8,     8,     9,    11,
      11,    12,    12,    12,    12,     8,     8,    11,    11,    11,
      13,     0,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     6,     4,     4,     5,     5,
       5,     9,     7,    13,     9,    11,     7,    13,     9,    11,
       7,     4,     4,     4,     7,     7,     7,     3,     3,     3,
       3,     5,     5,     3,     3,     2,     3,     4,     3,     2,
       5,     7,    11,    10,    13,    14,    16,    17,     0,     1,
       0,     4,     4,     4,     6,     0,     2,     6,     7,     6,
       7,     6,     7,     8,     9,     7,     8,     7,     8,     7,
       8,     9,    10,     6,    11,    11,    11,    13,    10,    10,
      10,    12,    12,    12,    12,     0,     2,     6,     7,     6,
       7,     6,     7,     8,     9,     7,     8,     7,     8,     7,
       8,     9,    10,     6,    11,    11,    11,    13,    10,    10,
      10,    12,    12,    12,    12,     8,     6,     3,     3,     3,
       3,     3,     6,     1,     7,     6,     1,     2,     2,     4,
       7,     6,    11,    11,    13,    13,    13,    13,     7,    11,
      11,    13,    13,    10,     8,     8,     7,     4,     0,     2,
       1,     1,     6,     6,     6,     8,     7,     7,     7,     9,
      10,    10,    12,    10,    12,    10,    12,     6,     7,     8,
       0,     2,     4,     0,     3,     6,     6,    10,    12,    10,
      12,     8,     6,     1,     2,     4,     0,     3,     2,     2,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     6,     4,
       4,     4,     4,     3,     3,     4,     4,     4,     4,     4,
       4,     3,     4,     3,     4,     3,     8,     8,     8,     4,
       4,     4,     3,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     1,     8,     8,
       8,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: KW_FREE statements_opt  */
#line 199 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3243 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 202 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3251 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 209 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3261 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 214 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3272 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 223 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3280 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 226 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3291 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3297 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3303 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3309 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3315 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 239 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3321 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3327 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3333 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 242 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3339 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3345 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3351 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3357 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 246 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3363 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3369 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 248 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3375 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 249 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3381 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 250 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3387 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3393 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3399 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3405 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3411 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3417 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3423 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3429 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3435 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3441 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3447 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3453 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 262 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3459 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 263 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3465 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 264 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3471 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 265 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3477 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 266 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3483 "build/parser.cpp"
    break;

  case 41: /* statement: xml_into_stmt  */
#line 267 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3489 "build/parser.cpp"
    break;

  case 42: /* statement: data_into_stmt  */
#line 268 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3495 "build/parser.cpp"
    break;

  case 43: /* statement: data_gen_stmt  */
#line 269 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3501 "build/parser.cpp"
    break;

  case 44: /* statement: snd_msg_stmt  */
#line 270 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3507 "build/parser.cpp"
    break;

  case 45: /* statement: in_da_stmt  */
#line 271 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3513 "build/parser.cpp"
    break;

  case 46: /* statement: out_da_stmt  */
#line 272 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3519 "build/parser.cpp"
    break;

  case 47: /* statement: unlock_da_stmt  */
#line 273 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3525 "build/parser.cpp"
    break;

  case 48: /* statement: expr_stmt  */
#line 274 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3531 "build/parser.cpp"
    break;

  case 49: /* statement: error SEMICOLON  */
#line 275 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3537 "build/parser.cpp"
    break;

  case 50: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 280 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3546 "build/parser.cpp"
    break;

  case 51: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 284 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3555 "build/parser.cpp"
    break;

  case 52: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 288 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3564 "build/parser.cpp"
    break;

  case 53: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 292 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3573 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 300 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3583 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 305 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3593 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 310 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3603 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 315 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3613 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 320 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3623 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 325 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3633 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 330 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3643 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 335 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3653 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 340 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3663 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 345 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3673 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 350 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3683 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 355 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3693 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 361 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3704 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 367 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3715 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 373 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3724 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 377 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3733 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 381 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3742 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 385 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3751 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 389 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3760 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 393 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3769 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 397 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3778 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 401 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3787 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 405 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3796 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 409 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3805 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 413 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3816 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 419 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3827 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 425 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3838 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 431 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3849 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 437 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3861 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 444 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3871 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 449 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3882 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 455 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3892 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 460 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3902 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 465 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3912 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 470 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3922 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 475 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3932 "build/parser.cpp"
    break;

  case 90: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 480 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3942 "build/parser.cpp"
    break;

  case 91: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 485 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3952 "build/parser.cpp"
    break;

  case 92: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 490 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3962 "build/parser.cpp"
    break;

  case 93: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 495 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3972 "build/parser.cpp"
    break;

  case 94: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 500 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3982 "build/parser.cpp"
    break;

  case 95: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 505 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3992 "build/parser.cpp"
    break;

  case 96: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 510 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 4002 "build/parser.cpp"
    break;

  case 97: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 515 "src/parser.y"
                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 4012 "build/parser.cpp"
    break;

  case 98: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 520 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 4022 "build/parser.cpp"
    break;

  case 99: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 525 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 4032 "build/parser.cpp"
    break;

  case 100: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 530 "src/parser.y"
                                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-11].sval)); free((yyvsp[-2].sval));
    }
#line 4042 "build/parser.cpp"
    break;

  case 101: /* dcl_s_keywords: %empty  */
#line 538 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 4048 "build/parser.cpp"
    break;

  case 102: /* dcl_s_keywords: KW_STATIC  */
#line 539 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 4054 "build/parser.cpp"
    break;

  case 103: /* dcl_s_keywords: KW_TEMPLATE  */
#line 540 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 4060 "build/parser.cpp"
    break;

  case 104: /* dcl_s_keywords: KW_EXPORT  */
#line 541 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 4066 "build/parser.cpp"
    break;

  case 105: /* dcl_s_keywords: KW_IMPORT  */
#line 542 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 4072 "build/parser.cpp"
    break;

  case 106: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 547 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 4081 "build/parser.cpp"
    break;

  case 107: /* eval_target: IDENTIFIER  */
#line 554 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4090 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_POS  */
#line 558 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 4096 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_OVERLAY  */
#line 559 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 4102 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_PREFIX  */
#line 560 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 4108 "build/parser.cpp"
    break;

  case 111: /* eval_target: KW_UNS  */
#line 561 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 4114 "build/parser.cpp"
    break;

  case 112: /* eval_target: KW_FLOAT_TYPE  */
#line 562 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 4120 "build/parser.cpp"
    break;

  case 113: /* eval_target: KW_GRAPH  */
#line 563 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 4126 "build/parser.cpp"
    break;

  case 114: /* eval_target: KW_ASCEND  */
#line 564 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 4132 "build/parser.cpp"
    break;

  case 115: /* eval_target: KW_DESCEND  */
#line 565 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 4138 "build/parser.cpp"
    break;

  case 116: /* eval_target: KW_RTNPARM  */
#line 566 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4144 "build/parser.cpp"
    break;

  case 117: /* eval_target: KW_OPDESC  */
#line 567 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4150 "build/parser.cpp"
    break;

  case 118: /* eval_target: KW_NULLIND  */
#line 568 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4156 "build/parser.cpp"
    break;

  case 119: /* eval_target: KW_DATFMT  */
#line 569 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4162 "build/parser.cpp"
    break;

  case 120: /* eval_target: KW_TIMFMT  */
#line 570 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4168 "build/parser.cpp"
    break;

  case 121: /* eval_target: KW_EXTNAME  */
#line 571 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4174 "build/parser.cpp"
    break;

  case 122: /* eval_target: INDICATOR  */
#line 572 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 4182 "build/parser.cpp"
    break;

  case 123: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 575 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 4193 "build/parser.cpp"
    break;

  case 124: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 581 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 4202 "build/parser.cpp"
    break;

  case 125: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 585 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 4213 "build/parser.cpp"
    break;

  case 126: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 591 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 4221 "build/parser.cpp"
    break;

  case 127: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 597 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4232 "build/parser.cpp"
    break;

  case 128: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 603 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4243 "build/parser.cpp"
    break;

  case 129: /* eval_stmt: KW_EVAL_EXT eval_target EQUALS expression SEMICOLON  */
#line 609 "src/parser.y"
                                                          {
        auto* s = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
        s->extenders = (yyvsp[-4].sval); free((yyvsp[-4].sval));
        (yyval.stmt) = s;
    }
#line 4256 "build/parser.cpp"
    break;

  case 130: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 620 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4266 "build/parser.cpp"
    break;

  case 131: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 628 "src/parser.y"
                                                                                  {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-7].sval));
    }
#line 4277 "build/parser.cpp"
    break;

  case 132: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression RPAREN SEMICOLON  */
#line 634 "src/parser.y"
                                                                   {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-5].sval));
    }
#line 4288 "build/parser.cpp"
    break;

  case 133: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression COLON expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 643 "src/parser.y"
                                                                                                                        {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-11].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 4300 "build/parser.cpp"
    break;

  case 134: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 650 "src/parser.y"
                                                                                      {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-7].sval));
    }
#line 4312 "build/parser.cpp"
    break;

  case 135: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 657 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-9].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            nullptr,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 4324 "build/parser.cpp"
    break;

  case 136: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression RPAREN SEMICOLON  */
#line 664 "src/parser.y"
                                                                     {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr, nullptr);
        free((yyvsp[-5].sval));
    }
#line 4335 "build/parser.cpp"
    break;

  case 137: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression COLON expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 673 "src/parser.y"
                                                                                                                       {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-11].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 4347 "build/parser.cpp"
    break;

  case 138: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 680 "src/parser.y"
                                                                                     {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-7].sval));
    }
#line 4359 "build/parser.cpp"
    break;

  case 139: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 687 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-9].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            nullptr,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 4371 "build/parser.cpp"
    break;

  case 140: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression RPAREN SEMICOLON  */
#line 694 "src/parser.y"
                                                                    {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr, nullptr);
        free((yyvsp[-5].sval));
    }
#line 4382 "build/parser.cpp"
    break;

  case 141: /* snd_msg_stmt: KW_SND_MSG KW_STAR_ESCAPE expression SEMICOLON  */
#line 703 "src/parser.y"
                                                   {
        (yyval.stmt) = new rpg::SndMsgStmt("ESCAPE", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4390 "build/parser.cpp"
    break;

  case 142: /* snd_msg_stmt: KW_SND_MSG KW_STAR_INFO expression SEMICOLON  */
#line 706 "src/parser.y"
                                                   {
        (yyval.stmt) = new rpg::SndMsgStmt("INFO", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4398 "build/parser.cpp"
    break;

  case 143: /* snd_msg_stmt: KW_SND_MSG KW_STAR_DIAG expression SEMICOLON  */
#line 709 "src/parser.y"
                                                   {
        (yyval.stmt) = new rpg::SndMsgStmt("DIAG", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4406 "build/parser.cpp"
    break;

  case 144: /* snd_msg_stmt: KW_SND_MSG KW_TYPE LPAREN KW_STAR_ESCAPE RPAREN expression SEMICOLON  */
#line 712 "src/parser.y"
                                                                           {
        (yyval.stmt) = new rpg::SndMsgStmt("ESCAPE", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4414 "build/parser.cpp"
    break;

  case 145: /* snd_msg_stmt: KW_SND_MSG KW_TYPE LPAREN KW_STAR_INFO RPAREN expression SEMICOLON  */
#line 715 "src/parser.y"
                                                                         {
        (yyval.stmt) = new rpg::SndMsgStmt("INFO", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4422 "build/parser.cpp"
    break;

  case 146: /* snd_msg_stmt: KW_SND_MSG KW_TYPE LPAREN KW_STAR_DIAG RPAREN expression SEMICOLON  */
#line 718 "src/parser.y"
                                                                         {
        (yyval.stmt) = new rpg::SndMsgStmt("DIAG", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4430 "build/parser.cpp"
    break;

  case 147: /* snd_msg_stmt: KW_SND_MSG expression SEMICOLON  */
#line 721 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::SndMsgStmt("INFO", std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4438 "build/parser.cpp"
    break;

  case 148: /* in_da_stmt: KW_IN IDENTIFIER SEMICOLON  */
#line 727 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DataInStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4447 "build/parser.cpp"
    break;

  case 149: /* out_da_stmt: KW_OUT IDENTIFIER SEMICOLON  */
#line 734 "src/parser.y"
                                {
        (yyval.stmt) = new rpg::DataOutStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4456 "build/parser.cpp"
    break;

  case 150: /* unlock_da_stmt: KW_UNLOCK IDENTIFIER SEMICOLON  */
#line 741 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::DataUnlockStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4465 "build/parser.cpp"
    break;

  case 151: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 748 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4476 "build/parser.cpp"
    break;

  case 152: /* evalr_stmt: KW_EVALR_EXT eval_target EQUALS expression SEMICOLON  */
#line 754 "src/parser.y"
                                                           {
        auto* s = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
        s->extenders = (yyvsp[-4].sval); free((yyvsp[-4].sval));
        (yyval.stmt) = s;
    }
#line 4489 "build/parser.cpp"
    break;

  case 153: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 765 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), "");
    }
#line 4497 "build/parser.cpp"
    break;

  case 154: /* callp_stmt: KW_CALLP_EXT expression SEMICOLON  */
#line 768 "src/parser.y"
                                        {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), (yyvsp[-2].sval));
        free((yyvsp[-2].sval));
    }
#line 4506 "build/parser.cpp"
    break;

  case 155: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 775 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4514 "build/parser.cpp"
    break;

  case 156: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 781 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4522 "build/parser.cpp"
    break;

  case 157: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 787 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4530 "build/parser.cpp"
    break;

  case 158: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 793 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4538 "build/parser.cpp"
    break;

  case 159: /* return_stmt: KW_RETURN SEMICOLON  */
#line 796 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4546 "build/parser.cpp"
    break;

  case 160: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 803 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4556 "build/parser.cpp"
    break;

  case 161: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 814 "src/parser.y"
                                                                                {
        rpg::ProcInterface iface;
        if ((yyvsp[-4].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-4].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-2].param_list)->params);
        delete (yyvsp[-2].param_list);
        (yyval.stmt) = new rpg::DclPR((yyvsp[-5].sval), std::move(iface));
        free((yyvsp[-5].sval));
    }
#line 4577 "build/parser.cpp"
    break;

  case 162: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 831 "src/parser.y"
                                                                                                                          {
        rpg::ProcInterface iface;
        if ((yyvsp[-8].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-8].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-2].param_list)->params);
        delete (yyvsp[-2].param_list);
        auto* pr = new rpg::DclPR((yyvsp[-9].sval), std::move(iface));
        pr->extproc = (yyvsp[-5].sval);
        free((yyvsp[-9].sval));
        free((yyvsp[-5].sval));
        (yyval.stmt) = pr;
    }
#line 4601 "build/parser.cpp"
    break;

  case 163: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 851 "src/parser.y"
                                                                                                          {
        rpg::ProcInterface iface;
        iface.has_return = false;
        iface.params = std::move((yyvsp[-2].param_list)->params);
        delete (yyvsp[-2].param_list);
        auto* pr = new rpg::DclPR((yyvsp[-8].sval), std::move(iface));
        pr->extpgm = (yyvsp[-5].sval);
        free((yyvsp[-8].sval));
        free((yyvsp[-5].sval));
        (yyval.stmt) = pr;
    }
#line 4617 "build/parser.cpp"
    break;

  case 164: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 869 "src/parser.y"
                          {
        rpg::ProcInterface iface;
        if ((yyvsp[-7].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-7].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-5].param_list)->params);
        delete (yyvsp[-5].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-11].sval), std::move(iface));
        proc->is_export = ((yyvsp[-10].ival) != 0);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = proc;
    }
#line 4642 "build/parser.cpp"
    break;

  case 165: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 893 "src/parser.y"
                            {
        rpg::ProcInterface iface;
        if ((yyvsp[-7].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-7].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-5].param_list)->params);
        delete (yyvsp[-5].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-12].sval), std::move(iface));
        proc->is_export = ((yyvsp[-11].ival) != 0);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-12].sval));
        free((yyvsp[-8].sval));
        (yyval.stmt) = proc;
    }
#line 4668 "build/parser.cpp"
    break;

  case 166: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 919 "src/parser.y"
                            {
        rpg::ProcInterface iface;
        if ((yyvsp[-10].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-10].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-8].param_list)->params);
        delete (yyvsp[-8].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-14].sval), std::move(iface));
        proc->is_export = ((yyvsp[-13].ival) != 0);
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->on_exit_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-14].sval));
        (yyval.stmt) = proc;
    }
#line 4695 "build/parser.cpp"
    break;

  case 167: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 946 "src/parser.y"
                            {
        rpg::ProcInterface iface;
        if ((yyvsp[-10].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-10].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-8].param_list)->params);
        delete (yyvsp[-8].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-15].sval), std::move(iface));
        proc->is_export = ((yyvsp[-14].ival) != 0);
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->on_exit_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-15].sval));
        free((yyvsp[-11].sval));
        (yyval.stmt) = proc;
    }
#line 4723 "build/parser.cpp"
    break;

  case 168: /* proc_export: %empty  */
#line 972 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4729 "build/parser.cpp"
    break;

  case 169: /* proc_export: KW_EXPORT  */
#line 973 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4735 "build/parser.cpp"
    break;

  case 170: /* pi_return_type: %empty  */
#line 978 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4741 "build/parser.cpp"
    break;

  case 171: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 979 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4747 "build/parser.cpp"
    break;

  case 172: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 980 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4753 "build/parser.cpp"
    break;

  case 173: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 981 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4759 "build/parser.cpp"
    break;

  case 174: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 982 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4765 "build/parser.cpp"
    break;

  case 175: /* pi_params: %empty  */
#line 987 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4773 "build/parser.cpp"
    break;

  case 176: /* pi_params: pi_params pi_param  */
#line 990 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4783 "build/parser.cpp"
    break;

  case 177: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 998 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4792 "build/parser.cpp"
    break;

  case 178: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1002 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4801 "build/parser.cpp"
    break;

  case 179: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1006 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4810 "build/parser.cpp"
    break;

  case 180: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1010 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4819 "build/parser.cpp"
    break;

  case 181: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1014 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4828 "build/parser.cpp"
    break;

  case 182: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1018 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4837 "build/parser.cpp"
    break;

  case 183: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1022 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4846 "build/parser.cpp"
    break;

  case 184: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1026 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4855 "build/parser.cpp"
    break;

  case 185: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1031 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4864 "build/parser.cpp"
    break;

  case 186: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1035 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4873 "build/parser.cpp"
    break;

  case 187: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1039 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4882 "build/parser.cpp"
    break;

  case 188: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1043 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4891 "build/parser.cpp"
    break;

  case 189: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1047 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4900 "build/parser.cpp"
    break;

  case 190: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1051 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4909 "build/parser.cpp"
    break;

  case 191: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1055 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4918 "build/parser.cpp"
    break;

  case 192: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1059 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4927 "build/parser.cpp"
    break;

  case 193: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1063 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4937 "build/parser.cpp"
    break;

  case 194: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1069 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4947 "build/parser.cpp"
    break;

  case 195: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1074 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4957 "build/parser.cpp"
    break;

  case 196: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1079 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4967 "build/parser.cpp"
    break;

  case 197: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1084 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4977 "build/parser.cpp"
    break;

  case 198: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1090 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4987 "build/parser.cpp"
    break;

  case 199: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1095 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4997 "build/parser.cpp"
    break;

  case 200: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1100 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5007 "build/parser.cpp"
    break;

  case 201: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1105 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5017 "build/parser.cpp"
    break;

  case 202: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1111 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5027 "build/parser.cpp"
    break;

  case 203: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1116 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5037 "build/parser.cpp"
    break;

  case 204: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1121 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5047 "build/parser.cpp"
    break;

  case 205: /* pr_params: %empty  */
#line 1130 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 5055 "build/parser.cpp"
    break;

  case 206: /* pr_params: pr_params pr_param  */
#line 1133 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 5065 "build/parser.cpp"
    break;

  case 207: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1141 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5074 "build/parser.cpp"
    break;

  case 208: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1145 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5083 "build/parser.cpp"
    break;

  case 209: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1149 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5092 "build/parser.cpp"
    break;

  case 210: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1153 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5101 "build/parser.cpp"
    break;

  case 211: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1157 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5110 "build/parser.cpp"
    break;

  case 212: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1161 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5119 "build/parser.cpp"
    break;

  case 213: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1165 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 5128 "build/parser.cpp"
    break;

  case 214: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1169 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 5137 "build/parser.cpp"
    break;

  case 215: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1174 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5146 "build/parser.cpp"
    break;

  case 216: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1178 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5155 "build/parser.cpp"
    break;

  case 217: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1182 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5164 "build/parser.cpp"
    break;

  case 218: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1186 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5173 "build/parser.cpp"
    break;

  case 219: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1190 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5182 "build/parser.cpp"
    break;

  case 220: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1194 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5191 "build/parser.cpp"
    break;

  case 221: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1198 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 5200 "build/parser.cpp"
    break;

  case 222: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1202 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 5209 "build/parser.cpp"
    break;

  case 223: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1206 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 5219 "build/parser.cpp"
    break;

  case 224: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1212 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5229 "build/parser.cpp"
    break;

  case 225: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1217 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5239 "build/parser.cpp"
    break;

  case 226: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1222 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5249 "build/parser.cpp"
    break;

  case 227: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1227 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 5259 "build/parser.cpp"
    break;

  case 228: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1233 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5269 "build/parser.cpp"
    break;

  case 229: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1238 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5279 "build/parser.cpp"
    break;

  case 230: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1243 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5289 "build/parser.cpp"
    break;

  case 231: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1248 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5299 "build/parser.cpp"
    break;

  case 232: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1254 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5309 "build/parser.cpp"
    break;

  case 233: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1259 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5319 "build/parser.cpp"
    break;

  case 234: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1264 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5329 "build/parser.cpp"
    break;

  case 235: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1274 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5342 "build/parser.cpp"
    break;

  case 236: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1285 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 5354 "build/parser.cpp"
    break;

  case 237: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1295 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5363 "build/parser.cpp"
    break;

  case 238: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1303 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5372 "build/parser.cpp"
    break;

  case 239: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1311 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5381 "build/parser.cpp"
    break;

  case 240: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1318 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5390 "build/parser.cpp"
    break;

  case 241: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1326 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5399 "build/parser.cpp"
    break;

  case 242: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1334 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 5410 "build/parser.cpp"
    break;

  case 243: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1345 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 5420 "build/parser.cpp"
    break;

  case 244: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1355 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 5433 "build/parser.cpp"
    break;

  case 245: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1363 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 5446 "build/parser.cpp"
    break;

  case 246: /* enum_constants: enum_constant  */
#line 1374 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 5454 "build/parser.cpp"
    break;

  case 247: /* enum_constants: enum_constants enum_constant  */
#line 1377 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 5464 "build/parser.cpp"
    break;

  case 248: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1385 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5477 "build/parser.cpp"
    break;

  case 249: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1393 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5491 "build/parser.cpp"
    break;

  case 250: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1408 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5504 "build/parser.cpp"
    break;

  case 251: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1417 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 5517 "build/parser.cpp"
    break;

  case 252: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1426 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5531 "build/parser.cpp"
    break;

  case 253: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1436 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5545 "build/parser.cpp"
    break;

  case 254: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1446 "src/parser.y"
                                                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->dim_type = 1;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5560 "build/parser.cpp"
    break;

  case 255: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1457 "src/parser.y"
                                                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->dim_type = 1;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5575 "build/parser.cpp"
    break;

  case 256: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1468 "src/parser.y"
                                                                                                                                       {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->dim_type = 2;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5590 "build/parser.cpp"
    break;

  case 257: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1479 "src/parser.y"
                                                                                                                                       {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->dim_type = 2;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5605 "build/parser.cpp"
    break;

  case 258: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1490 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5617 "build/parser.cpp"
    break;

  case 259: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1498 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5630 "build/parser.cpp"
    break;

  case 260: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1507 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5644 "build/parser.cpp"
    break;

  case 261: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1517 "src/parser.y"
                                                                                                                                         {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-8].sval);
        ds->prefix_nbr = (yyvsp[-6].ival);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval)); free((yyvsp[-8].sval));
        (yyval.stmt) = ds;
    }
#line 5659 "build/parser.cpp"
    break;

  case 262: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1528 "src/parser.y"
                                                                                                                                         {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-7].sval);
        ds->prefix_nbr = (yyvsp[-5].ival);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval)); free((yyvsp[-7].sval));
        (yyval.stmt) = ds;
    }
#line 5674 "build/parser.cpp"
    break;

  case 263: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1539 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5688 "build/parser.cpp"
    break;

  case 264: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1549 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5702 "build/parser.cpp"
    break;

  case 265: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1559 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5716 "build/parser.cpp"
    break;

  case 266: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1569 "src/parser.y"
                                                                           {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->is_psds = true;
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5730 "build/parser.cpp"
    break;

  case 267: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON  */
#line 1579 "src/parser.y"
                                             {
        auto* ds = new rpg::DclDS((yyvsp[-2].sval));
        ds->is_psds = true;
        ds->qualified = false;
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5742 "build/parser.cpp"
    break;

  case 268: /* ds_fields: %empty  */
#line 1589 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5750 "build/parser.cpp"
    break;

  case 269: /* ds_fields: ds_fields ds_field  */
#line 1592 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5760 "build/parser.cpp"
    break;

  case 270: /* psds_kw: KW_PSDS  */
#line 1600 "src/parser.y"
            {}
#line 5766 "build/parser.cpp"
    break;

  case 271: /* psds_kw: KW_SDS  */
#line 1601 "src/parser.y"
             {}
#line 5772 "build/parser.cpp"
    break;

  case 272: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1605 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5781 "build/parser.cpp"
    break;

  case 273: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1609 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5790 "build/parser.cpp"
    break;

  case 274: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1613 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5799 "build/parser.cpp"
    break;

  case 275: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1617 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5808 "build/parser.cpp"
    break;

  case 276: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1622 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5817 "build/parser.cpp"
    break;

  case 277: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1626 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5826 "build/parser.cpp"
    break;

  case 278: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1630 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5835 "build/parser.cpp"
    break;

  case 279: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1634 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5844 "build/parser.cpp"
    break;

  case 280: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1639 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5855 "build/parser.cpp"
    break;

  case 281: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1645 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5866 "build/parser.cpp"
    break;

  case 282: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1651 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5877 "build/parser.cpp"
    break;

  case 283: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1658 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5888 "build/parser.cpp"
    break;

  case 284: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1665 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5900 "build/parser.cpp"
    break;

  case 285: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1672 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5911 "build/parser.cpp"
    break;

  case 286: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1678 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5923 "build/parser.cpp"
    break;

  case 287: /* ds_field: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1686 "src/parser.y"
                                                              {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5934 "build/parser.cpp"
    break;

  case 288: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1692 "src/parser.y"
                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5945 "build/parser.cpp"
    break;

  case 289: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1703 "src/parser.y"
                                                                                            {
        auto* node = new rpg::IfStmt(std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)));
        for (auto* s : (yyvsp[-4].stmt_list)->stmts) node->then_body.emplace_back(s);
        delete (yyvsp[-4].stmt_list);
        if ((yyvsp[-3].elseif_list)) {
            for (auto* eif : *(yyvsp[-3].elseif_list)) {
                rpg::ElseIfBranch branch;
                branch.condition.reset(eif->cond);
                for (auto* s : eif->body) branch.body.emplace_back(s);
                node->elseif_branches.push_back(std::move(branch));
                delete eif;
            }
            delete (yyvsp[-3].elseif_list);
        }
        if ((yyvsp[-2].stmt_list)) {
            for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->else_body.emplace_back(s);
            delete (yyvsp[-2].stmt_list);
        }
        (yyval.stmt) = node;
    }
#line 5970 "build/parser.cpp"
    break;

  case 290: /* elseif_clauses: %empty  */
#line 1726 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5976 "build/parser.cpp"
    break;

  case 291: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1727 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5986 "build/parser.cpp"
    break;

  case 292: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1735 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5997 "build/parser.cpp"
    break;

  case 293: /* else_clause: %empty  */
#line 1744 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 6003 "build/parser.cpp"
    break;

  case 294: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1745 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 6011 "build/parser.cpp"
    break;

  case 295: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1751 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 6022 "build/parser.cpp"
    break;

  case 296: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1760 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 6033 "build/parser.cpp"
    break;

  case 297: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1769 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::ForStmt((yyvsp[-8].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            nullptr, false);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-8].sval));
        (yyval.stmt) = node;
    }
#line 6048 "build/parser.cpp"
    break;

  case 298: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1779 "src/parser.y"
                                                                                                                    {
        auto* node = new rpg::ForStmt((yyvsp[-10].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)), false);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-10].sval));
        (yyval.stmt) = node;
    }
#line 6063 "build/parser.cpp"
    break;

  case 299: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1789 "src/parser.y"
                                                                                                       {
        auto* node = new rpg::ForStmt((yyvsp[-8].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            nullptr, true);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-8].sval));
        (yyval.stmt) = node;
    }
#line 6078 "build/parser.cpp"
    break;

  case 300: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1799 "src/parser.y"
                                                                                                                        {
        auto* node = new rpg::ForStmt((yyvsp[-10].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)), true);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-10].sval));
        (yyval.stmt) = node;
    }
#line 6093 "build/parser.cpp"
    break;

  case 301: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1812 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 6105 "build/parser.cpp"
    break;

  case 302: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1822 "src/parser.y"
                                                                     {
        auto* node = new rpg::SelectStmt();
        for (auto* w : *(yyvsp[-3].when_list)) {
            rpg::WhenBranch branch;
            branch.condition.reset(w->cond);
            for (auto* s : w->body) branch.body.emplace_back(s);
            node->when_branches.push_back(std::move(branch));
            delete w;
        }
        delete (yyvsp[-3].when_list);
        if ((yyvsp[-2].stmt_list)) {
            for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->other_body.emplace_back(s);
            delete (yyvsp[-2].stmt_list);
        }
        (yyval.stmt) = node;
    }
#line 6126 "build/parser.cpp"
    break;

  case 303: /* when_clauses: when_clause  */
#line 1841 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 6135 "build/parser.cpp"
    break;

  case 304: /* when_clauses: when_clauses when_clause  */
#line 1845 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 6144 "build/parser.cpp"
    break;

  case 305: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1852 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 6155 "build/parser.cpp"
    break;

  case 306: /* other_clause: %empty  */
#line 1861 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 6161 "build/parser.cpp"
    break;

  case 307: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1862 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 6169 "build/parser.cpp"
    break;

  case 308: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1868 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 6175 "build/parser.cpp"
    break;

  case 309: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1872 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 6181 "build/parser.cpp"
    break;

  case 310: /* expression: or_expr  */
#line 1878 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 6187 "build/parser.cpp"
    break;

  case 311: /* or_expr: and_expr  */
#line 1882 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 6193 "build/parser.cpp"
    break;

  case 312: /* or_expr: or_expr KW_OR and_expr  */
#line 1883 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6203 "build/parser.cpp"
    break;

  case 313: /* and_expr: not_expr  */
#line 1891 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 6209 "build/parser.cpp"
    break;

  case 314: /* and_expr: and_expr KW_AND not_expr  */
#line 1892 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6219 "build/parser.cpp"
    break;

  case 315: /* not_expr: comparison_expr  */
#line 1900 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 6225 "build/parser.cpp"
    break;

  case 316: /* not_expr: KW_NOT comparison_expr  */
#line 1901 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6233 "build/parser.cpp"
    break;

  case 317: /* comparison_expr: additive_expr  */
#line 1907 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 6239 "build/parser.cpp"
    break;

  case 318: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1908 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6249 "build/parser.cpp"
    break;

  case 319: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1913 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6259 "build/parser.cpp"
    break;

  case 320: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1918 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6269 "build/parser.cpp"
    break;

  case 321: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1923 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6279 "build/parser.cpp"
    break;

  case 322: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1928 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6289 "build/parser.cpp"
    break;

  case 323: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1933 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6299 "build/parser.cpp"
    break;

  case 324: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1938 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6309 "build/parser.cpp"
    break;

  case 325: /* additive_expr: multiplicative_expr  */
#line 1946 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 6315 "build/parser.cpp"
    break;

  case 326: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1947 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6325 "build/parser.cpp"
    break;

  case 327: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1952 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6335 "build/parser.cpp"
    break;

  case 328: /* multiplicative_expr: power_expr  */
#line 1960 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6341 "build/parser.cpp"
    break;

  case 329: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1961 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6351 "build/parser.cpp"
    break;

  case 330: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1966 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6361 "build/parser.cpp"
    break;

  case 331: /* power_expr: unary_expr  */
#line 1974 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6367 "build/parser.cpp"
    break;

  case 332: /* power_expr: unary_expr POWER power_expr  */
#line 1975 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6377 "build/parser.cpp"
    break;

  case 333: /* unary_expr: postfix_expr  */
#line 1983 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6383 "build/parser.cpp"
    break;

  case 334: /* unary_expr: MINUS postfix_expr  */
#line 1984 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6393 "build/parser.cpp"
    break;

  case 335: /* postfix_expr: primary_expr  */
#line 1992 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6399 "build/parser.cpp"
    break;

  case 336: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1993 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6408 "build/parser.cpp"
    break;

  case 337: /* ident: IDENTIFIER  */
#line 2000 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 6414 "build/parser.cpp"
    break;

  case 338: /* ident: KW_UNS  */
#line 2001 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 6420 "build/parser.cpp"
    break;

  case 339: /* ident: KW_FLOAT_TYPE  */
#line 2002 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 6426 "build/parser.cpp"
    break;

  case 340: /* ident: KW_GRAPH  */
#line 2003 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 6432 "build/parser.cpp"
    break;

  case 341: /* ident: KW_ASCEND  */
#line 2004 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 6438 "build/parser.cpp"
    break;

  case 342: /* ident: KW_DESCEND  */
#line 2005 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 6444 "build/parser.cpp"
    break;

  case 343: /* ident: KW_IN  */
#line 2006 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 6450 "build/parser.cpp"
    break;

  case 344: /* ident: KW_RTNPARM  */
#line 2007 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 6456 "build/parser.cpp"
    break;

  case 345: /* ident: KW_OPDESC  */
#line 2008 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 6462 "build/parser.cpp"
    break;

  case 346: /* ident: KW_NULLIND  */
#line 2009 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 6468 "build/parser.cpp"
    break;

  case 347: /* ident: KW_DATFMT  */
#line 2010 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 6474 "build/parser.cpp"
    break;

  case 348: /* ident: KW_TIMFMT  */
#line 2011 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 6480 "build/parser.cpp"
    break;

  case 349: /* ident: KW_EXTNAME  */
#line 2012 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 6486 "build/parser.cpp"
    break;

  case 350: /* ident: KW_OVERLAY  */
#line 2013 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 6492 "build/parser.cpp"
    break;

  case 351: /* ident: KW_POS  */
#line 2014 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 6498 "build/parser.cpp"
    break;

  case 352: /* ident: KW_PREFIX  */
#line 2015 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 6504 "build/parser.cpp"
    break;

  case 353: /* primary_expr: IDENTIFIER  */
#line 2019 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6513 "build/parser.cpp"
    break;

  case 354: /* primary_expr: KW_UNS  */
#line 2023 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 6519 "build/parser.cpp"
    break;

  case 355: /* primary_expr: KW_FLOAT_TYPE  */
#line 2024 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 6525 "build/parser.cpp"
    break;

  case 356: /* primary_expr: KW_GRAPH  */
#line 2025 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 6531 "build/parser.cpp"
    break;

  case 357: /* primary_expr: KW_ASCEND  */
#line 2026 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 6537 "build/parser.cpp"
    break;

  case 358: /* primary_expr: KW_DESCEND  */
#line 2027 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 6543 "build/parser.cpp"
    break;

  case 359: /* primary_expr: KW_RTNPARM  */
#line 2028 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 6549 "build/parser.cpp"
    break;

  case 360: /* primary_expr: KW_OPDESC  */
#line 2029 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 6555 "build/parser.cpp"
    break;

  case 361: /* primary_expr: KW_NULLIND  */
#line 2030 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 6561 "build/parser.cpp"
    break;

  case 362: /* primary_expr: KW_DATFMT  */
#line 2031 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 6567 "build/parser.cpp"
    break;

  case 363: /* primary_expr: KW_OVERLAY  */
#line 2032 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 6573 "build/parser.cpp"
    break;

  case 364: /* primary_expr: KW_POS  */
#line 2033 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 6579 "build/parser.cpp"
    break;

  case 365: /* primary_expr: KW_PREFIX  */
#line 2034 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 6585 "build/parser.cpp"
    break;

  case 366: /* primary_expr: KW_TIMFMT  */
#line 2035 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 6591 "build/parser.cpp"
    break;

  case 367: /* primary_expr: KW_EXTNAME  */
#line 2036 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 6597 "build/parser.cpp"
    break;

  case 368: /* primary_expr: INTEGER_LITERAL  */
#line 2037 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6605 "build/parser.cpp"
    break;

  case 369: /* primary_expr: FLOAT_LITERAL  */
#line 2040 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6613 "build/parser.cpp"
    break;

  case 370: /* primary_expr: STRING_LITERAL  */
#line 2043 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6622 "build/parser.cpp"
    break;

  case 371: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 2047 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6631 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 2051 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6639 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 2054 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6647 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 2057 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6655 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 2060 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6663 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 2063 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6671 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 2066 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6679 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 2069 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6687 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 2072 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6695 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 2075 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6703 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 2078 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6711 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 2081 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6719 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 2084 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6727 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 2087 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6736 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 2091 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6744 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 2094 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6752 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 2097 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6760 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 2100 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6768 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 2103 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6776 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 2106 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6784 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 2109 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6792 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 2112 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6800 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 2115 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6811 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 2121 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6822 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 2127 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6833 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 2133 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6844 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 2139 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6855 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 2145 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6866 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 2151 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6874 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 2154 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6882 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 2157 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6890 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 2160 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6898 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 2163 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6907 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 2167 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6916 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 2171 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6924 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 2174 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6932 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 2177 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6940 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 2180 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6948 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 2183 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6956 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 2186 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6964 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 2189 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6973 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 2193 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6981 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 2196 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6990 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 2200 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6998 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 2203 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 7007 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 2207 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7019 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 2214 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7031 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 2221 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7043 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2228 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 7053 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2233 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 7063 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2238 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 7073 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2243 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 7082 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2247 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 7091 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2251 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 7099 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2254 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 7107 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2257 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 7115 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2260 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 7123 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2263 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 7131 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2266 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 7139 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2269 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 7147 "build/parser.cpp"
    break;

  case 431: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2272 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 7155 "build/parser.cpp"
    break;

  case 432: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2275 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 7163 "build/parser.cpp"
    break;

  case 433: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2278 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 7171 "build/parser.cpp"
    break;

  case 434: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2281 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 7179 "build/parser.cpp"
    break;

  case 435: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2284 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 7187 "build/parser.cpp"
    break;

  case 436: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2287 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 7195 "build/parser.cpp"
    break;

  case 437: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2290 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 7203 "build/parser.cpp"
    break;

  case 438: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2293 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 7211 "build/parser.cpp"
    break;

  case 439: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2296 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 7219 "build/parser.cpp"
    break;

  case 440: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2299 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 7227 "build/parser.cpp"
    break;

  case 441: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2302 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 7235 "build/parser.cpp"
    break;

  case 442: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2305 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 7243 "build/parser.cpp"
    break;

  case 443: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2308 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7251 "build/parser.cpp"
    break;

  case 444: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2311 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7259 "build/parser.cpp"
    break;

  case 445: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2314 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 7267 "build/parser.cpp"
    break;

  case 446: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2317 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 7275 "build/parser.cpp"
    break;

  case 447: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2320 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 7283 "build/parser.cpp"
    break;

  case 448: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2323 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 7291 "build/parser.cpp"
    break;

  case 449: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2326 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7299 "build/parser.cpp"
    break;

  case 450: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2329 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7307 "build/parser.cpp"
    break;

  case 451: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2332 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 7317 "build/parser.cpp"
    break;

  case 452: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2337 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 7327 "build/parser.cpp"
    break;

  case 453: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2342 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 7337 "build/parser.cpp"
    break;

  case 454: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2347 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 7347 "build/parser.cpp"
    break;

  case 455: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2352 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 7358 "build/parser.cpp"
    break;

  case 456: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2358 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7367 "build/parser.cpp"
    break;

  case 457: /* primary_expr: BIF_PROC  */
#line 2362 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7376 "build/parser.cpp"
    break;

  case 458: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2366 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7388 "build/parser.cpp"
    break;

  case 459: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2373 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7400 "build/parser.cpp"
    break;

  case 460: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2380 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7412 "build/parser.cpp"
    break;

  case 461: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2387 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 7423 "build/parser.cpp"
    break;

  case 462: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2393 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 7434 "build/parser.cpp"
    break;

  case 463: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2399 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 7445 "build/parser.cpp"
    break;

  case 464: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2405 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 7453 "build/parser.cpp"
    break;

  case 465: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2408 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 7461 "build/parser.cpp"
    break;

  case 466: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2411 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 7469 "build/parser.cpp"
    break;

  case 467: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2414 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 7477 "build/parser.cpp"
    break;

  case 468: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2417 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 7485 "build/parser.cpp"
    break;

  case 469: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2420 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 7493 "build/parser.cpp"
    break;

  case 470: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2423 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 7501 "build/parser.cpp"
    break;

  case 471: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2426 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 7512 "build/parser.cpp"
    break;

  case 472: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2432 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 7520 "build/parser.cpp"
    break;

  case 473: /* primary_expr: INDICATOR  */
#line 2435 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 7528 "build/parser.cpp"
    break;

  case 474: /* primary_expr: KW_ON  */
#line 2438 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 7536 "build/parser.cpp"
    break;

  case 475: /* primary_expr: KW_OFF  */
#line 2441 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 7544 "build/parser.cpp"
    break;

  case 476: /* primary_expr: KW_NULL  */
#line 2444 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7552 "build/parser.cpp"
    break;

  case 477: /* primary_expr: KW_OMIT  */
#line 2447 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7560 "build/parser.cpp"
    break;

  case 478: /* primary_expr: KW_USER  */
#line 2450 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("RPG_USER");
        if (g_program) g_program->uses_user_const = true;
    }
#line 7569 "build/parser.cpp"
    break;

  case 479: /* primary_expr: KW_BLANKS  */
#line 2454 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 7577 "build/parser.cpp"
    break;

  case 480: /* primary_expr: KW_ZEROS  */
#line 2457 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 7585 "build/parser.cpp"
    break;

  case 481: /* primary_expr: KW_HIVAL  */
#line 2460 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 7593 "build/parser.cpp"
    break;

  case 482: /* primary_expr: KW_LOVAL  */
#line 2463 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 7601 "build/parser.cpp"
    break;

  case 483: /* primary_expr: LPAREN expression RPAREN  */
#line 2466 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 7609 "build/parser.cpp"
    break;

  case 484: /* call_args_opt: %empty  */
#line 2473 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 7615 "build/parser.cpp"
    break;

  case 485: /* call_args_opt: call_arg_list  */
#line 2474 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7621 "build/parser.cpp"
    break;

  case 486: /* call_arg_list: expression  */
#line 2478 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7630 "build/parser.cpp"
    break;

  case 487: /* call_arg_list: call_arg_list COLON expression  */
#line 2482 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7639 "build/parser.cpp"
    break;

  case 488: /* arg_list: expression  */
#line 2490 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7648 "build/parser.cpp"
    break;

  case 489: /* arg_list: arg_list COLON expression  */
#line 2494 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7657 "build/parser.cpp"
    break;


#line 7661 "build/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2500 "src/parser.y"


void yyerror(const char* s) {
    g_error_count++;
    const char* token = yytext;
    if (token == NULL || token[0] == '\0') {
        fprintf(stderr, "Error at line %d: %s (unexpected end of file)\n", yylineno, s);
    } else {
        fprintf(stderr, "Error at line %d: %s (near '%s')\n", yylineno, s, token);
    }
}

rpg::Program* get_parsed_program() {
    g_program = new rpg::Program();
    g_error_count = 0;
    yyparse();
    return g_program;
}

int get_parse_error_count() {
    return g_error_count;
}
