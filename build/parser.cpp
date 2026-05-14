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
  YYSYMBOL_IDENTIFIER = 238,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 239,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 240,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 241,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 242,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 243,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 244,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 245,                   /* RPAREN  */
  YYSYMBOL_COLON = 246,                    /* COLON  */
  YYSYMBOL_PLUS = 247,                     /* PLUS  */
  YYSYMBOL_MINUS = 248,                    /* MINUS  */
  YYSYMBOL_STAR = 249,                     /* STAR  */
  YYSYMBOL_SLASH = 250,                    /* SLASH  */
  YYSYMBOL_NE = 251,                       /* NE  */
  YYSYMBOL_LE = 252,                       /* LE  */
  YYSYMBOL_GE = 253,                       /* GE  */
  YYSYMBOL_LT = 254,                       /* LT  */
  YYSYMBOL_GT = 255,                       /* GT  */
  YYSYMBOL_YYACCEPT = 256,                 /* $accept  */
  YYSYMBOL_program = 257,                  /* program  */
  YYSYMBOL_statements_opt = 258,           /* statements_opt  */
  YYSYMBOL_statement_list = 259,           /* statement_list  */
  YYSYMBOL_statement = 260,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 261,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 262,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 263,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 264,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 265,              /* eval_target  */
  YYSYMBOL_eval_stmt = 266,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 267,           /* eval_corr_stmt  */
  YYSYMBOL_xml_into_stmt = 268,            /* xml_into_stmt  */
  YYSYMBOL_data_into_stmt = 269,           /* data_into_stmt  */
  YYSYMBOL_data_gen_stmt = 270,            /* data_gen_stmt  */
  YYSYMBOL_in_da_stmt = 271,               /* in_da_stmt  */
  YYSYMBOL_out_da_stmt = 272,              /* out_da_stmt  */
  YYSYMBOL_unlock_da_stmt = 273,           /* unlock_da_stmt  */
  YYSYMBOL_evalr_stmt = 274,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 275,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 276,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 277,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 278,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 279,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 280,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 281,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 282,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 283,              /* proc_export  */
  YYSYMBOL_pi_return_type = 284,           /* pi_return_type  */
  YYSYMBOL_pi_params = 285,                /* pi_params  */
  YYSYMBOL_pi_param = 286,                 /* pi_param  */
  YYSYMBOL_pr_params = 287,                /* pr_params  */
  YYSYMBOL_pr_param = 288,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 289,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 290,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 291,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 292,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 293,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 294,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 295,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 296,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 297,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 298,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 299,           /* enum_constants  */
  YYSYMBOL_enum_constant = 300,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 301,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 302,                /* ds_fields  */
  YYSYMBOL_psds_kw = 303,                  /* psds_kw  */
  YYSYMBOL_ds_field = 304,                 /* ds_field  */
  YYSYMBOL_if_stmt = 305,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 306,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 307,            /* elseif_clause  */
  YYSYMBOL_else_clause = 308,              /* else_clause  */
  YYSYMBOL_dow_stmt = 309,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 310,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 311,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 312,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 313,              /* select_stmt  */
  YYSYMBOL_when_clauses = 314,             /* when_clauses  */
  YYSYMBOL_when_clause = 315,              /* when_clause  */
  YYSYMBOL_other_clause = 316,             /* other_clause  */
  YYSYMBOL_iter_stmt = 317,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 318,               /* leave_stmt  */
  YYSYMBOL_expression = 319,               /* expression  */
  YYSYMBOL_or_expr = 320,                  /* or_expr  */
  YYSYMBOL_and_expr = 321,                 /* and_expr  */
  YYSYMBOL_not_expr = 322,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 323,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 324,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 325,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 326,               /* power_expr  */
  YYSYMBOL_unary_expr = 327,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 328,             /* postfix_expr  */
  YYSYMBOL_ident = 329,                    /* ident  */
  YYSYMBOL_primary_expr = 330,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 331,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 332,            /* call_arg_list  */
  YYSYMBOL_arg_list = 333                  /* arg_list  */
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
#define YYLAST   5142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  256
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  481
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1584

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   510


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
     255
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   198,   198,   201,   206,   208,   213,   222,   225,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   278,
     282,   286,   290,   298,   303,   308,   313,   318,   323,   328,
     333,   338,   343,   348,   353,   359,   365,   371,   375,   379,
     383,   387,   391,   395,   399,   403,   407,   411,   417,   423,
     429,   435,   442,   447,   453,   458,   463,   468,   473,   478,
     483,   488,   493,   498,   503,   508,   513,   518,   523,   528,
     536,   537,   538,   539,   540,   545,   552,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   573,   579,   583,   589,   595,   601,   607,   618,
     626,   632,   641,   648,   655,   662,   671,   678,   685,   692,
     701,   708,   715,   722,   728,   739,   742,   749,   755,   761,
     767,   770,   777,   788,   805,   825,   840,   864,   889,   916,
     946,   947,   952,   953,   954,   955,   956,   961,   964,   972,
     976,   980,   984,   988,   992,   996,  1000,  1005,  1009,  1013,
    1017,  1021,  1025,  1029,  1033,  1037,  1043,  1048,  1053,  1058,
    1064,  1069,  1074,  1079,  1085,  1090,  1095,  1104,  1107,  1115,
    1119,  1123,  1127,  1131,  1135,  1139,  1143,  1148,  1152,  1156,
    1160,  1164,  1168,  1172,  1176,  1180,  1186,  1191,  1196,  1201,
    1207,  1212,  1217,  1222,  1228,  1233,  1238,  1248,  1259,  1269,
    1277,  1285,  1292,  1300,  1308,  1319,  1329,  1337,  1348,  1351,
    1359,  1367,  1382,  1391,  1400,  1410,  1420,  1431,  1442,  1453,
    1464,  1472,  1481,  1491,  1502,  1513,  1523,  1533,  1543,  1553,
    1563,  1566,  1574,  1575,  1579,  1583,  1587,  1591,  1596,  1600,
    1604,  1608,  1613,  1619,  1625,  1632,  1639,  1646,  1652,  1660,
    1666,  1677,  1700,  1701,  1709,  1718,  1719,  1725,  1734,  1743,
    1753,  1763,  1773,  1786,  1796,  1815,  1819,  1826,  1835,  1836,
    1842,  1846,  1852,  1856,  1857,  1865,  1866,  1874,  1875,  1881,
    1882,  1887,  1892,  1897,  1902,  1907,  1912,  1920,  1921,  1926,
    1934,  1935,  1940,  1948,  1949,  1957,  1958,  1966,  1967,  1974,
    1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,
    1985,  1986,  1987,  1988,  1989,  1993,  1997,  1998,  1999,  2000,
    2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,
    2011,  2014,  2017,  2021,  2025,  2028,  2031,  2034,  2037,  2040,
    2043,  2046,  2049,  2052,  2055,  2058,  2061,  2065,  2068,  2071,
    2074,  2077,  2080,  2083,  2086,  2089,  2095,  2101,  2107,  2113,
    2119,  2125,  2128,  2131,  2134,  2137,  2141,  2145,  2148,  2151,
    2154,  2157,  2160,  2163,  2167,  2170,  2174,  2177,  2181,  2188,
    2195,  2202,  2207,  2212,  2217,  2221,  2225,  2228,  2231,  2234,
    2237,  2240,  2243,  2246,  2249,  2252,  2255,  2258,  2261,  2264,
    2267,  2270,  2273,  2276,  2279,  2282,  2285,  2288,  2291,  2294,
    2297,  2300,  2303,  2306,  2311,  2316,  2321,  2326,  2332,  2336,
    2340,  2347,  2354,  2361,  2367,  2373,  2379,  2382,  2385,  2388,
    2391,  2394,  2397,  2400,  2406,  2409,  2412,  2415,  2418,  2421,
    2424,  2428,  2431,  2434,  2437,  2440,  2447,  2448,  2452,  2456,
    2464,  2468
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
  "KW_IN", "KW_XML_INTO", "KW_DATA_INTO", "KW_DATA_GEN", "IDENTIFIER",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "SEMICOLON",
  "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS", "STAR", "SLASH",
  "NE", "LE", "GE", "LT", "GT", "$accept", "program", "statements_opt",
  "statement_list", "statement", "dcl_f_stmt", "dcl_s_stmt",
  "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "xml_into_stmt", "data_into_stmt", "data_gen_stmt",
  "in_da_stmt", "out_da_stmt", "unlock_da_stmt", "evalr_stmt",
  "callp_stmt", "leavesr_stmt", "dsply_stmt", "inlr_stmt", "return_stmt",
  "expr_stmt", "dcl_pr_stmt", "dcl_proc_stmt", "proc_export",
  "pi_return_type", "pi_params", "pi_param", "pr_params", "pr_param",
  "monitor_stmt", "begsr_stmt", "exsr_stmt", "sorta_stmt", "reset_stmt",
  "clear_stmt", "dealloc_stmt", "test_stmt", "exec_sql_stmt",
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

#define YYPACT_NINF (-879)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-300)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,  -879,    64,    46,   580,  -879,  -174,  -166,   267,  -129,
    4462,   227,   267,   227,  4462,  -115,   267,   -95,   227,   227,
    4462,  -879,  3762,   -78,  4462,  4462,  4462,   267,   -70,   -29,
     -15,   -11,    14,   267,   267,   267,   267,  -879,    35,    47,
      55,    57,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,    66,    75,  -879,  -879,  -879,  -879,  -879,    91,  -879,
     267,    96,   267,   267,   267,   -12,  -879,  -879,  -879,  -879,
      95,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,    82,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,   163,  4462,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  4637,   105,   114,
     118,   126,   148,   157,   171,   175,   196,   200,   213,   219,
     254,   262,   272,   321,   331,   335,   361,   401,   404,   409,
     420,   422,   429,   433,   446,   450,   456,   517,   525,   535,
     561,   568,   575,   576,   577,   578,   579,   581,   582,   583,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   110,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,   630,
    -879,  -879,  -879,  4462,  4812,   524,   377,   552,  -879,   239,
     182,    69,  -879,   462,   715,  -879,     5,   481,   632,   633,
     635,  -879,   636,   267,   637,   639,   642,  -879,   643,   831,
     646,   650,   651,   652,   819,  -879,  -879,  -879,   654,   655,
     656,   657,   658,   852,   448,    89,  4462,   660,   661,   -54,
     670,   663,   710,   711,   712,   669,  4462,  4462,    -8,   668,
     671,   667,   678,   684,   686,   688,    86,   -69,   672,   673,
     691,   692,   693,   694,   697,   698,   699,   700,   703,   704,
     239,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,
    4462,  4462,  4462,   689,   708,  4462,  4462,  4462,  4462,  4462,
     713,   716,   717,  4462,  4462,  4462,  3937,  4112,  4287,  4462,
    4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,
    4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,
    4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,
    4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,  4462,
    4462,  4462,  4462,  4462,   674,   721,   267,   267,  4462,  4462,
    4462,  4462,  4462,  4462,  4462,   267,  4462,  -879,  4462,   722,
     715,  -879,  4462,  4462,  4637,  4637,  4637,  4637,  4637,  4637,
    4637,  4637,  4637,  4637,  4637,  4637,   718,  4462,  4462,   267,
    4462,  -879,  -879,   731,  4462,  4462,  -879,  -879,   729,  -879,
    -879,  -879,  4462,  4462,   268,  -879,  1738,  -879,  -879,  -879,
    -879,  -879,  -879,   735,   734,   736,   737,   740,   743,   -14,
      28,   744,   745,   748,  -879,  -879,  -879,   -36,  -879,   101,
    -879,  -879,   751,   719,  4462,  -879,   750,   753,   754,  -879,
     755,   757,   709,   759,   760,  -879,  -879,  -879,   696,   764,
     766,   768,   769,   765,  -879,   767,  -879,  -879,  -879,  -879,
     752,   771,   773,   775,   776,   777,   789,  -879,  -879,   127,
     139,   151,   177,   238,   312,   314,   316,   318,   323,   328,
     332,  -879,  -879,   337,   342,   344,   346,   348,  -879,  -879,
    -879,   350,   352,   354,  -879,   356,  -879,   358,  -879,   362,
     714,   772,   774,   778,   364,   378,   380,   382,   384,   386,
     391,   779,   393,   395,   411,   416,   426,   430,   434,   437,
     439,   441,   443,   451,   453,   457,   459,   461,   463,   465,
     467,   469,   471,   473,   475,   477,   480,   482,   484,   486,
     488,   781,   782,   783,   784,   785,  -879,   786,   787,   490,
     492,   494,   496,   498,   500,   502,   788,   504,  -879,   790,
    -879,   552,  -879,   225,   225,   225,   225,   225,   225,   225,
      69,    69,  -879,  -879,  -879,  -879,   755,   780,   792,   794,
     267,   795,   796,  -879,   885,  1809,  2035,   379,   797,   798,
    -879,   905,   799,  -879,  2106,   903,   803,   805,   806,   807,
     802,   808,  -879,   809,   810,  -879,   813,   264,   811,   812,
      21,   814,   190,  -879,  4462,   719,   509,  -108,  -879,   815,
    4462,  4462,  4462,   909,   816,  4462,  -879,   817,   818,   823,
     824,   801,   825,   821,   822,   827,   829,   830,   832,   833,
     834,   836,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  4462,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,   515,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,   820,  -879,  -879,   690,
     838,   841,  4462,  4462,  -879,  -879,   845,  -879,   846,    23,
     853,   854,   855,   844,   863,   835,    40,   278,   826,    61,
    -879,   864,   867,   879,   880,   510,   849,   871,   365,  -879,
    -879,    62,  -879,    50,  -879,  4462,   884,  -879,  -879,   512,
     514,   519,   889,  -879,  -879,   882,   108,   111,   141,   890,
     891,   886,   887,   892,   479,   479,   479,   479,   479,   894,
     893,   888,   895,   896,   910,   911,   912,  -879,  4462,   906,
    -879,   955,  -879,  -879,   -32,   -31,  1111,  2332,  -879,  2436,
    -879,   513,   916,  -879,  -879,  -879,   897,   917,   915,   919,
     899,   376,  -879,   908,   918,   922,   522,   920,   107,   924,
     929,   921,   -34,   927,   931,  -879,   392,   930,   932,   935,
     937,   938,   119,   933,   941,   942,  -879,  2662,   950,  4462,
    -150,  4462,  -125,  4462,  -879,   944,   991,   951,  -879,  -879,
     953,  1018,  -879,   958,   959,   962,   963,  -879,   964,   966,
     969,  1021,   970,   971,  1031,   973,   974,   980,   926,   961,
     981,   982,  -879,   983,   985,   987,   988,   989,   968,   521,
    -879,  -879,  -879,  -879,  -879,  -879,   992,  -879,   993,  4462,
    -879,  4462,  -879,   994,   995,  -879,   996,  -879,   997,  -879,
     538,   998,   999,  1000,  1001,  1014,  1020,  1022,  1023,  1024,
    1025,  -879,  1026,  1015,  1017,  1029,  1019,  -879,  -879,  1027,
    1030,  1032,  1039,  1041,  1042,  1028,  1034,  1036,  1048,   900,
    1046,  -879,  -879,  -879,  1049,  -879,  1045,  1052,  -879,  1047,
    1053,  -879,  1054,  1056,  1062,  4462,  1002,  1063,  1069,  1072,
    -879,  4462,   280,  1076,  -879,  1073,  4462,  1086,  1081,   282,
    1088,  -879,   265,   479,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  1092,  1090,  1093,  1094,  1096,  1097,  1098,  -879,  2733,
    -879,  1108,  2959,  1109,  3030,  -879,  -879,    10,  -879,    51,
    -879,  1110,  1112,  1113,  1114,  1116,  1120,  1121,  1122,  1115,
    1107,  1117,  -879,  -879,  1118,  -879,  1130,  1135,  -879,  1125,
     136,  1262,  1127,  1128,  1129,  1131,  1133,  1124,  1132,  1134,
    1126,  1136,  -879,  -879,  1138,  4462,   -76,  4462,    32,  1140,
    4462,  1139,  1141,  4462,  1142,  1143,  1144,  1137,  1145,  1147,
    1148,  4462,  1149,  1150,  4462,  1151,  1152,  1154,  1155,  1343,
    1146,  1157,  1158,  1161,  1162,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  1215,  -879,  1163,  -879,  1164,    13,  1165,  1170,
     399,  -879,  1167,   121,  1171,  1172,  1173,  1174,  1169,  1175,
    1176,  1182,  1184,  1188,  1196,   137,   169,  1197,  1198,  1201,
     203,  1209,  1213,  1214,  1212,  1216,  1217,  1218,  1220,   129,
    1221,   153,  1178,  1224,  -879,  1222,  1225,  -879,  1223,  1226,
    -879,  -879,  1239,  1229,  1243,  1241,   112,  1245,  1246,  1179,
    1219,  1247,  1248,  1249,  1250,  1251,  1252,  1259,  1260,   179,
    1258,  1257,  4462,  1263,  1253,  -879,  -879,  3256,  -879,  3327,
    -879,  1264,  -879,   542,  1261,  1265,  1267,  1268,  1270,  -879,
    1280,  1278,  1282,  1287,  1279,   -35,   -26,   -25,  1294,  1292,
    -879,  -879,  1295,  1296,  -879,  -879,  -879,  1298,  1299,  -879,
    -879,  1313,  1314,  1315,  1319,  1317,  1316,  1320,  -879,  -879,
    1321,  1324,  -879,  1318,  -879,  1327,  4462,  1328,  4462,  1329,
    -879,  -879,  1330,  1331,  1333,  -879,  -879,  -879,  1332,  1335,
    -879,  -879,  1334,  -879,  -879,  1340,  1338,  1339,  1345,  1346,
    -879,  -879,  4462,  1344,  1348,  1349,  1354,  1356,  -879,  1441,
    1341,  1359,  1360,  1361,  1322,  1369,  1370,  1372,  1266,  -879,
     -55,   -47,   -46,  1373,  1371,   -43,  -879,  1374,   -41,  -879,
    1375,   -40,  -879,  1376,  -879,   204,   205,  -879,  -879,   214,
     218,   220,  -879,  -879,   228,  -879,  -879,  -879,  1377,  -879,
    1378,  1381,  1379,  1384,   -97,  -879,  1380,  -879,  1382,  -879,
    -879,  -879,  -879,  1386,  1387,  -879,  -879,  1388,  1389,  -879,
    -879,  1390,  1392,  1394,  1395,  -879,  -879,  1512,  1396,  1397,
    1385,  1393,  1401,  1404,  1399,  1402,  1409,  1368,  1410,  1414,
    -879,  1422,  -879,  1423,  -879,  1421,   724,  1424,  -879,   726,
    1425,  -879,   728,  1427,  -879,   -24,  1430,  1431,  1438,  1439,
    1440,  1442,  1443,   532,  1444,   537,  1445,  1447,  -879,  1446,
    1450,  -879,  -879,  -879,  -879,  1451,  -879,  -879,  -879,  1452,
    1453,  -879,  -879,  1454,  1455,  1456,  1400,   -17,    -7,    -6,
    1448,  1460,  -879,  -879,  -879,   -45,  1437,  1458,  1412,  1459,
    1461,  1413,  1462,  1464,  1579,  1463,   -39,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  1468,  1457,  1469,  1472,  1465,
    1473,  1478,  -879,  -879,  -879,  -879,  -879,  3553,   -44,   -42,
     -38,  1479,  1481,   -23,  -879,  1482,   -20,  -879,  1483,   -19,
    -879,  1490,  -879,  1494,  -879,  1326,  1495,  1506,  1337,  1498,
    1507,  1638,  1511,  1509,  1649,  1513,  -879,  -879,  1510,  -879,
    -879,  1514,  -879,  1515,  3624,  1516,  1519,  -879,  1520,  -879,
    1521,  -879,  1522,   738,  1524,  -879,   746,  1531,  -879,   756,
    1537,  -879,    -2,  -879,  1538,  -879,  1523,  1539,  -879,  1540,
    1541,  -879,  1543,  1542,  1651,  1546,  1547,  1548,  1549,  -879,
    -879,  -879,  -879,   -37,  1518,  1550,  1709,  1551,  1553,  1719,
    1555,  1554,  1747,  1552,   -18,  -879,  1560,  -879,  1561,  -879,
    1564,  -879,  1566,  1575,  -879,  -879,  -879,  -879,  1567,  -879,
    1763,  1580,  1584,  1776,  1588,  1586,  1785,  1592,  1590,  1789,
    1594,  -879,  -879,  -879,  -879,  -879,  1604,  -879,  1607,  -879,
    1611,  1609,  -879,  1613,  1612,  -879,  1614,  1615,  1811,  -879,
    1619,  -879,  1620,  -879,  1623,  -879,  1624,  1622,  -879,  -879,
    -879,  -879,  1626,  -879
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,     0,   110,   111,   112,   108,   107,   109,   118,   119,
     120,     0,     0,   115,   116,   113,   114,   117,     0,   235,
       0,     0,     0,     0,     0,   106,     5,     9,    10,    11,
       0,    12,    13,    41,    42,    43,    44,    45,    46,    35,
      36,    37,    14,    15,    16,    47,    26,    25,    29,    30,
      31,    34,    32,    33,    38,    39,    40,    28,    27,    17,
      18,    19,    20,    21,    22,    23,    24,    48,     0,   330,
     331,   332,   342,   343,   344,   339,   340,   341,   336,   337,
     333,   334,   338,   335,   329,     0,     0,   468,   469,   466,
     471,   472,   473,   474,   470,   467,   465,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   346,   347,   348,   355,   356,
     357,   354,   358,   359,   351,   352,   349,   350,   353,   345,
     360,   361,   362,     0,     0,     0,   302,   303,   305,   307,
     309,   317,   320,   323,   325,   327,   106,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,     0,   300,   301,     7,     0,     0,
       0,     0,     0,   160,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,   476,     0,
     326,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   233,     0,     0,     0,   146,   150,     0,     7,
       7,     7,     0,     0,   298,   295,     0,     7,   229,   231,
     232,   230,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,   260,     0,   480,     0,
     141,   142,     0,     0,     0,   140,     0,     0,     0,   122,
     478,     0,   477,     0,     0,    49,    50,    51,     0,     0,
       0,     0,     0,     0,    69,     0,    70,    71,    67,    72,
       0,     0,     0,     0,     0,     0,     0,    68,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   414,   415,     0,     0,     0,     0,     0,   376,   395,
     396,     0,     0,     0,   403,     0,   405,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   478,     0,
     475,   304,   306,   310,   311,   314,   315,   312,   313,   316,
     318,   319,   321,   322,   324,   328,     0,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,     0,     0,     0,
     296,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,   197,     0,     0,   260,     0,     0,     0,     0,
       0,     0,   259,   125,     0,     0,     0,     0,   238,     0,
       0,     0,     0,   123,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   399,   400,   401,   397,   398,   393,
     394,   377,   402,   404,   406,     0,   411,   412,   413,   378,
     379,   380,   381,   382,   383,   384,     0,   391,   392,   416,
     417,   418,   429,   423,   419,   420,   421,   422,   424,   425,
     426,   427,   428,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   363,   127,   129,   143,     0,   128,   144,   285,
       0,     0,     0,     0,     7,     7,     0,     7,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     260,     0,   481,     0,   240,     0,     0,   239,     7,     0,
       0,     0,     0,   152,   479,     0,   100,   100,   100,     0,
       0,     0,     0,     0,   100,   100,   100,   100,   100,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
     283,     0,   287,   288,     0,     0,     0,     0,   294,     0,
     228,   162,     0,   164,   165,   163,     0,     0,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,   101,   102,
       0,   103,   104,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
     387,   386,   385,   388,   389,   390,     0,     7,     0,     0,
       7,     0,     7,     0,     0,   167,     0,   197,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,     0,     0,     0,     0,     0,   250,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   236,   241,     0,   131,     0,     0,   135,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,    55,   100,   100,    94,    95,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     7,     0,
     281,     0,     0,     0,     0,   227,   167,     0,   166,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,   260,     0,   257,     0,     0,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,   408,   409,   410,   450,
     451,   452,     0,     7,     0,     7,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,   133,     0,     0,
     137,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57,     0,   289,     0,
     291,     0,     7,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,   260,     0,     0,   260,   260,   260,     0,     0,   255,
     260,     0,     0,     0,     0,     0,     0,     0,   265,   266,
       0,     0,   264,     0,   279,     0,     0,     0,     0,     0,
      62,    89,     0,     0,     0,    74,    96,    64,     0,     0,
      75,    97,     0,    61,    88,     0,     0,     0,     0,     0,
      73,    98,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
       0,     0,     0,     0,     0,     0,   201,     0,     0,   203,
       0,     0,   199,     0,   215,     0,     0,   245,   252,     0,
       0,     0,   244,   251,     0,   269,   270,   268,     0,   280,
       0,     0,     0,     0,     0,   134,     0,   138,     0,    59,
      66,    92,    93,     0,     0,    58,    65,     0,     0,    90,
      91,     0,     0,     0,     0,   290,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,     0,   211,     0,   207,     0,     0,     0,   202,     0,
       0,   204,     0,     0,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,     0,
       0,    79,    80,    77,    78,     0,    63,    76,    99,     0,
       0,     7,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,   212,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   247,   249,
     254,   246,   248,   253,   271,     0,     0,     0,     0,     0,
       0,     0,   132,   136,    60,     7,   157,     0,     0,     0,
       0,     0,     0,     0,   171,     0,     0,   173,     0,     0,
     169,     0,   185,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,   275,     0,   272,
     277,     0,   273,     0,     0,     0,     0,   179,     0,   181,
       0,   177,     0,     0,     0,   172,     0,     0,   174,     0,
       0,   170,     0,   214,     0,   221,     0,     0,   222,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,   158,
     180,   182,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,     0,   217,     0,   218,
       0,   216,     0,     0,   276,   278,   274,   159,     0,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   225,   226,   224,   223,     0,   184,     0,   191,
       0,     0,   192,     0,     0,   190,     0,     0,     0,   219,
       0,   187,     0,   188,     0,   186,     0,     0,   195,   196,
     194,   193,     0,   189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -879,  -879,  1868,  -422,   804,  -879,  -879,  -722,  -879,   489,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -708,   339,
    -879,  -878,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,
    -879,  -879,  -879,   723,  -614,  -879,  -644,   936,  -879,  -879,
    -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  -879,  1426,
    -879,  -879,  -879,   -10,  -879,  1467,  1471,  1735,   116,   389,
      30,  -879,  1629,    -3,  -879,  1466,  -879,  4736
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   446,   633,    67,    68,   905,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   453,   459,  1037,
    1121,   786,   862,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   657,   658,    98,   650,   467,   799,    99,
     769,   840,   841,   100,   101,   102,   103,   104,   444,   445,
     631,   105,   106,   468,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   125,   255,   481,   482,   469
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     245,   789,   484,  1357,   260,  1360,  1363,  1465,   801,   258,
     266,  1284,   268,   262,   270,   271,   272,   624,   625,   626,
    1287,  1290,  1415,  1484,   273,   634,  1487,  1490,  1550,  1442,
     279,   280,   281,   282,   454,   455,   456,   457,   641,  1445,
    1448,   939,   941,   807,  1523,  1349,    -3,     6,   987,   472,
       7,     8,     9,  1351,  1353,  1453,  1476,   290,  1478,   292,
     293,   294,  1480,  1538,     5,  1285,     1,   651,   107,  1039,
     966,   852,   108,   990,  1288,  1291,  1416,    10,    11,    12,
      13,    14,    15,  1443,    16,    17,    18,    19,    20,   298,
     299,   300,   988,  1446,  1449,   910,   917,   295,  1524,    21,
      22,    23,   923,   924,   925,   926,   927,  1118,    24,   126,
    1191,  1377,    25,    26,   295,    27,   319,   991,  1119,   806,
      28,  1119,  1156,   796,    29,    30,    31,   261,   797,    32,
     656,    33,   643,    34,    35,    36,    37,   896,   897,   859,
      38,   906,   495,   944,    39,  1378,   868,    40,   860,   263,
    1122,   898,   899,   900,   898,   899,   882,   901,   902,   860,
     907,   902,  1123,   867,   883,   269,  1157,    41,   797,   797,
     911,   912,   274,   496,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   898,   899,   913,  1350,   473,   807,
     914,   902,   460,   461,   462,  1352,  1354,  1454,  1477,  1358,
    1479,  1361,  1364,  1466,  1481,  1539,   652,  1286,   967,   962,
     940,   942,   903,   275,   797,   908,  1289,  1292,  1417,  1485,
    1200,   980,  1488,  1491,  1551,  1444,   797,   276,   642,   860,
    1159,   277,   296,   409,   485,  1447,  1450,   644,  1142,  1212,
    1525,   464,   465,   797,   797,   915,    42,    43,  1120,   427,
      44,  1120,   278,    45,    46,    47,    48,    49,    50,   798,
     433,   851,    51,    52,    53,    54,    55,    56,    57,   311,
     645,  1213,    58,   283,  1160,    59,   797,   884,   861,    60,
      61,    62,    63,    64,    65,   284,   480,   483,   656,   861,
    1103,  1104,  -260,   285,  1099,  1100,   493,  -260,   463,   798,
     798,   286,   464,   465,   287,  1217,  1366,  1367,   898,   899,
     797,   797,   797,   288,   907,   902,  1368,    37,   423,   424,
    1369,   797,  1370,   904,  1060,   797,   909,   797,   494,   289,
    1371,   466,  1243,  1244,   291,   797,  1226,  1227,   297,   540,
     541,   542,   543,   443,   629,   798,   653,   654,    41,   321,
     551,   407,   846,   847,  1245,   849,   916,   798,   322,   861,
    1230,  1231,   323,   312,   313,   314,   315,   316,   317,  1101,
     324,  1228,   682,   654,   798,   798,   877,   878,   879,   880,
     581,   582,   583,   584,   683,   654,   887,   951,   952,   953,
     954,   318,   325,   587,   588,  1232,   684,   654,   598,  1258,
    1259,   326,   596,   970,   971,   972,   973,   798,  1135,  1136,
    1194,  1195,  1196,  1197,  1140,   327,   420,   616,   617,   328,
     619,  1260,   685,   654,   621,   622,   618,    42,    43,   421,
     422,    44,   627,   628,    45,    46,    47,    48,    49,    50,
     329,   798,   798,   798,   330,    53,    54,    55,    56,    57,
     772,   773,   798,   612,   613,   614,   798,   331,   798,   454,
     455,   456,   457,   332,   659,   256,   798,   109,   110,   412,
     881,   111,   421,   422,   112,   113,   114,   115,   116,   117,
    1102,   955,   414,   686,   654,   118,   119,   120,   121,   122,
     415,   416,   417,   418,   419,   791,   792,   974,   333,   458,
     257,   123,   259,   793,  1198,   124,   334,   264,   265,   863,
     864,  1087,  1088,  1095,  1096,  1029,   335,   865,  1032,  1089,
    1034,  1097,   898,   899,   454,   455,   456,   457,   907,   902,
     603,   604,   605,   606,   607,   608,   609,   831,   832,   833,
     834,   835,   836,  1022,  1023,  1024,  1025,  1026,  1027,  1041,
    1042,  1043,  1044,  1270,  1271,  1272,  1273,   687,   654,   688,
     654,   689,   654,   690,   654,   336,  1295,  1296,   691,   654,
    1299,  1300,  1301,   692,   654,   337,  1304,   693,   654,   338,
      -2,     6,   694,   654,     7,     8,     9,   695,   654,   696,
     654,   697,   654,   698,   654,   699,   654,   700,   654,   701,
     654,   702,   654,   703,   654,   339,  1112,   704,   654,   709,
     654,    10,    11,    12,    13,    14,    15,   766,    16,    17,
      18,    19,    20,   710,   654,   711,   654,   712,   654,   713,
     654,   714,   654,    21,    22,    23,   715,   654,   717,   654,
     718,   654,    24,   413,   802,   340,    25,    26,   341,    27,
     809,   810,   811,   342,    28,   814,   719,   654,    29,    30,
      31,   720,   654,    32,   343,    33,   344,    34,    35,    36,
      37,   721,   654,   345,    38,   722,   654,   346,    39,   723,
     654,    40,   724,   654,   725,   654,   726,   654,   727,   654,
     347,  1187,   425,  1189,   348,   830,   728,   654,   729,   654,
     349,    41,   730,   654,   731,   654,   732,   654,   733,   654,
     734,   654,   735,   654,   736,   654,   737,   654,   738,   654,
     739,   654,   740,   654,   428,   741,   654,   742,   654,   743,
     654,   744,   654,   745,   654,   753,   654,   754,   654,   755,
     654,   756,   654,   757,   654,   758,   654,   759,   654,   761,
     654,   804,   805,   838,   839,   873,   874,   888,   889,   890,
     891,   350,   844,   845,   892,   893,   411,   959,   960,   351,
    1269,  1406,  1407,  1409,  1410,  1412,  1413,  1425,  1426,   352,
      42,    43,  1428,  1429,    44,  1514,  1515,    45,    46,    47,
      48,    49,    50,  1517,  1518,   885,    51,    52,    53,    54,
      55,    56,    57,  1520,  1521,   353,    58,    66,    66,    59,
     610,   611,   354,    60,    61,    62,    63,    64,    65,   355,
     356,   357,   358,   359,   426,   360,   361,   362,   936,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,  1337,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   408,   429,   430,   431,   432,   986,
     434,   989,   435,   992,   436,   437,     6,   438,   439,     7,
       8,     9,   440,   441,   443,   442,   447,   448,   449,   450,
     451,   452,   470,   471,   474,   475,   476,   479,   477,   478,
     486,   488,   585,   487,   497,   498,    10,    11,    12,    13,
      14,    15,   489,    16,    17,    18,    19,    20,   490,  1031,
     491,  1033,   492,   499,   521,   668,   500,   501,   502,    22,
      23,   503,   504,   505,   506,   507,   508,    24,  -282,  -282,
    -282,    25,    26,   522,    27,   665,   615,   656,   528,    28,
     705,   529,   530,    29,    30,    31,   586,   600,    32,  1437,
      33,   623,    34,    35,    36,    37,   620,   635,   636,    38,
     637,   638,   776,    39,   639,  1081,    40,   640,   647,   648,
     675,  1086,   649,   655,   660,   681,  1092,   661,   662,   779,
     663,   666,   664,   669,   667,   670,    41,   671,   672,   673,
     676,   674,   677,  1474,   678,   679,   680,   706,   812,   707,
     938,   994,   763,   708,   965,   716,   746,   747,   748,   749,
     750,   751,   752,   760,   764,   762,   765,   767,   768,   774,
     775,   777,   780,   784,   781,   782,   783,   819,   997,   794,
     795,  1005,   785,   787,   788,   790,   800,   808,   813,   821,
     822,  1008,   837,   816,   866,  1155,   815,  1158,   817,   818,
    1162,   820,   823,  1165,   824,   825,   858,   826,   827,   828,
     842,  1173,   829,   843,  1176,    42,    43,   848,   850,    44,
     856,   875,    45,    46,    47,    48,    49,    50,   853,   854,
     855,    51,    52,    53,    54,    55,    56,    57,   857,   876,
     869,    58,     6,   870,    59,     7,     8,     9,    60,    61,
      62,    63,    64,    65,   871,   872,   886,   894,   895,   918,
     919,   920,   921,   930,   922,   928,   946,   950,  1071,   929,
     931,   932,    10,    11,    12,    13,    14,    15,   937,    16,
      17,    18,    19,    20,   956,   933,   934,   935,   945,   947,
     948,   949,   961,   963,   957,    22,    23,   958,   964,   968,
     969,  1012,  1263,    24,   975,   981,   976,    25,    26,   977,
      27,   978,   979,   982,   983,    28,  -297,  -297,  -297,    29,
      30,    31,   985,   993,    32,   995,    33,   996,    34,    35,
      36,    37,   998,   999,  1000,    38,  1013,  1001,  1002,    39,
    1003,  1004,    40,  1021,  1006,  1007,     6,  1009,  1010,     7,
       8,     9,  1011,  1014,  1015,  1016,  1316,  1017,  1318,  1018,
    1019,  1020,    41,  1138,  1028,  1030,  1035,  1036,  1139,  1040,
    1082,  1038,  1045,  1046,  1047,  1048,    10,    11,    12,    13,
      14,    15,  1331,    16,    17,    18,    19,    20,  1049,  1050,
    1056,  1051,  1057,  1059,  1054,  1052,  1053,  1067,  1055,    22,
      23,  1058,  1061,  1068,  1062,  1069,  1063,    24,  -284,  -284,
    -284,    25,    26,  1064,    27,  1065,  1066,  1070,  1072,    28,
    1074,  1073,  1076,    29,    30,    31,  1075,  1077,    32,  1078,
      33,  1079,    34,    35,    36,    37,  1080,  1083,  1084,    38,
    1085,    42,    43,    39,  1090,    44,    40,  1091,    45,    46,
      47,    48,    49,    50,  1093,  1094,  1098,    51,    52,    53,
      54,    55,    56,    57,  1105,  1106,    41,    58,  1107,  1108,
      59,  1109,  1110,  1111,    60,    61,    62,    63,    64,    65,
    1113,  1115,  1133,  1132,  1124,  1128,  1125,  1126,  1127,  1129,
    1130,  1131,  1134,  1137,  1141,  1143,  1144,  1145,  1146,  1149,
    1147,  1148,  1152,  1181,  1494,  1117,     0,  1150,   803,  1151,
    1154,  1153,  1161,  1169,  1163,  1497,  1164,  1166,  1167,  1168,
    1182,  1170,  1171,  1172,  1174,  1175,   646,  1177,  1178,  1179,
    1180,  1183,  1184,  1185,  1186,  1188,  1190,  1192,  1193,  1199,
    1201,  1202,  1203,  1204,  1205,    42,    43,  1233,  1248,    44,
    1206,  1207,    45,    46,    47,    48,    49,    50,  1208,  1209,
    1210,    51,    52,    53,    54,    55,    56,    57,  1211,  1214,
    1215,    58,     6,  1216,    59,     7,     8,     9,    60,    61,
      62,    63,    64,    65,  1218,  1219,  1220,  1221,  1249,  1457,
    1460,  1222,  1223,  1229,  1224,  1225,  1234,  1235,  1237,  1236,
    1238,  1240,    10,    11,    12,    13,    14,    15,  1338,    16,
      17,    18,    19,    20,  1239,  1241,  1242,  1246,  1247,  1250,
    1251,  1265,  1253,  1254,  1252,    22,    23,  1255,  1256,  1257,
    1261,  1262,  1264,    24,  1348,  1274,  1268,    25,    26,  1275,
      27,  1276,  1277,     6,  1278,    28,     7,     8,     9,    29,
      30,    31,  1279,  1280,    32,  1283,    33,  1281,    34,    35,
      36,    37,  1282,  1293,  1294,    38,  1339,  1297,  1298,    39,
    1302,  1303,    40,    10,    11,    12,    13,    14,    15,  1389,
      16,    17,    18,    19,    20,  1305,  1306,  1307,  1308,  1309,
    1310,  1344,    41,  1314,  1311,  1312,    22,    23,  1313,  1315,
    1317,  1319,  1320,  1321,    24,  1322,  1325,  1323,    25,    26,
    1324,    27,  1326,  1327,  1328,  1340,    28,  1329,  1330,  1332,
      29,    30,    31,  1333,  1334,    32,  1335,    33,  1336,    34,
      35,    36,    37,  1341,  1342,  1343,    38,  1390,  1345,  1346,
      39,  1347,  1355,    40,  1400,  1356,  1373,  1375,  1359,  1362,
    1374,  1365,  1372,  1376,  1393,  1379,  1463,  1380,  1381,  1382,
    1383,  1384,  1394,    41,  1386,  1385,  1387,  1388,  1391,  1392,
    1395,    42,    43,  1396,  1397,    44,  1441,  1398,    45,    46,
      47,    48,    49,    50,  1399,  1401,  1402,    51,    52,    53,
      54,    55,    56,    57,  1403,  1404,  1405,    58,  1408,  1411,
      59,  1414,  1418,  1419,    60,    61,    62,    63,    64,    65,
    1420,  1421,  1422,  1455,  1423,  1424,  1500,  1451,  1432,  1427,
    1430,  1431,  1433,  1434,  1435,  1436,  1468,  1503,  1533,  1438,
    1439,  1440,  1452,  1456,  1471,  1458,  1459,  1464,  1461,  1462,
    1467,  1469,    42,    43,  1470,  1472,    44,  1473,  1482,    45,
      46,    47,    48,    49,    50,  1483,  1486,  1489,    51,    52,
      53,    54,    55,    56,    57,  1492,  1493,  1495,    58,     6,
    1498,    59,     7,     8,     9,    60,    61,    62,    63,    64,
      65,  1496,  1499,  1501,  1502,  1505,  1542,  1504,  1509,  1506,
    1507,  1510,  1511,  1512,  1540,  1527,  1545,  1513,  1516,    10,
      11,    12,    13,    14,    15,  1519,    16,    17,    18,    19,
      20,  1522,  1529,  1526,  1528,  1531,  1530,  1532,  1534,  1535,
    1536,  1537,    22,    23,  1548,  1541,  1549,  1543,  1544,  1547,
      24,  1546,  1552,  1553,    25,    26,  1554,    27,  1555,  1557,
       6,  1558,    28,     7,     8,     9,    29,    30,    31,   632,
    1556,    32,  1559,    33,  1561,    34,    35,    36,    37,  1560,
    1562,  1563,    38,  1564,  1565,  1566,    39,  1567,  1568,    40,
      10,    11,    12,    13,    14,    15,  1569,    16,    17,    18,
      19,    20,  1570,  1571,  1572,  1573,  1575,  1574,  1577,    41,
    1576,  1578,  1579,    22,    23,  1580,  1581,  1582,  1583,     4,
     630,    24,   320,   410,   599,    25,    26,   770,    27,   601,
       0,     0,     0,    28,   602,     0,     0,    29,    30,    31,
       0,     0,    32,     0,    33,     0,    34,    35,    36,    37,
       0,     0,     0,    38,     0,     0,     0,    39,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,    42,    43,
       0,     0,    44,     0,     0,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,    58,     0,     0,    59,     0,     0,
       0,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,     6,     0,    59,     7,
       8,     9,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
      14,    15,     0,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,   771,    27,     0,     0,     6,     0,    28,
       7,     8,     9,    29,    30,    31,     0,     0,    32,     0,
      33,     0,    34,    35,    36,    37,     0,     0,     0,    38,
       0,     0,     0,    39,     0,     0,    40,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,    26,     0,    27,     0,     0,     0,     0,
      28,     0,     0,     0,    29,    30,    31,     0,     0,    32,
     778,    33,     0,    34,    35,    36,    37,     0,     0,     0,
      38,     0,     0,     0,    39,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,    42,    43,     0,     0,    44,
       0,     0,    45,    46,    47,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,    58,     0,     0,    59,     0,     0,     0,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     6,     0,    59,     7,     8,     9,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,     0,     0,     0,     0,    28,     0,     0,  -299,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
      39,     0,     0,    40,     0,     0,     0,     6,     0,     0,
       7,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,    26,     0,    27,     0,     0,     0,     0,
      28,     0,     0,     0,    29,    30,    31,     0,   943,    32,
       0,    33,     0,    34,    35,    36,    37,     0,     0,     0,
      38,     0,    42,    43,    39,     0,    44,    40,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,    41,    58,     0,
       0,    59,     0,     0,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     6,     0,    59,     7,     8,     9,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,   984,     0,     6,     0,    28,     7,     8,     9,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
      39,     0,     0,    40,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,  -286,    25,
      26,     0,    27,     0,     0,     0,     0,    28,     0,     0,
       0,    29,    30,    31,     0,     0,    32,     0,    33,     0,
      34,    35,    36,    37,     0,     0,     0,    38,     0,     0,
       0,    39,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     0,
       0,    59,     0,     0,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
       6,     0,    59,     7,     8,     9,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,    26,     0,    27,  1114,
       0,     6,     0,    28,     7,     8,     9,    29,    30,    31,
       0,     0,    32,     0,    33,     0,    34,    35,    36,    37,
       0,     0,     0,    38,     0,     0,     0,    39,     0,     0,
      40,    10,    11,    12,    13,    14,    15,     0,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,     0,    27,
    1116,     0,     0,     0,    28,     0,     0,     0,    29,    30,
      31,     0,     0,    32,     0,    33,     0,    34,    35,    36,
      37,     0,     0,     0,    38,     0,     0,     0,    39,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,     0,     0,    59,     0,
       0,     0,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,     0,    44,     0,     0,    45,    46,    47,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,    58,     6,     0,    59,
       7,     8,     9,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,    26,     0,    27,  1266,     0,     6,     0,
      28,     7,     8,     9,    29,    30,    31,     0,     0,    32,
       0,    33,     0,    34,    35,    36,    37,     0,     0,     0,
      38,     0,     0,     0,    39,     0,     0,    40,    10,    11,
      12,    13,    14,    15,     0,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    22,    23,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,  1267,     0,     0,
       0,    28,     0,     0,     0,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     0,     0,    39,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     0,     0,    59,     0,     0,     0,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,    44,     0,     0,    45,    46,    47,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    58,     6,     0,    59,     7,     8,     9,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,     0,    27,     0,     0,     6,     0,    28,     7,     8,
       9,    29,    30,    31,     0,     0,    32,     0,    33,     0,
      34,    35,    36,    37,     0,     0,     0,    38,  1475,     0,
       0,    39,     0,     0,    40,    10,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    22,    23,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
      25,    26,     0,    27,     0,     0,     0,     0,    28,     0,
       0,     0,    29,    30,    31,     0,     0,    32,     0,    33,
       0,    34,    35,    36,    37,     0,     0,     0,    38,  1508,
       0,     0,    39,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
       0,     0,    59,   127,     0,     0,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,    42,    43,     0,     0,    44,     0,
       0,    45,    46,    47,    48,    49,    50,     0,     0,     0,
      51,    52,    53,    54,    55,    56,    57,     0,   135,     0,
      58,     0,   136,    59,     0,   137,     0,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   127,     0,
       0,   224,   225,   226,     0,     0,   227,     0,     0,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
     234,   235,   236,   237,   238,   128,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,     0,
     239,   240,   241,   242,   267,     0,   243,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,   136,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   127,     0,     0,   224,   225,   226,     0,
       0,   227,     0,     0,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,   234,   235,   236,   237,   238,
     128,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,     0,   239,   240,   241,   242,     0,
       0,   243,   534,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   127,     0,
       0,   224,   225,   226,     0,     0,   227,     0,     0,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
     234,   235,   236,   237,   238,   128,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,     0,
     239,   240,   241,   242,     0,     0,   243,   536,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,   136,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   127,     0,     0,   224,   225,   226,     0,
       0,   227,     0,     0,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,   234,   235,   236,   237,   238,
     128,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,     0,   239,   240,   241,   242,     0,
       0,   243,   538,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   127,     0,
       0,   224,   225,   226,     0,     0,   227,     0,     0,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
     234,   235,   236,   237,   238,   128,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,     0,
     239,   240,   241,   242,     0,     0,   243,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   127,     0,     0,   224,   225,   226,     0,
       0,   227,     0,     0,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,   234,   235,   236,   237,   238,
     128,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,     0,   239,   240,   241,   242,     0,
       0,   243,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,     0,     0,
       0,   224,   225,   226,     0,     0,   227,     0,     0,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,   243,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,     0,
       0,   523,   524,   525,   526,   527,     0,     0,     0,   531,
     532,   533,   535,   537,   539,     0,     0,     0,     0,   544,
     545,   546,   547,   548,   549,   550,     0,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,     0,     0,     0,     0,
       0,     0,     0,     0,   589,   590,   591,   592,   593,   594,
     595,     0,   597
};

static const yytype_int16 yycheck[] =
{
      10,   645,    10,    46,    14,    46,    46,    46,   652,    12,
      20,    46,    22,    16,    24,    25,    26,   439,   440,   441,
      46,    46,    46,    46,    27,   447,    46,    46,    46,    46,
      33,    34,    35,    36,    11,    12,    13,    14,    52,    46,
      46,    73,    73,   657,    46,   100,     0,     1,   198,   103,
       4,     5,     6,   100,   100,   100,   100,    60,   100,    62,
      63,    64,   100,   100,     0,   100,     3,   103,   242,   947,
     104,   779,   238,   198,   100,   100,   100,    31,    32,    33,
      34,    35,    36,   100,    38,    39,    40,    41,    42,     7,
       8,     9,   242,   100,   100,   817,   818,   109,   100,    53,
      54,    55,   824,   825,   826,   827,   828,    97,    62,   238,
      97,   208,    66,    67,   109,    69,   126,   242,   108,   227,
      74,   108,   198,   102,    78,    79,    80,   242,   107,    83,
     238,    85,   104,    87,    88,    89,    90,    29,    30,    99,
      94,    30,   211,   851,    98,   242,   790,   101,   108,   244,
      99,    43,    44,    45,    43,    44,   800,    49,    50,   108,
      49,    50,  1040,   102,   102,   243,   242,   121,   107,   107,
      29,    30,   242,   242,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    43,    44,    45,   242,   242,   803,
      49,    50,   103,   104,   105,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   102,
     242,   242,   104,   242,   107,   104,   242,   242,   242,   242,
      99,   102,   242,   242,   242,   242,   107,   242,   242,   108,
     198,   242,   244,   243,   242,   242,   242,   209,   102,   102,
     242,   213,   214,   107,   107,   104,   200,   201,   238,   244,
     204,   238,   238,   207,   208,   209,   210,   211,   212,   238,
     263,   238,   216,   217,   218,   219,   220,   221,   222,   106,
     242,   102,   226,   238,   242,   229,   107,   227,   238,   233,
     234,   235,   236,   237,   238,   238,   296,   297,   238,   238,
    1012,  1013,   102,   238,    29,    30,   210,   107,   209,   238,
     238,   244,   213,   214,   238,   102,   102,   102,    43,    44,
     107,   107,   107,   238,    49,    50,   102,    90,   249,   250,
     102,   107,   102,   215,   968,   107,   215,   107,   242,   238,
     102,   242,   220,   221,   238,   107,   207,   208,   243,   349,
     350,   351,   352,    75,    76,   238,   245,   246,   121,   244,
     360,   241,   774,   775,   242,   777,   215,   238,   244,   238,
     207,   208,   244,   200,   201,   202,   203,   204,   205,   104,
     244,   242,   245,   246,   238,   238,    11,    12,    13,    14,
     390,   391,   392,   393,   245,   246,   808,    11,    12,    13,
      14,   228,   244,   396,   397,   242,   245,   246,   408,   220,
     221,   244,   405,    11,    12,    13,    14,   238,  1052,  1053,
      11,    12,    13,    14,  1058,   244,   234,   427,   428,   244,
     430,   242,   245,   246,   434,   435,   429,   200,   201,   247,
     248,   204,   442,   443,   207,   208,   209,   210,   211,   212,
     244,   238,   238,   238,   244,   218,   219,   220,   221,   222,
      71,    72,   238,   423,   424,   425,   238,   244,   238,    11,
      12,    13,    14,   244,   474,   238,   238,   200,   201,    92,
     105,   204,   247,   248,   207,   208,   209,   210,   211,   212,
     215,   105,   243,   245,   246,   218,   219,   220,   221,   222,
     251,   252,   253,   254,   255,   231,   232,   105,   244,    51,
      11,   234,    13,   239,   105,   238,   244,    18,    19,   231,
     232,   231,   232,   231,   232,   937,   244,   239,   940,   239,
     942,   239,    43,    44,    11,    12,    13,    14,    49,    50,
     414,   415,   416,   417,   418,   419,   420,    22,    23,    24,
      25,    26,    27,    22,    23,    24,    25,    26,    27,    11,
      12,    13,    14,    11,    12,    13,    14,   245,   246,   245,
     246,   245,   246,   245,   246,   244,  1210,  1211,   245,   246,
    1214,  1215,  1216,   245,   246,   244,  1220,   245,   246,   244,
       0,     1,   245,   246,     4,     5,     6,   245,   246,   245,
     246,   245,   246,   245,   246,   245,   246,   245,   246,   245,
     246,   245,   246,   245,   246,   244,  1028,   245,   246,   245,
     246,    31,    32,    33,    34,    35,    36,   620,    38,    39,
      40,    41,    42,   245,   246,   245,   246,   245,   246,   245,
     246,   245,   246,    53,    54,    55,   245,   246,   245,   246,
     245,   246,    62,    91,   654,   244,    66,    67,   244,    69,
     660,   661,   662,   244,    74,   665,   245,   246,    78,    79,
      80,   245,   246,    83,   244,    85,   244,    87,    88,    89,
      90,   245,   246,   244,    94,   245,   246,   244,    98,   245,
     246,   101,   245,   246,   245,   246,   245,   246,   245,   246,
     244,  1113,   230,  1115,   244,   705,   245,   246,   245,   246,
     244,   121,   245,   246,   245,   246,   245,   246,   245,   246,
     245,   246,   245,   246,   245,   246,   245,   246,   245,   246,
     245,   246,   245,   246,   243,   245,   246,   245,   246,   245,
     246,   245,   246,   245,   246,   245,   246,   245,   246,   245,
     246,   245,   246,   245,   246,   245,   246,   245,   246,   245,
     246,   242,   243,    63,    64,   245,   246,   245,   246,   245,
     246,   244,   772,   773,   245,   246,   242,   245,   246,   244,
    1192,    47,    48,    47,    48,    47,    48,   245,   246,   244,
     200,   201,   245,   246,   204,    47,    48,   207,   208,   209,
     210,   211,   212,    47,    48,   805,   216,   217,   218,   219,
     220,   221,   222,    47,    48,   244,   226,     3,     4,   229,
     421,   422,   244,   233,   234,   235,   236,   237,   238,   244,
     244,   244,   244,   244,   109,   244,   244,   244,   838,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,  1268,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   243,   243,   242,   242,   889,
     243,   891,   243,   893,   242,   242,     1,    56,   242,     4,
       5,     6,   242,   242,    75,   243,   242,   242,   242,   242,
     242,    49,   242,   242,   234,   242,   196,   238,   197,   197,
     242,   244,   238,   242,   242,   242,    31,    32,    33,    34,
      35,    36,   244,    38,    39,    40,    41,    42,   244,   939,
     244,   941,   244,   242,   245,   239,   244,   244,   244,    54,
      55,   244,   244,   244,   244,   242,   242,    62,    63,    64,
      65,    66,    67,   245,    69,   246,   238,   238,   245,    74,
     246,   245,   245,    78,    79,    80,   245,   245,    83,  1391,
      85,   242,    87,    88,    89,    90,   245,   242,   244,    94,
     244,   244,    77,    98,   244,   995,   101,   244,   244,   244,
     238,  1001,   244,   242,   244,   206,  1006,   244,   244,    96,
     245,   242,   245,   239,   244,   239,   121,   239,   239,   244,
     239,   244,   239,  1435,   239,   239,   239,   245,   109,   245,
      65,    30,   242,   245,   103,   246,   245,   245,   245,   245,
     245,   245,   245,   245,   242,   245,   242,   242,   242,   242,
     242,   242,   239,   241,   239,   239,   239,   246,    30,   238,
     238,    30,   244,   244,   244,   242,   242,   242,   242,   238,
     238,    30,   242,   245,   238,  1075,   249,  1077,   245,   245,
    1080,   246,   245,  1083,   245,   245,   241,   245,   245,   245,
     242,  1091,   246,   242,  1094,   200,   201,   242,   242,   204,
     246,   242,   207,   208,   209,   210,   211,   212,   245,   245,
     245,   216,   217,   218,   219,   220,   221,   222,   245,   238,
     246,   226,     1,   246,   229,     4,     5,     6,   233,   234,
     235,   236,   237,   238,   245,   245,   242,   238,   246,   239,
     239,   245,   245,   245,   242,   241,   239,   238,   238,   246,
     245,   245,    31,    32,    33,    34,    35,    36,   242,    38,
      39,    40,    41,    42,   246,   245,   245,   245,   242,   242,
     245,   242,   242,   239,   246,    54,    55,   245,   239,   242,
     239,   245,  1182,    62,   244,   242,   244,    66,    67,   244,
      69,   244,   244,   242,   242,    74,    75,    76,    77,    78,
      79,    80,   242,   249,    83,   244,    85,   244,    87,    88,
      89,    90,   244,   244,   242,    94,   245,   244,   244,    98,
     244,   242,   101,   245,   244,   244,     1,   244,   244,     4,
       5,     6,   242,   242,   242,   242,  1236,   242,  1238,   242,
     242,   242,   121,   103,   242,   242,   242,   242,   103,   242,
     238,   245,   244,   244,   244,   244,    31,    32,    33,    34,
      35,    36,  1262,    38,    39,    40,    41,    42,   244,   239,
     245,   239,   245,   244,   239,   242,   242,   239,   242,    54,
      55,   242,   245,   239,   244,   239,   244,    62,    63,    64,
      65,    66,    67,   244,    69,   244,   244,   239,   242,    74,
     245,   242,   245,    78,    79,    80,   244,   244,    83,   245,
      85,   245,    87,    88,    89,    90,   244,   244,   239,    94,
     238,   200,   201,    98,   238,   204,   101,   244,   207,   208,
     209,   210,   211,   212,   238,   244,   238,   216,   217,   218,
     219,   220,   221,   222,   242,   245,   121,   226,   245,   245,
     229,   245,   245,   245,   233,   234,   235,   236,   237,   238,
     242,   242,   245,   238,   244,   239,   244,   244,   244,   239,
     239,   239,   245,   245,   239,   103,   239,   239,   239,   245,
     239,   238,   246,    30,    48,  1036,    -1,   245,   655,   245,
     242,   245,   242,   246,   245,    48,   245,   245,   245,   245,
     244,   246,   245,   245,   245,   245,   460,   246,   246,   245,
     245,   244,   244,   242,   242,   242,   242,   242,   238,   242,
     239,   239,   239,   239,   245,   200,   201,   239,   239,   204,
     245,   245,   207,   208,   209,   210,   211,   212,   246,   245,
     242,   216,   217,   218,   219,   220,   221,   222,   242,   242,
     242,   226,     1,   242,   229,     4,     5,     6,   233,   234,
     235,   236,   237,   238,   245,   242,   242,   245,   239,    47,
      47,   245,   245,   242,   246,   245,   242,   245,   245,   244,
     244,   242,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   245,   242,   245,   242,   242,   242,
     242,   238,   242,   242,   245,    54,    55,   245,   239,   239,
     242,   244,   239,    62,   238,   244,   242,    66,    67,   244,
      69,   244,   244,     1,   244,    74,     4,     5,     6,    78,
      79,    80,   242,   245,    83,   246,    85,   245,    87,    88,
      89,    90,   245,   239,   242,    94,    95,   242,   242,    98,
     242,   242,   101,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   242,   242,   242,   239,   242,
     244,   239,   121,   245,   244,   244,    54,    55,   244,   242,
     242,   242,   242,   242,    62,   242,   242,   245,    66,    67,
     245,    69,   242,   245,   245,   244,    74,   242,   242,   245,
      78,    79,    80,   245,   245,    83,   242,    85,   242,    87,
      88,    89,    90,   244,   244,   244,    94,    95,   239,   239,
      98,   239,   239,   101,   246,   244,   238,   238,   244,   244,
     239,   245,   245,   239,   239,   245,    47,   245,   242,   242,
     242,   242,   239,   121,   242,   245,   242,   242,   242,   242,
     239,   200,   201,   239,   245,   204,   246,   245,   207,   208,
     209,   210,   211,   212,   245,   245,   242,   216,   217,   218,
     219,   220,   221,   222,   242,   242,   245,   226,   244,   244,
     229,   244,   242,   242,   233,   234,   235,   236,   237,   238,
     242,   242,   242,   246,   242,   242,    48,   239,   242,   245,
     245,   244,   242,   242,   242,   242,   239,    48,    47,   245,
     245,   245,   242,   245,   239,   246,   245,   244,   246,   245,
     242,   242,   200,   201,   242,   242,   204,   239,   239,   207,
     208,   209,   210,   211,   212,   244,   244,   244,   216,   217,
     218,   219,   220,   221,   222,   245,   242,   242,   226,     1,
     242,   229,     4,     5,     6,   233,   234,   235,   236,   237,
     238,   245,   245,   242,   245,   245,    47,   244,   242,   245,
     245,   242,   242,   242,   246,   242,    47,   245,   244,    31,
      32,    33,    34,    35,    36,   244,    38,    39,    40,    41,
      42,   244,   242,   245,   245,   242,   245,   245,   242,   242,
     242,   242,    54,    55,    47,   245,   244,   246,   245,   245,
      62,   246,   242,   242,    66,    67,   242,    69,   242,   242,
       1,    48,    74,     4,     5,     6,    78,    79,    80,    81,
     245,    83,   242,    85,    48,    87,    88,    89,    90,   245,
     242,   245,    94,    48,   242,   245,    98,    48,   244,   101,
      31,    32,    33,    34,    35,    36,   242,    38,    39,    40,
      41,    42,   245,   242,   245,   242,   242,   245,    47,   121,
     245,   242,   242,    54,    55,   242,   242,   245,   242,     1,
     444,    62,   137,   244,   408,    66,    67,    68,    69,   412,
      -1,    -1,    -1,    74,   413,    -1,    -1,    78,    79,    80,
      -1,    -1,    83,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,
      -1,    -1,   204,    -1,    -1,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,   229,    -1,    -1,
      -1,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,   226,     1,    -1,   229,     4,
       5,     6,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,     1,    -1,    74,
       4,     5,     6,    78,    79,    80,    -1,    -1,    83,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,   101,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    83,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,   226,    -1,    -1,   229,    -1,    -1,    -1,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,     1,    -1,   229,     4,     5,     6,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,    67,
      -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,     1,    -1,    -1,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    82,    83,
      -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    -1,   200,   201,    98,    -1,   204,   101,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,   121,   226,    -1,
      -1,   229,    -1,    -1,    -1,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,     1,    -1,   229,     4,     5,     6,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,     1,    -1,    74,     4,     5,     6,
      78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,   101,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    66,
      67,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,   229,    -1,    -1,    -1,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,   226,
       1,    -1,   229,     4,     5,     6,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,    -1,    -1,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,   226,     1,    -1,   229,
       4,     5,     6,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      83,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,   229,    -1,    -1,    -1,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,
      -1,   204,    -1,    -1,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,   226,     1,    -1,   229,     4,     5,     6,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,
      67,    -1,    69,    -1,    -1,     1,    -1,    74,     4,     5,
       6,    78,    79,    80,    -1,    -1,    83,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      66,    67,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    83,    -1,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,    -1,    -1,   204,    -1,    -1,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,   226,
      -1,    -1,   229,    21,    -1,    -1,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,   200,   201,    -1,    -1,   204,    -1,
      -1,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,    -1,    86,    -1,
     226,    -1,    90,   229,    -1,    93,    -1,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    21,    -1,
      -1,   199,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,   221,   222,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    -1,
     238,   239,   240,   241,   242,    -1,   244,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    21,    -1,    -1,   199,   200,   201,    -1,
      -1,   204,    -1,    -1,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,   222,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    -1,   238,   239,   240,   241,    -1,
      -1,   244,   245,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    21,    -1,
      -1,   199,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,   221,   222,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    -1,
     238,   239,   240,   241,    -1,    -1,   244,   245,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    21,    -1,    -1,   199,   200,   201,    -1,
      -1,   204,    -1,    -1,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,   222,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    -1,   238,   239,   240,   241,    -1,
      -1,   244,   245,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    21,    -1,
      -1,   199,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,   221,   222,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    -1,
     238,   239,   240,   241,    -1,    -1,   244,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    21,    -1,    -1,   199,   200,   201,    -1,
      -1,   204,    -1,    -1,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,   222,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    -1,   238,   239,   240,   241,    -1,
      -1,   244,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,    -1,
      -1,   199,   200,   201,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,   240,   241,    -1,    -1,   244,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,    -1,
      -1,   335,   336,   337,   338,   339,    -1,    -1,    -1,   343,
     344,   345,   346,   347,   348,    -1,    -1,    -1,    -1,   353,
     354,   355,   356,   357,   358,   359,    -1,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,   403,
     404,    -1,   406
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   257,   258,   258,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    53,    54,    55,    62,    66,    67,    69,    74,    78,
      79,    80,    83,    85,    87,    88,    89,    90,    94,    98,
     101,   121,   200,   201,   204,   207,   208,   209,   210,   211,
     212,   216,   217,   218,   219,   220,   221,   222,   226,   229,
     233,   234,   235,   236,   237,   238,   260,   261,   262,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   301,   305,
     309,   310,   311,   312,   313,   317,   318,   242,   238,   200,
     201,   204,   207,   208,   209,   210,   211,   212,   218,   219,
     220,   221,   222,   234,   238,   329,   238,    21,    48,    56,
      57,    58,    59,    60,    61,    86,    90,    93,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   199,   200,   201,   204,   207,   208,
     209,   210,   211,   212,   218,   219,   220,   221,   222,   238,
     239,   240,   241,   244,   248,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   330,   238,   265,   329,   265,
     319,   242,   329,   244,   265,   265,   319,   242,   319,   243,
     319,   319,   319,   329,   242,   242,   242,   242,   238,   329,
     329,   329,   329,   238,   238,   238,   244,   238,   238,   238,
     329,   238,   329,   329,   329,   109,   244,   243,     7,     8,
       9,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   106,   200,   201,   202,   203,   204,   205,   228,   319,
     323,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   241,   244,   319,
     328,   242,    92,    91,   243,   251,   252,   253,   254,   255,
     234,   247,   248,   249,   250,   230,   109,   244,   243,   243,
     243,   242,   242,   329,   243,   243,   242,   242,    56,   242,
     242,   242,   243,    75,   314,   315,   259,   242,   242,   242,
     242,   242,    49,   283,    11,    12,    13,    14,    51,   284,
     103,   104,   105,   209,   213,   214,   242,   303,   319,   333,
     242,   242,   103,   242,   234,   242,   196,   197,   197,   238,
     319,   331,   332,   319,    10,   242,   242,   242,   244,   244,
     244,   244,   244,   210,   242,   211,   242,   242,   242,   242,
     244,   244,   244,   244,   244,   244,   244,   242,   242,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   245,   245,   333,   333,   333,   333,   333,   245,   245,
     245,   333,   333,   333,   245,   333,   245,   333,   245,   333,
     319,   319,   319,   319,   333,   333,   333,   333,   333,   333,
     333,   319,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   319,   319,   319,   319,   238,   245,   329,   329,   333,
     333,   333,   333,   333,   333,   333,   329,   333,   319,   331,
     245,   321,   322,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   326,   326,   326,   238,   319,   319,   329,   319,
     245,   319,   319,   242,   259,   259,   259,   319,   319,    76,
     315,   316,    81,   260,   259,   242,   244,   244,   244,   244,
     244,    52,   242,   104,   209,   242,   303,   244,   244,   244,
     302,   103,   242,   245,   246,   242,   238,   299,   300,   319,
     244,   244,   244,   245,   245,   246,   242,   244,   239,   239,
     239,   239,   239,   244,   244,   238,   239,   239,   239,   239,
     239,   206,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   246,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   242,   242,   242,   329,   242,   242,   306,
      68,    68,    71,    72,   242,   242,    77,   242,    84,    96,
     239,   239,   239,   239,   241,   244,   287,   244,   244,   302,
     242,   231,   232,   239,   238,   238,   102,   107,   238,   304,
     242,   302,   319,   299,   242,   243,   227,   300,   242,   319,
     319,   319,   109,   242,   319,   249,   245,   245,   245,   246,
     246,   238,   238,   245,   245,   245,   245,   245,   245,   246,
     319,    22,    23,    24,    25,    26,    27,   242,    63,    64,
     307,   308,   242,   242,   319,   319,   259,   259,   242,   259,
     242,   238,   284,   245,   245,   245,   246,   245,   241,    99,
     108,   238,   288,   231,   232,   239,   238,   102,   302,   246,
     246,   245,   245,   245,   246,   242,   238,    11,    12,    13,
      14,   105,   302,   102,   227,   319,   242,   259,   245,   246,
     245,   246,   245,   246,   238,   246,    29,    30,    43,    44,
      45,    49,    50,   104,   215,   263,    30,    49,   104,   215,
     263,    29,    30,    45,    49,   104,   215,   263,   239,   239,
     245,   245,   242,   263,   263,   263,   263,   263,   241,   246,
     245,   245,   245,   245,   245,   245,   319,   242,    65,    73,
     242,    73,   242,    82,   284,   242,   239,   242,   245,   242,
     238,    11,    12,    13,    14,   105,   246,   246,   245,   245,
     246,   242,   102,   239,   239,   103,   104,   242,   242,   239,
      11,    12,    13,    14,   105,   244,   244,   244,   244,   244,
     102,   242,   242,   242,    70,   242,   319,   198,   242,   319,
     198,   242,   319,   249,    30,   244,   244,    30,   244,   244,
     242,   244,   244,   244,   242,    30,   244,   244,    30,   244,
     244,   242,   245,   245,   242,   242,   242,   242,   242,   242,
     242,   245,    22,    23,    24,    25,    26,    27,   242,   259,
     242,   319,   259,   319,   259,   242,   242,   285,   245,   287,
     242,    11,    12,    13,    14,   244,   244,   244,   244,   244,
     239,   239,   242,   242,   239,   242,   245,   245,   242,   244,
     302,   245,   244,   244,   244,   244,   244,   239,   239,   239,
     239,   238,   242,   242,   245,   244,   245,   244,   245,   245,
     244,   319,   238,   244,   239,   238,   319,   231,   232,   239,
     238,   244,   319,   238,   244,   231,   232,   239,   238,    29,
      30,   104,   215,   263,   263,   242,   245,   245,   245,   245,
     245,   245,   259,   242,    70,   242,    70,   285,    97,   108,
     238,   286,    99,   287,   244,   244,   244,   244,   239,   239,
     239,   239,   238,   245,   245,   302,   302,   245,   103,   103,
     302,   239,   102,   103,   239,   239,   239,   239,   238,   245,
     245,   245,   246,   245,   242,   319,   198,   242,   319,   198,
     242,   242,   319,   245,   245,   319,   245,   245,   245,   246,
     246,   245,   245,   319,   245,   245,   319,   246,   246,   245,
     245,    30,   244,   244,   244,   242,   242,   259,   242,   259,
     242,    97,   242,   238,    11,    12,    13,    14,   105,   242,
      99,   239,   239,   239,   239,   245,   245,   245,   246,   245,
     242,   242,   102,   102,   242,   242,   242,   102,   245,   242,
     242,   245,   245,   245,   246,   245,   207,   208,   242,   242,
     207,   208,   242,   239,   242,   245,   244,   245,   244,   245,
     242,   242,   245,   220,   221,   242,   242,   242,   239,   239,
     242,   242,   245,   242,   242,   245,   239,   239,   220,   221,
     242,   242,   244,   319,   239,   238,    70,    70,   242,   259,
      11,    12,    13,    14,   244,   244,   244,   244,   244,   242,
     245,   245,   245,   246,    46,   100,   242,    46,   100,   242,
      46,   100,   242,   239,   242,   302,   302,   242,   242,   302,
     302,   302,   242,   242,   302,   242,   242,   242,   239,   242,
     244,   244,   244,   244,   245,   242,   319,   242,   319,   242,
     242,   242,   242,   245,   245,   242,   242,   245,   245,   242,
     242,   319,   245,   245,   245,   242,   242,   259,    37,    95,
     244,   244,   244,   244,   239,   239,   239,   239,   238,   100,
     242,   100,   242,   100,   242,   239,   244,    46,   242,   244,
      46,   242,   244,    46,   242,   245,   102,   102,   102,   102,
     102,   102,   245,   238,   239,   238,   239,   208,   242,   245,
     245,   242,   242,   242,   242,   245,   242,   242,   242,    37,
      95,   242,   242,   239,   239,   239,   239,   245,   245,   245,
     246,   245,   242,   242,   242,   245,    47,    48,   244,    47,
      48,   244,    47,    48,   244,    46,   100,   242,   242,   242,
     242,   242,   242,   242,   242,   245,   246,   245,   245,   246,
     245,   244,   242,   242,   242,   242,   242,   259,   245,   245,
     245,   246,    46,   100,   242,    46,   100,   242,    46,   100,
     242,   239,   242,   100,   242,   246,   245,    47,   246,   245,
      47,   246,   245,    47,   244,    46,   242,   242,   239,   242,
     242,   239,   242,   239,   259,    95,   100,   242,   100,   242,
     100,   242,   239,   244,    46,   242,   244,    46,   242,   244,
      46,   242,   245,   242,    48,   242,   245,    48,   242,   245,
      48,   242,   245,    48,   244,   245,   245,   245,    95,   242,
     242,   242,   242,   245,    47,    48,   244,    47,    48,   244,
      47,    48,   244,    46,   100,   242,   245,   242,   245,   242,
     245,   242,   245,    47,   242,   242,   242,   242,   100,   242,
     246,   245,    47,   246,   245,    47,   246,   245,    47,   244,
      46,   242,   242,   242,   242,   242,   245,   242,    48,   242,
     245,    48,   242,   245,    48,   242,   245,    48,   244,   242,
     245,   242,   245,   242,   245,   242,   245,    47,   242,   242,
     242,   242,   245,   242
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   256,   257,   257,   258,   258,   258,   259,   259,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     261,   261,   261,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     263,   263,   263,   263,   263,   264,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   266,   266,   266,   267,
     268,   268,   269,   269,   269,   269,   270,   270,   270,   270,
     271,   272,   273,   274,   274,   275,   275,   276,   277,   278,
     279,   279,   280,   281,   281,   281,   282,   282,   282,   282,
     283,   283,   284,   284,   284,   284,   284,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   287,   287,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   298,   299,   299,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     302,   302,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   305,   306,   306,   307,   308,   308,   309,   310,   311,
     311,   311,   311,   312,   313,   314,   314,   315,   316,   316,
     317,   318,   319,   320,   320,   321,   321,   322,   322,   323,
     323,   323,   323,   323,   323,   323,   323,   324,   324,   324,
     325,   325,   325,   326,   326,   327,   327,   328,   328,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   331,   331,   332,   332,
     333,   333
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,    10,     8,     8,     8,    10,    10,    12,    12,
      14,    11,    11,    13,    11,    12,    12,     4,     4,     4,
       4,     4,     4,    11,    11,    11,    13,    13,    13,    13,
      13,     7,     8,     8,     8,     8,     8,     9,    11,    11,
      12,    12,    12,    12,     8,     8,    11,    11,    11,    13,
       0,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     6,     4,     4,     5,     5,     5,
       9,     7,    13,     9,    11,     7,    13,     9,    11,     7,
       3,     3,     3,     5,     5,     3,     3,     2,     3,     4,
       3,     2,     5,     7,    11,    10,    13,    14,    16,    17,
       0,     1,     0,     4,     4,     4,     6,     0,     2,     6,
       7,     6,     7,     6,     7,     8,     9,     7,     8,     7,
       8,     7,     8,     9,    10,     6,    11,    11,    11,    13,
      10,    10,    10,    12,    12,    12,    12,     0,     2,     6,
       7,     6,     7,     6,     7,     8,     9,     7,     8,     7,
       8,     7,     8,     9,    10,     6,    11,    11,    11,    13,
      10,    10,    10,    12,    12,    12,    12,     8,     6,     3,
       3,     3,     3,     3,     6,     1,     7,     6,     1,     2,
       2,     4,     7,     6,    11,    11,    13,    13,    13,    13,
       7,    11,    11,    13,    13,    10,     8,     8,     7,     4,
       0,     2,     1,     1,     6,     6,     6,     8,     7,     7,
       7,     9,    10,    10,    12,    10,    12,    10,    12,     6,
       7,     8,     0,     2,     4,     0,     3,     6,     6,    10,
      12,    10,    12,     8,     6,     1,     2,     4,     0,     3,
       2,     2,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       6,     4,     4,     4,     4,     3,     3,     4,     4,     4,
       4,     4,     4,     3,     4,     3,     4,     3,     8,     8,
       8,     4,     4,     4,     3,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     1,
       8,     8,     8,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     3,
       1,     3
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
#line 198 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3179 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 201 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3187 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 208 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3197 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 213 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3208 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 222 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3216 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 225 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3227 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3233 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3239 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3245 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3251 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 238 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3257 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3263 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3269 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3275 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 242 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3281 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3287 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3293 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3299 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3305 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 247 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3311 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 248 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3317 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 249 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3323 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3329 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3335 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3341 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3347 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3353 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3359 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3365 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3371 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3377 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3383 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3389 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3395 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 262 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3401 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 263 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3407 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 264 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3413 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 265 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3419 "build/parser.cpp"
    break;

  case 41: /* statement: xml_into_stmt  */
#line 266 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3425 "build/parser.cpp"
    break;

  case 42: /* statement: data_into_stmt  */
#line 267 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3431 "build/parser.cpp"
    break;

  case 43: /* statement: data_gen_stmt  */
#line 268 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3437 "build/parser.cpp"
    break;

  case 44: /* statement: in_da_stmt  */
#line 269 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3443 "build/parser.cpp"
    break;

  case 45: /* statement: out_da_stmt  */
#line 270 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3449 "build/parser.cpp"
    break;

  case 46: /* statement: unlock_da_stmt  */
#line 271 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3455 "build/parser.cpp"
    break;

  case 47: /* statement: expr_stmt  */
#line 272 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3461 "build/parser.cpp"
    break;

  case 48: /* statement: error SEMICOLON  */
#line 273 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3467 "build/parser.cpp"
    break;

  case 49: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 278 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3476 "build/parser.cpp"
    break;

  case 50: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 282 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3485 "build/parser.cpp"
    break;

  case 51: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 286 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3494 "build/parser.cpp"
    break;

  case 52: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 290 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3503 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 298 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3513 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 303 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3523 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 308 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3533 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 313 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3543 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 318 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3553 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 323 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3563 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 328 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3573 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 333 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3583 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 338 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3593 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 343 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3603 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 348 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3613 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 353 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3623 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 359 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3634 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 365 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3645 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 371 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3654 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 375 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3663 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 379 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3672 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 383 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3681 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 387 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3690 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 391 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3699 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 395 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3708 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 399 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3717 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 403 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3726 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 407 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3735 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 411 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3746 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 417 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3757 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 423 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3768 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 429 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3779 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 435 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3791 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 442 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3801 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 447 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3812 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 453 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3822 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 458 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3832 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 463 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3842 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 468 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3852 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 473 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3862 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 478 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3872 "build/parser.cpp"
    break;

  case 90: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 483 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3882 "build/parser.cpp"
    break;

  case 91: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 488 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3892 "build/parser.cpp"
    break;

  case 92: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 493 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3902 "build/parser.cpp"
    break;

  case 93: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 498 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3912 "build/parser.cpp"
    break;

  case 94: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 503 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3922 "build/parser.cpp"
    break;

  case 95: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 508 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3932 "build/parser.cpp"
    break;

  case 96: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 513 "src/parser.y"
                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3942 "build/parser.cpp"
    break;

  case 97: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 518 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3952 "build/parser.cpp"
    break;

  case 98: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 523 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3962 "build/parser.cpp"
    break;

  case 99: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 528 "src/parser.y"
                                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-11].sval)); free((yyvsp[-2].sval));
    }
#line 3972 "build/parser.cpp"
    break;

  case 100: /* dcl_s_keywords: %empty  */
#line 536 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3978 "build/parser.cpp"
    break;

  case 101: /* dcl_s_keywords: KW_STATIC  */
#line 537 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3984 "build/parser.cpp"
    break;

  case 102: /* dcl_s_keywords: KW_TEMPLATE  */
#line 538 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3990 "build/parser.cpp"
    break;

  case 103: /* dcl_s_keywords: KW_EXPORT  */
#line 539 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3996 "build/parser.cpp"
    break;

  case 104: /* dcl_s_keywords: KW_IMPORT  */
#line 540 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 4002 "build/parser.cpp"
    break;

  case 105: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 545 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 4011 "build/parser.cpp"
    break;

  case 106: /* eval_target: IDENTIFIER  */
#line 552 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4020 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_POS  */
#line 556 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 4026 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_OVERLAY  */
#line 557 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 4032 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_PREFIX  */
#line 558 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 4038 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_UNS  */
#line 559 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 4044 "build/parser.cpp"
    break;

  case 111: /* eval_target: KW_FLOAT_TYPE  */
#line 560 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 4050 "build/parser.cpp"
    break;

  case 112: /* eval_target: KW_GRAPH  */
#line 561 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 4056 "build/parser.cpp"
    break;

  case 113: /* eval_target: KW_ASCEND  */
#line 562 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 4062 "build/parser.cpp"
    break;

  case 114: /* eval_target: KW_DESCEND  */
#line 563 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 4068 "build/parser.cpp"
    break;

  case 115: /* eval_target: KW_RTNPARM  */
#line 564 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4074 "build/parser.cpp"
    break;

  case 116: /* eval_target: KW_OPDESC  */
#line 565 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4080 "build/parser.cpp"
    break;

  case 117: /* eval_target: KW_NULLIND  */
#line 566 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4086 "build/parser.cpp"
    break;

  case 118: /* eval_target: KW_DATFMT  */
#line 567 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4092 "build/parser.cpp"
    break;

  case 119: /* eval_target: KW_TIMFMT  */
#line 568 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4098 "build/parser.cpp"
    break;

  case 120: /* eval_target: KW_EXTNAME  */
#line 569 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4104 "build/parser.cpp"
    break;

  case 121: /* eval_target: INDICATOR  */
#line 570 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 4112 "build/parser.cpp"
    break;

  case 122: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 573 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 4123 "build/parser.cpp"
    break;

  case 123: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 579 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 4132 "build/parser.cpp"
    break;

  case 124: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 583 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 4143 "build/parser.cpp"
    break;

  case 125: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 589 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 4151 "build/parser.cpp"
    break;

  case 126: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 595 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4162 "build/parser.cpp"
    break;

  case 127: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 601 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4173 "build/parser.cpp"
    break;

  case 128: /* eval_stmt: KW_EVAL_EXT eval_target EQUALS expression SEMICOLON  */
#line 607 "src/parser.y"
                                                          {
        auto* s = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
        s->extenders = (yyvsp[-4].sval); free((yyvsp[-4].sval));
        (yyval.stmt) = s;
    }
#line 4186 "build/parser.cpp"
    break;

  case 129: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 618 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4196 "build/parser.cpp"
    break;

  case 130: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 626 "src/parser.y"
                                                                                  {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-7].sval));
    }
#line 4207 "build/parser.cpp"
    break;

  case 131: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression RPAREN SEMICOLON  */
#line 632 "src/parser.y"
                                                                   {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-5].sval));
    }
#line 4218 "build/parser.cpp"
    break;

  case 132: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression COLON expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 641 "src/parser.y"
                                                                                                                        {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-11].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 4230 "build/parser.cpp"
    break;

  case 133: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 648 "src/parser.y"
                                                                                      {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-7].sval));
    }
#line 4242 "build/parser.cpp"
    break;

  case 134: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 655 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-9].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            nullptr,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 4254 "build/parser.cpp"
    break;

  case 135: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression RPAREN SEMICOLON  */
#line 662 "src/parser.y"
                                                                     {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr, nullptr);
        free((yyvsp[-5].sval));
    }
#line 4265 "build/parser.cpp"
    break;

  case 136: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression COLON expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 671 "src/parser.y"
                                                                                                                       {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-11].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 4277 "build/parser.cpp"
    break;

  case 137: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 678 "src/parser.y"
                                                                                     {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-7].sval));
    }
#line 4289 "build/parser.cpp"
    break;

  case 138: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression RPAREN BIF_PARSER LPAREN expression RPAREN SEMICOLON  */
#line 685 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-9].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            nullptr,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 4301 "build/parser.cpp"
    break;

  case 139: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression RPAREN SEMICOLON  */
#line 692 "src/parser.y"
                                                                    {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr, nullptr);
        free((yyvsp[-5].sval));
    }
#line 4312 "build/parser.cpp"
    break;

  case 140: /* in_da_stmt: KW_IN IDENTIFIER SEMICOLON  */
#line 701 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DataInStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4321 "build/parser.cpp"
    break;

  case 141: /* out_da_stmt: KW_OUT IDENTIFIER SEMICOLON  */
#line 708 "src/parser.y"
                                {
        (yyval.stmt) = new rpg::DataOutStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4330 "build/parser.cpp"
    break;

  case 142: /* unlock_da_stmt: KW_UNLOCK IDENTIFIER SEMICOLON  */
#line 715 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::DataUnlockStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4339 "build/parser.cpp"
    break;

  case 143: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 722 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4350 "build/parser.cpp"
    break;

  case 144: /* evalr_stmt: KW_EVALR_EXT eval_target EQUALS expression SEMICOLON  */
#line 728 "src/parser.y"
                                                           {
        auto* s = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
        s->extenders = (yyvsp[-4].sval); free((yyvsp[-4].sval));
        (yyval.stmt) = s;
    }
#line 4363 "build/parser.cpp"
    break;

  case 145: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 739 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), "");
    }
#line 4371 "build/parser.cpp"
    break;

  case 146: /* callp_stmt: KW_CALLP_EXT expression SEMICOLON  */
#line 742 "src/parser.y"
                                        {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), (yyvsp[-2].sval));
        free((yyvsp[-2].sval));
    }
#line 4380 "build/parser.cpp"
    break;

  case 147: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 749 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4388 "build/parser.cpp"
    break;

  case 148: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 755 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4396 "build/parser.cpp"
    break;

  case 149: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 761 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4404 "build/parser.cpp"
    break;

  case 150: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 767 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4412 "build/parser.cpp"
    break;

  case 151: /* return_stmt: KW_RETURN SEMICOLON  */
#line 770 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4420 "build/parser.cpp"
    break;

  case 152: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 777 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4430 "build/parser.cpp"
    break;

  case 153: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 788 "src/parser.y"
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
#line 4451 "build/parser.cpp"
    break;

  case 154: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 805 "src/parser.y"
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
#line 4475 "build/parser.cpp"
    break;

  case 155: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 825 "src/parser.y"
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
#line 4491 "build/parser.cpp"
    break;

  case 156: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 843 "src/parser.y"
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
#line 4516 "build/parser.cpp"
    break;

  case 157: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 867 "src/parser.y"
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
#line 4542 "build/parser.cpp"
    break;

  case 158: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 893 "src/parser.y"
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
#line 4569 "build/parser.cpp"
    break;

  case 159: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 920 "src/parser.y"
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
#line 4597 "build/parser.cpp"
    break;

  case 160: /* proc_export: %empty  */
#line 946 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4603 "build/parser.cpp"
    break;

  case 161: /* proc_export: KW_EXPORT  */
#line 947 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4609 "build/parser.cpp"
    break;

  case 162: /* pi_return_type: %empty  */
#line 952 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4615 "build/parser.cpp"
    break;

  case 163: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 953 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4621 "build/parser.cpp"
    break;

  case 164: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 954 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4627 "build/parser.cpp"
    break;

  case 165: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 955 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4633 "build/parser.cpp"
    break;

  case 166: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 956 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4639 "build/parser.cpp"
    break;

  case 167: /* pi_params: %empty  */
#line 961 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4647 "build/parser.cpp"
    break;

  case 168: /* pi_params: pi_params pi_param  */
#line 964 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4657 "build/parser.cpp"
    break;

  case 169: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 972 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4666 "build/parser.cpp"
    break;

  case 170: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 976 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4675 "build/parser.cpp"
    break;

  case 171: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 980 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4684 "build/parser.cpp"
    break;

  case 172: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 984 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4693 "build/parser.cpp"
    break;

  case 173: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 988 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4702 "build/parser.cpp"
    break;

  case 174: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 992 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4711 "build/parser.cpp"
    break;

  case 175: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 996 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4720 "build/parser.cpp"
    break;

  case 176: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1000 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4729 "build/parser.cpp"
    break;

  case 177: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1005 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4738 "build/parser.cpp"
    break;

  case 178: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1009 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4747 "build/parser.cpp"
    break;

  case 179: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1013 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4756 "build/parser.cpp"
    break;

  case 180: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1017 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4765 "build/parser.cpp"
    break;

  case 181: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1021 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4774 "build/parser.cpp"
    break;

  case 182: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1025 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4783 "build/parser.cpp"
    break;

  case 183: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1029 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4792 "build/parser.cpp"
    break;

  case 184: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1033 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4801 "build/parser.cpp"
    break;

  case 185: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1037 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4811 "build/parser.cpp"
    break;

  case 186: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1043 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4821 "build/parser.cpp"
    break;

  case 187: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1048 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4831 "build/parser.cpp"
    break;

  case 188: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1053 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4841 "build/parser.cpp"
    break;

  case 189: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1058 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4851 "build/parser.cpp"
    break;

  case 190: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1064 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4861 "build/parser.cpp"
    break;

  case 191: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1069 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4871 "build/parser.cpp"
    break;

  case 192: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1074 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4881 "build/parser.cpp"
    break;

  case 193: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1079 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4891 "build/parser.cpp"
    break;

  case 194: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1085 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4901 "build/parser.cpp"
    break;

  case 195: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1090 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4911 "build/parser.cpp"
    break;

  case 196: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1095 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4921 "build/parser.cpp"
    break;

  case 197: /* pr_params: %empty  */
#line 1104 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4929 "build/parser.cpp"
    break;

  case 198: /* pr_params: pr_params pr_param  */
#line 1107 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4939 "build/parser.cpp"
    break;

  case 199: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1115 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4948 "build/parser.cpp"
    break;

  case 200: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1119 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4957 "build/parser.cpp"
    break;

  case 201: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1123 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4966 "build/parser.cpp"
    break;

  case 202: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1127 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4975 "build/parser.cpp"
    break;

  case 203: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1131 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4984 "build/parser.cpp"
    break;

  case 204: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1135 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4993 "build/parser.cpp"
    break;

  case 205: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1139 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 5002 "build/parser.cpp"
    break;

  case 206: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1143 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 5011 "build/parser.cpp"
    break;

  case 207: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1148 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5020 "build/parser.cpp"
    break;

  case 208: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1152 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5029 "build/parser.cpp"
    break;

  case 209: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1156 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5038 "build/parser.cpp"
    break;

  case 210: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1160 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5047 "build/parser.cpp"
    break;

  case 211: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1164 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5056 "build/parser.cpp"
    break;

  case 212: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1168 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5065 "build/parser.cpp"
    break;

  case 213: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1172 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 5074 "build/parser.cpp"
    break;

  case 214: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1176 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 5083 "build/parser.cpp"
    break;

  case 215: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1180 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 5093 "build/parser.cpp"
    break;

  case 216: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1186 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5103 "build/parser.cpp"
    break;

  case 217: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1191 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5113 "build/parser.cpp"
    break;

  case 218: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1196 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5123 "build/parser.cpp"
    break;

  case 219: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1201 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 5133 "build/parser.cpp"
    break;

  case 220: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1207 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5143 "build/parser.cpp"
    break;

  case 221: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1212 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5153 "build/parser.cpp"
    break;

  case 222: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1217 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5163 "build/parser.cpp"
    break;

  case 223: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1222 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5173 "build/parser.cpp"
    break;

  case 224: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1228 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5183 "build/parser.cpp"
    break;

  case 225: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1233 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5193 "build/parser.cpp"
    break;

  case 226: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1238 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5203 "build/parser.cpp"
    break;

  case 227: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1248 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5216 "build/parser.cpp"
    break;

  case 228: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1259 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 5228 "build/parser.cpp"
    break;

  case 229: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1269 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5237 "build/parser.cpp"
    break;

  case 230: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1277 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5246 "build/parser.cpp"
    break;

  case 231: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1285 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5255 "build/parser.cpp"
    break;

  case 232: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1292 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5264 "build/parser.cpp"
    break;

  case 233: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1300 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5273 "build/parser.cpp"
    break;

  case 234: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1308 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 5284 "build/parser.cpp"
    break;

  case 235: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1319 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 5294 "build/parser.cpp"
    break;

  case 236: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1329 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 5307 "build/parser.cpp"
    break;

  case 237: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1337 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 5320 "build/parser.cpp"
    break;

  case 238: /* enum_constants: enum_constant  */
#line 1348 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 5328 "build/parser.cpp"
    break;

  case 239: /* enum_constants: enum_constants enum_constant  */
#line 1351 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 5338 "build/parser.cpp"
    break;

  case 240: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1359 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5351 "build/parser.cpp"
    break;

  case 241: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1367 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5365 "build/parser.cpp"
    break;

  case 242: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1382 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5378 "build/parser.cpp"
    break;

  case 243: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1391 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 5391 "build/parser.cpp"
    break;

  case 244: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1400 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5405 "build/parser.cpp"
    break;

  case 245: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1410 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5419 "build/parser.cpp"
    break;

  case 246: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1420 "src/parser.y"
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
#line 5434 "build/parser.cpp"
    break;

  case 247: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1431 "src/parser.y"
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
#line 5449 "build/parser.cpp"
    break;

  case 248: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1442 "src/parser.y"
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
#line 5464 "build/parser.cpp"
    break;

  case 249: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1453 "src/parser.y"
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
#line 5479 "build/parser.cpp"
    break;

  case 250: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1464 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5491 "build/parser.cpp"
    break;

  case 251: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1472 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5504 "build/parser.cpp"
    break;

  case 252: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1481 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5518 "build/parser.cpp"
    break;

  case 253: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1491 "src/parser.y"
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
#line 5533 "build/parser.cpp"
    break;

  case 254: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1502 "src/parser.y"
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
#line 5548 "build/parser.cpp"
    break;

  case 255: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1513 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5562 "build/parser.cpp"
    break;

  case 256: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1523 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5576 "build/parser.cpp"
    break;

  case 257: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1533 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5590 "build/parser.cpp"
    break;

  case 258: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1543 "src/parser.y"
                                                                           {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->is_psds = true;
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5604 "build/parser.cpp"
    break;

  case 259: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON  */
#line 1553 "src/parser.y"
                                             {
        auto* ds = new rpg::DclDS((yyvsp[-2].sval));
        ds->is_psds = true;
        ds->qualified = false;
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5616 "build/parser.cpp"
    break;

  case 260: /* ds_fields: %empty  */
#line 1563 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5624 "build/parser.cpp"
    break;

  case 261: /* ds_fields: ds_fields ds_field  */
#line 1566 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5634 "build/parser.cpp"
    break;

  case 262: /* psds_kw: KW_PSDS  */
#line 1574 "src/parser.y"
            {}
#line 5640 "build/parser.cpp"
    break;

  case 263: /* psds_kw: KW_SDS  */
#line 1575 "src/parser.y"
             {}
#line 5646 "build/parser.cpp"
    break;

  case 264: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1579 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5655 "build/parser.cpp"
    break;

  case 265: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1583 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5664 "build/parser.cpp"
    break;

  case 266: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1587 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5673 "build/parser.cpp"
    break;

  case 267: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1591 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5682 "build/parser.cpp"
    break;

  case 268: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1596 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5691 "build/parser.cpp"
    break;

  case 269: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1600 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5700 "build/parser.cpp"
    break;

  case 270: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1604 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5709 "build/parser.cpp"
    break;

  case 271: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1608 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5718 "build/parser.cpp"
    break;

  case 272: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1613 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5729 "build/parser.cpp"
    break;

  case 273: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1619 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5740 "build/parser.cpp"
    break;

  case 274: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1625 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5751 "build/parser.cpp"
    break;

  case 275: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1632 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5762 "build/parser.cpp"
    break;

  case 276: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1639 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5774 "build/parser.cpp"
    break;

  case 277: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1646 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5785 "build/parser.cpp"
    break;

  case 278: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1652 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5797 "build/parser.cpp"
    break;

  case 279: /* ds_field: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1660 "src/parser.y"
                                                              {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5808 "build/parser.cpp"
    break;

  case 280: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1666 "src/parser.y"
                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5819 "build/parser.cpp"
    break;

  case 281: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1677 "src/parser.y"
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
#line 5844 "build/parser.cpp"
    break;

  case 282: /* elseif_clauses: %empty  */
#line 1700 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5850 "build/parser.cpp"
    break;

  case 283: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1701 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5860 "build/parser.cpp"
    break;

  case 284: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1709 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5871 "build/parser.cpp"
    break;

  case 285: /* else_clause: %empty  */
#line 1718 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5877 "build/parser.cpp"
    break;

  case 286: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1719 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5885 "build/parser.cpp"
    break;

  case 287: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1725 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5896 "build/parser.cpp"
    break;

  case 288: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1734 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5907 "build/parser.cpp"
    break;

  case 289: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1743 "src/parser.y"
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
#line 5922 "build/parser.cpp"
    break;

  case 290: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1753 "src/parser.y"
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
#line 5937 "build/parser.cpp"
    break;

  case 291: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1763 "src/parser.y"
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
#line 5952 "build/parser.cpp"
    break;

  case 292: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1773 "src/parser.y"
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
#line 5967 "build/parser.cpp"
    break;

  case 293: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1786 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5979 "build/parser.cpp"
    break;

  case 294: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1796 "src/parser.y"
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
#line 6000 "build/parser.cpp"
    break;

  case 295: /* when_clauses: when_clause  */
#line 1815 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 6009 "build/parser.cpp"
    break;

  case 296: /* when_clauses: when_clauses when_clause  */
#line 1819 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 6018 "build/parser.cpp"
    break;

  case 297: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1826 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 6029 "build/parser.cpp"
    break;

  case 298: /* other_clause: %empty  */
#line 1835 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 6035 "build/parser.cpp"
    break;

  case 299: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1836 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 6043 "build/parser.cpp"
    break;

  case 300: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1842 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 6049 "build/parser.cpp"
    break;

  case 301: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1846 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 6055 "build/parser.cpp"
    break;

  case 302: /* expression: or_expr  */
#line 1852 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 6061 "build/parser.cpp"
    break;

  case 303: /* or_expr: and_expr  */
#line 1856 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 6067 "build/parser.cpp"
    break;

  case 304: /* or_expr: or_expr KW_OR and_expr  */
#line 1857 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6077 "build/parser.cpp"
    break;

  case 305: /* and_expr: not_expr  */
#line 1865 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 6083 "build/parser.cpp"
    break;

  case 306: /* and_expr: and_expr KW_AND not_expr  */
#line 1866 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6093 "build/parser.cpp"
    break;

  case 307: /* not_expr: comparison_expr  */
#line 1874 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 6099 "build/parser.cpp"
    break;

  case 308: /* not_expr: KW_NOT comparison_expr  */
#line 1875 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6107 "build/parser.cpp"
    break;

  case 309: /* comparison_expr: additive_expr  */
#line 1881 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 6113 "build/parser.cpp"
    break;

  case 310: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1882 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6123 "build/parser.cpp"
    break;

  case 311: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1887 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6133 "build/parser.cpp"
    break;

  case 312: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1892 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6143 "build/parser.cpp"
    break;

  case 313: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1897 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6153 "build/parser.cpp"
    break;

  case 314: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1902 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6163 "build/parser.cpp"
    break;

  case 315: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1907 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6173 "build/parser.cpp"
    break;

  case 316: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1912 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6183 "build/parser.cpp"
    break;

  case 317: /* additive_expr: multiplicative_expr  */
#line 1920 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 6189 "build/parser.cpp"
    break;

  case 318: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1921 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6199 "build/parser.cpp"
    break;

  case 319: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1926 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6209 "build/parser.cpp"
    break;

  case 320: /* multiplicative_expr: power_expr  */
#line 1934 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6215 "build/parser.cpp"
    break;

  case 321: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1935 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6225 "build/parser.cpp"
    break;

  case 322: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1940 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6235 "build/parser.cpp"
    break;

  case 323: /* power_expr: unary_expr  */
#line 1948 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6241 "build/parser.cpp"
    break;

  case 324: /* power_expr: unary_expr POWER power_expr  */
#line 1949 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6251 "build/parser.cpp"
    break;

  case 325: /* unary_expr: postfix_expr  */
#line 1957 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6257 "build/parser.cpp"
    break;

  case 326: /* unary_expr: MINUS postfix_expr  */
#line 1958 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6267 "build/parser.cpp"
    break;

  case 327: /* postfix_expr: primary_expr  */
#line 1966 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6273 "build/parser.cpp"
    break;

  case 328: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1967 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6282 "build/parser.cpp"
    break;

  case 329: /* ident: IDENTIFIER  */
#line 1974 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 6288 "build/parser.cpp"
    break;

  case 330: /* ident: KW_UNS  */
#line 1975 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 6294 "build/parser.cpp"
    break;

  case 331: /* ident: KW_FLOAT_TYPE  */
#line 1976 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 6300 "build/parser.cpp"
    break;

  case 332: /* ident: KW_GRAPH  */
#line 1977 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 6306 "build/parser.cpp"
    break;

  case 333: /* ident: KW_ASCEND  */
#line 1978 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 6312 "build/parser.cpp"
    break;

  case 334: /* ident: KW_DESCEND  */
#line 1979 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 6318 "build/parser.cpp"
    break;

  case 335: /* ident: KW_IN  */
#line 1980 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 6324 "build/parser.cpp"
    break;

  case 336: /* ident: KW_RTNPARM  */
#line 1981 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 6330 "build/parser.cpp"
    break;

  case 337: /* ident: KW_OPDESC  */
#line 1982 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 6336 "build/parser.cpp"
    break;

  case 338: /* ident: KW_NULLIND  */
#line 1983 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 6342 "build/parser.cpp"
    break;

  case 339: /* ident: KW_DATFMT  */
#line 1984 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 6348 "build/parser.cpp"
    break;

  case 340: /* ident: KW_TIMFMT  */
#line 1985 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 6354 "build/parser.cpp"
    break;

  case 341: /* ident: KW_EXTNAME  */
#line 1986 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 6360 "build/parser.cpp"
    break;

  case 342: /* ident: KW_OVERLAY  */
#line 1987 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 6366 "build/parser.cpp"
    break;

  case 343: /* ident: KW_POS  */
#line 1988 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 6372 "build/parser.cpp"
    break;

  case 344: /* ident: KW_PREFIX  */
#line 1989 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 6378 "build/parser.cpp"
    break;

  case 345: /* primary_expr: IDENTIFIER  */
#line 1993 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6387 "build/parser.cpp"
    break;

  case 346: /* primary_expr: KW_UNS  */
#line 1997 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 6393 "build/parser.cpp"
    break;

  case 347: /* primary_expr: KW_FLOAT_TYPE  */
#line 1998 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 6399 "build/parser.cpp"
    break;

  case 348: /* primary_expr: KW_GRAPH  */
#line 1999 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 6405 "build/parser.cpp"
    break;

  case 349: /* primary_expr: KW_ASCEND  */
#line 2000 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 6411 "build/parser.cpp"
    break;

  case 350: /* primary_expr: KW_DESCEND  */
#line 2001 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 6417 "build/parser.cpp"
    break;

  case 351: /* primary_expr: KW_RTNPARM  */
#line 2002 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 6423 "build/parser.cpp"
    break;

  case 352: /* primary_expr: KW_OPDESC  */
#line 2003 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 6429 "build/parser.cpp"
    break;

  case 353: /* primary_expr: KW_NULLIND  */
#line 2004 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 6435 "build/parser.cpp"
    break;

  case 354: /* primary_expr: KW_DATFMT  */
#line 2005 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 6441 "build/parser.cpp"
    break;

  case 355: /* primary_expr: KW_OVERLAY  */
#line 2006 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 6447 "build/parser.cpp"
    break;

  case 356: /* primary_expr: KW_POS  */
#line 2007 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 6453 "build/parser.cpp"
    break;

  case 357: /* primary_expr: KW_PREFIX  */
#line 2008 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 6459 "build/parser.cpp"
    break;

  case 358: /* primary_expr: KW_TIMFMT  */
#line 2009 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 6465 "build/parser.cpp"
    break;

  case 359: /* primary_expr: KW_EXTNAME  */
#line 2010 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 6471 "build/parser.cpp"
    break;

  case 360: /* primary_expr: INTEGER_LITERAL  */
#line 2011 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6479 "build/parser.cpp"
    break;

  case 361: /* primary_expr: FLOAT_LITERAL  */
#line 2014 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6487 "build/parser.cpp"
    break;

  case 362: /* primary_expr: STRING_LITERAL  */
#line 2017 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6496 "build/parser.cpp"
    break;

  case 363: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 2021 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6505 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 2025 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6513 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 2028 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6521 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 2031 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6529 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 2034 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6537 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 2037 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6545 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 2040 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6553 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 2043 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6561 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 2046 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6569 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 2049 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6577 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 2052 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6585 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 2055 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6593 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 2058 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6601 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 2061 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6610 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 2065 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6618 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 2068 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6626 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 2071 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6634 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 2074 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6642 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 2077 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6650 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 2080 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6658 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 2083 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6666 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 2086 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6674 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 2089 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6685 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 2095 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6696 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 2101 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6707 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 2107 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6718 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 2113 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6729 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 2119 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6740 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 2125 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6748 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 2128 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6756 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 2131 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6764 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 2134 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6772 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 2137 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6781 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 2141 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6790 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 2145 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6798 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 2148 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6806 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 2151 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6814 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 2154 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6822 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 2157 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6830 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 2160 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6838 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 2163 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6847 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 2167 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6855 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 2170 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6864 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 2174 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6872 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 2177 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6881 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 2181 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6893 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 2188 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6905 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 2195 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6917 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2202 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6927 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2207 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6937 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2212 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6947 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2217 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6956 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2221 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6965 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2225 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6973 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2228 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6981 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2231 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6989 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2234 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6997 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2237 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 7005 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2240 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 7013 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2243 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 7021 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2246 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 7029 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2249 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 7037 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2252 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 7045 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2255 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 7053 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2258 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 7061 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2261 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 7069 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2264 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 7077 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2267 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 7085 "build/parser.cpp"
    break;

  case 431: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2270 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 7093 "build/parser.cpp"
    break;

  case 432: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2273 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 7101 "build/parser.cpp"
    break;

  case 433: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2276 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 7109 "build/parser.cpp"
    break;

  case 434: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2279 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 7117 "build/parser.cpp"
    break;

  case 435: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2282 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7125 "build/parser.cpp"
    break;

  case 436: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2285 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7133 "build/parser.cpp"
    break;

  case 437: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2288 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 7141 "build/parser.cpp"
    break;

  case 438: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2291 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 7149 "build/parser.cpp"
    break;

  case 439: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2294 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 7157 "build/parser.cpp"
    break;

  case 440: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2297 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 7165 "build/parser.cpp"
    break;

  case 441: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2300 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7173 "build/parser.cpp"
    break;

  case 442: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2303 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7181 "build/parser.cpp"
    break;

  case 443: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2306 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 7191 "build/parser.cpp"
    break;

  case 444: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2311 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 7201 "build/parser.cpp"
    break;

  case 445: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2316 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 7211 "build/parser.cpp"
    break;

  case 446: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2321 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 7221 "build/parser.cpp"
    break;

  case 447: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2326 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 7232 "build/parser.cpp"
    break;

  case 448: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2332 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7241 "build/parser.cpp"
    break;

  case 449: /* primary_expr: BIF_PROC  */
#line 2336 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7250 "build/parser.cpp"
    break;

  case 450: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2340 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7262 "build/parser.cpp"
    break;

  case 451: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2347 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7274 "build/parser.cpp"
    break;

  case 452: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2354 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7286 "build/parser.cpp"
    break;

  case 453: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2361 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 7297 "build/parser.cpp"
    break;

  case 454: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2367 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 7308 "build/parser.cpp"
    break;

  case 455: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2373 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 7319 "build/parser.cpp"
    break;

  case 456: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2379 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 7327 "build/parser.cpp"
    break;

  case 457: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2382 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 7335 "build/parser.cpp"
    break;

  case 458: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2385 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 7343 "build/parser.cpp"
    break;

  case 459: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2388 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 7351 "build/parser.cpp"
    break;

  case 460: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2391 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 7359 "build/parser.cpp"
    break;

  case 461: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2394 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 7367 "build/parser.cpp"
    break;

  case 462: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2397 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 7375 "build/parser.cpp"
    break;

  case 463: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2400 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 7386 "build/parser.cpp"
    break;

  case 464: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2406 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 7394 "build/parser.cpp"
    break;

  case 465: /* primary_expr: INDICATOR  */
#line 2409 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 7402 "build/parser.cpp"
    break;

  case 466: /* primary_expr: KW_ON  */
#line 2412 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 7410 "build/parser.cpp"
    break;

  case 467: /* primary_expr: KW_OFF  */
#line 2415 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 7418 "build/parser.cpp"
    break;

  case 468: /* primary_expr: KW_NULL  */
#line 2418 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7426 "build/parser.cpp"
    break;

  case 469: /* primary_expr: KW_OMIT  */
#line 2421 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7434 "build/parser.cpp"
    break;

  case 470: /* primary_expr: KW_USER  */
#line 2424 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("RPG_USER");
        if (g_program) g_program->uses_user_const = true;
    }
#line 7443 "build/parser.cpp"
    break;

  case 471: /* primary_expr: KW_BLANKS  */
#line 2428 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 7451 "build/parser.cpp"
    break;

  case 472: /* primary_expr: KW_ZEROS  */
#line 2431 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 7459 "build/parser.cpp"
    break;

  case 473: /* primary_expr: KW_HIVAL  */
#line 2434 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 7467 "build/parser.cpp"
    break;

  case 474: /* primary_expr: KW_LOVAL  */
#line 2437 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 7475 "build/parser.cpp"
    break;

  case 475: /* primary_expr: LPAREN expression RPAREN  */
#line 2440 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 7483 "build/parser.cpp"
    break;

  case 476: /* call_args_opt: %empty  */
#line 2447 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 7489 "build/parser.cpp"
    break;

  case 477: /* call_args_opt: call_arg_list  */
#line 2448 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7495 "build/parser.cpp"
    break;

  case 478: /* call_arg_list: expression  */
#line 2452 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7504 "build/parser.cpp"
    break;

  case 479: /* call_arg_list: call_arg_list COLON expression  */
#line 2456 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7513 "build/parser.cpp"
    break;

  case 480: /* arg_list: expression  */
#line 2464 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7522 "build/parser.cpp"
    break;

  case 481: /* arg_list: arg_list COLON expression  */
#line 2468 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7531 "build/parser.cpp"
    break;


#line 7535 "build/parser.cpp"

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

#line 2474 "src/parser.y"


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
