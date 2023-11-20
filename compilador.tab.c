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
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "rotulos.h"
#include "tabelaSimbolos.h"


int num_vars = 0;
int novasVariaveis, deslocamento, nivel_lexico;
int num_Rotulos=0;
TypeTabelaSimbolosPilha tabela_simbolos;
type_infos_tabela_simbolos *nova_entrada, *procedimento_atual, *destino, *carregada;
char *rotuloAtual;
pilha_rotulo pilhaRotulo;
pilha_Tipo tabelaTipo;

char sinal_da_comparacao[10];


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

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_ABRE_PARENTESES = 4,            /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 5,           /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 6,                    /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 7,            /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 8,                /* DOIS_PONTOS  */
  YYSYMBOL_PONTO = 9,                      /* PONTO  */
  YYSYMBOL_T_BEGIN = 10,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 11,                     /* T_END  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_ATRIBUICAO = 14,                /* ATRIBUICAO  */
  YYSYMBOL_NUMERO = 15,                    /* NUMERO  */
  YYSYMBOL_INTEGER = 16,                   /* INTEGER  */
  YYSYMBOL_PROCEDURE = 17,                 /* PROCEDURE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_IGUAL = 20,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 21,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 22,                     /* MENOR  */
  YYSYMBOL_MENOR_IGUAL = 23,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 24,               /* MAIOR_IGUAL  */
  YYSYMBOL_MAIOR = 25,                     /* MAIOR  */
  YYSYMBOL_SOMA = 26,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 27,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 28,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 29,                   /* DIVISAO  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_READ = 32,                      /* READ  */
  YYSYMBOL_WRITE = 33,                     /* WRITE  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_programa = 35,                  /* programa  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_parametros_ou_nada = 37,        /* parametros_ou_nada  */
  YYSYMBOL_parametros = 38,                /* parametros  */
  YYSYMBOL_nada = 39,                      /* nada  */
  YYSYMBOL_bloco = 40,                     /* bloco  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_42_3 = 42,                      /* $@3  */
  YYSYMBOL_parte_declara_vars = 43,        /* parte_declara_vars  */
  YYSYMBOL_var = 44,                       /* var  */
  YYSYMBOL_declara_vars = 45,              /* declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 46, /* parte_declara_sub_rotinas  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_regra_sub_rotina = 48,          /* regra_sub_rotina  */
  YYSYMBOL_declara_procedimento = 49,      /* declara_procedimento  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_parametros_formais_ou_nada = 51, /* parametros_formais_ou_nada  */
  YYSYMBOL_parametros_formais = 52,        /* parametros_formais  */
  YYSYMBOL_secao_parametros_formais = 53,  /* secao_parametros_formais  */
  YYSYMBOL_var_ou_nada = 54,               /* var_ou_nada  */
  YYSYMBOL_declara_var = 55,               /* declara_var  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_tipo = 58,                      /* tipo  */
  YYSYMBOL_lista_id_var = 59,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 60,              /* lista_idents  */
  YYSYMBOL_comando_composto = 61,          /* comando_composto  */
  YYSYMBOL_comandos = 62,                  /* comandos  */
  YYSYMBOL_comando = 63,                   /* comando  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_numero_ou_nada = 65,            /* numero_ou_nada  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_comando_sem_rotulo = 67,        /* comando_sem_rotulo  */
  YYSYMBOL_read = 68,                      /* read  */
  YYSYMBOL_lista_leitura = 69,             /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 70,           /* simbolo_leitura  */
  YYSYMBOL_comando_atribuicao = 71,        /* comando_atribuicao  */
  YYSYMBOL_variavel = 72,                  /* variavel  */
  YYSYMBOL_numero = 73,                    /* numero  */
  YYSYMBOL_comando_while = 74,             /* comando_while  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_expressao = 77,                 /* expressao  */
  YYSYMBOL_relacao_expressao_simples = 78, /* relacao_expressao_simples  */
  YYSYMBOL_relacao = 79,                   /* relacao  */
  YYSYMBOL_expressao_simples = 80,         /* expressao_simples  */
  YYSYMBOL_mais_ou_menos = 81,             /* mais_ou_menos  */
  YYSYMBOL_termo = 82,                     /* termo  */
  YYSYMBOL_lista_fator = 83,               /* lista_fator  */
  YYSYMBOL_fator = 84,                     /* fator  */
  YYSYMBOL_expressao_mais_menos_termo = 85, /* expressao_mais_menos_termo  */
  YYSYMBOL_lista_e_termo = 86,             /* lista_e_termo  */
  YYSYMBOL_87_12 = 87                      /* $@12  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   90

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    39,    54,    57,    61,    63,    69,    80,
      68,    98,   109,   110,   113,   114,   119,   119,   123,   125,
     125,   129,   128,   155,   155,   158,   158,   164,   166,   166,
     174,   179,   174,   189,   197,   210,   222,   224,   228,   230,
     231,   235,   235,   240,   240,   242,   247,   249,   251,   252,
     254,   256,   259,   259,   262,   288,   307,   327,   339,   350,
     339,   358,   363,   363,   370,   374,   377,   380,   384,   388,
     394,   396,   396,   396,   400,   400,   403,   406,   409,   412,
     417,   419,   419,   422,   422,   428
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "NUMERO", "INTEGER", "PROCEDURE", "WHILE", "DO", "IGUAL", "DIFERENTE",
  "MENOR", "MENOR_IGUAL", "MAIOR_IGUAL", "MAIOR", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "DIV", "AND", "READ", "WRITE", "$accept",
  "programa", "$@1", "parametros_ou_nada", "parametros", "nada", "bloco",
  "$@2", "$@3", "parte_declara_vars", "var", "declara_vars",
  "parte_declara_sub_rotinas", "$@4", "regra_sub_rotina",
  "declara_procedimento", "$@5", "parametros_formais_ou_nada",
  "parametros_formais", "secao_parametros_formais", "var_ou_nada",
  "declara_var", "$@6", "$@7", "tipo", "lista_id_var", "lista_idents",
  "comando_composto", "comandos", "comando", "$@8", "numero_ou_nada",
  "$@9", "comando_sem_rotulo", "read", "lista_leitura", "simbolo_leitura",
  "comando_atribuicao", "variavel", "numero", "comando_while", "$@10",
  "$@11", "expressao", "relacao_expressao_simples", "relacao",
  "expressao_simples", "mais_ou_menos", "termo", "lista_fator", "fator",
  "expressao_mais_menos_termo", "lista_e_termo", "$@12", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -120,     8,    12,  -120,    -2,    24,     9,    42,  -120,  -120,
    -120,    25,    20,  -120,    38,  -120,    46,  -120,  -120,  -120,
      43,  -120,    44,  -120,  -120,  -120,  -120,    10,  -120,  -120,
      45,    47,    48,    49,    50,  -120,  -120,  -120,    51,  -120,
      55,  -120,  -120,  -120,    54,  -120,  -120,    -1,  -120,  -120,
    -120,  -120,  -120,    51,  -120,    -9,    61,     1,  -120,  -120,
    -120,    59,  -120,  -120,  -120,  -120,  -120,    56,  -120,  -120,
       1,  -120,    58,    65,  -120,  -120,     9,    18,    60,    18,
    -120,    67,    20,    13,  -120,  -120,  -120,  -120,    14,    51,
    -120,    41,  -120,  -120,    63,  -120,    48,    39,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,    18,  -120,    -4,  -120,
      27,  -120,    60,  -120,  -120,  -120,  -120,    51,    51,    51,
      51,  -120,    51,  -120,    52,  -120,  -120,  -120,  -120,  -120,
      -4,    51,    -4
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     7,     0,     0,     4,     5,
      37,     0,    30,     6,     0,    30,     0,     8,    11,    13,
       0,    36,    12,    15,     3,     7,    35,     0,    14,    18,
       9,     0,     0,     0,     7,    34,    33,    31,     7,    10,
       0,    20,    17,    19,     0,    57,    45,     0,    40,    41,
      43,    21,    32,     7,    38,     7,     0,     7,    39,    56,
      58,     0,    50,    47,    42,    49,    46,     0,    48,    44,
       7,    28,    24,     0,    23,    26,     0,     7,     0,     7,
      29,     0,    30,     0,    71,    72,    73,    59,     7,     0,
      54,     0,    53,    55,     7,    22,     0,     0,    64,    65,
      66,    67,    68,    69,    63,    61,     7,    80,    82,    75,
      70,    51,     0,    25,    27,    60,    62,     0,     0,     0,
       0,    74,     0,    81,     0,    52,    76,    77,    78,    79,
      85,     0,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,    -5,    -6,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,     7,   -15,
    -120,    -8,  -120,  -120,   -16,  -120,     5,    29,  -120,    32,
    -120,  -120,  -120,  -120,  -120,  -120,   -30,  -120,  -120,   -36,
    -120,  -120,  -120,    11,  -120,  -120,   -20,  -120,  -119,  -120,
     -77,  -120,  -120,  -120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    86,    16,    25,    33,    17,
      18,    22,    30,    34,    42,    43,    57,    73,    74,    75,
      76,    19,    20,    44,    37,    27,    11,    39,    47,    48,
      55,    49,    56,    64,    65,    91,    92,    66,    67,   107,
      68,    77,    97,    87,   105,   106,    88,    89,   108,   121,
     109,   110,   123,   124
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    38,    50,   130,    59,    70,    53,    23,     3,    60,
      54,     5,   132,    71,    28,     4,    31,    50,    32,    14,
      29,    96,    10,    61,   117,   118,   119,   120,     6,    41,
      13,    14,    15,    46,    98,    99,   100,   101,   102,   103,
     126,   127,   128,   129,    84,    85,   111,   112,    46,    12,
      62,    21,    72,   -83,   122,    24,    26,   -30,   115,    38,
      35,    52,   -16,    78,    36,    80,    45,    40,    51,    69,
      79,   -29,    82,    90,    94,    71,    95,    81,   131,   113,
     114,    83,   125,   104,    63,    58,   116,     0,     0,    80,
      93
};

static const yytype_int16 yycheck[] =
{
       5,    10,    38,   122,    13,     4,     7,    15,     0,    18,
      11,    13,   131,    12,    22,     3,     6,    53,     8,     6,
      25,     8,    13,    32,    28,    29,    30,    31,     4,    34,
       5,     6,    12,    38,    20,    21,    22,    23,    24,    25,
     117,   118,   119,   120,    26,    27,     5,     6,    53,     7,
      55,    13,    57,    26,    27,     9,    13,    13,    19,    10,
      13,     7,    17,     4,    16,    70,    15,    17,    13,     8,
      14,    13,     7,    13,     7,    12,    82,    70,    26,    94,
      96,    76,   112,    88,    55,    53,   106,    -1,    -1,    94,
      79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    36,     0,     3,    13,     4,    37,    38,    39,
      13,    60,     7,     5,     6,    12,    40,    43,    44,    55,
      56,    13,    45,    55,     9,    41,    13,    59,    55,    39,
      46,     6,     8,    42,    47,    13,    16,    58,    10,    61,
      17,    39,    48,    49,    57,    15,    39,    62,    63,    65,
      73,    13,     7,     7,    11,    64,    66,    50,    63,    13,
      18,    32,    39,    61,    67,    68,    71,    72,    74,     8,
       4,    12,    39,    51,    52,    53,    54,    75,     4,    14,
      39,    52,     7,    60,    26,    27,    39,    77,    80,    81,
      13,    69,    70,    77,     7,    40,     8,    76,    20,    21,
      22,    23,    24,    25,    39,    78,    79,    73,    82,    84,
      85,     5,     6,    53,    58,    19,    80,    28,    29,    30,
      31,    83,    27,    86,    87,    70,    84,    84,    84,    84,
      82,    26,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    35,    37,    37,    38,    39,    41,    42,
      40,    43,    44,    44,    45,    45,    47,    46,    46,    48,
      48,    50,    49,    51,    51,    52,    52,    53,    54,    54,
      56,    57,    55,    58,    59,    59,    60,    60,    61,    62,
      62,    64,    63,    66,    65,    65,    67,    67,    67,    67,
      67,    68,    69,    69,    70,    71,    72,    73,    75,    76,
      74,    77,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    81,    81,    81,    82,    82,    83,    83,    83,    83,
      84,    85,    85,    87,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     0,     0,     0,
       5,     1,     2,     1,     2,     1,     0,     3,     1,     1,
       1,     0,     6,     1,     1,     4,     1,     4,     1,     1,
       0,     0,     6,     1,     3,     1,     3,     1,     3,     3,
       1,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     1,     3,     1,     1,     0,     0,
       5,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     2,     2,     2,     2,
       1,     2,     1,     0,     3,     2
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
  case 2: /* $@1: %empty  */
#line 39 "compilador.y"
             { //TODO: rever todo esse bloco
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(num_Rotulos);
						 num_Rotulos++;
						 push_tabela_rotulos(&pilhaRotulo, RotInicioSubrotina);
             }
#line 1269 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_ou_nada PONTO_E_VIRGULA bloco PONTO  */
#line 46 "compilador.y"
                         {
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1280 "compilador.tab.c"
    break;

  case 4: /* parametros_ou_nada: parametros  */
#line 54 "compilador.y"
                               {

}
#line 1288 "compilador.tab.c"
    break;

  case 5: /* parametros_ou_nada: nada  */
#line 57 "compilador.y"
                         {

                  }
#line 1296 "compilador.tab.c"
    break;

  case 7: /* nada: %empty  */
#line 63 "compilador.y"
      {
   printf("entrou em nada\n");
}
#line 1304 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 69 "compilador.y"
              {
               // momento em que é feita a parte do desvio
               // cria um novo rotulo
               char rotuloPrint[100];
               rotuloAtual = pega_Rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "DSVS %s", rotuloAtual);
               geraCodigo(NULL, rotuloPrint);

              }
#line 1318 "compilador.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 80 "compilador.y"
              {

               char rotuloPrint[100];
               rotuloAtual = pega_Rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "%s", rotuloAtual);
               geraCodigo(rotuloPrint, "NADA");



              }
#line 1333 "compilador.tab.c"
    break;

  case 11: /* parte_declara_vars: var  */
#line 98 "compilador.y"
                         {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		atualizaNumeroVariaveis(&tabela_simbolos, num_vars, nivel_lexico);

		geraCodigo(NULL, amem);
}
#line 1345 "compilador.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 119 "compilador.y"
                                                     {


}
#line 1354 "compilador.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 129 "compilador.y"
{

//TODO: implementar
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
	geraCodigo(pega_Rotulo(&pilhaRotulo, 2), printRotuloEntrada);
   // TODO: criar tipo de variavel para procedimento e add na tabela de simbolos
   nova_entrada=criaVariavelSimplesProcedimento(token,nivel_lexico, 0, entraProcedimento);
   push_tabela_simbolos(&tabela_simbolos, nova_entrada);
   imprime_tabela_simbolos(&tabela_simbolos);

   procedimento_atual = nova_entrada;

}
#line 1384 "compilador.tab.c"
    break;

  case 30: /* $@6: %empty  */
#line 174 "compilador.y"
              {
   novasVariaveis= 0;
}
#line 1392 "compilador.tab.c"
    break;

  case 31: /* $@7: %empty  */
#line 179 "compilador.y"
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;
               printf("num de variaveis %d\n", num_vars);
               //para usar amem tem que saber qual deslocamento
               //TODO: implementar
              }
#line 1404 "compilador.tab.c"
    break;

  case 33: /* tipo: INTEGER  */
#line 189 "compilador.y"
                      {

   setaTipo(&tabela_simbolos, integer, novasVariaveis);
}
#line 1413 "compilador.tab.c"
    break;

  case 34: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 198 "compilador.y"
              { /* insere ultima vars na tabela de s�mbolos */
                novasVariaveis++;
               //  add na tabela de simbolos

               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               imprime_tabela_simbolos(&tabela_simbolos);
                deslocamento++;


               //  no futuro setar o valor de deslocamento tb
                }
#line 1430 "compilador.tab.c"
    break;

  case 35: /* lista_id_var: IDENT  */
#line 210 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
              novasVariaveis++;

               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               imprime_tabela_simbolos(&tabela_simbolos);
                deslocamento++;


               }
#line 1445 "compilador.tab.c"
    break;

  case 41: /* $@8: %empty  */
#line 235 "compilador.y"
                       {
   printf("entrou em comando\n");
}
#line 1453 "compilador.tab.c"
    break;

  case 43: /* $@9: %empty  */
#line 240 "compilador.y"
                       {
   printf("entrou em numero_ou_nada\n");
}
#line 1461 "compilador.tab.c"
    break;

  case 45: /* numero_ou_nada: nada  */
#line 242 "compilador.y"
                     {

}
#line 1469 "compilador.tab.c"
    break;

  case 54: /* simbolo_leitura: IDENT  */
#line 263 "compilador.y"
        {
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
#line 1487 "compilador.tab.c"
    break;

  case 55: /* comando_atribuicao: variavel ATRIBUICAO expressao  */
#line 289 "compilador.y"
{


		verifica_tipo(&tabelaTipo, "atribuicao");
		char printARM[100];
      // verifica o tipo de passagem de parametro
      printf("passagem de parametro %d\n", destino->passagem_parametro);
		if (destino->passagem_parametro == VALOR)
{      printf("saiu do verifica_tipo\n");
			sprintf(printARM, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);}
		else
			sprintf(printARM, "ARMI %d, %d", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, printARM);
		destino = NULL;
	}
#line 1507 "compilador.tab.c"
    break;

  case 56: /* variavel: IDENT  */
#line 307 "compilador.y"
                {
   if (destino == NULL) {
         destino = busca_tabela_simbolos(&tabela_simbolos, token);

         if (destino == NULL) {
            printf("Variavel nao declarada: %s\n", token);
            exit(1);
         }

         push_pilha_Tipo(&tabelaTipo, destino->type);
   }
   else {
      carregada = busca_tabela_simbolos(&tabela_simbolos, token);
      if (carregada == NULL) {
         printf("Variavel nao declarada: %s\n", token);
         exit(1);
      }
      push_pilha_Tipo(&tabelaTipo, carregada->type);
   }
}
#line 1532 "compilador.tab.c"
    break;

  case 57: /* numero: NUMERO  */
#line 327 "compilador.y"
               {
	//TODO: add na tabela de tipos
   printf("entrou em numero\n");
		push_pilha_Tipo(&tabelaTipo, integer);
      printf("saiu de push_pilha_Tipo\n");
	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}
#line 1546 "compilador.tab.c"
    break;

  case 58: /* $@10: %empty  */
#line 339 "compilador.y"
                     {
   //Cria rotulos do inicio e fim do While e adiciona eles na pilha de rotulos
      char *ROTwhile_ini = cria_rotulo(num_Rotulos);
      num_Rotulos++;
      char *ROTwhile_fim = cria_rotulo(num_Rotulos);
      num_Rotulos++;

      push_tabela_rotulos(&pilhaRotulo, ROTwhile_ini);
      push_tabela_rotulos(&pilhaRotulo, ROTwhile_fim);

      geraCodigo(pega_Rotulo(&pilhaRotulo, 2), "NADA");
   }
#line 1563 "compilador.tab.c"
    break;

  case 59: /* $@11: %empty  */
#line 350 "compilador.y"
               {}
#line 1569 "compilador.tab.c"
    break;

  case 60: /* comando_while: WHILE $@10 expressao $@11 DO  */
#line 351 "compilador.y"
     {
      char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_Rotulo(&pilhaRotulo, 1));
		geraCodigo(NULL, dsvf);
   }
#line 1579 "compilador.tab.c"
    break;

  case 61: /* expressao: expressao_simples relacao_expressao_simples  */
#line 358 "compilador.y"
                                                       {
   printf("entrou em expressao\n");
}
#line 1587 "compilador.tab.c"
    break;

  case 63: /* relacao_expressao_simples: nada  */
#line 364 "compilador.y"
{
   printf("entrou nesse nada\n");
}
#line 1595 "compilador.tab.c"
    break;

  case 64: /* relacao: IGUAL  */
#line 370 "compilador.y"
             {
      // TODO: implementar
      strcpy(sinal_da_comparacao,"CMIG");
   }
#line 1604 "compilador.tab.c"
    break;

  case 65: /* relacao: DIFERENTE  */
#line 374 "compilador.y"
                    {
      strcpy(sinal_da_comparacao,"CMDG");
     }
#line 1612 "compilador.tab.c"
    break;

  case 66: /* relacao: MENOR  */
#line 377 "compilador.y"
                {
      strcpy(sinal_da_comparacao,"CMME");
   }
#line 1620 "compilador.tab.c"
    break;

  case 67: /* relacao: MENOR_IGUAL  */
#line 380 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMEG");

   }
#line 1629 "compilador.tab.c"
    break;

  case 68: /* relacao: MAIOR_IGUAL  */
#line 384 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMAG");

   }
#line 1638 "compilador.tab.c"
    break;

  case 69: /* relacao: MAIOR  */
#line 388 "compilador.y"
                {
      strcpy(sinal_da_comparacao,"CMMA");
    }
#line 1646 "compilador.tab.c"
    break;

  case 76: /* lista_fator: MULTIPLICACAO fator  */
#line 403 "compilador.y"
                            {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 1654 "compilador.tab.c"
    break;

  case 77: /* lista_fator: DIVISAO fator  */
#line 406 "compilador.y"
                        {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 1662 "compilador.tab.c"
    break;

  case 78: /* lista_fator: DIV fator  */
#line 409 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 1670 "compilador.tab.c"
    break;

  case 79: /* lista_fator: AND fator  */
#line 412 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "and");
		geraCodigo(NULL, "CONJ"); }
#line 1678 "compilador.tab.c"
    break;

  case 83: /* $@12: %empty  */
#line 422 "compilador.y"
        {
		printf("Lista termo\n");
	}
#line 1686 "compilador.tab.c"
    break;

  case 84: /* lista_e_termo: $@12 SOMA termo  */
#line 425 "compilador.y"
                   {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 1694 "compilador.tab.c"
    break;

  case 85: /* lista_e_termo: SUBTRACAO termo  */
#line 428 "compilador.y"
                          {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
#line 1702 "compilador.tab.c"
    break;


#line 1706 "compilador.tab.c"

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

#line 434 "compilador.y"


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
   cria_pilha_Tipo(&tabelaTipo);

   return 0;
}
