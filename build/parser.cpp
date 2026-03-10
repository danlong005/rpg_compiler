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
  YYSYMBOL_KW_STATIC = 40,                 /* KW_STATIC  */
  YYSYMBOL_KW_TEMPLATE = 41,               /* KW_TEMPLATE  */
  YYSYMBOL_KW_BASED = 42,                  /* KW_BASED  */
  YYSYMBOL_KW_OPTIONS = 43,                /* KW_OPTIONS  */
  YYSYMBOL_KW_NOPASS = 44,                 /* KW_NOPASS  */
  YYSYMBOL_KW_OMIT = 45,                   /* KW_OMIT  */
  YYSYMBOL_KW_EXPORT = 46,                 /* KW_EXPORT  */
  YYSYMBOL_KW_IMPORT = 47,                 /* KW_IMPORT  */
  YYSYMBOL_KW_EXTPGM = 48,                 /* KW_EXTPGM  */
  YYSYMBOL_KW_EXTPROC = 49,                /* KW_EXTPROC  */
  YYSYMBOL_KW_CTLOPT = 50,                 /* KW_CTLOPT  */
  YYSYMBOL_KW_RETURN = 51,                 /* KW_RETURN  */
  YYSYMBOL_KW_INLR = 52,                   /* KW_INLR  */
  YYSYMBOL_KW_ON = 53,                     /* KW_ON  */
  YYSYMBOL_KW_BLANKS = 54,                 /* KW_BLANKS  */
  YYSYMBOL_KW_ZEROS = 55,                  /* KW_ZEROS  */
  YYSYMBOL_KW_HIVAL = 56,                  /* KW_HIVAL  */
  YYSYMBOL_KW_LOVAL = 57,                  /* KW_LOVAL  */
  YYSYMBOL_KW_IF = 58,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 59,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 60,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 61,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 62,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 63,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 64,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 65,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 66,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 67,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 68,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 69,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 70,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 71,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 72,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 73,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 74,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 75,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 76,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 77,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 78,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 79,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 80,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 81,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 82,                    /* KW_OFF  */
  YYSYMBOL_KW_RESET = 83,                  /* KW_RESET  */
  YYSYMBOL_KW_CLEAR = 84,                  /* KW_CLEAR  */
  YYSYMBOL_KW_SORTA = 85,                  /* KW_SORTA  */
  YYSYMBOL_INDICATOR = 86,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 87,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 88,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 89,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 90,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 91,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 92,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 93,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 94,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 95,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 96,                  /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 97,                 /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 98,                 /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 99,              /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 100,                   /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 101,                /* KW_LIKEDS  */
  YYSYMBOL_KW_LIKE = 102,                  /* KW_LIKE  */
  YYSYMBOL_KW_DCL_SUBF = 103,              /* KW_DCL_SUBF  */
  YYSYMBOL_KW_DCL_PARM = 104,              /* KW_DCL_PARM  */
  YYSYMBOL_DOT = 105,                      /* DOT  */
  YYSYMBOL_BIF_CHAR = 106,                 /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 107,                 /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 108,                /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 109,                /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 110,                  /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 111,                /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 112,                 /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 113,              /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 114,                /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 115,                  /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 116,                  /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 117,                 /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 118,                /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 119,                  /* BIF_EOF  */
  YYSYMBOL_BIF_ABS = 120,                  /* BIF_ABS  */
  YYSYMBOL_BIF_DIV = 121,                  /* BIF_DIV  */
  YYSYMBOL_BIF_REM = 122,                  /* BIF_REM  */
  YYSYMBOL_BIF_SIZE = 123,                 /* BIF_SIZE  */
  YYSYMBOL_BIF_ADDR = 124,                 /* BIF_ADDR  */
  YYSYMBOL_BIF_PARMS = 125,                /* BIF_PARMS  */
  YYSYMBOL_BIF_STATUS = 126,               /* BIF_STATUS  */
  YYSYMBOL_BIF_ERROR = 127,                /* BIF_ERROR  */
  YYSYMBOL_BIF_MAX = 128,                  /* BIF_MAX  */
  YYSYMBOL_BIF_MIN = 129,                  /* BIF_MIN  */
  YYSYMBOL_BIF_LOOKUP = 130,               /* BIF_LOOKUP  */
  YYSYMBOL_BIF_DATE = 131,                 /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 132,                 /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 133,            /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 134,                 /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 135,                 /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 136,               /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 137,                /* BIF_YEARS  */
  YYSYMBOL_BIF_EDITC = 138,                /* BIF_EDITC  */
  YYSYMBOL_BIF_EDITW = 139,                /* BIF_EDITW  */
  YYSYMBOL_BIF_REPLACE = 140,              /* BIF_REPLACE  */
  YYSYMBOL_BIF_CHECK = 141,                /* BIF_CHECK  */
  YYSYMBOL_BIF_CHECKR = 142,               /* BIF_CHECKR  */
  YYSYMBOL_BIF_LOWER = 143,                /* BIF_LOWER  */
  YYSYMBOL_BIF_UPPER = 144,                /* BIF_UPPER  */
  YYSYMBOL_BIF_SUBDT = 145,                /* BIF_SUBDT  */
  YYSYMBOL_BIF_FLOAT = 146,                /* BIF_FLOAT  */
  YYSYMBOL_BIF_SQRT = 147,                 /* BIF_SQRT  */
  YYSYMBOL_BIF_ALLOC = 148,                /* BIF_ALLOC  */
  YYSYMBOL_BIF_REALLOC = 149,              /* BIF_REALLOC  */
  YYSYMBOL_BIF_XFOOT = 150,                /* BIF_XFOOT  */
  YYSYMBOL_BIF_SUBARR = 151,               /* BIF_SUBARR  */
  YYSYMBOL_BIF_SPLIT = 152,                /* BIF_SPLIT  */
  YYSYMBOL_BIF_UNS = 153,                  /* BIF_UNS  */
  YYSYMBOL_BIF_INTH = 154,                 /* BIF_INTH  */
  YYSYMBOL_BIF_DECH = 155,                 /* BIF_DECH  */
  YYSYMBOL_BIF_DECPOS = 156,               /* BIF_DECPOS  */
  YYSYMBOL_BIF_CONCAT = 157,               /* BIF_CONCAT  */
  YYSYMBOL_BIF_CONCATARR = 158,            /* BIF_CONCATARR  */
  YYSYMBOL_BIF_LEFT = 159,                 /* BIF_LEFT  */
  YYSYMBOL_BIF_RIGHT = 160,                /* BIF_RIGHT  */
  YYSYMBOL_BIF_STR = 161,                  /* BIF_STR  */
  YYSYMBOL_BIF_MAXARR = 162,               /* BIF_MAXARR  */
  YYSYMBOL_BIF_MINARR = 163,               /* BIF_MINARR  */
  YYSYMBOL_BIF_LIST = 164,                 /* BIF_LIST  */
  YYSYMBOL_BIF_RANGE = 165,                /* BIF_RANGE  */
  YYSYMBOL_BIF_LOOKUPLT = 166,             /* BIF_LOOKUPLT  */
  YYSYMBOL_BIF_LOOKUPGE = 167,             /* BIF_LOOKUPGE  */
  YYSYMBOL_BIF_LOOKUPLE = 168,             /* BIF_LOOKUPLE  */
  YYSYMBOL_BIF_LOOKUPGT = 169,             /* BIF_LOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUP = 170,              /* BIF_TLOOKUP  */
  YYSYMBOL_BIF_TLOOKUPLT = 171,            /* BIF_TLOOKUPLT  */
  YYSYMBOL_BIF_TLOOKUPGT = 172,            /* BIF_TLOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUPLE = 173,            /* BIF_TLOOKUPLE  */
  YYSYMBOL_BIF_TLOOKUPGE = 174,            /* BIF_TLOOKUPGE  */
  YYSYMBOL_BIF_HOURS = 175,                /* BIF_HOURS  */
  YYSYMBOL_BIF_MINUTES = 176,              /* BIF_MINUTES  */
  YYSYMBOL_BIF_SECONDS = 177,              /* BIF_SECONDS  */
  YYSYMBOL_BIF_MSECONDS = 178,             /* BIF_MSECONDS  */
  YYSYMBOL_BIF_PADDR = 179,                /* BIF_PADDR  */
  YYSYMBOL_BIF_PROC = 180,                 /* BIF_PROC  */
  YYSYMBOL_BIF_PASSED = 181,               /* BIF_PASSED  */
  YYSYMBOL_BIF_OMITTED = 182,              /* BIF_OMITTED  */
  YYSYMBOL_BIF_BITAND = 183,               /* BIF_BITAND  */
  YYSYMBOL_BIF_BITNOT = 184,               /* BIF_BITNOT  */
  YYSYMBOL_BIF_BITOR = 185,                /* BIF_BITOR  */
  YYSYMBOL_BIF_BITXOR = 186,               /* BIF_BITXOR  */
  YYSYMBOL_BIF_SCANR = 187,                /* BIF_SCANR  */
  YYSYMBOL_BIF_EDITFLT = 188,              /* BIF_EDITFLT  */
  YYSYMBOL_BIF_UNSH = 189,                 /* BIF_UNSH  */
  YYSYMBOL_BIF_PARMNUM = 190,              /* BIF_PARMNUM  */
  YYSYMBOL_KW_ALL = 191,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 192,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 193,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 194,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 195,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 196,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 197,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 198,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 199,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 200,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 201,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 202,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 203,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 204,               /* KW_EXTNAME  */
  YYSYMBOL_KW_RTNPARM = 205,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 206,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 207,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 208,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 209,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 210,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 211,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 212,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 213,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 214,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 215,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 216,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 217,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 218,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 219,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 220,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 221,                    /* KW_IN  */
  YYSYMBOL_IDENTIFIER = 222,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 223,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 224,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 225,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 226,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 227,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 228,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 229,                   /* RPAREN  */
  YYSYMBOL_COLON = 230,                    /* COLON  */
  YYSYMBOL_PLUS = 231,                     /* PLUS  */
  YYSYMBOL_MINUS = 232,                    /* MINUS  */
  YYSYMBOL_STAR = 233,                     /* STAR  */
  YYSYMBOL_SLASH = 234,                    /* SLASH  */
  YYSYMBOL_NE = 235,                       /* NE  */
  YYSYMBOL_LE = 236,                       /* LE  */
  YYSYMBOL_GE = 237,                       /* GE  */
  YYSYMBOL_LT = 238,                       /* LT  */
  YYSYMBOL_GT = 239,                       /* GT  */
  YYSYMBOL_YYACCEPT = 240,                 /* $accept  */
  YYSYMBOL_program = 241,                  /* program  */
  YYSYMBOL_statements_opt = 242,           /* statements_opt  */
  YYSYMBOL_statement_list = 243,           /* statement_list  */
  YYSYMBOL_statement = 244,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 245,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 246,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 247,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 248,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 249,              /* eval_target  */
  YYSYMBOL_eval_stmt = 250,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 251,           /* eval_corr_stmt  */
  YYSYMBOL_evalr_stmt = 252,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 253,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 254,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 255,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 256,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 257,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 258,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 259,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 260,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 261,              /* proc_export  */
  YYSYMBOL_pi_return_type = 262,           /* pi_return_type  */
  YYSYMBOL_pi_params = 263,                /* pi_params  */
  YYSYMBOL_pi_param = 264,                 /* pi_param  */
  YYSYMBOL_pr_params = 265,                /* pr_params  */
  YYSYMBOL_pr_param = 266,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 267,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 268,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 269,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 270,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 271,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 272,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 273,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 274,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 275,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 276,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 277,           /* enum_constants  */
  YYSYMBOL_enum_constant = 278,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 279,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 280,                /* ds_fields  */
  YYSYMBOL_ds_field = 281,                 /* ds_field  */
  YYSYMBOL_if_stmt = 282,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 283,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 284,            /* elseif_clause  */
  YYSYMBOL_else_clause = 285,              /* else_clause  */
  YYSYMBOL_dow_stmt = 286,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 287,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 288,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 289,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 290,              /* select_stmt  */
  YYSYMBOL_when_clauses = 291,             /* when_clauses  */
  YYSYMBOL_when_clause = 292,              /* when_clause  */
  YYSYMBOL_other_clause = 293,             /* other_clause  */
  YYSYMBOL_iter_stmt = 294,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 295,               /* leave_stmt  */
  YYSYMBOL_expression = 296,               /* expression  */
  YYSYMBOL_or_expr = 297,                  /* or_expr  */
  YYSYMBOL_and_expr = 298,                 /* and_expr  */
  YYSYMBOL_not_expr = 299,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 300,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 301,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 302,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 303,               /* power_expr  */
  YYSYMBOL_unary_expr = 304,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 305,             /* postfix_expr  */
  YYSYMBOL_ident = 306,                    /* ident  */
  YYSYMBOL_primary_expr = 307,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 308,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 309,            /* call_arg_list  */
  YYSYMBOL_arg_list = 310                  /* arg_list  */
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
#define YYLAST   4893

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  445
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1451

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   494


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
     235,   236,   237,   238,   239
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   197,   202,   204,   209,   218,   221,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   268,   272,   276,   280,   288,   293,   298,
     303,   308,   313,   318,   323,   328,   333,   338,   343,   349,
     355,   361,   365,   369,   373,   377,   381,   385,   389,   393,
     397,   401,   407,   413,   419,   425,   432,   437,   443,   448,
     453,   458,   463,   468,   473,   478,   483,   488,   493,   498,
     506,   507,   508,   509,   510,   515,   522,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   543,   549,   553,   559,   565,   571,   580,   588,
     597,   603,   609,   615,   621,   624,   631,   642,   659,   679,
     694,   718,   743,   770,   800,   801,   806,   807,   808,   809,
     810,   815,   818,   826,   830,   834,   838,   842,   846,   850,
     854,   859,   863,   867,   871,   875,   879,   883,   887,   891,
     897,   902,   907,   912,   918,   923,   928,   933,   939,   944,
     949,   958,   961,   969,   973,   977,   981,   985,   989,   993,
     997,  1002,  1006,  1010,  1014,  1018,  1022,  1026,  1030,  1034,
    1040,  1045,  1050,  1055,  1061,  1066,  1071,  1076,  1082,  1087,
    1092,  1102,  1113,  1123,  1131,  1139,  1146,  1154,  1162,  1173,
    1183,  1191,  1202,  1205,  1213,  1221,  1236,  1245,  1254,  1264,
    1274,  1285,  1296,  1307,  1318,  1326,  1335,  1345,  1356,  1367,
    1379,  1382,  1390,  1394,  1398,  1402,  1407,  1411,  1415,  1419,
    1424,  1430,  1436,  1443,  1450,  1457,  1463,  1475,  1498,  1499,
    1507,  1516,  1517,  1523,  1532,  1541,  1551,  1561,  1571,  1584,
    1594,  1613,  1617,  1624,  1633,  1634,  1640,  1644,  1650,  1654,
    1655,  1663,  1664,  1672,  1673,  1679,  1680,  1685,  1690,  1695,
    1700,  1705,  1710,  1718,  1719,  1724,  1732,  1733,  1738,  1746,
    1747,  1755,  1756,  1764,  1765,  1772,  1773,  1774,  1775,  1776,
    1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,
    1787,  1791,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1812,  1815,  1819,
    1823,  1826,  1829,  1832,  1835,  1838,  1841,  1844,  1847,  1850,
    1853,  1856,  1859,  1863,  1866,  1869,  1872,  1875,  1878,  1881,
    1884,  1887,  1893,  1899,  1905,  1911,  1917,  1923,  1926,  1929,
    1932,  1935,  1939,  1943,  1946,  1949,  1952,  1955,  1958,  1961,
    1965,  1968,  1972,  1975,  1979,  1986,  1993,  2000,  2005,  2010,
    2015,  2019,  2023,  2026,  2029,  2032,  2035,  2038,  2041,  2044,
    2047,  2050,  2053,  2056,  2059,  2062,  2065,  2068,  2071,  2074,
    2077,  2080,  2083,  2086,  2089,  2092,  2095,  2098,  2101,  2104,
    2109,  2114,  2119,  2124,  2130,  2134,  2138,  2145,  2152,  2159,
    2165,  2171,  2177,  2180,  2183,  2186,  2189,  2192,  2195,  2198,
    2204,  2207,  2210,  2213,  2216,  2219,  2222,  2225,  2228,  2231,
    2238,  2239,  2243,  2247,  2255,  2259
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
  "KW_DEALLOC", "KW_TEST", "KW_STATIC", "KW_TEMPLATE", "KW_BASED",
  "KW_OPTIONS", "KW_NOPASS", "KW_OMIT", "KW_EXPORT", "KW_IMPORT",
  "KW_EXTPGM", "KW_EXTPROC", "KW_CTLOPT", "KW_RETURN", "KW_INLR", "KW_ON",
  "KW_BLANKS", "KW_ZEROS", "KW_HIVAL", "KW_LOVAL", "KW_IF", "KW_ELSEIF",
  "KW_ELSE", "KW_ENDIF", "KW_DOW", "KW_DOU", "KW_ENDDO", "KW_FOR",
  "KW_ENDFOR", "KW_TO", "KW_DOWNTO", "KW_BY", "KW_SELECT", "KW_WHEN",
  "KW_OTHER", "KW_ENDSL", "KW_ITER", "KW_LEAVE", "KW_MONITOR",
  "KW_ON_ERROR", "KW_ENDMON", "KW_BEGSR", "KW_ENDSR", "KW_EXSR", "KW_OFF",
  "KW_RESET", "KW_CLEAR", "KW_SORTA", "INDICATOR", "KW_AND", "KW_OR",
  "KW_NOT", "KW_DCL_PROC", "KW_END_PROC", "KW_DCL_PI", "KW_END_PI",
  "KW_DCL_PR", "KW_END_PR", "KW_VALUE", "KW_DCL_DS", "KW_END_DS",
  "KW_QUALIFIED", "KW_DIM", "KW_LIKEDS", "KW_LIKE", "KW_DCL_SUBF",
  "KW_DCL_PARM", "DOT", "BIF_CHAR", "BIF_TRIM", "BIF_TRIML", "BIF_TRIMR",
  "BIF_LEN", "BIF_SUBST", "BIF_SCAN", "BIF_SCANRPL", "BIF_XLATE",
  "BIF_DEC", "BIF_INT", "BIF_ELEM", "BIF_FOUND", "BIF_EOF", "BIF_ABS",
  "BIF_DIV", "BIF_REM", "BIF_SIZE", "BIF_ADDR", "BIF_PARMS", "BIF_STATUS",
  "BIF_ERROR", "BIF_MAX", "BIF_MIN", "BIF_LOOKUP", "BIF_DATE", "BIF_TIME",
  "BIF_TIMESTAMP", "BIF_DIFF", "BIF_DAYS", "BIF_MONTHS", "BIF_YEARS",
  "BIF_EDITC", "BIF_EDITW", "BIF_REPLACE", "BIF_CHECK", "BIF_CHECKR",
  "BIF_LOWER", "BIF_UPPER", "BIF_SUBDT", "BIF_FLOAT", "BIF_SQRT",
  "BIF_ALLOC", "BIF_REALLOC", "BIF_XFOOT", "BIF_SUBARR", "BIF_SPLIT",
  "BIF_UNS", "BIF_INTH", "BIF_DECH", "BIF_DECPOS", "BIF_CONCAT",
  "BIF_CONCATARR", "BIF_LEFT", "BIF_RIGHT", "BIF_STR", "BIF_MAXARR",
  "BIF_MINARR", "BIF_LIST", "BIF_RANGE", "BIF_LOOKUPLT", "BIF_LOOKUPGE",
  "BIF_LOOKUPLE", "BIF_LOOKUPGT", "BIF_TLOOKUP", "BIF_TLOOKUPLT",
  "BIF_TLOOKUPGT", "BIF_TLOOKUPLE", "BIF_TLOOKUPGE", "BIF_HOURS",
  "BIF_MINUTES", "BIF_SECONDS", "BIF_MSECONDS", "BIF_PADDR", "BIF_PROC",
  "BIF_PASSED", "BIF_OMITTED", "BIF_BITAND", "BIF_BITNOT", "BIF_BITOR",
  "BIF_BITXOR", "BIF_SCANR", "BIF_EDITFLT", "BIF_UNSH", "BIF_PARMNUM",
  "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE", "KW_BINDEC", "KW_UCS2", "KW_GRAPH",
  "KW_OBJECT", "KW_JAVA", "KW_OVERLAY", "KW_POS", "KW_PREFIX", "KW_DATFMT",
  "KW_TIMFMT", "KW_EXTNAME", "KW_RTNPARM", "KW_OPDESC", "KW_ASCEND",
  "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE", "KW_STRING_OPT", "KW_TRIM_OPT",
  "KW_DCL_ENUM", "KW_END_ENUM", "KW_BOOLEAN", "EXEC_SQL_TEXT", "POWER",
  "KW_DIM_VAR", "KW_DIM_AUTO", "KW_FOR_EACH", "KW_IN", "IDENTIFIER",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "SEMICOLON",
  "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS", "STAR", "SLASH",
  "NE", "LE", "GE", "LT", "GT", "$accept", "program", "statements_opt",
  "statement_list", "statement", "dcl_f_stmt", "dcl_s_stmt",
  "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "evalr_stmt", "callp_stmt", "leavesr_stmt",
  "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt", "dcl_pr_stmt",
  "dcl_proc_stmt", "proc_export", "pi_return_type", "pi_params",
  "pi_param", "pr_params", "pr_param", "monitor_stmt", "begsr_stmt",
  "exsr_stmt", "sorta_stmt", "reset_stmt", "clear_stmt", "dealloc_stmt",
  "test_stmt", "exec_sql_stmt", "dcl_enum_stmt", "enum_constants",
  "enum_constant", "dcl_ds_stmt", "ds_fields", "ds_field", "if_stmt",
  "elseif_clauses", "elseif_clause", "else_clause", "dow_stmt", "dou_stmt",
  "for_stmt", "for_each_stmt", "select_stmt", "when_clauses",
  "when_clause", "other_clause", "iter_stmt", "leave_stmt", "expression",
  "or_expr", "and_expr", "not_expr", "comparison_expr", "additive_expr",
  "multiplicative_expr", "power_expr", "unary_expr", "postfix_expr",
  "ident", "primary_expr", "call_args_opt", "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-819)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-266)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      61,  -819,    85,    37,   479,  -819,  -120,   -98,   219,    36,
    4203,   -37,   219,   -37,  4203,    -1,   219,    23,  -819,  3447,
      39,  4203,  4203,  4203,   219,    55,    74,    80,   108,   115,
     219,   219,   219,   219,  -819,   138,   146,   148,   114,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   153,  -819,   219,   -51,  -819,  -819,  -819,
    -819,   117,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   197,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
     133,  4203,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  4392,   134,   217,   231,   240,   250,   277,   281,   288,
     308,   310,   312,   315,   324,   331,   333,   344,   378,   382,
     384,   463,   470,   472,   511,   512,   514,   516,   517,   518,
     525,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   541,   542,   544,   545,   552,   554,   555,   556,
     557,   559,   560,   561,   565,   566,   568,   570,   575,   576,
     577,   579,   580,   581,   583,   584,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   606,   607,   169,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,   608,  -819,  -819,  -819,  4203,  4581,   178,   101,
     553,  -819,   211,  -166,    63,  -819,   222,   461,  -819,   -31,
     443,   610,   611,   450,  -819,   482,   219,  -819,   613,   787,
     615,   616,   617,   618,   773,  -819,  -819,  -819,   620,   621,
     622,   623,   624,   805,   396,    -9,  4203,   -32,   631,   632,
    4203,  4203,    -8,   627,   629,   628,   630,   634,   635,   636,
    -140,  -100,   639,   640,   641,   642,   643,   644,   645,   646,
     648,   649,   652,   653,   211,  4203,  4203,  4203,  4203,  4203,
    4203,  4203,  4203,  4203,  4203,  4203,  4203,   651,   654,  4203,
    4203,  4203,  4203,  4203,   655,   656,   657,  4203,  4203,  4203,
    3636,  3825,  4014,  4203,  4203,  4203,  4203,  4203,  4203,  4203,
    4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,
    4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,
    4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,
    4203,  4203,  4203,  4203,  4203,  4203,  4203,  4203,   638,   658,
     219,   219,  4203,  4203,  4203,  4203,  4203,  4203,  4203,   219,
    -819,  4203,   659,   461,  -819,  4203,  4203,  4392,  4392,  4392,
    4392,  4392,  4392,  4392,  4392,  4392,  4392,  4392,  4392,   660,
    4203,  4203,   219,  4203,  -819,  -819,   661,  -819,   663,  -819,
    -819,  -819,  4203,  4203,   246,  -819,  1544,  -819,  -819,  -819,
    -819,  -819,  -819,   665,   664,   666,   667,   668,   669,    -5,
      -6,   670,   672,   673,  -819,  -819,   120,   677,   682,  4203,
    -819,   676,   681,   683,   680,   686,  -819,  -819,  -819,   703,
     704,   705,   707,   708,   706,  -819,   709,  -819,  -819,  -819,
    -819,   711,   712,   717,   718,   719,   720,   695,  -819,  -819,
     171,   184,   187,   213,   236,   247,   252,   269,   274,   278,
     294,   296,  -819,  -819,   303,   305,   316,   318,   321,  -819,
    -819,  -819,   327,   338,   341,  -819,   345,  -819,   348,  -819,
     350,   714,   710,   721,   722,   352,   355,   357,   359,   361,
     363,   365,   715,   368,   371,   373,   375,   379,   385,   387,
     389,   391,   393,   395,   397,   399,   401,   403,   405,   407,
     409,   412,   414,   416,   419,   421,   423,   425,   427,   429,
     431,   433,   723,   724,   725,   726,   727,  -819,   728,   730,
     435,   437,   439,   444,   460,   467,   473,   731,  -819,   735,
    -819,   553,  -819,   462,   462,   462,   462,   462,   462,   462,
      63,    63,  -819,  -819,  -819,  -819,   676,   739,   740,   741,
     219,  -819,   716,  1611,  1824,   637,   742,   743,  -819,   795,
     744,  -819,  1891,   777,   748,   749,   750,   751,   650,   752,
    -819,   753,   754,  -819,    29,   755,   757,    12,  -819,  4203,
     682,   301,  -118,  -819,   759,   776,   760,  4203,  -819,   713,
     747,   765,   768,   769,   770,   761,   779,   774,   775,   778,
     781,   782,   783,   772,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  4203,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   448,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,   780,   647,   788,
     790,  4203,  4203,  -819,  -819,   791,  -819,   792,     9,   784,
     794,   796,   804,   797,   799,    10,   122,   813,    32,   807,
     809,   815,   816,   480,   820,   826,   298,  -819,  -819,   -97,
    -819,  4203,   823,  -819,  -819,   828,  -819,  -819,   829,   261,
     292,   337,   798,   830,   831,   833,   832,   411,   411,   411,
     411,   411,   838,   834,   836,   837,   839,   840,   841,   842,
    -819,  4203,   846,  -819,   886,  -819,  -819,   -24,   -23,   957,
    2104,  -819,  2198,  -819,   442,   847,  -819,  -819,  -819,   844,
     849,   848,   850,   856,   271,  -819,   851,   858,   862,   484,
     853,   857,   869,   899,   -16,   867,   871,  -819,   449,   868,
     870,   872,   873,   878,   879,  -819,  2411,  -819,   864,   918,
     880,  -819,  -819,   887,   919,  -819,   889,   881,   890,  -819,
     891,   894,   975,   895,   896,  1065,   900,   903,   877,   893,
     907,   912,  -819,   913,   914,   916,   917,   920,   915,   464,
    -819,  -819,  -819,  -819,  -819,  -819,   921,  -819,   925,  4203,
    -819,  4203,  -819,   926,   928,  -819,   938,  -819,   929,  -819,
     481,   941,   943,   944,   946,   947,   876,   953,   952,   954,
     958,  -819,   955,   956,   960,   959,  -819,  -819,   961,   963,
     964,   965,   966,   972,   973,   974,   976,  -819,  -819,   962,
     969,   977,  4203,   967,   978,   979,  -819,  4203,   140,  -819,
     980,  4203,   981,   982,   162,  -819,   306,   411,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,   983,   971,   984,   985,   986,
     987,   988,  -819,  2478,  -819,   992,  2691,   993,  2758,  -819,
    -819,     4,  -819,    33,  -819,   994,   995,   996,   997,   989,
     998,  1003,  1004,  1006,   991,  1000,  -819,  -819,  1001,  1083,
    1084,  -819,  1008,   121,  1102,  1009,  1010,  1011,  1012,  1007,
    1013,  1016,  1018,  -819,  1014,  4203,  1017,  1020,  4203,  1032,
    1033,  1036,  1042,  1034,  4203,  1045,  1046,  4203,  1047,  1048,
    1050,  1174,  1052,  1053,  1015,  1056,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  1051,  -819,  1057,  -819,  1058,     5,  1059,
    1054,   275,  -819,  1060,    34,  1064,  1066,  1067,  1068,  1063,
    1075,  1076,  1077,  1079,  1062,  1080,   164,   165,  1085,  1086,
    1087,   166,  1081,  1088,  1091,  1089,  1090,  1092,  1093,    93,
    1094,   105,  1070,  -819,  1095,  1099,  1104,  1112,   -50,  1105,
    1071,  1110,  1116,  1115,  1120,  1125,  1123,  1130,  1133,   -47,
    1100,  4203,  1134,  -819,  -819,  2971,  -819,  3038,  -819,  1145,
    -819,   508,  1131,  1132,  1144,  1146,  1147,  -819,  1150,  1148,
    1149,  1151,  1143,   -40,   -33,   -19,  1156,  1158,  -819,  -819,
    1159,  1160,  -819,  -819,  -819,  1161,  1162,  -819,  -819,  1164,
    1165,  1166,  1172,  1169,  1170,  -819,  -819,  1171,  1175,  -819,
    1173,  1178,  -819,  -819,  1182,  1183,  1185,  -819,  -819,  1184,
    1189,  -819,  1193,  -819,  -819,  1194,  1195,  1197,  1201,  1203,
    -819,  4203,  1202,  1204,  1206,  1208,  -819,  1264,  1207,  1209,
    1210,  1211,  1177,  1200,  1213,  1217,  1219,  -819,   -48,   -46,
     -45,  1220,  1214,   -38,  -819,  1216,   -27,  -819,  1218,   -26,
    -819,  1221,  -819,   167,   173,  -819,  -819,   174,   175,   176,
    -819,  -819,   177,  -819,  -819,  -819,  1222,  1223,  1224,  1227,
    1229,  -107,  -819,  -819,  -819,  -819,  1228,  1232,  -819,  -819,
    1233,  1235,  -819,  -819,  1226,  1236,  1248,  -819,  -819,  1331,
    1249,  1250,  1230,  1255,  1256,  1258,  1253,  1254,  1259,  1257,
    1260,  1265,  -819,  1266,  -819,  1267,  -819,  1261,   671,  1268,
    -819,   674,  1269,  -819,   679,  1270,  -819,   -18,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,   496,  1280,   498,  1281,  1283,
    -819,  -819,  -819,  -819,  -819,  1282,  -819,  -819,  1286,  1287,
    -819,  -819,  1285,  1288,  1289,  1290,   -17,   -15,   -14,  1262,
    1293,  -819,  -819,  -819,   -44,  1291,  1296,  1163,  1292,  1297,
    1167,  1298,  1300,  1386,  1313,   -25,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  1316,  1271,  1317,  1320,  1272,  1326,
    1284,  -819,  -819,  -819,  3251,   -43,   -39,   -36,  1332,  1328,
     -12,  -819,  1329,   -11,  -819,  1330,    -4,  -819,  1325,  -819,
    1333,  -819,  1192,  1334,  1335,  1461,  1336,  1337,  1470,  1339,
    1338,  1471,  1340,  -819,  -819,  1341,  -819,  -819,  1342,  -819,
    1343,  3318,  1347,  1348,  -819,  1355,  -819,  1358,  -819,  1356,
     685,  1359,  -819,   687,  1360,  -819,   689,  1361,  -819,   -13,
    -819,  1357,  -819,  1364,  1362,  -819,  1366,  1365,  -819,  1367,
    1368,  1517,  1372,  1373,  1374,  1375,  -819,  -819,  -819,  -819,
     -35,  1378,  1376,  1519,  1380,  1382,  1525,  1383,  1393,  1559,
    1396,    -3,  -819,  1400,  -819,  1405,  -819,  1406,  -819,  1407,
    1408,  -819,  -819,  -819,  -819,  1409,  -819,  1591,  1413,  1411,
    1603,  1425,  1423,  1608,  1428,  1426,  1612,  1430,  -819,  -819,
    -819,  -819,  -819,  1433,  -819,  1427,  -819,  1434,  1435,  -819,
    1439,  1437,  -819,  1441,  1442,  1560,  -819,  1444,  -819,  1446,
    -819,  1451,  -819,  1452,  1450,  -819,  -819,  -819,  -819,  1454,
    -819
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,   100,
     101,   102,    98,    97,    99,   108,   109,   110,   105,   106,
     103,   104,   107,     0,   209,     0,    96,     5,     9,    10,
      11,     0,    12,    13,    35,    36,    37,    14,    15,    16,
      41,    26,    25,    29,    30,    31,    34,    32,    33,    38,
      39,    40,    28,    27,    17,    18,    19,    20,    21,    22,
      23,    24,    42,     0,   296,   297,   298,   308,   309,   310,
     305,   306,   307,   302,   303,   299,   300,   304,   301,   295,
       0,     0,   433,   434,   431,   435,   436,   437,   438,   432,
     430,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   415,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   312,   313,
     314,   321,   322,   323,   320,   324,   325,   317,   318,   315,
     316,   319,   311,   326,   327,   328,     0,     0,     0,   268,
     269,   271,   273,   275,   283,   286,   289,   291,   293,    96,
       0,     0,     0,     0,   121,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,   266,   267,     7,     0,     0,
       0,     0,     0,   134,   136,     0,     0,     0,     0,     0,
     440,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     419,   440,     0,   292,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,   207,     0,   124,     0,     7,
       7,     7,     0,     0,   264,   261,     0,     7,   203,   205,
     206,   204,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   444,     0,     0,     0,     0,
     112,   442,     0,   441,     0,     0,    43,    44,    45,     0,
       0,     0,     0,     0,     0,    63,     0,    64,    65,    61,
      66,     0,     0,     0,     0,     0,     0,     0,    62,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   381,     0,     0,     0,     0,     0,   342,
     361,   362,     0,     0,     0,   369,     0,   371,     0,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   414,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   442,     0,
     439,   270,   272,   276,   277,   280,   281,   278,   279,   282,
     284,   285,   287,   288,   290,   294,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,     0,   230,     0,     0,     0,     0,   115,     0,
       0,     0,     0,   212,     0,   113,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   365,   366,   367,   363,
     364,   359,   360,   343,   368,   370,   372,     0,   377,   378,
     379,   344,   345,   346,   347,   348,   349,   350,     0,   357,
     358,   382,   383,   384,   395,   389,   385,   386,   387,   388,
     390,   391,   392,   393,   394,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   329,   117,   118,   119,     0,   251,     0,
       0,     0,     0,     7,     7,     0,     7,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   445,     0,
     214,     0,     0,   213,     7,     0,   126,   443,     0,    90,
      90,    90,     0,     0,     0,     0,     0,    90,    90,    90,
      90,    90,     0,     0,     0,     0,     0,     0,     0,     0,
     208,     0,     0,   249,     0,   253,   254,     0,     0,     0,
       0,   260,     0,   202,   136,     0,   138,   139,   137,     0,
       0,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,   211,     0,   114,     0,     0,
       0,    91,    92,     0,    93,    94,     0,     0,     0,    93,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
     353,   352,   351,   354,   355,   356,     0,     7,     0,     0,
       7,     0,     7,     0,     0,   141,     0,   171,     0,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,     0,     0,     0,     0,   224,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,   215,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,    48,
       0,     0,     0,     0,     0,    49,    90,    90,    88,    89,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     7,     0,   247,     0,     0,     0,     0,   201,
     141,     0,   140,     0,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   230,     0,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,   374,   375,   376,
     416,   417,   418,     0,     7,     0,     7,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,     0,   255,     0,   257,     0,
       7,     0,     0,     0,     0,     0,     0,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   230,
       0,     0,   230,   230,   230,     0,     0,   229,   230,     0,
       0,     0,     0,     0,     0,   233,   234,     0,     0,   232,
       0,     0,    56,    83,     0,     0,     0,    68,    58,     0,
       0,    69,     0,    55,    82,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   175,     0,     0,   177,     0,     0,
     173,     0,   189,     0,     0,   219,   226,     0,     0,     0,
     218,   225,     0,   237,   238,   236,     0,     0,     0,     0,
       0,     0,    53,    60,    86,    87,     0,     0,    52,    59,
       0,     0,    84,    85,     0,     0,     0,   256,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,     0,   185,     0,   181,     0,     0,     0,
     176,     0,     0,   178,     0,     0,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,    73,    74,    71,    72,     0,    57,    70,     0,     0,
       7,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   186,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   221,   223,   228,
     220,   222,   227,   239,     0,     0,     0,     0,     0,     0,
       0,    54,     7,   131,     0,     0,     0,     0,     0,     0,
       0,   145,     0,     0,   147,     0,     0,   143,     0,   159,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   243,     0,   240,   245,     0,   241,
       0,     0,     0,     0,   153,     0,   155,     0,   151,     0,
       0,     0,   146,     0,     0,   148,     0,     0,   144,     0,
     188,     0,   195,     0,     0,   196,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,   132,   154,   156,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,   191,     0,   192,     0,   190,     0,
       0,   244,   246,   242,   133,     0,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   199,
     200,   198,   197,     0,   158,     0,   165,     0,     0,   166,
       0,     0,   164,     0,     0,     0,   193,     0,   161,     0,
     162,     0,   160,     0,     0,   169,   170,   168,   167,     0,
     163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -819,  -819,  1237,  -403,   732,  -819,  -819,  -628,  -819,   185,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -500,   289,  -819,  -818,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,   699,  -565,  -819,
    -602,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  1295,  -819,  -819,  -819,   -10,  -819,  1299,  1302,
    1547,    43,   343,  -223,  -819,  1455,     3,  -819,  1308,  -819,
    4515
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   416,   591,    58,    59,   837,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   423,   429,   951,  1022,   735,   805,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   612,   613,    83,
     607,   747,    84,   718,   783,   784,    85,    86,    87,    88,
      89,   414,   415,   589,    90,    91,   435,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   110,   238,   442,   443,
     436
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     228,   738,   445,  1162,   243,  1229,   582,   583,   584,   248,
    1165,   250,   251,   252,   592,   241,  1232,  1235,  1332,   245,
     424,   425,   426,   427,  1168,  1284,  1309,   253,  1312,  1315,
    1390,  1351,  1354,   259,   260,   261,   262,    -3,     6,  1357,
    1417,     7,     8,     9,   599,   869,   871,   753,  1221,    34,
    1223,  1225,  1320,  1343,   269,   393,  1163,  1345,   268,   953,
    1347,  1405,   454,  1166,     1,   394,   395,   437,    10,    11,
      12,    13,    14,    15,   269,    16,    17,  1169,  1285,  1310,
      38,  1313,  1316,  1391,   895,     5,   455,    18,    19,    20,
     430,   431,   432,  1249,   601,    21,   752,  1019,  1079,    22,
      23,   293,    24,   456,   611,   802,    92,    25,  1020,  1020,
     744,    26,    27,    28,   803,   745,    29,   823,    30,  1250,
      31,    32,    33,    34,    93,   611,   457,    35,  1023,  1088,
     810,    36,   841,   847,    37,   745,  1024,   803,   803,   853,
     854,   855,   856,   857,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,    38,    39,    40,  1125,  1126,    41,
    1138,  1139,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   572,   573,   574,  1127,   270,  1222,  1140,
    1224,  1226,  1321,  1344,   753,   239,  1164,  1346,  1230,   385,
    1348,  1406,   433,  1167,   438,   602,   240,   400,   242,  1233,
    1236,  1333,   870,   872,   272,   273,   274,  1170,  1286,  1311,
     896,  1314,  1317,  1392,  1352,  1355,   382,   434,   446,  1043,
     603,   600,  1358,  1418,   745,   244,  1021,  1021,   795,    39,
      40,   794,   804,    41,   746,   285,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   739,   740,   406,
      53,   246,   741,    54,   746,   804,   804,    55,   111,    56,
     441,   444,  1100,  1101,  1105,  1238,   249,   745,   745,   745,
     745,  1239,  1240,  1241,  1242,  1243,   745,   745,   745,   745,
     745,   254,   881,   882,   883,   884,  1082,  1083,  1084,  1085,
     829,   830,  1113,  1114,   874,   973,   396,   397,  1004,  1005,
     255,   831,   832,   833,  1117,  1118,   256,   834,   835,   819,
     820,   821,   822,   501,   502,   503,   504,   413,   587,  1115,
     789,   790,   838,   792,   512,   286,   287,   288,   289,   290,
     291,  1119,   831,   832,   257,  1001,  1002,   258,   839,   835,
     806,   807,   266,   746,   271,   808,   831,   832,   292,   608,
     609,   826,   839,   835,   542,   543,   544,   545,   991,   992,
     263,   836,   295,   993,  1036,  1037,   842,   843,   264,  1041,
     265,   558,   885,   548,   549,   267,  1086,   831,   832,   844,
     998,   999,   557,   845,   835,  1000,   746,   746,   746,   746,
     576,   577,   840,   579,   380,   746,   746,   746,   746,   746,
     634,   609,   585,   586,   384,   578,  1003,   424,   425,   426,
     427,    94,    95,   635,   609,    96,   636,   609,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   614,
     563,   564,   565,   566,   567,   568,   569,   846,   387,   398,
     108,   109,   637,   609,   428,   296,   388,   389,   390,   391,
     392,   831,   832,   424,   425,   426,   427,   839,   835,   297,
     899,   900,   901,   902,   943,   638,   609,   946,   298,   948,
     774,   775,   776,   777,   778,   779,   639,   609,   299,    -2,
       6,   640,   609,     7,     8,     9,   936,   937,   938,   939,
     940,   941,   955,   956,   957,   958,  1173,  1174,   641,   609,
    1177,  1178,  1179,   642,   609,   300,  1182,   643,   609,   301,
      10,    11,    12,    13,    14,    15,   302,    16,    17,  1148,
    1149,  1150,  1151,   644,   609,   645,   609,   750,   751,    18,
      19,    20,   646,   609,   647,   609,   303,    21,   304,  1013,
     305,    22,    23,   306,    24,   648,   609,   649,   609,    25,
     650,   609,   307,    26,    27,    28,   651,   609,    29,   308,
      30,   309,    31,    32,    33,    34,   399,   652,   609,    35,
     653,   609,   310,    36,   654,   609,    37,   655,   609,   656,
     609,   661,   609,   717,   662,   609,   663,   609,   664,   609,
     665,   609,   666,   609,   667,   609,    38,   669,   609,   748,
     670,   609,   671,   609,   672,   609,   311,   757,   673,   609,
     312,  1075,   313,  1077,   674,   609,   675,   609,   676,   609,
     677,   609,   678,   609,   679,   609,   680,   609,   681,   609,
     682,   609,   683,   609,   684,   609,   685,   609,   686,   609,
     386,   687,   609,   688,   609,   689,   609,   773,   690,   609,
     691,   609,   692,   609,   693,   609,   694,   609,   695,   609,
     696,   609,   697,   609,   705,   609,   706,   609,   707,   609,
     401,    39,    40,   708,   609,    41,   404,  1147,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   709,
     609,   314,    53,   394,   395,    54,   710,   609,   315,    55,
     316,    56,   711,   609,   721,   722,   781,   782,   405,   815,
     816,   787,   788,   889,   890,  1275,  1276,     6,  1278,  1279,
       7,     8,     9,  1281,  1282,  1294,  1295,  1297,  1298,  1381,
    1382,  1384,  1385,  1387,  1388,    57,    57,   570,   571,   317,
     318,   824,   319,  1209,   320,   321,   322,    10,    11,    12,
      13,    14,    15,   323,    16,    17,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    19,    20,   335,
     336,   866,   337,   338,    21,  -248,  -248,  -248,    22,    23,
     339,    24,   340,   341,   342,   343,    25,   344,   345,   346,
      26,    27,    28,   347,   348,    29,   349,    30,   350,    31,
      32,    33,    34,   351,   352,   353,    35,   354,   355,   356,
      36,   357,   358,    37,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,    38,   378,   379,   381,   402,   403,   407,
     408,   409,   410,   411,   413,   412,   417,   418,   419,   420,
     421,   422,   439,   447,   440,   448,   449,  1304,   450,   945,
     546,   947,   451,   452,   453,   458,   459,   460,   725,   728,
     461,   462,   463,   464,   465,   733,   466,   467,   468,   469,
     482,   755,   575,   483,   489,   490,   491,   547,   560,   581,
     580,   593,   594,   633,   595,   596,   597,   598,   604,  1341,
     605,   606,   986,   610,   611,   615,   618,   990,    39,    40,
     616,   995,    41,   617,   619,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   620,   621,   622,    53,
     623,   624,    54,   627,   625,   628,    55,   626,    56,   658,
     629,   630,   631,   632,   657,   668,   758,   868,   911,   914,
     659,   660,   698,   699,   700,   701,   702,   703,     6,   704,
     712,     7,     8,     9,   713,   714,   715,   716,   723,   724,
     726,   729,   730,   731,   732,  1054,   759,   742,  1057,   743,
     734,   736,   737,   764,  1063,   754,   756,  1066,    10,    11,
      12,    13,    14,    15,   760,    16,    17,   761,   894,   762,
     763,   765,   772,   766,   767,   920,   780,   768,    19,    20,
     769,   770,   771,   796,   785,    21,   786,   791,   793,    22,
      23,   848,    24,   797,   801,   798,   800,    25,  -263,  -263,
    -263,    26,    27,    28,   799,   809,    29,   811,    30,   812,
      31,    32,    33,    34,   813,   814,   817,    35,   818,   825,
     827,    36,     6,   849,    37,     7,     8,     9,   852,   828,
     850,  1142,   851,   858,   859,   860,   861,   876,   862,   863,
     864,   865,   867,   875,    38,   877,   879,   878,   880,   891,
     892,   886,    10,    11,    12,    13,    14,    15,   887,    16,
      17,   888,   893,   897,   898,   923,   903,   910,   904,   964,
     905,   906,    19,    20,   907,   908,   926,   916,   912,    21,
    -250,  -250,  -250,    22,    23,   913,    24,   915,   917,   918,
     919,    25,   927,   921,   922,    26,    27,    28,   924,   925,
      29,  1204,    30,   928,    31,    32,    33,    34,   929,   930,
     931,    35,   932,   933,   935,    36,   934,   942,    37,    39,
      40,   944,   949,    41,   950,   954,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   952,    38,   959,
      53,   960,   961,    54,   962,   963,   965,    55,   966,    56,
     967,   968,  1039,  1040,   969,   970,   971,   972,   983,   987,
     974,   975,   976,   977,   978,   979,   980,   981,   984,   982,
    1007,  1044,   989,   996,  1070,   985,   988,  1324,   994,  1006,
     997,  1327,  1029,  1008,  1009,  1010,  1011,  1012,  1014,  1016,
    1034,  1030,  1025,  1026,  1027,  1028,  1031,  1032,  1033,  1035,
    1038,  1042,  1045,  1046,  1047,  1048,  1049,  1361,     4,  1018,
    1053,  1073,  1050,    39,    40,  1051,  1055,    41,  1052,  1056,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,  1058,  1059,  1062,    53,     6,  1060,    54,     7,     8,
       9,    55,  1061,    56,  1064,  1065,  1081,  1067,  1068,  1069,
    1071,  1072,  1074,  1076,  1078,  1080,  1087,  1089,  1098,  1090,
    1091,  1092,  1093,  1120,  1129,    10,    11,    12,    13,    14,
      15,  1210,    16,    17,  1094,  1095,  1099,  1096,  1097,   749,
    1106,  1102,  1103,  1104,  1107,    19,    20,  1108,  1109,  1110,
    1116,  1111,    21,  1112,  1121,  1122,    22,    23,  1141,    24,
    1123,  1128,     6,  1130,    25,     7,     8,     9,    26,    27,
      28,  1124,  1131,    29,  1132,    30,  1133,    31,    32,    33,
      34,  1134,  1135,  1136,    35,  1211,  1137,  1143,    36,  1152,
    1153,    37,    10,    11,    12,    13,    14,    15,  1258,    16,
      17,  1146,  1154,  1161,  1155,  1156,  1157,  1158,  1159,  1171,
    1160,    38,    19,    20,  1172,  1175,  1176,  1180,  1181,    21,
    1183,  1184,  1185,    22,    23,  1186,    24,  1187,  1188,  1189,
    1216,    25,  1191,  1190,  1192,    26,    27,    28,  1193,  1194,
      29,  1195,    30,  1196,    31,    32,    33,    34,  1197,  1198,
    1199,    35,  1259,  1217,  1200,    36,  1201,  1202,    37,  1203,
    1330,  1205,  1207,  1206,  1208,  1212,  1218,  1213,  1214,  1215,
    1219,  1220,  1228,  1227,  1231,  1245,  1234,  1246,    38,  1247,
    1237,  1244,  1248,  1262,  1251,  1255,    39,    40,  1252,  1253,
      41,  1254,  1256,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,  1257,  1260,  1261,    53,  1263,  1264,
      54,  1265,  1266,  1267,    55,  1318,    56,  1269,  1268,  1270,
    1274,  1271,  1272,  1273,  1335,  1338,  1277,  1280,  1283,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1364,  1340,  1301,  1296,
    1299,  1300,  1302,  1303,  1305,  1367,  1370,  1306,  1307,  1319,
    1308,  1322,  1325,    39,    40,  1323,  1326,    41,  1328,  1329,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,  1331,  1334,  1336,    53,     6,  1337,    54,     7,     8,
       9,    55,  1339,    56,  1359,  1349,  1350,  1353,  1356,  1360,
    1362,  1400,  1365,  1409,  1363,  1368,  1366,  1369,  1371,  1412,
    1372,  1373,  1374,  1376,  1377,    10,    11,    12,    13,    14,
      15,  1378,    16,    17,  1379,  1380,  1393,  1383,  1386,  1389,
    1394,  1395,  1396,  1398,  1397,    19,    20,  1399,  1401,  1402,
    1403,  1404,    21,  1415,  1444,  1408,    22,    23,  1407,    24,
    1410,  1411,     6,  1413,    25,     7,     8,     9,    26,    27,
      28,   590,  1414,    29,  1416,    30,  1419,    31,    32,    33,
      34,  1420,  1421,  1422,    35,  1424,  1425,  1423,    36,  1426,
    1427,    37,    10,    11,    12,    13,    14,    15,  1428,    16,
      17,  1429,  1430,  1431,  1432,  1433,  1437,  1434,  1435,  1436,
    1438,    38,    19,    20,  1439,  1440,  1441,  1442,   294,    21,
    1445,  1443,  1446,    22,    23,   719,    24,  1447,  1448,  1449,
    1450,    25,   383,     0,   561,    26,    27,    28,   562,   559,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,     0,     0,     0,    36,     0,     0,    37,   588,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,    53,     0,     0,
      54,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     6,     0,    54,     7,     8,
       9,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,    23,   720,    24,
       0,     0,     6,     0,    25,     7,     8,     9,    26,    27,
      28,     0,     0,    29,     0,    30,     0,    31,    32,    33,
      34,     0,     0,     0,    35,     0,     0,     0,    36,     0,
       0,    37,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,     0,     0,     0,
       0,    25,     0,     0,     0,    26,    27,    28,     0,     0,
      29,   727,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,     0,     0,     0,    36,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,    53,     0,     0,
      54,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     6,     0,    54,     7,     8,
       9,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,    23,     0,    24,
       0,     0,     0,     0,    25,     0,     0,  -265,    26,    27,
      28,     0,     0,    29,     0,    30,     0,    31,    32,    33,
      34,     0,     0,     0,    35,     0,     0,     0,    36,     6,
       0,    37,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,     0,     0,     0,     0,    25,     0,
       0,     0,    26,    27,    28,     0,   873,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,    38,     0,    53,     0,     0,
      54,     0,     0,     0,    55,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     6,     0,    54,     7,     8,     9,    55,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,   909,     0,     6,
       0,    25,     7,     8,     9,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,     0,     0,     0,    36,     0,     0,    37,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,  -252,
      22,    23,     0,    24,     0,     0,     0,     0,    25,     0,
       0,     0,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     0,     0,    54,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     6,     0,    54,     7,     8,     9,    55,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,  1015,     0,     6,
       0,    25,     7,     8,     9,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,     0,     0,     0,    36,     0,     0,    37,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,  1017,     0,     0,     0,    25,     0,
       0,     0,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     0,     0,    54,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     6,     0,    54,     7,     8,     9,    55,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,  1144,     0,     6,
       0,    25,     7,     8,     9,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,     0,     0,     0,    36,     0,     0,    37,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,  1145,     0,     0,     0,    25,     0,
       0,     0,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     0,     0,    54,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     6,     0,    54,     7,     8,     9,    55,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,     0,     0,     6,
       0,    25,     7,     8,     9,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,  1342,     0,     0,    36,     0,     0,    37,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,     0,     0,     0,     0,    25,     0,
       0,     0,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,  1375,
       0,     0,    36,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     0,     0,    54,   112,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,   119,
       0,    53,     0,   120,    54,     0,   121,     0,    55,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,     0,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,   247,     0,   226,     0,     0,     0,   227,
       0,   113,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,   120,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,     0,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,   226,   495,     0,     0,   227,     0,
     113,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,     0,     0,
       0,   120,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
       0,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,   226,   497,     0,     0,   227,     0,   113,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
     120,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,     0,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,   226,   499,     0,     0,   227,     0,   113,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,     0,     0,     0,   120,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,     0,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,   226,     0,     0,     0,   227,     0,   113,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
     226,     0,     0,     0,   227,     0,   113,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,     0,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,   226,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,     0,     0,   484,   485,   486,   487,   488,     0,
       0,     0,   492,   493,   494,   496,   498,   500,     0,     0,
       0,     0,   505,   506,   507,   508,   509,   510,   511,     0,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556
};

static const yytype_int16 yycheck[] =
{
      10,   603,    10,    43,    14,    43,   409,   410,   411,    19,
      43,    21,    22,    23,   417,    12,    43,    43,    43,    16,
      11,    12,    13,    14,    43,    43,    43,    24,    43,    43,
      43,    43,    43,    30,    31,    32,    33,     0,     1,    43,
      43,     4,     5,     6,    49,    69,    69,   612,    96,    86,
      96,    96,    96,    96,   105,   221,    96,    96,    55,   877,
      96,    96,   202,    96,     3,   231,   232,    99,    31,    32,
      33,    34,    35,    36,   105,    38,    39,    96,    96,    96,
     117,    96,    96,    96,   100,     0,   226,    50,    51,    52,
      99,   100,   101,   200,   100,    58,   214,    93,    93,    62,
      63,   111,    65,   203,   222,    95,   226,    70,   104,   104,
      98,    74,    75,    76,   104,   103,    79,   214,    81,   226,
      83,    84,    85,    86,   222,   222,   226,    90,    95,    95,
      98,    94,   760,   761,    97,   103,   954,   104,   104,   767,
     768,   769,   770,   771,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   117,   192,   193,   207,   208,   196,
     207,   208,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   396,   397,   398,   226,   228,   226,   226,
     226,   226,   226,   226,   749,   222,   226,   226,   226,    88,
     226,   226,   201,   226,   226,   201,    11,   228,    13,   226,
     226,   226,   226,   226,     7,     8,     9,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,    98,
     226,   226,   226,   226,   103,   226,   222,   222,   728,   192,
     193,   222,   222,   196,   222,   102,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   218,   219,   246,
     213,   228,   223,   216,   222,   222,   222,   220,   222,   222,
     270,   271,    98,    98,    98,    98,   227,   103,   103,   103,
     103,    98,    98,    98,    98,    98,   103,   103,   103,   103,
     103,   226,    11,    12,    13,    14,    11,    12,    13,    14,
      29,    30,   199,   200,   794,   897,   233,   234,   926,   927,
     226,    40,    41,    42,   199,   200,   226,    46,    47,    11,
      12,    13,    14,   323,   324,   325,   326,    71,    72,   226,
     723,   724,    30,   726,   334,   192,   193,   194,   195,   196,
     197,   226,    40,    41,   226,    29,    30,   222,    46,    47,
     218,   219,   228,   222,   227,   223,    40,    41,   215,   229,
     230,   754,    46,    47,   364,   365,   366,   367,   218,   219,
     222,   100,   228,   223,   966,   967,    29,    30,   222,   971,
     222,   381,   101,   370,   371,   222,   101,    40,    41,    42,
     218,   219,   379,    46,    47,   223,   222,   222,   222,   222,
     400,   401,   100,   403,   225,   222,   222,   222,   222,   222,
     229,   230,   412,   413,   226,   402,   100,    11,    12,    13,
      14,   192,   193,   229,   230,   196,   229,   230,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   439,
     387,   388,   389,   390,   391,   392,   393,   100,   227,   217,
     221,   222,   229,   230,    48,   228,   235,   236,   237,   238,
     239,    40,    41,    11,    12,    13,    14,    46,    47,   228,
      11,    12,    13,    14,   867,   229,   230,   870,   228,   872,
      22,    23,    24,    25,    26,    27,   229,   230,   228,     0,
       1,   229,   230,     4,     5,     6,    22,    23,    24,    25,
      26,    27,    11,    12,    13,    14,  1098,  1099,   229,   230,
    1102,  1103,  1104,   229,   230,   228,  1108,   229,   230,   228,
      31,    32,    33,    34,    35,    36,   228,    38,    39,    11,
      12,    13,    14,   229,   230,   229,   230,   226,   227,    50,
      51,    52,   229,   230,   229,   230,   228,    58,   228,   942,
     228,    62,    63,   228,    65,   229,   230,   229,   230,    70,
     229,   230,   228,    74,    75,    76,   229,   230,    79,   228,
      81,   228,    83,    84,    85,    86,   105,   229,   230,    90,
     229,   230,   228,    94,   229,   230,    97,   229,   230,   229,
     230,   229,   230,   580,   229,   230,   229,   230,   229,   230,
     229,   230,   229,   230,   229,   230,   117,   229,   230,   609,
     229,   230,   229,   230,   229,   230,   228,   617,   229,   230,
     228,  1014,   228,  1016,   229,   230,   229,   230,   229,   230,
     229,   230,   229,   230,   229,   230,   229,   230,   229,   230,
     229,   230,   229,   230,   229,   230,   229,   230,   229,   230,
      87,   229,   230,   229,   230,   229,   230,   657,   229,   230,
     229,   230,   229,   230,   229,   230,   229,   230,   229,   230,
     229,   230,   229,   230,   229,   230,   229,   230,   229,   230,
     227,   192,   193,   229,   230,   196,   226,  1080,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   229,
     230,   228,   213,   231,   232,   216,   229,   230,   228,   220,
     228,   222,   229,   230,    67,    68,    59,    60,   226,   229,
     230,   721,   722,   229,   230,    44,    45,     1,    44,    45,
       4,     5,     6,    44,    45,   229,   230,   229,   230,    44,
      45,    44,    45,    44,    45,     3,     4,   394,   395,   228,
     228,   751,   228,  1146,   228,   228,   228,    31,    32,    33,
      34,    35,    36,   228,    38,    39,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,    51,    52,   228,
     228,   781,   228,   228,    58,    59,    60,    61,    62,    63,
     228,    65,   228,   228,   228,   228,    70,   228,   228,   228,
      74,    75,    76,   228,   228,    79,   228,    81,   228,    83,
      84,    85,    86,   228,   228,   228,    90,   228,   228,   228,
      94,   228,   228,    97,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   117,   228,   228,   228,   227,   227,   226,
      53,   226,   226,   226,    71,   227,   226,   226,   226,   226,
     226,    46,   221,   226,   222,   226,   228,  1260,   228,   869,
     222,   871,   228,   228,   228,   226,   226,   226,    73,    92,
     228,   228,   228,   228,   228,   225,   228,   228,   226,   226,
     229,   105,   222,   229,   229,   229,   229,   229,   229,   226,
     229,   226,   228,   198,   228,   228,   228,   228,   228,  1302,
     228,   228,   912,   226,   222,   229,   226,   917,   192,   193,
     229,   921,   196,   230,   228,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   223,   223,   223,   213,
     223,   223,   216,   222,   228,   223,   220,   228,   222,   229,
     223,   223,   223,   223,   230,   230,   233,    61,    30,    30,
     229,   229,   229,   229,   229,   229,   229,   229,     1,   229,
     229,     4,     5,     6,   229,   226,   226,   226,   226,   226,
     226,   223,   223,   223,   223,   985,   229,   222,   988,   222,
     228,   228,   228,   222,   994,   226,   226,   997,    31,    32,
      33,    34,    35,    36,   229,    38,    39,   229,    99,   230,
     230,   222,   230,   229,   229,    30,   226,   229,    51,    52,
     229,   229,   229,   229,   226,    58,   226,   226,   226,    62,
      63,   223,    65,   229,   225,   229,   229,    70,    71,    72,
      73,    74,    75,    76,   230,   222,    79,   230,    81,   230,
      83,    84,    85,    86,   229,   229,   226,    90,   222,   226,
     222,    94,     1,   223,    97,     4,     5,     6,   226,   230,
     229,  1071,   229,   225,   230,   229,   229,   223,   229,   229,
     229,   229,   226,   226,   117,   226,   226,   229,   222,   226,
     223,   230,    31,    32,    33,    34,    35,    36,   230,    38,
      39,   229,   223,   226,   223,    30,   228,   233,   228,   223,
     228,   228,    51,    52,   226,   226,   229,   226,   228,    58,
      59,    60,    61,    62,    63,   228,    65,   228,   228,   228,
     226,    70,   229,   228,   228,    74,    75,    76,   228,   226,
      79,  1141,    81,   226,    83,    84,    85,    86,   226,   226,
     226,    90,   226,   226,   229,    94,   226,   226,    97,   192,
     193,   226,   226,   196,   226,   226,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   229,   117,   228,
     213,   228,   228,   216,   228,   228,   223,   220,   226,   222,
     226,   223,    99,    99,   229,   229,   226,   228,   226,   222,
     229,   228,   228,   228,   228,   223,   223,   223,   229,   223,
     229,    99,   223,   222,    30,   228,   228,    44,   228,   226,
     228,    44,   223,   229,   229,   229,   229,   229,   226,   226,
     229,   223,   228,   228,   228,   228,   223,   223,   222,   229,
     229,   223,   223,   223,   223,   223,   229,    45,     1,   950,
     226,   226,   229,   192,   193,   229,   229,   196,   230,   229,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   229,   229,   229,   213,     1,   230,   216,     4,     5,
       6,   220,   230,   222,   229,   229,   222,   230,   230,   229,
     228,   228,   226,   226,   226,   226,   226,   223,   226,   223,
     223,   223,   229,   223,   223,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   229,   229,   226,   230,   229,   610,
     229,   226,   226,   226,   226,    51,    52,   226,   229,   229,
     226,   229,    58,   230,   229,   226,    62,    63,   228,    65,
     226,   226,     1,   223,    70,     4,     5,     6,    74,    75,
      76,   229,   226,    79,   229,    81,   226,    83,    84,    85,
      86,   226,   229,   223,    90,    91,   223,   223,    94,   228,
     228,    97,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   226,   228,   230,   228,   228,   226,   229,   229,   223,
     229,   117,    51,    52,   226,   226,   226,   226,   226,    58,
     226,   226,   226,    62,    63,   223,    65,   228,   228,   228,
     223,    70,   229,   228,   226,    74,    75,    76,   226,   226,
      79,   226,    81,   229,    83,    84,    85,    86,   229,   226,
     226,    90,    91,   223,   229,    94,   229,   226,    97,   226,
      44,   229,   226,   229,   226,   228,   223,   228,   228,   228,
     223,   222,   228,   223,   228,   222,   228,   223,   117,   222,
     229,   229,   223,   223,   226,   229,   192,   193,   226,   226,
     196,   226,   226,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   226,   226,   226,   213,   223,   223,
     216,   223,   229,   229,   220,   223,   222,   230,   229,   229,
     229,   226,   226,   226,   223,   223,   228,   228,   228,   226,
     226,   226,   226,   226,   226,   226,    45,   223,   226,   229,
     229,   228,   226,   226,   229,    45,    45,   229,   229,   226,
     230,   230,   230,   192,   193,   229,   229,   196,   230,   229,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   228,   226,   226,   213,     1,   226,   216,     4,     5,
       6,   220,   226,   222,   229,   223,   228,   228,   228,   226,
     226,    44,   226,    44,   229,   226,   229,   229,   228,    44,
     229,   229,   229,   226,   226,    31,    32,    33,    34,    35,
      36,   226,    38,    39,   226,   229,   229,   228,   228,   228,
     226,   229,   226,   226,   229,    51,    52,   229,   226,   226,
     226,   226,    58,    44,    44,   229,    62,    63,   230,    65,
     230,   229,     1,   230,    70,     4,     5,     6,    74,    75,
      76,    77,   229,    79,   228,    81,   226,    83,    84,    85,
      86,   226,   226,   226,    90,   226,    45,   229,    94,   226,
     229,    97,    31,    32,    33,    34,    35,    36,    45,    38,
      39,   226,   229,    45,   226,   229,   229,    45,   228,   226,
     226,   117,    51,    52,   229,   226,   229,   226,   121,    58,
     226,   229,   226,    62,    63,    64,    65,   226,   226,   229,
     226,    70,   227,    -1,   385,    74,    75,    76,   386,   381,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,   414,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
     196,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
     216,    -1,    -1,    -1,   220,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,     1,    -1,   216,     4,     5,
       6,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,     1,    -1,    70,     4,     5,     6,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,
      -1,    97,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      79,    80,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,
     196,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
     216,    -1,    -1,    -1,   220,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,     1,    -1,   216,     4,     5,
       6,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,     1,
      -1,    97,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    78,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,   192,   193,    -1,    -1,
     196,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,   117,    -1,   213,    -1,    -1,
     216,    -1,    -1,    -1,   220,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,     1,    -1,   216,     4,     5,     6,   220,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,     1,
      -1,    70,     4,     5,     6,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,   216,    -1,    -1,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,     1,    -1,   216,     4,     5,     6,   220,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,     1,
      -1,    70,     4,     5,     6,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,   216,    -1,    -1,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,     1,    -1,   216,     4,     5,     6,   220,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,     1,
      -1,    70,     4,     5,     6,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,   216,    -1,    -1,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,     1,    -1,   216,     4,     5,     6,   220,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,     1,
      -1,    70,     4,     5,     6,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    91,    -1,    -1,    94,    -1,    -1,    97,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,   216,    21,    -1,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    82,
      -1,   213,    -1,    86,   216,    -1,    89,    -1,   220,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,
     223,   224,   225,   226,    -1,   228,    -1,    -1,    -1,   232,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,   196,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,   223,
     224,   225,    -1,    -1,   228,   229,    -1,    -1,   232,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,   223,   224,
     225,    -1,    -1,   228,   229,    -1,    -1,   232,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     196,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   223,   224,   225,
      -1,    -1,   228,   229,    -1,    -1,   232,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   196,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   222,   223,   224,   225,    -1,
      -1,   228,    -1,    -1,    -1,   232,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   223,   224,   225,    -1,    -1,
     228,    -1,    -1,    -1,   232,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   222,   223,   224,   225,    -1,    -1,   228,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    -1,    -1,   309,   310,   311,   312,   313,    -1,
      -1,    -1,   317,   318,   319,   320,   321,   322,    -1,    -1,
      -1,    -1,   327,   328,   329,   330,   331,   332,   333,    -1,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   373,   374,
     375,   376,   377,   378
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   241,   242,   242,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   117,   192,
     193,   196,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   213,   216,   220,   222,   244,   245,   246,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   279,   282,   286,   287,   288,   289,   290,
     294,   295,   226,   222,   192,   193,   196,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   221,   222,
     306,   222,    21,    45,    53,    54,    55,    56,    57,    82,
      86,    89,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     196,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   222,   223,   224,   225,   228,   232,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   307,   222,
     249,   306,   249,   296,   226,   306,   228,   226,   296,   227,
     296,   296,   296,   306,   226,   226,   226,   226,   222,   306,
     306,   306,   306,   222,   222,   222,   228,   222,   306,   105,
     228,   227,     7,     8,     9,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   102,   192,   193,   194,   195,
     196,   197,   215,   296,   300,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     225,   228,   296,   305,   226,    88,    87,   227,   235,   236,
     237,   238,   239,   221,   231,   232,   233,   234,   217,   105,
     228,   227,   227,   227,   226,   226,   306,   226,    53,   226,
     226,   226,   227,    71,   291,   292,   243,   226,   226,   226,
     226,   226,    46,   261,    11,    12,    13,    14,    48,   262,
      99,   100,   101,   201,   226,   296,   310,    99,   226,   221,
     222,   296,   308,   309,   296,    10,   226,   226,   226,   228,
     228,   228,   228,   228,   202,   226,   203,   226,   226,   226,
     226,   228,   228,   228,   228,   228,   228,   228,   226,   226,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   229,   229,   310,   310,   310,   310,   310,   229,
     229,   229,   310,   310,   310,   229,   310,   229,   310,   229,
     310,   296,   296,   296,   296,   310,   310,   310,   310,   310,
     310,   310,   296,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   296,   296,   296,   296,   222,   229,   306,   306,
     310,   310,   310,   310,   310,   310,   310,   306,   296,   308,
     229,   298,   299,   301,   301,   301,   301,   301,   301,   301,
     302,   302,   303,   303,   303,   222,   296,   296,   306,   296,
     229,   226,   243,   243,   243,   296,   296,    72,   292,   293,
      77,   244,   243,   226,   228,   228,   228,   228,   228,    49,
     226,   100,   201,   226,   228,   228,   228,   280,   229,   230,
     226,   222,   277,   278,   296,   229,   229,   230,   226,   228,
     223,   223,   223,   223,   223,   228,   228,   222,   223,   223,
     223,   223,   223,   198,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   230,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   230,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   226,   226,   226,   306,   283,    64,
      64,    67,    68,   226,   226,    73,   226,    80,    92,   223,
     223,   223,   223,   225,   228,   265,   228,   228,   280,   218,
     219,   223,   222,   222,    98,   103,   222,   281,   296,   277,
     226,   227,   214,   278,   226,   105,   226,   296,   233,   229,
     229,   229,   230,   230,   222,   222,   229,   229,   229,   229,
     229,   229,   230,   296,    22,    23,    24,    25,    26,    27,
     226,    59,    60,   284,   285,   226,   226,   296,   296,   243,
     243,   226,   243,   226,   222,   262,   229,   229,   229,   230,
     229,   225,    95,   104,   222,   266,   218,   219,   223,   222,
      98,   230,   230,   229,   229,   229,   230,   226,   222,    11,
      12,    13,    14,   214,   296,   226,   243,   222,   230,    29,
      30,    40,    41,    42,    46,    47,   100,   247,    30,    46,
     100,   247,    29,    30,    42,    46,   100,   247,   223,   223,
     229,   229,   226,   247,   247,   247,   247,   247,   225,   230,
     229,   229,   229,   229,   229,   229,   296,   226,    61,    69,
     226,    69,   226,    78,   262,   226,   223,   226,   229,   226,
     222,    11,    12,    13,    14,   101,   230,   230,   229,   229,
     230,   226,   223,   223,    99,   100,   226,   226,   223,    11,
      12,    13,    14,   228,   228,   228,   228,   226,   226,    66,
     233,    30,   228,   228,    30,   228,   226,   228,   228,   226,
      30,   228,   228,    30,   228,   226,   229,   229,   226,   226,
     226,   226,   226,   226,   226,   229,    22,    23,    24,    25,
      26,    27,   226,   243,   226,   296,   243,   296,   243,   226,
     226,   263,   229,   265,   226,    11,    12,    13,    14,   228,
     228,   228,   228,   228,   223,   223,   226,   226,   223,   229,
     229,   226,   228,   280,   229,   228,   228,   228,   228,   223,
     223,   223,   223,   226,   229,   228,   296,   222,   228,   223,
     296,   218,   219,   223,   228,   296,   222,   228,   218,   219,
     223,    29,    30,   100,   247,   247,   226,   229,   229,   229,
     229,   229,   229,   243,   226,    66,   226,    66,   263,    93,
     104,   222,   264,    95,   265,   228,   228,   228,   228,   223,
     223,   223,   223,   222,   229,   229,   280,   280,   229,    99,
      99,   280,   223,    98,    99,   223,   223,   223,   223,   229,
     229,   229,   230,   226,   296,   229,   229,   296,   229,   229,
     230,   230,   229,   296,   229,   229,   296,   230,   230,   229,
      30,   228,   228,   226,   226,   243,   226,   243,   226,    93,
     226,   222,    11,    12,    13,    14,   101,   226,    95,   223,
     223,   223,   223,   229,   229,   229,   230,   229,   226,   226,
      98,    98,   226,   226,   226,    98,   229,   226,   226,   229,
     229,   229,   230,   199,   200,   226,   226,   199,   200,   226,
     223,   229,   226,   226,   229,   207,   208,   226,   226,   223,
     223,   226,   229,   226,   226,   229,   223,   223,   207,   208,
     226,   228,   296,   223,    66,    66,   226,   243,    11,    12,
      13,    14,   228,   228,   228,   228,   228,   226,   229,   229,
     229,   230,    43,    96,   226,    43,    96,   226,    43,    96,
     226,   223,   226,   280,   280,   226,   226,   280,   280,   280,
     226,   226,   280,   226,   226,   226,   223,   228,   228,   228,
     228,   229,   226,   226,   226,   226,   229,   229,   226,   226,
     229,   229,   226,   226,   296,   229,   229,   226,   226,   243,
      37,    91,   228,   228,   228,   228,   223,   223,   223,   223,
     222,    96,   226,    96,   226,    96,   226,   223,   228,    43,
     226,   228,    43,   226,   228,    43,   226,   229,    98,    98,
      98,    98,    98,    98,   229,   222,   223,   222,   223,   200,
     226,   226,   226,   226,   226,   229,   226,   226,    37,    91,
     226,   226,   223,   223,   223,   223,   229,   229,   229,   230,
     229,   226,   226,   226,   229,    44,    45,   228,    44,    45,
     228,    44,    45,   228,    43,    96,   226,   226,   226,   226,
     226,   226,   226,   226,   229,   230,   229,   229,   230,   229,
     228,   226,   226,   226,   243,   229,   229,   229,   230,    43,
      96,   226,    43,    96,   226,    43,    96,   226,   223,   226,
      96,   226,   230,   229,    44,   230,   229,    44,   230,   229,
      44,   228,    43,   226,   226,   223,   226,   226,   223,   226,
     223,   243,    91,    96,   226,    96,   226,    96,   226,   223,
     228,    43,   226,   228,    43,   226,   228,    43,   226,   229,
     226,    45,   226,   229,    45,   226,   229,    45,   226,   229,
      45,   228,   229,   229,   229,    91,   226,   226,   226,   226,
     229,    44,    45,   228,    44,    45,   228,    44,    45,   228,
      43,    96,   226,   229,   226,   229,   226,   229,   226,   229,
      44,   226,   226,   226,   226,    96,   226,   230,   229,    44,
     230,   229,    44,   230,   229,    44,   228,    43,   226,   226,
     226,   226,   226,   229,   226,    45,   226,   229,    45,   226,
     229,    45,   226,   229,    45,   228,   226,   229,   226,   229,
     226,   229,   226,   229,    44,   226,   226,   226,   226,   229,
     226
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   240,   241,   241,   242,   242,   242,   243,   243,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   245,   245,   245,   245,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     247,   247,   247,   247,   247,   248,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   250,   250,   251,   252,
     253,   254,   255,   256,   257,   257,   258,   259,   259,   259,
     260,   260,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   263,   263,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   265,   265,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   276,   277,   277,   278,   278,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   282,   283,   283,
     284,   285,   285,   286,   287,   288,   288,   288,   288,   289,
     290,   291,   291,   292,   293,   293,   294,   295,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   300,   300,   300,
     300,   300,   300,   301,   301,   301,   302,   302,   302,   303,
     303,   304,   304,   305,   305,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     308,   308,   309,   309,   310,   310
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,    10,     8,     8,     8,
      10,    10,    12,    12,    14,    11,    11,    13,    11,    12,
      12,     4,     4,     4,     4,     4,     4,    11,    11,    11,
      13,    13,    13,    13,    13,     7,     8,     8,     8,     8,
       8,     9,    11,    11,    12,    12,    12,    12,     8,     8,
       0,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     6,     4,     4,     5,     5,     5,
       3,     2,     3,     4,     3,     2,     5,     7,    11,    10,
      13,    14,    16,    17,     0,     1,     0,     4,     4,     4,
       6,     0,     2,     6,     7,     6,     7,     6,     7,     8,
       9,     7,     8,     7,     8,     7,     8,     9,    10,     6,
      11,    11,    11,    13,    10,    10,    10,    12,    12,    12,
      12,     0,     2,     6,     7,     6,     7,     6,     7,     8,
       9,     7,     8,     7,     8,     7,     8,     9,    10,     6,
      11,    11,    11,    13,    10,    10,    10,    12,    12,    12,
      12,     8,     6,     3,     3,     3,     3,     3,     6,     1,
       7,     6,     1,     2,     2,     4,     7,     6,    11,    11,
      13,    13,    13,    13,     7,    11,    11,    13,    13,    10,
       0,     2,     6,     6,     6,     8,     7,     7,     7,     9,
      10,    10,    12,    10,    12,    10,    12,     8,     0,     2,
       4,     0,     3,     6,     6,    10,    12,    10,    12,     8,
       6,     1,     2,     4,     0,     3,     2,     2,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     6,     6,     6,     4,     4,     4,
       4,     3,     3,     4,     4,     4,     4,     4,     4,     3,
       4,     3,     4,     3,     8,     8,     8,     4,     4,     4,
       3,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     1,     8,     8,     8,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     3,     1,     3
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
#line 194 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3048 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 197 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3056 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 204 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3066 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 209 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3077 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 218 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3085 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 221 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3096 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3102 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3108 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 232 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3114 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3120 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 234 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3126 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3132 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3138 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3144 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3150 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3156 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3162 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3168 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 242 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3174 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3180 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3186 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3192 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3198 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3204 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3210 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3216 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3222 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3228 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3234 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3240 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3246 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3252 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3258 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3264 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3270 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3276 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3282 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3288 "build/parser.cpp"
    break;

  case 41: /* statement: expr_stmt  */
#line 262 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3294 "build/parser.cpp"
    break;

  case 42: /* statement: error SEMICOLON  */
#line 263 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3300 "build/parser.cpp"
    break;

  case 43: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 268 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3309 "build/parser.cpp"
    break;

  case 44: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 272 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3318 "build/parser.cpp"
    break;

  case 45: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 276 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3327 "build/parser.cpp"
    break;

  case 46: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 280 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3336 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 288 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3346 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 293 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3356 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 298 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3366 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 303 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3376 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 308 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3386 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 313 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3396 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 318 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3406 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 323 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3416 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 328 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3426 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 333 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3436 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 338 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3446 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 343 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3456 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 349 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3467 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 355 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3478 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 361 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3487 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 365 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3496 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 369 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3505 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 373 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3514 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 377 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3523 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 381 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3532 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 385 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3541 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 389 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3550 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 393 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3559 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 397 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3568 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 401 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3579 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 407 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3590 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 413 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3601 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 419 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3612 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 425 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3624 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 432 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3634 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 437 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3645 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 443 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3655 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 448 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3665 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 453 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3675 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 458 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3685 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 463 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3695 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 468 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3705 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 473 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3715 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 478 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3725 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 483 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3735 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 488 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3745 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 493 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3755 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 498 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3765 "build/parser.cpp"
    break;

  case 90: /* dcl_s_keywords: %empty  */
#line 506 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3771 "build/parser.cpp"
    break;

  case 91: /* dcl_s_keywords: KW_STATIC  */
#line 507 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3777 "build/parser.cpp"
    break;

  case 92: /* dcl_s_keywords: KW_TEMPLATE  */
#line 508 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3783 "build/parser.cpp"
    break;

  case 93: /* dcl_s_keywords: KW_EXPORT  */
#line 509 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3789 "build/parser.cpp"
    break;

  case 94: /* dcl_s_keywords: KW_IMPORT  */
#line 510 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3795 "build/parser.cpp"
    break;

  case 95: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 515 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3804 "build/parser.cpp"
    break;

  case 96: /* eval_target: IDENTIFIER  */
#line 522 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3813 "build/parser.cpp"
    break;

  case 97: /* eval_target: KW_POS  */
#line 526 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3819 "build/parser.cpp"
    break;

  case 98: /* eval_target: KW_OVERLAY  */
#line 527 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3825 "build/parser.cpp"
    break;

  case 99: /* eval_target: KW_PREFIX  */
#line 528 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3831 "build/parser.cpp"
    break;

  case 100: /* eval_target: KW_UNS  */
#line 529 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3837 "build/parser.cpp"
    break;

  case 101: /* eval_target: KW_FLOAT_TYPE  */
#line 530 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3843 "build/parser.cpp"
    break;

  case 102: /* eval_target: KW_GRAPH  */
#line 531 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 3849 "build/parser.cpp"
    break;

  case 103: /* eval_target: KW_ASCEND  */
#line 532 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 3855 "build/parser.cpp"
    break;

  case 104: /* eval_target: KW_DESCEND  */
#line 533 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 3861 "build/parser.cpp"
    break;

  case 105: /* eval_target: KW_RTNPARM  */
#line 534 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 3867 "build/parser.cpp"
    break;

  case 106: /* eval_target: KW_OPDESC  */
#line 535 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 3873 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_NULLIND  */
#line 536 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 3879 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_DATFMT  */
#line 537 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 3885 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_TIMFMT  */
#line 538 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 3891 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_EXTNAME  */
#line 539 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 3897 "build/parser.cpp"
    break;

  case 111: /* eval_target: INDICATOR  */
#line 540 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3905 "build/parser.cpp"
    break;

  case 112: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 543 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3916 "build/parser.cpp"
    break;

  case 113: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 549 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3925 "build/parser.cpp"
    break;

  case 114: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 553 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3936 "build/parser.cpp"
    break;

  case 115: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 559 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 3944 "build/parser.cpp"
    break;

  case 116: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 565 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3955 "build/parser.cpp"
    break;

  case 117: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 571 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3966 "build/parser.cpp"
    break;

  case 118: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 580 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3976 "build/parser.cpp"
    break;

  case 119: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 588 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3987 "build/parser.cpp"
    break;

  case 120: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 597 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3995 "build/parser.cpp"
    break;

  case 121: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 603 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4003 "build/parser.cpp"
    break;

  case 122: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 609 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4011 "build/parser.cpp"
    break;

  case 123: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 615 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4019 "build/parser.cpp"
    break;

  case 124: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 621 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4027 "build/parser.cpp"
    break;

  case 125: /* return_stmt: KW_RETURN SEMICOLON  */
#line 624 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4035 "build/parser.cpp"
    break;

  case 126: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 631 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4045 "build/parser.cpp"
    break;

  case 127: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 642 "src/parser.y"
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
#line 4066 "build/parser.cpp"
    break;

  case 128: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 659 "src/parser.y"
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
#line 4090 "build/parser.cpp"
    break;

  case 129: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 679 "src/parser.y"
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
#line 4106 "build/parser.cpp"
    break;

  case 130: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 697 "src/parser.y"
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
#line 4131 "build/parser.cpp"
    break;

  case 131: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 721 "src/parser.y"
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
#line 4157 "build/parser.cpp"
    break;

  case 132: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 747 "src/parser.y"
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
#line 4184 "build/parser.cpp"
    break;

  case 133: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 774 "src/parser.y"
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
#line 4212 "build/parser.cpp"
    break;

  case 134: /* proc_export: %empty  */
#line 800 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4218 "build/parser.cpp"
    break;

  case 135: /* proc_export: KW_EXPORT  */
#line 801 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4224 "build/parser.cpp"
    break;

  case 136: /* pi_return_type: %empty  */
#line 806 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4230 "build/parser.cpp"
    break;

  case 137: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 807 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4236 "build/parser.cpp"
    break;

  case 138: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 808 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4242 "build/parser.cpp"
    break;

  case 139: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 809 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4248 "build/parser.cpp"
    break;

  case 140: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 810 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4254 "build/parser.cpp"
    break;

  case 141: /* pi_params: %empty  */
#line 815 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4262 "build/parser.cpp"
    break;

  case 142: /* pi_params: pi_params pi_param  */
#line 818 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4272 "build/parser.cpp"
    break;

  case 143: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 826 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4281 "build/parser.cpp"
    break;

  case 144: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 830 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4290 "build/parser.cpp"
    break;

  case 145: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 834 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4299 "build/parser.cpp"
    break;

  case 146: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 838 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4308 "build/parser.cpp"
    break;

  case 147: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 842 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4317 "build/parser.cpp"
    break;

  case 148: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 846 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4326 "build/parser.cpp"
    break;

  case 149: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 850 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4335 "build/parser.cpp"
    break;

  case 150: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 854 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4344 "build/parser.cpp"
    break;

  case 151: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 859 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4353 "build/parser.cpp"
    break;

  case 152: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 863 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4362 "build/parser.cpp"
    break;

  case 153: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 867 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4371 "build/parser.cpp"
    break;

  case 154: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 871 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4380 "build/parser.cpp"
    break;

  case 155: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 875 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4389 "build/parser.cpp"
    break;

  case 156: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 879 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4398 "build/parser.cpp"
    break;

  case 157: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 883 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4407 "build/parser.cpp"
    break;

  case 158: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 887 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4416 "build/parser.cpp"
    break;

  case 159: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 891 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4426 "build/parser.cpp"
    break;

  case 160: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 897 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4436 "build/parser.cpp"
    break;

  case 161: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 902 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4446 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 907 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4456 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 912 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4466 "build/parser.cpp"
    break;

  case 164: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 918 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4476 "build/parser.cpp"
    break;

  case 165: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 923 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4486 "build/parser.cpp"
    break;

  case 166: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 928 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4496 "build/parser.cpp"
    break;

  case 167: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 933 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4506 "build/parser.cpp"
    break;

  case 168: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 939 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4516 "build/parser.cpp"
    break;

  case 169: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 944 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4526 "build/parser.cpp"
    break;

  case 170: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 949 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4536 "build/parser.cpp"
    break;

  case 171: /* pr_params: %empty  */
#line 958 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4544 "build/parser.cpp"
    break;

  case 172: /* pr_params: pr_params pr_param  */
#line 961 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4554 "build/parser.cpp"
    break;

  case 173: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 969 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4563 "build/parser.cpp"
    break;

  case 174: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 973 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4572 "build/parser.cpp"
    break;

  case 175: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 977 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4581 "build/parser.cpp"
    break;

  case 176: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 981 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4590 "build/parser.cpp"
    break;

  case 177: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 985 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4599 "build/parser.cpp"
    break;

  case 178: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 989 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4608 "build/parser.cpp"
    break;

  case 179: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 993 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4617 "build/parser.cpp"
    break;

  case 180: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 997 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4626 "build/parser.cpp"
    break;

  case 181: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1002 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4635 "build/parser.cpp"
    break;

  case 182: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1006 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4644 "build/parser.cpp"
    break;

  case 183: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1010 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4653 "build/parser.cpp"
    break;

  case 184: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1014 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4662 "build/parser.cpp"
    break;

  case 185: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1018 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4671 "build/parser.cpp"
    break;

  case 186: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1022 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4680 "build/parser.cpp"
    break;

  case 187: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1026 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4689 "build/parser.cpp"
    break;

  case 188: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1030 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4698 "build/parser.cpp"
    break;

  case 189: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1034 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4708 "build/parser.cpp"
    break;

  case 190: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1040 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4718 "build/parser.cpp"
    break;

  case 191: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1045 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4728 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1050 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4738 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1055 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4748 "build/parser.cpp"
    break;

  case 194: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1061 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4758 "build/parser.cpp"
    break;

  case 195: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1066 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4768 "build/parser.cpp"
    break;

  case 196: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1071 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4778 "build/parser.cpp"
    break;

  case 197: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1076 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4788 "build/parser.cpp"
    break;

  case 198: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1082 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4798 "build/parser.cpp"
    break;

  case 199: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1087 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4808 "build/parser.cpp"
    break;

  case 200: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1092 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4818 "build/parser.cpp"
    break;

  case 201: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1102 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4831 "build/parser.cpp"
    break;

  case 202: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1113 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4843 "build/parser.cpp"
    break;

  case 203: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1123 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4852 "build/parser.cpp"
    break;

  case 204: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1131 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4861 "build/parser.cpp"
    break;

  case 205: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1139 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4870 "build/parser.cpp"
    break;

  case 206: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1146 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4879 "build/parser.cpp"
    break;

  case 207: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1154 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4888 "build/parser.cpp"
    break;

  case 208: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1162 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4899 "build/parser.cpp"
    break;

  case 209: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1173 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 4909 "build/parser.cpp"
    break;

  case 210: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1183 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 4922 "build/parser.cpp"
    break;

  case 211: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1191 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 4935 "build/parser.cpp"
    break;

  case 212: /* enum_constants: enum_constant  */
#line 1202 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 4943 "build/parser.cpp"
    break;

  case 213: /* enum_constants: enum_constants enum_constant  */
#line 1205 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 4953 "build/parser.cpp"
    break;

  case 214: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1213 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 4966 "build/parser.cpp"
    break;

  case 215: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1221 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 4980 "build/parser.cpp"
    break;

  case 216: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1236 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4993 "build/parser.cpp"
    break;

  case 217: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1245 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 5006 "build/parser.cpp"
    break;

  case 218: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1254 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5020 "build/parser.cpp"
    break;

  case 219: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1264 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5034 "build/parser.cpp"
    break;

  case 220: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1274 "src/parser.y"
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
#line 5049 "build/parser.cpp"
    break;

  case 221: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1285 "src/parser.y"
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
#line 5064 "build/parser.cpp"
    break;

  case 222: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1296 "src/parser.y"
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
#line 5079 "build/parser.cpp"
    break;

  case 223: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1307 "src/parser.y"
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
#line 5094 "build/parser.cpp"
    break;

  case 224: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1318 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5106 "build/parser.cpp"
    break;

  case 225: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1326 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5119 "build/parser.cpp"
    break;

  case 226: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1335 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5133 "build/parser.cpp"
    break;

  case 227: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1345 "src/parser.y"
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
#line 5148 "build/parser.cpp"
    break;

  case 228: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1356 "src/parser.y"
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
#line 5163 "build/parser.cpp"
    break;

  case 229: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1367 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5177 "build/parser.cpp"
    break;

  case 230: /* ds_fields: %empty  */
#line 1379 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5185 "build/parser.cpp"
    break;

  case 231: /* ds_fields: ds_fields ds_field  */
#line 1382 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5195 "build/parser.cpp"
    break;

  case 232: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1390 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5204 "build/parser.cpp"
    break;

  case 233: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1394 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5213 "build/parser.cpp"
    break;

  case 234: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1398 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5222 "build/parser.cpp"
    break;

  case 235: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1402 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5231 "build/parser.cpp"
    break;

  case 236: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1407 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5240 "build/parser.cpp"
    break;

  case 237: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1411 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5249 "build/parser.cpp"
    break;

  case 238: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1415 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5258 "build/parser.cpp"
    break;

  case 239: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1419 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5267 "build/parser.cpp"
    break;

  case 240: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1424 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5278 "build/parser.cpp"
    break;

  case 241: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1430 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5289 "build/parser.cpp"
    break;

  case 242: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1436 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5300 "build/parser.cpp"
    break;

  case 243: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1443 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5311 "build/parser.cpp"
    break;

  case 244: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1450 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5323 "build/parser.cpp"
    break;

  case 245: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1457 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5334 "build/parser.cpp"
    break;

  case 246: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1463 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5346 "build/parser.cpp"
    break;

  case 247: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1475 "src/parser.y"
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
#line 5371 "build/parser.cpp"
    break;

  case 248: /* elseif_clauses: %empty  */
#line 1498 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5377 "build/parser.cpp"
    break;

  case 249: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1499 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5387 "build/parser.cpp"
    break;

  case 250: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1507 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5398 "build/parser.cpp"
    break;

  case 251: /* else_clause: %empty  */
#line 1516 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5404 "build/parser.cpp"
    break;

  case 252: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1517 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5412 "build/parser.cpp"
    break;

  case 253: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1523 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5423 "build/parser.cpp"
    break;

  case 254: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1532 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5434 "build/parser.cpp"
    break;

  case 255: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1541 "src/parser.y"
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
#line 5449 "build/parser.cpp"
    break;

  case 256: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1551 "src/parser.y"
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
#line 5464 "build/parser.cpp"
    break;

  case 257: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1561 "src/parser.y"
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
#line 5479 "build/parser.cpp"
    break;

  case 258: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1571 "src/parser.y"
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
#line 5494 "build/parser.cpp"
    break;

  case 259: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1584 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5506 "build/parser.cpp"
    break;

  case 260: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1594 "src/parser.y"
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
#line 5527 "build/parser.cpp"
    break;

  case 261: /* when_clauses: when_clause  */
#line 1613 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5536 "build/parser.cpp"
    break;

  case 262: /* when_clauses: when_clauses when_clause  */
#line 1617 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5545 "build/parser.cpp"
    break;

  case 263: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1624 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5556 "build/parser.cpp"
    break;

  case 264: /* other_clause: %empty  */
#line 1633 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5562 "build/parser.cpp"
    break;

  case 265: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1634 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5570 "build/parser.cpp"
    break;

  case 266: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1640 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5576 "build/parser.cpp"
    break;

  case 267: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1644 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5582 "build/parser.cpp"
    break;

  case 268: /* expression: or_expr  */
#line 1650 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5588 "build/parser.cpp"
    break;

  case 269: /* or_expr: and_expr  */
#line 1654 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5594 "build/parser.cpp"
    break;

  case 270: /* or_expr: or_expr KW_OR and_expr  */
#line 1655 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5604 "build/parser.cpp"
    break;

  case 271: /* and_expr: not_expr  */
#line 1663 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5610 "build/parser.cpp"
    break;

  case 272: /* and_expr: and_expr KW_AND not_expr  */
#line 1664 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5620 "build/parser.cpp"
    break;

  case 273: /* not_expr: comparison_expr  */
#line 1672 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5626 "build/parser.cpp"
    break;

  case 274: /* not_expr: KW_NOT comparison_expr  */
#line 1673 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5634 "build/parser.cpp"
    break;

  case 275: /* comparison_expr: additive_expr  */
#line 1679 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5640 "build/parser.cpp"
    break;

  case 276: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1680 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5650 "build/parser.cpp"
    break;

  case 277: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1685 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5660 "build/parser.cpp"
    break;

  case 278: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1690 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5670 "build/parser.cpp"
    break;

  case 279: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1695 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5680 "build/parser.cpp"
    break;

  case 280: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1700 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5690 "build/parser.cpp"
    break;

  case 281: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1705 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5700 "build/parser.cpp"
    break;

  case 282: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1710 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5710 "build/parser.cpp"
    break;

  case 283: /* additive_expr: multiplicative_expr  */
#line 1718 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 5716 "build/parser.cpp"
    break;

  case 284: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1719 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5726 "build/parser.cpp"
    break;

  case 285: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1724 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5736 "build/parser.cpp"
    break;

  case 286: /* multiplicative_expr: power_expr  */
#line 1732 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5742 "build/parser.cpp"
    break;

  case 287: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1733 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5752 "build/parser.cpp"
    break;

  case 288: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1738 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5762 "build/parser.cpp"
    break;

  case 289: /* power_expr: unary_expr  */
#line 1746 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5768 "build/parser.cpp"
    break;

  case 290: /* power_expr: unary_expr POWER power_expr  */
#line 1747 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5778 "build/parser.cpp"
    break;

  case 291: /* unary_expr: postfix_expr  */
#line 1755 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5784 "build/parser.cpp"
    break;

  case 292: /* unary_expr: MINUS postfix_expr  */
#line 1756 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5794 "build/parser.cpp"
    break;

  case 293: /* postfix_expr: primary_expr  */
#line 1764 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5800 "build/parser.cpp"
    break;

  case 294: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1765 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5809 "build/parser.cpp"
    break;

  case 295: /* ident: IDENTIFIER  */
#line 1772 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 5815 "build/parser.cpp"
    break;

  case 296: /* ident: KW_UNS  */
#line 1773 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 5821 "build/parser.cpp"
    break;

  case 297: /* ident: KW_FLOAT_TYPE  */
#line 1774 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 5827 "build/parser.cpp"
    break;

  case 298: /* ident: KW_GRAPH  */
#line 1775 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 5833 "build/parser.cpp"
    break;

  case 299: /* ident: KW_ASCEND  */
#line 1776 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 5839 "build/parser.cpp"
    break;

  case 300: /* ident: KW_DESCEND  */
#line 1777 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 5845 "build/parser.cpp"
    break;

  case 301: /* ident: KW_IN  */
#line 1778 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 5851 "build/parser.cpp"
    break;

  case 302: /* ident: KW_RTNPARM  */
#line 1779 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 5857 "build/parser.cpp"
    break;

  case 303: /* ident: KW_OPDESC  */
#line 1780 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 5863 "build/parser.cpp"
    break;

  case 304: /* ident: KW_NULLIND  */
#line 1781 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 5869 "build/parser.cpp"
    break;

  case 305: /* ident: KW_DATFMT  */
#line 1782 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 5875 "build/parser.cpp"
    break;

  case 306: /* ident: KW_TIMFMT  */
#line 1783 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 5881 "build/parser.cpp"
    break;

  case 307: /* ident: KW_EXTNAME  */
#line 1784 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 5887 "build/parser.cpp"
    break;

  case 308: /* ident: KW_OVERLAY  */
#line 1785 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 5893 "build/parser.cpp"
    break;

  case 309: /* ident: KW_POS  */
#line 1786 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 5899 "build/parser.cpp"
    break;

  case 310: /* ident: KW_PREFIX  */
#line 1787 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 5905 "build/parser.cpp"
    break;

  case 311: /* primary_expr: IDENTIFIER  */
#line 1791 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5914 "build/parser.cpp"
    break;

  case 312: /* primary_expr: KW_UNS  */
#line 1795 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 5920 "build/parser.cpp"
    break;

  case 313: /* primary_expr: KW_FLOAT_TYPE  */
#line 1796 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 5926 "build/parser.cpp"
    break;

  case 314: /* primary_expr: KW_GRAPH  */
#line 1797 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 5932 "build/parser.cpp"
    break;

  case 315: /* primary_expr: KW_ASCEND  */
#line 1798 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 5938 "build/parser.cpp"
    break;

  case 316: /* primary_expr: KW_DESCEND  */
#line 1799 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 5944 "build/parser.cpp"
    break;

  case 317: /* primary_expr: KW_RTNPARM  */
#line 1800 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 5950 "build/parser.cpp"
    break;

  case 318: /* primary_expr: KW_OPDESC  */
#line 1801 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 5956 "build/parser.cpp"
    break;

  case 319: /* primary_expr: KW_NULLIND  */
#line 1802 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 5962 "build/parser.cpp"
    break;

  case 320: /* primary_expr: KW_DATFMT  */
#line 1803 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 5968 "build/parser.cpp"
    break;

  case 321: /* primary_expr: KW_OVERLAY  */
#line 1804 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 5974 "build/parser.cpp"
    break;

  case 322: /* primary_expr: KW_POS  */
#line 1805 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 5980 "build/parser.cpp"
    break;

  case 323: /* primary_expr: KW_PREFIX  */
#line 1806 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 5986 "build/parser.cpp"
    break;

  case 324: /* primary_expr: KW_TIMFMT  */
#line 1807 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 5992 "build/parser.cpp"
    break;

  case 325: /* primary_expr: KW_EXTNAME  */
#line 1808 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 5998 "build/parser.cpp"
    break;

  case 326: /* primary_expr: INTEGER_LITERAL  */
#line 1809 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6006 "build/parser.cpp"
    break;

  case 327: /* primary_expr: FLOAT_LITERAL  */
#line 1812 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6014 "build/parser.cpp"
    break;

  case 328: /* primary_expr: STRING_LITERAL  */
#line 1815 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6023 "build/parser.cpp"
    break;

  case 329: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1819 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6032 "build/parser.cpp"
    break;

  case 330: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1823 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6040 "build/parser.cpp"
    break;

  case 331: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1826 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6048 "build/parser.cpp"
    break;

  case 332: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1829 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6056 "build/parser.cpp"
    break;

  case 333: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1832 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6064 "build/parser.cpp"
    break;

  case 334: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1835 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6072 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1838 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6080 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1841 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6088 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1844 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6096 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1847 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6104 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1850 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6112 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1853 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6120 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1856 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6128 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1859 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6137 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1863 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6145 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1866 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6153 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1869 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6161 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1872 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6169 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1875 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6177 "build/parser.cpp"
    break;

  case 348: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1878 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6185 "build/parser.cpp"
    break;

  case 349: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1881 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6193 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1884 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6201 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1887 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6212 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1893 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6223 "build/parser.cpp"
    break;

  case 353: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1899 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6234 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1905 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6245 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1911 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6256 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1917 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6267 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1923 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6275 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1926 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6283 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1929 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6291 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1932 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6299 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1935 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6308 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1939 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6317 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1943 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6325 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1946 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6333 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1949 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6341 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1952 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6349 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1955 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6357 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1958 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6365 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1961 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6374 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1965 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6382 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1968 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6391 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1972 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6399 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1975 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6408 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1979 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6420 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1986 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6432 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1993 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6444 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2000 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6454 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2005 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6464 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2010 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6474 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2015 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6483 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2019 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6492 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2023 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6500 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2026 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6508 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2029 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6516 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2032 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6524 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2035 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6532 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2038 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6540 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2041 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6548 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2044 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6556 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2047 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 6564 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2050 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6572 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2053 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6580 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2056 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6588 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2059 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6596 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2062 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6604 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2065 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6612 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2068 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6620 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2071 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6628 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2074 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6636 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2077 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6644 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2080 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6652 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2083 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6660 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2086 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6668 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2089 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 6676 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2092 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6684 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2095 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6692 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2098 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6700 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2101 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6708 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2104 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 6718 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2109 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 6728 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2114 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 6738 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2119 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 6748 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2124 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 6759 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2130 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6768 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_PROC  */
#line 2134 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6777 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2138 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6789 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2145 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6801 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2152 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6813 "build/parser.cpp"
    break;

  case 419: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2159 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 6824 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2165 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 6835 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2171 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 6846 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2177 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 6854 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2180 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 6862 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2183 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 6870 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2186 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 6878 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2189 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 6886 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2192 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 6894 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2195 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 6902 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2198 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 6913 "build/parser.cpp"
    break;

  case 430: /* primary_expr: INDICATOR  */
#line 2204 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 6921 "build/parser.cpp"
    break;

  case 431: /* primary_expr: KW_ON  */
#line 2207 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 6929 "build/parser.cpp"
    break;

  case 432: /* primary_expr: KW_OFF  */
#line 2210 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 6937 "build/parser.cpp"
    break;

  case 433: /* primary_expr: KW_NULL  */
#line 2213 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6945 "build/parser.cpp"
    break;

  case 434: /* primary_expr: KW_OMIT  */
#line 2216 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6953 "build/parser.cpp"
    break;

  case 435: /* primary_expr: KW_BLANKS  */
#line 2219 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 6961 "build/parser.cpp"
    break;

  case 436: /* primary_expr: KW_ZEROS  */
#line 2222 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 6969 "build/parser.cpp"
    break;

  case 437: /* primary_expr: KW_HIVAL  */
#line 2225 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 6977 "build/parser.cpp"
    break;

  case 438: /* primary_expr: KW_LOVAL  */
#line 2228 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 6985 "build/parser.cpp"
    break;

  case 439: /* primary_expr: LPAREN expression RPAREN  */
#line 2231 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 6993 "build/parser.cpp"
    break;

  case 440: /* call_args_opt: %empty  */
#line 2238 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 6999 "build/parser.cpp"
    break;

  case 441: /* call_args_opt: call_arg_list  */
#line 2239 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7005 "build/parser.cpp"
    break;

  case 442: /* call_arg_list: expression  */
#line 2243 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7014 "build/parser.cpp"
    break;

  case 443: /* call_arg_list: call_arg_list COLON expression  */
#line 2247 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7023 "build/parser.cpp"
    break;

  case 444: /* arg_list: expression  */
#line 2255 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7032 "build/parser.cpp"
    break;

  case 445: /* arg_list: arg_list COLON expression  */
#line 2259 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7041 "build/parser.cpp"
    break;


#line 7045 "build/parser.cpp"

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

#line 2265 "src/parser.y"


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
