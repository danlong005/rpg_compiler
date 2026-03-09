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
  YYSYMBOL_KW_DCL_S = 4,                   /* KW_DCL_S  */
  YYSYMBOL_KW_DCL_C = 5,                   /* KW_DCL_C  */
  YYSYMBOL_KW_CHAR = 6,                    /* KW_CHAR  */
  YYSYMBOL_KW_VARCHAR = 7,                 /* KW_VARCHAR  */
  YYSYMBOL_KW_INT = 8,                     /* KW_INT  */
  YYSYMBOL_KW_PACKED = 9,                  /* KW_PACKED  */
  YYSYMBOL_KW_ZONED = 10,                  /* KW_ZONED  */
  YYSYMBOL_KW_DATE = 11,                   /* KW_DATE  */
  YYSYMBOL_KW_TIME = 12,                   /* KW_TIME  */
  YYSYMBOL_KW_TIMESTAMP = 13,              /* KW_TIMESTAMP  */
  YYSYMBOL_KW_DAYS = 14,                   /* KW_DAYS  */
  YYSYMBOL_KW_MONTHS = 15,                 /* KW_MONTHS  */
  YYSYMBOL_KW_YEARS = 16,                  /* KW_YEARS  */
  YYSYMBOL_KW_CONST = 17,                  /* KW_CONST  */
  YYSYMBOL_KW_INZ = 18,                    /* KW_INZ  */
  YYSYMBOL_KW_DSPLY = 19,                  /* KW_DSPLY  */
  YYSYMBOL_KW_EVAL = 20,                   /* KW_EVAL  */
  YYSYMBOL_KW_RETURN = 21,                 /* KW_RETURN  */
  YYSYMBOL_KW_INLR = 22,                   /* KW_INLR  */
  YYSYMBOL_KW_ON = 23,                     /* KW_ON  */
  YYSYMBOL_KW_IF = 24,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 25,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 26,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 27,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 28,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 29,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 30,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 31,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 32,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 33,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 34,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 35,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 36,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 37,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 38,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 39,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 40,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 41,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 42,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 43,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 44,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 45,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 46,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 47,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 48,                    /* KW_OFF  */
  YYSYMBOL_INDICATOR = 49,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 50,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 51,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 52,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 53,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 54,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 55,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 56,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 57,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 58,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 59,                  /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 60,                 /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 61,                 /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 62,              /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 63,                    /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 64,                 /* KW_LIKEDS  */
  YYSYMBOL_DOT = 65,                       /* DOT  */
  YYSYMBOL_BIF_CHAR = 66,                  /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 67,                  /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 68,                 /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 69,                 /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 70,                   /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 71,                 /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 72,                  /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 73,               /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 74,                 /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 75,                   /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 76,                   /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 77,                  /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 78,                 /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 79,                   /* BIF_EOF  */
  YYSYMBOL_BIF_DATE = 80,                  /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 81,                  /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 82,             /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 83,                  /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 84,                  /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 85,                /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 86,                 /* BIF_YEARS  */
  YYSYMBOL_IDENTIFIER = 87,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 88,           /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 89,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 90,            /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 91,                 /* SEMICOLON  */
  YYSYMBOL_EQUALS = 92,                    /* EQUALS  */
  YYSYMBOL_LPAREN = 93,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 94,                    /* RPAREN  */
  YYSYMBOL_COLON = 95,                     /* COLON  */
  YYSYMBOL_PLUS = 96,                      /* PLUS  */
  YYSYMBOL_MINUS = 97,                     /* MINUS  */
  YYSYMBOL_STAR = 98,                      /* STAR  */
  YYSYMBOL_SLASH = 99,                     /* SLASH  */
  YYSYMBOL_NE = 100,                       /* NE  */
  YYSYMBOL_LE = 101,                       /* LE  */
  YYSYMBOL_GE = 102,                       /* GE  */
  YYSYMBOL_LT = 103,                       /* LT  */
  YYSYMBOL_GT = 104,                       /* GT  */
  YYSYMBOL_YYACCEPT = 105,                 /* $accept  */
  YYSYMBOL_program = 106,                  /* program  */
  YYSYMBOL_statements_opt = 107,           /* statements_opt  */
  YYSYMBOL_statement_list = 108,           /* statement_list  */
  YYSYMBOL_statement = 109,                /* statement  */
  YYSYMBOL_dcl_s_stmt = 110,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 111,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 112,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 113,              /* eval_target  */
  YYSYMBOL_eval_stmt = 114,                /* eval_stmt  */
  YYSYMBOL_dsply_stmt = 115,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 116,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 117,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 118,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 119,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 120,            /* dcl_proc_stmt  */
  YYSYMBOL_pi_return_type = 121,           /* pi_return_type  */
  YYSYMBOL_pi_params = 122,                /* pi_params  */
  YYSYMBOL_pi_param = 123,                 /* pi_param  */
  YYSYMBOL_pr_params = 124,                /* pr_params  */
  YYSYMBOL_pr_param = 125,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 126,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 127,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 128,                /* exsr_stmt  */
  YYSYMBOL_dcl_ds_stmt = 129,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 130,                /* ds_fields  */
  YYSYMBOL_ds_field = 131,                 /* ds_field  */
  YYSYMBOL_if_stmt = 132,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 133,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 134,            /* elseif_clause  */
  YYSYMBOL_else_clause = 135,              /* else_clause  */
  YYSYMBOL_dow_stmt = 136,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 137,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 138,                 /* for_stmt  */
  YYSYMBOL_select_stmt = 139,              /* select_stmt  */
  YYSYMBOL_when_clauses = 140,             /* when_clauses  */
  YYSYMBOL_when_clause = 141,              /* when_clause  */
  YYSYMBOL_other_clause = 142,             /* other_clause  */
  YYSYMBOL_iter_stmt = 143,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 144,               /* leave_stmt  */
  YYSYMBOL_expression = 145,               /* expression  */
  YYSYMBOL_or_expr = 146,                  /* or_expr  */
  YYSYMBOL_and_expr = 147,                 /* and_expr  */
  YYSYMBOL_not_expr = 148,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 149,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 150,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 151,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 152,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 153,             /* postfix_expr  */
  YYSYMBOL_primary_expr = 154,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 155,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 156,            /* call_arg_list  */
  YYSYMBOL_arg_list = 157                  /* arg_list  */
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
#define YYLAST   1499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  564

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   359


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   161,   163,   171,   174,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   208,   212,
     216,   220,   224,   228,   233,   238,   243,   248,   253,   258,
     263,   267,   271,   277,   283,   290,   294,   297,   303,   312,
     318,   327,   333,   339,   342,   349,   360,   380,   404,   431,
     432,   433,   434,   435,   440,   443,   451,   455,   459,   463,
     467,   471,   475,   479,   487,   490,   498,   502,   506,   510,
     514,   518,   522,   526,   535,   546,   556,   566,   575,   584,
     594,   604,   612,   623,   626,   634,   638,   642,   646,   655,
     678,   679,   687,   696,   697,   703,   712,   721,   731,   741,
     751,   764,   783,   787,   794,   803,   804,   810,   814,   820,
     824,   825,   833,   834,   842,   843,   849,   850,   855,   860,
     865,   870,   875,   883,   884,   889,   897,   898,   903,   911,
     912,   920,   921,   928,   932,   935,   938,   942,   946,   949,
     952,   955,   958,   961,   964,   967,   970,   973,   976,   979,
     982,   985,   989,   992,   996,   999,  1003,  1010,  1017,  1024,
    1029,  1034,  1039,  1043,  1047,  1050,  1053,  1056,  1063,  1064,
    1068,  1072,  1080,  1084
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_FREE", "KW_DCL_S",
  "KW_DCL_C", "KW_CHAR", "KW_VARCHAR", "KW_INT", "KW_PACKED", "KW_ZONED",
  "KW_DATE", "KW_TIME", "KW_TIMESTAMP", "KW_DAYS", "KW_MONTHS", "KW_YEARS",
  "KW_CONST", "KW_INZ", "KW_DSPLY", "KW_EVAL", "KW_RETURN", "KW_INLR",
  "KW_ON", "KW_IF", "KW_ELSEIF", "KW_ELSE", "KW_ENDIF", "KW_DOW", "KW_DOU",
  "KW_ENDDO", "KW_FOR", "KW_ENDFOR", "KW_TO", "KW_DOWNTO", "KW_BY",
  "KW_SELECT", "KW_WHEN", "KW_OTHER", "KW_ENDSL", "KW_ITER", "KW_LEAVE",
  "KW_MONITOR", "KW_ON_ERROR", "KW_ENDMON", "KW_BEGSR", "KW_ENDSR",
  "KW_EXSR", "KW_OFF", "INDICATOR", "KW_AND", "KW_OR", "KW_NOT",
  "KW_DCL_PROC", "KW_END_PROC", "KW_DCL_PI", "KW_END_PI", "KW_DCL_PR",
  "KW_END_PR", "KW_VALUE", "KW_DCL_DS", "KW_END_DS", "KW_QUALIFIED",
  "KW_DIM", "KW_LIKEDS", "DOT", "BIF_CHAR", "BIF_TRIM", "BIF_TRIML",
  "BIF_TRIMR", "BIF_LEN", "BIF_SUBST", "BIF_SCAN", "BIF_SCANRPL",
  "BIF_XLATE", "BIF_DEC", "BIF_INT", "BIF_ELEM", "BIF_FOUND", "BIF_EOF",
  "BIF_DATE", "BIF_TIME", "BIF_TIMESTAMP", "BIF_DIFF", "BIF_DAYS",
  "BIF_MONTHS", "BIF_YEARS", "IDENTIFIER", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "SEMICOLON", "EQUALS", "LPAREN",
  "RPAREN", "COLON", "PLUS", "MINUS", "STAR", "SLASH", "NE", "LE", "GE",
  "LT", "GT", "$accept", "program", "statements_opt", "statement_list",
  "statement", "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt", "eval_target",
  "eval_stmt", "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt",
  "dcl_pr_stmt", "dcl_proc_stmt", "pi_return_type", "pi_params",
  "pi_param", "pr_params", "pr_param", "monitor_stmt", "begsr_stmt",
  "exsr_stmt", "dcl_ds_stmt", "ds_fields", "ds_field", "if_stmt",
  "elseif_clauses", "elseif_clause", "else_clause", "dow_stmt", "dou_stmt",
  "for_stmt", "select_stmt", "when_clauses", "when_clause", "other_clause",
  "iter_stmt", "leave_stmt", "expression", "or_expr", "and_expr",
  "not_expr", "comparison_expr", "additive_expr", "multiplicative_expr",
  "unary_expr", "postfix_expr", "primary_expr", "call_args_opt",
  "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-319)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-117)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,  -319,    40,    25,  -319,   -67,   -45,   -10,  1270,   -27,
     997,    -9,  1270,  1270,  1270,    15,    20,    27,    41,    55,
      29,    62,  -319,    73,    80,    83,   -14,  -319,  -319,  -319,
      22,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,
    -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,
     132,  1270,  -319,  -319,  -319,  1338,    82,    89,    98,   105,
     107,   111,   115,   131,   144,   151,   156,   165,   169,   173,
     198,   202,   204,   205,   207,   209,   210,   215,  -319,  -319,
    -319,  1270,  1406,   155,   266,   176,  -319,    21,    34,    53,
    -319,   253,  -319,    -1,   223,  -319,   228,   297,   231,   233,
     238,   241,   294,  -319,  -319,  -319,   244,   245,   246,    26,
      24,   252,  1270,  1270,   247,   248,   251,   255,   256,   261,
     263,   265,   267,    21,  1270,  1270,  1270,  1270,  1270,  1270,
    1270,  1270,  1270,  1270,  1270,  1270,   249,   259,  1066,  1134,
    1202,  1270,  1270,  1270,  1270,  1270,   268,   253,  -319,  1270,
    1270,  1338,  1338,  1338,  1338,  1338,  1338,  1338,  1338,  1338,
    1338,   270,  1270,  1270,  -319,   269,  -319,  -319,  -319,  1270,
    1270,   121,  -319,   346,  -319,  -319,   291,   271,   280,   283,
     286,   272,    12,   287,   288,  -319,  -319,   284,   289,   290,
     293,   273,   302,   308,   310,   312,  -319,  -319,  -319,  -319,
    -319,    95,   101,   108,   112,   116,   119,   122,   127,   133,
     135,   137,   146,  -319,  -319,  -319,   153,  -319,   170,  -319,
     175,   306,   311,   313,   314,  -319,   315,  -319,   176,  -319,
      34,    34,    34,    34,    34,    34,    53,    53,  -319,  -319,
    -319,   284,   319,  -319,   152,   416,   470,   239,   320,   321,
    -319,   316,   322,  -319,   520,     8,   326,   327,   328,   330,
    -319,   309,  -319,   331,   317,    23,   357,   332,  1270,  -319,
     333,   335,   336,   329,   337,  -319,  1270,  -319,  -319,  -319,
    -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,  -319,
    -319,  1270,  -319,  -319,  -319,  -319,  -319,   250,   334,   343,
    1270,  1270,  -319,  -319,   348,  -319,   350,    26,   351,   349,
     354,   355,   356,   -30,   338,    30,   359,   360,   364,   120,
    -319,   363,  -319,  -319,   260,   341,   262,   371,   372,  -319,
     367,  1270,   373,  -319,   439,  -319,  -319,   -32,   -15,   214,
     570,  -319,   620,  -319,   376,  -319,  -319,  -319,  -319,   382,
     381,   157,  -319,   383,   387,   417,    18,  -319,   388,   389,
     390,   391,  -319,   462,   392,   395,   394,   397,   475,   402,
     405,   408,   410,    92,   414,  -319,   418,  1270,  -319,  1270,
    -319,   422,  -319,   -35,   413,  -319,   415,   421,   423,   425,
     429,  -319,   431,   433,  -319,   440,   441,   443,   444,   442,
    1270,  -319,  1270,  -319,   445,  1270,  -319,   264,  -319,   449,
     451,   452,  -319,   670,  -319,   446,   720,   456,   770,  -319,
     -29,   459,   178,  -319,  -319,   448,   464,   465,   466,  -319,
    -319,   467,   469,   474,   476,   438,  1270,   478,   482,  1270,
     484,   516,   471,   468,   488,  -319,  -319,  -319,   285,  -319,
     490,  -319,   491,   492,  -319,   493,   494,   495,   500,   501,
     502,   503,   463,    32,    33,   506,   511,   512,   513,   496,
     514,   522,   523,   524,   525,   527,  1270,  -319,  -319,   820,
    -319,   870,  -319,  -319,   920,   497,   517,   534,   538,   -50,
     -41,   -36,   540,   541,   542,   543,  -319,  -319,  -319,   535,
     544,  -319,  -319,   545,  -319,  1270,   537,   546,   547,   974,
     552,   551,   553,   556,   557,   555,  -319,   562,  -319,   563,
    -319,   561,  -319,  -319,  -319,   567,  -319,  -319,   565,   572,
    -319,  -319,   575,  -319,   -28,   -23,   -22,   580,  -319,  -319,
    -319,   -20,  -319,   579,  -319,  -319,   581,  -319,   585,  -319,
     587,  -319,   588,   590,  -319,  -319,  -319,  -319,  -319,   -11,
    -319,   592,  -319,  -319
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,    45,     4,     7,     8,
       0,     9,    10,    11,    12,    26,    21,    20,    23,    24,
      25,    22,    13,    14,    15,    16,    17,    18,    19,    27,
       0,     0,   175,   176,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
     146,     0,     0,     0,   119,   120,   122,   124,   126,   133,
     136,   139,   141,    45,     0,    54,     0,     0,     0,     0,
       0,     0,     0,   117,   118,     5,     0,     0,     0,    59,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,     0,   140,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     5,     5,     5,     0,
       0,   115,   112,     0,     5,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    47,   180,     0,   179,
       0,     0,     0,     0,     0,     0,    40,    41,    42,    44,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,   173,   161,     0,   163,     0,   165,
       0,     0,     0,     0,     0,   180,     0,   177,   121,   123,
     127,   128,   131,   132,   129,   130,   134,   135,   137,   138,
     142,     0,     0,    52,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     6,     0,    59,     0,     0,     0,     0,
      74,     0,    93,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,   148,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   162,
     164,     0,   169,   170,   171,   147,    50,   103,     0,     0,
       0,     0,     5,     5,     0,     5,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,    55,   181,    43,    43,    43,     0,     0,   183,
       0,     0,     0,   101,     0,   105,   106,     0,     0,     0,
       0,   111,     0,    85,     0,    64,    61,    62,    60,     0,
       0,     0,    75,     0,     0,     0,     0,    88,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     5,     0,
       5,     0,    64,     0,     0,    56,     0,     0,     0,     0,
       0,    87,     0,     0,    91,     0,     0,     0,     0,     0,
       0,    28,     0,    29,     0,     0,    30,    43,    43,     0,
       0,     0,     5,     0,    99,     0,     0,     0,     0,    84,
       0,     0,     0,    65,    63,     0,     0,     0,     0,    93,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,   167,   168,     0,     5,
       0,     5,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
     107,     0,   109,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    95,     0,
       0,    37,    39,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    80,     0,
      76,     0,    90,    89,    92,     0,    34,    33,     0,     0,
     108,   110,     0,    57,     0,     0,     0,     0,    79,    81,
      77,     0,    98,     0,    38,    58,     0,    68,     0,    70,
       0,    66,     0,     0,    82,    35,    69,    71,    67,     0,
      83,     0,    72,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -319,  -319,  -319,  -155,   676,  -319,  -318,  -319,   675,  -319,
    -319,  -319,  -319,  -319,  -319,  -319,  -245,   303,  -319,  -319,
    -319,  -319,  -319,  -319,  -319,  -261,  -319,  -319,  -319,  -319,
    -319,  -319,  -319,  -319,  -319,  -319,   515,  -319,  -319,  -319,
      -8,  -319,   539,   550,   632,   -55,   130,   125,   611,  -319,
     558,  -319,   970
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   173,   253,    28,   365,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   181,   383,   423,   313,
     352,    38,    39,    40,    41,   265,   320,    42,   297,   333,
     334,    43,    44,    45,    46,   171,   172,   251,    47,    48,
     200,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     188,   189,   201
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,   315,    96,   377,    98,    99,   100,   367,   370,   515,
     308,   244,   245,   246,   177,   178,   179,   180,   517,   254,
     379,   421,    22,   519,    49,    -2,     5,   453,   350,     6,
       7,   546,   177,   178,   179,   180,   548,   550,     1,   553,
       4,   516,    50,   122,     8,     9,    10,    11,   561,    12,
     518,   111,   422,    13,    14,   520,    15,   351,   422,   378,
      93,    16,   344,   547,   111,    17,    18,    19,   549,   551,
      20,   554,    21,   146,    22,   261,   380,    51,    23,   112,
     562,   393,    24,    97,   318,    25,   182,   183,   184,   443,
     444,   354,   162,   493,   494,   307,   230,   231,   232,   233,
     234,   235,   101,   262,   187,   190,   409,   410,   411,   394,
     319,   102,    26,   151,   113,   185,   106,   319,   103,   319,
     319,   152,   153,   154,   155,   156,   358,   359,   360,   361,
     157,   158,   104,   221,   222,   223,   224,   225,   114,   115,
     116,   117,   118,   119,   120,   121,   105,   339,   340,   107,
     342,   159,   160,     5,   241,   242,     6,     7,   170,   249,
     108,   247,   248,   386,   387,   388,   389,   109,   463,   464,
     110,     8,     9,    10,    11,   124,    12,  -100,  -100,  -100,
      13,    14,   125,    15,   455,   456,   457,   458,    16,   275,
     276,   126,    17,    18,    19,   277,   276,    20,   127,    21,
     128,    22,   278,   276,   129,    23,   279,   276,   130,    24,
     280,   276,    25,   281,   276,     5,   282,   276,     6,     7,
     413,   283,   276,   416,   131,   418,   150,   284,   276,   285,
     276,   286,   276,     8,     9,    10,    11,   132,    12,    26,
     287,   276,    13,    14,   133,    15,   148,   288,   276,   134,
      16,  -114,  -114,  -114,    17,    18,    19,   448,   135,    20,
     323,    21,   136,    22,   289,   276,   137,    23,   329,   290,
     276,    24,   300,   301,    25,   331,   332,   363,   364,   368,
     369,   441,   442,   330,   238,   239,     5,   236,   237,     6,
       7,   138,   337,   338,   479,   139,   481,   140,   141,   484,
     142,    26,   143,   144,     8,     9,    10,    11,   145,    12,
    -102,  -102,  -102,    13,    14,   163,    15,   149,   161,   164,
     165,    16,   166,   374,   167,    17,    18,    19,   509,   168,
      20,   170,    21,   169,    22,   174,   175,   176,    23,   186,
     191,   192,    24,   213,   193,    25,   255,     5,   194,   195,
       6,     7,   196,   214,   197,   304,   198,   240,   199,   366,
     243,   270,   227,   260,   256,     8,     9,    10,    11,   415,
      12,   417,    26,   257,    13,    14,   258,    15,   266,   259,
     263,   264,    16,   267,   269,   268,    17,    18,    19,   252,
     271,    20,   437,    21,   438,    22,   272,   440,   273,    23,
     274,   291,   314,    24,   317,   292,    25,   293,   294,   295,
     296,   302,   303,   305,   309,   310,   311,     5,   312,   316,
       6,     7,   321,   322,   327,   335,   353,   324,   470,   325,
     326,   473,   328,    26,   336,     8,     9,    10,    11,   341,
      12,   343,   345,   346,    13,    14,   298,    15,   347,   348,
     362,   349,    16,   355,   356,   357,    17,    18,    19,   371,
     372,    20,   373,    21,   375,    22,   376,   382,   506,    23,
     384,     5,   385,    24,     6,     7,    25,   390,   391,   392,
     399,   395,   396,   397,   398,   400,   401,   402,   403,     8,
       9,    10,    11,   404,    12,   405,   406,   528,    13,    14,
     299,    15,   407,    26,   408,   412,    16,   424,   425,   414,
      17,    18,    19,   419,   426,    20,   427,    21,   428,    22,
     429,     5,   430,    23,     6,     7,   431,    24,   432,   433,
      25,   434,   435,   469,   475,   436,   459,   449,   439,     8,
       9,    10,    11,   445,    12,   446,   447,   451,    13,    14,
     454,    15,   460,   461,   462,   465,    16,    26,   492,   477,
      17,    18,    19,   466,   476,    20,   306,    21,   467,    22,
     468,     5,   471,    23,     6,     7,   472,    24,   474,   478,
      25,   480,   482,   483,   499,   511,   485,   486,   487,     8,
       9,    10,    11,   488,    12,   489,   490,   491,    13,    14,
     495,    15,   496,   497,   498,   512,    16,    26,   500,  -116,
      17,    18,    19,   501,   502,    20,   504,    21,   503,    22,
     505,     5,   513,    23,     6,     7,   514,    24,   521,   525,
      25,   529,   522,   523,   524,   526,   527,   530,   531,     8,
       9,    10,    11,   533,    12,   534,   538,   535,    13,    14,
     536,    15,   537,   539,   540,   541,    16,    26,   542,   543,
      17,    18,    19,   544,   381,    20,   545,    21,   552,    22,
     555,     5,   556,    23,     6,     7,   557,    24,   558,    27,
      25,   560,   559,   563,    94,   420,   250,   123,   228,     8,
       9,    10,    11,   147,    12,     0,     0,  -104,    13,    14,
     229,    15,     0,   226,     0,     0,    16,    26,     0,     0,
      17,    18,    19,     0,     0,    20,     0,    21,     0,    22,
       0,     5,     0,    23,     6,     7,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     0,    12,     0,     0,     0,    13,    14,
       0,    15,   450,     0,     0,     0,    16,    26,     0,     0,
      17,    18,    19,     0,     0,    20,     0,    21,     0,    22,
       0,     5,     0,    23,     6,     7,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     0,    12,     0,     0,     0,    13,    14,
       0,    15,   452,     0,     0,     0,    16,    26,     0,     0,
      17,    18,    19,     0,     0,    20,     0,    21,     0,    22,
       0,     5,     0,    23,     6,     7,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     0,    12,     0,     0,     0,    13,    14,
       0,    15,   507,     0,     0,     0,    16,    26,     0,     0,
      17,    18,    19,     0,     0,    20,     0,    21,     0,    22,
       0,     5,     0,    23,     6,     7,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     0,    12,     0,     0,     0,    13,    14,
       0,    15,   508,     0,     0,     0,    16,    26,     0,     0,
      17,    18,    19,     0,     0,    20,     0,    21,     0,    22,
       0,     5,     0,    23,     6,     7,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     0,    12,     0,     0,     0,    13,    14,
       0,    15,     0,     0,     0,     0,    16,    26,     0,     0,
      17,    18,    19,     0,     0,    20,     0,    21,     0,    22,
       0,     0,     0,    23,   510,     5,     0,    24,     6,     7,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,     0,    12,     0,
       0,     0,    13,    14,     0,    15,     0,    26,     0,     0,
      16,     0,     0,     0,    17,    18,    19,     0,     0,    20,
      52,    21,     0,    22,     0,     0,     0,    23,   532,     0,
       0,    24,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    95,    52,
      81,     0,     0,     0,    82,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,     0,   216,   218,
     220,     0,     0,     0,    53,    54,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    52,     0,    81,
     215,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    52,     0,    81,   217,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    52,     0,    81,   219,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    52,     0,    81,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    52,
       0,    81,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       8,   262,    10,    35,    12,    13,    14,   325,   326,    59,
     255,   166,   167,   168,     6,     7,     8,     9,    59,   174,
      35,    56,    49,    59,    91,     0,     1,    56,    58,     4,
       5,    59,     6,     7,     8,     9,    59,    59,     3,    59,
       0,    91,    87,    51,    19,    20,    21,    22,    59,    24,
      91,    65,    87,    28,    29,    91,    31,    87,    87,    91,
      87,    36,   307,    91,    65,    40,    41,    42,    91,    91,
      45,    91,    47,    81,    49,    63,    91,    87,    53,    93,
      91,    63,    57,    92,    61,    60,    62,    63,    64,   407,
     408,    61,    93,    61,    61,    87,   151,   152,   153,   154,
     155,   156,    87,    91,   112,   113,    14,    15,    16,    91,
      87,    91,    87,    92,    92,    91,    87,    87,    91,    87,
      87,   100,   101,   102,   103,   104,     6,     7,     8,     9,
      96,    97,    91,   141,   142,   143,   144,   145,     6,     7,
       8,     9,    10,    11,    12,    13,    91,   302,   303,    87,
     305,    98,    99,     1,   162,   163,     4,     5,    37,    38,
      87,   169,   170,     6,     7,     8,     9,    87,   429,   430,
      87,    19,    20,    21,    22,    93,    24,    25,    26,    27,
      28,    29,    93,    31,     6,     7,     8,     9,    36,    94,
      95,    93,    40,    41,    42,    94,    95,    45,    93,    47,
      93,    49,    94,    95,    93,    53,    94,    95,    93,    57,
      94,    95,    60,    94,    95,     1,    94,    95,     4,     5,
     375,    94,    95,   378,    93,   380,    50,    94,    95,    94,
      95,    94,    95,    19,    20,    21,    22,    93,    24,    87,
      94,    95,    28,    29,    93,    31,    91,    94,    95,    93,
      36,    37,    38,    39,    40,    41,    42,   412,    93,    45,
     268,    47,    93,    49,    94,    95,    93,    53,   276,    94,
      95,    57,    33,    34,    60,    25,    26,    17,    18,    17,
      18,    17,    18,   291,   159,   160,     1,   157,   158,     4,
       5,    93,   300,   301,   449,    93,   451,    93,    93,   454,
      93,    87,    93,    93,    19,    20,    21,    22,    93,    24,
      25,    26,    27,    28,    29,    92,    31,    51,    65,    91,
      23,    36,    91,   331,    91,    40,    41,    42,   483,    91,
      45,    37,    47,    92,    49,    91,    91,    91,    53,    87,
      93,    93,    57,    94,    93,    60,    55,     1,    93,    93,
       4,     5,    91,    94,    91,    39,    91,    87,    91,    18,
      91,    88,    94,    91,    93,    19,    20,    21,    22,   377,
      24,   379,    87,    93,    28,    29,    93,    31,    94,    93,
      93,    93,    36,    94,    91,    95,    40,    41,    42,    43,
      88,    45,   400,    47,   402,    49,    88,   405,    88,    53,
      88,    95,    93,    57,    87,    94,    60,    94,    94,    94,
      91,    91,    91,    91,    88,    88,    88,     1,    88,    88,
       4,     5,    65,    91,    95,    91,    88,    94,   436,    94,
      94,   439,    95,    87,    91,    19,    20,    21,    22,    91,
      24,    91,    91,    94,    28,    29,    30,    31,    94,    94,
      87,    95,    36,    94,    94,    91,    40,    41,    42,    88,
      88,    45,    95,    47,    91,    49,    27,    91,   476,    53,
      88,     1,    91,    57,     4,     5,    60,    94,    91,    62,
      18,    93,    93,    93,    93,    93,    91,    93,    91,    19,
      20,    21,    22,    18,    24,    93,    91,   505,    28,    29,
      30,    31,    94,    87,    94,    91,    36,    94,    93,    91,
      40,    41,    42,    91,    93,    45,    93,    47,    93,    49,
      91,     1,    91,    53,     4,     5,    93,    57,    88,    88,
      60,    88,    88,    95,    18,    93,    88,    91,    93,    19,
      20,    21,    22,    94,    24,    94,    94,    91,    28,    29,
      91,    31,    88,    88,    88,    88,    36,    87,    95,    91,
      40,    41,    42,    94,    93,    45,    46,    47,    94,    49,
      94,     1,    94,    53,     4,     5,    94,    57,    94,    91,
      60,    91,    91,    91,    88,    88,    93,    93,    93,    19,
      20,    21,    22,    93,    24,    94,    94,    94,    28,    29,
      94,    31,    91,    91,    91,    88,    36,    87,    94,    39,
      40,    41,    42,    91,    91,    45,    91,    47,    94,    49,
      93,     1,    88,    53,     4,     5,    88,    57,    88,    94,
      60,    94,    91,    91,    91,    91,    91,    91,    91,    19,
      20,    21,    22,    91,    24,    94,    91,    94,    28,    29,
      94,    31,    95,    91,    91,    94,    36,    87,    91,    94,
      40,    41,    42,    91,    44,    45,    91,    47,    88,    49,
      91,     1,    91,    53,     4,     5,    91,    57,    91,     3,
      60,    91,    94,    91,     9,   382,   171,    55,   149,    19,
      20,    21,    22,    82,    24,    -1,    -1,    27,    28,    29,
     150,    31,    -1,   145,    -1,    -1,    36,    87,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    -1,    47,    -1,    49,
      -1,     1,    -1,    53,     4,     5,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    36,    87,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    -1,    47,    -1,    49,
      -1,     1,    -1,    53,     4,     5,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    36,    87,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    -1,    47,    -1,    49,
      -1,     1,    -1,    53,     4,     5,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    36,    87,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    -1,    47,    -1,    49,
      -1,     1,    -1,    53,     4,     5,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    36,    87,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    -1,    47,    -1,    49,
      -1,     1,    -1,    53,     4,     5,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    -1,    -1,    -1,    -1,    36,    87,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    -1,    47,    -1,    49,
      -1,    -1,    -1,    53,    54,     1,    -1,    57,     4,     5,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    28,    29,    -1,    31,    -1,    87,    -1,    -1,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    45,
      23,    47,    -1,    49,    -1,    -1,    -1,    53,    54,    -1,
      -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    23,
      93,    -1,    -1,    -1,    97,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    -1,    -1,   138,   139,
     140,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    23,    -1,    93,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    23,    -1,    93,    94,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    23,    -1,    93,    94,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    23,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    23,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   106,   107,     0,     1,     4,     5,    19,    20,
      21,    22,    24,    28,    29,    31,    36,    40,    41,    42,
      45,    47,    49,    53,    57,    60,    87,   109,   110,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   126,   127,
     128,   129,   132,   136,   137,   138,   139,   143,   144,    91,
      87,    87,    23,    48,    49,    52,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    97,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    87,   113,    91,   145,    92,   145,   145,
     145,    87,    91,    91,    91,    91,    87,    87,    87,    87,
      87,    65,    93,    92,     6,     7,     8,     9,    10,    11,
      12,    13,   145,   149,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,   145,   153,    91,    51,
      50,    92,   100,   101,   102,   103,   104,    96,    97,    98,
      99,    65,    93,    92,    91,    23,    91,    91,    91,    92,
      37,   140,   141,   108,    91,    91,    91,     6,     7,     8,
       9,   121,    62,    63,    64,    91,    87,   145,   155,   156,
     145,    93,    93,    93,    93,    93,    91,    91,    91,    91,
     145,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,    94,    94,    94,   157,    94,   157,    94,
     157,   145,   145,   145,   145,   145,   155,    94,   147,   148,
     150,   150,   150,   150,   150,   150,   151,   151,   152,   152,
      87,   145,   145,    91,   108,   108,   108,   145,   145,    38,
     141,   142,    43,   109,   108,    55,    93,    93,    93,    93,
      91,    63,    91,    93,    93,   130,    94,    94,    95,    91,
      88,    88,    88,    88,    88,    94,    95,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    94,    94,    94,    94,    91,   133,    30,    30,
      33,    34,    91,    91,    39,    91,    46,    87,   121,    88,
      88,    88,    88,   124,    93,   130,    88,    87,    61,    87,
     131,    65,    91,   145,    94,    94,    94,    95,    95,   145,
     145,    25,    26,   134,   135,    91,    91,   145,   145,   108,
     108,    91,   108,    91,   121,    91,    94,    94,    94,    95,
      58,    87,   125,    88,    61,    94,    94,    91,     6,     7,
       8,     9,    87,    17,    18,   111,    18,   111,    17,    18,
     111,    88,    88,    95,   145,    91,    27,    35,    91,    35,
      91,    44,    91,   122,    88,    91,     6,     7,     8,     9,
      94,    91,    62,    63,    91,    93,    93,    93,    93,    18,
      93,    91,    93,    91,    18,    93,    91,    94,    94,    14,
      15,    16,    91,   108,    91,   145,   108,   145,   108,    91,
     122,    56,    87,   123,    94,    93,    93,    93,    93,    91,
      91,    93,    88,    88,    88,    88,    93,   145,   145,    93,
     145,    17,    18,   111,   111,    94,    94,    94,   108,    91,
      32,    91,    32,    56,    91,     6,     7,     8,     9,    88,
      88,    88,    88,   130,   130,    88,    94,    94,    94,    95,
     145,    94,    94,   145,    94,    18,    93,    91,    91,   108,
      91,   108,    91,    91,   108,    93,    93,    93,    93,    94,
      94,    94,    95,    61,    61,    94,    91,    91,    91,    88,
      94,    91,    91,    94,    91,    93,   145,    32,    32,   108,
      54,    88,    88,    88,    88,    59,    91,    59,    91,    59,
      91,    88,    91,    91,    91,    94,    91,    91,   145,    94,
      91,    91,    54,    91,    94,    94,    94,    95,    91,    91,
      91,    94,    91,    94,    91,    91,    59,    91,    59,    91,
      59,    91,    88,    59,    91,    91,    91,    91,    91,    94,
      91,    59,    91,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   112,   113,   113,   113,   113,   114,
     114,   115,   116,   117,   117,   118,   119,   120,   120,   121,
     121,   121,   121,   121,   122,   122,   123,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   127,   128,   129,   129,   129,
     129,   129,   129,   130,   130,   131,   131,   131,   131,   132,
     133,   133,   134,   135,   135,   136,   137,   138,   138,   138,
     138,   139,   140,   140,   141,   142,   142,   143,   144,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   149,   149,
     149,   149,   149,   150,   150,   150,   151,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   155,   155,
     156,   156,   157,   157
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     8,     8,
       8,    10,    10,    12,    12,    14,    11,    11,    13,    11,
       4,     4,     4,     0,     4,     1,     1,     3,     6,     4,
       5,     3,     4,     3,     2,     5,     7,    12,    13,     0,
       4,     4,     4,     6,     0,     2,     6,     7,     6,     7,
       6,     7,     8,     9,     0,     2,     6,     7,     6,     7,
       6,     7,     8,     9,     8,     6,     3,     7,     6,    11,
      11,     7,    11,     0,     2,     6,     6,     6,     8,     8,
       0,     2,     4,     0,     3,     6,     6,    10,    12,    10,
      12,     6,     1,     2,     4,     0,     3,     2,     2,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     4,     3,     4,     3,     8,     8,     8,     4,
       4,     4,     3,     3,     1,     1,     1,     3,     0,     1,
       1,     3,     1,     3
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
#line 156 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 1815 "build/parser.cpp"
    break;

  case 4: /* statements_opt: statements_opt statement  */
#line 163 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 1825 "build/parser.cpp"
    break;

  case 5: /* statement_list: %empty  */
#line 171 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 1833 "build/parser.cpp"
    break;

  case 6: /* statement_list: statement_list statement  */
#line 174 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 1844 "build/parser.cpp"
    break;

  case 7: /* statement: dcl_s_stmt  */
#line 183 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1850 "build/parser.cpp"
    break;

  case 8: /* statement: dcl_c_stmt  */
#line 184 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1856 "build/parser.cpp"
    break;

  case 9: /* statement: eval_stmt  */
#line 185 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1862 "build/parser.cpp"
    break;

  case 10: /* statement: dsply_stmt  */
#line 186 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1868 "build/parser.cpp"
    break;

  case 11: /* statement: inlr_stmt  */
#line 187 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1874 "build/parser.cpp"
    break;

  case 12: /* statement: return_stmt  */
#line 188 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1880 "build/parser.cpp"
    break;

  case 13: /* statement: if_stmt  */
#line 189 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1886 "build/parser.cpp"
    break;

  case 14: /* statement: dow_stmt  */
#line 190 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1892 "build/parser.cpp"
    break;

  case 15: /* statement: dou_stmt  */
#line 191 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1898 "build/parser.cpp"
    break;

  case 16: /* statement: for_stmt  */
#line 192 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1904 "build/parser.cpp"
    break;

  case 17: /* statement: select_stmt  */
#line 193 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1910 "build/parser.cpp"
    break;

  case 18: /* statement: iter_stmt  */
#line 194 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1916 "build/parser.cpp"
    break;

  case 19: /* statement: leave_stmt  */
#line 195 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1922 "build/parser.cpp"
    break;

  case 20: /* statement: dcl_proc_stmt  */
#line 196 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1928 "build/parser.cpp"
    break;

  case 21: /* statement: dcl_pr_stmt  */
#line 197 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1934 "build/parser.cpp"
    break;

  case 22: /* statement: dcl_ds_stmt  */
#line 198 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1940 "build/parser.cpp"
    break;

  case 23: /* statement: monitor_stmt  */
#line 199 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1946 "build/parser.cpp"
    break;

  case 24: /* statement: begsr_stmt  */
#line 200 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1952 "build/parser.cpp"
    break;

  case 25: /* statement: exsr_stmt  */
#line 201 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1958 "build/parser.cpp"
    break;

  case 26: /* statement: expr_stmt  */
#line 202 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 1964 "build/parser.cpp"
    break;

  case 27: /* statement: error SEMICOLON  */
#line 203 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 1970 "build/parser.cpp"
    break;

  case 28: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 208 "src/parser.y"
                                                                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        free((yyvsp[-6].sval));
    }
#line 1979 "build/parser.cpp"
    break;

  case 29: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 212 "src/parser.y"
                                                                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        free((yyvsp[-6].sval));
    }
#line 1988 "build/parser.cpp"
    break;

  case 30: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 216 "src/parser.y"
                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        free((yyvsp[-6].sval));
    }
#line 1997 "build/parser.cpp"
    break;

  case 31: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 220 "src/parser.y"
                                                                                                                 {
        (yyval.stmt) = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        free((yyvsp[-8].sval));
    }
#line 2006 "build/parser.cpp"
    break;

  case 32: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 224 "src/parser.y"
                                                                                                                {
        (yyval.stmt) = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        free((yyvsp[-8].sval));
    }
#line 2015 "build/parser.cpp"
    break;

  case 33: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 228 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2025 "build/parser.cpp"
    break;

  case 34: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 233 "src/parser.y"
                                                                                                                   {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2035 "build/parser.cpp"
    break;

  case 35: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 238 "src/parser.y"
                                                                                                                                           {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 2045 "build/parser.cpp"
    break;

  case 36: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 243 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2055 "build/parser.cpp"
    break;

  case 37: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 248 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2065 "build/parser.cpp"
    break;

  case 38: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 253 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 2075 "build/parser.cpp"
    break;

  case 39: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 258 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2085 "build/parser.cpp"
    break;

  case 40: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_DATE SEMICOLON  */
#line 263 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 2094 "build/parser.cpp"
    break;

  case 41: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIME SEMICOLON  */
#line 267 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 2103 "build/parser.cpp"
    break;

  case 42: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIMESTAMP SEMICOLON  */
#line 271 "src/parser.y"
                                                 {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 2112 "build/parser.cpp"
    break;

  case 44: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 283 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 2121 "build/parser.cpp"
    break;

  case 45: /* eval_target: IDENTIFIER  */
#line 290 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 2130 "build/parser.cpp"
    break;

  case 46: /* eval_target: INDICATOR  */
#line 294 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 2138 "build/parser.cpp"
    break;

  case 47: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 297 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 2149 "build/parser.cpp"
    break;

  case 48: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 303 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 2160 "build/parser.cpp"
    break;

  case 49: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 312 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 2171 "build/parser.cpp"
    break;

  case 50: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 318 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 2182 "build/parser.cpp"
    break;

  case 51: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 327 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 2190 "build/parser.cpp"
    break;

  case 52: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 333 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 2198 "build/parser.cpp"
    break;

  case 53: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 339 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 2206 "build/parser.cpp"
    break;

  case 54: /* return_stmt: KW_RETURN SEMICOLON  */
#line 342 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 2214 "build/parser.cpp"
    break;

  case 55: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 349 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 2224 "build/parser.cpp"
    break;

  case 56: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 360 "src/parser.y"
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
#line 2245 "build/parser.cpp"
    break;

  case 57: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 383 "src/parser.y"
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
#line 2270 "build/parser.cpp"
    break;

  case 58: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 407 "src/parser.y"
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
#line 2295 "build/parser.cpp"
    break;

  case 59: /* pi_return_type: %empty  */
#line 431 "src/parser.y"
               { (yyval.ival) = -1; }
#line 2301 "build/parser.cpp"
    break;

  case 60: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 432 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 2307 "build/parser.cpp"
    break;

  case 61: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 433 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 2313 "build/parser.cpp"
    break;

  case 62: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 434 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 2319 "build/parser.cpp"
    break;

  case 63: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 435 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 2325 "build/parser.cpp"
    break;

  case 64: /* pi_params: %empty  */
#line 440 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 2333 "build/parser.cpp"
    break;

  case 65: /* pi_params: pi_params pi_param  */
#line 443 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 2343 "build/parser.cpp"
    break;

  case 66: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 451 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2352 "build/parser.cpp"
    break;

  case 67: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 455 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2361 "build/parser.cpp"
    break;

  case 68: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 459 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2370 "build/parser.cpp"
    break;

  case 69: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 463 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2379 "build/parser.cpp"
    break;

  case 70: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 467 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2388 "build/parser.cpp"
    break;

  case 71: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 471 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2397 "build/parser.cpp"
    break;

  case 72: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 475 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 2406 "build/parser.cpp"
    break;

  case 73: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 479 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 2415 "build/parser.cpp"
    break;

  case 74: /* pr_params: %empty  */
#line 487 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 2423 "build/parser.cpp"
    break;

  case 75: /* pr_params: pr_params pr_param  */
#line 490 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 2433 "build/parser.cpp"
    break;

  case 76: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 498 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2442 "build/parser.cpp"
    break;

  case 77: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 502 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2451 "build/parser.cpp"
    break;

  case 78: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 506 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2460 "build/parser.cpp"
    break;

  case 79: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 510 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2469 "build/parser.cpp"
    break;

  case 80: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 514 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 2478 "build/parser.cpp"
    break;

  case 81: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 518 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 2487 "build/parser.cpp"
    break;

  case 82: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 522 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 2496 "build/parser.cpp"
    break;

  case 83: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 526 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 2505 "build/parser.cpp"
    break;

  case 84: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 535 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 2518 "build/parser.cpp"
    break;

  case 85: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 546 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 2530 "build/parser.cpp"
    break;

  case 86: /* exsr_stmt: KW_EXSR IDENTIFIER SEMICOLON  */
#line 556 "src/parser.y"
                                 {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 2539 "build/parser.cpp"
    break;

  case 87: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 566 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 2552 "build/parser.cpp"
    break;

  case 88: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 575 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 2565 "build/parser.cpp"
    break;

  case 89: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 584 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 2579 "build/parser.cpp"
    break;

  case 90: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 594 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 2593 "build/parser.cpp"
    break;

  case 91: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 604 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 2605 "build/parser.cpp"
    break;

  case 92: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 612 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 2618 "build/parser.cpp"
    break;

  case 93: /* ds_fields: %empty  */
#line 623 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 2626 "build/parser.cpp"
    break;

  case 94: /* ds_fields: ds_fields ds_field  */
#line 626 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 2636 "build/parser.cpp"
    break;

  case 95: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 634 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 2645 "build/parser.cpp"
    break;

  case 96: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 638 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 2654 "build/parser.cpp"
    break;

  case 97: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 642 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 2663 "build/parser.cpp"
    break;

  case 98: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 646 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 2672 "build/parser.cpp"
    break;

  case 99: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 655 "src/parser.y"
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
#line 2697 "build/parser.cpp"
    break;

  case 100: /* elseif_clauses: %empty  */
#line 678 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 2703 "build/parser.cpp"
    break;

  case 101: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 679 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 2713 "build/parser.cpp"
    break;

  case 102: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 687 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 2724 "build/parser.cpp"
    break;

  case 103: /* else_clause: %empty  */
#line 696 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 2730 "build/parser.cpp"
    break;

  case 104: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 697 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 2738 "build/parser.cpp"
    break;

  case 105: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 703 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 2749 "build/parser.cpp"
    break;

  case 106: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 712 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 2760 "build/parser.cpp"
    break;

  case 107: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 721 "src/parser.y"
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
#line 2775 "build/parser.cpp"
    break;

  case 108: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 731 "src/parser.y"
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
#line 2790 "build/parser.cpp"
    break;

  case 109: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 741 "src/parser.y"
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
#line 2805 "build/parser.cpp"
    break;

  case 110: /* for_stmt: KW_FOR IDENTIFIER EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 751 "src/parser.y"
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
#line 2820 "build/parser.cpp"
    break;

  case 111: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 764 "src/parser.y"
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
#line 2841 "build/parser.cpp"
    break;

  case 112: /* when_clauses: when_clause  */
#line 783 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 2850 "build/parser.cpp"
    break;

  case 113: /* when_clauses: when_clauses when_clause  */
#line 787 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 2859 "build/parser.cpp"
    break;

  case 114: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 794 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 2870 "build/parser.cpp"
    break;

  case 115: /* other_clause: %empty  */
#line 803 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 2876 "build/parser.cpp"
    break;

  case 116: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 804 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 2884 "build/parser.cpp"
    break;

  case 117: /* iter_stmt: KW_ITER SEMICOLON  */
#line 810 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 2890 "build/parser.cpp"
    break;

  case 118: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 814 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 2896 "build/parser.cpp"
    break;

  case 119: /* expression: or_expr  */
#line 820 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 2902 "build/parser.cpp"
    break;

  case 120: /* or_expr: and_expr  */
#line 824 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 2908 "build/parser.cpp"
    break;

  case 121: /* or_expr: or_expr KW_OR and_expr  */
#line 825 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2918 "build/parser.cpp"
    break;

  case 122: /* and_expr: not_expr  */
#line 833 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 2924 "build/parser.cpp"
    break;

  case 123: /* and_expr: and_expr KW_AND not_expr  */
#line 834 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2934 "build/parser.cpp"
    break;

  case 124: /* not_expr: comparison_expr  */
#line 842 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2940 "build/parser.cpp"
    break;

  case 125: /* not_expr: KW_NOT comparison_expr  */
#line 843 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2948 "build/parser.cpp"
    break;

  case 126: /* comparison_expr: additive_expr  */
#line 849 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2954 "build/parser.cpp"
    break;

  case 127: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 850 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2964 "build/parser.cpp"
    break;

  case 128: /* comparison_expr: comparison_expr NE additive_expr  */
#line 855 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2974 "build/parser.cpp"
    break;

  case 129: /* comparison_expr: comparison_expr LT additive_expr  */
#line 860 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2984 "build/parser.cpp"
    break;

  case 130: /* comparison_expr: comparison_expr GT additive_expr  */
#line 865 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 2994 "build/parser.cpp"
    break;

  case 131: /* comparison_expr: comparison_expr LE additive_expr  */
#line 870 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3004 "build/parser.cpp"
    break;

  case 132: /* comparison_expr: comparison_expr GE additive_expr  */
#line 875 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3014 "build/parser.cpp"
    break;

  case 133: /* additive_expr: multiplicative_expr  */
#line 883 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 3020 "build/parser.cpp"
    break;

  case 134: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 884 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3030 "build/parser.cpp"
    break;

  case 135: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 889 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3040 "build/parser.cpp"
    break;

  case 136: /* multiplicative_expr: unary_expr  */
#line 897 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 3046 "build/parser.cpp"
    break;

  case 137: /* multiplicative_expr: multiplicative_expr STAR unary_expr  */
#line 898 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3056 "build/parser.cpp"
    break;

  case 138: /* multiplicative_expr: multiplicative_expr SLASH unary_expr  */
#line 903 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3066 "build/parser.cpp"
    break;

  case 139: /* unary_expr: postfix_expr  */
#line 911 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 3072 "build/parser.cpp"
    break;

  case 140: /* unary_expr: MINUS postfix_expr  */
#line 912 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 3082 "build/parser.cpp"
    break;

  case 141: /* postfix_expr: primary_expr  */
#line 920 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 3088 "build/parser.cpp"
    break;

  case 142: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 921 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3097 "build/parser.cpp"
    break;

  case 143: /* primary_expr: IDENTIFIER  */
#line 928 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3106 "build/parser.cpp"
    break;

  case 144: /* primary_expr: INTEGER_LITERAL  */
#line 932 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 3114 "build/parser.cpp"
    break;

  case 145: /* primary_expr: FLOAT_LITERAL  */
#line 935 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 3122 "build/parser.cpp"
    break;

  case 146: /* primary_expr: STRING_LITERAL  */
#line 938 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3131 "build/parser.cpp"
    break;

  case 147: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 942 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 3140 "build/parser.cpp"
    break;

  case 148: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 946 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 3148 "build/parser.cpp"
    break;

  case 149: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 949 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 3156 "build/parser.cpp"
    break;

  case 150: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 952 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 3164 "build/parser.cpp"
    break;

  case 151: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 955 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 3172 "build/parser.cpp"
    break;

  case 152: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 958 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 3180 "build/parser.cpp"
    break;

  case 153: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 961 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 3188 "build/parser.cpp"
    break;

  case 154: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 964 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 3196 "build/parser.cpp"
    break;

  case 155: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 967 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 3204 "build/parser.cpp"
    break;

  case 156: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 970 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 3212 "build/parser.cpp"
    break;

  case 157: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 973 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 3220 "build/parser.cpp"
    break;

  case 158: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 976 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 3228 "build/parser.cpp"
    break;

  case 159: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 979 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 3236 "build/parser.cpp"
    break;

  case 160: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 982 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 3244 "build/parser.cpp"
    break;

  case 161: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 985 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 3253 "build/parser.cpp"
    break;

  case 162: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 989 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 3261 "build/parser.cpp"
    break;

  case 163: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 992 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 3270 "build/parser.cpp"
    break;

  case 164: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 996 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 3278 "build/parser.cpp"
    break;

  case 165: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 999 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 3287 "build/parser.cpp"
    break;

  case 166: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1003 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 3299 "build/parser.cpp"
    break;

  case 167: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1010 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 3311 "build/parser.cpp"
    break;

  case 168: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1017 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 3323 "build/parser.cpp"
    break;

  case 169: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 1024 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 3333 "build/parser.cpp"
    break;

  case 170: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 1029 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 3343 "build/parser.cpp"
    break;

  case 171: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 1034 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 3353 "build/parser.cpp"
    break;

  case 172: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 1039 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 3362 "build/parser.cpp"
    break;

  case 173: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 1043 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 3371 "build/parser.cpp"
    break;

  case 174: /* primary_expr: INDICATOR  */
#line 1047 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3379 "build/parser.cpp"
    break;

  case 175: /* primary_expr: KW_ON  */
#line 1050 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 3387 "build/parser.cpp"
    break;

  case 176: /* primary_expr: KW_OFF  */
#line 1053 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 3395 "build/parser.cpp"
    break;

  case 177: /* primary_expr: LPAREN expression RPAREN  */
#line 1056 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 3403 "build/parser.cpp"
    break;

  case 178: /* call_args_opt: %empty  */
#line 1063 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 3409 "build/parser.cpp"
    break;

  case 179: /* call_args_opt: call_arg_list  */
#line 1064 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 3415 "build/parser.cpp"
    break;

  case 180: /* call_arg_list: expression  */
#line 1068 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 3424 "build/parser.cpp"
    break;

  case 181: /* call_arg_list: call_arg_list COLON expression  */
#line 1072 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 3433 "build/parser.cpp"
    break;

  case 182: /* arg_list: expression  */
#line 1080 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 3442 "build/parser.cpp"
    break;

  case 183: /* arg_list: arg_list COLON expression  */
#line 1084 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 3451 "build/parser.cpp"
    break;


#line 3455 "build/parser.cpp"

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

#line 1090 "src/parser.y"


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
