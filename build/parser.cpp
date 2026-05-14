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
  YYSYMBOL_KW_IF = 61,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 62,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 63,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 64,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 65,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 66,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 67,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 68,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 69,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 70,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 71,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 72,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 73,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 74,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 75,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 76,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 77,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 78,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 79,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 80,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 81,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 82,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 83,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 84,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 85,                    /* KW_OFF  */
  YYSYMBOL_KW_RESET = 86,                  /* KW_RESET  */
  YYSYMBOL_KW_CLEAR = 87,                  /* KW_CLEAR  */
  YYSYMBOL_KW_SORTA = 88,                  /* KW_SORTA  */
  YYSYMBOL_INDICATOR = 89,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 90,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 91,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 92,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 93,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 94,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 95,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 96,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 97,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 98,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 99,                  /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 100,                /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 101,                /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 102,             /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 103,                   /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 104,                /* KW_LIKEDS  */
  YYSYMBOL_KW_LIKE = 105,                  /* KW_LIKE  */
  YYSYMBOL_KW_DCL_SUBF = 106,              /* KW_DCL_SUBF  */
  YYSYMBOL_KW_DCL_PARM = 107,              /* KW_DCL_PARM  */
  YYSYMBOL_DOT = 108,                      /* DOT  */
  YYSYMBOL_BIF_CHAR = 109,                 /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 110,                 /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 111,                /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 112,                /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 113,                  /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 114,                /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 115,                 /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 116,              /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 117,                /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 118,                  /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 119,                  /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 120,                 /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 121,                /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 122,                  /* BIF_EOF  */
  YYSYMBOL_BIF_ABS = 123,                  /* BIF_ABS  */
  YYSYMBOL_BIF_DIV = 124,                  /* BIF_DIV  */
  YYSYMBOL_BIF_REM = 125,                  /* BIF_REM  */
  YYSYMBOL_BIF_SIZE = 126,                 /* BIF_SIZE  */
  YYSYMBOL_BIF_ADDR = 127,                 /* BIF_ADDR  */
  YYSYMBOL_BIF_PARMS = 128,                /* BIF_PARMS  */
  YYSYMBOL_BIF_STATUS = 129,               /* BIF_STATUS  */
  YYSYMBOL_BIF_ERROR = 130,                /* BIF_ERROR  */
  YYSYMBOL_BIF_MAX = 131,                  /* BIF_MAX  */
  YYSYMBOL_BIF_MIN = 132,                  /* BIF_MIN  */
  YYSYMBOL_BIF_LOOKUP = 133,               /* BIF_LOOKUP  */
  YYSYMBOL_BIF_DATE = 134,                 /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 135,                 /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 136,            /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 137,                 /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 138,                 /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 139,               /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 140,                /* BIF_YEARS  */
  YYSYMBOL_BIF_EDITC = 141,                /* BIF_EDITC  */
  YYSYMBOL_BIF_EDITW = 142,                /* BIF_EDITW  */
  YYSYMBOL_BIF_REPLACE = 143,              /* BIF_REPLACE  */
  YYSYMBOL_BIF_CHECK = 144,                /* BIF_CHECK  */
  YYSYMBOL_BIF_CHECKR = 145,               /* BIF_CHECKR  */
  YYSYMBOL_BIF_LOWER = 146,                /* BIF_LOWER  */
  YYSYMBOL_BIF_UPPER = 147,                /* BIF_UPPER  */
  YYSYMBOL_BIF_SUBDT = 148,                /* BIF_SUBDT  */
  YYSYMBOL_BIF_FLOAT = 149,                /* BIF_FLOAT  */
  YYSYMBOL_BIF_SQRT = 150,                 /* BIF_SQRT  */
  YYSYMBOL_BIF_ALLOC = 151,                /* BIF_ALLOC  */
  YYSYMBOL_BIF_REALLOC = 152,              /* BIF_REALLOC  */
  YYSYMBOL_BIF_XFOOT = 153,                /* BIF_XFOOT  */
  YYSYMBOL_BIF_SUBARR = 154,               /* BIF_SUBARR  */
  YYSYMBOL_BIF_SPLIT = 155,                /* BIF_SPLIT  */
  YYSYMBOL_BIF_UNS = 156,                  /* BIF_UNS  */
  YYSYMBOL_BIF_INTH = 157,                 /* BIF_INTH  */
  YYSYMBOL_BIF_DECH = 158,                 /* BIF_DECH  */
  YYSYMBOL_BIF_DECPOS = 159,               /* BIF_DECPOS  */
  YYSYMBOL_BIF_CONCAT = 160,               /* BIF_CONCAT  */
  YYSYMBOL_BIF_CONCATARR = 161,            /* BIF_CONCATARR  */
  YYSYMBOL_BIF_LEFT = 162,                 /* BIF_LEFT  */
  YYSYMBOL_BIF_RIGHT = 163,                /* BIF_RIGHT  */
  YYSYMBOL_BIF_STR = 164,                  /* BIF_STR  */
  YYSYMBOL_BIF_MAXARR = 165,               /* BIF_MAXARR  */
  YYSYMBOL_BIF_MINARR = 166,               /* BIF_MINARR  */
  YYSYMBOL_BIF_LIST = 167,                 /* BIF_LIST  */
  YYSYMBOL_BIF_RANGE = 168,                /* BIF_RANGE  */
  YYSYMBOL_BIF_LOOKUPLT = 169,             /* BIF_LOOKUPLT  */
  YYSYMBOL_BIF_LOOKUPGE = 170,             /* BIF_LOOKUPGE  */
  YYSYMBOL_BIF_LOOKUPLE = 171,             /* BIF_LOOKUPLE  */
  YYSYMBOL_BIF_LOOKUPGT = 172,             /* BIF_LOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUP = 173,              /* BIF_TLOOKUP  */
  YYSYMBOL_BIF_TLOOKUPLT = 174,            /* BIF_TLOOKUPLT  */
  YYSYMBOL_BIF_TLOOKUPGT = 175,            /* BIF_TLOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUPLE = 176,            /* BIF_TLOOKUPLE  */
  YYSYMBOL_BIF_TLOOKUPGE = 177,            /* BIF_TLOOKUPGE  */
  YYSYMBOL_BIF_HOURS = 178,                /* BIF_HOURS  */
  YYSYMBOL_BIF_MINUTES = 179,              /* BIF_MINUTES  */
  YYSYMBOL_BIF_SECONDS = 180,              /* BIF_SECONDS  */
  YYSYMBOL_BIF_MSECONDS = 181,             /* BIF_MSECONDS  */
  YYSYMBOL_BIF_PADDR = 182,                /* BIF_PADDR  */
  YYSYMBOL_BIF_PROC = 183,                 /* BIF_PROC  */
  YYSYMBOL_BIF_PASSED = 184,               /* BIF_PASSED  */
  YYSYMBOL_BIF_OMITTED = 185,              /* BIF_OMITTED  */
  YYSYMBOL_BIF_BITAND = 186,               /* BIF_BITAND  */
  YYSYMBOL_BIF_BITNOT = 187,               /* BIF_BITNOT  */
  YYSYMBOL_BIF_BITOR = 188,                /* BIF_BITOR  */
  YYSYMBOL_BIF_BITXOR = 189,               /* BIF_BITXOR  */
  YYSYMBOL_BIF_SCANR = 190,                /* BIF_SCANR  */
  YYSYMBOL_BIF_EDITFLT = 191,              /* BIF_EDITFLT  */
  YYSYMBOL_BIF_UNSH = 192,                 /* BIF_UNSH  */
  YYSYMBOL_BIF_PARMNUM = 193,              /* BIF_PARMNUM  */
  YYSYMBOL_BIF_GETENV = 194,               /* BIF_GETENV  */
  YYSYMBOL_BIF_XML = 195,                  /* BIF_XML  */
  YYSYMBOL_BIF_DATA = 196,                 /* BIF_DATA  */
  YYSYMBOL_BIF_PARSER = 197,               /* BIF_PARSER  */
  YYSYMBOL_KW_ALL = 198,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 199,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 200,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 201,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 202,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 203,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 204,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 205,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 206,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 207,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 208,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 209,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 210,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 211,               /* KW_EXTNAME  */
  YYSYMBOL_KW_PSDS = 212,                  /* KW_PSDS  */
  YYSYMBOL_KW_SDS = 213,                   /* KW_SDS  */
  YYSYMBOL_KW_DTAARA = 214,                /* KW_DTAARA  */
  YYSYMBOL_KW_OUT = 215,                   /* KW_OUT  */
  YYSYMBOL_KW_UNLOCK = 216,                /* KW_UNLOCK  */
  YYSYMBOL_KW_RTNPARM = 217,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 218,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 219,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 220,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 221,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 222,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 223,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 224,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 225,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 226,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 227,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 228,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 229,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 230,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 231,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 232,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 233,                    /* KW_IN  */
  YYSYMBOL_KW_XML_INTO = 234,              /* KW_XML_INTO  */
  YYSYMBOL_KW_DATA_INTO = 235,             /* KW_DATA_INTO  */
  YYSYMBOL_KW_DATA_GEN = 236,              /* KW_DATA_GEN  */
  YYSYMBOL_IDENTIFIER = 237,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 238,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 239,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 240,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 241,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 242,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 243,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 244,                   /* RPAREN  */
  YYSYMBOL_COLON = 245,                    /* COLON  */
  YYSYMBOL_PLUS = 246,                     /* PLUS  */
  YYSYMBOL_MINUS = 247,                    /* MINUS  */
  YYSYMBOL_STAR = 248,                     /* STAR  */
  YYSYMBOL_SLASH = 249,                    /* SLASH  */
  YYSYMBOL_NE = 250,                       /* NE  */
  YYSYMBOL_LE = 251,                       /* LE  */
  YYSYMBOL_GE = 252,                       /* GE  */
  YYSYMBOL_LT = 253,                       /* LT  */
  YYSYMBOL_GT = 254,                       /* GT  */
  YYSYMBOL_YYACCEPT = 255,                 /* $accept  */
  YYSYMBOL_program = 256,                  /* program  */
  YYSYMBOL_statements_opt = 257,           /* statements_opt  */
  YYSYMBOL_statement_list = 258,           /* statement_list  */
  YYSYMBOL_statement = 259,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 260,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 261,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 262,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 263,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 264,              /* eval_target  */
  YYSYMBOL_eval_stmt = 265,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 266,           /* eval_corr_stmt  */
  YYSYMBOL_xml_into_stmt = 267,            /* xml_into_stmt  */
  YYSYMBOL_data_into_stmt = 268,           /* data_into_stmt  */
  YYSYMBOL_data_gen_stmt = 269,            /* data_gen_stmt  */
  YYSYMBOL_in_da_stmt = 270,               /* in_da_stmt  */
  YYSYMBOL_out_da_stmt = 271,              /* out_da_stmt  */
  YYSYMBOL_unlock_da_stmt = 272,           /* unlock_da_stmt  */
  YYSYMBOL_evalr_stmt = 273,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 274,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 275,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 276,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 277,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 278,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 279,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 280,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 281,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 282,              /* proc_export  */
  YYSYMBOL_pi_return_type = 283,           /* pi_return_type  */
  YYSYMBOL_pi_params = 284,                /* pi_params  */
  YYSYMBOL_pi_param = 285,                 /* pi_param  */
  YYSYMBOL_pr_params = 286,                /* pr_params  */
  YYSYMBOL_pr_param = 287,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 288,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 289,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 290,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 291,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 292,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 293,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 294,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 295,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 296,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 297,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 298,           /* enum_constants  */
  YYSYMBOL_enum_constant = 299,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 300,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 301,                /* ds_fields  */
  YYSYMBOL_psds_kw = 302,                  /* psds_kw  */
  YYSYMBOL_ds_field = 303,                 /* ds_field  */
  YYSYMBOL_if_stmt = 304,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 305,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 306,            /* elseif_clause  */
  YYSYMBOL_else_clause = 307,              /* else_clause  */
  YYSYMBOL_dow_stmt = 308,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 309,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 310,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 311,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 312,              /* select_stmt  */
  YYSYMBOL_when_clauses = 313,             /* when_clauses  */
  YYSYMBOL_when_clause = 314,              /* when_clause  */
  YYSYMBOL_other_clause = 315,             /* other_clause  */
  YYSYMBOL_iter_stmt = 316,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 317,               /* leave_stmt  */
  YYSYMBOL_expression = 318,               /* expression  */
  YYSYMBOL_or_expr = 319,                  /* or_expr  */
  YYSYMBOL_and_expr = 320,                 /* and_expr  */
  YYSYMBOL_not_expr = 321,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 322,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 323,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 324,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 325,               /* power_expr  */
  YYSYMBOL_unary_expr = 326,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 327,             /* postfix_expr  */
  YYSYMBOL_ident = 328,                    /* ident  */
  YYSYMBOL_primary_expr = 329,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 330,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 331,            /* call_arg_list  */
  YYSYMBOL_arg_list = 332                  /* arg_list  */
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
#define YYLAST   5164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  255
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  480
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1583

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   509


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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254
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
    2424,  2427,  2430,  2433,  2436,  2443,  2444,  2448,  2452,  2460,
    2464
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
  "KW_HIVAL", "KW_LOVAL", "KW_IF", "KW_ELSEIF", "KW_ELSE", "KW_ENDIF",
  "KW_DOW", "KW_DOU", "KW_ENDDO", "KW_FOR", "KW_ENDFOR", "KW_TO",
  "KW_DOWNTO", "KW_BY", "KW_SELECT", "KW_WHEN", "KW_OTHER", "KW_ENDSL",
  "KW_ITER", "KW_LEAVE", "KW_MONITOR", "KW_ON_ERROR", "KW_ENDMON",
  "KW_BEGSR", "KW_ENDSR", "KW_EXSR", "KW_OFF", "KW_RESET", "KW_CLEAR",
  "KW_SORTA", "INDICATOR", "KW_AND", "KW_OR", "KW_NOT", "KW_DCL_PROC",
  "KW_END_PROC", "KW_DCL_PI", "KW_END_PI", "KW_DCL_PR", "KW_END_PR",
  "KW_VALUE", "KW_DCL_DS", "KW_END_DS", "KW_QUALIFIED", "KW_DIM",
  "KW_LIKEDS", "KW_LIKE", "KW_DCL_SUBF", "KW_DCL_PARM", "DOT", "BIF_CHAR",
  "BIF_TRIM", "BIF_TRIML", "BIF_TRIMR", "BIF_LEN", "BIF_SUBST", "BIF_SCAN",
  "BIF_SCANRPL", "BIF_XLATE", "BIF_DEC", "BIF_INT", "BIF_ELEM",
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

#define YYPACT_NINF (-855)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-300)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,  -855,   102,    35,   634,  -855,   -79,   -73,   322,   -54,
    4487,    99,   322,    99,  4487,   -31,   322,   -56,    99,    99,
    4487,  -855,  3791,    42,  4487,  4487,  4487,   322,    46,    72,
      82,   110,    -6,   322,   322,   322,   322,  -855,    63,   117,
     125,   123,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,   154,   161,  -855,  -855,  -855,  -855,  -855,   163,  -855,
     322,   170,   322,   322,   322,    18,  -855,  -855,  -855,  -855,
     101,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,   403,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,   157,  4487,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  4661,   144,   172,   179,
     187,   205,   233,   236,   243,   246,   248,   284,   295,   311,
     315,   332,   372,   390,   405,   421,   428,   447,   449,   455,
     458,   467,   474,   476,   483,   510,   526,   542,   545,   546,
     547,   548,   549,   550,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   585,   586,   587,   588,
     589,   592,   593,   595,   596,   604,   605,   613,   614,   615,
     617,   618,   620,   419,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,   621,  -855,
    -855,  -855,  4487,  4835,   364,   639,   775,  -855,   199,  -149,
    -139,  -855,   643,   765,  -855,    33,   632,   633,   635,   638,
    -855,   640,   322,   641,   642,   644,  -855,   645,   820,   646,
     647,   648,   649,   816,  -855,  -855,  -855,   651,   652,   653,
     654,   655,   848,   426,   177,  4487,   657,   658,   -37,   667,
     660,   707,   708,   709,   666,  4487,  4487,    -8,   665,   668,
     664,   669,   670,   674,   676,  -110,   -32,   677,   679,   680,
     681,   682,   683,   684,   686,   688,   689,   692,   693,   199,
    4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,
    4487,  4487,   678,   691,  4487,  4487,  4487,  4487,  4487,   694,
     695,   696,  4487,  4487,  4487,  3965,  4139,  4313,  4487,  4487,
    4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,
    4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,
    4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,
    4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,  4487,
    4487,  4487,  4487,   671,   703,   322,   322,  4487,  4487,  4487,
    4487,  4487,  4487,  4487,   322,  4487,  -855,  4487,   710,   765,
    -855,  4487,  4487,  4661,  4661,  4661,  4661,  4661,  4661,  4661,
    4661,  4661,  4661,  4661,  4661,   673,  4487,  4487,   322,  4487,
    -855,  -855,   711,  4487,  4487,  -855,  -855,   712,  -855,  -855,
    -855,  4487,  4487,   106,  -855,  1779,  -855,  -855,  -855,  -855,
    -855,  -855,   715,   714,   716,   717,   719,   723,   -15,   155,
     725,   727,   736,  -855,  -855,  -855,   -11,  -855,   -55,  -855,
    -855,   722,   699,  4487,  -855,   737,   738,   739,  -855,   733,
     741,   713,   726,   743,  -855,  -855,  -855,   685,   753,   755,
     762,   763,   759,  -855,   761,  -855,  -855,  -855,  -855,   700,
     767,   768,   770,   771,   773,   756,  -855,  -855,   -48,    20,
     150,   211,   213,   226,   272,   279,   312,   316,   318,   320,
    -855,  -855,   324,   329,   333,   335,   337,  -855,  -855,  -855,
     339,   341,   343,  -855,   345,  -855,   347,  -855,   349,   769,
     772,   774,   776,   351,   353,   355,   357,   359,   363,   365,
     777,   367,   369,   373,   375,   377,   379,   381,   383,   385,
     387,   392,   397,   400,   402,   408,   411,   413,   416,   418,
     433,   435,   437,   439,   441,   452,   459,   461,   464,   470,
     779,   781,   782,   783,   784,  -855,   785,   787,   480,   484,
     488,   491,   493,   495,   497,   788,   499,  -855,   789,  -855,
     775,  -855,   214,   214,   214,   214,   214,   214,   214,  -139,
    -139,  -855,  -855,  -855,  -855,   733,   778,   793,   794,   322,
     795,   796,  -855,   910,  1849,  2074,   675,   797,   798,  -855,
     936,   799,  -855,  2144,   920,   786,   803,   804,   805,   806,
     801,  -855,   802,   807,  -855,   808,   216,   810,   811,    41,
     812,   282,  -855,  4487,   699,   506,    64,  -855,   813,  4487,
    4487,  4487,   909,   814,  4487,  -855,   809,   815,   817,   818,
     822,   823,   819,   821,   826,   827,   829,   830,   831,   832,
     833,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  4487,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,   487,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,   824,  -855,  -855,   687,   836,
     838,  4487,  4487,  -855,  -855,   840,  -855,   841,    36,   842,
     843,   844,   839,   845,   850,    56,   242,   854,    59,  -855,
     847,   849,   851,   852,   507,   856,   861,   362,  -855,  -855,
      60,  -855,    66,  -855,  4487,   858,  -855,  -855,   511,   513,
     515,   863,  -855,  -855,   857,   100,    90,   108,   825,   855,
     859,   860,   864,   444,   444,   444,   444,   444,   866,   862,
     867,   868,   870,   871,   878,   879,  -855,  4487,   883,  -855,
     957,  -855,  -855,   -34,   -29,  1155,  2369,  -855,  2473,  -855,
     485,   891,  -855,  -855,  -855,   895,   893,   892,   896,   902,
     391,  -855,   903,   904,   897,   519,   899,    78,   912,   913,
     949,     8,   911,   915,  -855,   415,   865,   914,   919,   921,
     922,    93,   917,   925,   926,  -855,  2698,   927,  4487,   -93,
    4487,   -82,  4487,  -855,   837,  1022,   929,  -855,  -855,   930,
    1030,  -855,   931,   932,   928,   933,  -855,   934,   935,   938,
    1071,   937,   939,  1124,   940,   941,   944,   948,   954,   958,
     959,  -855,   960,   961,   962,   963,   964,   967,   522,  -855,
    -855,  -855,  -855,  -855,  -855,   965,  -855,   966,  4487,  -855,
    4487,  -855,   971,   972,  -855,   970,  -855,   974,  -855,   523,
     975,   976,   979,   981,   983,   943,   997,   995,   999,  1000,
    -855,  1004,   973,  1002,  1006,  1007,  -855,  -855,  1005,  1010,
    1011,  1013,  1014,  1015,  1021,  1023,  1024,  1028,   918,  1026,
    -855,  -855,  -855,  1027,  -855,  1025,  1029,  -855,  1032,  1031,
    -855,  1033,  1034,  1036,  4487,  1043,  1038,  1035,  1045,  -855,
    4487,   252,  1046,  -855,  1041,  4487,  1048,  1044,   254,  1049,
    -855,   245,   444,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    1047,  1052,  1058,  1059,  1060,  1061,  1062,  -855,  2768,  -855,
    1066,  2993,  1067,  3063,  -855,  -855,    11,  -855,    84,  -855,
    1068,  1069,  1072,  1073,  1051,  1079,  1080,  1081,  1089,  1065,
    1084,  -855,  -855,  1085,  -855,  1106,  1168,  -855,  1092,   107,
    1169,  1093,  1095,  1096,  1097,  1102,  1098,  1100,  1105,  1108,
    1107,  -855,  -855,  1099,  4487,    86,  4487,    94,  1109,  4487,
    1113,  1116,  4487,  1123,  1125,  1133,  1136,  1137,  1134,  1140,
    4487,  1141,  1142,  4487,  1148,  1149,  1151,  1152,  1280,  1154,
    1156,  1157,  1127,  1160,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  1259,  -855,  1161,  -855,  1162,    29,  1163,  1170,   422,
    -855,  1164,    88,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1153,  1178,  1165,  1167,   176,   225,  1182,  1183,  1184,   227,
    1185,  1186,  1187,  1188,  1189,  1190,  1181,  1191,   105,  1195,
     165,  1179,  1196,  -855,  1194,  1197,  -855,  1198,  1200,  -855,
    -855,  1201,  1203,  1205,  1204,   158,  1206,  1208,  1180,  1192,
    1209,  1210,  1211,  1212,  1213,  1216,  1193,  1214,   201,  1215,
    1218,  4487,  1219,  1202,  -855,  -855,  3288,  -855,  3358,  -855,
    1222,  -855,   539,  1221,  1228,  1229,  1230,  1238,  -855,  1241,
    1239,  1242,  1253,  1254,   -43,   -41,   -35,  1260,  1261,  -855,
    -855,  1262,  1263,  -855,  -855,  -855,  1264,  1265,  -855,  -855,
    1266,  1267,  1268,  1272,  1270,  1257,  1258,  -855,  -855,  1269,
    1271,  -855,  1283,  -855,  1287,  4487,  1288,  4487,  1289,  -855,
    -855,  1290,  1291,  1292,  -855,  -855,  -855,  1293,  1296,  -855,
    -855,  1294,  -855,  -855,  1295,  1297,  1298,  1302,  1303,  -855,
    -855,  4487,  1304,  1307,  1309,  1305,  1306,  -855,  1484,  1311,
    1313,  1321,  1322,  1275,  1329,  1331,  1336,  1338,  -855,   -36,
     -27,   -21,  1341,  1333,   -40,  -855,  1337,   -39,  -855,  1339,
     -26,  -855,  1353,  -855,   228,   231,  -855,  -855,   241,   244,
     263,  -855,  -855,   264,  -855,  -855,  -855,  1354,  -855,  1346,
    1361,  1363,  1364,  -114,  -855,  1357,  -855,  1359,  -855,  -855,
    -855,  -855,  1365,  1366,  -855,  -855,  1369,  1370,  -855,  -855,
    1368,  1372,  1373,  1375,  -855,  -855,  1554,  1376,  1377,  1367,
    1383,  1385,  1386,  1381,  1382,  1384,  1389,  1391,  1388,  -855,
    1396,  -855,  1398,  -855,  1400,   718,  1387,  -855,   720,  1402,
    -855,   724,  1403,  -855,   -20,  1408,  1409,  1411,  1412,  1414,
    1415,  1416,   529,  1417,   531,  1418,  1420,  -855,  1419,  1423,
    -855,  -855,  -855,  -855,  1424,  -855,  -855,  -855,  1425,  1426,
    -855,  -855,  1427,  1428,  1429,  1413,   -19,   -18,   -17,  1421,
    1434,  -855,  -855,  -855,   -16,  1431,  1433,  1394,  1435,  1437,
    1487,  1440,  1438,  1621,  1436,   -25,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  1445,  1432,  1447,  1448,  1458,  1456,
    1460,  -855,  -855,  -855,  -855,  -855,  3583,   -14,   -13,    -5,
    1468,  1464,   -24,  -855,  1465,   -23,  -855,  1467,    -4,  -855,
    1469,  -855,  1470,  -855,  1115,  1473,  1471,  1122,  1481,  1479,
    1630,  1483,  1482,  1677,  1485,  -855,  -855,  1486,  -855,  -855,
    1488,  -855,  1489,  3653,  1490,  1493,  -855,  1494,  -855,  1495,
    -855,  1496,   730,  1498,  -855,   732,  1499,  -855,   734,  1500,
    -855,   -12,  -855,  1501,  -855,  1497,  1502,  -855,  1503,  1504,
    -855,  1506,  1505,  1622,  1509,  1510,  1511,  1514,  -855,  -855,
    -855,  -855,     6,  1492,  1512,  1680,  1513,  1515,  1682,  1521,
    1523,  1692,  1525,    16,  -855,  1535,  -855,  1536,  -855,  1537,
    -855,  1540,  1548,  -855,  -855,  -855,  -855,  1552,  -855,  1746,
    1555,  1551,  1749,  1557,  1556,  1751,  1560,  1558,  1755,  1561,
    -855,  -855,  -855,  -855,  -855,  1564,  -855,  1562,  -855,  1566,
    1565,  -855,  1567,  1572,  -855,  1581,  1579,  1777,  -855,  1584,
    -855,  1585,  -855,  1586,  -855,  1587,  1588,  -855,  -855,  -855,
    -855,  1589,  -855
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
     470,   471,   472,   473,   467,   465,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   346,   347,   348,   355,   356,   357,
     354,   358,   359,   351,   352,   349,   350,   353,   345,   360,
     361,   362,     0,     0,     0,   302,   303,   305,   307,   309,
     317,   320,   323,   325,   327,   106,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,   300,   301,     7,     0,     0,     0,
       0,     0,   160,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   453,   475,     0,   326,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   233,     0,     0,     0,   146,   150,     0,     7,     7,
       7,     0,     0,   298,   295,     0,     7,   229,   231,   232,
     230,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   263,   260,     0,   479,     0,   141,
     142,     0,     0,     0,   140,     0,     0,     0,   122,   477,
       0,   476,     0,     0,    49,    50,    51,     0,     0,     0,
       0,     0,     0,    69,     0,    70,    71,    67,    72,     0,
       0,     0,     0,     0,     0,     0,    68,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     414,   415,     0,     0,     0,     0,     0,   376,   395,   396,
       0,     0,     0,   403,     0,   405,     0,   407,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   448,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,     0,   474,
     304,   306,   310,   311,   314,   315,   312,   313,   316,   318,
     319,   321,   322,   324,   328,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,   260,     0,     0,     0,     0,     0,
       0,   259,   125,     0,     0,     0,     0,   238,     0,     0,
       0,     0,   123,     0,     0,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   399,   400,   401,   397,   398,   393,   394,
     377,   402,   404,   406,     0,   411,   412,   413,   378,   379,
     380,   381,   382,   383,   384,     0,   391,   392,   416,   417,
     418,   429,   423,   419,   420,   421,   422,   424,   425,   426,
     427,   428,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   363,   127,   129,   143,     0,   128,   144,   285,     0,
       0,     0,     0,     7,     7,     0,     7,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   261,   260,
       0,   480,     0,   240,     0,     0,   239,     7,     0,     0,
       0,     0,   152,   478,     0,   100,   100,   100,     0,     0,
       0,     0,     0,   100,   100,   100,   100,   100,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,     0,   283,
       0,   287,   288,     0,     0,     0,     0,   294,     0,   228,
     162,     0,   164,   165,   163,     0,     0,     0,     0,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,   101,   102,     0,
     103,   104,     0,     0,     0,     0,   103,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,   387,
     386,   385,   388,   389,   390,     0,     7,     0,     0,     7,
       0,     7,     0,     0,   167,     0,   197,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,     0,     0,     0,     0,     0,   250,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,   236,   241,     0,   131,     0,     0,   135,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
      55,   100,   100,    94,    95,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     7,     0,   281,
       0,     0,     0,     0,   227,   167,     0,   166,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   260,     0,   257,     0,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,   408,   409,   410,   450,   451,
     452,     0,     7,     0,     7,     0,     0,     0,     0,     0,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,     0,     0,   133,     0,     0,   137,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,   289,     0,   291,
       0,     7,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
     260,     0,     0,   260,   260,   260,     0,     0,   255,   260,
       0,     0,     0,     0,     0,     0,     0,   265,   266,     0,
       0,   264,     0,   279,     0,     0,     0,     0,     0,    62,
      89,     0,     0,     0,    74,    96,    64,     0,     0,    75,
      97,     0,    61,    88,     0,     0,     0,     0,     0,    73,
      98,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,     0,     0,   201,     0,     0,   203,     0,
       0,   199,     0,   215,     0,     0,   245,   252,     0,     0,
       0,   244,   251,     0,   269,   270,   268,     0,   280,     0,
       0,     0,     0,     0,   134,     0,   138,     0,    59,    66,
      92,    93,     0,     0,    58,    65,     0,     0,    90,    91,
       0,     0,     0,     0,   290,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,   211,     0,   207,     0,     0,     0,   202,     0,     0,
     204,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,     0,     0,
      79,    80,    77,    78,     0,    63,    76,    99,     0,     0,
       7,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,   212,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   247,   249,   254,
     246,   248,   253,   271,     0,     0,     0,     0,     0,     0,
       0,   132,   136,    60,     7,   157,     0,     0,     0,     0,
       0,     0,     0,   171,     0,     0,   173,     0,     0,   169,
       0,   185,     0,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,   275,     0,   272,   277,
       0,   273,     0,     0,     0,     0,   179,     0,   181,     0,
     177,     0,     0,     0,   172,     0,     0,   174,     0,     0,
     170,     0,   214,     0,   221,     0,     0,   222,     0,     0,
     220,     0,     0,     0,     0,     0,     0,     0,   158,   180,
     182,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,     0,   217,     0,   218,     0,
     216,     0,     0,   276,   278,   274,   159,     0,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   225,   226,   224,   223,     0,   184,     0,   191,     0,
       0,   192,     0,     0,   190,     0,     0,     0,   219,     0,
     187,     0,   188,     0,   186,     0,     0,   195,   196,   194,
     193,     0,   189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -855,  -855,  1828,  -421,   780,  -855,  -855,  -772,  -855,   456,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -683,   378,
    -855,  -854,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,
    -855,  -855,  -855,   760,  -610,  -855,  -643,   956,  -855,  -855,
    -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  -855,  1392,
    -855,  -855,  -855,   -10,  -855,  1430,  1439,  1695,    89,   366,
      21,  -855,  1593,    -3,  -855,  1009,  -855,  4759
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   445,   632,    67,    68,   904,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   452,   458,  1036,
    1120,   785,   861,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   656,   657,    98,   649,   466,   798,    99,
     768,   839,   840,   100,   101,   102,   103,   104,   443,   444,
     630,   105,   106,   467,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   125,   254,   480,   481,   468
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     244,   788,   483,  1283,   259,  1286,  1356,  1359,   800,   257,
     265,  1289,   267,   261,   269,   270,   271,   623,   624,   625,
    1362,  1464,  1483,  1486,   272,   633,  1414,  1441,  1444,  1447,
     278,   279,   280,   281,  1522,    -3,     6,   640,   938,     7,
       8,     9,  1489,   940,   909,   916,   806,   453,   454,   455,
     456,   922,   923,   924,   925,   926,  1284,   289,  1287,   291,
     292,   293,  1549,  1348,  1290,   471,    10,    11,    12,    13,
      14,    15,  1350,    16,    17,    18,    19,    20,  1352,  1415,
    1442,  1445,  1448,  1452,   419,  1475,  1477,  1523,    21,    22,
      23,   650,  1038,  1376,  1479,   851,    24,   420,   421,   492,
      25,    26,     5,    27,   986,  1537,     1,  1117,    28,   422,
     423,   965,    29,    30,    31,   989,   318,    32,  1118,    33,
     905,    34,    35,    36,    37,  1190,   294,  1377,    38,   895,
     896,   493,    39,   897,   898,    40,  1118,   910,   911,   906,
     901,   294,   795,   897,   898,   899,   867,   796,   987,   900,
     901,   897,   898,   912,   858,    41,   881,   913,   901,   990,
     866,   882,   107,   859,   108,   796,   796,   943,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   494,   961,
     442,   628,  1121,   126,   796,  1122,  1199,   262,    37,   652,
     653,   859,   806,   907,   979,   859,   681,   653,  1285,   796,
    1288,  1357,  1360,   902,   472,  1349,  1291,   939,  1141,   495,
     260,   914,   941,   796,  1351,  1363,  1465,  1484,  1487,    41,
    1353,  1416,  1443,  1446,  1449,  1453,   641,  1476,  1478,  1524,
     651,   277,   408,   484,    42,    43,  1480,  1490,    44,  1102,
    1103,    45,    46,    47,    48,    49,    50,  1538,  1119,   966,
      51,    52,    53,    54,    55,    56,    57,  1550,   642,   432,
      58,   295,   310,    59,   682,   653,  1119,    60,    61,    62,
      63,    64,    65,   850,  1098,  1099,   426,  1211,   797,   459,
     460,   461,   796,  1155,   268,   479,   482,   273,   897,   898,
     805,  1158,   883,   860,   906,   901,   797,   797,    42,    43,
     282,   655,    44,   655,   908,    45,    46,    47,    48,    49,
      50,  1225,  1226,   274,   903,   797,    53,    54,    55,    56,
      57,   860,   915,   275,  1059,   860,  1212,  1156,  1216,  1365,
     797,   796,  1366,   796,   796,  1159,   255,   796,   539,   540,
     541,   542,  1367,   296,   797,  1368,  1227,   796,  1100,   550,
     796,   276,   845,   846,   283,   848,   311,   312,   313,   314,
     315,   316,   284,   643,  1369,  1370,   285,   463,   464,   796,
     796,  1229,  1230,   876,   877,   878,   879,  1242,  1243,   580,
     581,   582,   583,  -260,   317,   462,   886,   320,  -260,   463,
     464,   286,   586,   587,   683,   653,   644,   597,   287,  1244,
     288,   595,   950,   951,   952,   953,  1231,   290,  1134,  1135,
     297,   298,   299,   797,  1139,   321,   615,   616,   465,   618,
    1257,  1258,   322,   620,   621,   617,   969,   970,   971,   972,
     323,   626,   627,  1193,  1194,  1195,  1196,   453,   454,   455,
     456,   413,  1259,   611,   612,   613,   790,   791,   324,   414,
     415,   416,   417,   418,   792,   684,   653,   685,   653,  1101,
     420,   421,   797,   658,   797,   797,   880,   256,   797,   258,
     686,   653,   862,   863,   263,   264,   325,   457,   797,   326,
     864,   797,  1086,  1087,  1094,  1095,   327,   897,   898,   328,
    1088,   329,  1096,   906,   901,   954,   453,   454,   455,   456,
     797,   797,   602,   603,   604,   605,   606,   607,   608,   830,
     831,   832,   833,   834,   835,  1028,   687,   653,  1031,   973,
    1033,   109,   110,   688,   653,   111,  1197,   330,   112,   113,
     114,   115,   116,   117,  1040,  1041,  1042,  1043,   331,   118,
     119,   120,   121,   122,  1021,  1022,  1023,  1024,  1025,  1026,
    1269,  1270,  1271,  1272,   332,   123,   689,   653,   333,   124,
     690,   653,   691,   653,   692,   653,  1294,  1295,   693,   653,
    1298,  1299,  1300,   694,   653,   334,  1303,   695,   653,   696,
     653,   697,   653,   698,   653,   699,   653,   700,   653,   701,
     653,   702,   653,   703,   653,   708,   653,   709,   653,   710,
     653,   711,   653,   712,   653,   410,  1111,   713,   653,   714,
     653,   716,   653,   717,   653,   335,   765,   718,   653,   719,
     653,   720,   653,   721,   653,   722,   653,   723,   653,   724,
     653,   725,   653,   336,    -2,     6,   726,   653,     7,     8,
       9,   727,   653,   801,   728,   653,   729,   653,   337,   808,
     809,   810,   730,   653,   813,   731,   653,   732,   653,   406,
     733,   653,   734,   653,   338,    10,    11,    12,    13,    14,
      15,   339,    16,    17,    18,    19,    20,   735,   653,   736,
     653,   737,   653,   738,   653,   739,   653,    21,    22,    23,
     340,  1186,   341,  1188,   829,    24,   740,   653,   342,    25,
      26,   343,    27,   741,   653,   742,   653,    28,   743,   653,
     344,    29,    30,    31,   744,   653,    32,   345,    33,   346,
      34,    35,    36,    37,   752,   653,   347,    38,   753,   653,
     411,    39,   754,   653,    40,   755,   653,   756,   653,   757,
     653,   758,   653,   760,   653,   771,   772,   803,   804,   837,
     838,   872,   873,   348,    41,   887,   888,   889,   890,   891,
     892,   843,   844,   958,   959,  1405,  1406,  1408,  1409,   349,
    1268,  1411,  1412,  1424,  1425,  1427,  1428,  1513,  1514,  1516,
    1517,  1519,  1520,    66,    66,   350,   609,   610,   351,   352,
     353,   354,   355,   356,   884,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   935,   389,   390,
     391,   392,   393,    42,    43,   394,   395,    44,   396,   397,
      45,    46,    47,    48,    49,    50,  1336,   398,   399,    51,
      52,    53,    54,    55,    56,    57,   400,   401,   402,    58,
     403,   404,    59,   405,   407,   412,    60,    61,    62,    63,
      64,    65,   424,   425,   427,   428,   437,   429,   985,   430,
     988,   431,   991,   433,   434,   435,   436,   438,   439,   440,
     442,   441,   446,   447,   448,   449,   450,   451,   469,   470,
     473,   474,   475,   478,   476,   477,   485,   487,   584,   486,
     614,     6,   488,   489,     7,     8,     9,   490,   496,   491,
     497,   498,   520,   667,   499,   500,   501,   502,  1030,   503,
    1032,   504,   505,   506,   507,   521,   655,   674,   527,   528,
     529,    10,    11,    12,    13,    14,    15,   585,    16,    17,
      18,    19,    20,   622,   599,   619,   634,   635,   664,   636,
     637,   680,   638,   654,    22,    23,   639,   665,   646,  1436,
     647,    24,  -282,  -282,  -282,    25,    26,   662,    27,   648,
     659,   660,   661,    28,  1080,   663,   666,    29,    30,    31,
    1085,   668,    32,   669,    33,  1091,    34,    35,    36,    37,
     670,   671,   672,    38,   673,   675,   676,    39,   677,   678,
      40,   679,   775,  1473,   704,   778,   705,   811,   706,   762,
     707,   937,   715,   745,   779,   746,   747,   748,   749,   750,
      41,   751,   759,   761,   763,   764,   766,   767,   773,   774,
     776,   780,   781,   782,   784,   786,   783,   793,   794,   789,
     787,   964,   993,   799,   807,   812,   820,   814,   821,   815,
     996,   816,   817,   917,  1154,   836,  1157,   818,   819,  1161,
     822,   823,  1164,   824,   825,   826,   827,   841,   828,   842,
    1172,   847,   849,  1175,   855,   992,   852,   853,   854,   856,
     857,   865,   868,   918,   869,   870,   871,   874,   875,   885,
     893,  1004,   894,   919,   920,   921,   927,   928,   974,    42,
      43,   929,   930,    44,   931,   932,    45,    46,    47,    48,
      49,    50,   933,   934,   936,    51,    52,    53,    54,    55,
      56,    57,   944,   945,   946,    58,   947,   948,    59,   949,
     960,   957,    60,    61,    62,    63,    64,    65,   955,   956,
     962,   963,   967,   968,  1007,  1070,     6,   975,   980,     7,
       8,     9,   976,  1493,   977,   978,   981,   982,   984,   999,
    1496,  1262,   994,   995,   997,   998,  1000,  1001,  1002,  1003,
    1005,  1049,  1006,  1008,  1009,  1010,    10,    11,    12,    13,
      14,    15,  1011,    16,    17,    18,    19,    20,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1027,  1029,  1137,    22,
      23,  1020,  1034,  1035,  1037,  1039,    24,  1055,  1044,  1045,
      25,    26,  1046,    27,  1047,  1315,  1048,  1317,    28,  -297,
    -297,  -297,    29,    30,    31,  1050,  1051,    32,  1053,    33,
    1052,    34,    35,    36,    37,  1054,  1056,  1057,    38,  1060,
    1058,  1330,    39,  1061,  1062,    40,  1063,  1064,  1065,  1066,
       6,  1067,  1068,     7,     8,     9,  1069,  1071,  1072,  1073,
    1138,  1142,  1074,  1083,  1076,    41,  1075,  1077,  1078,  1079,
    1081,  1082,  1084,  1089,  1090,  1092,  1097,  1093,  1104,  1127,
      10,    11,    12,    13,    14,    15,  1105,    16,    17,    18,
      19,    20,  1106,  1107,  1108,  1109,  1110,  1112,  1114,  1132,
    1180,  1123,  1124,    22,    23,  1125,  1126,  1128,  1129,  1130,
      24,  -284,  -284,  -284,    25,    26,  1131,    27,  1133,  1136,
    1140,  1143,    28,  1144,  1145,  1146,    29,    30,    31,  1147,
    1153,    32,  1148,    33,  1149,    34,    35,    36,    37,  1150,
    1160,  1152,    38,  1151,    42,    43,    39,  1162,    44,    40,
    1163,    45,    46,    47,    48,    49,    50,  1165,  1184,  1166,
      51,    52,    53,    54,    55,    56,    57,  1167,  1170,    41,
      58,  1168,  1169,    59,  1171,  1173,  1174,    60,    61,    62,
      63,    64,    65,  1176,  1177,  1178,  1179,  1181,  1207,  1182,
    1183,  1185,  1187,  1189,  1191,  1198,  1209,  1192,  1210,  1200,
    1201,  1202,  1203,  1116,   802,   645,   598,  1232,  1247,  1204,
    1205,  1206,  1208,  1213,  1214,  1215,  1223,  1218,  1219,  1217,
    1248,  1255,  1220,  1221,  1222,  1224,  1228,  1233,  1234,  1264,
    1235,  1456,  1236,  1237,  1239,  1238,  1240,  1245,  1241,  1246,
    1249,  1250,  1256,  1252,  1253,  1251,  1260,  1263,    42,    43,
    1254,  1261,    44,  1267,  1273,    45,    46,    47,    48,    49,
      50,  1274,  1275,  1276,    51,    52,    53,    54,    55,    56,
      57,  1277,  1278,  1279,    58,     6,  1280,    59,     7,     8,
       9,    60,    61,    62,    63,    64,    65,  1281,  1292,  1282,
    1309,  1310,  1293,  1296,  1297,  1301,  1302,  1304,  1305,  1306,
    1307,  1308,  1311,  1343,  1312,    10,    11,    12,    13,    14,
      15,  1337,    16,    17,    18,    19,    20,  1313,  1314,  1316,
    1318,  1319,  1320,  1321,  1459,  1324,  1325,  1322,    22,    23,
    1323,  1326,  1327,  1328,  1329,    24,  1334,  1335,  1331,    25,
      26,  1332,    27,  1333,  1339,     6,  1340,    28,     7,     8,
       9,    29,    30,    31,  1341,  1342,    32,  1344,    33,  1345,
      34,    35,    36,    37,  1346,  1347,  1355,    38,  1338,  1354,
    1358,    39,  1361,  1372,    40,    10,    11,    12,    13,    14,
      15,  1388,    16,    17,    18,    19,    20,  1364,  1371,  1373,
    1374,  1378,  1375,  1379,    41,  1392,  1380,  1381,    22,    23,
    1382,  1383,  1384,  1385,  1386,    24,  1387,  1390,  1391,    25,
      26,  1393,    27,  1394,  1395,  1396,  1397,    28,  1398,  1401,
    1407,    29,    30,    31,  1399,  1400,    32,  1402,    33,  1403,
      34,    35,    36,    37,  1404,  1410,  1413,    38,  1389,  1417,
    1418,    39,  1419,  1420,    40,  1421,  1422,  1423,  1440,  1450,
    1431,  1426,  1429,  1430,  1432,  1433,  1434,  1435,  1462,  1532,
    1467,  1437,  1438,  1439,    41,  1451,  1454,  1455,  1499,  1463,
    1457,  1458,  1461,    42,    43,  1460,  1466,    44,  1468,  1469,
      45,    46,    47,    48,    49,    50,  1470,  1471,  1472,    51,
      52,    53,    54,    55,    56,    57,  1481,  1482,  1485,    58,
    1488,  1492,    59,  1491,  1494,  1495,    60,    61,    62,    63,
      64,    65,  1497,  1498,  1500,  1502,  1501,  1541,  1503,  1544,
    1504,  1508,  1505,  1506,  1509,  1510,  1511,  1539,  1526,  1547,
    1512,  1515,  1518,  1521,  1528,  1525,  1527,  1530,  1529,  1531,
    1533,  1534,  1535,    42,    43,  1536,  1540,    44,  1542,  1543,
      45,    46,    47,    48,    49,    50,  1545,  1546,  1548,    51,
      52,    53,    54,    55,    56,    57,  1551,  1552,  1553,    58,
       6,  1554,    59,     7,     8,     9,    60,    61,    62,    63,
      64,    65,  1555,  1556,  1557,  1559,  1558,  1560,  1561,  1563,
    1562,  1564,  1565,  1566,  1567,  1568,  1569,  1570,  1572,  1571,
      10,    11,    12,    13,    14,    15,  1573,    16,    17,    18,
      19,    20,  1574,  1575,  1576,  1577,  1578,  1579,  1580,     4,
    1582,   319,  1581,    22,    23,   629,   409,     0,     0,     0,
      24,   600,     0,     0,    25,    26,     0,    27,     0,     0,
       6,   601,    28,     7,     8,     9,    29,    30,    31,   631,
       0,    32,     0,    33,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,    39,     0,     0,    40,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
      24,     0,     0,     0,    25,    26,   769,    27,     0,     0,
       0,     0,    28,     0,     0,     0,    29,    30,    31,     0,
       0,    32,     0,    33,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
       0,     0,    44,     0,     0,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,    58,     0,     0,    59,     0,     0,
       0,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
       0,     0,    44,     0,     0,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,    58,     6,     0,    59,     7,     8,
       9,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,   770,    27,     0,     0,     6,     0,    28,     7,     8,
       9,    29,    30,    31,     0,     0,    32,     0,    33,     0,
      34,    35,    36,    37,     0,     0,     0,    38,     0,     0,
       0,    39,     0,     0,    40,    10,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    22,    23,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,     0,    27,     0,     0,     0,     0,    28,     0,     0,
       0,    29,    30,    31,     0,     0,    32,   777,    33,     0,
      34,    35,    36,    37,     0,     0,     0,    38,     0,     0,
       0,    39,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
       0,     0,    59,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
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
      24,     0,     0,     0,    25,    26,     0,    27,     0,     0,
       0,     0,    28,     0,     0,  -299,    29,    30,    31,     0,
       0,    32,     0,    33,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     0,     0,     0,     6,     0,     0,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,     0,     0,     0,     0,    28,     0,     0,     0,
      29,    30,    31,     0,   942,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,    42,    43,
      39,     0,    44,    40,     0,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,     0,     0,    41,    58,     0,     0,    59,     0,     0,
       0,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     6,
       0,    59,     7,     8,     9,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,   983,     0,     6,
       0,    28,     7,     8,     9,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     0,     0,    39,     0,     0,    40,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,    24,
       0,     0,  -286,    25,    26,     0,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     0,     0,    39,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,    44,     0,     0,    45,    46,    47,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    58,     0,     0,    59,     0,     0,     0,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
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
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,  1113,     0,     6,     0,    28,     7,     8,     9,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
      39,     0,     0,    40,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,  1115,     0,     0,     0,    28,     0,     0,     0,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
      39,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     0,
       0,    59,     0,     0,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     6,
       0,    59,     7,     8,     9,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,  1265,     0,     6,
       0,    28,     7,     8,     9,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     0,     0,    39,     0,     0,    40,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,  1266,     0,     0,
       0,    28,     0,     0,     0,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     0,     0,    39,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,    44,     0,     0,    45,    46,    47,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    58,     0,     0,    59,     0,     0,     0,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
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
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,     0,     0,     6,     0,    28,     7,     8,     9,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,  1474,     0,     0,
      39,     0,     0,    40,    10,    11,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,    27,     0,     0,     0,     0,    28,     0,     0,     0,
      29,    30,    31,     0,     0,    32,     0,    33,     0,    34,
      35,    36,    37,     0,     0,     0,    38,  1507,     0,     0,
      39,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     0,
       0,    59,   127,     0,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,   134,     0,    58,     0,
     135,    59,     0,   136,     0,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   127,     0,     0,   223,
     224,   225,     0,     0,   226,     0,     0,   227,   228,   229,
     230,   231,   232,     0,     0,     0,     0,     0,   233,   234,
     235,   236,   237,   128,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,     0,     0,   238,   239,
     240,   241,   266,     0,   242,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,   135,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     127,     0,     0,   223,   224,   225,     0,     0,   226,     0,
       0,   227,   228,   229,   230,   231,   232,     0,     0,     0,
       0,     0,   233,   234,   235,   236,   237,   128,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,   132,   133,
       0,     0,   238,   239,   240,   241,     0,     0,   242,   533,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     0,     0,     0,   135,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   127,     0,     0,   223,   224,   225,
       0,     0,   226,     0,     0,   227,   228,   229,   230,   231,
     232,     0,     0,     0,     0,     0,   233,   234,   235,   236,
     237,   128,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,     0,     0,   238,   239,   240,   241,
       0,     0,   242,   535,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,   135,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   127,     0,
       0,   223,   224,   225,     0,     0,   226,     0,     0,   227,
     228,   229,   230,   231,   232,     0,     0,     0,     0,     0,
     233,   234,   235,   236,   237,   128,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,     0,     0,
     238,   239,   240,   241,     0,     0,   242,   537,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,   135,     0,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   127,     0,     0,   223,   224,   225,     0,     0,
     226,     0,     0,   227,   228,   229,   230,   231,   232,     0,
       0,     0,     0,     0,   233,   234,   235,   236,   237,   128,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,     0,     0,   238,   239,   240,   241,     0,     0,
     242,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,     0,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   127,     0,     0,   223,
     224,   225,     0,     0,   226,     0,     0,   227,   228,   229,
     230,   231,   232,     0,     0,     0,     0,     0,   233,   234,
     235,   236,   237,   128,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,     0,     0,   238,   239,
     240,   241,     0,     0,   242,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,   223,   224,   225,     0,     0,   226,     0,
       0,   227,   228,   229,   230,   231,   232,     0,     0,     0,
       0,     0,   233,   234,   235,   236,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,   239,   240,   241,     0,     0,   242,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,     0,     0,   522,   523,   524,   525,   526,     0,     0,
       0,   530,   531,   532,   534,   536,   538,     0,     0,     0,
       0,   543,   544,   545,   546,   547,   548,   549,     0,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,     0,     0,
       0,     0,     0,     0,     0,     0,   588,   589,   590,   591,
     592,   593,   594,     0,   596
};

static const yytype_int16 yycheck[] =
{
      10,   644,    10,    46,    14,    46,    46,    46,   651,    12,
      20,    46,    22,    16,    24,    25,    26,   438,   439,   440,
      46,    46,    46,    46,    27,   446,    46,    46,    46,    46,
      33,    34,    35,    36,    46,     0,     1,    52,    72,     4,
       5,     6,    46,    72,   816,   817,   656,    11,    12,    13,
      14,   823,   824,   825,   826,   827,    99,    60,    99,    62,
      63,    64,    46,    99,    99,   102,    31,    32,    33,    34,
      35,    36,    99,    38,    39,    40,    41,    42,    99,    99,
      99,    99,    99,    99,   233,    99,    99,    99,    53,    54,
      55,   102,   946,   207,    99,   778,    61,   246,   247,   209,
      65,    66,     0,    68,   197,    99,     3,    96,    73,   248,
     249,   103,    77,    78,    79,   197,   126,    82,   107,    84,
      30,    86,    87,    88,    89,    96,   108,   241,    93,    29,
      30,   241,    97,    43,    44,   100,   107,    29,    30,    49,
      50,   108,   101,    43,    44,    45,   789,   106,   241,    49,
      50,    43,    44,    45,    98,   120,   799,    49,    50,   241,
     101,   101,   241,   107,   237,   106,   106,   850,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   210,   101,
      74,    75,    98,   237,   106,  1039,    98,   243,    89,   244,
     245,   107,   802,   103,   101,   107,   244,   245,   241,   106,
     241,   241,   241,   103,   241,   241,   241,   241,   101,   241,
     241,   103,   241,   106,   241,   241,   241,   241,   241,   120,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   237,   242,   241,   199,   200,   241,   241,   203,  1011,
    1012,   206,   207,   208,   209,   210,   211,   241,   237,   241,
     215,   216,   217,   218,   219,   220,   221,   241,   103,   262,
     225,   243,   105,   228,   244,   245,   237,   232,   233,   234,
     235,   236,   237,   237,    29,    30,   243,   101,   237,   102,
     103,   104,   106,   197,   242,   295,   296,   241,    43,    44,
     226,   197,   226,   237,    49,    50,   237,   237,   199,   200,
     237,   237,   203,   237,   214,   206,   207,   208,   209,   210,
     211,   206,   207,   241,   214,   237,   217,   218,   219,   220,
     221,   237,   214,   241,   967,   237,   101,   241,   101,   101,
     237,   106,   101,   106,   106,   241,   237,   106,   348,   349,
     350,   351,   101,   242,   237,   101,   241,   106,   103,   359,
     106,   241,   773,   774,   237,   776,   199,   200,   201,   202,
     203,   204,   237,   208,   101,   101,   243,   212,   213,   106,
     106,   206,   207,    11,    12,    13,    14,   219,   220,   389,
     390,   391,   392,   101,   227,   208,   807,   243,   106,   212,
     213,   237,   395,   396,   244,   245,   241,   407,   237,   241,
     237,   404,    11,    12,    13,    14,   241,   237,  1051,  1052,
       7,     8,     9,   237,  1057,   243,   426,   427,   241,   429,
     219,   220,   243,   433,   434,   428,    11,    12,    13,    14,
     243,   441,   442,    11,    12,    13,    14,    11,    12,    13,
      14,   242,   241,   422,   423,   424,   230,   231,   243,   250,
     251,   252,   253,   254,   238,   244,   245,   244,   245,   214,
     246,   247,   237,   473,   237,   237,   104,    11,   237,    13,
     244,   245,   230,   231,    18,    19,   243,    51,   237,   243,
     238,   237,   230,   231,   230,   231,   243,    43,    44,   243,
     238,   243,   238,    49,    50,   104,    11,    12,    13,    14,
     237,   237,   413,   414,   415,   416,   417,   418,   419,    22,
      23,    24,    25,    26,    27,   936,   244,   245,   939,   104,
     941,   199,   200,   244,   245,   203,   104,   243,   206,   207,
     208,   209,   210,   211,    11,    12,    13,    14,   243,   217,
     218,   219,   220,   221,    22,    23,    24,    25,    26,    27,
      11,    12,    13,    14,   243,   233,   244,   245,   243,   237,
     244,   245,   244,   245,   244,   245,  1209,  1210,   244,   245,
    1213,  1214,  1215,   244,   245,   243,  1219,   244,   245,   244,
     245,   244,   245,   244,   245,   244,   245,   244,   245,   244,
     245,   244,   245,   244,   245,   244,   245,   244,   245,   244,
     245,   244,   245,   244,   245,   241,  1027,   244,   245,   244,
     245,   244,   245,   244,   245,   243,   619,   244,   245,   244,
     245,   244,   245,   244,   245,   244,   245,   244,   245,   244,
     245,   244,   245,   243,     0,     1,   244,   245,     4,     5,
       6,   244,   245,   653,   244,   245,   244,   245,   243,   659,
     660,   661,   244,   245,   664,   244,   245,   244,   245,   240,
     244,   245,   244,   245,   243,    31,    32,    33,    34,    35,
      36,   243,    38,    39,    40,    41,    42,   244,   245,   244,
     245,   244,   245,   244,   245,   244,   245,    53,    54,    55,
     243,  1112,   243,  1114,   704,    61,   244,   245,   243,    65,
      66,   243,    68,   244,   245,   244,   245,    73,   244,   245,
     243,    77,    78,    79,   244,   245,    82,   243,    84,   243,
      86,    87,    88,    89,   244,   245,   243,    93,   244,   245,
      91,    97,   244,   245,   100,   244,   245,   244,   245,   244,
     245,   244,   245,   244,   245,    70,    71,   241,   242,    62,
      63,   244,   245,   243,   120,   244,   245,   244,   245,   244,
     245,   771,   772,   244,   245,    47,    48,    47,    48,   243,
    1191,    47,    48,   244,   245,   244,   245,    47,    48,    47,
      48,    47,    48,     3,     4,   243,   420,   421,   243,   243,
     243,   243,   243,   243,   804,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   837,   243,   243,
     243,   243,   243,   199,   200,   243,   243,   203,   243,   243,
     206,   207,   208,   209,   210,   211,  1267,   243,   243,   215,
     216,   217,   218,   219,   220,   221,   243,   243,   243,   225,
     243,   243,   228,   243,   243,    90,   232,   233,   234,   235,
     236,   237,   229,   108,   242,   242,    56,   242,   888,   241,
     890,   241,   892,   242,   242,   241,   241,   241,   241,   241,
      74,   242,   241,   241,   241,   241,   241,    49,   241,   241,
     233,   241,   195,   237,   196,   196,   241,   243,   237,   241,
     237,     1,   243,   243,     4,     5,     6,   243,   241,   243,
     241,   241,   244,   238,   243,   243,   243,   243,   938,   243,
     940,   243,   243,   241,   241,   244,   237,   237,   244,   244,
     244,    31,    32,    33,    34,    35,    36,   244,    38,    39,
      40,    41,    42,   241,   244,   244,   241,   243,   245,   243,
     243,   205,   243,   241,    54,    55,   243,   241,   243,  1390,
     243,    61,    62,    63,    64,    65,    66,   244,    68,   243,
     243,   243,   243,    73,   994,   244,   243,    77,    78,    79,
    1000,   238,    82,   238,    84,  1005,    86,    87,    88,    89,
     238,   238,   243,    93,   243,   238,   238,    97,   238,   238,
     100,   238,    76,  1434,   245,    95,   244,   108,   244,   241,
     244,    64,   245,   244,   238,   244,   244,   244,   244,   244,
     120,   244,   244,   244,   241,   241,   241,   241,   241,   241,
     241,   238,   238,   238,   243,   243,   240,   237,   237,   241,
     243,   102,    30,   241,   241,   241,   237,   248,   237,   244,
      30,   244,   244,   238,  1074,   241,  1076,   245,   245,  1079,
     244,   244,  1082,   244,   244,   244,   244,   241,   245,   241,
    1090,   241,   241,  1093,   245,   248,   244,   244,   244,   244,
     240,   237,   245,   238,   245,   244,   244,   241,   237,   241,
     237,    30,   245,   244,   244,   241,   240,   245,   243,   199,
     200,   244,   244,   203,   244,   244,   206,   207,   208,   209,
     210,   211,   244,   244,   241,   215,   216,   217,   218,   219,
     220,   221,   241,   238,   241,   225,   244,   241,   228,   237,
     241,   244,   232,   233,   234,   235,   236,   237,   245,   245,
     238,   238,   241,   238,    30,   237,     1,   243,   241,     4,
       5,     6,   243,    48,   243,   243,   241,   241,   241,   241,
      48,  1181,   243,   243,   243,   243,   243,   243,   243,   241,
     243,   238,   243,   243,   243,   241,    31,    32,    33,    34,
      35,    36,   244,    38,    39,    40,    41,    42,   244,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   102,    54,
      55,   244,   241,   241,   244,   241,    61,   244,   243,   243,
      65,    66,   243,    68,   243,  1235,   243,  1237,    73,    74,
      75,    76,    77,    78,    79,   238,   241,    82,   238,    84,
     241,    86,    87,    88,    89,   241,   244,   241,    93,   244,
     243,  1261,    97,   243,   243,   100,   243,   243,   243,   238,
       1,   238,   238,     4,     5,     6,   238,   241,   241,   244,
     102,   102,   243,   238,   243,   120,   244,   244,   244,   243,
     237,   243,   237,   237,   243,   237,   237,   243,   241,   238,
      31,    32,    33,    34,    35,    36,   244,    38,    39,    40,
      41,    42,   244,   244,   244,   244,   244,   241,   241,   244,
      30,   243,   243,    54,    55,   243,   243,   238,   238,   238,
      61,    62,    63,    64,    65,    66,   237,    68,   244,   244,
     238,   238,    73,   238,   238,   238,    77,    78,    79,   237,
     241,    82,   244,    84,   244,    86,    87,    88,    89,   244,
     241,   244,    93,   245,   199,   200,    97,   244,   203,   100,
     244,   206,   207,   208,   209,   210,   211,   244,   241,   244,
     215,   216,   217,   218,   219,   220,   221,   244,   244,   120,
     225,   245,   245,   228,   244,   244,   244,   232,   233,   234,
     235,   236,   237,   245,   245,   244,   244,   243,   245,   243,
     243,   241,   241,   241,   241,   241,   241,   237,   241,   238,
     238,   238,   238,  1035,   654,   459,   407,   238,   238,   244,
     244,   244,   244,   241,   241,   241,   245,   241,   241,   244,
     238,   238,   244,   244,   244,   244,   241,   241,   244,   237,
     243,    47,   244,   243,   241,   244,   241,   241,   244,   241,
     241,   241,   238,   241,   241,   244,   241,   238,   199,   200,
     244,   243,   203,   241,   243,   206,   207,   208,   209,   210,
     211,   243,   243,   243,   215,   216,   217,   218,   219,   220,
     221,   243,   241,   244,   225,     1,   244,   228,     4,     5,
       6,   232,   233,   234,   235,   236,   237,   244,   238,   245,
     243,   243,   241,   241,   241,   241,   241,   241,   241,   241,
     238,   241,   243,   238,   243,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   244,   241,   241,
     241,   241,   241,   241,    47,   241,   241,   244,    54,    55,
     244,   244,   244,   241,   241,    61,   241,   241,   244,    65,
      66,   244,    68,   244,   243,     1,   243,    73,     4,     5,
       6,    77,    78,    79,   243,   243,    82,   238,    84,   238,
      86,    87,    88,    89,   238,   237,   243,    93,    94,   238,
     243,    97,   243,   237,   100,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   244,   244,   238,
     237,   244,   238,   244,   120,   238,   241,   241,    54,    55,
     241,   241,   244,   241,   241,    61,   241,   241,   241,    65,
      66,   238,    68,   238,   238,   244,   244,    73,   244,   241,
     243,    77,    78,    79,   245,   244,    82,   241,    84,   241,
      86,    87,    88,    89,   244,   243,   243,    93,    94,   241,
     241,    97,   241,   241,   100,   241,   241,   241,   245,   238,
     241,   244,   244,   243,   241,   241,   241,   241,    47,    47,
     238,   244,   244,   244,   120,   241,   245,   244,    48,   243,
     245,   244,   244,   199,   200,   245,   241,   203,   241,   241,
     206,   207,   208,   209,   210,   211,   238,   241,   238,   215,
     216,   217,   218,   219,   220,   221,   238,   243,   243,   225,
     243,   241,   228,   244,   241,   244,   232,   233,   234,   235,
     236,   237,   241,   244,   241,    48,   244,    47,   243,    47,
     244,   241,   244,   244,   241,   241,   241,   245,   241,    47,
     244,   243,   243,   243,   241,   244,   244,   241,   244,   244,
     241,   241,   241,   199,   200,   241,   244,   203,   245,   244,
     206,   207,   208,   209,   210,   211,   245,   244,   243,   215,
     216,   217,   218,   219,   220,   221,   241,   241,   241,   225,
       1,   241,   228,     4,     5,     6,   232,   233,   234,   235,
     236,   237,   244,   241,    48,   244,   241,    48,   241,    48,
     244,   241,   244,    48,   243,   241,   244,   241,   241,   244,
      31,    32,    33,    34,    35,    36,   244,    38,    39,    40,
      41,    42,   241,   244,    47,   241,   241,   241,   241,     1,
     241,   136,   244,    54,    55,   443,   243,    -1,    -1,    -1,
      61,   411,    -1,    -1,    65,    66,    -1,    68,    -1,    -1,
       1,   412,    73,     4,     5,     6,    77,    78,    79,    80,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,
      -1,    -1,   203,    -1,    -1,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,   228,    -1,    -1,
      -1,   232,   233,   234,   235,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,
      -1,    -1,   203,    -1,    -1,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,   225,     1,    -1,   228,     4,     5,
       6,   232,   233,   234,   235,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,     1,    -1,    73,     4,     5,
       6,    77,    78,    79,    -1,    -1,    82,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    82,    83,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,   228,    -1,    -1,    -1,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,   225,
       1,    -1,   228,     4,     5,     6,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    65,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    76,    77,    78,    79,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    81,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    93,    -1,   199,   200,
      97,    -1,   203,   100,    -1,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,   120,   225,    -1,    -1,   228,    -1,    -1,
      -1,   232,   233,   234,   235,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,   225,     1,
      -1,   228,     4,     5,     6,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,     1,
      -1,    73,     4,     5,     6,    77,    78,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    65,    66,    -1,    68,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,   203,    -1,    -1,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,   203,    -1,    -1,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   225,     1,    -1,   228,     4,     5,     6,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,
      -1,    68,    69,    -1,     1,    -1,    73,     4,     5,     6,
      77,    78,    79,    -1,    -1,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,   100,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,
      -1,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,   228,    -1,    -1,    -1,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,   225,     1,
      -1,   228,     4,     5,     6,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,     1,
      -1,    73,     4,     5,     6,    77,    78,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,   203,    -1,    -1,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,   203,    -1,    -1,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   225,     1,    -1,   228,     4,     5,     6,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,
      -1,    68,    -1,    -1,     1,    -1,    73,     4,     5,     6,
      77,    78,    79,    -1,    -1,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    -1,   100,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    93,    94,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,   228,    21,    -1,    -1,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,   199,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    -1,    85,    -1,   225,    -1,
      89,   228,    -1,    92,    -1,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    21,    -1,    -1,   198,
     199,   200,    -1,    -1,   203,    -1,    -1,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    -1,    -1,   237,   238,
     239,   240,   241,    -1,   243,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      21,    -1,    -1,   198,   199,   200,    -1,    -1,   203,    -1,
      -1,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      -1,    -1,   237,   238,   239,   240,    -1,    -1,   243,   244,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,    21,    -1,    -1,   198,   199,   200,
      -1,    -1,   203,    -1,    -1,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    -1,    -1,   237,   238,   239,   240,
      -1,    -1,   243,   244,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    21,    -1,
      -1,   198,   199,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,
     237,   238,   239,   240,    -1,    -1,   243,   244,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    21,    -1,    -1,   198,   199,   200,    -1,    -1,
     203,    -1,    -1,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    -1,    -1,   237,   238,   239,   240,    -1,    -1,
     243,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    21,    -1,    -1,   198,
     199,   200,    -1,    -1,   203,    -1,    -1,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    -1,    -1,   237,   238,
     239,   240,    -1,    -1,   243,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,   198,   199,   200,    -1,    -1,   203,    -1,
      -1,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,   239,   240,    -1,    -1,   243,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,    -1,    -1,   334,   335,   336,   337,   338,    -1,    -1,
      -1,   342,   343,   344,   345,   346,   347,    -1,    -1,    -1,
      -1,   352,   353,   354,   355,   356,   357,   358,    -1,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,   400,
     401,   402,   403,    -1,   405
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   256,   257,   257,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    53,    54,    55,    61,    65,    66,    68,    73,    77,
      78,    79,    82,    84,    86,    87,    88,    89,    93,    97,
     100,   120,   199,   200,   203,   206,   207,   208,   209,   210,
     211,   215,   216,   217,   218,   219,   220,   221,   225,   228,
     232,   233,   234,   235,   236,   237,   259,   260,   261,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   300,   304,
     308,   309,   310,   311,   312,   316,   317,   241,   237,   199,
     200,   203,   206,   207,   208,   209,   210,   211,   217,   218,
     219,   220,   221,   233,   237,   328,   237,    21,    48,    56,
      57,    58,    59,    60,    85,    89,    92,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   198,   199,   200,   203,   206,   207,   208,
     209,   210,   211,   217,   218,   219,   220,   221,   237,   238,
     239,   240,   243,   247,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   329,   237,   264,   328,   264,   318,
     241,   328,   243,   264,   264,   318,   241,   318,   242,   318,
     318,   318,   328,   241,   241,   241,   241,   237,   328,   328,
     328,   328,   237,   237,   237,   243,   237,   237,   237,   328,
     237,   328,   328,   328,   108,   243,   242,     7,     8,     9,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     105,   199,   200,   201,   202,   203,   204,   227,   318,   322,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   240,   243,   318,   327,
     241,    91,    90,   242,   250,   251,   252,   253,   254,   233,
     246,   247,   248,   249,   229,   108,   243,   242,   242,   242,
     241,   241,   328,   242,   242,   241,   241,    56,   241,   241,
     241,   242,    74,   313,   314,   258,   241,   241,   241,   241,
     241,    49,   282,    11,    12,    13,    14,    51,   283,   102,
     103,   104,   208,   212,   213,   241,   302,   318,   332,   241,
     241,   102,   241,   233,   241,   195,   196,   196,   237,   318,
     330,   331,   318,    10,   241,   241,   241,   243,   243,   243,
     243,   243,   209,   241,   210,   241,   241,   241,   241,   243,
     243,   243,   243,   243,   243,   243,   241,   241,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     244,   244,   332,   332,   332,   332,   332,   244,   244,   244,
     332,   332,   332,   244,   332,   244,   332,   244,   332,   318,
     318,   318,   318,   332,   332,   332,   332,   332,   332,   332,
     318,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     318,   318,   318,   318,   237,   244,   328,   328,   332,   332,
     332,   332,   332,   332,   332,   328,   332,   318,   330,   244,
     320,   321,   323,   323,   323,   323,   323,   323,   323,   324,
     324,   325,   325,   325,   237,   318,   318,   328,   318,   244,
     318,   318,   241,   258,   258,   258,   318,   318,    75,   314,
     315,    80,   259,   258,   241,   243,   243,   243,   243,   243,
      52,   241,   103,   208,   241,   302,   243,   243,   243,   301,
     102,   241,   244,   245,   241,   237,   298,   299,   318,   243,
     243,   243,   244,   244,   245,   241,   243,   238,   238,   238,
     238,   238,   243,   243,   237,   238,   238,   238,   238,   238,
     205,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   245,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   245,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   241,   241,   241,   328,   241,   241,   305,    67,
      67,    70,    71,   241,   241,    76,   241,    83,    95,   238,
     238,   238,   238,   240,   243,   286,   243,   243,   301,   241,
     230,   231,   238,   237,   237,   101,   106,   237,   303,   241,
     301,   318,   298,   241,   242,   226,   299,   241,   318,   318,
     318,   108,   241,   318,   248,   244,   244,   244,   245,   245,
     237,   237,   244,   244,   244,   244,   244,   244,   245,   318,
      22,    23,    24,    25,    26,    27,   241,    62,    63,   306,
     307,   241,   241,   318,   318,   258,   258,   241,   258,   241,
     237,   283,   244,   244,   244,   245,   244,   240,    98,   107,
     237,   287,   230,   231,   238,   237,   101,   301,   245,   245,
     244,   244,   244,   245,   241,   237,    11,    12,    13,    14,
     104,   301,   101,   226,   318,   241,   258,   244,   245,   244,
     245,   244,   245,   237,   245,    29,    30,    43,    44,    45,
      49,    50,   103,   214,   262,    30,    49,   103,   214,   262,
      29,    30,    45,    49,   103,   214,   262,   238,   238,   244,
     244,   241,   262,   262,   262,   262,   262,   240,   245,   244,
     244,   244,   244,   244,   244,   318,   241,    64,    72,   241,
      72,   241,    81,   283,   241,   238,   241,   244,   241,   237,
      11,    12,    13,    14,   104,   245,   245,   244,   244,   245,
     241,   101,   238,   238,   102,   103,   241,   241,   238,    11,
      12,    13,    14,   104,   243,   243,   243,   243,   243,   101,
     241,   241,   241,    69,   241,   318,   197,   241,   318,   197,
     241,   318,   248,    30,   243,   243,    30,   243,   243,   241,
     243,   243,   243,   241,    30,   243,   243,    30,   243,   243,
     241,   244,   244,   241,   241,   241,   241,   241,   241,   241,
     244,    22,    23,    24,    25,    26,    27,   241,   258,   241,
     318,   258,   318,   258,   241,   241,   284,   244,   286,   241,
      11,    12,    13,    14,   243,   243,   243,   243,   243,   238,
     238,   241,   241,   238,   241,   244,   244,   241,   243,   301,
     244,   243,   243,   243,   243,   243,   238,   238,   238,   238,
     237,   241,   241,   244,   243,   244,   243,   244,   244,   243,
     318,   237,   243,   238,   237,   318,   230,   231,   238,   237,
     243,   318,   237,   243,   230,   231,   238,   237,    29,    30,
     103,   214,   262,   262,   241,   244,   244,   244,   244,   244,
     244,   258,   241,    69,   241,    69,   284,    96,   107,   237,
     285,    98,   286,   243,   243,   243,   243,   238,   238,   238,
     238,   237,   244,   244,   301,   301,   244,   102,   102,   301,
     238,   101,   102,   238,   238,   238,   238,   237,   244,   244,
     244,   245,   244,   241,   318,   197,   241,   318,   197,   241,
     241,   318,   244,   244,   318,   244,   244,   244,   245,   245,
     244,   244,   318,   244,   244,   318,   245,   245,   244,   244,
      30,   243,   243,   243,   241,   241,   258,   241,   258,   241,
      96,   241,   237,    11,    12,    13,    14,   104,   241,    98,
     238,   238,   238,   238,   244,   244,   244,   245,   244,   241,
     241,   101,   101,   241,   241,   241,   101,   244,   241,   241,
     244,   244,   244,   245,   244,   206,   207,   241,   241,   206,
     207,   241,   238,   241,   244,   243,   244,   243,   244,   241,
     241,   244,   219,   220,   241,   241,   241,   238,   238,   241,
     241,   244,   241,   241,   244,   238,   238,   219,   220,   241,
     241,   243,   318,   238,   237,    69,    69,   241,   258,    11,
      12,    13,    14,   243,   243,   243,   243,   243,   241,   244,
     244,   244,   245,    46,    99,   241,    46,    99,   241,    46,
      99,   241,   238,   241,   301,   301,   241,   241,   301,   301,
     301,   241,   241,   301,   241,   241,   241,   238,   241,   243,
     243,   243,   243,   244,   241,   318,   241,   318,   241,   241,
     241,   241,   244,   244,   241,   241,   244,   244,   241,   241,
     318,   244,   244,   244,   241,   241,   258,    37,    94,   243,
     243,   243,   243,   238,   238,   238,   238,   237,    99,   241,
      99,   241,    99,   241,   238,   243,    46,   241,   243,    46,
     241,   243,    46,   241,   244,   101,   101,   101,   101,   101,
     101,   244,   237,   238,   237,   238,   207,   241,   244,   244,
     241,   241,   241,   241,   244,   241,   241,   241,    37,    94,
     241,   241,   238,   238,   238,   238,   244,   244,   244,   245,
     244,   241,   241,   241,   244,    47,    48,   243,    47,    48,
     243,    47,    48,   243,    46,    99,   241,   241,   241,   241,
     241,   241,   241,   241,   244,   245,   244,   244,   245,   244,
     243,   241,   241,   241,   241,   241,   258,   244,   244,   244,
     245,    46,    99,   241,    46,    99,   241,    46,    99,   241,
     238,   241,    99,   241,   245,   244,    47,   245,   244,    47,
     245,   244,    47,   243,    46,   241,   241,   238,   241,   241,
     238,   241,   238,   258,    94,    99,   241,    99,   241,    99,
     241,   238,   243,    46,   241,   243,    46,   241,   243,    46,
     241,   244,   241,    48,   241,   244,    48,   241,   244,    48,
     241,   244,    48,   243,   244,   244,   244,    94,   241,   241,
     241,   241,   244,    47,    48,   243,    47,    48,   243,    47,
      48,   243,    46,    99,   241,   244,   241,   244,   241,   244,
     241,   244,    47,   241,   241,   241,   241,    99,   241,   245,
     244,    47,   245,   244,    47,   245,   244,    47,   243,    46,
     241,   241,   241,   241,   241,   244,   241,    48,   241,   244,
      48,   241,   244,    48,   241,   244,    48,   243,   241,   244,
     241,   244,   241,   244,   241,   244,    47,   241,   241,   241,
     241,   244,   241
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   255,   256,   256,   257,   257,   257,   258,   258,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   260,
     260,   260,   260,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     262,   262,   262,   262,   262,   263,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   266,
     267,   267,   268,   268,   268,   268,   269,   269,   269,   269,
     270,   271,   272,   273,   273,   274,   274,   275,   276,   277,
     278,   278,   279,   280,   280,   280,   281,   281,   281,   281,
     282,   282,   283,   283,   283,   283,   283,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   297,   298,   298,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     301,   301,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   304,   305,   305,   306,   307,   307,   308,   309,   310,
     310,   310,   310,   311,   312,   313,   313,   314,   315,   315,
     316,   317,   318,   319,   319,   320,   320,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   323,   323,   323,
     324,   324,   324,   325,   325,   326,   326,   327,   327,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   330,   330,   331,   331,   332,
     332
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
       1,     1,     1,     1,     3,     0,     1,     1,     3,     1,
       3
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
#line 3181 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 201 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3189 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 208 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3199 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 213 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3210 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 222 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3218 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 225 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3229 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3235 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3241 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3247 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3253 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 238 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3259 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3265 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3271 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3277 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 242 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3283 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3289 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3295 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3301 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3307 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 247 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3313 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 248 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3319 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 249 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3325 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3331 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3337 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3343 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3349 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3355 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3361 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3367 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3373 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3379 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3385 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3391 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3397 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 262 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3403 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 263 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3409 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 264 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3415 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 265 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3421 "build/parser.cpp"
    break;

  case 41: /* statement: xml_into_stmt  */
#line 266 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3427 "build/parser.cpp"
    break;

  case 42: /* statement: data_into_stmt  */
#line 267 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3433 "build/parser.cpp"
    break;

  case 43: /* statement: data_gen_stmt  */
#line 268 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3439 "build/parser.cpp"
    break;

  case 44: /* statement: in_da_stmt  */
#line 269 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3445 "build/parser.cpp"
    break;

  case 45: /* statement: out_da_stmt  */
#line 270 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3451 "build/parser.cpp"
    break;

  case 46: /* statement: unlock_da_stmt  */
#line 271 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3457 "build/parser.cpp"
    break;

  case 47: /* statement: expr_stmt  */
#line 272 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3463 "build/parser.cpp"
    break;

  case 48: /* statement: error SEMICOLON  */
#line 273 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3469 "build/parser.cpp"
    break;

  case 49: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 278 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3478 "build/parser.cpp"
    break;

  case 50: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 282 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3487 "build/parser.cpp"
    break;

  case 51: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 286 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3496 "build/parser.cpp"
    break;

  case 52: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 290 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3505 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 298 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3515 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 303 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3525 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 308 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3535 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 313 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3545 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 318 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3555 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 323 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3565 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 328 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3575 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 333 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3585 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 338 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3595 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 343 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3605 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 348 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3615 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 353 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3625 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 359 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3636 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 365 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3647 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 371 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3656 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 375 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3665 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 379 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3674 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 383 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3683 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 387 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3692 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 391 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3701 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 395 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3710 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 399 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3719 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 403 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3728 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 407 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3737 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 411 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3748 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 417 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3759 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 423 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3770 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 429 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3781 "build/parser.cpp"
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
#line 3793 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 442 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3803 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 447 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3814 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 453 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3824 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 458 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3834 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 463 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3844 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 468 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3854 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 473 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3864 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 478 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3874 "build/parser.cpp"
    break;

  case 90: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 483 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3884 "build/parser.cpp"
    break;

  case 91: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 488 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3894 "build/parser.cpp"
    break;

  case 92: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 493 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3904 "build/parser.cpp"
    break;

  case 93: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 498 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3914 "build/parser.cpp"
    break;

  case 94: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 503 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3924 "build/parser.cpp"
    break;

  case 95: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 508 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3934 "build/parser.cpp"
    break;

  case 96: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 513 "src/parser.y"
                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3944 "build/parser.cpp"
    break;

  case 97: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 518 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3954 "build/parser.cpp"
    break;

  case 98: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 523 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3964 "build/parser.cpp"
    break;

  case 99: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 528 "src/parser.y"
                                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-11].sval)); free((yyvsp[-2].sval));
    }
#line 3974 "build/parser.cpp"
    break;

  case 100: /* dcl_s_keywords: %empty  */
#line 536 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3980 "build/parser.cpp"
    break;

  case 101: /* dcl_s_keywords: KW_STATIC  */
#line 537 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3986 "build/parser.cpp"
    break;

  case 102: /* dcl_s_keywords: KW_TEMPLATE  */
#line 538 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3992 "build/parser.cpp"
    break;

  case 103: /* dcl_s_keywords: KW_EXPORT  */
#line 539 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3998 "build/parser.cpp"
    break;

  case 104: /* dcl_s_keywords: KW_IMPORT  */
#line 540 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 4004 "build/parser.cpp"
    break;

  case 105: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 545 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 4013 "build/parser.cpp"
    break;

  case 106: /* eval_target: IDENTIFIER  */
#line 552 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4022 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_POS  */
#line 556 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 4028 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_OVERLAY  */
#line 557 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 4034 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_PREFIX  */
#line 558 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 4040 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_UNS  */
#line 559 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 4046 "build/parser.cpp"
    break;

  case 111: /* eval_target: KW_FLOAT_TYPE  */
#line 560 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 4052 "build/parser.cpp"
    break;

  case 112: /* eval_target: KW_GRAPH  */
#line 561 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 4058 "build/parser.cpp"
    break;

  case 113: /* eval_target: KW_ASCEND  */
#line 562 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 4064 "build/parser.cpp"
    break;

  case 114: /* eval_target: KW_DESCEND  */
#line 563 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 4070 "build/parser.cpp"
    break;

  case 115: /* eval_target: KW_RTNPARM  */
#line 564 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4076 "build/parser.cpp"
    break;

  case 116: /* eval_target: KW_OPDESC  */
#line 565 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4082 "build/parser.cpp"
    break;

  case 117: /* eval_target: KW_NULLIND  */
#line 566 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4088 "build/parser.cpp"
    break;

  case 118: /* eval_target: KW_DATFMT  */
#line 567 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4094 "build/parser.cpp"
    break;

  case 119: /* eval_target: KW_TIMFMT  */
#line 568 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4100 "build/parser.cpp"
    break;

  case 120: /* eval_target: KW_EXTNAME  */
#line 569 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4106 "build/parser.cpp"
    break;

  case 121: /* eval_target: INDICATOR  */
#line 570 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 4114 "build/parser.cpp"
    break;

  case 122: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 573 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 4125 "build/parser.cpp"
    break;

  case 123: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 579 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 4134 "build/parser.cpp"
    break;

  case 124: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 583 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 4145 "build/parser.cpp"
    break;

  case 125: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 589 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 4153 "build/parser.cpp"
    break;

  case 126: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 595 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4164 "build/parser.cpp"
    break;

  case 127: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 601 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4175 "build/parser.cpp"
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
#line 4188 "build/parser.cpp"
    break;

  case 129: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 618 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4198 "build/parser.cpp"
    break;

  case 130: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 626 "src/parser.y"
                                                                                  {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-7].sval));
    }
#line 4209 "build/parser.cpp"
    break;

  case 131: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression RPAREN SEMICOLON  */
#line 632 "src/parser.y"
                                                                   {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-5].sval));
    }
#line 4220 "build/parser.cpp"
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
#line 4232 "build/parser.cpp"
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
#line 4244 "build/parser.cpp"
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
#line 4256 "build/parser.cpp"
    break;

  case 135: /* data_into_stmt: KW_DATA_INTO ident BIF_DATA LPAREN expression RPAREN SEMICOLON  */
#line 662 "src/parser.y"
                                                                     {
        (yyval.stmt) = new rpg::DataIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr, nullptr);
        free((yyvsp[-5].sval));
    }
#line 4267 "build/parser.cpp"
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
#line 4279 "build/parser.cpp"
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
#line 4291 "build/parser.cpp"
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
#line 4303 "build/parser.cpp"
    break;

  case 139: /* data_gen_stmt: KW_DATA_GEN ident BIF_DATA LPAREN expression RPAREN SEMICOLON  */
#line 692 "src/parser.y"
                                                                    {
        (yyval.stmt) = new rpg::DataGenStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr, nullptr);
        free((yyvsp[-5].sval));
    }
#line 4314 "build/parser.cpp"
    break;

  case 140: /* in_da_stmt: KW_IN IDENTIFIER SEMICOLON  */
#line 701 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DataInStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4323 "build/parser.cpp"
    break;

  case 141: /* out_da_stmt: KW_OUT IDENTIFIER SEMICOLON  */
#line 708 "src/parser.y"
                                {
        (yyval.stmt) = new rpg::DataOutStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4332 "build/parser.cpp"
    break;

  case 142: /* unlock_da_stmt: KW_UNLOCK IDENTIFIER SEMICOLON  */
#line 715 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::DataUnlockStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4341 "build/parser.cpp"
    break;

  case 143: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 722 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4352 "build/parser.cpp"
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
#line 4365 "build/parser.cpp"
    break;

  case 145: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 739 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), "");
    }
#line 4373 "build/parser.cpp"
    break;

  case 146: /* callp_stmt: KW_CALLP_EXT expression SEMICOLON  */
#line 742 "src/parser.y"
                                        {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), (yyvsp[-2].sval));
        free((yyvsp[-2].sval));
    }
#line 4382 "build/parser.cpp"
    break;

  case 147: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 749 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4390 "build/parser.cpp"
    break;

  case 148: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 755 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4398 "build/parser.cpp"
    break;

  case 149: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 761 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4406 "build/parser.cpp"
    break;

  case 150: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 767 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4414 "build/parser.cpp"
    break;

  case 151: /* return_stmt: KW_RETURN SEMICOLON  */
#line 770 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4422 "build/parser.cpp"
    break;

  case 152: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 777 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4432 "build/parser.cpp"
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
#line 4453 "build/parser.cpp"
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
#line 4477 "build/parser.cpp"
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
#line 4493 "build/parser.cpp"
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
#line 4518 "build/parser.cpp"
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
#line 4544 "build/parser.cpp"
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
#line 4571 "build/parser.cpp"
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
#line 4599 "build/parser.cpp"
    break;

  case 160: /* proc_export: %empty  */
#line 946 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4605 "build/parser.cpp"
    break;

  case 161: /* proc_export: KW_EXPORT  */
#line 947 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4611 "build/parser.cpp"
    break;

  case 162: /* pi_return_type: %empty  */
#line 952 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4617 "build/parser.cpp"
    break;

  case 163: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 953 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4623 "build/parser.cpp"
    break;

  case 164: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 954 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4629 "build/parser.cpp"
    break;

  case 165: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 955 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4635 "build/parser.cpp"
    break;

  case 166: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 956 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4641 "build/parser.cpp"
    break;

  case 167: /* pi_params: %empty  */
#line 961 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4649 "build/parser.cpp"
    break;

  case 168: /* pi_params: pi_params pi_param  */
#line 964 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4659 "build/parser.cpp"
    break;

  case 169: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 972 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4668 "build/parser.cpp"
    break;

  case 170: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 976 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4677 "build/parser.cpp"
    break;

  case 171: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 980 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4686 "build/parser.cpp"
    break;

  case 172: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 984 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4695 "build/parser.cpp"
    break;

  case 173: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 988 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4704 "build/parser.cpp"
    break;

  case 174: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 992 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4713 "build/parser.cpp"
    break;

  case 175: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 996 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4722 "build/parser.cpp"
    break;

  case 176: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1000 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4731 "build/parser.cpp"
    break;

  case 177: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1005 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4740 "build/parser.cpp"
    break;

  case 178: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1009 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4749 "build/parser.cpp"
    break;

  case 179: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1013 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4758 "build/parser.cpp"
    break;

  case 180: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1017 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4767 "build/parser.cpp"
    break;

  case 181: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1021 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4776 "build/parser.cpp"
    break;

  case 182: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1025 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4785 "build/parser.cpp"
    break;

  case 183: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1029 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4794 "build/parser.cpp"
    break;

  case 184: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1033 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4803 "build/parser.cpp"
    break;

  case 185: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1037 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4813 "build/parser.cpp"
    break;

  case 186: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1043 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4823 "build/parser.cpp"
    break;

  case 187: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1048 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4833 "build/parser.cpp"
    break;

  case 188: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1053 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4843 "build/parser.cpp"
    break;

  case 189: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1058 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4853 "build/parser.cpp"
    break;

  case 190: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1064 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4863 "build/parser.cpp"
    break;

  case 191: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1069 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4873 "build/parser.cpp"
    break;

  case 192: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1074 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4883 "build/parser.cpp"
    break;

  case 193: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1079 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4893 "build/parser.cpp"
    break;

  case 194: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1085 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4903 "build/parser.cpp"
    break;

  case 195: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1090 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4913 "build/parser.cpp"
    break;

  case 196: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1095 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4923 "build/parser.cpp"
    break;

  case 197: /* pr_params: %empty  */
#line 1104 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4931 "build/parser.cpp"
    break;

  case 198: /* pr_params: pr_params pr_param  */
#line 1107 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4941 "build/parser.cpp"
    break;

  case 199: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1115 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4950 "build/parser.cpp"
    break;

  case 200: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1119 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4959 "build/parser.cpp"
    break;

  case 201: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1123 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4968 "build/parser.cpp"
    break;

  case 202: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1127 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4977 "build/parser.cpp"
    break;

  case 203: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1131 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4986 "build/parser.cpp"
    break;

  case 204: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1135 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4995 "build/parser.cpp"
    break;

  case 205: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1139 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 5004 "build/parser.cpp"
    break;

  case 206: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1143 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 5013 "build/parser.cpp"
    break;

  case 207: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1148 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5022 "build/parser.cpp"
    break;

  case 208: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1152 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5031 "build/parser.cpp"
    break;

  case 209: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1156 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5040 "build/parser.cpp"
    break;

  case 210: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1160 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5049 "build/parser.cpp"
    break;

  case 211: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1164 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 5058 "build/parser.cpp"
    break;

  case 212: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1168 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 5067 "build/parser.cpp"
    break;

  case 213: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1172 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 5076 "build/parser.cpp"
    break;

  case 214: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1176 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 5085 "build/parser.cpp"
    break;

  case 215: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1180 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 5095 "build/parser.cpp"
    break;

  case 216: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1186 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5105 "build/parser.cpp"
    break;

  case 217: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1191 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5115 "build/parser.cpp"
    break;

  case 218: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1196 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 5125 "build/parser.cpp"
    break;

  case 219: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1201 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 5135 "build/parser.cpp"
    break;

  case 220: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1207 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5145 "build/parser.cpp"
    break;

  case 221: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1212 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5155 "build/parser.cpp"
    break;

  case 222: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1217 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 5165 "build/parser.cpp"
    break;

  case 223: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1222 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5175 "build/parser.cpp"
    break;

  case 224: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1228 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5185 "build/parser.cpp"
    break;

  case 225: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1233 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5195 "build/parser.cpp"
    break;

  case 226: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1238 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5205 "build/parser.cpp"
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
#line 5218 "build/parser.cpp"
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
#line 5230 "build/parser.cpp"
    break;

  case 229: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1269 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5239 "build/parser.cpp"
    break;

  case 230: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1277 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5248 "build/parser.cpp"
    break;

  case 231: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1285 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5257 "build/parser.cpp"
    break;

  case 232: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1292 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5266 "build/parser.cpp"
    break;

  case 233: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1300 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5275 "build/parser.cpp"
    break;

  case 234: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1308 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 5286 "build/parser.cpp"
    break;

  case 235: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1319 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 5296 "build/parser.cpp"
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
#line 5309 "build/parser.cpp"
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
#line 5322 "build/parser.cpp"
    break;

  case 238: /* enum_constants: enum_constant  */
#line 1348 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 5330 "build/parser.cpp"
    break;

  case 239: /* enum_constants: enum_constants enum_constant  */
#line 1351 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 5340 "build/parser.cpp"
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
#line 5353 "build/parser.cpp"
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
#line 5367 "build/parser.cpp"
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
#line 5380 "build/parser.cpp"
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
#line 5393 "build/parser.cpp"
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
#line 5407 "build/parser.cpp"
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
#line 5421 "build/parser.cpp"
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
#line 5436 "build/parser.cpp"
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
#line 5451 "build/parser.cpp"
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
#line 5466 "build/parser.cpp"
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
#line 5481 "build/parser.cpp"
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
#line 5493 "build/parser.cpp"
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
#line 5506 "build/parser.cpp"
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
#line 5520 "build/parser.cpp"
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
#line 5535 "build/parser.cpp"
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
#line 5550 "build/parser.cpp"
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
#line 5564 "build/parser.cpp"
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
#line 5578 "build/parser.cpp"
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
#line 5592 "build/parser.cpp"
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
#line 5606 "build/parser.cpp"
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
#line 5618 "build/parser.cpp"
    break;

  case 260: /* ds_fields: %empty  */
#line 1563 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5626 "build/parser.cpp"
    break;

  case 261: /* ds_fields: ds_fields ds_field  */
#line 1566 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5636 "build/parser.cpp"
    break;

  case 262: /* psds_kw: KW_PSDS  */
#line 1574 "src/parser.y"
            {}
#line 5642 "build/parser.cpp"
    break;

  case 263: /* psds_kw: KW_SDS  */
#line 1575 "src/parser.y"
             {}
#line 5648 "build/parser.cpp"
    break;

  case 264: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1579 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5657 "build/parser.cpp"
    break;

  case 265: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1583 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5666 "build/parser.cpp"
    break;

  case 266: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1587 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5675 "build/parser.cpp"
    break;

  case 267: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1591 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5684 "build/parser.cpp"
    break;

  case 268: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1596 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5693 "build/parser.cpp"
    break;

  case 269: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1600 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5702 "build/parser.cpp"
    break;

  case 270: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1604 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5711 "build/parser.cpp"
    break;

  case 271: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1608 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5720 "build/parser.cpp"
    break;

  case 272: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1613 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5731 "build/parser.cpp"
    break;

  case 273: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1619 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5742 "build/parser.cpp"
    break;

  case 274: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1625 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5753 "build/parser.cpp"
    break;

  case 275: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1632 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5764 "build/parser.cpp"
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
#line 5776 "build/parser.cpp"
    break;

  case 277: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1646 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5787 "build/parser.cpp"
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
#line 5799 "build/parser.cpp"
    break;

  case 279: /* ds_field: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1660 "src/parser.y"
                                                              {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5810 "build/parser.cpp"
    break;

  case 280: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1666 "src/parser.y"
                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5821 "build/parser.cpp"
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
#line 5846 "build/parser.cpp"
    break;

  case 282: /* elseif_clauses: %empty  */
#line 1700 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5852 "build/parser.cpp"
    break;

  case 283: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1701 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5862 "build/parser.cpp"
    break;

  case 284: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1709 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5873 "build/parser.cpp"
    break;

  case 285: /* else_clause: %empty  */
#line 1718 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5879 "build/parser.cpp"
    break;

  case 286: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1719 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5887 "build/parser.cpp"
    break;

  case 287: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1725 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5898 "build/parser.cpp"
    break;

  case 288: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1734 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5909 "build/parser.cpp"
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
#line 5924 "build/parser.cpp"
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
#line 5939 "build/parser.cpp"
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
#line 5954 "build/parser.cpp"
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
#line 5969 "build/parser.cpp"
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
#line 5981 "build/parser.cpp"
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
#line 6002 "build/parser.cpp"
    break;

  case 295: /* when_clauses: when_clause  */
#line 1815 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 6011 "build/parser.cpp"
    break;

  case 296: /* when_clauses: when_clauses when_clause  */
#line 1819 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 6020 "build/parser.cpp"
    break;

  case 297: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1826 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 6031 "build/parser.cpp"
    break;

  case 298: /* other_clause: %empty  */
#line 1835 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 6037 "build/parser.cpp"
    break;

  case 299: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1836 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 6045 "build/parser.cpp"
    break;

  case 300: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1842 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 6051 "build/parser.cpp"
    break;

  case 301: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1846 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 6057 "build/parser.cpp"
    break;

  case 302: /* expression: or_expr  */
#line 1852 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 6063 "build/parser.cpp"
    break;

  case 303: /* or_expr: and_expr  */
#line 1856 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 6069 "build/parser.cpp"
    break;

  case 304: /* or_expr: or_expr KW_OR and_expr  */
#line 1857 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6079 "build/parser.cpp"
    break;

  case 305: /* and_expr: not_expr  */
#line 1865 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 6085 "build/parser.cpp"
    break;

  case 306: /* and_expr: and_expr KW_AND not_expr  */
#line 1866 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6095 "build/parser.cpp"
    break;

  case 307: /* not_expr: comparison_expr  */
#line 1874 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 6101 "build/parser.cpp"
    break;

  case 308: /* not_expr: KW_NOT comparison_expr  */
#line 1875 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6109 "build/parser.cpp"
    break;

  case 309: /* comparison_expr: additive_expr  */
#line 1881 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 6115 "build/parser.cpp"
    break;

  case 310: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1882 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6125 "build/parser.cpp"
    break;

  case 311: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1887 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6135 "build/parser.cpp"
    break;

  case 312: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1892 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6145 "build/parser.cpp"
    break;

  case 313: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1897 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6155 "build/parser.cpp"
    break;

  case 314: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1902 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6165 "build/parser.cpp"
    break;

  case 315: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1907 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6175 "build/parser.cpp"
    break;

  case 316: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1912 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6185 "build/parser.cpp"
    break;

  case 317: /* additive_expr: multiplicative_expr  */
#line 1920 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 6191 "build/parser.cpp"
    break;

  case 318: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1921 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6201 "build/parser.cpp"
    break;

  case 319: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1926 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6211 "build/parser.cpp"
    break;

  case 320: /* multiplicative_expr: power_expr  */
#line 1934 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6217 "build/parser.cpp"
    break;

  case 321: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1935 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6227 "build/parser.cpp"
    break;

  case 322: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1940 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6237 "build/parser.cpp"
    break;

  case 323: /* power_expr: unary_expr  */
#line 1948 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6243 "build/parser.cpp"
    break;

  case 324: /* power_expr: unary_expr POWER power_expr  */
#line 1949 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6253 "build/parser.cpp"
    break;

  case 325: /* unary_expr: postfix_expr  */
#line 1957 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6259 "build/parser.cpp"
    break;

  case 326: /* unary_expr: MINUS postfix_expr  */
#line 1958 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6269 "build/parser.cpp"
    break;

  case 327: /* postfix_expr: primary_expr  */
#line 1966 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6275 "build/parser.cpp"
    break;

  case 328: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1967 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6284 "build/parser.cpp"
    break;

  case 329: /* ident: IDENTIFIER  */
#line 1974 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 6290 "build/parser.cpp"
    break;

  case 330: /* ident: KW_UNS  */
#line 1975 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 6296 "build/parser.cpp"
    break;

  case 331: /* ident: KW_FLOAT_TYPE  */
#line 1976 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 6302 "build/parser.cpp"
    break;

  case 332: /* ident: KW_GRAPH  */
#line 1977 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 6308 "build/parser.cpp"
    break;

  case 333: /* ident: KW_ASCEND  */
#line 1978 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 6314 "build/parser.cpp"
    break;

  case 334: /* ident: KW_DESCEND  */
#line 1979 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 6320 "build/parser.cpp"
    break;

  case 335: /* ident: KW_IN  */
#line 1980 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 6326 "build/parser.cpp"
    break;

  case 336: /* ident: KW_RTNPARM  */
#line 1981 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 6332 "build/parser.cpp"
    break;

  case 337: /* ident: KW_OPDESC  */
#line 1982 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 6338 "build/parser.cpp"
    break;

  case 338: /* ident: KW_NULLIND  */
#line 1983 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 6344 "build/parser.cpp"
    break;

  case 339: /* ident: KW_DATFMT  */
#line 1984 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 6350 "build/parser.cpp"
    break;

  case 340: /* ident: KW_TIMFMT  */
#line 1985 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 6356 "build/parser.cpp"
    break;

  case 341: /* ident: KW_EXTNAME  */
#line 1986 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 6362 "build/parser.cpp"
    break;

  case 342: /* ident: KW_OVERLAY  */
#line 1987 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 6368 "build/parser.cpp"
    break;

  case 343: /* ident: KW_POS  */
#line 1988 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 6374 "build/parser.cpp"
    break;

  case 344: /* ident: KW_PREFIX  */
#line 1989 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 6380 "build/parser.cpp"
    break;

  case 345: /* primary_expr: IDENTIFIER  */
#line 1993 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6389 "build/parser.cpp"
    break;

  case 346: /* primary_expr: KW_UNS  */
#line 1997 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 6395 "build/parser.cpp"
    break;

  case 347: /* primary_expr: KW_FLOAT_TYPE  */
#line 1998 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 6401 "build/parser.cpp"
    break;

  case 348: /* primary_expr: KW_GRAPH  */
#line 1999 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 6407 "build/parser.cpp"
    break;

  case 349: /* primary_expr: KW_ASCEND  */
#line 2000 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 6413 "build/parser.cpp"
    break;

  case 350: /* primary_expr: KW_DESCEND  */
#line 2001 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 6419 "build/parser.cpp"
    break;

  case 351: /* primary_expr: KW_RTNPARM  */
#line 2002 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 6425 "build/parser.cpp"
    break;

  case 352: /* primary_expr: KW_OPDESC  */
#line 2003 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 6431 "build/parser.cpp"
    break;

  case 353: /* primary_expr: KW_NULLIND  */
#line 2004 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 6437 "build/parser.cpp"
    break;

  case 354: /* primary_expr: KW_DATFMT  */
#line 2005 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 6443 "build/parser.cpp"
    break;

  case 355: /* primary_expr: KW_OVERLAY  */
#line 2006 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 6449 "build/parser.cpp"
    break;

  case 356: /* primary_expr: KW_POS  */
#line 2007 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 6455 "build/parser.cpp"
    break;

  case 357: /* primary_expr: KW_PREFIX  */
#line 2008 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 6461 "build/parser.cpp"
    break;

  case 358: /* primary_expr: KW_TIMFMT  */
#line 2009 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 6467 "build/parser.cpp"
    break;

  case 359: /* primary_expr: KW_EXTNAME  */
#line 2010 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 6473 "build/parser.cpp"
    break;

  case 360: /* primary_expr: INTEGER_LITERAL  */
#line 2011 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6481 "build/parser.cpp"
    break;

  case 361: /* primary_expr: FLOAT_LITERAL  */
#line 2014 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6489 "build/parser.cpp"
    break;

  case 362: /* primary_expr: STRING_LITERAL  */
#line 2017 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6498 "build/parser.cpp"
    break;

  case 363: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 2021 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6507 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 2025 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6515 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 2028 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6523 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 2031 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6531 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 2034 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6539 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 2037 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6547 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 2040 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6555 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 2043 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6563 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 2046 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6571 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 2049 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6579 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 2052 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6587 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 2055 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6595 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 2058 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6603 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 2061 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6612 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 2065 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6620 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 2068 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6628 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 2071 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6636 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 2074 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6644 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 2077 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6652 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 2080 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6660 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 2083 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6668 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 2086 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6676 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 2089 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6687 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 2095 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6698 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 2101 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6709 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 2107 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6720 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 2113 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6731 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 2119 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6742 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 2125 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6750 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 2128 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6758 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 2131 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6766 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 2134 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6774 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 2137 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6783 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 2141 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6792 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 2145 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6800 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 2148 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6808 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 2151 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6816 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 2154 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6824 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 2157 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6832 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 2160 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6840 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 2163 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6849 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 2167 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6857 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 2170 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6866 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 2174 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6874 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 2177 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6883 "build/parser.cpp"
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
#line 6895 "build/parser.cpp"
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
#line 6907 "build/parser.cpp"
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
#line 6919 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2202 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6929 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2207 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6939 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2212 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6949 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2217 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6958 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2221 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6967 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2225 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6975 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2228 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6983 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2231 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6991 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2234 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6999 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2237 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 7007 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2240 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 7015 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2243 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 7023 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2246 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 7031 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2249 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 7039 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2252 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 7047 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2255 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 7055 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2258 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 7063 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2261 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 7071 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2264 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 7079 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2267 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 7087 "build/parser.cpp"
    break;

  case 431: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2270 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 7095 "build/parser.cpp"
    break;

  case 432: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2273 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 7103 "build/parser.cpp"
    break;

  case 433: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2276 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 7111 "build/parser.cpp"
    break;

  case 434: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2279 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 7119 "build/parser.cpp"
    break;

  case 435: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2282 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7127 "build/parser.cpp"
    break;

  case 436: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2285 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7135 "build/parser.cpp"
    break;

  case 437: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2288 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 7143 "build/parser.cpp"
    break;

  case 438: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2291 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 7151 "build/parser.cpp"
    break;

  case 439: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2294 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 7159 "build/parser.cpp"
    break;

  case 440: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2297 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 7167 "build/parser.cpp"
    break;

  case 441: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2300 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7175 "build/parser.cpp"
    break;

  case 442: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2303 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7183 "build/parser.cpp"
    break;

  case 443: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2306 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 7193 "build/parser.cpp"
    break;

  case 444: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2311 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 7203 "build/parser.cpp"
    break;

  case 445: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2316 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 7213 "build/parser.cpp"
    break;

  case 446: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2321 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 7223 "build/parser.cpp"
    break;

  case 447: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2326 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 7234 "build/parser.cpp"
    break;

  case 448: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2332 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7243 "build/parser.cpp"
    break;

  case 449: /* primary_expr: BIF_PROC  */
#line 2336 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7252 "build/parser.cpp"
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
#line 7264 "build/parser.cpp"
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
#line 7276 "build/parser.cpp"
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
#line 7288 "build/parser.cpp"
    break;

  case 453: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2361 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 7299 "build/parser.cpp"
    break;

  case 454: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2367 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 7310 "build/parser.cpp"
    break;

  case 455: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2373 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 7321 "build/parser.cpp"
    break;

  case 456: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2379 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 7329 "build/parser.cpp"
    break;

  case 457: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2382 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 7337 "build/parser.cpp"
    break;

  case 458: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2385 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 7345 "build/parser.cpp"
    break;

  case 459: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2388 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 7353 "build/parser.cpp"
    break;

  case 460: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2391 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 7361 "build/parser.cpp"
    break;

  case 461: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2394 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 7369 "build/parser.cpp"
    break;

  case 462: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2397 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 7377 "build/parser.cpp"
    break;

  case 463: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2400 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 7388 "build/parser.cpp"
    break;

  case 464: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2406 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 7396 "build/parser.cpp"
    break;

  case 465: /* primary_expr: INDICATOR  */
#line 2409 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 7404 "build/parser.cpp"
    break;

  case 466: /* primary_expr: KW_ON  */
#line 2412 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 7412 "build/parser.cpp"
    break;

  case 467: /* primary_expr: KW_OFF  */
#line 2415 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 7420 "build/parser.cpp"
    break;

  case 468: /* primary_expr: KW_NULL  */
#line 2418 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7428 "build/parser.cpp"
    break;

  case 469: /* primary_expr: KW_OMIT  */
#line 2421 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7436 "build/parser.cpp"
    break;

  case 470: /* primary_expr: KW_BLANKS  */
#line 2424 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 7444 "build/parser.cpp"
    break;

  case 471: /* primary_expr: KW_ZEROS  */
#line 2427 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 7452 "build/parser.cpp"
    break;

  case 472: /* primary_expr: KW_HIVAL  */
#line 2430 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 7460 "build/parser.cpp"
    break;

  case 473: /* primary_expr: KW_LOVAL  */
#line 2433 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 7468 "build/parser.cpp"
    break;

  case 474: /* primary_expr: LPAREN expression RPAREN  */
#line 2436 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 7476 "build/parser.cpp"
    break;

  case 475: /* call_args_opt: %empty  */
#line 2443 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 7482 "build/parser.cpp"
    break;

  case 476: /* call_args_opt: call_arg_list  */
#line 2444 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7488 "build/parser.cpp"
    break;

  case 477: /* call_arg_list: expression  */
#line 2448 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7497 "build/parser.cpp"
    break;

  case 478: /* call_arg_list: call_arg_list COLON expression  */
#line 2452 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7506 "build/parser.cpp"
    break;

  case 479: /* arg_list: expression  */
#line 2460 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7515 "build/parser.cpp"
    break;

  case 480: /* arg_list: arg_list COLON expression  */
#line 2464 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7524 "build/parser.cpp"
    break;


#line 7528 "build/parser.cpp"

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

#line 2470 "src/parser.y"


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
