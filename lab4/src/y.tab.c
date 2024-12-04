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
#line 1 "ss.y"


#include <stdio.h>
#include <string.h>
#include "cst.h"

int yylex(void);
void yyerror(char *);

node *root;


#line 84 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INT_LIT = 259,                 /* INT_LIT  */
    FLOAT_LIT = 260,               /* FLOAT_LIT  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    VOID = 263,                    /* VOID  */
    CONST = 264,                   /* CONST  */
    RETURN = 265,                  /* RETURN  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    BREAK = 269,                   /* BREAK  */
    CONTINUE = 270,                /* CONTINUE  */
    LP = 271,                      /* LP  */
    RP = 272,                      /* RP  */
    LB = 273,                      /* LB  */
    RB = 274,                      /* RB  */
    LC = 275,                      /* LC  */
    RC = 276,                      /* RC  */
    COMMA = 277,                   /* COMMA  */
    SEMICN = 278,                  /* SEMICN  */
    MINUS = 279,                   /* MINUS  */
    NOT = 280,                     /* NOT  */
    ASSIGN = 281,                  /* ASSIGN  */
    PLUS = 282,                    /* PLUS  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    LT = 290,                      /* LT  */
    LE = 291,                      /* LE  */
    GT = 292,                      /* GT  */
    GE = 293                       /* GE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT_LIT 259
#define FLOAT_LIT 260
#define INT 261
#define FLOAT 262
#define VOID 263
#define CONST 264
#define RETURN 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define BREAK 269
#define CONTINUE 270
#define LP 271
#define RP 272
#define LB 273
#define RB 274
#define LC 275
#define RC 276
#define COMMA 277
#define SEMICN 278
#define MINUS 279
#define NOT 280
#define ASSIGN 281
#define PLUS 282
#define MUL 283
#define DIV 284
#define MOD 285
#define AND 286
#define OR 287
#define EQ 288
#define NE 289
#define LT 290
#define LE 291
#define GT 292
#define GE 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "ss.y"

    int int_val;
    float float_val;
    char *str_val;
    struct Node *node_val;

#line 220 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT_LIT = 4,                    /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 5,                  /* FLOAT_LIT  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_CONST = 9,                      /* CONST  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_LP = 16,                        /* LP  */
  YYSYMBOL_RP = 17,                        /* RP  */
  YYSYMBOL_LB = 18,                        /* LB  */
  YYSYMBOL_RB = 19,                        /* RB  */
  YYSYMBOL_LC = 20,                        /* LC  */
  YYSYMBOL_RC = 21,                        /* RC  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_SEMICN = 23,                    /* SEMICN  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_LE = 36,                        /* LE  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_Root = 40,                      /* Root  */
  YYSYMBOL_CompUnit = 41,                  /* CompUnit  */
  YYSYMBOL_ConstDecl = 42,                 /* ConstDecl  */
  YYSYMBOL_ConstDef = 43,                  /* ConstDef  */
  YYSYMBOL_ConstExpArray = 44,             /* ConstExpArray  */
  YYSYMBOL_ConstInitVal = 45,              /* ConstInitVal  */
  YYSYMBOL_ConstExp = 46,                  /* ConstExp  */
  YYSYMBOL_VarDecl = 47,                   /* VarDecl  */
  YYSYMBOL_VarDef = 48,                    /* VarDef  */
  YYSYMBOL_InitVal = 49,                   /* InitVal  */
  YYSYMBOL_InitVals = 50,                  /* InitVals  */
  YYSYMBOL_FuncDef = 51,                   /* FuncDef  */
  YYSYMBOL_FuncFParam = 52,                /* FuncFParam  */
  YYSYMBOL_Block = 53,                     /* Block  */
  YYSYMBOL_BlockItem = 54,                 /* BlockItem  */
  YYSYMBOL_Stmt = 55,                      /* Stmt  */
  YYSYMBOL_Exp = 56,                       /* Exp  */
  YYSYMBOL_AddExp = 57,                    /* AddExp  */
  YYSYMBOL_MulExp = 58,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 59,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 60,               /* FuncRParams  */
  YYSYMBOL_PrimaryExp = 61,                /* PrimaryExp  */
  YYSYMBOL_LVal = 62,                      /* LVal  */
  YYSYMBOL_Cond = 63,                      /* Cond  */
  YYSYMBOL_LOrExp = 64,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 65,                   /* LAndExp  */
  YYSYMBOL_EqExp = 66,                     /* EqExp  */
  YYSYMBOL_RelExp = 67,                    /* RelExp  */
  YYSYMBOL_ExpArray = 68                   /* ExpArray  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    40,    41,    42,    43,    44,    45,    48,
      49,    52,    53,    56,    57,    60,    61,    62,    63,    66,
      67,    68,    71,    72,    75,    76,    77,    78,    81,    82,
      83,    86,    87,    90,    91,    92,    93,    94,    95,    98,
      99,   100,   101,   102,   103,   104,   105,   108,   110,   111,
     112,   113,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   128,   130,   131,   132,   135,   136,   137,   138,
     141,   142,   143,   144,   145,   146,   149,   150,   153,   154,
     155,   156,   159,   161,   163,   164,   167,   168,   171,   172,
     173,   176,   177,   178,   179,   180,   183,   184
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT_LIT",
  "FLOAT_LIT", "INT", "FLOAT", "VOID", "CONST", "RETURN", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "LP", "RP", "LB", "RB", "LC", "RC",
  "COMMA", "SEMICN", "MINUS", "NOT", "ASSIGN", "PLUS", "MUL", "DIV", "MOD",
  "AND", "OR", "EQ", "NE", "LT", "LE", "GT", "GE", "$accept", "Root",
  "CompUnit", "ConstDecl", "ConstDef", "ConstExpArray", "ConstInitVal",
  "ConstExp", "VarDecl", "VarDef", "InitVal", "InitVals", "FuncDef",
  "FuncFParam", "Block", "BlockItem", "Stmt", "Exp", "AddExp", "MulExp",
  "UnaryExp", "FuncRParams", "PrimaryExp", "LVal", "Cond", "LOrExp",
  "LAndExp", "EqExp", "RelExp", "ExpArray", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     236,    22,    33,    39,    86,    10,  -172,   236,   236,   236,
       1,    37,   150,    51,    65,   103,   103,  -172,  -172,  -172,
    -172,     6,   214,     7,  -172,    14,  -172,    41,    71,   115,
     119,   143,   149,   163,   152,   164,  -172,  -172,   214,   214,
     214,   214,   171,    48,    83,  -172,  -172,   188,   182,   163,
     177,   163,   179,   178,  -172,  -172,    21,    43,    94,  -172,
     163,   112,   214,  -172,   180,  -172,    64,  -172,  -172,  -172,
      71,   214,   214,   214,   214,   214,    71,  -172,   154,   181,
    -172,  -172,   163,  -172,   163,   196,   186,    89,   189,    89,
     188,   188,   210,   194,   195,   199,   201,    94,    94,  -172,
     204,    94,   205,   203,  -172,  -172,   209,   215,   208,  -172,
     214,   214,  -172,  -172,  -172,  -172,  -172,  -172,  -172,   218,
     233,   188,  -172,  -172,   168,   234,  -172,   237,  -172,   237,
    -172,  -172,   213,   214,   214,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,   214,   214,  -172,   237,  -172,  -172,   182,  -172,
    -172,  -172,   101,   103,   235,   238,  -172,   211,   241,  -172,
     227,   230,    97,   245,   240,  -172,  -172,  -172,  -172,   196,
    -172,    89,    89,   214,   214,   214,   214,   140,   214,   214,
     214,   214,   140,  -172,   243,  -172,  -172,  -172,  -172,  -172,
    -172,   253,  -172,  -172,  -172,  -172,  -172,  -172,   140,  -172
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
      13,     0,    13,     0,     0,     0,     0,     1,     6,     7,
       8,     0,     0,    24,    22,     0,    23,     0,    13,     0,
       0,     0,     0,     0,     0,    96,    80,    81,     0,     0,
       0,     0,     0,    19,    66,    70,    79,     0,     0,     0,
       0,     0,     0,     0,     9,    10,    39,    40,    48,    33,
       0,     0,     0,    82,     0,    62,    63,    74,    75,    73,
      13,     0,     0,     0,     0,     0,    13,    26,     0,    25,
      28,    34,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    48,    54,
       0,    48,     0,    79,    36,    71,    76,     0,     0,    78,
       0,     0,    14,    21,    20,    67,    68,    69,    29,    31,
       0,     0,    37,    38,     0,    11,    15,    96,    43,    96,
      44,    61,     0,     0,     0,    58,    59,    49,    50,    47,
      51,    53,     0,     0,    72,    96,    65,    64,     0,    30,
      27,    16,     0,     0,    41,    42,    60,    91,     0,    83,
      84,    86,    88,     0,     0,    77,    97,    32,    17,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,    45,    46,    92,    94,    93,
      95,    55,    85,    87,    89,    90,    57,    18,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,   126,   -30,   -13,   -21,  -115,   244,   -28,     3,
     219,   120,  -172,   -23,   -25,   -11,  -171,   -16,   -96,   -22,
     122,   127,  -172,   -57,   135,    93,    95,    -4,    77,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    29,    23,   125,   126,     8,    11,
     119,   120,     9,    34,    99,   100,   101,   102,    65,    66,
      44,   107,    45,    46,   158,   159,   160,   161,   162,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,   103,    50,    30,    52,    13,   191,    53,    59,   152,
      17,   196,    31,    32,   146,   147,   154,    21,   155,    22,
      31,    32,    64,    33,    81,    10,    83,   199,    97,    47,
      98,    49,    80,    48,   166,   104,    12,   157,   157,    86,
     103,   103,    14,    87,   103,   106,   108,    31,    32,   112,
      77,   115,   116,   117,   184,   113,   114,   122,    51,   123,
      24,    88,    80,    43,   128,    89,   130,    97,    97,    98,
      98,    97,    71,    98,    26,    72,   132,   157,   157,   157,
     157,    27,   157,   157,   157,   157,   137,   138,   110,    22,
     140,   111,    15,    16,    13,    31,    32,    35,    36,    37,
      90,    91,    43,     4,    92,    93,    28,    94,    95,    96,
      38,    73,    74,    75,    58,    35,    36,    37,    39,    40,
     103,    41,   168,   169,   150,   103,   164,   106,    38,   105,
     180,   181,    80,    18,    19,    20,    39,    40,    54,    41,
     170,   103,    55,    35,    36,    37,    56,    43,   185,   186,
      92,    93,    57,    94,    95,    96,    38,    35,    36,    37,
      58,    67,    68,    69,    39,    40,    25,    41,    22,    60,
      38,    35,    36,    37,    78,   118,   194,   195,    39,    40,
      61,    41,    62,    58,    38,    35,    36,    37,   124,   151,
      70,    76,    39,    40,    82,    41,    84,   109,    38,    35,
      36,    37,    78,   121,    85,   127,    39,    40,   129,    41,
     133,   134,    38,    35,    36,    37,   124,    35,    36,    37,
      39,    40,   135,    41,   136,   139,    38,   145,   141,   142,
      38,   143,   144,   131,    39,    40,   156,    41,    39,    40,
     148,    41,     1,     2,     3,     4,   173,   174,   175,   176,
     187,   188,   189,   190,   149,    62,   153,   171,   177,   178,
     172,   179,   182,   183,   197,   198,    42,    79,   167,   163,
     165,   192,     0,     0,   193
};

static const yytype_int16 yycheck[] =
{
      22,    58,    25,    16,    27,     2,   177,    28,    33,   124,
       0,   182,     6,     7,   110,   111,   127,    16,   129,    18,
       6,     7,    38,    17,    49,     3,    51,   198,    58,    22,
      58,    17,    48,    26,   145,    60,     3,   133,   134,    18,
      97,    98,     3,    22,   101,    61,    62,     6,     7,    70,
      47,    73,    74,    75,   169,    71,    72,    82,    17,    84,
      23,    18,    78,    85,    87,    22,    89,    97,    98,    97,
      98,   101,    24,   101,    23,    27,    92,   173,   174,   175,
     176,    16,   178,   179,   180,   181,    97,    98,    24,    18,
     101,    27,     6,     7,    91,     6,     7,     3,     4,     5,
       6,     7,   124,     9,    10,    11,     3,    13,    14,    15,
      16,    28,    29,    30,    20,     3,     4,     5,    24,    25,
     177,    27,    21,    22,   121,   182,   142,   143,    16,    17,
      33,    34,   148,     7,     8,     9,    24,    25,    23,    27,
     153,   198,    23,     3,     4,     5,     3,   169,   171,   172,
      10,    11,     3,    13,    14,    15,    16,     3,     4,     5,
      20,    39,    40,    41,    24,    25,    16,    27,    18,    17,
      16,     3,     4,     5,    20,    21,   180,   181,    24,    25,
      16,    27,    18,    20,    16,     3,     4,     5,    20,    21,
      19,     3,    24,    25,    17,    27,    17,    17,    16,     3,
       4,     5,    20,    22,    26,    19,    24,    25,    19,    27,
      16,    16,    16,     3,     4,     5,    20,     3,     4,     5,
      24,    25,    23,    27,    23,    21,    16,    19,    23,    26,
      16,    22,    17,    23,    24,    25,    23,    27,    24,    25,
      22,    27,     6,     7,     8,     9,    35,    36,    37,    38,
     173,   174,   175,   176,    21,    18,    22,    22,    17,    32,
      22,    31,    17,    23,    21,    12,    22,    48,   148,   134,
     143,   178,    -1,    -1,   179
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    40,    41,    42,    47,    51,
       3,    48,     3,    48,     3,     6,     7,     0,    41,    41,
      41,    16,    18,    44,    23,    16,    23,    16,     3,    43,
      43,     6,     7,    17,    52,     3,     4,     5,    16,    24,
      25,    27,    46,    58,    59,    61,    62,    22,    26,    17,
      52,    17,    52,    44,    23,    23,     3,     3,    20,    53,
      17,    16,    18,    68,    56,    57,    58,    59,    59,    59,
      19,    24,    27,    28,    29,    30,     3,    48,    20,    49,
      56,    53,    17,    53,    17,    26,    18,    22,    18,    22,
       6,     7,    10,    11,    13,    14,    15,    42,    47,    53,
      54,    55,    56,    62,    53,    17,    56,    60,    56,    17,
      24,    27,    44,    56,    56,    58,    58,    58,    21,    49,
      50,    22,    53,    53,    20,    45,    46,    19,    52,    19,
      52,    23,    56,    16,    16,    23,    23,    54,    54,    21,
      54,    23,    26,    22,    17,    19,    57,    57,    22,    21,
      48,    21,    45,    22,    68,    68,    23,    57,    63,    64,
      65,    66,    67,    63,    56,    60,    68,    50,    21,    22,
      43,    22,    22,    35,    36,    37,    38,    17,    32,    31,
      33,    34,    17,    23,    45,    52,    52,    67,    67,    67,
      67,    55,    64,    65,    66,    66,    55,    21,    12,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    41,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    45,    45,    46,
      46,    46,    47,    47,    48,    48,    48,    48,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    57,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    62,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     4,
       4,     4,     6,     0,     4,     1,     2,     3,     5,     1,
       3,     3,     3,     3,     2,     4,     4,     6,     1,     2,
       3,     1,     3,     5,     5,     5,     6,     6,     6,     2,
       2,     5,     5,     4,     4,     7,     7,     3,     0,     2,
       2,     2,     4,     2,     1,     5,     7,     5,     2,     2,
       3,     2,     1,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     4,     2,     2,     2,     1,     3,     3,     1,
       1,     1,     2,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     0,     4
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
  case 2: /* Root: CompUnit  */
#line 38 "ss.y"
               { root = append(Root, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1407 "y.tab.c"
    break;

  case 3: /* CompUnit: ConstDecl  */
#line 40 "ss.y"
                                { (yyval.node_val) = append(CompUnit, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1413 "y.tab.c"
    break;

  case 4: /* CompUnit: VarDecl  */
#line 41 "ss.y"
                                { (yyval.node_val) = append(CompUnit, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1419 "y.tab.c"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 42 "ss.y"
                                { (yyval.node_val) = append(CompUnit, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1425 "y.tab.c"
    break;

  case 6: /* CompUnit: ConstDecl CompUnit  */
#line 43 "ss.y"
                                { (yyval.node_val) = append(CompUnit, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1431 "y.tab.c"
    break;

  case 7: /* CompUnit: VarDecl CompUnit  */
#line 44 "ss.y"
                                { (yyval.node_val) = append(CompUnit, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1437 "y.tab.c"
    break;

  case 8: /* CompUnit: FuncDef CompUnit  */
#line 45 "ss.y"
                                { (yyval.node_val) = append(CompUnit, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1443 "y.tab.c"
    break;

  case 9: /* ConstDecl: CONST INT ConstDef SEMICN  */
#line 48 "ss.y"
                                        { (yyval.node_val) = append(ConstDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Int); }
#line 1449 "y.tab.c"
    break;

  case 10: /* ConstDecl: CONST FLOAT ConstDef SEMICN  */
#line 49 "ss.y"
                                        { (yyval.node_val) = append(ConstDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Float); }
#line 1455 "y.tab.c"
    break;

  case 11: /* ConstDef: ID ConstExpArray ASSIGN ConstInitVal  */
#line 52 "ss.y"
                                                                { (yyval.node_val) = append(ConstDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), NonType); }
#line 1461 "y.tab.c"
    break;

  case 12: /* ConstDef: ID ConstExpArray ASSIGN ConstInitVal COMMA ConstDef  */
#line 53 "ss.y"
                                                                { (yyval.node_val) = append(ConstDef, (yyvsp[0].node_val), (yyvsp[-4].node_val), (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), NonType); }
#line 1467 "y.tab.c"
    break;

  case 13: /* ConstExpArray: %empty  */
#line 56 "ss.y"
                                                { (yyval.node_val) = NULL; }
#line 1473 "y.tab.c"
    break;

  case 14: /* ConstExpArray: LB ConstExp RB ConstExpArray  */
#line 57 "ss.y"
                                                { (yyval.node_val) = append(ConstExpArray, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1479 "y.tab.c"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 60 "ss.y"
                                                        { (yyval.node_val) = append(ConstInitVal, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1485 "y.tab.c"
    break;

  case 16: /* ConstInitVal: LC RC  */
#line 61 "ss.y"
                                                        { (yyval.node_val) = append(ConstInitVal, NULL, NULL, NULL, 0, 0, NULL, NonType); }
#line 1491 "y.tab.c"
    break;

  case 17: /* ConstInitVal: LC ConstInitVal RC  */
#line 62 "ss.y"
                                                        { (yyval.node_val) = append(ConstInitVal, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1497 "y.tab.c"
    break;

  case 18: /* ConstInitVal: LC ConstInitVal COMMA ConstInitVal RC  */
#line 63 "ss.y"
                                                        { (yyval.node_val) = append(ConstInitVal, (yyvsp[-1].node_val), NULL, (yyvsp[-3].node_val), 0, 0, NULL, NonType); }
#line 1503 "y.tab.c"
    break;

  case 19: /* ConstExp: MulExp  */
#line 66 "ss.y"
                                { (yyval.node_val) = append(ConstExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1509 "y.tab.c"
    break;

  case 20: /* ConstExp: MulExp PLUS Exp  */
#line 67 "ss.y"
                                { (yyval.node_val) = append(ConstExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), PLUS, 0, NULL, NonType); }
#line 1515 "y.tab.c"
    break;

  case 21: /* ConstExp: MulExp MINUS Exp  */
#line 68 "ss.y"
                                { (yyval.node_val) = append(ConstExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), MINUS, 0, NULL, NonType); }
#line 1521 "y.tab.c"
    break;

  case 22: /* VarDecl: INT VarDef SEMICN  */
#line 71 "ss.y"
                                { (yyval.node_val) = append(VarDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Int); }
#line 1527 "y.tab.c"
    break;

  case 23: /* VarDecl: FLOAT VarDef SEMICN  */
#line 72 "ss.y"
                                { (yyval.node_val) = append(VarDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Float); }
#line 1533 "y.tab.c"
    break;

  case 24: /* VarDef: ID ConstExpArray  */
#line 75 "ss.y"
                                                        { (yyval.node_val) = append(VarDef, NULL, (yyvsp[0].node_val), NULL, 0, 0, (yyvsp[-1].str_val), NonType); }
#line 1539 "y.tab.c"
    break;

  case 25: /* VarDef: ID ConstExpArray ASSIGN InitVal  */
#line 76 "ss.y"
                                                        { (yyval.node_val) = append(VarDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), NonType); }
#line 1545 "y.tab.c"
    break;

  case 26: /* VarDef: ID ConstExpArray COMMA VarDef  */
#line 77 "ss.y"
                                                        { (yyval.node_val) = append(VarDef, (yyvsp[0].node_val), (yyvsp[-2].node_val), NULL, 0, 0, (yyvsp[-3].str_val), NonType); }
#line 1551 "y.tab.c"
    break;

  case 27: /* VarDef: ID ConstExpArray ASSIGN InitVal COMMA VarDef  */
#line 78 "ss.y"
                                                        { (yyval.node_val) = append(VarDef, (yyvsp[0].node_val), (yyvsp[-4].node_val), (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), NonType); }
#line 1557 "y.tab.c"
    break;

  case 28: /* InitVal: Exp  */
#line 81 "ss.y"
                        { (yyval.node_val) = append(InitVal, NULL, NULL, (yyvsp[0].node_val), Exp, 0, NULL, NonType); }
#line 1563 "y.tab.c"
    break;

  case 29: /* InitVal: LC RC  */
#line 82 "ss.y"
                        { (yyval.node_val) = append(InitVal, NULL, NULL, NULL, InitVals, 0, NULL, NonType); }
#line 1569 "y.tab.c"
    break;

  case 30: /* InitVal: LC InitVals RC  */
#line 83 "ss.y"
                        { (yyval.node_val) = append(InitVal, NULL, NULL, (yyvsp[-1].node_val), InitVals, 0, NULL, NonType); }
#line 1575 "y.tab.c"
    break;

  case 31: /* InitVals: InitVal  */
#line 86 "ss.y"
                                        { (yyval.node_val) = append(InitVals, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1581 "y.tab.c"
    break;

  case 32: /* InitVals: InitVal COMMA InitVals  */
#line 87 "ss.y"
                                        { (yyval.node_val) = append(InitVals, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1587 "y.tab.c"
    break;

  case 33: /* FuncDef: INT ID LP RP Block  */
#line 90 "ss.y"
                                                { (yyval.node_val) = append(FuncDef, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Int); }
#line 1593 "y.tab.c"
    break;

  case 34: /* FuncDef: FLOAT ID LP RP Block  */
#line 91 "ss.y"
                                                { (yyval.node_val) = append(FuncDef, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Float); }
#line 1599 "y.tab.c"
    break;

  case 35: /* FuncDef: VOID ID LP RP Block  */
#line 92 "ss.y"
                                                { (yyval.node_val) = append(FuncDef, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Void); }
#line 1605 "y.tab.c"
    break;

  case 36: /* FuncDef: INT ID LP FuncFParam RP Block  */
#line 93 "ss.y"
                                                { (yyval.node_val) = append(FuncDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-4].str_val), Int); }
#line 1611 "y.tab.c"
    break;

  case 37: /* FuncDef: FLOAT ID LP FuncFParam RP Block  */
#line 94 "ss.y"
                                                { (yyval.node_val) = append(FuncDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-4].str_val), Float); }
#line 1617 "y.tab.c"
    break;

  case 38: /* FuncDef: VOID ID LP FuncFParam RP Block  */
#line 95 "ss.y"
                                                { (yyval.node_val) = append(FuncDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-4].str_val), Void); }
#line 1623 "y.tab.c"
    break;

  case 39: /* FuncFParam: INT ID  */
#line 98 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, NULL, NULL, NULL, 0, 0, (yyvsp[0].str_val), Int); }
#line 1629 "y.tab.c"
    break;

  case 40: /* FuncFParam: FLOAT ID  */
#line 99 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, NULL, NULL, NULL, 0, 0, (yyvsp[0].str_val), Float); }
#line 1635 "y.tab.c"
    break;

  case 41: /* FuncFParam: INT ID LB RB ExpArray  */
#line 100 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Int); }
#line 1641 "y.tab.c"
    break;

  case 42: /* FuncFParam: FLOAT ID LB RB ExpArray  */
#line 101 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Float); }
#line 1647 "y.tab.c"
    break;

  case 43: /* FuncFParam: INT ID COMMA FuncFParam  */
#line 102 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, (yyvsp[0].node_val), NULL, NULL, 0, 0, (yyvsp[-2].str_val), Int); }
#line 1653 "y.tab.c"
    break;

  case 44: /* FuncFParam: FLOAT ID COMMA FuncFParam  */
#line 103 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, (yyvsp[0].node_val), NULL, NULL, 0, 0, (yyvsp[-2].str_val), Float); }
#line 1659 "y.tab.c"
    break;

  case 45: /* FuncFParam: INT ID LB RB ExpArray COMMA FuncFParam  */
#line 104 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), Int); }
#line 1665 "y.tab.c"
    break;

  case 46: /* FuncFParam: FLOAT ID LB RB ExpArray COMMA FuncFParam  */
#line 105 "ss.y"
                                                        { (yyval.node_val) = append(FuncFParam, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), Float); }
#line 1671 "y.tab.c"
    break;

  case 47: /* Block: LC BlockItem RC  */
#line 108 "ss.y"
                       { (yyval.node_val) = append(Block, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1677 "y.tab.c"
    break;

  case 48: /* BlockItem: %empty  */
#line 110 "ss.y"
                                { (yyval.node_val) = NULL; }
#line 1683 "y.tab.c"
    break;

  case 49: /* BlockItem: ConstDecl BlockItem  */
#line 111 "ss.y"
                                { (yyval.node_val) = append(BlockItem, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1689 "y.tab.c"
    break;

  case 50: /* BlockItem: VarDecl BlockItem  */
#line 112 "ss.y"
                                { (yyval.node_val) = append(BlockItem, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1695 "y.tab.c"
    break;

  case 51: /* BlockItem: Stmt BlockItem  */
#line 113 "ss.y"
                                { (yyval.node_val) = append(BlockItem, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1701 "y.tab.c"
    break;

  case 52: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 116 "ss.y"
                                     { (yyval.node_val) = append(AssignStmt, (yyvsp[-1].node_val), NULL, (yyvsp[-3].node_val), 0, 0, NULL, NonType); }
#line 1707 "y.tab.c"
    break;

  case 53: /* Stmt: Exp SEMICN  */
#line 117 "ss.y"
                                     { (yyval.node_val) = append(ExpStmt, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1713 "y.tab.c"
    break;

  case 54: /* Stmt: Block  */
#line 118 "ss.y"
                                     { (yyval.node_val) = append(BlockStmt, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1719 "y.tab.c"
    break;

  case 55: /* Stmt: IF LP Cond RP Stmt  */
#line 119 "ss.y"
                                     { (yyval.node_val) = append(IfStmt, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1725 "y.tab.c"
    break;

  case 56: /* Stmt: IF LP Cond RP Stmt ELSE Stmt  */
#line 120 "ss.y"
                                     { (yyval.node_val) = append(IfElseStmt, (yyvsp[0].node_val), (yyvsp[-2].node_val), (yyvsp[-4].node_val), 0, 0, NULL, NonType); }
#line 1731 "y.tab.c"
    break;

  case 57: /* Stmt: WHILE LP Cond RP Stmt  */
#line 121 "ss.y"
                                     { (yyval.node_val) = append(WhileStmt, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1737 "y.tab.c"
    break;

  case 58: /* Stmt: BREAK SEMICN  */
#line 122 "ss.y"
                                     { (yyval.node_val) = append(BreakStmt, NULL, NULL, NULL, 0, 0, NULL, NonType); }
#line 1743 "y.tab.c"
    break;

  case 59: /* Stmt: CONTINUE SEMICN  */
#line 123 "ss.y"
                                     { (yyval.node_val) = append(ContinueStmt, NULL, NULL, NULL, 0, 0, NULL, NonType); }
#line 1749 "y.tab.c"
    break;

  case 60: /* Stmt: RETURN Exp SEMICN  */
#line 124 "ss.y"
                                     { (yyval.node_val) = append(ReturnStmt, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1755 "y.tab.c"
    break;

  case 61: /* Stmt: RETURN SEMICN  */
#line 125 "ss.y"
                                     { (yyval.node_val) = append(BlankReturnStmt, NULL, NULL, NULL, 0, 0, NULL, NonType); }
#line 1761 "y.tab.c"
    break;

  case 62: /* Exp: AddExp  */
#line 128 "ss.y"
                { (yyval.node_val) = append(Exp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1767 "y.tab.c"
    break;

  case 63: /* AddExp: MulExp  */
#line 130 "ss.y"
                                { (yyval.node_val) = append(AddExp, NULL, NULL, (yyvsp[0].node_val), Mul, 0, NULL, NonType); }
#line 1773 "y.tab.c"
    break;

  case 64: /* AddExp: MulExp PLUS AddExp  */
#line 131 "ss.y"
                                { (yyval.node_val) = append(AddExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), Plus, 0, NULL, NonType); }
#line 1779 "y.tab.c"
    break;

  case 65: /* AddExp: MulExp MINUS AddExp  */
#line 132 "ss.y"
                                { (yyval.node_val) = append(AddExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), Minus, 0, NULL, NonType); }
#line 1785 "y.tab.c"
    break;

  case 66: /* MulExp: UnaryExp  */
#line 135 "ss.y"
                                { (yyval.node_val) = append(MulExp, NULL, NULL, (yyvsp[0].node_val), UnaryExp, 0, NULL, NonType); }
#line 1791 "y.tab.c"
    break;

  case 67: /* MulExp: UnaryExp MUL MulExp  */
#line 136 "ss.y"
                                { (yyval.node_val) = append(MulExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), Mul, 0, NULL, NonType); }
#line 1797 "y.tab.c"
    break;

  case 68: /* MulExp: UnaryExp DIV MulExp  */
#line 137 "ss.y"
                                { (yyval.node_val) = append(MulExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), Div, 0, NULL, NonType); }
#line 1803 "y.tab.c"
    break;

  case 69: /* MulExp: UnaryExp MOD MulExp  */
#line 138 "ss.y"
                                { (yyval.node_val) = append(MulExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), Mod, 0, NULL, NonType); }
#line 1809 "y.tab.c"
    break;

  case 70: /* UnaryExp: PrimaryExp  */
#line 141 "ss.y"
                                { (yyval.node_val) = append(UnaryExp, NULL, NULL, (yyvsp[0].node_val), PrimaryExp, 0, NULL, NonType); }
#line 1815 "y.tab.c"
    break;

  case 71: /* UnaryExp: ID LP RP  */
#line 142 "ss.y"
                                { (yyval.node_val) = append(UnaryExp, NULL, NULL, NULL, FuncRParams, 0, (yyvsp[-2].str_val), NonType); }
#line 1821 "y.tab.c"
    break;

  case 72: /* UnaryExp: ID LP FuncRParams RP  */
#line 143 "ss.y"
                                { (yyval.node_val) = append(UnaryExp, NULL, NULL, (yyvsp[-1].node_val), FuncRParams, 0, (yyvsp[-3].str_val), NonType); }
#line 1827 "y.tab.c"
    break;

  case 73: /* UnaryExp: PLUS UnaryExp  */
#line 144 "ss.y"
                                { (yyval.node_val) = append(UnaryExp, NULL, NULL, (yyvsp[0].node_val), PLUS, 0, NULL, NonType); }
#line 1833 "y.tab.c"
    break;

  case 74: /* UnaryExp: MINUS UnaryExp  */
#line 145 "ss.y"
                                { (yyval.node_val) = append(UnaryExp, NULL, NULL, (yyvsp[0].node_val), MINUS, 0, NULL, NonType); }
#line 1839 "y.tab.c"
    break;

  case 75: /* UnaryExp: NOT UnaryExp  */
#line 146 "ss.y"
                                { (yyval.node_val) = append(UnaryExp, NULL, NULL, (yyvsp[0].node_val), Not, 0, NULL, NonType); }
#line 1845 "y.tab.c"
    break;

  case 76: /* FuncRParams: Exp  */
#line 149 "ss.y"
                                        { (yyval.node_val) = append(FuncRParams, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1851 "y.tab.c"
    break;

  case 77: /* FuncRParams: Exp COMMA FuncRParams  */
#line 150 "ss.y"
                                        { (yyval.node_val) = append(FuncRParams, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1857 "y.tab.c"
    break;

  case 78: /* PrimaryExp: LP Exp RP  */
#line 153 "ss.y"
                        { (yyval.node_val) = append(PrimaryExp, NULL, NULL, (yyvsp[-1].node_val), Exp, 0, NULL, NonType); }
#line 1863 "y.tab.c"
    break;

  case 79: /* PrimaryExp: LVal  */
#line 154 "ss.y"
                        { (yyval.node_val) = append(PrimaryExp, NULL, NULL, (yyvsp[0].node_val), LVal, 0, NULL, NonType); }
#line 1869 "y.tab.c"
    break;

  case 80: /* PrimaryExp: INT_LIT  */
#line 155 "ss.y"
                        { (yyval.node_val) = append(PrimaryExp, NULL, NULL, NULL, (yyvsp[0].int_val), 0, NULL, Int); }
#line 1875 "y.tab.c"
    break;

  case 81: /* PrimaryExp: FLOAT_LIT  */
#line 156 "ss.y"
                        { (yyval.node_val) = append(PrimaryExp, NULL, NULL, NULL, 0, (yyvsp[0].float_val), NULL, Float); }
#line 1881 "y.tab.c"
    break;

  case 82: /* LVal: ID ExpArray  */
#line 159 "ss.y"
                        { (yyval.node_val) = append(LVal, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-1].str_val), NonType); }
#line 1887 "y.tab.c"
    break;

  case 83: /* Cond: LOrExp  */
#line 161 "ss.y"
                        { (yyval.node_val) = append(Cond, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1893 "y.tab.c"
    break;

  case 84: /* LOrExp: LAndExp  */
#line 163 "ss.y"
                                { (yyval.node_val) = append(Cond, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1899 "y.tab.c"
    break;

  case 85: /* LOrExp: LAndExp OR LOrExp  */
#line 164 "ss.y"
                                { (yyval.node_val) = append(Cond, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), OR, 0, 0, NonType); }
#line 1905 "y.tab.c"
    break;

  case 86: /* LAndExp: EqExp  */
#line 167 "ss.y"
                                { (yyval.node_val) = append(LAndExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1911 "y.tab.c"
    break;

  case 87: /* LAndExp: EqExp AND LAndExp  */
#line 168 "ss.y"
                                { (yyval.node_val) = append(LAndExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), AND, 0, NULL, NonType); }
#line 1917 "y.tab.c"
    break;

  case 88: /* EqExp: RelExp  */
#line 171 "ss.y"
                        { (yyval.node_val) = append(EqExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1923 "y.tab.c"
    break;

  case 89: /* EqExp: RelExp EQ EqExp  */
#line 172 "ss.y"
                        { (yyval.node_val) = append(EqExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), EQ, 0, NULL, NonType); }
#line 1929 "y.tab.c"
    break;

  case 90: /* EqExp: RelExp NE EqExp  */
#line 173 "ss.y"
                        { (yyval.node_val) = append(EqExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), NE, 0, NULL, NonType); }
#line 1935 "y.tab.c"
    break;

  case 91: /* RelExp: AddExp  */
#line 176 "ss.y"
                         { (yyval.node_val) = append(RelExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1941 "y.tab.c"
    break;

  case 92: /* RelExp: AddExp LT RelExp  */
#line 177 "ss.y"
                         { (yyval.node_val) = append(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), LT, 0, NULL, NonType); }
#line 1947 "y.tab.c"
    break;

  case 93: /* RelExp: AddExp GT RelExp  */
#line 178 "ss.y"
                         { (yyval.node_val) = append(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), GT, 0, NULL, NonType); }
#line 1953 "y.tab.c"
    break;

  case 94: /* RelExp: AddExp LE RelExp  */
#line 179 "ss.y"
                         { (yyval.node_val) = append(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), LE, 0, NULL, NonType); }
#line 1959 "y.tab.c"
    break;

  case 95: /* RelExp: AddExp GE RelExp  */
#line 180 "ss.y"
                         { (yyval.node_val) = append(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), GE, 0, NULL, NonType); }
#line 1965 "y.tab.c"
    break;

  case 96: /* ExpArray: %empty  */
#line 183 "ss.y"
                                { (yyval.node_val) = NULL; }
#line 1971 "y.tab.c"
    break;

  case 97: /* ExpArray: LB Exp RB ExpArray  */
#line 184 "ss.y"
                                { (yyval.node_val) = append(ExpArray, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1977 "y.tab.c"
    break;


#line 1981 "y.tab.c"

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

#line 187 "ss.y"


void yyerror(char *str){
    extern int yylineno; // 行号
    extern char *yytext; // 当前文本
    fprintf(stderr, "Error: %s at line %d, near '%s'\n", str, yylineno, yytext);
}

int main()
{
    printf("Parsing...\n");
    yyparse();
    printf("Parsing finished.\n\n");
    print_tree(root,0);
    return 0;
}
