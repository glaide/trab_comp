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
int num_Rotulos=0;
int novasVariaveis, deslocamento, nivel_lexico, esta_no_procedimento, qnt_var_parametro, qnt_parametros, aux_var, qnt_novos_parametros;
TypeTabelaSimbolosPilha tabela_simbolos;
type_infos_tabela_simbolos *nova_entrada, *procedimento_atual, *destino, *carregada, *procedimento_atual;
char *rotuloAtual;
pilha_rotulo pilhaRotulo;
pilha_Tipo pilha_tipo;
pilha_no_procedimento pilha_no;

char sinal_da_comparacao[100];
char printRotuloProcedimento[100];


#line 96 "compilador.tab.c"

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
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_THEN = 21,                      /* THEN  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_IGUAL = 23,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 24,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 25,                     /* MENOR  */
  YYSYMBOL_MENOR_IGUAL = 26,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 27,               /* MAIOR_IGUAL  */
  YYSYMBOL_MAIOR = 28,                     /* MAIOR  */
  YYSYMBOL_SOMA = 29,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 30,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 31,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 32,                   /* DIVISAO  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_READ = 35,                      /* READ  */
  YYSYMBOL_WRITE = 36,                     /* WRITE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_parametros_ou_nada = 40,        /* parametros_ou_nada  */
  YYSYMBOL_parametros = 41,                /* parametros  */
  YYSYMBOL_nada = 42,                      /* nada  */
  YYSYMBOL_bloco = 43,                     /* bloco  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_parte_declara_vars = 46,        /* parte_declara_vars  */
  YYSYMBOL_var = 47,                       /* var  */
  YYSYMBOL_declara_vars = 48,              /* declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 49, /* parte_declara_sub_rotinas  */
  YYSYMBOL_regra_sub_rotina = 50,          /* regra_sub_rotina  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_declara_procedimento = 52,      /* declara_procedimento  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_parametros_formais_ou_nada = 55, /* parametros_formais_ou_nada  */
  YYSYMBOL_parametros_formais = 56,        /* parametros_formais  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_lista_parametros_formais = 58,  /* lista_parametros_formais  */
  YYSYMBOL_secao_parametros_formais = 59,  /* secao_parametros_formais  */
  YYSYMBOL_var_ou_nada = 60,               /* var_ou_nada  */
  YYSYMBOL_comando_chama_procedimento = 61, /* comando_chama_procedimento  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_expressoes_ou_nada = 64,        /* expressoes_ou_nada  */
  YYSYMBOL_declara_var = 65,               /* declara_var  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_67_12 = 67,                     /* $@12  */
  YYSYMBOL_tipo = 68,                      /* tipo  */
  YYSYMBOL_lista_id_var = 69,              /* lista_id_var  */
  YYSYMBOL_70_13 = 70,                     /* $@13  */
  YYSYMBOL_lista_idents = 71,              /* lista_idents  */
  YYSYMBOL_comando_composto = 72,          /* comando_composto  */
  YYSYMBOL_comandos = 73,                  /* comandos  */
  YYSYMBOL_comando = 74,                   /* comando  */
  YYSYMBOL_75_14 = 75,                     /* $@14  */
  YYSYMBOL_numero_ou_nada = 76,            /* numero_ou_nada  */
  YYSYMBOL_77_15 = 77,                     /* $@15  */
  YYSYMBOL_comando_sem_rotulo = 78,        /* comando_sem_rotulo  */
  YYSYMBOL_read = 79,                      /* read  */
  YYSYMBOL_lista_leitura = 80,             /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 81,           /* simbolo_leitura  */
  YYSYMBOL_write = 82,                     /* write  */
  YYSYMBOL_lista_escrita = 83,             /* lista_escrita  */
  YYSYMBOL_comando_atribuicao = 84,        /* comando_atribuicao  */
  YYSYMBOL_variavel = 85,                  /* variavel  */
  YYSYMBOL_numero = 86,                    /* numero  */
  YYSYMBOL_comando_while = 87,             /* comando_while  */
  YYSYMBOL_88_16 = 88,                     /* $@16  */
  YYSYMBOL_89_17 = 89,                     /* $@17  */
  YYSYMBOL_comando_if = 90,                /* comando_if  */
  YYSYMBOL_if_then = 91,                   /* if_then  */
  YYSYMBOL_92_18 = 92,                     /* $@18  */
  YYSYMBOL_93_19 = 93,                     /* $@19  */
  YYSYMBOL_cond_else = 94,                 /* cond_else  */
  YYSYMBOL_95_20 = 95,                     /* $@20  */
  YYSYMBOL_expressao = 96,                 /* expressao  */
  YYSYMBOL_97_21 = 97,                     /* $@21  */
  YYSYMBOL_relacao_expressao_simples = 98, /* relacao_expressao_simples  */
  YYSYMBOL_relacao = 99,                   /* relacao  */
  YYSYMBOL_expressao_simples = 100,        /* expressao_simples  */
  YYSYMBOL_101_22 = 101,                   /* $@22  */
  YYSYMBOL_mais_ou_menos = 102,            /* mais_ou_menos  */
  YYSYMBOL_termo = 103,                    /* termo  */
  YYSYMBOL_lista_fator = 104,              /* lista_fator  */
  YYSYMBOL_fator = 105,                    /* fator  */
  YYSYMBOL_expressao_mais_menos_termo = 106, /* expressao_mais_menos_termo  */
  YYSYMBOL_lista_e_termo = 107             /* lista_e_termo  */
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
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    42,    57,    60,    64,    66,    72,    82,
      71,    93,   106,   107,   110,   113,   120,   121,   123,   123,
     124,   129,   150,   127,   174,   174,   177,   177,   185,   187,
     192,   194,   194,   196,   203,   196,   211,   218,   227,   233,
     227,   243,   253,   252,   266,   276,   282,   290,   292,   293,
     297,   297,   302,   302,   304,   309,   311,   312,   313,   314,
     315,   316,   317,   319,   322,   322,   325,   344,   348,   349,
     353,   371,   398,   410,   423,   410,   446,   453,   456,   453,
     474,   474,   482,   485,   485,   490,   492,   496,   499,   502,
     505,   508,   511,   518,   518,   522,   522,   522,   527,   527,
     532,   535,   538,   541,   546,   546,   622,   622,   626,   629
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
  "NUMERO", "INTEGER", "PROCEDURE", "WHILE", "DO", "IF", "THEN", "ELSE",
  "IGUAL", "DIFERENTE", "MENOR", "MENOR_IGUAL", "MAIOR_IGUAL", "MAIOR",
  "SOMA", "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "DIV", "AND", "READ",
  "WRITE", "$accept", "programa", "$@1", "parametros_ou_nada",
  "parametros", "nada", "bloco", "$@2", "$@3", "parte_declara_vars", "var",
  "declara_vars", "parte_declara_sub_rotinas", "regra_sub_rotina", "$@4",
  "declara_procedimento", "$@5", "$@6", "parametros_formais_ou_nada",
  "parametros_formais", "$@7", "lista_parametros_formais",
  "secao_parametros_formais", "var_ou_nada", "comando_chama_procedimento",
  "$@8", "$@9", "expressoes_ou_nada", "declara_var", "$@11", "$@12",
  "tipo", "lista_id_var", "$@13", "lista_idents", "comando_composto",
  "comandos", "comando", "$@14", "numero_ou_nada", "$@15",
  "comando_sem_rotulo", "read", "lista_leitura", "simbolo_leitura",
  "write", "lista_escrita", "comando_atribuicao", "variavel", "numero",
  "comando_while", "$@16", "$@17", "comando_if", "if_then", "$@18", "$@19",
  "cond_else", "$@20", "expressao", "$@21", "relacao_expressao_simples",
  "relacao", "expressao_simples", "$@22", "mais_ou_menos", "termo",
  "lista_fator", "fator", "expressao_mais_menos_termo", "lista_e_termo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -111,    23,    38,  -111,    13,    49,    44,    61,  -111,  -111,
    -111,     7,    58,  -111,    56,  -111,    62,  -111,  -111,    59,
    -111,    60,  -111,    59,  -111,  -111,  -111,  -111,    10,  -111,
      63,    64,    65,    66,  -111,    72,  -111,  -111,  -111,  -111,
    -111,  -111,    69,  -111,    67,  -111,    68,    81,  -111,  -111,
      -1,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    79,  -111,
      69,  -111,     4,    80,    75,  -111,  -111,  -111,  -111,  -111,
      85,    86,  -111,  -111,    87,  -111,  -111,  -111,  -111,  -111,
      78,  -111,  -111,    54,  -111,  -111,  -111,    14,  -111,    44,
      58,  -111,  -111,    82,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    75,    26,  -111,    74,     6,  -111,  -111,    55,  -111,
      57,  -111,  -111,  -111,     4,  -111,    65,  -111,  -111,  -111,
    -111,    20,  -111,    73,  -111,    82,  -111,  -111,  -111,    92,
    -111,  -111,    72,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,     6,    43,     4,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    -3,  -111,    35,  -111,    43,    43,    43,    43,  -111,
      43,    43,  -111,  -111,  -111,  -111,  -111,    -3,    -3
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     7,     0,     0,     4,     5,
      46,     0,    38,     6,     0,    38,     0,     8,    11,    13,
      15,     0,    45,    12,     3,     7,    14,    44,     0,    17,
       7,     0,     0,     0,    20,     0,    16,    18,    42,    41,
      39,    21,     7,    10,     0,    43,     0,     7,    72,    54,
       0,    49,    50,    52,    19,    40,    26,    25,     0,    24,
       7,    47,     7,     0,     7,    22,    48,    71,    73,    77,
       0,     0,    61,    62,     0,    56,    51,    59,    60,    55,
       0,    58,    57,     7,    53,    31,    32,     0,    29,     0,
      38,    83,    83,     0,    83,    34,    83,    80,    82,    76,
      27,     7,     0,    23,     0,     7,    78,    66,     0,    65,
       0,    69,     7,    70,     7,    28,     0,    74,    95,    96,
      97,     7,    93,     0,    63,     0,    67,    83,    37,     0,
      81,    30,     0,    87,    88,    89,    90,    92,    91,    86,
      84,     7,     0,     7,    64,    68,    35,    75,    85,   105,
     104,   107,    99,    94,    79,     0,     0,     0,     0,    98,
       0,     0,   106,   100,   101,   102,   103,   108,   109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,    -5,     9,  -111,  -111,  -111,
    -111,    88,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,     0,  -111,  -111,  -111,  -111,  -111,    -8,  -111,
    -111,   -14,  -111,  -111,    15,   -34,  -111,    45,  -111,  -111,
    -111,  -110,  -111,  -111,   -19,  -111,  -111,  -111,   -60,   -33,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -89,
    -111,  -111,  -111,   -32,  -111,  -111,   -94,  -111,  -106,  -111,
    -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    72,    16,    25,    35,    17,
      18,    19,    30,    36,    44,    37,    47,    90,    58,    59,
      64,    87,    88,    89,    73,    74,   112,   129,    20,    21,
      46,    40,    28,    45,    11,    75,    50,    51,    62,    52,
      63,    76,    77,   108,   109,    78,   110,    79,   149,   150,
      81,    91,   132,    82,    83,    92,   123,    99,   114,   104,
     105,   140,   141,   121,   142,   122,   151,   159,   152,   153,
     162
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    43,    80,   106,   130,   111,    60,   113,   -33,    53,
      61,    26,    13,    14,    42,    26,    31,    67,    32,   100,
      29,   101,    68,     3,    69,    34,     5,    53,   155,   156,
     157,   158,    14,   154,   116,   118,   119,    49,   145,    70,
      71,     4,    57,   133,   134,   135,   136,   137,   138,   163,
     164,   165,   166,     6,    80,    49,    67,    10,    48,    86,
     124,   125,   126,   127,   160,   161,   167,   168,    12,    22,
      15,    24,   -38,    27,    54,    55,    97,    38,    98,    41,
      33,    39,    42,    80,    48,    56,    65,    85,    84,    93,
      94,    95,    96,   117,   143,   107,    86,   146,   147,   103,
     120,   115,   131,    23,   102,    66,   144,   128,     0,   148,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
       5,    35,    62,    92,   114,    94,     7,    96,     4,    42,
      11,    19,     5,     6,    10,    23,     6,    13,     8,     5,
      25,     7,    18,     0,    20,    30,    13,    60,    31,    32,
      33,    34,     6,   143,     8,    29,    30,    42,   127,    35,
      36,     3,    47,    23,    24,    25,    26,    27,    28,   155,
     156,   157,   158,     4,   114,    60,    13,    13,    15,    64,
       5,     6,     5,     6,    29,    30,   160,   161,     7,    13,
      12,     9,    13,    13,     7,     7,    22,    13,    83,    13,
      17,    16,    10,   143,    15,     4,     7,    12,     8,     4,
       4,     4,    14,    19,    21,    13,   101,     5,   132,    90,
     105,   101,   116,    15,    89,    60,   125,   112,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,    13,     4,    40,    41,    42,
      13,    71,     7,     5,     6,    12,    43,    46,    47,    48,
      65,    66,    13,    48,     9,    44,    65,    13,    69,    42,
      49,     6,     8,    17,    42,    45,    50,    52,    13,    16,
      68,    13,    10,    72,    51,    70,    67,    53,    15,    42,
      73,    74,    76,    86,     7,     7,     4,    42,    55,    56,
       7,    11,    75,    77,    57,     7,    74,    13,    18,    20,
      35,    36,    42,    61,    62,    72,    78,    79,    82,    84,
      85,    87,    90,    91,     8,    12,    42,    58,    59,    60,
      54,    88,    92,     4,     4,     4,    14,    22,    42,    94,
       5,     7,    71,    43,    96,    97,    96,    13,    80,    81,
      83,    96,    63,    96,    95,    59,     8,    19,    29,    30,
      42,   100,   102,    93,     5,     6,     5,     6,    42,    64,
      78,    68,    89,    23,    24,    25,    26,    27,    28,    42,
      98,    99,   101,    21,    81,    96,     5,    72,   100,    85,
      86,   103,   105,   106,    78,    31,    32,    33,    34,   104,
      29,    30,   107,   105,   105,   105,   105,   103,   103
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    42,    44,    45,
      43,    46,    47,    47,    48,    48,    49,    49,    51,    50,
      50,    53,    54,    52,    55,    55,    57,    56,    58,    58,
      59,    60,    60,    62,    63,    61,    61,    64,    66,    67,
      65,    68,    70,    69,    69,    71,    71,    72,    73,    73,
      75,    74,    77,    76,    76,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    80,    81,    82,    83,    83,
      84,    85,    86,    88,    89,    87,    90,    92,    93,    91,
      95,    94,    94,    97,    96,    98,    98,    99,    99,    99,
      99,    99,    99,   101,   100,   102,   102,   102,   103,   103,
     104,   104,   104,   104,   105,   105,   106,   106,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     0,     0,     0,
       5,     1,     2,     1,     2,     1,     2,     1,     0,     3,
       1,     0,     0,     7,     1,     1,     0,     4,     3,     1,
       4,     1,     1,     0,     0,     5,     0,     1,     0,     0,
       6,     1,     0,     4,     1,     3,     1,     3,     3,     1,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     1,     1,     4,     3,     1,
       3,     1,     1,     0,     0,     6,     2,     0,     0,     6,
       0,     3,     1,     0,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     1,     1,     2,     1,
       2,     2,     2,     2,     1,     1,     2,     1,     2,     2
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
#line 42 "compilador.y"
             { //TODO: rever todo esse bloco
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(num_Rotulos);
						 num_Rotulos++;
						 push_tabela_rotulos(&pilhaRotulo, RotInicioSubrotina);
             }
#line 1322 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_ou_nada PONTO_E_VIRGULA bloco PONTO  */
#line 49 "compilador.y"
                         {
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1333 "compilador.tab.c"
    break;

  case 4: /* parametros_ou_nada: parametros  */
#line 57 "compilador.y"
                               {

}
#line 1341 "compilador.tab.c"
    break;

  case 5: /* parametros_ou_nada: nada  */
#line 60 "compilador.y"
                         {

                  }
#line 1349 "compilador.tab.c"
    break;

  case 7: /* nada: %empty  */
#line 66 "compilador.y"
      {

}
#line 1357 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 72 "compilador.y"
              {
               // momento em que é feita a parte do desvio
               // cria um novo rotulo
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "DSVS %s", rotuloAtual);
               geraCodigo(NULL, rotuloPrint);
               printf("caiu no bloco\n");
              }
#line 1371 "compilador.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 82 "compilador.y"
              {
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "%s", rotuloAtual);
               geraCodigo(rotuloPrint, "NADA");
              }
#line 1382 "compilador.tab.c"
    break;

  case 11: /* parte_declara_vars: var  */
#line 93 "compilador.y"
                         {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		atualizaNumeroVariaveis(&tabela_simbolos, num_vars, nivel_lexico);
		geraCodigo(NULL, amem);




}
#line 1397 "compilador.tab.c"
    break;

  case 14: /* declara_vars: declara_vars declara_var  */
#line 110 "compilador.y"
                                       {
   printf("caiu no declara_vars\n");
}
#line 1405 "compilador.tab.c"
    break;

  case 15: /* declara_vars: declara_var  */
#line 113 "compilador.y"
                          {
   printf("caiu no declara_var\n");
            }
#line 1413 "compilador.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 123 "compilador.y"
                                        {atualizaNumProcedimento(&tabela_simbolos, nivel_lexico);}
#line 1419 "compilador.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 129 "compilador.y"
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
   push_pilha_no_procedimento(&pilha_no, nova_entrada);
   qnt_novos_parametros = 0;
}
#line 1446 "compilador.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 150 "compilador.y"
                                             {
   // salva o numero atual de variaveis
   	aux_var = num_vars;
		num_vars = 0;
		deslocamento = 0;
}
#line 1457 "compilador.tab.c"
    break;

  case 23: /* declara_procedimento: PROCEDURE IDENT $@5 parametros_formais_ou_nada PONTO_E_VIRGULA $@6 bloco  */
#line 155 "compilador.y"
        {
		procedimento_atual = (type_infos_tabela_simbolos*) pop_pilha_no_procedimento(&pilha_no);

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
#line 1480 "compilador.tab.c"
    break;

  case 26: /* $@7: %empty  */
#line 177 "compilador.y"
                                    {
qnt_parametros=0;
}
#line 1488 "compilador.tab.c"
    break;

  case 27: /* parametros_formais: ABRE_PARENTESES $@7 lista_parametros_formais FECHA_PARENTESES  */
#line 180 "compilador.y"
                                          {
   type_infos_tabela_simbolos *aux = pega_posicao(&tabela_simbolos,qnt_parametros);
   atualizaNumeroParametros(aux,&tabela_simbolos, qnt_parametros);
}
#line 1497 "compilador.tab.c"
    break;

  case 28: /* lista_parametros_formais: lista_parametros_formais PONTO_E_VIRGULA secao_parametros_formais  */
#line 185 "compilador.y"
                                                                                           {
qnt_novos_parametros++;
}
#line 1505 "compilador.tab.c"
    break;

  case 33: /* $@8: %empty  */
#line 196 "compilador.y"
                            {
   printf("chamou procedimento\n");
   esta_no_procedimento = 1;
   procedimento_atual = destino;

	sprintf(printRotuloProcedimento, "CHPR %s, %d", destino->rotulo, nivel_lexico);

}
#line 1518 "compilador.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 203 "compilador.y"
                  {
   qnt_novos_parametros=0;
}
#line 1526 "compilador.tab.c"
    break;

  case 35: /* comando_chama_procedimento: $@8 ABRE_PARENTESES $@9 expressoes_ou_nada FECHA_PARENTESES  */
#line 205 "compilador.y"
                                      {
   esta_no_procedimento = 0;
   geraCodigo(NULL, printRotuloProcedimento);
   destino = NULL;

}
#line 1537 "compilador.tab.c"
    break;

  case 36: /* comando_chama_procedimento: %empty  */
#line 211 "compilador.y"
{
   procedimento_atual = destino;
   sprintf(printRotuloProcedimento, "CHPR %s, %d", destino->rotulo, nivel_lexico);
	geraCodigo(NULL, printRotuloProcedimento);
   destino = NULL;
}
#line 1548 "compilador.tab.c"
    break;

  case 38: /* $@11: %empty  */
#line 227 "compilador.y"
              {
   novasVariaveis= 0;
   printf("caiu no declara_var\n");
}
#line 1557 "compilador.tab.c"
    break;

  case 39: /* $@12: %empty  */
#line 233 "compilador.y"
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;

               //para usar amem tem que saber qual deslocamento
               //TODO: implementar
              }
#line 1569 "compilador.tab.c"
    break;

  case 41: /* tipo: INTEGER  */
#line 243 "compilador.y"
                      {

   setaTipo(&tabela_simbolos, integer, novasVariaveis);
   printf("caiu no integer\n");
}
#line 1579 "compilador.tab.c"
    break;

  case 42: /* $@13: %empty  */
#line 253 "compilador.y"
{
   printf("caiu no 1\n");
}
#line 1587 "compilador.tab.c"
    break;

  case 43: /* lista_id_var: lista_id_var VIRGULA IDENT $@13  */
#line 256 "compilador.y"
              { /* insere ultima vars na tabela de s�mbolos */
               novasVariaveis++;
               //  add na tabela de simbolos
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;


               //  no futuro setar o valor de deslocamento tb
                }
#line 1602 "compilador.tab.c"
    break;

  case 44: /* lista_id_var: IDENT  */
#line 266 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
   printf("caiu no 2\n");

               novasVariaveis++;
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;
               }
#line 1615 "compilador.tab.c"
    break;

  case 45: /* lista_idents: lista_idents VIRGULA IDENT  */
#line 276 "compilador.y"
                                         {
   qnt_parametros++;
   printf("caiu no 3\n");

}
#line 1625 "compilador.tab.c"
    break;

  case 46: /* lista_idents: IDENT  */
#line 282 "compilador.y"
                   {
   printf("caiu no 4\n");

               qnt_parametros++;
            }
#line 1635 "compilador.tab.c"
    break;

  case 50: /* $@14: %empty  */
#line 297 "compilador.y"
                       {

}
#line 1643 "compilador.tab.c"
    break;

  case 52: /* $@15: %empty  */
#line 302 "compilador.y"
                       {

}
#line 1651 "compilador.tab.c"
    break;

  case 54: /* numero_ou_nada: nada  */
#line 304 "compilador.y"
                     {

}
#line 1659 "compilador.tab.c"
    break;

  case 66: /* simbolo_leitura: IDENT  */
#line 326 "compilador.y"
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
#line 1679 "compilador.tab.c"
    break;

  case 68: /* lista_escrita: lista_escrita VIRGULA expressao  */
#line 348 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 1685 "compilador.tab.c"
    break;

  case 69: /* lista_escrita: expressao  */
#line 349 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 1691 "compilador.tab.c"
    break;

  case 70: /* comando_atribuicao: variavel ATRIBUICAO expressao  */
#line 354 "compilador.y"
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
#line 1710 "compilador.tab.c"
    break;

  case 71: /* variavel: IDENT  */
#line 371 "compilador.y"
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
#line 1742 "compilador.tab.c"
    break;

  case 72: /* numero: NUMERO  */
#line 398 "compilador.y"
               {
	//TODO: add na tabela de tipos

		push_pilha_Tipo(&pilha_tipo, integer);

	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}
#line 1756 "compilador.tab.c"
    break;

  case 73: /* $@16: %empty  */
#line 410 "compilador.y"
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
#line 1774 "compilador.tab.c"
    break;

  case 74: /* $@17: %empty  */
#line 423 "compilador.y"
   {
      char dsvf[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(dsvf, "DSVF %s", rotuloAtual);
		geraCodigo(NULL, dsvf);
   }
#line 1785 "compilador.tab.c"
    break;

  case 75: /* comando_while: WHILE $@16 expressao DO $@17 comando_composto  */
#line 428 "compilador.y"
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
#line 1804 "compilador.tab.c"
    break;

  case 76: /* comando_if: if_then cond_else  */
#line 446 "compilador.y"
                        {
         char rot[100];
         rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		   geraCodigo(rotuloAtual, "NADA");
		   pop_pilha_rotulos(&pilhaRotulo, 2);
       }
#line 1815 "compilador.tab.c"
    break;

  case 77: /* $@18: %empty  */
#line 453 "compilador.y"
            {
   printf("passou do if\n");
}
#line 1823 "compilador.tab.c"
    break;

  case 78: /* $@19: %empty  */
#line 456 "compilador.y"
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
#line 1843 "compilador.tab.c"
    break;

  case 80: /* $@20: %empty  */
#line 474 "compilador.y"
          {
         char rot[100];
         rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		   sprintf(rot, "DSVS %s", rotuloAtual);
		   geraCodigo(NULL, rot);

         rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		   geraCodigo(rotuloAtual, "NADA");
      }
#line 1857 "compilador.tab.c"
    break;

  case 83: /* $@21: %empty  */
#line 485 "compilador.y"
          {
   qnt_novos_parametros++;
}
#line 1865 "compilador.tab.c"
    break;

  case 85: /* relacao_expressao_simples: relacao expressao_simples  */
#line 490 "compilador.y"
                                                     {
      geraCodigo(NULL, sinal_da_comparacao);
}
#line 1873 "compilador.tab.c"
    break;

  case 87: /* relacao: IGUAL  */
#line 496 "compilador.y"
              {
      strcpy(sinal_da_comparacao,"CMIG");
   }
#line 1881 "compilador.tab.c"
    break;

  case 88: /* relacao: DIFERENTE  */
#line 499 "compilador.y"
                    {
      strcpy(sinal_da_comparacao,"CMDG");
   }
#line 1889 "compilador.tab.c"
    break;

  case 89: /* relacao: MENOR  */
#line 502 "compilador.y"
                {
      strcpy(sinal_da_comparacao,"CMME");
   }
#line 1897 "compilador.tab.c"
    break;

  case 90: /* relacao: MENOR_IGUAL  */
#line 505 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMEG");
   }
#line 1905 "compilador.tab.c"
    break;

  case 91: /* relacao: MAIOR  */
#line 508 "compilador.y"
           {
      strcpy(sinal_da_comparacao,"CMMA");
   }
#line 1913 "compilador.tab.c"
    break;

  case 92: /* relacao: MAIOR_IGUAL  */
#line 511 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMAG");
   }
#line 1921 "compilador.tab.c"
    break;

  case 93: /* $@22: %empty  */
#line 518 "compilador.y"
                                 {

}
#line 1929 "compilador.tab.c"
    break;

  case 97: /* mais_ou_menos: nada  */
#line 522 "compilador.y"
                                       {

}
#line 1937 "compilador.tab.c"
    break;

  case 99: /* termo: fator  */
#line 527 "compilador.y"
                                {

}
#line 1945 "compilador.tab.c"
    break;

  case 100: /* lista_fator: MULTIPLICACAO fator  */
#line 532 "compilador.y"
                            {
		verifica_tipo(&pilha_tipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 1953 "compilador.tab.c"
    break;

  case 101: /* lista_fator: DIVISAO fator  */
#line 535 "compilador.y"
                        {
		verifica_tipo(&pilha_tipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 1961 "compilador.tab.c"
    break;

  case 102: /* lista_fator: DIV fator  */
#line 538 "compilador.y"
                    {
		verifica_tipo(&pilha_tipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 1969 "compilador.tab.c"
    break;

  case 103: /* lista_fator: AND fator  */
#line 541 "compilador.y"
                    {
		verifica_tipo(&pilha_tipo, "and");
		geraCodigo(NULL, "CONJ"); }
#line 1977 "compilador.tab.c"
    break;

  case 105: /* fator: variavel  */
#line 546 "compilador.y"
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
#line 2057 "compilador.tab.c"
    break;

  case 108: /* lista_e_termo: SOMA termo  */
#line 626 "compilador.y"
                   {
		verifica_tipo(&pilha_tipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 2065 "compilador.tab.c"
    break;

  case 109: /* lista_e_termo: SUBTRACAO termo  */
#line 629 "compilador.y"
                          {
		verifica_tipo(&pilha_tipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
#line 2073 "compilador.tab.c"
    break;


#line 2077 "compilador.tab.c"

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

#line 635 "compilador.y"


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
   cria_pilha_no_procedimento(&pilha_no);

   return 0;
}
