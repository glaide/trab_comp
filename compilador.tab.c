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
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "rotulos.h"
#include "tabelaSimbolos.h"


int num_vars = 0;
int num_Rotulos=0;
int novasVariaveis, deslocamento, nivel_lexico, esta_no_procedimento, qnt_var_parametro, qnt_parametros, aux_var, qnt_novos_parametros;
TypeTabelaSimbolosPilha tabela_simbolos;
type_infos_tabela_simbolos *nova_entrada, *procedimento_atual, *destino, *carregada, *procedimento_atual;
char *rotuloAtual;
pilha_rotulo pilhaRotulo;
pilha_Tipo pilha_tipo;

char sinal_da_comparacao[100];
char printRotuloProcedimento[100];


#line 94 "compilador.tab.c"

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
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
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
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    IDENT = 268,
    ATRIBUICAO = 269,
    NUMERO = 270,
    INTEGER = 271,
    PROCEDURE = 272,
    WHILE = 273,
    DO = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    IGUAL = 278,
    DIFERENTE = 279,
    MENOR = 280,
    MENOR_IGUAL = 281,
    MAIOR_IGUAL = 282,
    MAIOR = 283,
    SOMA = 284,
    SUBTRACAO = 285,
    MULTIPLICACAO = 286,
    DIVISAO = 287,
    DIV = 288,
    AND = 289,
    READ = 290,
    WRITE = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */



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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    41,    56,    59,    63,    65,    71,    81,
      70,    92,   101,   102,   105,   108,   115,   116,   118,   118,
     123,   143,   121,   165,   165,   168,   168,   176,   178,   183,
     185,   185,   187,   194,   187,   202,   209,   218,   224,   218,
     234,   244,   243,   257,   267,   273,   281,   283,   284,   288,
     288,   293,   293,   295,   300,   302,   303,   304,   305,   306,
     307,   308,   310,   313,   313,   316,   335,   339,   340,   344,
     362,   389,   401,   414,   401,   437,   444,   447,   444,   465,
     465,   473,   476,   476,   481,   483,   487,   490,   493,   496,
     499,   502,   509,   509,   513,   513,   513,   518,   518,   523,
     526,   529,   532,   537,   537,   613,   613,   617,   620
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "NUMERO", "INTEGER",
  "PROCEDURE", "WHILE", "DO", "IF", "THEN", "ELSE", "IGUAL", "DIFERENTE",
  "MENOR", "MENOR_IGUAL", "MAIOR_IGUAL", "MAIOR", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "DIV", "AND", "READ", "WRITE", "$accept",
  "programa", "$@1", "parametros_ou_nada", "parametros", "nada", "bloco",
  "$@2", "$@3", "parte_declara_vars", "var", "declara_vars",
  "parte_declara_sub_rotinas", "regra_sub_rotina", "declara_procedimento",
  "$@4", "$@5", "parametros_formais_ou_nada", "parametros_formais", "$@6",
  "lista_parametros_formais", "secao_parametros_formais", "var_ou_nada",
  "comando_chama_procedimento", "$@7", "$@8", "expressoes_ou_nada",
  "declara_var", "$@10", "$@11", "tipo", "lista_id_var", "$@12",
  "lista_idents", "comando_composto", "comandos", "comando", "$@13",
  "numero_ou_nada", "$@14", "comando_sem_rotulo", "read", "lista_leitura",
  "simbolo_leitura", "write", "lista_escrita", "comando_atribuicao",
  "variavel", "numero", "comando_while", "$@15", "$@16", "comando_if",
  "if_then", "$@17", "$@18", "cond_else", "$@19", "expressao", "$@20",
  "relacao_expressao_simples", "relacao", "expressao_simples", "$@21",
  "mais_ou_menos", "termo", "lista_fator", "fator",
  "expressao_mais_menos_termo", "lista_e_termo", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -109,     6,     9,  -109,    18,    48,    42,    16,  -109,  -109,
    -109,    30,    47,  -109,    58,  -109,    61,  -109,  -109,    60,
    -109,    62,  -109,    60,  -109,  -109,  -109,  -109,    10,  -109,
      55,    64,    63,    65,  -109,    70,  -109,  -109,  -109,  -109,
    -109,  -109,    66,  -109,  -109,    67,    78,  -109,  -109,     2,
    -109,  -109,  -109,  -109,  -109,  -109,    77,  -109,    66,  -109,
       4,    79,    73,  -109,  -109,  -109,  -109,  -109,    82,    84,
    -109,  -109,    85,  -109,  -109,  -109,  -109,  -109,    76,  -109,
    -109,    69,  -109,  -109,  -109,    14,  -109,    42,    47,  -109,
    -109,    80,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    73,
      26,  -109,    81,    31,  -109,  -109,    57,  -109,    59,  -109,
    -109,  -109,     4,  -109,    63,  -109,  -109,  -109,  -109,    19,
    -109,    71,  -109,    80,  -109,  -109,  -109,    90,  -109,  -109,
      70,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    31,
      43,     4,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    -4,
    -109,    37,  -109,    43,    43,    43,    43,  -109,    43,    43,
    -109,  -109,  -109,  -109,  -109,    -4,    -4
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     7,     0,     0,     4,     5,
      45,     0,    37,     6,     0,    37,     0,     8,    11,    13,
      15,     0,    44,    12,     3,     7,    14,    43,     0,    17,
       7,     0,     0,     0,    19,     0,    16,    18,    41,    40,
      38,    20,     7,    10,    42,     0,     7,    71,    53,     0,
      48,    49,    51,    39,    25,    24,     0,    23,     7,    46,
       7,     0,     7,    21,    47,    70,    72,    76,     0,     0,
      60,    61,     0,    55,    50,    58,    59,    54,     0,    57,
      56,     7,    52,    30,    31,     0,    28,     0,    37,    82,
      82,     0,    82,    33,    82,    79,    81,    75,    26,     7,
       0,    22,     0,     7,    77,    65,     0,    64,     0,    68,
       7,    69,     7,    27,     0,    73,    94,    95,    96,     7,
      92,     0,    62,     0,    66,    82,    36,     0,    80,    29,
       0,    86,    87,    88,    89,    91,    90,    85,    83,     7,
       0,     7,    63,    67,    34,    74,    84,   104,   103,   106,
      98,    93,    78,     0,     0,     0,     0,    97,     0,     0,
     105,    99,   100,   101,   102,   107,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -109,  -109,    -5,    11,  -109,  -109,  -109,
    -109,    86,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,    -2,  -109,  -109,  -109,  -109,  -109,    -8,  -109,  -109,
     -12,  -109,  -109,    17,   -34,  -109,    45,  -109,  -109,  -109,
    -108,  -109,  -109,   -17,  -109,  -109,  -109,   -58,   -32,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   -87,  -109,
    -109,  -109,   -31,  -109,  -109,   -90,  -109,  -105,  -109,  -109
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    70,    16,    25,    35,    17,
      18,    19,    30,    36,    37,    46,    88,    56,    57,    62,
      85,    86,    87,    71,    72,   110,   127,    20,    21,    45,
      40,    28,    44,    11,    73,    49,    50,    60,    51,    61,
      74,    75,   106,   107,    76,   108,    77,   147,   148,    79,
      89,   130,    80,    81,    90,   121,    97,   112,   102,   103,
     138,   139,   119,   140,   120,   149,   157,   150,   151,   160
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    43,    78,   104,   128,   109,     3,   111,   -32,    58,
      52,    26,     4,    59,    42,    26,    31,    65,    32,    98,
      29,    99,    66,    12,    67,    34,    52,   153,   154,   155,
     156,     5,    14,   152,   114,    13,    14,    48,   143,    68,
      69,    55,   131,   132,   133,   134,   135,   136,   161,   162,
     163,   164,     6,    48,    78,    10,    65,    84,    47,    15,
     116,   117,   122,   123,   124,   125,   158,   159,   165,   166,
      24,    22,    33,   -37,    53,    27,    96,    38,    41,    39,
      42,    47,    54,    78,    63,    83,    91,    82,    92,    93,
      94,    95,   141,   105,    84,   144,   145,   113,   118,   101,
     115,    23,   129,    64,   100,   126,   142,     0,   146,     0,
       0,     0,     0,     0,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118
};

static const yytype_int16 yycheck[] =
{
       5,    35,    60,    90,   112,    92,     0,    94,     4,     7,
      42,    19,     3,    11,    10,    23,     6,    13,     8,     5,
      25,     7,    18,     7,    20,    30,    58,    31,    32,    33,
      34,    13,     6,   141,     8,     5,     6,    42,   125,    35,
      36,    46,    23,    24,    25,    26,    27,    28,   153,   154,
     155,   156,     4,    58,   112,    13,    13,    62,    15,    12,
      29,    30,     5,     6,     5,     6,    29,    30,   158,   159,
       9,    13,    17,    13,     7,    13,    81,    13,    13,    16,
      10,    15,     4,   141,     7,    12,     4,     8,     4,     4,
      14,    22,    21,    13,    99,     5,   130,    99,   103,    88,
      19,    15,   114,    58,    87,   110,   123,    -1,   139,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,    13,     4,    40,    41,    42,
      13,    70,     7,     5,     6,    12,    43,    46,    47,    48,
      64,    65,    13,    48,     9,    44,    64,    13,    68,    42,
      49,     6,     8,    17,    42,    45,    50,    51,    13,    16,
      67,    13,    10,    71,    69,    66,    52,    15,    42,    72,
      73,    75,    85,     7,     4,    42,    54,    55,     7,    11,
      74,    76,    56,     7,    73,    13,    18,    20,    35,    36,
      42,    60,    61,    71,    77,    78,    81,    83,    84,    86,
      89,    90,     8,    12,    42,    57,    58,    59,    53,    87,
      91,     4,     4,     4,    14,    22,    42,    93,     5,     7,
      70,    43,    95,    96,    95,    13,    79,    80,    82,    95,
      62,    95,    94,    58,     8,    19,    29,    30,    42,    99,
     101,    92,     5,     6,     5,     6,    42,    63,    77,    67,
      88,    23,    24,    25,    26,    27,    28,    42,    97,    98,
     100,    21,    80,    95,     5,    71,    99,    84,    85,   102,
     104,   105,    77,    31,    32,    33,    34,   103,    29,    30,
     106,   104,   104,   104,   104,   102,   102
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    42,    44,    45,
      43,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      52,    53,    51,    54,    54,    56,    55,    57,    57,    58,
      59,    59,    61,    62,    60,    60,    63,    65,    66,    64,
      67,    69,    68,    68,    70,    70,    71,    72,    72,    74,
      73,    76,    75,    75,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    79,    80,    81,    82,    82,    83,
      84,    85,    87,    88,    86,    89,    91,    92,    90,    94,
      93,    93,    96,    95,    97,    97,    98,    98,    98,    98,
      98,    98,   100,    99,   101,   101,   101,   102,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     0,     0,     0,
       5,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       0,     0,     7,     1,     1,     0,     4,     3,     1,     4,
       1,     1,     0,     0,     5,     0,     1,     0,     0,     6,
       1,     0,     4,     1,     3,     1,     3,     3,     1,     0,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     4,     3,     1,     3,
       1,     1,     0,     0,     6,     2,     0,     0,     6,     0,
       3,     1,     0,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     1,     1,     1,     2,     1,     2,
       2,     2,     2,     1,     1,     2,     1,     2,     2
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
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
#line 41 "compilador.y"
             { //TODO: rever todo esse bloco
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(num_Rotulos);
						 num_Rotulos++;
						 push_tabela_rotulos(&pilhaRotulo, RotInicioSubrotina);
             }
#line 1487 "compilador.tab.c"
    break;

  case 3:
#line 48 "compilador.y"
                         {
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1498 "compilador.tab.c"
    break;

  case 4:
#line 56 "compilador.y"
                               {

}
#line 1506 "compilador.tab.c"
    break;

  case 5:
#line 59 "compilador.y"
                         {

                  }
#line 1514 "compilador.tab.c"
    break;

  case 7:
#line 65 "compilador.y"
      {

}
#line 1522 "compilador.tab.c"
    break;

  case 8:
#line 71 "compilador.y"
              {
               // momento em que é feita a parte do desvio
               // cria um novo rotulo
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "DSVS %s", rotuloAtual);
               geraCodigo(NULL, rotuloPrint);
               printf("caiu no bloco\n");
              }
#line 1536 "compilador.tab.c"
    break;

  case 9:
#line 81 "compilador.y"
              {
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "%s", rotuloAtual);
               geraCodigo(rotuloPrint, "NADA");
              }
#line 1547 "compilador.tab.c"
    break;

  case 11:
#line 92 "compilador.y"
                         {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		atualizaNumeroVariaveis(&tabela_simbolos, num_vars, nivel_lexico);
		geraCodigo(NULL, amem);
}
#line 1558 "compilador.tab.c"
    break;

  case 14:
#line 105 "compilador.y"
                                       {
   printf("caiu no declara_vars\n");
}
#line 1566 "compilador.tab.c"
    break;

  case 15:
#line 108 "compilador.y"
                          {
   printf("caiu no declara_var\n");
            }
#line 1574 "compilador.tab.c"
    break;

  case 20:
#line 123 "compilador.y"
{
   nivel_lexico++;
   // cria os rotulos de entrada e saida do procedimento, e add eles na pilha de rotulos
   char *entraProcedimento = cria_rotulo(num_Rotulos);
   num_Rotulos++;
   push_tabela_rotulos(&pilhaRotulo, entraProcedimento);

   char *saiProcedimento = cria_rotulo(num_Rotulos);
   num_Rotulos++;
   push_tabela_rotulos(&pilhaRotulo, saiProcedimento);
   //faz a impressao do mepa
   char printRotuloEntrada[100];
   sprintf(printRotuloEntrada, "ENPR %d", nivel_lexico);
	geraCodigo(pega_rotulo(&pilhaRotulo, 2), printRotuloEntrada);

   // TODO: criar tipo de variavel para procedimento e add na tabela de simbolos
   nova_entrada=criaVariavelSimplesProcedimento(token,nivel_lexico, 0, entraProcedimento);
   push_tabela_simbolos(&tabela_simbolos, nova_entrada);
   procedimento_atual = nova_entrada;
   qnt_novos_parametros = 0;
}
#line 1600 "compilador.tab.c"
    break;

  case 21:
#line 143 "compilador.y"
                                             {
   // salva o numero atual de variaveis
   	aux_var = num_vars;
		num_vars = 0;
		deslocamento = 0;
}
#line 1611 "compilador.tab.c"
    break;

  case 22:
#line 148 "compilador.y"
        {
   char printRotuloSaida[100];
   pop_tabela_simbolos(&tabela_simbolos, procedimento_atual->qnt_variaveis);
	sprintf(printRotuloSaida, "DMEM %d", procedimento_atual->qnt_variaveis);
	geraCodigo(NULL, printRotuloSaida);
   pop_tabela_simbolos(&tabela_simbolos, procedimento_atual->numero_parametros);

	sprintf(printRotuloSaida, "RTPR %d, %d", nivel_lexico, procedimento_atual->numero_parametros);
   geraCodigo(NULL, printRotuloSaida);
   qnt_novos_parametros = 0;
   // saiu do procedimento
   nivel_lexico--;
   num_vars = aux_var;
   pop_pilha_rotulos(&pilhaRotulo, 2);

}
#line 1632 "compilador.tab.c"
    break;

  case 25:
#line 168 "compilador.y"
                                    {
qnt_parametros=0;
}
#line 1640 "compilador.tab.c"
    break;

  case 26:
#line 171 "compilador.y"
                                          {
   type_infos_tabela_simbolos *aux = pega_posicao(&tabela_simbolos,qnt_parametros);
   atualizaNumeroParametros(aux,&tabela_simbolos, qnt_parametros);
}
#line 1649 "compilador.tab.c"
    break;

  case 27:
#line 176 "compilador.y"
                                                                                           {
qnt_novos_parametros++;
}
#line 1657 "compilador.tab.c"
    break;

  case 32:
#line 187 "compilador.y"
                            {
   printf("chamou procedimento\n");
   esta_no_procedimento = 1;
   procedimento_atual = destino;

	sprintf(printRotuloProcedimento, "CHPR %s, %d", destino->rotulo, nivel_lexico);

}
#line 1670 "compilador.tab.c"
    break;

  case 33:
#line 194 "compilador.y"
                  {
   qnt_novos_parametros=0;
}
#line 1678 "compilador.tab.c"
    break;

  case 34:
#line 196 "compilador.y"
                                      {
   esta_no_procedimento = 0;
   geraCodigo(NULL, printRotuloProcedimento);
   destino = NULL;

}
#line 1689 "compilador.tab.c"
    break;

  case 35:
#line 202 "compilador.y"
{
   procedimento_atual = destino;
   sprintf(printRotuloProcedimento, "CHPR %s, %d", destino->rotulo, nivel_lexico);
	geraCodigo(NULL, printRotuloProcedimento);
   destino = NULL;
}
#line 1700 "compilador.tab.c"
    break;

  case 37:
#line 218 "compilador.y"
              {
   novasVariaveis= 0;
   printf("caiu no declara_var\n");
}
#line 1709 "compilador.tab.c"
    break;

  case 38:
#line 224 "compilador.y"
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;

               //para usar amem tem que saber qual deslocamento
               //TODO: implementar
              }
#line 1721 "compilador.tab.c"
    break;

  case 40:
#line 234 "compilador.y"
                      {

   setaTipo(&tabela_simbolos, integer, novasVariaveis);
   printf("caiu no integer\n");
}
#line 1731 "compilador.tab.c"
    break;

  case 41:
#line 244 "compilador.y"
{
   printf("caiu no 1\n");
}
#line 1739 "compilador.tab.c"
    break;

  case 42:
#line 247 "compilador.y"
              { /* insere ultima vars na tabela de s�mbolos */
               novasVariaveis++;
               //  add na tabela de simbolos
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;


               //  no futuro setar o valor de deslocamento tb
                }
#line 1754 "compilador.tab.c"
    break;

  case 43:
#line 257 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
   printf("caiu no 2\n");

               novasVariaveis++;
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;
               }
#line 1767 "compilador.tab.c"
    break;

  case 44:
#line 267 "compilador.y"
                                         {
   qnt_parametros++;
   printf("caiu no 3\n");

}
#line 1777 "compilador.tab.c"
    break;

  case 45:
#line 273 "compilador.y"
                   {
   printf("caiu no 4\n");

               qnt_parametros++;
            }
#line 1787 "compilador.tab.c"
    break;

  case 49:
#line 288 "compilador.y"
                       {

}
#line 1795 "compilador.tab.c"
    break;

  case 51:
#line 293 "compilador.y"
                       {

}
#line 1803 "compilador.tab.c"
    break;

  case 53:
#line 295 "compilador.y"
                     {

}
#line 1811 "compilador.tab.c"
    break;

  case 65:
#line 317 "compilador.y"
        {
   printf("caiu no 5\n");

		geraCodigo(NULL, "LEIT");
		destino = busca_tabela_simbolos(&tabela_simbolos, token);
		if(destino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

      char print[1000];
		sprintf(print, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, print);
		destino = NULL;
	}
#line 1831 "compilador.tab.c"
    break;

  case 67:
#line 339 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 1837 "compilador.tab.c"
    break;

  case 68:
#line 340 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 1843 "compilador.tab.c"
    break;

  case 69:
#line 345 "compilador.y"
{


		verifica_tipo(&pilha_tipo, "atribuicao");
		char printARM[100];
      // verifica o tipo de passagem de parametro
      printf("passagem de parametro %d\n", destino->passagem_parametro);
		if (destino->passagem_parametro == VALOR)
			sprintf(printARM, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);
		else
			sprintf(printARM, "ARMI %d, %d", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, printARM);
		destino = NULL;
	}
#line 1862 "compilador.tab.c"
    break;

  case 70:
#line 362 "compilador.y"
                {
   printf("caiu no 6\n");

   if (destino == NULL) {
         printf("Variavel nao declarada: %s\n", token);
         destino = busca_tabela_simbolos(&tabela_simbolos, token);

         if (destino == NULL) {
            printf("Variavel nao declarada: %s\n", token);
            exit(1);
         }

         push_pilha_Tipo(&pilha_tipo, destino->type);

   }
   else
    {
         printf("Variavel entrou em carregada: %s\n", token);

      carregada = busca_tabela_simbolos(&tabela_simbolos, token);
      if (carregada == NULL) {

         exit(1);
      }
      push_pilha_Tipo(&pilha_tipo, carregada->type);
   }
}
#line 1894 "compilador.tab.c"
    break;

  case 71:
#line 389 "compilador.y"
               {
	//TODO: add na tabela de tipos

		push_pilha_Tipo(&pilha_tipo, integer);

	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}
#line 1908 "compilador.tab.c"
    break;

  case 72:
#line 401 "compilador.y"
                     {
   //Cria rotulos do inicio e fim do While e adiciona eles na pilha de rotulos
      char *inicio_while = cria_rotulo(num_Rotulos);
      num_Rotulos++;
      char *fim_while = cria_rotulo(num_Rotulos);
      num_Rotulos++;

      push_tabela_rotulos(&pilhaRotulo, inicio_while);
      push_tabela_rotulos(&pilhaRotulo, fim_while);
      rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
      geraCodigo(rotuloAtual, "NADA");

   }
#line 1926 "compilador.tab.c"
    break;

  case 73:
#line 414 "compilador.y"
   {
      char dsvf[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(dsvf, "DSVF %s", rotuloAtual);
		geraCodigo(NULL, dsvf);
   }
#line 1937 "compilador.tab.c"
    break;

  case 74:
#line 419 "compilador.y"
                      {

      char dsvs[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		sprintf(dsvs, "DSVS %s",rotuloAtual);
		geraCodigo(NULL, dsvs);

		char rot[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(rot, "%s", rotuloAtual);
		geraCodigo(rot, "NADA");

		pop_pilha_rotulos(&pilhaRotulo, 2);
   }
#line 1956 "compilador.tab.c"
    break;

  case 75:
#line 437 "compilador.y"
                        {
         char rot[100];
         rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		   geraCodigo(rotuloAtual, "NADA");
		   pop_pilha_rotulos(&pilhaRotulo, 2);
       }
#line 1967 "compilador.tab.c"
    break;

  case 76:
#line 444 "compilador.y"
            {
   printf("passou do if\n");
}
#line 1975 "compilador.tab.c"
    break;

  case 77:
#line 447 "compilador.y"
      {
         printf("sinal da comparacao\n");
      char *inicio_If = cria_rotulo(num_Rotulos);
      num_Rotulos++;
		char *fim_If = cria_rotulo(num_Rotulos);
		num_Rotulos++;

		push_tabela_rotulos(&pilhaRotulo, inicio_If);
		push_tabela_rotulos(&pilhaRotulo, fim_If);

		char rot[100];
		sprintf(rot, "DSVF %s", pega_rotulo(&pilhaRotulo, 1));
		geraCodigo(NULL, rot);

      }
#line 1995 "compilador.tab.c"
    break;

  case 79:
#line 465 "compilador.y"
          {
         char rot[100];
         rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		   sprintf(rot, "DSVS %s", rotuloAtual);
		   geraCodigo(NULL, rot);

         rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		   geraCodigo(rotuloAtual, "NADA");
      }
#line 2009 "compilador.tab.c"
    break;

  case 82:
#line 476 "compilador.y"
          {
   qnt_novos_parametros++;
}
#line 2017 "compilador.tab.c"
    break;

  case 84:
#line 481 "compilador.y"
                                                     {
      geraCodigo(NULL, sinal_da_comparacao);
}
#line 2025 "compilador.tab.c"
    break;

  case 86:
#line 487 "compilador.y"
              {
      strcpy(sinal_da_comparacao,"CMIG");
   }
#line 2033 "compilador.tab.c"
    break;

  case 87:
#line 490 "compilador.y"
                    {
      strcpy(sinal_da_comparacao,"CMDG");
   }
#line 2041 "compilador.tab.c"
    break;

  case 88:
#line 493 "compilador.y"
                {
      strcpy(sinal_da_comparacao,"CMME");
   }
#line 2049 "compilador.tab.c"
    break;

  case 89:
#line 496 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMEG");
   }
#line 2057 "compilador.tab.c"
    break;

  case 90:
#line 499 "compilador.y"
           {
      strcpy(sinal_da_comparacao,"CMMA");
   }
#line 2065 "compilador.tab.c"
    break;

  case 91:
#line 502 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMAG");
   }
#line 2073 "compilador.tab.c"
    break;

  case 92:
#line 509 "compilador.y"
                                 {

}
#line 2081 "compilador.tab.c"
    break;

  case 96:
#line 513 "compilador.y"
                                       {

}
#line 2089 "compilador.tab.c"
    break;

  case 98:
#line 518 "compilador.y"
                                {

}
#line 2097 "compilador.tab.c"
    break;

  case 99:
#line 523 "compilador.y"
                            {
		verifica_tipo(&pilha_tipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 2105 "compilador.tab.c"
    break;

  case 100:
#line 526 "compilador.y"
                        {
		verifica_tipo(&pilha_tipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 2113 "compilador.tab.c"
    break;

  case 101:
#line 529 "compilador.y"
                    {
		verifica_tipo(&pilha_tipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 2121 "compilador.tab.c"
    break;

  case 102:
#line 532 "compilador.y"
                    {
		verifica_tipo(&pilha_tipo, "and");
		geraCodigo(NULL, "CONJ"); }
#line 2129 "compilador.tab.c"
    break;

  case 104:
#line 537 "compilador.y"
                         {
      if(carregada != NULL) {
			printf("variavel carregada: %s\n", carregada->rotulo);
         // verifica se é funcao
			if(carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
         // se nao é funcao, faz CRVL, CRVI ou CREN
			else {
            char comando[100];
            int num_proc, passagem_parametro, eh_ref_carregada;

            if (esta_no_procedimento == 2) {
               num_proc = procedimento_atual->numero_parametros - qnt_var_parametro + 1;
            } else {
               num_proc = qnt_novos_parametros;
            }

            if (esta_no_procedimento == 0) {
               passagem_parametro = carregada->passagem_parametro;
            } else {
               passagem_parametro = procedimento_atual->parametros[procedimento_atual->numero_parametros - num_proc].tipo_passado;
            }

            eh_ref_carregada = (passagem_parametro == REFERENCIA && esta_no_procedimento == 1 && carregada->passagem_parametro == REFERENCIA);

            if (passagem_parametro == VALOR || eh_ref_carregada) {
               sprintf(comando, "CRVL %d, %d", carregada->nivel_lexico, carregada->deslocamento);
            } else if (esta_no_procedimento >= 1 && passagem_parametro == REFERENCIA) {
               sprintf(comando, "CREN %d, %d", carregada->nivel_lexico, carregada->deslocamento);
            } else {
               sprintf(comando, "CRVI %d, %d", carregada->nivel_lexico, carregada->deslocamento);
            }

            carregada = NULL;
            geraCodigo(NULL, comando);

			}
      }
      else {

			if(destino->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", destino->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
            char comando[100];
            int passagem_parametro, eh_ref;

            if (esta_no_procedimento == 0) {
               passagem_parametro = destino->passagem_parametro;
            } else {
               passagem_parametro = procedimento_atual->parametros[procedimento_atual->numero_parametros - qnt_novos_parametros].tipo_passado;
            }

            eh_ref = (passagem_parametro == REFERENCIA && esta_no_procedimento == 1 && destino->passagem_parametro == REFERENCIA);

            if (passagem_parametro == VALOR || eh_ref) {
               sprintf(comando, "CRVL %d, %d", destino->nivel_lexico, destino->deslocamento);
            } else if (esta_no_procedimento == 1 && passagem_parametro == REFERENCIA) {
               sprintf(comando, "CREN %d, %d", destino->nivel_lexico, destino->deslocamento);
            } else {
               sprintf(comando, "CRVI %d, %d", destino->nivel_lexico, destino->deslocamento);
            }

            destino = NULL;
            geraCodigo(NULL, comando);

			}
		}
}
#line 2209 "compilador.tab.c"
    break;

  case 107:
#line 617 "compilador.y"
                   {
		verifica_tipo(&pilha_tipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 2217 "compilador.tab.c"
    break;

  case 108:
#line 620 "compilador.y"
                          {
		verifica_tipo(&pilha_tipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
#line 2225 "compilador.tab.c"
    break;


#line 2229 "compilador.tab.c"

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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 626 "compilador.y"


int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();
   criar_tabela_simbolos(&tabela_simbolos);
   cria_pilha_rotulo(&pilhaRotulo);
   cria_pilha_Tipo(&pilha_tipo);

   return 0;
}
