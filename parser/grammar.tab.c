/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

void yyerror(void **, const char *);
extern int yylex (void);
#include "ast.h"

#line 76 "grammar.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    FUNC_NAME = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPEDEF_NAME = 285,
    ENUMERATION_CONSTANT = 286,
    TYPEDEF = 287,
    EXTERN = 288,
    STATIC = 289,
    AUTO = 290,
    REGISTER = 291,
    INLINE = 292,
    CONST = 293,
    RESTRICT = 294,
    VOLATILE = 295,
    BOOL = 296,
    CHAR = 297,
    SHORT = 298,
    INT = 299,
    LONG = 300,
    SIGNED = 301,
    UNSIGNED = 302,
    FLOAT = 303,
    DOUBLE = 304,
    VOID = 305,
    COMPLEX = 306,
    IMAGINARY = 307,
    STRUCT = 308,
    UNION = 309,
    ENUM = 310,
    ELLIPSIS = 311,
    CASE = 312,
    DEFAULT = 313,
    IF = 314,
    ELSE = 315,
    SWITCH = 316,
    WHILE = 317,
    DO = 318,
    FOR = 319,
    GOTO = 320,
    CONTINUE = 321,
    BREAK = 322,
    RETURN = 323,
    ALIGNAS = 324,
    ALIGNOF = 325,
    ATOMIC = 326,
    GENERIC = 327,
    NORETURN = 328,
    STATIC_ASSERT = 329,
    THREAD_LOCAL = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "grammar.y"

    int i_num;
    double d_num;
    const char *str;
    void *ptr;

#line 211 "grammar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void ** ast);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  278
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  483

#define YYUNDEFTOK  2
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,     2,     2,     2,    92,    85,     2,
      76,    77,    86,    87,    78,    88,    82,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    99,
      93,    98,    94,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    96,    84,    89,     2,     2,     2,
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
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    47,    48,    49,    50,    54,    55,    56,
      60,    64,    65,    69,    73,    74,    78,    79,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    96,    97,
     101,   102,   103,   104,   105,   106,   107,   111,   112,   113,
     114,   115,   116,   120,   121,   125,   126,   127,   128,   132,
     133,   134,   138,   139,   140,   144,   145,   146,   147,   148,
     152,   153,   154,   158,   159,   163,   164,   168,   169,   173,
     174,   178,   179,   183,   184,   188,   189,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   207,   208,
     212,   216,   217,   218,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   235,   236,   240,   241,   245,   246,
     247,   248,   249,   250,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     273,   274,   275,   279,   280,   284,   285,   289,   290,   291,
     295,   296,   297,   298,   302,   303,   307,   308,   309,   313,
     314,   315,   316,   317,   321,   322,   326,   327,   331,   335,
     336,   337,   338,   342,   343,   347,   348,   352,   353,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   374,   375,   376,   377,   381,   382,   387,
     388,   392,   393,   397,   398,   399,   403,   404,   408,   409,
     413,   414,   415,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   443,   444,   445,   449,   450,   451,
     452,   456,   460,   461,   465,   466,   470,   474,   475,   476,
     477,   478,   479,   483,   484,   485,   489,   490,   490,   490,
     494,   495,   499,   500,   504,   505,   509,   510,   511,   515,
     516,   517,   518,   519,   520,   524,   525,   526,   527,   528,
     532,   533,   537,   538,   542,   543,   547,   548,   552
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF_NAME", "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE",
  "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "VOID", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('",
  "')'", "','", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "'='", "';'", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "$@1", "$@2", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", "start_symbol", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    40,    41,    44,    58,
      91,    93,    46,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61,    59
};
# endif

#define YYPACT_NINF (-362)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2039,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,    27,   -57,   -47,  -362,   -37,
    -362,  -362,    66,  2129,  2129,  -362,    32,  -362,  -362,  2129,
    2129,  2129,  -362,  2039,  -362,  -362,    91,   -52,    93,   766,
    2238,  1514,  -362,    99,   158,  -362,   -45,  -362,  1725,   -48,
      75,  -362,  -362,    37,  2167,  -362,  -362,  -362,  -362,  -362,
      93,  -362,    36,    -5,  -362,  -362,  -362,  -362,  -362,  -362,
    1536,  1558,  1558,  -362,    73,    88,   766,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,   236,  -362,  1514,
    -362,    68,    96,   200,    31,   210,    62,    86,    70,   212,
      33,  -362,   157,  2238,   100,  2238,   163,   199,   204,   215,
    -362,  -362,  -362,   158,    99,  -362,   214,  1272,  -362,    66,
    -362,  1941,  1679,   854,   -48,  2167,  1841,  -362,    59,  -362,
     117,  1514,    15,  -362,   766,  -362,   766,  -362,  -362,  2238,
    1514,   196,  -362,  -362,   160,   225,   301,  -362,  -362,  1294,
    1514,   306,  -362,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  -362,  -362,  1792,   876,   -23,  -362,   135,  -362,
    -362,  -362,   305,  -362,  -362,  -362,  -362,   216,  -362,   443,
    1250,  -362,  -362,  -362,  -362,  -362,  -362,   102,   244,   265,
    -362,   165,  1118,  -362,   266,   268,   898,  1888,  -362,  -362,
    1514,  -362,   -44,  -362,   267,    23,  -362,  -362,  -362,  -362,
     273,   275,   277,   279,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  1514,  -362,  1514,  1382,  -362,
    -362,   203,  -362,   -10,  -362,  -362,  -362,  -362,    68,    68,
      96,    96,   200,   200,   200,   200,    31,    31,   210,    62,
      86,    70,   212,   206,  -362,   278,   281,  1118,  -362,   282,
     283,   986,   135,  1993,  1008,   285,   287,  1514,   288,   292,
     293,   294,   586,   295,   372,   280,   284,   630,  -362,   -34,
    -362,  -362,  -362,  -362,   443,  -362,  -362,  -362,  -362,  -362,
    1514,   373,  -362,   121,  1272,    34,  -362,  1624,  -362,   128,
    -362,  -362,  2085,  -362,   375,   300,  1118,  -362,  -362,  1514,
    -362,   303,   304,  -362,  -362,    47,  -362,  1514,  -362,   299,
     299,  -362,  2204,  -362,  -362,  1250,  -362,  -362,  1514,  -362,
    1514,  -362,  -362,   307,  1118,  -362,  -362,  1514,  -362,   308,
    -362,   309,  1118,  -362,   310,   312,  1030,   291,   586,   315,
     586,  1514,  1514,  1514,   325,   533,   296,  -362,  -362,  -362,
      78,  -362,   313,  -362,   318,  -362,  1140,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   320,   321,  -362,  -362,  -362,
    -362,   317,   209,  -362,   324,   125,  -362,  -362,  -362,   323,
     326,  -362,  -362,   328,  1118,  -362,  -362,  1514,  -362,   329,
    -362,  -362,   586,  -362,   218,   223,   229,   330,   676,   676,
    -362,  -362,  -362,  -362,  -362,  -362,  1272,  -362,  -362,  1514,
    -362,  2204,  1514,  1162,  -362,  -362,  -362,  -362,   331,   333,
    -362,  -362,   586,   586,   586,  1514,  1404,  1426,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   345,  -362,  -362,   250,   586,
     254,   586,   256,   586,   316,  -362,   586,  -362,   586,  -362,
    -362,  -362,  -362
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   129,   108,   109,   110,   112,   113,   163,   159,   160,
     161,   123,   115,   116,   117,   118,   121,   122,   119,   120,
     114,   124,   125,   133,   134,     0,     0,   162,   164,     0,
     111,   273,     0,    95,    97,   127,     0,   128,   126,    99,
     101,   103,    93,   278,   270,   272,     0,   153,     0,     0,
       0,     0,   169,     0,   186,    91,     0,   104,   107,   168,
       0,    94,    96,   132,     0,    98,   100,   102,   271,     1,
       0,    10,   157,     0,   154,     2,     7,     8,    11,    12,
       0,     0,     0,     9,     0,     0,     0,    37,    38,    39,
      40,    41,    42,    18,     3,     4,     6,    30,    43,     0,
      45,    49,    52,    55,    60,    63,    65,    67,    69,    71,
      73,    90,     0,   141,   199,   143,     0,     0,     0,     0,
     162,   187,   185,   184,     0,    92,   247,     0,   276,     0,
     275,     0,     0,     0,   167,     0,     0,   135,     0,   139,
       0,     0,     0,   149,     0,    34,     0,    31,    32,     0,
       0,    43,    75,    88,     0,     0,     0,    24,    25,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   140,     0,     0,   201,   198,   202,   142,
     165,   158,     0,   170,   188,   183,   105,   107,   246,     0,
       0,   226,   106,   277,   274,   196,   181,   195,     0,   190,
     191,     0,     0,   171,    38,     0,     0,     0,   130,   136,
       0,   137,     0,   144,   148,     0,   151,   156,   150,   155,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    77,     0,     5,     0,     0,    23,
      20,     0,    28,     0,    22,    46,    47,    48,    50,    51,
      53,    54,    58,    59,    56,    57,    61,    62,    64,    66,
      68,    70,    72,     0,   220,     0,     0,     0,   204,    38,
       0,     0,   200,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,     0,
     252,   253,   237,   238,   248,   250,   239,   240,   241,   242,
       0,     0,   228,     0,     0,     0,   232,     0,   193,   201,
     194,   180,     0,   182,     0,     0,     0,   172,   179,     0,
     178,    38,     0,   131,   146,     0,   138,     0,   152,    35,
       0,    36,     0,    76,    89,     0,    44,    21,     0,    19,
       0,   221,   203,     0,     0,   205,   211,     0,   210,     0,
     222,     0,     0,   212,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   267,   268,
       0,   255,     0,   251,     0,   235,     0,   224,   227,   231,
     233,   189,   192,   197,   174,     0,     0,   175,   177,   145,
     147,     0,     0,    14,     0,     0,    29,    74,   207,     0,
       0,   209,   223,     0,     0,   213,   219,     0,   218,     0,
     236,   243,     0,   245,     0,     0,     0,     0,     0,     0,
     265,   269,   249,   234,   225,   230,     0,   173,   176,     0,
      13,     0,     0,     0,    26,   206,   208,   215,     0,     0,
     216,   244,     0,     0,     0,     0,     0,     0,   229,    17,
      15,    16,    27,   214,   217,   257,   258,   259,     0,     0,
       0,     0,     0,     0,     0,   263,     0,   261,     0,   256,
     260,   264,   262
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -362,  -362,  -362,  -362,  -362,  -362,  -362,   -25,  -362,  -362,
      90,  -362,   -75,   169,   172,    79,   170,   241,   242,   240,
     243,   245,  -362,   -13,    -6,  -362,   -83,    16,   -56,     8,
    -362,   297,  -362,   -43,  -362,  -362,   289,  -109,   -55,  -362,
      85,  -362,   353,  -131,  -362,   -49,  -362,  -362,   -20,   -46,
     -38,  -129,  -122,  -362,   104,  -362,   -27,   -94,  -169,  -114,
      83,  -361,  -362,   114,   -24,    -9,  -362,    71,  -362,  -362,
    -362,   127,  -238,  -362,  -362,  -362,  -362,   389,  -362,  -362,
    -362
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    93,    94,    72,    95,    96,   402,   403,    97,   251,
     151,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   152,   153,   245,   299,   112,    31,   129,
      56,    57,    33,    34,    35,    36,   136,   137,   114,   222,
     223,    37,    73,    74,    38,    39,    40,    41,   119,    59,
      60,   123,   275,   209,   210,   211,   404,   276,   188,   312,
     313,   314,   315,   316,    42,   301,   302,   303,   199,   382,
     304,   305,   306,   307,   308,   309,    43,    44,    45,   131,
      46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     115,   115,   128,   154,   216,   121,   113,   113,    32,   138,
     208,   229,    58,   202,   134,   115,   122,   282,    71,    49,
     187,   113,   116,   117,   162,   436,    71,   219,   132,    50,
      47,    70,   133,   124,   335,    63,   111,   115,   111,    51,
     139,    61,    62,   113,   247,   170,   171,    65,    66,    67,
      52,    32,   180,   184,   125,   336,   281,   185,   183,   155,
     189,   154,    52,   154,   115,   381,   115,   118,   247,    52,
     113,   349,   113,   142,   194,   203,   186,   253,    52,   143,
     138,   138,   436,   326,   121,   195,   115,   115,   255,   256,
     257,    69,   113,   113,   229,   115,    71,   115,   273,   228,
     115,   113,    52,   113,   197,    52,   113,   338,   219,   197,
      48,   139,   139,   320,   310,    64,   311,   230,   224,   231,
     135,   201,   232,    53,   172,   173,   220,   215,   111,   130,
     181,    52,   389,    54,   141,    53,   121,   429,   220,    98,
     207,    98,    53,   300,   233,    54,   186,   176,   354,   149,
     282,    53,    54,   252,   163,   366,   247,   227,   221,   164,
     165,   361,   138,   121,   150,    55,   178,   194,   115,   319,
     145,   147,   148,   346,   113,    53,   184,   431,   317,   280,
     185,   177,   185,   166,   167,    54,    54,   318,    54,    98,
     456,   457,   207,   139,   201,   225,     8,     9,    10,   386,
     388,   226,   204,   443,   317,   387,   325,   111,   185,   444,
     332,   283,   168,   169,   380,   284,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   174,   175,   121,   120,
     179,    98,   194,   414,   182,   121,   334,   246,   247,   343,
     190,   344,   323,   324,    54,   156,   157,   158,   300,   262,
     263,   264,   265,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,   353,   435,   134,   111,   359,   191,   194,   365,   319,
     347,   348,   192,   374,   247,   350,   440,   441,   424,   425,
     426,   207,   193,   115,   244,   452,   247,   111,   198,   113,
     453,   247,   248,   369,   249,   194,   454,   247,   201,   254,
      98,   285,   159,   121,   127,   224,   160,   194,   161,   428,
     395,   321,   458,   396,   111,   207,   384,   474,   247,   435,
     207,   476,   247,   478,   247,   258,   259,   407,    98,   201,
     260,   261,   406,   322,   266,   267,   337,   327,   409,   328,
     339,   410,   340,   400,   341,   351,   413,   342,   352,   421,
     419,   423,   367,   355,   356,   194,   368,   370,   371,   372,
     373,   375,   468,   470,   472,   376,   385,    98,   393,   377,
     201,   394,   345,   378,   397,   398,   412,   427,   408,   411,
     420,   415,   115,   416,   422,   430,   439,   432,   113,   433,
      98,   437,   438,   442,   445,   473,   455,   446,   448,   447,
     450,   449,   463,   451,   464,   480,   460,   268,   270,   269,
     399,   196,   271,   140,   217,   272,   392,    98,   405,   390,
     201,   383,    68,   459,     0,     0,   461,   201,     0,     0,
      98,     0,     0,   465,   466,   467,   286,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
     475,     0,   477,     0,   479,     0,     0,   481,     0,   482,
       0,     0,     0,     1,    83,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
     287,   288,   289,     0,   290,   291,   292,   293,   294,   295,
     296,   297,    26,    84,    27,    85,    28,    29,    30,    86,
       0,     0,     0,     0,     0,     0,   126,     0,    87,    88,
      89,    90,    91,    92,     0,     0,    75,    76,    77,    78,
      79,    80,   298,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    83,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   286,
      76,    77,    78,    79,    80,     0,    81,    82,     0,     0,
       0,     0,    26,    84,    27,    85,    28,    29,    30,    86,
       0,     0,     0,     0,     0,     0,     0,    83,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,   298,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,   287,   288,   289,     0,   290,   291,   292,
     293,   294,   295,   296,   297,     0,    84,     0,    85,     0,
       0,    83,    86,     0,     0,     0,     0,     0,     0,   126,
       0,    87,    88,    89,    90,    91,    92,     0,     0,    75,
      76,    77,    78,    79,    80,   298,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    85,     0,     0,     0,    86,    83,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,    85,     0,
       0,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,     0,     0,    75,
      76,    77,    78,    79,    80,   298,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    83,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    27,    85,     0,
       0,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    83,    81,    82,   212,     0,
       0,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    83,    81,    82,
     277,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,    84,   120,    85,     0,     0,    83,
      86,     0,   329,     0,     0,   213,     8,     9,    10,    87,
     214,    89,    90,    91,    92,     0,    84,   120,    85,     0,
       0,     0,    86,     0,     0,     0,     0,   278,     0,     0,
       0,    87,   279,    89,    90,    91,    92,     0,    84,   120,
      85,     0,     0,     0,    86,     0,     0,     0,     0,   330,
       0,     0,     0,    87,   331,    89,    90,    91,    92,    75,
      76,    77,    78,    79,    80,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    83,    81,    82,
     357,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    83,
      81,    82,   362,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,    84,   120,    85,     0,
       0,    83,    86,     0,   417,     0,     0,   358,     8,     9,
      10,    87,    88,    89,    90,    91,    92,     0,    84,   120,
      85,     0,     0,     0,    86,     0,     0,     0,     0,   363,
       0,     0,     0,    87,   364,    89,    90,    91,    92,     0,
      84,   120,    85,     0,     0,     0,    86,     0,     0,     0,
       0,   418,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    75,    76,    77,    78,    79,    80,     0,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    83,
      81,    82,     0,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    83,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,   120,
      85,     0,     0,    83,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,     0,
      84,     0,    85,     0,     0,     0,    86,     0,     0,     0,
     310,     0,   311,   200,   434,    87,    88,    89,    90,    91,
      92,     0,    84,     0,    85,     0,     0,     0,    86,     0,
       0,     0,   310,     0,   311,   200,   462,    87,    88,    89,
      90,    91,    92,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    83,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    83,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    85,     0,     0,    83,    86,     0,     0,     0,
     310,     0,   311,   200,     0,    87,    88,    89,    90,    91,
      92,     0,    84,     0,    85,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,   200,     0,    87,    88,    89,
      90,    91,    92,     0,    84,     0,    85,     0,     0,     0,
      86,   250,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    91,    92,    75,    76,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    83,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    83,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,    85,     0,     0,    83,    86,     0,
       0,     0,     0,     0,     0,   345,     0,    87,    88,    89,
      90,    91,    92,     0,    84,     0,    85,     0,     0,     0,
      86,   469,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    91,    92,     0,    84,     0,    85,     0,
       0,     0,    86,   471,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    83,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    83,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    85,     0,     0,    83,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    91,    92,     0,    84,     0,    85,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    52,    84,     0,
      85,     0,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,     0,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,     0,    30,
     317,   274,     0,     0,   185,     0,     0,     0,     0,     1,
      54,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,     1,   206,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   127,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,   184,   274,
       0,     1,   185,     0,     0,     0,     0,     0,    54,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    29,     0,     0,     1,     0,
       0,     0,     0,     0,     0,   218,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   333,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     1,   126,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,     0,    30,     1,
     360,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,    29,    30,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   391,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     1,
      30,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    26,     0,
      27,     0,    28,     0,    30,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,    27,     0,
       0,    29,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,   401,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,    27,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      49,    50,    58,    86,   133,    54,    49,    50,     0,    64,
     132,   142,    32,   127,    60,    64,    54,   186,     3,    76,
     114,    64,    49,    50,    99,   386,     3,   136,    76,    76,
       3,    83,    80,    78,    78,     3,    49,    86,    51,    76,
      64,    33,    34,    86,    78,    14,    15,    39,    40,    41,
       3,    43,    19,    76,    99,    99,   185,    80,   113,    86,
     115,   144,     3,   146,   113,    99,   115,    51,    78,     3,
     113,    81,   115,    78,   123,   131,   114,   160,     3,    84,
     135,   136,   443,   212,   133,   123,   135,   136,   163,   164,
     165,     0,   135,   136,   225,   144,     3,   146,   181,    84,
     149,   144,     3,   146,   124,     3,   149,    84,   217,   129,
      83,   135,   136,   207,    80,    83,    82,   144,   138,   146,
      83,   127,   149,    76,    93,    94,    79,   133,   141,    58,
      97,     3,    98,    86,    98,    76,   185,   375,    79,    49,
     132,    51,    76,   199,   150,    86,   184,    85,   277,    76,
     319,    76,    86,   159,    86,   284,    78,   141,    99,    91,
      92,   283,   217,   212,    76,    99,    96,   216,   217,   207,
      80,    81,    82,   248,   217,    76,    76,    99,    76,   185,
      80,    95,    80,    87,    88,    86,    86,   207,    86,    99,
     428,   429,   184,   217,   200,    78,    38,    39,    40,    78,
     314,    84,   131,    78,    76,    84,   212,   220,    80,    84,
     216,    76,    12,    13,   297,    80,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    16,    17,   277,    71,
      18,   141,   281,   362,    77,   284,   220,    77,    78,   245,
      77,   247,    77,    78,    86,     9,    10,    11,   304,   170,
     171,   172,   173,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   277,   386,   319,   287,   281,    77,   326,   284,   317,
      77,    78,    78,   292,    78,    79,    77,    78,   371,   372,
     373,   283,    77,   342,    98,    77,    78,   310,    84,   342,
      77,    78,    77,   287,     3,   354,    77,    78,   314,     3,
     220,     6,    76,   362,    98,   335,    80,   366,    82,   375,
     326,    77,   436,   329,   337,   317,   310,    77,    78,   443,
     322,    77,    78,    77,    78,   166,   167,   350,   248,   345,
     168,   169,   348,    78,   174,   175,    79,    81,   354,    81,
      77,   357,    77,   337,    77,    77,   362,    78,    77,   368,
     366,   370,    77,    81,    81,   414,    79,    79,    76,    76,
      76,    76,   455,   456,   457,     3,     3,   287,     3,    99,
     386,    81,    83,    99,    81,    81,    77,    62,    81,    81,
      99,    81,   441,    81,    79,    99,    79,    84,   441,    81,
     310,    81,    81,    79,    81,    60,    76,    81,   414,    81,
      81,   417,    81,   422,    81,    99,   441,   176,   178,   177,
     335,   124,   179,    70,   135,   180,   322,   337,   345,   315,
     436,   304,    43,   439,    -1,    -1,   442,   443,    -1,    -1,
     350,    -1,    -1,   452,   453,   454,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
     469,    -1,   471,    -1,   473,    -1,    -1,   476,    -1,   478,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    -1,    -1,     3,     4,     5,     6,
       7,     8,    99,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    -1,    72,    -1,
      -1,    31,    76,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,     3,
       4,     5,     6,     7,     8,    99,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,     3,
       4,     5,     6,     7,     8,    99,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    31,
      76,    -1,    34,    -1,    -1,    81,    38,    39,    40,    85,
      86,    87,    88,    89,    90,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    31,    76,    -1,    34,    -1,    -1,    81,    38,    39,
      40,    85,    86,    87,    88,    89,    90,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    31,    76,    -1,    -1,    -1,
      80,    -1,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    31,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    70,    -1,    72,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    31,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    70,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,     3,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    77,    -1,    -1,    80,    -1,    -1,    -1,    -1,    30,
      86,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    30,    77,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    98,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    77,
      -1,    30,    80,    -1,    -1,    -1,    -1,    -1,    86,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    84,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    83,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    30,
      77,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    74,    75,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    30,
      75,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    69,    -1,
      71,    -1,    73,    -1,    75,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    71,    -1,
      -1,    74,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    73,    74,
      75,   128,   129,   132,   133,   134,   135,   141,   144,   145,
     146,   147,   164,   176,   177,   178,   180,     3,    83,    76,
      76,    76,     3,    76,    86,    99,   130,   131,   148,   149,
     150,   129,   129,     3,    83,   129,   129,   129,   177,     0,
      83,     3,   103,   142,   143,     3,     4,     5,     6,     7,
       8,    10,    11,    31,    70,    72,    76,    85,    86,    87,
      88,    89,    90,   101,   102,   104,   105,   108,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   127,   133,   138,   145,   156,   156,   127,   148,
      71,   145,   150,   151,    78,    99,    83,    98,   128,   129,
     167,   179,    76,    80,   149,    83,   136,   137,   138,   164,
     142,    98,    78,    84,    76,   110,    76,   110,   110,    76,
      76,   110,   123,   124,   126,   156,     9,    10,    11,    76,
      80,    82,   112,    86,    91,    92,    87,    88,    12,    13,
      14,    15,    93,    94,    16,    17,    85,    95,    96,    18,
      19,    97,    77,   138,    76,    80,   150,   157,   158,   138,
      77,    77,    78,    77,   145,   150,   131,   148,    84,   168,
      83,   124,   159,   128,   167,     3,    77,   129,   152,   153,
     154,   155,    34,    81,    86,   124,   151,   136,    84,   137,
      79,    99,   139,   140,   148,    78,    84,   127,    84,   143,
     156,   156,   156,   124,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    98,   125,    77,    78,    77,     3,
      77,   109,   124,   126,     3,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   116,   116,   117,   118,
     119,   120,   121,   126,    77,   152,   157,    34,    81,    86,
     124,   151,   158,    76,    80,     6,     3,    57,    58,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    99,   126,
     128,   165,   166,   167,   170,   171,   172,   173,   174,   175,
      80,    82,   159,   160,   161,   162,   163,    76,   148,   150,
     157,    77,    78,    77,    78,   124,   151,    81,    81,    34,
      81,    86,   124,    84,   127,    78,    99,    79,    84,    77,
      77,    77,    78,   124,   124,    83,   112,    77,    78,    81,
      79,    77,    77,   124,   151,    81,    81,    34,    81,   124,
      77,   152,    34,    81,    86,   124,   151,    77,    79,   127,
      79,    76,    76,    76,   165,    76,     3,    99,    99,    99,
     126,    99,   169,   171,   127,     3,    78,    84,   159,    98,
     163,    56,   154,     3,    81,   124,   124,    81,    81,   140,
     127,    58,   106,   107,   156,   160,   124,   123,    81,   124,
     124,    81,    77,   124,   151,    81,    81,    34,    81,   124,
      99,   165,    79,   165,   126,   126,   126,    62,   128,   172,
      99,    99,    84,    81,    84,   159,   161,    81,    81,    79,
      77,    78,    79,    78,    84,    81,    81,    81,   124,   124,
      81,   165,    77,    77,    77,    76,   172,   172,   159,   124,
     107,   124,    84,    81,    81,   165,   165,   165,   126,    77,
     126,    77,   126,    60,    77,   165,    77,   165,    77,   165,
      99,   165,   165
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   128,   128,   128,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   138,   138,   139,   139,   140,   140,   140,   141,
     141,   141,   141,   141,   142,   142,   143,   143,   144,   145,
     145,   145,   145,   146,   146,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   150,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   155,   155,   156,   156,
     157,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     160,   161,   162,   162,   163,   163,   164,   165,   165,   165,
     165,   165,   165,   166,   166,   166,   167,   168,   169,   167,
     170,   170,   171,   171,   172,   172,   173,   173,   173,   174,
     174,   174,   174,   174,   174,   175,   175,   175,   175,   175,
     176,   176,   177,   177,   178,   178,   179,   179,   180
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     3,     2,     3,     1,     4,
       5,     5,     6,     2,     1,     3,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     3,     4,     3,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     2,     2,     1,     1,     3,     2,     1,
       2,     1,     1,     3,     2,     3,     5,     4,     5,     4,
       3,     3,     3,     4,     6,     5,     5,     6,     4,     4,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     4,
       3,     2,     1,     2,     3,     2,     7,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     0,     0,     5,
       1,     2,     1,     1,     1,     2,     7,     5,     5,     5,
       7,     6,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (ast, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void ** ast)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (ast);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void ** ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, ast);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void ** ast)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void ** ast)
{
  YYUSE (yyvaluep);
  YYUSE (ast);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void ** ast)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 46 "grammar.y"
                                   { (yyval.ptr) = primary_expression_1 ((yyvsp[0].str)); }
#line 2131 "grammar.tab.c"
    break;

  case 3:
#line 47 "grammar.y"
                                   { (yyval.ptr) = primary_expression_2 ((yyvsp[0].ptr)); }
#line 2137 "grammar.tab.c"
    break;

  case 4:
#line 48 "grammar.y"
                                   { (yyval.ptr) = primary_expression_3 ((yyvsp[0].ptr)); }
#line 2143 "grammar.tab.c"
    break;

  case 5:
#line 49 "grammar.y"
                                   { (yyval.ptr) = primary_expression_4 ((yyvsp[-1].ptr)); }
#line 2149 "grammar.tab.c"
    break;

  case 6:
#line 50 "grammar.y"
                                   { (yyval.ptr) = primary_expression_5 ((yyvsp[0].ptr)); }
#line 2155 "grammar.tab.c"
    break;

  case 7:
#line 54 "grammar.y"
                                   { (yyval.ptr) = constant_1 ((yyvsp[0].i_num)); }
#line 2161 "grammar.tab.c"
    break;

  case 8:
#line 55 "grammar.y"
                                   { (yyval.ptr) = constant_2 ((yyvsp[0].d_num)); }
#line 2167 "grammar.tab.c"
    break;

  case 9:
#line 56 "grammar.y"
                                   { (yyval.ptr) = constant_3 ((yyvsp[0].str)); }
#line 2173 "grammar.tab.c"
    break;

  case 10:
#line 60 "grammar.y"
                               { (yyval.ptr) = enumeration_constant_1 ((yyvsp[0].str)); }
#line 2179 "grammar.tab.c"
    break;

  case 11:
#line 64 "grammar.y"
                                   { (yyval.ptr) = string_1 ((yyvsp[0].str)); }
#line 2185 "grammar.tab.c"
    break;

  case 12:
#line 65 "grammar.y"
                                   { (yyval.ptr) = string_2 ((yyvsp[0].str)); }
#line 2191 "grammar.tab.c"
    break;

  case 13:
#line 69 "grammar.y"
                                                                           { (yyval.ptr) = NULL; /*generic_selection_1 ($3, $5);*/ }
#line 2197 "grammar.tab.c"
    break;

  case 14:
#line 73 "grammar.y"
                                   { (yyval.ptr) = NULL; /*generic_assoc_list_1 ($1);*/ }
#line 2203 "grammar.tab.c"
    break;

  case 15:
#line 74 "grammar.y"
                                                           { (yyval.ptr) = NULL; /*generic_assoc_list_2 ($1, $3);*/ }
#line 2209 "grammar.tab.c"
    break;

  case 16:
#line 78 "grammar.y"
                                                   { (yyval.ptr) = NULL; /*generic_assoc_1 ($1, $3);*/ }
#line 2215 "grammar.tab.c"
    break;

  case 17:
#line 79 "grammar.y"
                                                   { (yyval.ptr) = NULL; /*generic_assoc_2 ($3);*/ }
#line 2221 "grammar.tab.c"
    break;

  case 18:
#line 83 "grammar.y"
                                       { (yyval.ptr) = postfix_expression_1 ((yyvsp[0].ptr)); }
#line 2227 "grammar.tab.c"
    break;

  case 19:
#line 84 "grammar.y"
                                                       { (yyval.ptr) = postfix_expression_2 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 2233 "grammar.tab.c"
    break;

  case 20:
#line 85 "grammar.y"
                                       { (yyval.ptr) = postfix_expression_3 ((yyvsp[-2].ptr)); }
#line 2239 "grammar.tab.c"
    break;

  case 21:
#line 86 "grammar.y"
                                                               { (yyval.ptr) = postfix_expression_4 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 2245 "grammar.tab.c"
    break;

  case 22:
#line 87 "grammar.y"
                                                       { (yyval.ptr) = postfix_expression_5 ((yyvsp[-2].ptr), (yyvsp[0].str)); }
#line 2251 "grammar.tab.c"
    break;

  case 23:
#line 88 "grammar.y"
                                                       { (yyval.ptr) = postfix_expression_6 ((yyvsp[-2].ptr), (yyvsp[0].str)); }
#line 2257 "grammar.tab.c"
    break;

  case 24:
#line 89 "grammar.y"
                                       { (yyval.ptr) = postfix_expression_7 ((yyvsp[-1].ptr)); }
#line 2263 "grammar.tab.c"
    break;

  case 25:
#line 90 "grammar.y"
                                       { (yyval.ptr) = postfix_expression_8 ((yyvsp[-1].ptr)); }
#line 2269 "grammar.tab.c"
    break;

  case 26:
#line 91 "grammar.y"
                                                               { (yyval.ptr) = postfix_expression_9 ((yyvsp[-4].ptr), (yyvsp[-1].ptr)); }
#line 2275 "grammar.tab.c"
    break;

  case 27:
#line 92 "grammar.y"
                                                               { (yyval.ptr) = postfix_expression_10 ((yyvsp[-5].ptr), (yyvsp[-2].ptr)); }
#line 2281 "grammar.tab.c"
    break;

  case 28:
#line 96 "grammar.y"
                                       { (yyval.ptr) = argument_expression_list_1 ((yyvsp[0].ptr)); }
#line 2287 "grammar.tab.c"
    break;

  case 29:
#line 97 "grammar.y"
                                                               { (yyval.ptr) = argument_expression_list_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2293 "grammar.tab.c"
    break;

  case 30:
#line 101 "grammar.y"
                                           { (yyval.ptr) = unary_expression_1 ((yyvsp[0].ptr)); }
#line 2299 "grammar.tab.c"
    break;

  case 31:
#line 102 "grammar.y"
                                           { (yyval.ptr) = unary_expression_2 ((yyvsp[0].ptr)); }
#line 2305 "grammar.tab.c"
    break;

  case 32:
#line 103 "grammar.y"
                                           { (yyval.ptr) = unary_expression_3 ((yyvsp[0].ptr)); }
#line 2311 "grammar.tab.c"
    break;

  case 33:
#line 104 "grammar.y"
                                           { (yyval.ptr) = unary_expression_4 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2317 "grammar.tab.c"
    break;

  case 34:
#line 105 "grammar.y"
                                           { (yyval.ptr) = unary_expression_5 ((yyvsp[0].ptr)); }
#line 2323 "grammar.tab.c"
    break;

  case 35:
#line 106 "grammar.y"
                                           { (yyval.ptr) = unary_expression_6 ((yyvsp[-1].ptr)); }
#line 2329 "grammar.tab.c"
    break;

  case 36:
#line 107 "grammar.y"
                                           { (yyval.ptr) = unary_expression_7 ((yyvsp[-1].ptr)); }
#line 2335 "grammar.tab.c"
    break;

  case 37:
#line 111 "grammar.y"
                   { (yyval.ptr) = unary_operator_1 (); }
#line 2341 "grammar.tab.c"
    break;

  case 38:
#line 112 "grammar.y"
                   { (yyval.ptr) = unary_operator_2 (); }
#line 2347 "grammar.tab.c"
    break;

  case 39:
#line 113 "grammar.y"
                   { (yyval.ptr) = unary_operator_3 (); }
#line 2353 "grammar.tab.c"
    break;

  case 40:
#line 114 "grammar.y"
                   { (yyval.ptr) = unary_operator_4 (); }
#line 2359 "grammar.tab.c"
    break;

  case 41:
#line 115 "grammar.y"
                   { (yyval.ptr) = unary_operator_5 (); }
#line 2365 "grammar.tab.c"
    break;

  case 42:
#line 116 "grammar.y"
                   { (yyval.ptr) = unary_operator_6 (); }
#line 2371 "grammar.tab.c"
    break;

  case 43:
#line 120 "grammar.y"
                                               { (yyval.ptr) = cast_expression_1 ((yyvsp[0].ptr)); }
#line 2377 "grammar.tab.c"
    break;

  case 44:
#line 121 "grammar.y"
                                               { (yyval.ptr) = cast_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2383 "grammar.tab.c"
    break;

  case 45:
#line 125 "grammar.y"
                                   { (yyval.ptr) = multiplicative_expression_1 ((yyvsp[0].ptr)); }
#line 2389 "grammar.tab.c"
    break;

  case 46:
#line 126 "grammar.y"
                                                               { (yyval.ptr) = multiplicative_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2395 "grammar.tab.c"
    break;

  case 47:
#line 127 "grammar.y"
                                                               { (yyval.ptr) = multiplicative_expression_3 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2401 "grammar.tab.c"
    break;

  case 48:
#line 128 "grammar.y"
                                                               { (yyval.ptr) = multiplicative_expression_4 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2407 "grammar.tab.c"
    break;

  case 49:
#line 132 "grammar.y"
                                       { (yyval.ptr) = additive_expression_1 ((yyvsp[0].ptr)); }
#line 2413 "grammar.tab.c"
    break;

  case 50:
#line 133 "grammar.y"
                                                               { (yyval.ptr) = additive_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2419 "grammar.tab.c"
    break;

  case 51:
#line 134 "grammar.y"
                                                               { (yyval.ptr) = additive_expression_3 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2425 "grammar.tab.c"
    break;

  case 52:
#line 138 "grammar.y"
                                       { (yyval.ptr) = shift_expression_1 ((yyvsp[0].ptr)); }
#line 2431 "grammar.tab.c"
    break;

  case 53:
#line 139 "grammar.y"
                                                               { (yyval.ptr) = shift_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2437 "grammar.tab.c"
    break;

  case 54:
#line 140 "grammar.y"
                                                               { (yyval.ptr) = shift_expression_3 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2443 "grammar.tab.c"
    break;

  case 55:
#line 144 "grammar.y"
                                       { (yyval.ptr) = relational_expression_1 ((yyvsp[0].ptr)); }
#line 2449 "grammar.tab.c"
    break;

  case 56:
#line 145 "grammar.y"
                                                               { (yyval.ptr) = relational_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2455 "grammar.tab.c"
    break;

  case 57:
#line 146 "grammar.y"
                                                               { (yyval.ptr) = relational_expression_3 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2461 "grammar.tab.c"
    break;

  case 58:
#line 147 "grammar.y"
                                                               { (yyval.ptr) = relational_expression_4 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2467 "grammar.tab.c"
    break;

  case 59:
#line 148 "grammar.y"
                                                               { (yyval.ptr) = relational_expression_5 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2473 "grammar.tab.c"
    break;

  case 60:
#line 152 "grammar.y"
                                       { (yyval.ptr) = equality_expression_1 ((yyvsp[0].ptr)); }
#line 2479 "grammar.tab.c"
    break;

  case 61:
#line 153 "grammar.y"
                                                               { (yyval.ptr) = equality_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2485 "grammar.tab.c"
    break;

  case 62:
#line 154 "grammar.y"
                                                               { (yyval.ptr) = equality_expression_3 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2491 "grammar.tab.c"
    break;

  case 63:
#line 158 "grammar.y"
                                       { (yyval.ptr) = and_expression_1 ((yyvsp[0].ptr)); }
#line 2497 "grammar.tab.c"
    break;

  case 64:
#line 159 "grammar.y"
                                                               { (yyval.ptr) = and_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2503 "grammar.tab.c"
    break;

  case 65:
#line 163 "grammar.y"
                                       { (yyval.ptr) = exclusive_or_expression_1 ((yyvsp[0].ptr)); }
#line 2509 "grammar.tab.c"
    break;

  case 66:
#line 164 "grammar.y"
                                                               { (yyval.ptr) = exclusive_or_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2515 "grammar.tab.c"
    break;

  case 67:
#line 168 "grammar.y"
                                       { (yyval.ptr) = inclusive_or_expression_1 ((yyvsp[0].ptr)); }
#line 2521 "grammar.tab.c"
    break;

  case 68:
#line 169 "grammar.y"
                                                               { (yyval.ptr) = inclusive_or_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2527 "grammar.tab.c"
    break;

  case 69:
#line 173 "grammar.y"
                                       { (yyval.ptr) = logical_and_expression_1 ((yyvsp[0].ptr)); }
#line 2533 "grammar.tab.c"
    break;

  case 70:
#line 174 "grammar.y"
                                                                   { (yyval.ptr) = logical_and_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2539 "grammar.tab.c"
    break;

  case 71:
#line 178 "grammar.y"
                                       { (yyval.ptr) = logical_or_expression_1 ((yyvsp[0].ptr)); }
#line 2545 "grammar.tab.c"
    break;

  case 72:
#line 179 "grammar.y"
                                                                   { (yyval.ptr) = logical_or_expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2551 "grammar.tab.c"
    break;

  case 73:
#line 183 "grammar.y"
                                       { (yyval.ptr) = conditional_expression_1 ((yyvsp[0].ptr)); }
#line 2557 "grammar.tab.c"
    break;

  case 74:
#line 184 "grammar.y"
                                                                           { (yyval.ptr) = conditional_expression_2 ((yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2563 "grammar.tab.c"
    break;

  case 75:
#line 188 "grammar.y"
                                       { (yyval.ptr) = assignment_expression_1 ((yyvsp[0].ptr)); }
#line 2569 "grammar.tab.c"
    break;

  case 76:
#line 189 "grammar.y"
                                                                           { (yyval.ptr) = assignment_expression_2 ((yyvsp[-2].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2575 "grammar.tab.c"
    break;

  case 77:
#line 193 "grammar.y"
                           { (yyval.ptr) = assignment_operator_1 (); }
#line 2581 "grammar.tab.c"
    break;

  case 78:
#line 194 "grammar.y"
                           { (yyval.ptr) = assignment_operator_2 (); }
#line 2587 "grammar.tab.c"
    break;

  case 79:
#line 195 "grammar.y"
                           { (yyval.ptr) = assignment_operator_3 (); }
#line 2593 "grammar.tab.c"
    break;

  case 80:
#line 196 "grammar.y"
                           { (yyval.ptr) = assignment_operator_4 (); }
#line 2599 "grammar.tab.c"
    break;

  case 81:
#line 197 "grammar.y"
                           { (yyval.ptr) = assignment_operator_5 (); }
#line 2605 "grammar.tab.c"
    break;

  case 82:
#line 198 "grammar.y"
                           { (yyval.ptr) = assignment_operator_6 (); }
#line 2611 "grammar.tab.c"
    break;

  case 83:
#line 199 "grammar.y"
                           { (yyval.ptr) = assignment_operator_7 (); }
#line 2617 "grammar.tab.c"
    break;

  case 84:
#line 200 "grammar.y"
                           { (yyval.ptr) = assignment_operator_8 (); }
#line 2623 "grammar.tab.c"
    break;

  case 85:
#line 201 "grammar.y"
                           { (yyval.ptr) = assignment_operator_9 (); }
#line 2629 "grammar.tab.c"
    break;

  case 86:
#line 202 "grammar.y"
                           { (yyval.ptr) = assignment_operator_10 (); }
#line 2635 "grammar.tab.c"
    break;

  case 87:
#line 203 "grammar.y"
                           { (yyval.ptr) = assignment_operator_11 (); }
#line 2641 "grammar.tab.c"
    break;

  case 88:
#line 207 "grammar.y"
                                                   { (yyval.ptr) = expression_1 ((yyvsp[0].ptr)); }
#line 2647 "grammar.tab.c"
    break;

  case 89:
#line 208 "grammar.y"
                                                   { (yyval.ptr) = expression_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2653 "grammar.tab.c"
    break;

  case 90:
#line 212 "grammar.y"
                                       { (yyval.ptr) = constant_expression_1 ((yyvsp[0].ptr)); }
#line 2659 "grammar.tab.c"
    break;

  case 91:
#line 216 "grammar.y"
                                           { (yyval.ptr) = declaration_1 ((yyvsp[-1].ptr)); }
#line 2665 "grammar.tab.c"
    break;

  case 92:
#line 217 "grammar.y"
                                                           { (yyval.ptr) = declaration_2 ((yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 2671 "grammar.tab.c"
    break;

  case 93:
#line 218 "grammar.y"
                                           { (yyval.ptr) = declaration_3 ((yyvsp[0].ptr)); }
#line 2677 "grammar.tab.c"
    break;

  case 94:
#line 222 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2683 "grammar.tab.c"
    break;

  case 95:
#line 223 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_2 ((yyvsp[0].ptr)); }
#line 2689 "grammar.tab.c"
    break;

  case 96:
#line 224 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_3 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2695 "grammar.tab.c"
    break;

  case 97:
#line 225 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_4 ((yyvsp[0].ptr)); }
#line 2701 "grammar.tab.c"
    break;

  case 98:
#line 226 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_5 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2707 "grammar.tab.c"
    break;

  case 99:
#line 227 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_6 ((yyvsp[0].ptr)); }
#line 2713 "grammar.tab.c"
    break;

  case 100:
#line 228 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_7 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2719 "grammar.tab.c"
    break;

  case 101:
#line 229 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_8 ((yyvsp[0].ptr)); }
#line 2725 "grammar.tab.c"
    break;

  case 102:
#line 230 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_9 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2731 "grammar.tab.c"
    break;

  case 103:
#line 231 "grammar.y"
                                                           { (yyval.ptr) = declaration_specifiers_10 ((yyvsp[0].ptr)); }
#line 2737 "grammar.tab.c"
    break;

  case 104:
#line 235 "grammar.y"
                                   { (yyval.ptr) = init_declarator_list_1 ((yyvsp[0].ptr)); }
#line 2743 "grammar.tab.c"
    break;

  case 105:
#line 236 "grammar.y"
                                                           { (yyval.ptr) = init_declarator_list_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2749 "grammar.tab.c"
    break;

  case 106:
#line 240 "grammar.y"
                                           { (yyval.ptr) = init_declarator_1 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2755 "grammar.tab.c"
    break;

  case 107:
#line 241 "grammar.y"
                                           { (yyval.ptr) = init_declarator_2 ((yyvsp[0].ptr)); }
#line 2761 "grammar.tab.c"
    break;

  case 108:
#line 245 "grammar.y"
                                   { (yyval.ptr) = storage_class_specifier_1 (); }
#line 2767 "grammar.tab.c"
    break;

  case 109:
#line 246 "grammar.y"
                                   { (yyval.ptr) = storage_class_specifier_2 (); }
#line 2773 "grammar.tab.c"
    break;

  case 110:
#line 247 "grammar.y"
                                   { (yyval.ptr) = storage_class_specifier_3 (); }
#line 2779 "grammar.tab.c"
    break;

  case 111:
#line 248 "grammar.y"
                                   { (yyval.ptr) = storage_class_specifier_4 (); }
#line 2785 "grammar.tab.c"
    break;

  case 112:
#line 249 "grammar.y"
                                   { (yyval.ptr) = storage_class_specifier_5 (); }
#line 2791 "grammar.tab.c"
    break;

  case 113:
#line 250 "grammar.y"
                                   { (yyval.ptr) = storage_class_specifier_6 (); }
#line 2797 "grammar.tab.c"
    break;

  case 114:
#line 254 "grammar.y"
                                   { (yyval.ptr) = type_specifier_1 (); }
#line 2803 "grammar.tab.c"
    break;

  case 115:
#line 255 "grammar.y"
                                   { (yyval.ptr) = type_specifier_2 (); }
#line 2809 "grammar.tab.c"
    break;

  case 116:
#line 256 "grammar.y"
                                   { (yyval.ptr) = type_specifier_3 (); }
#line 2815 "grammar.tab.c"
    break;

  case 117:
#line 257 "grammar.y"
                                   { (yyval.ptr) = type_specifier_4 (); }
#line 2821 "grammar.tab.c"
    break;

  case 118:
#line 258 "grammar.y"
                                   { (yyval.ptr) = type_specifier_5 (); }
#line 2827 "grammar.tab.c"
    break;

  case 119:
#line 259 "grammar.y"
                                   { (yyval.ptr) = type_specifier_6 (); }
#line 2833 "grammar.tab.c"
    break;

  case 120:
#line 260 "grammar.y"
                                   { (yyval.ptr) = type_specifier_7 (); }
#line 2839 "grammar.tab.c"
    break;

  case 121:
#line 261 "grammar.y"
                                   { (yyval.ptr) = type_specifier_8 (); }
#line 2845 "grammar.tab.c"
    break;

  case 122:
#line 262 "grammar.y"
                                   { (yyval.ptr) = type_specifier_9 (); }
#line 2851 "grammar.tab.c"
    break;

  case 123:
#line 263 "grammar.y"
                                   { (yyval.ptr) = type_specifier_10 (); }
#line 2857 "grammar.tab.c"
    break;

  case 124:
#line 264 "grammar.y"
                                   { (yyval.ptr) = type_specifier_11 (); }
#line 2863 "grammar.tab.c"
    break;

  case 125:
#line 265 "grammar.y"
                                           { (yyval.ptr) = type_specifier_12 (); }
#line 2869 "grammar.tab.c"
    break;

  case 126:
#line 266 "grammar.y"
                                   { (yyval.ptr) = type_specifier_13 ((yyvsp[0].ptr)); }
#line 2875 "grammar.tab.c"
    break;

  case 127:
#line 267 "grammar.y"
                                       { (yyval.ptr) = type_specifier_14 ((yyvsp[0].ptr)); }
#line 2881 "grammar.tab.c"
    break;

  case 128:
#line 268 "grammar.y"
                                   { (yyval.ptr) = type_specifier_15 ((yyvsp[0].ptr)); }
#line 2887 "grammar.tab.c"
    break;

  case 129:
#line 269 "grammar.y"
                                   { (yyval.ptr) = type_specifier_16 ((yyvsp[0].str)); }
#line 2893 "grammar.tab.c"
    break;

  case 130:
#line 273 "grammar.y"
                                                                       { (yyval.ptr) = struct_or_union_specifier_1 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 2899 "grammar.tab.c"
    break;

  case 131:
#line 274 "grammar.y"
                                                                       { (yyval.ptr) = struct_or_union_specifier_2 ((yyvsp[-4].ptr), (yyvsp[-3].str), (yyvsp[-1].ptr)); }
#line 2905 "grammar.tab.c"
    break;

  case 132:
#line 275 "grammar.y"
                                               { (yyval.ptr) = struct_or_union_specifier_3 ((yyvsp[-1].ptr), (yyvsp[0].str)); }
#line 2911 "grammar.tab.c"
    break;

  case 133:
#line 279 "grammar.y"
                                   { (yyval.ptr) = struct_or_union_1 (); }
#line 2917 "grammar.tab.c"
    break;

  case 134:
#line 280 "grammar.y"
                                   { (yyval.ptr) = struct_or_union_2 (); }
#line 2923 "grammar.tab.c"
    break;

  case 135:
#line 284 "grammar.y"
                                   { (yyval.ptr) = struct_declaration_list_1 ((yyvsp[0].ptr)); }
#line 2929 "grammar.tab.c"
    break;

  case 136:
#line 285 "grammar.y"
                                                           { (yyval.ptr) = struct_declaration_list_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2935 "grammar.tab.c"
    break;

  case 137:
#line 289 "grammar.y"
                                                               { (yyval.ptr) = struct_declaration_1 ((yyvsp[-1].ptr)); }
#line 2941 "grammar.tab.c"
    break;

  case 138:
#line 290 "grammar.y"
                                                               { (yyval.ptr) = struct_declaration_2 ((yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 2947 "grammar.tab.c"
    break;

  case 139:
#line 291 "grammar.y"
                                                               { (yyval.ptr) = struct_declaration_3 ((yyvsp[0].ptr)); }
#line 2953 "grammar.tab.c"
    break;

  case 140:
#line 295 "grammar.y"
                                                       { (yyval.ptr) = specifier_qualifier_list_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2959 "grammar.tab.c"
    break;

  case 141:
#line 296 "grammar.y"
                                                       { (yyval.ptr) = specifier_qualifier_list_2 ((yyvsp[0].ptr)); }
#line 2965 "grammar.tab.c"
    break;

  case 142:
#line 297 "grammar.y"
                                                       { (yyval.ptr) = specifier_qualifier_list_3 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 2971 "grammar.tab.c"
    break;

  case 143:
#line 298 "grammar.y"
                                                       { (yyval.ptr) = specifier_qualifier_list_4 ((yyvsp[0].ptr)); }
#line 2977 "grammar.tab.c"
    break;

  case 144:
#line 302 "grammar.y"
                                       { (yyval.ptr) = struct_declarator_list_1 ((yyvsp[0].ptr)); }
#line 2983 "grammar.tab.c"
    break;

  case 145:
#line 303 "grammar.y"
                                                               { (yyval.ptr) = struct_declarator_list_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 2989 "grammar.tab.c"
    break;

  case 146:
#line 307 "grammar.y"
                                               { (yyval.ptr) = struct_declarator_1 ((yyvsp[0].ptr)); }
#line 2995 "grammar.tab.c"
    break;

  case 147:
#line 308 "grammar.y"
                                               { (yyval.ptr) = struct_declarator_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3001 "grammar.tab.c"
    break;

  case 148:
#line 309 "grammar.y"
                                               { (yyval.ptr) = struct_declarator_3 ((yyvsp[0].ptr)); }
#line 3007 "grammar.tab.c"
    break;

  case 149:
#line 313 "grammar.y"
                                               { (yyval.ptr) = enum_specifier_1 ((yyvsp[-1].ptr)); }
#line 3013 "grammar.tab.c"
    break;

  case 150:
#line 314 "grammar.y"
                                               { (yyval.ptr) = enum_specifier_2 ((yyvsp[-2].ptr)); }
#line 3019 "grammar.tab.c"
    break;

  case 151:
#line 315 "grammar.y"
                                                           { (yyval.ptr) = enum_specifier_3 ((yyvsp[-3].str), (yyvsp[-1].ptr)); }
#line 3025 "grammar.tab.c"
    break;

  case 152:
#line 316 "grammar.y"
                                                           { (yyval.ptr) = enum_specifier_4 ((yyvsp[-4].str), (yyvsp[-2].ptr)); }
#line 3031 "grammar.tab.c"
    break;

  case 153:
#line 317 "grammar.y"
                                               { (yyval.ptr) = enum_specifier_5 ((yyvsp[0].str)); }
#line 3037 "grammar.tab.c"
    break;

  case 154:
#line 321 "grammar.y"
                                               { (yyval.ptr) = enumerator_list_1 ((yyvsp[0].ptr)); }
#line 3043 "grammar.tab.c"
    break;

  case 155:
#line 322 "grammar.y"
                                               { (yyval.ptr) = enumerator_list_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3049 "grammar.tab.c"
    break;

  case 156:
#line 326 "grammar.y"
                                                           { (yyval.ptr) = enumerator_1 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3055 "grammar.tab.c"
    break;

  case 157:
#line 327 "grammar.y"
                                                           { (yyval.ptr) = enumerator_2 ((yyvsp[0].ptr)); }
#line 3061 "grammar.tab.c"
    break;

  case 158:
#line 331 "grammar.y"
                                       { (yyval.ptr) = atomic_type_specifier_1 ((yyvsp[-1].ptr)); }
#line 3067 "grammar.tab.c"
    break;

  case 159:
#line 335 "grammar.y"
                           { (yyval.ptr) = type_qualifier_1 (); }
#line 3073 "grammar.tab.c"
    break;

  case 160:
#line 336 "grammar.y"
                           { (yyval.ptr) = type_qualifier_2 (); }
#line 3079 "grammar.tab.c"
    break;

  case 161:
#line 337 "grammar.y"
                           { (yyval.ptr) = type_qualifier_3 (); }
#line 3085 "grammar.tab.c"
    break;

  case 162:
#line 338 "grammar.y"
                           { (yyval.ptr) = type_qualifier_4 (); }
#line 3091 "grammar.tab.c"
    break;

  case 163:
#line 342 "grammar.y"
                           { (yyval.ptr) = function_specifier_1 (); }
#line 3097 "grammar.tab.c"
    break;

  case 164:
#line 343 "grammar.y"
                           { (yyval.ptr) = function_specifier_2 (); }
#line 3103 "grammar.tab.c"
    break;

  case 165:
#line 347 "grammar.y"
                                                   { (yyval.ptr) = alignment_specifier_1 ((yyvsp[-1].ptr)); }
#line 3109 "grammar.tab.c"
    break;

  case 166:
#line 348 "grammar.y"
                                                   { (yyval.ptr) = alignment_specifier_2 ((yyvsp[-1].ptr)); }
#line 3115 "grammar.tab.c"
    break;

  case 167:
#line 352 "grammar.y"
                                           { (yyval.ptr) = declarator_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3121 "grammar.tab.c"
    break;

  case 168:
#line 353 "grammar.y"
                                           { (yyval.ptr) = declarator_2 ((yyvsp[0].ptr)); }
#line 3127 "grammar.tab.c"
    break;

  case 169:
#line 357 "grammar.y"
                                   { (yyval.ptr) = direct_declarator_1 ((yyvsp[0].str)); }
#line 3133 "grammar.tab.c"
    break;

  case 170:
#line 358 "grammar.y"
                                   { (yyval.ptr) = direct_declarator_2 ((yyvsp[-1].ptr)); }
#line 3139 "grammar.tab.c"
    break;

  case 171:
#line 359 "grammar.y"
                                           { (yyval.ptr) = direct_declarator_3 ((yyvsp[-2].ptr)); }
#line 3145 "grammar.tab.c"
    break;

  case 172:
#line 360 "grammar.y"
                                           { (yyval.ptr) = direct_declarator_4 ((yyvsp[-3].ptr)); }
#line 3151 "grammar.tab.c"
    break;

  case 173:
#line 361 "grammar.y"
                                                                                       { (yyval.ptr) = direct_declarator_5 ((yyvsp[-5].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 3157 "grammar.tab.c"
    break;

  case 174:
#line 362 "grammar.y"
                                                                       { (yyval.ptr) = direct_declarator_6 ((yyvsp[-4].ptr), (yyvsp[-1].ptr)); }
#line 3163 "grammar.tab.c"
    break;

  case 175:
#line 363 "grammar.y"
                                                                       { (yyval.ptr) = direct_declarator_7 ((yyvsp[-4].ptr), (yyvsp[-2].ptr)); }
#line 3169 "grammar.tab.c"
    break;

  case 176:
#line 364 "grammar.y"
                                                                                       { (yyval.ptr) = direct_declarator_8 ((yyvsp[-5].ptr), (yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3175 "grammar.tab.c"
    break;

  case 177:
#line 365 "grammar.y"
                                                                                       { (yyval.ptr) = direct_declarator_9 ((yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 3181 "grammar.tab.c"
    break;

  case 178:
#line 366 "grammar.y"
                                                                       { (yyval.ptr) = direct_declarator_10 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3187 "grammar.tab.c"
    break;

  case 179:
#line 367 "grammar.y"
                                                                       { (yyval.ptr) = direct_declarator_11 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3193 "grammar.tab.c"
    break;

  case 180:
#line 368 "grammar.y"
                                                                       { (yyval.ptr) = direct_declarator_12 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3199 "grammar.tab.c"
    break;

  case 181:
#line 369 "grammar.y"
                                       { (yyval.ptr) = direct_declarator_13 ((yyvsp[-2].ptr)); }
#line 3205 "grammar.tab.c"
    break;

  case 182:
#line 370 "grammar.y"
                                                                       { (yyval.ptr) = direct_declarator_14 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3211 "grammar.tab.c"
    break;

  case 183:
#line 374 "grammar.y"
                                           { (yyval.ptr) = pointer_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3217 "grammar.tab.c"
    break;

  case 184:
#line 375 "grammar.y"
                                           { (yyval.ptr) = pointer_2 ((yyvsp[0].ptr)); }
#line 3223 "grammar.tab.c"
    break;

  case 185:
#line 376 "grammar.y"
                                           { (yyval.ptr) = pointer_3 ((yyvsp[0].ptr)); }
#line 3229 "grammar.tab.c"
    break;

  case 186:
#line 377 "grammar.y"
                                           { (yyval.ptr) = pointer_4 (); }
#line 3235 "grammar.tab.c"
    break;

  case 187:
#line 381 "grammar.y"
                                               { (yyval.ptr) = type_qualifier_list_1 ((yyvsp[0].ptr)); }
#line 3241 "grammar.tab.c"
    break;

  case 188:
#line 382 "grammar.y"
                                               { (yyval.ptr) = type_qualifier_list_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3247 "grammar.tab.c"
    break;

  case 189:
#line 387 "grammar.y"
                                           { (yyval.ptr) = parameter_type_list_1 ((yyvsp[-2].ptr)); }
#line 3253 "grammar.tab.c"
    break;

  case 190:
#line 388 "grammar.y"
                                           { (yyval.ptr) = parameter_type_list_2 ((yyvsp[0].ptr)); }
#line 3259 "grammar.tab.c"
    break;

  case 191:
#line 392 "grammar.y"
                                                       { (yyval.ptr) = parameter_list_1 ((yyvsp[0].ptr)); }
#line 3265 "grammar.tab.c"
    break;

  case 192:
#line 393 "grammar.y"
                                                       { (yyval.ptr) = parameter_list_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3271 "grammar.tab.c"
    break;

  case 193:
#line 397 "grammar.y"
                                                       { (yyval.ptr) = parameter_declaration_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3277 "grammar.tab.c"
    break;

  case 194:
#line 398 "grammar.y"
                                                       { (yyval.ptr) = parameter_declaration_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3283 "grammar.tab.c"
    break;

  case 195:
#line 399 "grammar.y"
                                                       { (yyval.ptr) = parameter_declaration_3 ((yyvsp[0].ptr)); }
#line 3289 "grammar.tab.c"
    break;

  case 196:
#line 403 "grammar.y"
                                               { (yyval.ptr) = identifier_list_1 ((yyvsp[0].str)); }
#line 3295 "grammar.tab.c"
    break;

  case 197:
#line 404 "grammar.y"
                                               { (yyval.ptr) = identifier_list_2 ((yyvsp[-2].ptr), (yyvsp[0].str)); }
#line 3301 "grammar.tab.c"
    break;

  case 198:
#line 408 "grammar.y"
                                                           { (yyval.ptr) = type_name_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3307 "grammar.tab.c"
    break;

  case 199:
#line 409 "grammar.y"
                                                           { (yyval.ptr) = type_name_2 ((yyvsp[0].ptr)); }
#line 3313 "grammar.tab.c"
    break;

  case 200:
#line 413 "grammar.y"
                                               { (yyval.ptr) = abstract_declarator_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3319 "grammar.tab.c"
    break;

  case 201:
#line 414 "grammar.y"
                                               { (yyval.ptr) = abstract_declarator_2 ((yyvsp[0].ptr)); }
#line 3325 "grammar.tab.c"
    break;

  case 202:
#line 415 "grammar.y"
                                               { (yyval.ptr) = abstract_declarator_3 ((yyvsp[0].ptr)); }
#line 3331 "grammar.tab.c"
    break;

  case 203:
#line 419 "grammar.y"
                                               { (yyval.ptr) = direct_abstract_declarator_1 ((yyvsp[-1].ptr)); }
#line 3337 "grammar.tab.c"
    break;

  case 204:
#line 420 "grammar.y"
                           { (yyval.ptr) = direct_abstract_declarator_2 (); }
#line 3343 "grammar.tab.c"
    break;

  case 205:
#line 421 "grammar.y"
                           { (yyval.ptr) = direct_abstract_declarator_3 (); }
#line 3349 "grammar.tab.c"
    break;

  case 206:
#line 422 "grammar.y"
                                                                   { (yyval.ptr) = direct_abstract_declarator_4 ((yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 3355 "grammar.tab.c"
    break;

  case 207:
#line 423 "grammar.y"
                                               { (yyval.ptr) = direct_abstract_declarator_5 ((yyvsp[-1].ptr)); }
#line 3361 "grammar.tab.c"
    break;

  case 208:
#line 424 "grammar.y"
                                                                   { (yyval.ptr) = direct_abstract_declarator_6 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3367 "grammar.tab.c"
    break;

  case 209:
#line 425 "grammar.y"
                                                                   { (yyval.ptr) = direct_abstract_declarator_7 ((yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 3373 "grammar.tab.c"
    break;

  case 210:
#line 426 "grammar.y"
                                               { (yyval.ptr) = direct_abstract_declarator_8 ((yyvsp[-1].ptr)); }
#line 3379 "grammar.tab.c"
    break;

  case 211:
#line 427 "grammar.y"
                                               { (yyval.ptr) = direct_abstract_declarator_9 ((yyvsp[-1].ptr)); }
#line 3385 "grammar.tab.c"
    break;

  case 212:
#line 428 "grammar.y"
                                               { (yyval.ptr) = direct_abstract_declarator_10 ((yyvsp[-2].ptr)); }
#line 3391 "grammar.tab.c"
    break;

  case 213:
#line 429 "grammar.y"
                                                   { (yyval.ptr) = direct_abstract_declarator_11 ((yyvsp[-3].ptr)); }
#line 3397 "grammar.tab.c"
    break;

  case 214:
#line 430 "grammar.y"
                                                                                               { (yyval.ptr) = direct_abstract_declarator_12 ((yyvsp[-5].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 3403 "grammar.tab.c"
    break;

  case 215:
#line 431 "grammar.y"
                                                                           { (yyval.ptr) = direct_abstract_declarator_13 ((yyvsp[-4].ptr), (yyvsp[-1].ptr)); }
#line 3409 "grammar.tab.c"
    break;

  case 216:
#line 432 "grammar.y"
                                                                                           { (yyval.ptr) = direct_abstract_declarator_14 ((yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr)); }
#line 3415 "grammar.tab.c"
    break;

  case 217:
#line 433 "grammar.y"
                                                                                               { (yyval.ptr) = direct_abstract_declarator_15 ((yyvsp[-5].ptr), (yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3421 "grammar.tab.c"
    break;

  case 218:
#line 434 "grammar.y"
                                                                       { (yyval.ptr) = direct_abstract_declarator_16 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3427 "grammar.tab.c"
    break;

  case 219:
#line 435 "grammar.y"
                                                                       { (yyval.ptr) = direct_abstract_declarator_17 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3433 "grammar.tab.c"
    break;

  case 220:
#line 436 "grammar.y"
                           { (yyval.ptr) = direct_abstract_declarator_18 (); }
#line 3439 "grammar.tab.c"
    break;

  case 221:
#line 437 "grammar.y"
                                           { (yyval.ptr) = direct_abstract_declarator_19 ((yyvsp[-1].ptr)); }
#line 3445 "grammar.tab.c"
    break;

  case 222:
#line 438 "grammar.y"
                                               { (yyval.ptr) = direct_abstract_declarator_20 ((yyvsp[-2].ptr)); }
#line 3451 "grammar.tab.c"
    break;

  case 223:
#line 439 "grammar.y"
                                                                   { (yyval.ptr) = direct_abstract_declarator_21 ((yyvsp[-3].ptr), (yyvsp[-1].ptr)); }
#line 3457 "grammar.tab.c"
    break;

  case 224:
#line 443 "grammar.y"
                                           { (yyval.ptr) = initializer_1 ((yyvsp[-1].ptr)); }
#line 3463 "grammar.tab.c"
    break;

  case 225:
#line 444 "grammar.y"
                                           { (yyval.ptr) = initializer_2 ((yyvsp[-2].ptr)); }
#line 3469 "grammar.tab.c"
    break;

  case 226:
#line 445 "grammar.y"
                                           { (yyval.ptr) = initializer_3 ((yyvsp[0].ptr)); }
#line 3475 "grammar.tab.c"
    break;

  case 227:
#line 449 "grammar.y"
                                                           { (yyval.ptr) = initializer_list_1 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3481 "grammar.tab.c"
    break;

  case 228:
#line 450 "grammar.y"
                                                           { (yyval.ptr) = initializer_list_2 ((yyvsp[0].ptr)); }
#line 3487 "grammar.tab.c"
    break;

  case 229:
#line 451 "grammar.y"
                                                           { (yyval.ptr) = initializer_list_3 ((yyvsp[-3].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3493 "grammar.tab.c"
    break;

  case 230:
#line 452 "grammar.y"
                                                           { (yyval.ptr) = initializer_list_4 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3499 "grammar.tab.c"
    break;

  case 231:
#line 456 "grammar.y"
                                       { (yyval.ptr) = designation_1 ((yyvsp[-1].ptr)); }
#line 3505 "grammar.tab.c"
    break;

  case 232:
#line 460 "grammar.y"
                                       { (yyval.ptr) = designator_list_1 ((yyvsp[0].ptr)); }
#line 3511 "grammar.tab.c"
    break;

  case 233:
#line 461 "grammar.y"
                                       { (yyval.ptr) = designator_list_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3517 "grammar.tab.c"
    break;

  case 234:
#line 465 "grammar.y"
                                       { (yyval.ptr) = designator_1 ((yyvsp[-1].ptr)); }
#line 3523 "grammar.tab.c"
    break;

  case 235:
#line 466 "grammar.y"
                                       { (yyval.ptr) = designator_2 ((yyvsp[0].str)); }
#line 3529 "grammar.tab.c"
    break;

  case 236:
#line 470 "grammar.y"
                                                                           { (yyval.ptr) = static_assert_declaration_1 ((yyvsp[-4].ptr), (yyvsp[-2].str)); }
#line 3535 "grammar.tab.c"
    break;

  case 237:
#line 474 "grammar.y"
                                   { (yyval.ptr) = statement_1 ((yyvsp[0].ptr)); }
#line 3541 "grammar.tab.c"
    break;

  case 238:
#line 475 "grammar.y"
                                   { (yyval.ptr) = statement_2 ((yyvsp[0].ptr)); }
#line 3547 "grammar.tab.c"
    break;

  case 239:
#line 476 "grammar.y"
                                   { (yyval.ptr) = statement_3 ((yyvsp[0].ptr)); }
#line 3553 "grammar.tab.c"
    break;

  case 240:
#line 477 "grammar.y"
                                   { (yyval.ptr) = statement_4 ((yyvsp[0].ptr)); }
#line 3559 "grammar.tab.c"
    break;

  case 241:
#line 478 "grammar.y"
                                   { (yyval.ptr) = statement_5 ((yyvsp[0].ptr)); }
#line 3565 "grammar.tab.c"
    break;

  case 242:
#line 479 "grammar.y"
                                   { (yyval.ptr) = statement_6 ((yyvsp[0].ptr)); }
#line 3571 "grammar.tab.c"
    break;

  case 243:
#line 483 "grammar.y"
                                                   { (yyval.ptr) = labeled_statement_1 ((yyvsp[-2].str), (yyvsp[0].ptr)); }
#line 3577 "grammar.tab.c"
    break;

  case 244:
#line 484 "grammar.y"
                                                   { (yyval.ptr) = labeled_statement_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3583 "grammar.tab.c"
    break;

  case 245:
#line 485 "grammar.y"
                                                   { (yyval.ptr) = labeled_statement_3 ((yyvsp[0].ptr)); }
#line 3589 "grammar.tab.c"
    break;

  case 246:
#line 489 "grammar.y"
                                       { (yyval.ptr) = compound_statement_1 (); }
#line 3595 "grammar.tab.c"
    break;

  case 247:
#line 490 "grammar.y"
              { push_scope (); }
#line 3601 "grammar.tab.c"
    break;

  case 248:
#line 490 "grammar.y"
                                                 { pull_scope (); }
#line 3607 "grammar.tab.c"
    break;

  case 249:
#line 490 "grammar.y"
                                                                            { (yyval.ptr) = compound_statement_2 ((yyvsp[-2].ptr)); }
#line 3613 "grammar.tab.c"
    break;

  case 250:
#line 494 "grammar.y"
                                       { (yyval.ptr) = block_item_list_1 ((yyvsp[0].ptr)); }
#line 3619 "grammar.tab.c"
    break;

  case 251:
#line 495 "grammar.y"
                                       { (yyval.ptr) = block_item_list_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3625 "grammar.tab.c"
    break;

  case 252:
#line 499 "grammar.y"
                                       { (yyval.ptr) = block_item_1 ((yyvsp[0].ptr)); }
#line 3631 "grammar.tab.c"
    break;

  case 253:
#line 500 "grammar.y"
                                       { (yyval.ptr) = block_item_2 ((yyvsp[0].ptr)); }
#line 3637 "grammar.tab.c"
    break;

  case 254:
#line 504 "grammar.y"
                                       { (yyval.ptr) = expression_statement_1 (); }
#line 3643 "grammar.tab.c"
    break;

  case 255:
#line 505 "grammar.y"
                                       { (yyval.ptr) = expression_statement_2 ((yyvsp[-1].ptr)); }
#line 3649 "grammar.tab.c"
    break;

  case 256:
#line 509 "grammar.y"
                                                           { (yyval.ptr) = selection_statement_1 ((yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3655 "grammar.tab.c"
    break;

  case 257:
#line 510 "grammar.y"
                                                           { (yyval.ptr) = selection_statement_2 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3661 "grammar.tab.c"
    break;

  case 258:
#line 511 "grammar.y"
                                                           { (yyval.ptr) = selection_statement_3 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3667 "grammar.tab.c"
    break;

  case 259:
#line 515 "grammar.y"
                                                           { (yyval.ptr) = iteration_statement_1 ((yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3673 "grammar.tab.c"
    break;

  case 260:
#line 516 "grammar.y"
                                                           { (yyval.ptr) = iteration_statement_2 ((yyvsp[-5].ptr), (yyvsp[-2].ptr)); }
#line 3679 "grammar.tab.c"
    break;

  case 261:
#line 517 "grammar.y"
                                                                           { (yyval.ptr) = iteration_statement_3 ((yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3685 "grammar.tab.c"
    break;

  case 262:
#line 518 "grammar.y"
                                                                                       { (yyval.ptr) = iteration_statement_4 ((yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3691 "grammar.tab.c"
    break;

  case 263:
#line 519 "grammar.y"
                                                                           { (yyval.ptr) = iteration_statement_5 ((yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3697 "grammar.tab.c"
    break;

  case 264:
#line 520 "grammar.y"
                                                                               { (yyval.ptr) = iteration_statement_6 ((yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr)); }
#line 3703 "grammar.tab.c"
    break;

  case 265:
#line 524 "grammar.y"
                                       { (yyval.ptr) = jump_statement_1 ((yyvsp[-1].str)); }
#line 3709 "grammar.tab.c"
    break;

  case 266:
#line 525 "grammar.y"
                                       { (yyval.ptr) = jump_statement_2 (); }
#line 3715 "grammar.tab.c"
    break;

  case 267:
#line 526 "grammar.y"
                                       { (yyval.ptr) = jump_statement_3 (); }
#line 3721 "grammar.tab.c"
    break;

  case 268:
#line 527 "grammar.y"
                                       { (yyval.ptr) = jump_statement_4 (); }
#line 3727 "grammar.tab.c"
    break;

  case 269:
#line 528 "grammar.y"
                                       { (yyval.ptr) = jump_statement_5 ((yyvsp[-1].ptr)); }
#line 3733 "grammar.tab.c"
    break;

  case 270:
#line 532 "grammar.y"
                                                   { (yyval.ptr) = translation_unit_1 ((yyvsp[0].ptr)); }
#line 3739 "grammar.tab.c"
    break;

  case 271:
#line 533 "grammar.y"
                                                   { (yyval.ptr) = translation_unit_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3745 "grammar.tab.c"
    break;

  case 272:
#line 537 "grammar.y"
                                                   { (yyval.ptr) = external_declaration_1 ((yyvsp[0].ptr)); }
#line 3751 "grammar.tab.c"
    break;

  case 273:
#line 538 "grammar.y"
                                                   { (yyval.ptr) = external_declaration_2 ((yyvsp[0].ptr)); }
#line 3757 "grammar.tab.c"
    break;

  case 274:
#line 542 "grammar.y"
                                                                                   { (yyval.ptr) = function_definition_1 ((yyvsp[-3].ptr), (yyvsp[-2].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3763 "grammar.tab.c"
    break;

  case 275:
#line 543 "grammar.y"
                                                                                   { (yyval.ptr) = function_definition_2 ((yyvsp[-2].ptr), (yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3769 "grammar.tab.c"
    break;

  case 276:
#line 547 "grammar.y"
                                           { (yyval.ptr) = declaration_list_1 ((yyvsp[0].ptr)); }
#line 3775 "grammar.tab.c"
    break;

  case 277:
#line 548 "grammar.y"
                                           { (yyval.ptr) = declaration_list_2 ((yyvsp[-1].ptr), (yyvsp[0].ptr)); }
#line 3781 "grammar.tab.c"
    break;

  case 278:
#line 552 "grammar.y"
                            { *ast = (yyvsp[0].ptr); }
#line 3787 "grammar.tab.c"
    break;


#line 3791 "grammar.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (ast, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (ast, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, ast);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 554 "grammar.y"

#include <stdio.h>

void yyerror(void ** shit __attribute__ ((unused)), const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
