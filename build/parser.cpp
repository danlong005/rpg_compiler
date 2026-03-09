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

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

static rpg::Program* g_program = nullptr;
static int g_error_count = 0;

rpg::Program* get_parsed_program();
int get_parse_error_count();

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

#line 115 "build/parser.cpp"

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
  YYSYMBOL_KW_POINTER = 19,                /* KW_POINTER  */
  YYSYMBOL_KW_NULL = 20,                   /* KW_NULL  */
  YYSYMBOL_KW_DAYS = 21,                   /* KW_DAYS  */
  YYSYMBOL_KW_MONTHS = 22,                 /* KW_MONTHS  */
  YYSYMBOL_KW_YEARS = 23,                  /* KW_YEARS  */
  YYSYMBOL_KW_CONST = 24,                  /* KW_CONST  */
  YYSYMBOL_KW_INZ = 25,                    /* KW_INZ  */
  YYSYMBOL_KW_DSPLY = 26,                  /* KW_DSPLY  */
  YYSYMBOL_KW_EVAL = 27,                   /* KW_EVAL  */
  YYSYMBOL_KW_EVAL_CORR = 28,              /* KW_EVAL_CORR  */
  YYSYMBOL_KW_RETURN = 29,                 /* KW_RETURN  */
  YYSYMBOL_KW_INLR = 30,                   /* KW_INLR  */
  YYSYMBOL_KW_ON = 31,                     /* KW_ON  */
  YYSYMBOL_KW_IF = 32,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 33,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 34,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 35,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 36,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 37,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 38,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 39,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 40,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 41,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 42,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 43,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 44,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 45,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 46,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 47,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 48,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 49,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 50,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 51,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 52,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 53,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 54,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 55,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 56,                    /* KW_OFF  */
  YYSYMBOL_KW_RESET = 57,                  /* KW_RESET  */
  YYSYMBOL_KW_CLEAR = 58,                  /* KW_CLEAR  */
  YYSYMBOL_KW_SORTA = 59,                  /* KW_SORTA  */
  YYSYMBOL_INDICATOR = 60,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 61,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 62,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 63,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 64,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 65,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 66,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 67,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 68,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 69,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 70,                  /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 71,                 /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 72,                 /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 73,              /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 74,                    /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 75,                 /* KW_LIKEDS  */
  YYSYMBOL_KW_LIKE = 76,                   /* KW_LIKE  */
  YYSYMBOL_KW_DCL_SUBF = 77,               /* KW_DCL_SUBF  */
  YYSYMBOL_KW_DCL_PARM = 78,               /* KW_DCL_PARM  */
  YYSYMBOL_DOT = 79,                       /* DOT  */
  YYSYMBOL_BIF_CHAR = 80,                  /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 81,                  /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 82,                 /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 83,                 /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 84,                   /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 85,                 /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 86,                  /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 87,               /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 88,                 /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 89,                   /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 90,                   /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 91,                  /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 92,                 /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 93,                   /* BIF_EOF  */
  YYSYMBOL_BIF_ABS = 94,                   /* BIF_ABS  */
  YYSYMBOL_BIF_DIV = 95,                   /* BIF_DIV  */
  YYSYMBOL_BIF_REM = 96,                   /* BIF_REM  */
  YYSYMBOL_BIF_SIZE = 97,                  /* BIF_SIZE  */
  YYSYMBOL_BIF_ADDR = 98,                  /* BIF_ADDR  */
  YYSYMBOL_BIF_PARMS = 99,                 /* BIF_PARMS  */
  YYSYMBOL_BIF_STATUS = 100,               /* BIF_STATUS  */
  YYSYMBOL_BIF_ERROR = 101,                /* BIF_ERROR  */
  YYSYMBOL_BIF_MAX = 102,                  /* BIF_MAX  */
  YYSYMBOL_BIF_MIN = 103,                  /* BIF_MIN  */
  YYSYMBOL_BIF_LOOKUP = 104,               /* BIF_LOOKUP  */
  YYSYMBOL_BIF_DATE = 105,                 /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 106,                 /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 107,            /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 108,                 /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 109,                 /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 110,               /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 111,                /* BIF_YEARS  */
  YYSYMBOL_BIF_EDITC = 112,                /* BIF_EDITC  */
  YYSYMBOL_BIF_EDITW = 113,                /* BIF_EDITW  */
  YYSYMBOL_BIF_REPLACE = 114,              /* BIF_REPLACE  */
  YYSYMBOL_BIF_CHECK = 115,                /* BIF_CHECK  */
  YYSYMBOL_BIF_CHECKR = 116,               /* BIF_CHECKR  */
  YYSYMBOL_IDENTIFIER = 117,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 118,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 119,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 120,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 121,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 122,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 123,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 124,                   /* RPAREN  */
  YYSYMBOL_COLON = 125,                    /* COLON  */
  YYSYMBOL_PLUS = 126,                     /* PLUS  */
  YYSYMBOL_MINUS = 127,                    /* MINUS  */
  YYSYMBOL_STAR = 128,                     /* STAR  */
  YYSYMBOL_SLASH = 129,                    /* SLASH  */
  YYSYMBOL_NE = 130,                       /* NE  */
  YYSYMBOL_LE = 131,                       /* LE  */
  YYSYMBOL_GE = 132,                       /* GE  */
  YYSYMBOL_LT = 133,                       /* LT  */
  YYSYMBOL_GT = 134,                       /* GT  */
  YYSYMBOL_YYACCEPT = 135,                 /* $accept  */
  YYSYMBOL_program = 136,                  /* program  */
  YYSYMBOL_statements_opt = 137,           /* statements_opt  */
  YYSYMBOL_statement_list = 138,           /* statement_list  */
  YYSYMBOL_statement = 139,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 140,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 141,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 142,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 143,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 144,              /* eval_target  */
  YYSYMBOL_eval_stmt = 145,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 146,           /* eval_corr_stmt  */
  YYSYMBOL_dsply_stmt = 147,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 148,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 149,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 150,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 151,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 152,            /* dcl_proc_stmt  */
  YYSYMBOL_pi_return_type = 153,           /* pi_return_type  */
  YYSYMBOL_pi_params = 154,                /* pi_params  */
  YYSYMBOL_pi_param = 155,                 /* pi_param  */
  YYSYMBOL_pr_params = 156,                /* pr_params  */
  YYSYMBOL_pr_param = 157,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 158,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 159,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 160,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 161,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 162,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 163,               /* clear_stmt  */
  YYSYMBOL_dcl_ds_stmt = 164,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 165,                /* ds_fields  */
  YYSYMBOL_ds_field = 166,                 /* ds_field  */
  YYSYMBOL_if_stmt = 167,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 168,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 169,            /* elseif_clause  */
  YYSYMBOL_else_clause = 170,              /* else_clause  */
  YYSYMBOL_dow_stmt = 171,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 172,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 173,                 /* for_stmt  */
  YYSYMBOL_select_stmt = 174,              /* select_stmt  */
  YYSYMBOL_when_clauses = 175,             /* when_clauses  */
  YYSYMBOL_when_clause = 176,              /* when_clause  */
  YYSYMBOL_other_clause = 177,             /* other_clause  */
  YYSYMBOL_iter_stmt = 178,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 179,               /* leave_stmt  */
  YYSYMBOL_expression = 180,               /* expression  */
  YYSYMBOL_or_expr = 181,                  /* or_expr  */
  YYSYMBOL_and_expr = 182,                 /* and_expr  */
  YYSYMBOL_not_expr = 183,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 184,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 185,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 186,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 187,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 188,             /* postfix_expr  */
  YYSYMBOL_primary_expr = 189,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 190,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 191,            /* call_arg_list  */
  YYSYMBOL_arg_list = 192                  /* arg_list  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2035

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  785

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   389


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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   164,   166,   174,   177,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   216,   220,   224,   228,   236,   240,   244,
     248,   252,   256,   261,   266,   271,   276,   281,   286,   291,
     295,   299,   303,   307,   311,   315,   319,   323,   332,   338,
     345,   349,   352,   358,   362,   371,   377,   386,   394,   400,
     406,   409,   416,   427,   447,   471,   498,   499,   500,   501,
     502,   507,   510,   518,   522,   526,   530,   534,   538,   542,
     546,   551,   555,   559,   563,   567,   571,   575,   579,   583,
     592,   595,   603,   607,   611,   615,   619,   623,   627,   631,
     636,   640,   644,   648,   652,   656,   660,   664,   668,   678,
     689,   699,   707,   715,   722,   732,   741,   750,   760,   770,
     778,   789,   792,   800,   804,   808,   812,   817,   821,   825,
     829,   838,   861,   862,   870,   879,   880,   886,   895,   904,
     914,   924,   934,   947,   966,   970,   977,   986,   987,   993,
     997,  1003,  1007,  1008,  1016,  1017,  1025,  1026,  1032,  1033,
    1038,  1043,  1048,  1053,  1058,  1066,  1067,  1072,  1080,  1081,
    1086,  1094,  1095,  1103,  1104,  1111,  1115,  1118,  1121,  1125,
    1129,  1132,  1135,  1138,  1141,  1144,  1147,  1150,  1153,  1156,
    1159,  1162,  1165,  1169,  1172,  1175,  1178,  1181,  1184,  1187,
    1190,  1193,  1197,  1201,  1204,  1207,  1210,  1213,  1216,  1219,
    1223,  1226,  1230,  1233,  1237,  1244,  1251,  1258,  1263,  1268,
    1273,  1277,  1281,  1284,  1287,  1290,  1293,  1300,  1301,  1305,
    1309,  1317,  1321
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
  "KW_DATE", "KW_TIME", "KW_TIMESTAMP", "KW_POINTER", "KW_NULL", "KW_DAYS",
  "KW_MONTHS", "KW_YEARS", "KW_CONST", "KW_INZ", "KW_DSPLY", "KW_EVAL",
  "KW_EVAL_CORR", "KW_RETURN", "KW_INLR", "KW_ON", "KW_IF", "KW_ELSEIF",
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
  "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL",
  "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS",
  "STAR", "SLASH", "NE", "LE", "GE", "LT", "GT", "$accept", "program",
  "statements_opt", "statement_list", "statement", "dcl_f_stmt",
  "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt",
  "dcl_pr_stmt", "dcl_proc_stmt", "pi_return_type", "pi_params",
  "pi_param", "pr_params", "pr_param", "monitor_stmt", "begsr_stmt",
  "exsr_stmt", "sorta_stmt", "reset_stmt", "clear_stmt", "dcl_ds_stmt",
  "ds_fields", "ds_field", "if_stmt", "elseif_clauses", "elseif_clause",
  "else_clause", "dow_stmt", "dou_stmt", "for_stmt", "select_stmt",
  "when_clauses", "when_clause", "other_clause", "iter_stmt", "leave_stmt",
  "expression", "or_expr", "and_expr", "not_expr", "comparison_expr",
  "additive_expr", "multiplicative_expr", "unary_expr", "postfix_expr",
  "primary_expr", "call_args_opt", "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-398)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-159)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,  -398,    77,    15,  -398,   -40,   -30,    20,    27,  1674,
     -46,    31,  1269,    33,  1674,  1674,  1674,    40,    29,    48,
      56,    58,    67,    69,    76,   104,   111,  -398,   127,   129,
     134,    45,  -398,  -398,  -398,  -398,    39,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
     228,    17,  1674,  -398,  -398,  -398,  -398,  1775,   130,   139,
     151,   159,   163,   166,   182,   191,   195,   200,   225,   244,
     247,   250,   268,   271,   272,   273,   274,   275,   276,   282,
     289,   291,   292,   293,   294,   297,   302,   303,   305,   307,
     312,   313,   314,   316,   317,   318,  -398,  -398,  -398,  1674,
    1876,   155,   290,   382,  -398,   194,    78,    -6,  -398,   365,
    -398,    62,   324,   325,  -398,   327,   418,   329,   330,   331,
     332,   408,  -398,  -398,  -398,   334,   336,   337,   338,   339,
     340,   153,    41,   345,  1674,  1674,    -8,   342,   343,   333,
     346,   350,   354,   355,   344,   347,   358,   359,   360,   361,
     194,  1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,
    1674,  1674,  1674,   351,   357,  1674,  1674,  1674,  1674,  1674,
     362,   363,   364,  1674,  1674,  1674,  1371,  1472,  1573,  1674,
    1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,   366,
     365,  -398,  1674,  1674,  1775,  1775,  1775,  1775,  1775,  1775,
    1775,  1775,  1775,  1775,   349,  1674,  1674,   367,  -398,   368,
    -398,  -398,  -398,  1674,  1674,   156,  -398,   466,  -398,  -398,
    -398,  -398,  -398,   419,   376,   377,   378,   383,   387,   -25,
     386,   389,  -398,  -398,   373,   394,   388,   399,   404,  -398,
    -398,  -398,   410,   411,   413,   414,   415,  -398,  -398,  -398,
    -398,   405,  -398,  -398,    84,    88,   117,   135,   147,   160,
     178,   188,   196,   205,   207,   209,  -398,  -398,   211,   213,
     216,   218,   220,  -398,  -398,  -398,   222,   226,   229,  -398,
     231,  -398,   233,  -398,   235,   420,   412,   416,   422,   237,
     239,   241,   257,   259,  -398,   423,  -398,   382,  -398,    78,
      78,    78,    78,    78,    78,    -6,    -6,  -398,  -398,  -398,
     373,   427,   428,  -398,   190,   537,   598,   335,   429,   430,
    -398,   488,   431,  -398,   669,    11,   421,   426,   435,   437,
    -398,   433,  -398,   439,   441,    53,   481,   440,  1674,  -398,
     434,   444,   446,   447,   452,   453,   448,  -398,  1674,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  1674,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,   352,   458,   459,  1674,  1674,  -398,  -398,
     461,  -398,   463,   153,   467,   465,   469,   474,   475,    34,
     473,    61,   482,   483,   489,   492,   186,  -398,   494,  -398,
    -398,   487,    60,   -12,    80,   496,   497,   495,  -398,   493,
    1674,   498,  -398,   582,  -398,  -398,   -39,   -31,   251,   730,
    -398,   791,  -398,   499,  -398,  -398,  -398,  -398,   503,   501,
     506,    26,  -398,   505,   510,   559,   -13,  -398,   219,   515,
     516,   517,   518,  -398,   521,   608,   520,   522,   523,   527,
     529,   538,   636,   540,   541,   544,   543,   547,  -398,   246,
     551,  -398,   555,  1674,  -398,  1674,  -398,   556,  -398,    42,
     554,  -398,   252,   545,   557,   558,   560,   561,   564,  -398,
     565,   566,  -398,   567,   568,   569,   570,   576,   584,   585,
     586,   563,   577,  1674,   589,  -398,  1674,   591,  -398,   587,
    1674,   593,  -398,    82,  -398,   588,   590,   592,  -398,   852,
    -398,   599,   913,   600,   974,  -398,    43,   604,   562,    44,
    -398,  -398,   607,   609,   615,   616,   623,   624,   625,   626,
     571,  -398,  -398,   627,   628,   629,   630,   631,   637,   639,
     640,   643,   632,  1674,   641,   646,   647,   648,  1674,   649,
     651,   657,   653,   658,   633,   634,  -398,  -398,  -398,   374,
    -398,   661,  -398,   663,   670,  -398,   280,   676,   677,   679,
     680,   681,   675,   687,   688,   689,   684,   685,   686,   690,
     692,    75,    86,   698,   700,   701,   702,   704,   691,   693,
     710,   695,  -398,   708,   712,   713,   715,   716,   714,   721,
     724,   729,  1674,   736,  -398,  -398,  1035,  -398,  1096,  -398,
    -398,  1157,   737,   738,   740,   741,   747,   748,   749,   750,
     635,   745,   746,   751,   752,   -52,   -24,   -22,   753,   755,
     762,   764,   765,   769,   771,   772,   754,  -398,  -398,  -398,
     770,   774,  -398,  -398,  -398,  -398,   776,  -398,  -398,  1674,
     775,   779,   777,   783,  1228,   785,   756,   795,   797,   803,
     798,   800,   801,   802,   804,   -10,    -4,    -3,   808,   809,
    -398,   810,  -398,   811,  -398,   805,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,   812,   813,  -398,  -398,   814,   816,   823,
    -398,  -398,   825,  -398,   824,   827,   830,   822,     8,    10,
      18,   815,   834,   835,  -398,   837,  -398,   838,  -398,   836,
    -398,  -398,  -398,    19,   843,  -398,   844,  -398,  -398,  -398,
      21,    22,    24,   817,   846,  -398,   853,  -398,   855,  -398,
     858,  -398,  -398,  -398,  -398,    25,   862,  -398,  -398,  -398,
     864,  -398,   865,  -398,   866,  -398,   867,  -398,  -398,  -398,
      28,   868,  -398,  -398,  -398,  -398,  -398,    32,   869,  -398,
    -398,   871,  -398,  -398,  -398
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,    60,     4,     7,     8,     9,     0,    10,    11,    12,
      13,    14,    31,    23,    22,    25,    26,    27,    30,    28,
      29,    24,    15,    16,    17,    18,    19,    20,    21,    32,
       0,     0,     0,   235,   233,   234,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,     0,
       0,     0,   161,   162,   164,   166,   168,   175,   178,   181,
     183,    60,     0,     0,    71,     0,     0,     0,     0,     0,
       0,     0,   159,   160,     5,     0,     0,     0,     0,     0,
       0,    76,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,     0,
     182,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       5,     5,     5,     0,     0,   157,   154,     0,     5,   121,
     123,   124,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,    62,   239,     0,   238,     0,     0,    33,
      34,    35,     0,     0,     0,     0,     0,    49,    50,    51,
      52,     0,    59,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,     0,     0,
       0,     0,     0,   202,   211,   212,     0,     0,     0,   219,
       0,   221,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,   236,   163,   165,   169,
     170,   173,   174,   171,   172,   176,   177,   179,   180,   184,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     6,     0,    76,     0,     0,     0,     0,
     100,     0,   131,     0,     0,     0,    63,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     215,   216,   217,   213,   214,   209,   210,   203,   218,   220,
     222,     0,   227,   228,   229,   204,   205,   206,   207,   208,
     189,    66,    67,   145,     0,     0,     0,     0,     5,     5,
       0,     5,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,     0,    72,
     240,     0,    58,    58,    58,     0,     0,     0,   242,     0,
       0,     0,   143,     0,   147,   148,     0,     0,     0,     0,
     153,     0,   120,     0,    81,    78,    79,    77,     0,     0,
       0,     0,   101,     0,     0,     0,     0,   126,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     5,     0,     0,     5,     0,     5,     0,    81,     0,
       0,    73,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,    38,     0,
       0,     0,    39,    58,    58,     0,     0,     0,     5,     0,
     141,     0,     0,     0,     0,   119,     0,     0,     0,     0,
      82,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,   225,   226,     0,
       5,     0,     5,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,   149,     0,   151,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   133,
       0,     0,    46,    54,    48,    55,     0,    45,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,   106,     0,   102,     0,   118,   128,   127,   130,
     138,   139,   137,     0,     0,    43,    42,     0,     0,     0,
     150,   152,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,   114,     0,   110,     0,
     105,   107,   103,     0,     0,   136,     0,    47,    56,    75,
       0,     0,     0,     0,     0,    85,     0,    87,     0,    83,
       0,    99,   113,   115,   111,     0,     0,   108,   140,    44,
       0,    93,     0,    95,     0,    91,     0,    86,    88,    84,
       0,     0,   116,   109,    94,    96,    92,     0,     0,    89,
     117,     0,    97,    90,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -398,  -398,  -398,  -211,   870,  -398,  -398,  -397,  -398,   978,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -327,   262,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -341,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,   526,  -398,  -398,  -398,    -9,  -398,   792,   790,   744,
     -33,   179,   180,   885,  -398,   799,  -398,  1838
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   227,   333,    33,    34,   468,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,   238,   489,
     540,   409,   452,    45,    46,    47,    48,    49,    50,    51,
     345,   417,    52,   393,   432,   433,    53,    54,    55,    56,
     225,   226,   331,    57,    58,   263,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   245,   246,   264
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   411,   248,   125,   483,   127,   128,   129,   404,   324,
     325,   326,   485,   469,    27,    -2,     5,   334,   689,     6,
       7,     8,   234,   235,   236,   237,   471,   475,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   493,   494,   495,
     496,     9,    10,    11,    12,    13,   691,    14,   693,   341,
       1,    15,    16,   159,    17,   587,   588,   589,   590,    18,
     723,   501,   470,    19,    20,    21,   725,   727,    22,   690,
      23,   121,    24,    25,    26,    27,   443,     4,   744,    28,
     746,    59,   484,    29,   465,   466,    30,    60,   748,   756,
     486,   760,   762,   158,   764,   771,   342,   692,   778,   694,
     199,   497,   781,   449,   472,   473,   571,   572,   502,   537,
     584,   724,   450,   249,   239,   240,   241,   726,   728,   591,
     538,   538,   212,   213,   143,   414,   574,   575,   403,   745,
     415,   747,    31,   454,   467,   244,   247,    61,   415,   749,
     757,   143,   761,   763,    62,   765,   772,   650,   123,   779,
     131,   451,   415,   782,   474,   126,   573,   130,   651,   539,
     539,   145,   242,   415,   234,   235,   236,   237,   144,   132,
     416,   309,   310,   311,   312,   313,   314,   133,   416,   134,
     295,   296,   297,   298,   135,   215,   136,   438,   439,   304,
     441,     5,   416,   137,     6,     7,     8,   459,   460,   461,
     462,   224,   329,   416,   210,   211,   320,   321,   357,   358,
     601,   602,   359,   358,   327,   328,     9,    10,    11,    12,
      13,   138,    14,  -142,  -142,  -142,    15,    16,   139,    17,
     503,   504,   505,   506,    18,   146,   147,   148,    19,    20,
      21,   360,   358,    22,   140,    23,   141,    24,    25,    26,
      27,   142,     5,   161,    28,     6,     7,     8,    29,   361,
     358,    30,   162,   542,   543,   544,   545,   525,   526,   527,
     529,   362,   358,   532,   163,   534,   201,     9,    10,    11,
      12,    13,   164,    14,   363,   358,   165,    15,    16,   166,
      17,   632,   633,   634,   635,    18,  -156,  -156,  -156,    19,
      20,    21,   364,   358,    22,   167,    23,    31,    24,    25,
      26,    27,   365,   358,   168,    28,   204,   579,   169,    29,
     366,   358,    30,   170,   205,   206,   207,   208,   209,   367,
     358,   368,   358,   369,   358,   370,   358,   371,   358,   420,
     372,   358,   373,   358,   374,   358,   375,   358,   171,   428,
     376,   358,   202,   377,   358,   378,   358,   379,   358,   380,
     358,   385,   358,   386,   358,   387,   358,   172,    31,   626,
     173,   628,   429,   174,   631,     5,   396,   397,     6,     7,
       8,   388,   358,   389,   358,   430,   431,   436,   437,   315,
     316,   175,   317,   318,   176,   177,   178,   179,   180,   181,
       9,    10,    11,    12,    13,   182,    14,  -144,  -144,  -144,
      15,    16,   183,    17,   184,   185,   186,   187,    18,   674,
     188,   480,    19,    20,    21,   189,   190,    22,   191,    23,
     192,    24,    25,    26,    27,   193,   194,   195,    28,   196,
     197,   198,    29,   203,   214,    30,   216,   217,   218,   219,
     220,   221,   222,   224,   223,   228,   252,   229,   230,   231,
     232,   233,   243,   250,   251,   257,   319,     5,   258,   253,
       6,     7,     8,   254,   531,   276,   533,   255,   256,   259,
     260,   277,   262,   261,   322,   335,   283,   284,   285,   323,
     306,    31,     9,    10,    11,    12,    13,   346,    14,   336,
     337,   338,    15,    16,   564,    17,   339,   566,   340,   343,
      18,   569,   344,   348,    19,    20,    21,   332,   347,    22,
     349,    23,   356,    24,    25,    26,    27,   350,   351,   352,
      28,   353,   354,   355,    29,   400,   382,    30,     5,   405,
     383,     6,     7,     8,   406,   381,   384,   390,   391,   392,
     398,   399,   401,   407,   613,   408,   410,   412,   413,   618,
     418,   419,   421,     9,    10,    11,    12,    13,   422,    14,
     423,   424,   427,    15,    16,   394,    17,   425,   426,   434,
     435,    18,   440,    31,   442,    19,    20,    21,   444,   445,
      22,   453,    23,   446,    24,    25,    26,    27,   447,     5,
     448,    28,     6,     7,     8,    29,   455,   456,    30,   458,
     457,   463,   464,   670,   476,   477,   478,   482,   479,   481,
     488,   490,   491,   492,     9,    10,    11,    12,    13,   498,
      14,   499,   500,   512,    15,    16,   395,    17,   507,   508,
     509,   510,    18,   513,   515,   514,    19,    20,    21,   511,
     516,    22,   517,    23,    31,    24,    25,    26,    27,   518,
     707,   519,    28,   520,   521,   522,    29,   523,   546,    30,
       5,   524,   528,     6,     7,     8,   530,   535,   541,   586,
     547,   548,   621,   549,   550,   551,   552,   562,   600,   553,
     554,   555,   556,   557,   558,     9,    10,    11,    12,    13,
     563,    14,   559,   560,   561,    15,    16,   565,    17,   567,
     568,   570,   576,    18,   577,    31,   578,    19,    20,    21,
     580,   582,    22,   402,    23,   585,    24,    25,    26,    27,
     592,     5,   593,    28,     6,     7,     8,    29,   594,   595,
      30,   596,   597,   598,   599,   603,   604,   605,   606,   607,
     536,   330,   684,   612,   624,   625,     9,    10,    11,    12,
      13,   608,    14,   609,   610,   614,    15,    16,   611,    17,
     615,   616,   617,   619,    18,   620,   622,  -158,    19,    20,
      21,   623,   627,    22,   629,    23,    31,    24,    25,    26,
      27,   630,     5,   641,    28,     6,     7,     8,    29,   636,
     637,    30,   638,   639,   640,   642,   643,   644,   645,   646,
     647,   160,   657,   660,   658,   648,   649,     9,    10,    11,
      12,    13,   652,    14,   653,   654,   655,    15,    16,   656,
      17,   659,   661,   662,   663,    18,   664,   665,   666,    19,
      20,    21,   667,   487,    22,   668,    23,    31,    24,    25,
      26,    27,   669,     5,   671,    28,     6,     7,     8,    29,
     676,   677,    30,   678,   679,   680,   681,   682,   683,   685,
     686,   695,   703,    32,   714,   687,   696,   688,     9,    10,
      11,    12,    13,   697,    14,   698,   699,  -146,    15,    16,
     700,    17,   701,   702,   704,   705,    18,   706,   710,   708,
      19,    20,    21,   709,   711,    22,   713,    23,    31,    24,
      25,    26,    27,   715,     5,   716,    28,     6,     7,     8,
      29,   717,   718,    30,   719,   720,   729,   721,   722,   733,
     730,   731,   732,   750,   735,   766,   734,   737,   736,     9,
      10,    11,    12,    13,   738,    14,   739,   743,   740,    15,
      16,   741,    17,   581,   742,   751,   752,    18,   753,   754,
     755,    19,    20,    21,   758,   759,    22,   767,    23,    31,
      24,    25,    26,    27,   768,     5,   769,    28,     6,     7,
       8,    29,   770,   773,    30,   774,   775,   776,   122,   780,
     783,   777,   784,   308,   307,   200,     0,   305,     0,     0,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
      15,    16,     0,    17,   583,     0,     0,     0,    18,     0,
       0,     0,    19,    20,    21,     0,     0,    22,     0,    23,
      31,    24,    25,    26,    27,     0,     5,     0,    28,     6,
       7,     8,    29,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,    13,     0,    14,     0,     0,
       0,    15,    16,     0,    17,   672,     0,     0,     0,    18,
       0,     0,     0,    19,    20,    21,     0,     0,    22,     0,
      23,    31,    24,    25,    26,    27,     0,     5,     0,    28,
       6,     7,     8,    29,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,    13,     0,    14,     0,
       0,     0,    15,    16,     0,    17,   673,     0,     0,     0,
      18,     0,     0,     0,    19,    20,    21,     0,     0,    22,
       0,    23,    31,    24,    25,    26,    27,     0,     5,     0,
      28,     6,     7,     8,    29,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,     0,    14,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
       0,    18,     0,     0,     0,    19,    20,    21,     0,     0,
      22,     0,    23,    31,    24,    25,    26,    27,     0,     0,
       0,    28,   675,     0,     0,    29,     0,     0,    30,     5,
       0,     0,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    10,    11,    12,    13,     0,
      14,     0,     0,     0,    15,    16,     0,    17,     0,     0,
       0,     0,    18,     0,    31,     0,    19,    20,    21,     0,
       0,    22,     0,    23,     0,    24,    25,    26,    27,    63,
       0,     0,    28,   712,     0,     0,    29,     0,     0,    30,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    66,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     124,    63,   109,     0,     0,     0,   110,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,    66,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    63,     0,   109,   289,     0,     0,   110,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,    66,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    63,     0,   109,   291,     0,     0,   110,
       0,     0,     0,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,    66,     0,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    63,     0,   109,   293,     0,     0,
     110,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,    66,     0,     0,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    63,     0,   109,     0,     0,
       0,   110,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    63,     0,   109,     0,
       0,     0,   110,     0,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   109,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,     0,     0,   278,   279,   280,   281,   282,     0,     0,
       0,   286,   287,   288,   290,   292,   294,     0,     0,     0,
       0,   299,   300,   301,   302,   303
};

static const yytype_int16 yycheck[] =
{
       9,   342,    10,    12,    43,    14,    15,    16,   335,   220,
     221,   222,    43,    25,    60,     0,     1,   228,    70,     4,
       5,     6,    11,    12,    13,    14,   423,   424,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    11,    12,    13,
      14,    26,    27,    28,    29,    30,    70,    32,    70,    74,
       3,    36,    37,    62,    39,    11,    12,    13,    14,    44,
      70,    74,    74,    48,    49,    50,    70,    70,    53,   121,
      55,   117,    57,    58,    59,    60,   403,     0,    70,    64,
      70,   121,   121,    68,    24,    25,    71,   117,    70,    70,
     121,    70,    70,    76,    70,    70,   121,   121,    70,   121,
     109,    75,    70,    69,    24,    25,    24,    25,   121,    67,
      67,   121,    78,   121,    73,    74,    75,   121,   121,    75,
      78,    78,   128,   129,    79,    72,   523,   524,   117,   121,
      77,   121,   117,    72,    74,   144,   145,   117,    77,   121,
     121,    79,   121,   121,   117,   121,   121,    72,   117,   121,
     121,   117,    77,   121,    74,   122,    74,   117,    72,   117,
     117,   122,   121,    77,    11,    12,    13,    14,   123,   121,
     117,   204,   205,   206,   207,   208,   209,   121,   117,   121,
     189,   190,   191,   192,   117,   123,   117,   398,   399,   198,
     401,     1,   117,   117,     4,     5,     6,    11,    12,    13,
      14,    45,    46,   117,   126,   127,   215,   216,   124,   125,
     551,   552,   124,   125,   223,   224,    26,    27,    28,    29,
      30,   117,    32,    33,    34,    35,    36,    37,   117,    39,
      11,    12,    13,    14,    44,     7,     8,     9,    48,    49,
      50,   124,   125,    53,   117,    55,   117,    57,    58,    59,
      60,   117,     1,   123,    64,     4,     5,     6,    68,   124,
     125,    71,   123,    11,    12,    13,    14,    21,    22,    23,
     481,   124,   125,   484,   123,   486,   121,    26,    27,    28,
      29,    30,   123,    32,   124,   125,   123,    36,    37,   123,
      39,    11,    12,    13,    14,    44,    45,    46,    47,    48,
      49,    50,   124,   125,    53,   123,    55,   117,    57,    58,
      59,    60,   124,   125,   123,    64,   122,   528,   123,    68,
     124,   125,    71,   123,   130,   131,   132,   133,   134,   124,
     125,   124,   125,   124,   125,   124,   125,   124,   125,   348,
     124,   125,   124,   125,   124,   125,   124,   125,   123,   358,
     124,   125,    62,   124,   125,   124,   125,   124,   125,   124,
     125,   124,   125,   124,   125,   124,   125,   123,   117,   580,
     123,   582,   381,   123,   585,     1,    41,    42,     4,     5,
       6,   124,   125,   124,   125,    33,    34,   396,   397,   210,
     211,   123,   212,   213,   123,   123,   123,   123,   123,   123,
      26,    27,    28,    29,    30,   123,    32,    33,    34,    35,
      36,    37,   123,    39,   123,   123,   123,   123,    44,   630,
     123,   430,    48,    49,    50,   123,   123,    53,   123,    55,
     123,    57,    58,    59,    60,   123,   123,   123,    64,   123,
     123,   123,    68,    61,    79,    71,   122,   122,   121,    31,
     121,   121,   121,    45,   122,   121,   123,   121,   121,   121,
     121,   121,   117,   121,   121,   121,   117,     1,   121,   123,
       4,     5,     6,   123,   483,   124,   485,   123,   123,   121,
     121,   124,   121,   123,   117,    66,   124,   124,   124,   121,
     124,   117,    26,    27,    28,    29,    30,   124,    32,   123,
     123,   123,    36,    37,   513,    39,   123,   516,   121,   123,
      44,   520,   123,   125,    48,    49,    50,    51,   124,    53,
     121,    55,   117,    57,    58,    59,    60,   123,   118,   118,
      64,   118,   118,   118,    68,    47,   124,    71,     1,   118,
     124,     4,     5,     6,   118,   125,   124,   124,   121,   121,
     121,   121,   121,   118,   563,   118,   123,   118,   117,   568,
      79,   121,   128,    26,    27,    28,    29,    30,   124,    32,
     124,   124,   124,    36,    37,    38,    39,   125,   125,   121,
     121,    44,   121,   117,   121,    48,    49,    50,   121,   124,
      53,   118,    55,   124,    57,    58,    59,    60,   124,     1,
     125,    64,     4,     5,     6,    68,   124,   124,    71,   117,
     121,   117,   125,   622,   118,   118,   121,    35,   125,   121,
     121,   118,   121,   117,    26,    27,    28,    29,    30,   124,
      32,   121,    73,    25,    36,    37,    38,    39,   123,   123,
     123,   123,    44,   123,   121,   123,    48,    49,    50,   128,
     123,    53,   123,    55,   117,    57,    58,    59,    60,   121,
     669,    25,    64,   123,   123,   121,    68,   124,   123,    71,
       1,   124,   121,     4,     5,     6,   121,   121,   124,   117,
     123,   123,    25,   123,   123,   121,   121,   124,   117,   123,
     123,   123,   123,   123,   118,    26,    27,    28,    29,    30,
     123,    32,   118,   118,   118,    36,    37,   118,    39,   118,
     123,   118,   124,    44,   124,   117,   124,    48,    49,    50,
     121,   121,    53,    54,    55,   121,    57,    58,    59,    60,
     123,     1,   123,    64,     4,     5,     6,    68,   123,   123,
      71,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     488,   225,   117,   121,   121,   121,    26,    27,    28,    29,
      30,   124,    32,   124,   124,   124,    36,    37,   125,    39,
     124,   124,   124,   124,    44,   124,   123,    47,    48,    49,
      50,   123,   121,    53,   121,    55,   117,    57,    58,    59,
      60,   121,     1,   118,    64,     4,     5,     6,    68,   123,
     123,    71,   123,   123,   123,   118,   118,   118,   124,   124,
     124,    67,   121,   118,   121,   125,   124,    26,    27,    28,
      29,    30,   124,    32,   124,   124,   124,    36,    37,   125,
      39,   121,   124,   121,   121,    44,   121,   121,   124,    48,
      49,    50,   121,    52,    53,   121,    55,   117,    57,    58,
      59,    60,   123,     1,   118,    64,     4,     5,     6,    68,
     123,   123,    71,   123,   123,   118,   118,   118,   118,   124,
     124,   118,   118,     3,   118,   124,   121,   125,    26,    27,
      28,    29,    30,   121,    32,   121,   121,    35,    36,    37,
     121,    39,   121,   121,   124,   121,    44,   121,   121,   124,
      48,    49,    50,   124,   121,    53,   121,    55,   117,    57,
      58,    59,    60,   118,     1,   118,    64,     4,     5,     6,
      68,   118,   124,    71,   124,   124,   118,   125,   124,   124,
     121,   121,   121,   118,   121,   118,   124,   121,   124,    26,
      27,    28,    29,    30,   121,    32,   121,   125,   124,    36,
      37,   124,    39,    40,   124,   121,   121,    44,   121,   121,
     124,    48,    49,    50,   121,   121,    53,   121,    55,   117,
      57,    58,    59,    60,   121,     1,   121,    64,     4,     5,
       6,    68,   124,   121,    71,   121,   121,   121,    10,   121,
     121,   124,   121,   203,   202,   110,    -1,   198,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      36,    37,    -1,    39,    40,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    53,    -1,    55,
     117,    57,    58,    59,    60,    -1,     1,    -1,    64,     4,
       5,     6,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    -1,    39,    40,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,    -1,
      55,   117,    57,    58,    59,    60,    -1,     1,    -1,    64,
       4,     5,     6,    68,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,    -1,    39,    40,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,
      -1,    55,   117,    57,    58,    59,    60,    -1,     1,    -1,
      64,     4,     5,     6,    68,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    -1,    39,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    55,   117,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    -1,    -1,    68,    -1,    -1,    71,     1,
      -1,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    36,    37,    -1,    39,    -1,    -1,
      -1,    -1,    44,    -1,   117,    -1,    48,    49,    50,    -1,
      -1,    53,    -1,    55,    -1,    57,    58,    59,    60,    20,
      -1,    -1,    64,    65,    -1,    -1,    68,    -1,    -1,    71,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    20,   123,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    20,    -1,   123,   124,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    20,    -1,   123,   124,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    20,    -1,   123,   124,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    20,    -1,   123,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    20,    -1,   123,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,   123,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,   175,   176,   177,   178,   179,    -1,    -1,
      -1,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,   197
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   136,   137,     0,     1,     4,     5,     6,    26,
      27,    28,    29,    30,    32,    36,    37,    39,    44,    48,
      49,    50,    53,    55,    57,    58,    59,    60,    64,    68,
      71,   117,   139,   140,   141,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   158,   159,   160,   161,   162,
     163,   164,   167,   171,   172,   173,   174,   178,   179,   121,
     117,   117,   117,    20,    31,    56,    60,    63,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   123,
     127,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   117,   144,   117,   121,   180,   122,   180,   180,   180,
     117,   121,   121,   121,   121,   117,   117,   117,   117,   117,
     117,   117,   117,    79,   123,   122,     7,     8,     9,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    76,   180,
     184,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   180,
     188,   121,    62,    61,   122,   130,   131,   132,   133,   134,
     126,   127,   128,   129,    79,   123,   122,   122,   121,    31,
     121,   121,   121,   122,    45,   175,   176,   138,   121,   121,
     121,   121,   121,   121,    11,    12,    13,    14,   153,    73,
      74,    75,   121,   117,   180,   190,   191,   180,    10,   121,
     121,   121,   123,   123,   123,   123,   123,   121,   121,   121,
     121,   123,   121,   180,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   124,   124,   192,   192,
     192,   192,   192,   124,   124,   124,   192,   192,   192,   124,
     192,   124,   192,   124,   192,   180,   180,   180,   180,   192,
     192,   192,   192,   192,   180,   190,   124,   182,   183,   185,
     185,   185,   185,   185,   185,   186,   186,   187,   187,   117,
     180,   180,   117,   121,   138,   138,   138,   180,   180,    46,
     176,   177,    51,   139,   138,    66,   123,   123,   123,   123,
     121,    74,   121,   123,   123,   165,   124,   124,   125,   121,
     123,   118,   118,   118,   118,   118,   117,   124,   125,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   121,   121,   168,    38,    38,    41,    42,   121,   121,
      47,   121,    54,   117,   153,   118,   118,   118,   118,   156,
     123,   165,   118,   117,    72,    77,   117,   166,    79,   121,
     180,   128,   124,   124,   124,   125,   125,   124,   180,   180,
      33,    34,   169,   170,   121,   121,   180,   180,   138,   138,
     121,   138,   121,   153,   121,   124,   124,   124,   125,    69,
      78,   117,   157,   118,    72,   124,   124,   121,   117,    11,
      12,    13,    14,   117,   125,    24,    25,    74,   142,    25,
      74,   142,    24,    25,    74,   142,   118,   118,   121,   125,
     180,   121,    35,    43,   121,    43,   121,    52,   121,   154,
     118,   121,   117,    11,    12,    13,    14,    75,   124,   121,
      73,    74,   121,    11,    12,    13,    14,   123,   123,   123,
     123,   128,    25,   123,   123,   121,   123,   123,   121,    25,
     123,   123,   121,   124,   124,    21,    22,    23,   121,   138,
     121,   180,   138,   180,   138,   121,   154,    67,    78,   117,
     155,   124,    11,    12,    13,    14,   123,   123,   123,   123,
     123,   121,   121,   123,   123,   123,   123,   123,   118,   118,
     118,   118,   124,   123,   180,   118,   180,   118,   123,   180,
     118,    24,    25,    74,   142,   142,   124,   124,   124,   138,
     121,    40,   121,    40,    67,   121,   117,    11,    12,    13,
      14,    75,   123,   123,   123,   123,   118,   118,   118,   118,
     117,   165,   165,   118,   118,   118,   118,   118,   124,   124,
     124,   125,   121,   180,   124,   124,   124,   124,   180,   124,
     124,    25,   123,   123,   121,   121,   138,   121,   138,   121,
     121,   138,    11,    12,    13,    14,   123,   123,   123,   123,
     123,   118,   118,   118,   118,   124,   124,   124,   125,   124,
      72,    72,   124,   124,   124,   124,   125,   121,   121,   121,
     118,   124,   121,   121,   121,   121,   124,   121,   121,   123,
     180,   118,    40,    40,   138,    65,   123,   123,   123,   123,
     118,   118,   118,   118,   117,   124,   124,   124,   125,    70,
     121,    70,   121,    70,   121,   118,   121,   121,   121,   121,
     121,   121,   121,   118,   124,   121,   121,   180,   124,   124,
     121,   121,    65,   121,   118,   118,   118,   118,   124,   124,
     124,   125,   124,    70,   121,    70,   121,    70,   121,   118,
     121,   121,   121,   124,   124,   121,   124,   121,   121,   121,
     124,   124,   124,   125,    70,   121,    70,   121,    70,   121,
     118,   121,   121,   121,   121,   124,    70,   121,   121,   121,
      70,   121,    70,   121,    70,   121,   118,   121,   121,   121,
     124,    70,   121,   121,   121,   121,   121,   124,    70,   121,
     121,    70,   121,   121,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   135,   136,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   143,
     144,   144,   144,   144,   144,   145,   145,   146,   147,   148,
     149,   149,   150,   151,   152,   152,   153,   153,   153,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   156,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   158,
     159,   160,   161,   162,   163,   164,   164,   164,   164,   164,
     164,   165,   165,   166,   166,   166,   166,   166,   166,   166,
     166,   167,   168,   168,   169,   170,   170,   171,   172,   173,
     173,   173,   173,   174,   175,   175,   176,   177,   177,   178,
     179,   180,   181,   181,   182,   182,   183,   183,   184,   184,
     184,   184,   184,   184,   184,   185,   185,   185,   186,   186,
     186,   187,   187,   188,   188,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   190,   190,   191,
     191,   192,   192
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,    10,     8,     8,     8,
      10,    10,    12,    12,    14,    11,    11,    13,    11,     4,
       4,     4,     4,    11,    11,    11,    13,     7,     0,     4,
       1,     1,     3,     4,     6,     4,     5,     5,     3,     4,
       3,     2,     5,     7,    12,    13,     0,     4,     4,     4,
       6,     0,     2,     6,     7,     6,     7,     6,     7,     8,
       9,     7,     8,     7,     8,     7,     8,     9,    10,     6,
       0,     2,     6,     7,     6,     7,     6,     7,     8,     9,
       7,     8,     7,     8,     7,     8,     9,    10,     6,     8,
       6,     3,     3,     3,     3,     7,     6,    11,    11,     7,
      11,     0,     2,     6,     6,     6,     8,     7,     7,     7,
       9,     8,     0,     2,     4,     0,     3,     6,     6,    10,
      12,    10,    12,     6,     1,     2,     4,     0,     3,     2,
       2,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     3,     4,     4,     4,     4,     4,     4,     3,
       4,     3,     4,     3,     8,     8,     8,     4,     4,     4,
       3,     3,     1,     1,     1,     1,     3,     0,     1,     1,
       3,     1,     3
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
#line 159 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 2051 "build/parser.cpp"
    break;

  case 4: /* statements_opt: statements_opt statement  */
#line 166 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 2061 "build/parser.cpp"
    break;

  case 5: /* statement_list: %empty  */
#line 174 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 2069 "build/parser.cpp"
    break;

  case 6: /* statement_list: statement_list statement  */
#line 177 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 2080 "build/parser.cpp"
    break;

  case 7: /* statement: dcl_f_stmt  */
#line 186 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2086 "build/parser.cpp"
    break;

  case 8: /* statement: dcl_s_stmt  */
#line 187 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2092 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_c_stmt  */
#line 188 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2098 "build/parser.cpp"
    break;

  case 10: /* statement: eval_stmt  */
#line 189 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2104 "build/parser.cpp"
    break;

  case 11: /* statement: eval_corr_stmt  */
#line 190 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2110 "build/parser.cpp"
    break;

  case 12: /* statement: dsply_stmt  */
#line 191 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2116 "build/parser.cpp"
    break;

  case 13: /* statement: inlr_stmt  */
#line 192 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2122 "build/parser.cpp"
    break;

  case 14: /* statement: return_stmt  */
#line 193 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2128 "build/parser.cpp"
    break;

  case 15: /* statement: if_stmt  */
#line 194 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2134 "build/parser.cpp"
    break;

  case 16: /* statement: dow_stmt  */
#line 195 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2140 "build/parser.cpp"
    break;

  case 17: /* statement: dou_stmt  */
#line 196 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2146 "build/parser.cpp"
    break;

  case 18: /* statement: for_stmt  */
#line 197 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2152 "build/parser.cpp"
    break;

  case 19: /* statement: select_stmt  */
#line 198 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2158 "build/parser.cpp"
    break;

  case 20: /* statement: iter_stmt  */
#line 199 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2164 "build/parser.cpp"
    break;

  case 21: /* statement: leave_stmt  */
#line 200 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2170 "build/parser.cpp"
    break;

  case 22: /* statement: dcl_proc_stmt  */
#line 201 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2176 "build/parser.cpp"
    break;

  case 23: /* statement: dcl_pr_stmt  */
#line 202 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2182 "build/parser.cpp"
    break;

  case 24: /* statement: dcl_ds_stmt  */
#line 203 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2188 "build/parser.cpp"
    break;

  case 25: /* statement: monitor_stmt  */
#line 204 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2194 "build/parser.cpp"
    break;

  case 26: /* statement: begsr_stmt  */
#line 205 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2200 "build/parser.cpp"
    break;

  case 27: /* statement: exsr_stmt  */
#line 206 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2206 "build/parser.cpp"
    break;

  case 28: /* statement: reset_stmt  */
#line 207 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2212 "build/parser.cpp"
    break;

  case 29: /* statement: clear_stmt  */
#line 208 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2218 "build/parser.cpp"
    break;

  case 30: /* statement: sorta_stmt  */
#line 209 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2224 "build/parser.cpp"
    break;

  case 31: /* statement: expr_stmt  */
#line 210 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2230 "build/parser.cpp"
    break;

  case 32: /* statement: error SEMICOLON  */
#line 211 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 2236 "build/parser.cpp"
    break;

  case 33: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 216 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 2245 "build/parser.cpp"
    break;

  case 34: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 220 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 2254 "build/parser.cpp"
    break;

  case 35: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 224 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 2263 "build/parser.cpp"
    break;

  case 36: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 228 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 2272 "build/parser.cpp"
    break;

  case 37: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 236 "src/parser.y"
                                                                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        free((yyvsp[-6].sval));
    }
#line 2281 "build/parser.cpp"
    break;

  case 38: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 240 "src/parser.y"
                                                                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        free((yyvsp[-6].sval));
    }
#line 2290 "build/parser.cpp"
    break;

  case 39: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 244 "src/parser.y"
                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        free((yyvsp[-6].sval));
    }
#line 2299 "build/parser.cpp"
    break;

  case 40: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 248 "src/parser.y"
                                                                                                                 {
        (yyval.stmt) = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        free((yyvsp[-8].sval));
    }
#line 2308 "build/parser.cpp"
    break;

  case 41: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 252 "src/parser.y"
                                                                                                                {
        (yyval.stmt) = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        free((yyvsp[-8].sval));
    }
#line 2317 "build/parser.cpp"
    break;

  case 42: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 256 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2327 "build/parser.cpp"
    break;

  case 43: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 261 "src/parser.y"
                                                                                                                   {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2337 "build/parser.cpp"
    break;

  case 44: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 266 "src/parser.y"
                                                                                                                                           {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 2347 "build/parser.cpp"
    break;

  case 45: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 271 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2357 "build/parser.cpp"
    break;

  case 46: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 276 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2367 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 281 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 2377 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 286 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2387 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_DATE SEMICOLON  */
#line 291 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 2396 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIME SEMICOLON  */
#line 295 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 2405 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIMESTAMP SEMICOLON  */
#line 299 "src/parser.y"
                                                 {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 2414 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_POINTER SEMICOLON  */
#line 303 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 2423 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 307 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 2432 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 311 "src/parser.y"
                                                                                                               {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 2441 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 315 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 2450 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 319 "src/parser.y"
                                                                                                                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 2459 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 323 "src/parser.y"
                                                                     {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 2471 "build/parser.cpp"
    break;

  case 59: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 338 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 2480 "build/parser.cpp"
    break;

  case 60: /* eval_target: IDENTIFIER  */
#line 345 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 2489 "build/parser.cpp"
    break;

  case 61: /* eval_target: INDICATOR  */
#line 349 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 2497 "build/parser.cpp"
    break;

  case 62: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 352 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 2508 "build/parser.cpp"
    break;

  case 63: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 358 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 2517 "build/parser.cpp"
    break;

  case 64: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 362 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 2528 "build/parser.cpp"
    break;

  case 65: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 371 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 2539 "build/parser.cpp"
    break;

  case 66: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 377 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 2550 "build/parser.cpp"
    break;

  case 67: /* eval_corr_stmt: KW_EVAL_CORR IDENTIFIER EQUALS IDENTIFIER SEMICOLON  */
#line 386 "src/parser.y"
                                                        {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 2560 "build/parser.cpp"
    break;

  case 68: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 394 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 2568 "build/parser.cpp"
    break;

  case 69: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 400 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 2576 "build/parser.cpp"
    break;

  case 70: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 406 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 2584 "build/parser.cpp"
    break;

  case 71: /* return_stmt: KW_RETURN SEMICOLON  */
#line 409 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 2592 "build/parser.cpp"
    break;

  case 72: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 416 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 2602 "build/parser.cpp"
    break;

  case 73: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 427 "src/parser.y"
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
#line 2623 "build/parser.cpp"
    break;

  case 74: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 450 "src/parser.y"
                          {
        rpg::ProcInterface iface;
        if ((yyvsp[-7].ival) >= 0) {
            iface.has_return = true;
            // Decode type from pi_return_type
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-7].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-5].param_list)->params);
        delete (yyvsp[-5].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-10].sval), std::move(iface));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-10].sval));
        (yyval.stmt) = proc;
    }
#line 2648 "build/parser.cpp"
    break;

  case 75: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 474 "src/parser.y"
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
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-11].sval));
        free((yyvsp[-8].sval));
        (yyval.stmt) = proc;
    }
#line 2673 "build/parser.cpp"
    break;

  case 76: /* pi_return_type: %empty  */
#line 498 "src/parser.y"
               { (yyval.ival) = -1; }
#line 2679 "build/parser.cpp"
    break;

  case 77: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 499 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 2685 "build/parser.cpp"
    break;

  case 78: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 500 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 2691 "build/parser.cpp"
    break;

  case 79: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 501 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 2697 "build/parser.cpp"
    break;

  case 80: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 502 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 2703 "build/parser.cpp"
    break;

  case 81: /* pi_params: %empty  */
#line 507 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 2711 "build/parser.cpp"
    break;

  case 82: /* pi_params: pi_params pi_param  */
#line 510 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 2721 "build/parser.cpp"
    break;

  case 83: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 518 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2730 "build/parser.cpp"
    break;

  case 84: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 522 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2739 "build/parser.cpp"
    break;

  case 85: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 526 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2748 "build/parser.cpp"
    break;

  case 86: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 530 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2757 "build/parser.cpp"
    break;

  case 87: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 534 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2766 "build/parser.cpp"
    break;

  case 88: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 538 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2775 "build/parser.cpp"
    break;

  case 89: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 542 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 2784 "build/parser.cpp"
    break;

  case 90: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 546 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 2793 "build/parser.cpp"
    break;

  case 91: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 551 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2802 "build/parser.cpp"
    break;

  case 92: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 555 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2811 "build/parser.cpp"
    break;

  case 93: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 559 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2820 "build/parser.cpp"
    break;

  case 94: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 563 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2829 "build/parser.cpp"
    break;

  case 95: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 567 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2838 "build/parser.cpp"
    break;

  case 96: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 571 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2847 "build/parser.cpp"
    break;

  case 97: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 575 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 2856 "build/parser.cpp"
    break;

  case 98: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 579 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 2865 "build/parser.cpp"
    break;

  case 99: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 583 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 2875 "build/parser.cpp"
    break;

  case 100: /* pr_params: %empty  */
#line 592 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 2883 "build/parser.cpp"
    break;

  case 101: /* pr_params: pr_params pr_param  */
#line 595 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 2893 "build/parser.cpp"
    break;

  case 102: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 603 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2902 "build/parser.cpp"
    break;

  case 103: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 607 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2911 "build/parser.cpp"
    break;

  case 104: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 611 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2920 "build/parser.cpp"
    break;

  case 105: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 615 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2929 "build/parser.cpp"
    break;

  case 106: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 619 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2938 "build/parser.cpp"
    break;

  case 107: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 623 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2947 "build/parser.cpp"
    break;

  case 108: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 627 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 2956 "build/parser.cpp"
    break;

  case 109: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 631 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 2965 "build/parser.cpp"
    break;

  case 110: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 636 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2974 "build/parser.cpp"
    break;

  case 111: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 640 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2983 "build/parser.cpp"
    break;

  case 112: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 644 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2992 "build/parser.cpp"
    break;

  case 113: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 648 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3001 "build/parser.cpp"
    break;

  case 114: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 652 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3010 "build/parser.cpp"
    break;

  case 115: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 656 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3019 "build/parser.cpp"
    break;

  case 116: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 660 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3028 "build/parser.cpp"
    break;

  case 117: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 664 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3037 "build/parser.cpp"
    break;

  case 118: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 668 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 3047 "build/parser.cpp"
    break;

  case 119: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 678 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 3060 "build/parser.cpp"
    break;

  case 120: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 689 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 3072 "build/parser.cpp"
    break;

  case 121: /* exsr_stmt: KW_EXSR IDENTIFIER SEMICOLON  */
#line 699 "src/parser.y"
                                 {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 3081 "build/parser.cpp"
    break;

  case 122: /* sorta_stmt: KW_SORTA IDENTIFIER SEMICOLON  */
#line 707 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 3090 "build/parser.cpp"
    break;

  case 123: /* reset_stmt: KW_RESET IDENTIFIER SEMICOLON  */
#line 715 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 3099 "build/parser.cpp"
    break;

  case 124: /* clear_stmt: KW_CLEAR IDENTIFIER SEMICOLON  */
#line 722 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 3108 "build/parser.cpp"
    break;

  case 125: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 732 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 3121 "build/parser.cpp"
    break;

  case 126: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 741 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 3134 "build/parser.cpp"
    break;

  case 127: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 750 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 3148 "build/parser.cpp"
    break;

  case 128: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 760 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 3162 "build/parser.cpp"
    break;

  case 129: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 770 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 3174 "build/parser.cpp"
    break;

  case 130: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 778 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 3187 "build/parser.cpp"
    break;

  case 131: /* ds_fields: %empty  */
#line 789 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 3195 "build/parser.cpp"
    break;

  case 132: /* ds_fields: ds_fields ds_field  */
#line 792 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 3205 "build/parser.cpp"
    break;

  case 133: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 800 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 3214 "build/parser.cpp"
    break;

  case 134: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 804 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 3223 "build/parser.cpp"
    break;

  case 135: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 808 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 3232 "build/parser.cpp"
    break;

  case 136: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 812 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 3241 "build/parser.cpp"
    break;

  case 137: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 817 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 3250 "build/parser.cpp"
    break;

  case 138: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 821 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 3259 "build/parser.cpp"
    break;

  case 139: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 825 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 3268 "build/parser.cpp"
    break;

  case 140: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 829 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 3277 "build/parser.cpp"
    break;

  case 141: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 838 "src/parser.y"
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
#line 3302 "build/parser.cpp"
    break;

  case 142: /* elseif_clauses: %empty  */
#line 861 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 3308 "build/parser.cpp"
    break;

  case 143: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 862 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 3318 "build/parser.cpp"
    break;

  case 144: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 870 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 3329 "build/parser.cpp"
    break;

  case 145: /* else_clause: %empty  */
#line 879 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 3335 "build/parser.cpp"
    break;

  case 146: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 880 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 3343 "build/parser.cpp"
    break;

  case 147: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 886 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 3354 "build/parser.cpp"
    break;

  case 148: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 895 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 3365 "build/parser.cpp"
    break;

  case 149: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 904 "src/parser.y"
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
#line 3380 "build/parser.cpp"
    break;

  case 150: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 914 "src/parser.y"
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
#line 3395 "build/parser.cpp"
    break;

  case 151: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 924 "src/parser.y"
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
#line 3410 "build/parser.cpp"
    break;

  case 152: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 934 "src/parser.y"
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
#line 3425 "build/parser.cpp"
    break;

  case 153: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 947 "src/parser.y"
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
#line 3446 "build/parser.cpp"
    break;

  case 154: /* when_clauses: when_clause  */
#line 966 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 3455 "build/parser.cpp"
    break;

  case 155: /* when_clauses: when_clauses when_clause  */
#line 970 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 3464 "build/parser.cpp"
    break;

  case 156: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 977 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 3475 "build/parser.cpp"
    break;

  case 157: /* other_clause: %empty  */
#line 986 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 3481 "build/parser.cpp"
    break;

  case 158: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 987 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 3489 "build/parser.cpp"
    break;

  case 159: /* iter_stmt: KW_ITER SEMICOLON  */
#line 993 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 3495 "build/parser.cpp"
    break;

  case 160: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 997 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 3501 "build/parser.cpp"
    break;

  case 161: /* expression: or_expr  */
#line 1003 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 3507 "build/parser.cpp"
    break;

  case 162: /* or_expr: and_expr  */
#line 1007 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 3513 "build/parser.cpp"
    break;

  case 163: /* or_expr: or_expr KW_OR and_expr  */
#line 1008 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3523 "build/parser.cpp"
    break;

  case 164: /* and_expr: not_expr  */
#line 1016 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 3529 "build/parser.cpp"
    break;

  case 165: /* and_expr: and_expr KW_AND not_expr  */
#line 1017 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3539 "build/parser.cpp"
    break;

  case 166: /* not_expr: comparison_expr  */
#line 1025 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3545 "build/parser.cpp"
    break;

  case 167: /* not_expr: KW_NOT comparison_expr  */
#line 1026 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3553 "build/parser.cpp"
    break;

  case 168: /* comparison_expr: additive_expr  */
#line 1032 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 3559 "build/parser.cpp"
    break;

  case 169: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1033 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3569 "build/parser.cpp"
    break;

  case 170: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1038 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3579 "build/parser.cpp"
    break;

  case 171: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1043 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3589 "build/parser.cpp"
    break;

  case 172: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1048 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3599 "build/parser.cpp"
    break;

  case 173: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1053 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3609 "build/parser.cpp"
    break;

  case 174: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1058 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3619 "build/parser.cpp"
    break;

  case 175: /* additive_expr: multiplicative_expr  */
#line 1066 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 3625 "build/parser.cpp"
    break;

  case 176: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1067 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3635 "build/parser.cpp"
    break;

  case 177: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1072 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3645 "build/parser.cpp"
    break;

  case 178: /* multiplicative_expr: unary_expr  */
#line 1080 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 3651 "build/parser.cpp"
    break;

  case 179: /* multiplicative_expr: multiplicative_expr STAR unary_expr  */
#line 1081 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3661 "build/parser.cpp"
    break;

  case 180: /* multiplicative_expr: multiplicative_expr SLASH unary_expr  */
#line 1086 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3671 "build/parser.cpp"
    break;

  case 181: /* unary_expr: postfix_expr  */
#line 1094 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 3677 "build/parser.cpp"
    break;

  case 182: /* unary_expr: MINUS postfix_expr  */
#line 1095 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3687 "build/parser.cpp"
    break;

  case 183: /* postfix_expr: primary_expr  */
#line 1103 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 3693 "build/parser.cpp"
    break;

  case 184: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1104 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3702 "build/parser.cpp"
    break;

  case 185: /* primary_expr: IDENTIFIER  */
#line 1111 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3711 "build/parser.cpp"
    break;

  case 186: /* primary_expr: INTEGER_LITERAL  */
#line 1115 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 3719 "build/parser.cpp"
    break;

  case 187: /* primary_expr: FLOAT_LITERAL  */
#line 1118 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 3727 "build/parser.cpp"
    break;

  case 188: /* primary_expr: STRING_LITERAL  */
#line 1121 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3736 "build/parser.cpp"
    break;

  case 189: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1125 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 3745 "build/parser.cpp"
    break;

  case 190: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1129 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 3753 "build/parser.cpp"
    break;

  case 191: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1132 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 3761 "build/parser.cpp"
    break;

  case 192: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1135 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 3769 "build/parser.cpp"
    break;

  case 193: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1138 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 3777 "build/parser.cpp"
    break;

  case 194: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1141 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 3785 "build/parser.cpp"
    break;

  case 195: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1144 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 3793 "build/parser.cpp"
    break;

  case 196: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1147 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 3801 "build/parser.cpp"
    break;

  case 197: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1150 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 3809 "build/parser.cpp"
    break;

  case 198: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1153 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 3817 "build/parser.cpp"
    break;

  case 199: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1156 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 3825 "build/parser.cpp"
    break;

  case 200: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1159 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 3833 "build/parser.cpp"
    break;

  case 201: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1162 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 3841 "build/parser.cpp"
    break;

  case 202: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1165 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 3850 "build/parser.cpp"
    break;

  case 203: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1169 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 3858 "build/parser.cpp"
    break;

  case 204: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1172 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 3866 "build/parser.cpp"
    break;

  case 205: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1175 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 3874 "build/parser.cpp"
    break;

  case 206: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1178 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 3882 "build/parser.cpp"
    break;

  case 207: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1181 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 3890 "build/parser.cpp"
    break;

  case 208: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1184 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 3898 "build/parser.cpp"
    break;

  case 209: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1187 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 3906 "build/parser.cpp"
    break;

  case 210: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1190 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 3914 "build/parser.cpp"
    break;

  case 211: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1193 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 3923 "build/parser.cpp"
    break;

  case 212: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1197 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 3932 "build/parser.cpp"
    break;

  case 213: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1201 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 3940 "build/parser.cpp"
    break;

  case 214: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1204 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 3948 "build/parser.cpp"
    break;

  case 215: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1207 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 3956 "build/parser.cpp"
    break;

  case 216: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1210 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 3964 "build/parser.cpp"
    break;

  case 217: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1213 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 3972 "build/parser.cpp"
    break;

  case 218: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1216 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 3980 "build/parser.cpp"
    break;

  case 219: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1219 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 3989 "build/parser.cpp"
    break;

  case 220: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1223 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 3997 "build/parser.cpp"
    break;

  case 221: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1226 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 4006 "build/parser.cpp"
    break;

  case 222: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1230 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 4014 "build/parser.cpp"
    break;

  case 223: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1233 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 4023 "build/parser.cpp"
    break;

  case 224: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1237 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 4035 "build/parser.cpp"
    break;

  case 225: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1244 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 4047 "build/parser.cpp"
    break;

  case 226: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1251 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 4059 "build/parser.cpp"
    break;

  case 227: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 1258 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 4069 "build/parser.cpp"
    break;

  case 228: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 1263 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 4079 "build/parser.cpp"
    break;

  case 229: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 1268 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 4089 "build/parser.cpp"
    break;

  case 230: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 1273 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 4098 "build/parser.cpp"
    break;

  case 231: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 1277 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 4107 "build/parser.cpp"
    break;

  case 232: /* primary_expr: INDICATOR  */
#line 1281 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 4115 "build/parser.cpp"
    break;

  case 233: /* primary_expr: KW_ON  */
#line 1284 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 4123 "build/parser.cpp"
    break;

  case 234: /* primary_expr: KW_OFF  */
#line 1287 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 4131 "build/parser.cpp"
    break;

  case 235: /* primary_expr: KW_NULL  */
#line 1290 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 4139 "build/parser.cpp"
    break;

  case 236: /* primary_expr: LPAREN expression RPAREN  */
#line 1293 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 4147 "build/parser.cpp"
    break;

  case 237: /* call_args_opt: %empty  */
#line 1300 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 4153 "build/parser.cpp"
    break;

  case 238: /* call_args_opt: call_arg_list  */
#line 1301 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 4159 "build/parser.cpp"
    break;

  case 239: /* call_arg_list: expression  */
#line 1305 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 4168 "build/parser.cpp"
    break;

  case 240: /* call_arg_list: call_arg_list COLON expression  */
#line 1309 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 4177 "build/parser.cpp"
    break;

  case 241: /* arg_list: expression  */
#line 1317 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 4186 "build/parser.cpp"
    break;

  case 242: /* arg_list: arg_list COLON expression  */
#line 1321 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 4195 "build/parser.cpp"
    break;


#line 4199 "build/parser.cpp"

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

#line 1327 "src/parser.y"


void yyerror(const char* s) {
    g_error_count++;
    fprintf(stderr, "Error at line %d: %s (near '%s')\n", yylineno, s, yytext);
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
