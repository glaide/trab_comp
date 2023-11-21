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
#include "pilha.h"
#include "tabelaSimbolos.h"


int numero_variaveis, numero_parametros, nivel_lexico, deslocamento;
int entra_procedimento,aux_var, novas_variaveis, novos_param,por_ref;
char *rotulo_fim_subr;
int rotulo_print = 0;

int num_params_chamada;
char comparacao[100], rotuloPrint[100], *funcao_atual;

pilha_simbolos tabelaSimbolos;
type_info_tabela_simbolos *novaEntrada, *destino, *carregada, *procedimento_atual;
tipo_pilha tabelaTipo;
pilha_rotulo pilha_rotulos;
pilha_no tabelaNode;


#line 97 "compilador.tab.c"

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
  YYSYMBOL_INTEGER = 15,                   /* INTEGER  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_THEN = 19,                      /* THEN  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_MAIOR = 21,                     /* MAIOR  */
  YYSYMBOL_MENOR = 22,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 23,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 24,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 25,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 26,                 /* DIFERENTE  */
  YYSYMBOL_SOMA = 27,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 28,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 29,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 30,                   /* DIVISAO  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_NUMERO = 32,                    /* NUMERO  */
  YYSYMBOL_READ = 33,                      /* READ  */
  YYSYMBOL_WRITE = 34,                     /* WRITE  */
  YYSYMBOL_PROCEDURE = 35,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 36,                  /* FUNCTION  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_parametros_nada = 40,           /* parametros_nada  */
  YYSYMBOL_parametros = 41,                /* parametros  */
  YYSYMBOL_tipo = 42,                      /* tipo  */
  YYSYMBOL_bloco = 43,                     /* bloco  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_parte_declara_vars = 46,        /* parte_declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 47, /* parte_declara_sub_rotinas  */
  YYSYMBOL_regra_subrotina = 48,           /* regra_subrotina  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_declara_vars = 52,              /* declara_vars  */
  YYSYMBOL_declara_var = 53,               /* declara_var  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_55_7 = 55,                      /* $@7  */
  YYSYMBOL_lista_id_var = 56,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 57,              /* lista_idents  */
  YYSYMBOL_comando_while = 58,             /* comando_while  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_60_9 = 60,                      /* $@9  */
  YYSYMBOL_comando_if = 61,                /* comando_if  */
  YYSYMBOL_if = 62,                        /* if  */
  YYSYMBOL_63_10 = 63,                     /* $@10  */
  YYSYMBOL_else = 64,                      /* else  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_else_multiplo_unico = 66,       /* else_multiplo_unico  */
  YYSYMBOL_declaracao_procedimento = 67,   /* declaracao_procedimento  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_declaracao_funcao = 71,         /* declaracao_funcao  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_73_16 = 73,                     /* $@16  */
  YYSYMBOL_parametros_formais_vazio = 74,  /* parametros_formais_vazio  */
  YYSYMBOL_parametros_formais = 75,        /* parametros_formais  */
  YYSYMBOL_76_17 = 76,                     /* $@17  */
  YYSYMBOL_lista_parametros_formais = 77,  /* lista_parametros_formais  */
  YYSYMBOL_78_18 = 78,                     /* $@18  */
  YYSYMBOL_secao_parametros_formais = 79,  /* secao_parametros_formais  */
  YYSYMBOL_80_19 = 80,                     /* $@19  */
  YYSYMBOL_var_vazio = 81,                 /* var_vazio  */
  YYSYMBOL_comando_composto = 82,          /* comando_composto  */
  YYSYMBOL_comandos = 83,                  /* comandos  */
  YYSYMBOL_comando = 84,                   /* comando  */
  YYSYMBOL_nunero_nada = 85,               /* nunero_nada  */
  YYSYMBOL_nada = 86,                      /* nada  */
  YYSYMBOL_comando_sem_rotulo = 87,        /* comando_sem_rotulo  */
  YYSYMBOL_chama_procedimento = 88,        /* chama_procedimento  */
  YYSYMBOL_89_20 = 89,                     /* $@20  */
  YYSYMBOL_90_21 = 90,                     /* $@21  */
  YYSYMBOL_91_22 = 91,                     /* $@22  */
  YYSYMBOL_chama_funcao = 92,              /* chama_funcao  */
  YYSYMBOL_93_23 = 93,                     /* $@23  */
  YYSYMBOL_94_24 = 94,                     /* $@24  */
  YYSYMBOL_95_25 = 95,                     /* $@25  */
  YYSYMBOL_lista_expressoes_ou_vazio = 96, /* lista_expressoes_ou_vazio  */
  YYSYMBOL_lista_expressoes = 97,          /* lista_expressoes  */
  YYSYMBOL_98_26 = 98,                     /* $@26  */
  YYSYMBOL_expressao = 99,                 /* expressao  */
  YYSYMBOL_100_27 = 100,                   /* $@27  */
  YYSYMBOL_relacao_exp_simples_ou_vazio = 101, /* relacao_exp_simples_ou_vazio  */
  YYSYMBOL_relacao = 102,                  /* relacao  */
  YYSYMBOL_expressao_simples = 103,        /* expressao_simples  */
  YYSYMBOL_soma_ou_vazio = 104,            /* soma_ou_vazio  */
  YYSYMBOL_expressao_lista_termo = 105,    /* expressao_lista_termo  */
  YYSYMBOL_lista_termo = 106,              /* lista_termo  */
  YYSYMBOL_107_28 = 107,                   /* $@28  */
  YYSYMBOL_108_29 = 108,                   /* $@29  */
  YYSYMBOL_termo = 109,                    /* termo  */
  YYSYMBOL_lista_fator = 110,              /* lista_fator  */
  YYSYMBOL_fator = 111,                    /* fator  */
  YYSYMBOL_112_30 = 112,                   /* $@30  */
  YYSYMBOL_113_31 = 113,                   /* $@31  */
  YYSYMBOL_atribuicao_procedimento = 114,  /* atribuicao_procedimento  */
  YYSYMBOL_atribuicao_funcao = 115,        /* atribuicao_funcao  */
  YYSYMBOL_atribuicao = 116,               /* atribuicao  */
  YYSYMBOL_variavel = 117,                 /* variavel  */
  YYSYMBOL_numero = 118,                   /* numero  */
  YYSYMBOL_leitura = 119,                  /* leitura  */
  YYSYMBOL_lista_leitura = 120,            /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 121,          /* simbolo_leitura  */
  YYSYMBOL_escrita = 122,                  /* escrita  */
  YYSYMBOL_lista_escrita = 123             /* lista_escrita  */
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
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

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
       0,    45,    45,    45,    66,    66,    69,    73,    82,    89,
      81,    97,   105,   105,   109,   109,   112,   112,   115,   118,
     118,   120,   120,   122,   126,   122,   134,   140,   148,   154,
     166,   180,   165,   202,   212,   211,   232,   231,   242,   244,
     249,   272,   273,   247,   315,   342,   313,   384,   384,   387,
     387,   397,   398,   398,   402,   402,   406,   406,   410,   414,
     415,   419,   423,   423,   426,   429,   430,   431,   432,   433,
     434,   435,   441,   449,   454,   441,   461,   476,   483,   486,
     476,   495,   496,   505,   505,   505,   508,   508,   512,   518,
     524,   527,   530,   533,   536,   539,   545,   549,   552,   552,
     557,   558,   562,   565,   562,   570,   577,   578,   584,   587,
     590,   596,   666,   670,   666,   695,   696,   700,   701,   705,
     705,   709,   730,   758,   771,   775,   776,   780,   801,   805,
     806
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
  "INTEGER", "WHILE", "DO", "IF", "THEN", "ELSE", "MAIOR", "MENOR",
  "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "DIV", "NUMERO", "READ", "WRITE",
  "PROCEDURE", "FUNCTION", "$accept", "programa", "$@1", "parametros_nada",
  "parametros", "tipo", "bloco", "$@2", "$@3", "parte_declara_vars",
  "parte_declara_sub_rotinas", "regra_subrotina", "$@4", "$@5", "var",
  "declara_vars", "declara_var", "$@6", "$@7", "lista_id_var",
  "lista_idents", "comando_while", "$@8", "$@9", "comando_if", "if",
  "$@10", "else", "$@11", "else_multiplo_unico", "declaracao_procedimento",
  "$@12", "$@13", "$@14", "declaracao_funcao", "$@15", "$@16",
  "parametros_formais_vazio", "parametros_formais", "$@17",
  "lista_parametros_formais", "$@18", "secao_parametros_formais", "$@19",
  "var_vazio", "comando_composto", "comandos", "comando", "nunero_nada",
  "nada", "comando_sem_rotulo", "chama_procedimento", "$@20", "$@21",
  "$@22", "chama_funcao", "$@23", "$@24", "$@25",
  "lista_expressoes_ou_vazio", "lista_expressoes", "$@26", "expressao",
  "$@27", "relacao_exp_simples_ou_vazio", "relacao", "expressao_simples",
  "soma_ou_vazio", "expressao_lista_termo", "lista_termo", "$@28", "$@29",
  "termo", "lista_fator", "fator", "$@30", "$@31",
  "atribuicao_procedimento", "atribuicao_funcao", "atribuicao", "variavel",
  "numero", "leitura", "lista_leitura", "simbolo_leitura", "escrita",
  "lista_escrita", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -161,    14,    13,  -161,    15,    38,    62,    67,  -161,  -161,
    -161,    28,    66,  -161,    63,  -161,    70,  -161,  -161,    68,
    -161,    69,  -161,    68,  -161,  -161,  -161,  -161,    54,   -10,
    -161,    71,    65,    72,    73,    79,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,    51,  -161,    83,    84,    85,
    -161,    89,  -161,    20,  -161,     5,  -161,    86,  -161,  -161,
    -161,    89,  -161,    88,  -161,  -161,    51,  -161,  -161,  -161,
    -161,  -161,    93,    94,  -161,  -161,    80,  -161,  -161,  -161,
      95,  -161,  -161,     8,  -161,  -161,  -161,    96,  -161,    65,
    -161,  -161,    37,  -161,  -161,    91,  -161,  -161,  -161,  -161,
    -161,  -161,    97,  -161,  -161,  -161,     6,    98,    99,  -161,
    -161,  -161,    26,     4,    92,   100,  -161,    61,  -161,  -161,
      64,     5,   106,  -161,    66,  -161,    98,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
      37,  -161,    45,    24,  -161,   101,  -161,  -161,     5,  -161,
      91,  -161,  -161,  -161,  -161,  -161,   107,  -161,   108,   106,
    -161,  -161,    62,    66,  -161,   110,     4,  -161,   102,     4,
       4,     4,  -161,   109,    79,  -161,  -161,  -161,  -161,   112,
     111,    55,  -161,  -161,    24,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,    65,     4,  -161,  -161,  -161,  -161,
      24,   115,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,    64,     0,     0,     4,     5,
      29,     0,    23,     6,     0,    23,     0,     8,    11,    20,
      22,     0,    28,    19,     3,    64,    21,    27,     0,     9,
      13,     0,     0,     0,     0,     0,    12,    14,    16,    18,
      26,     7,    24,    40,    44,    64,    10,     0,     0,     0,
      41,    64,   123,     0,    60,    77,    63,     0,    15,    17,
      25,    64,    49,     0,    47,    48,    64,    58,   122,    86,
      30,    86,     0,     0,    69,    68,    64,    67,    61,   120,
       0,    66,   119,    76,    70,    71,    62,     0,    52,     0,
      59,   121,    64,    86,    34,     0,    86,    36,    33,    38,
      78,   118,     0,    65,   117,    42,     0,    64,     0,    97,
      98,    99,    64,     0,     0,     0,   127,     0,   126,   130,
       0,    77,    86,    73,    23,    50,    64,    56,    53,    54,
      57,    45,    95,    92,    94,    93,    90,    91,    89,    87,
      64,    86,    96,   101,   107,   111,   115,    31,    77,   124,
       0,   128,    86,    37,    39,    82,     0,    81,    83,    86,
      43,    51,     0,    23,    88,     0,     0,   100,     0,     0,
       0,     0,   106,     0,     0,    35,   125,   129,    79,     0,
       0,     0,    46,   116,   105,   103,   108,   109,   110,   113,
      32,    80,    86,    74,     0,     0,    86,    85,    75,    55,
     104,     0,   114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,  -161,  -161,   -86,  -120,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,   113,    21,  -161,  -161,  -161,
     -40,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,    75,  -161,  -161,
    -161,  -161,    -3,  -161,  -161,   -34,  -161,    58,  -161,    -5,
    -111,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   -33,
    -151,  -161,   -64,  -161,  -161,  -161,   -15,  -161,  -161,  -161,
    -161,  -161,  -160,  -161,  -112,  -161,  -161,  -161,  -161,    44,
     -53,   -36,  -161,  -161,   -20,  -161,  -161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    42,    16,    25,    35,    17,
      29,    36,    47,    48,    18,    19,    20,    21,    49,    28,
      11,    74,    93,   174,    75,    76,   115,    98,   121,   153,
      37,    50,    61,   124,    38,    51,   163,    63,    64,    88,
     106,   107,   128,   162,   129,    77,    53,    54,    55,    56,
      78,   101,   102,   159,   198,    79,    80,   122,   191,   156,
     157,   179,   158,    92,   139,   140,   112,   113,   142,   167,
     168,   195,   143,   172,   144,   173,   196,   103,    81,    82,
     145,   146,    84,   117,   118,    85,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    46,    83,   108,   160,    91,   184,    94,   141,    57,
     154,   125,   -72,   126,     3,    45,     4,    68,    68,    69,
      30,    70,    69,    71,    39,    33,    34,    66,     5,   114,
      57,    67,   119,    13,    14,   200,    52,   175,    72,    73,
      26,   197,     6,   182,    26,   201,    65,   132,   133,   134,
     135,   136,   137,   169,   170,   171,    65,   186,   187,   188,
      31,    14,    32,   194,   109,   110,   149,   150,    83,   151,
     152,    99,  -102,   166,    12,    10,    22,   165,    15,    24,
      41,   -23,    27,    52,    40,    43,    44,   111,   177,    45,
      58,    59,    60,    62,    86,    83,    89,    95,    96,   100,
      97,   123,   130,   105,   116,  -112,   131,   138,   199,   147,
     127,   -64,   178,   189,   -84,   183,   193,   155,   192,   148,
     202,   130,   181,   161,    90,   164,   180,   104,    23,   185,
     176,     0,     0,     0,     0,   111,    87,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155
};

static const yytype_int16 yycheck[] =
{
       5,    35,    55,    89,   124,    69,   166,    71,     4,    45,
     121,     5,     4,     7,     0,    10,     3,    13,    13,    14,
      25,    16,    14,    18,    29,    35,    36,     7,    13,    93,
      66,    11,    96,     5,     6,   195,    32,   148,    33,    34,
      19,   192,     4,   163,    23,   196,    51,    21,    22,    23,
      24,    25,    26,    29,    30,    31,    61,   169,   170,   171,
       6,     6,     8,     8,    27,    28,     5,     6,   121,     5,
       6,    76,    27,    28,     7,    13,    13,   141,    12,     9,
      15,    13,    13,    32,    13,    13,    13,    92,   152,    10,
       7,     7,     7,     4,     8,   148,     8,     4,     4,     4,
      20,     4,   107,     7,    13,     4,     7,   112,   194,    17,
      12,     5,     5,     4,     6,     5,     5,   122,     6,    19,
       5,   126,   162,   126,    66,   140,   159,    83,    15,    27,
     150,    -1,    -1,    -1,    -1,   140,    61,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,    13,     4,    40,    41,    86,
      13,    57,     7,     5,     6,    12,    43,    46,    51,    52,
      53,    54,    13,    52,     9,    44,    53,    13,    56,    47,
      86,     6,     8,    35,    36,    45,    48,    67,    71,    86,
      13,    15,    42,    13,    13,    10,    82,    49,    50,    55,
      68,    72,    32,    83,    84,    85,    86,   118,     7,     7,
       7,    69,     4,    74,    75,    86,     7,    11,    13,    14,
      16,    18,    33,    34,    58,    61,    62,    82,    87,    92,
      93,   115,   116,   117,   119,   122,     8,    74,    76,     8,
      84,    99,   100,    59,    99,     4,     4,    20,    64,    86,
       4,    88,    89,   114,   116,     7,    77,    78,    42,    27,
      28,    86,   103,   104,    99,    63,    13,   120,   121,    99,
     123,    65,    94,     4,    70,     5,     7,    12,    79,    81,
      86,     7,    21,    22,    23,    24,    25,    26,    86,   101,
     102,     4,   105,   109,   111,   117,   118,    17,    19,     5,
       6,     5,     6,    66,    87,    86,    96,    97,    99,    90,
      43,    79,    80,    73,   103,    99,    28,   106,   107,    29,
      30,    31,   110,   112,    60,    87,   121,    99,     5,    98,
      96,    57,    43,     5,   109,    27,   111,   111,   111,     4,
      82,    95,     6,     5,     8,   108,   113,    97,    91,    42,
     109,    97,     5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    42,    44,    45,
      43,    46,    47,    47,    49,    48,    50,    48,    48,    51,
      51,    52,    52,    54,    55,    53,    56,    56,    57,    57,
      59,    60,    58,    61,    63,    62,    65,    64,    64,    66,
      68,    69,    70,    67,    72,    73,    71,    74,    74,    76,
      75,    77,    78,    77,    80,    79,    81,    81,    82,    83,
      83,    84,    85,    85,    86,    87,    87,    87,    87,    87,
      87,    87,    89,    90,    91,    88,    88,    93,    94,    95,
      92,    96,    96,    97,    98,    97,   100,    99,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   104,   104,   104,
     105,   105,   107,   108,   106,   106,   109,   109,   110,   110,
     110,   111,   112,   113,   111,   111,   111,   114,   114,   115,
     115,   116,   117,   118,   119,   120,   120,   121,   122,   123,
     123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     1,     0,     0,
       5,     1,     2,     1,     0,     3,     0,     3,     1,     2,
       1,     2,     1,     0,     0,     6,     3,     1,     3,     1,
       0,     0,     6,     2,     0,     5,     0,     3,     1,     1,
       0,     0,     0,     8,     0,     0,     9,     1,     1,     0,
       4,     3,     0,     2,     0,     5,     1,     1,     3,     3,
       1,     2,     2,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     0,     0,     0,     6,     0,     0,     0,     0,
       6,     1,     1,     1,     0,     4,     0,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     1,     0,     0,     4,     2,     2,     1,     2,     2,
       2,     1,     0,     0,     6,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     4,     3,     1,     1,     4,     3,
       1
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
#line 45 "compilador.y"
             {
             	geraCodigo (NULL, "INPP");
             	char * RotInicioSubrotina = cria_rotulo(rotulo_print);
				rotulo_print++;
				push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
				procedimento_atual = cria_variavel_procedure("main", RotInicioSubrotina, 0, 0);
				push(&tabelaSimbolos, procedimento_atual);
				push_pilha_no(&tabelaNode, procedimento_atual);
			}
#line 1373 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_nada PONTO_E_VIRGULA bloco PONTO  */
#line 55 "compilador.y"
                        {
				procedimento_atual = pop_pilha_no(&tabelaNode);
            	pop(&tabelaSimbolos, procedimento_atual->numero_variaveis + procedimento_atual->numero_procedimentos);
            	char dmem[1000];

            	sprintf(dmem, "DMEM %d", procedimento_atual->numero_variaveis);
               	geraCodigo(NULL, dmem);
               	geraCodigo (NULL, "PARA");
            }
#line 1387 "compilador.tab.c"
    break;

  case 7: /* tipo: INTEGER  */
#line 73 "compilador.y"
                {
		seta_tipos(&tabelaSimbolos, integer, novas_variaveis);
	}
#line 1395 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 82 "compilador.y"
                                {
					// faz o desvio pro rotulo
					char rotsaida[100];
      				sprintf(rotsaida, "DSVS %s", pega_rotulo(&pilha_rotulos,0));
					geraCodigo(NULL, rotsaida);
				}
#line 1406 "compilador.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 89 "compilador.y"
                          {
				char rotsaida[100];
     			sprintf(rotsaida, "%s", pega_rotulo(&pilha_rotulos,0));
     			geraCodigo(rotsaida, "NADA");
				}
#line 1416 "compilador.tab.c"
    break;

  case 11: /* parte_declara_vars: var  */
#line 97 "compilador.y"
                         {
    	char amem[100];
		sprintf(amem, "AMEM %d", numero_variaveis);
		atualiza_num_variaveis(&tabelaSimbolos, numero_variaveis, nivel_lexico);
		geraCodigo(NULL, amem);
}
#line 1427 "compilador.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 109 "compilador.y"
                                {
		atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);
	}
#line 1435 "compilador.tab.c"
    break;

  case 16: /* $@5: %empty  */
#line 112 "compilador.y"
                            {
		atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);
	}
#line 1443 "compilador.tab.c"
    break;

  case 23: /* $@6: %empty  */
#line 122 "compilador.y"
              {
              novas_variaveis = 0;
}
#line 1451 "compilador.tab.c"
    break;

  case 24: /* $@7: %empty  */
#line 126 "compilador.y"
              {
                numero_variaveis += novas_variaveis;

              }
#line 1460 "compilador.tab.c"
    break;

  case 26: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 135 "compilador.y"
              { /* insere �ltima vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
#line 1470 "compilador.tab.c"
    break;

  case 27: /* lista_id_var: IDENT  */
#line 140 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
#line 1481 "compilador.tab.c"
    break;

  case 28: /* lista_idents: lista_idents VIRGULA IDENT  */
#line 148 "compilador.y"
                                        {
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1492 "compilador.tab.c"
    break;

  case 29: /* lista_idents: IDENT  */
#line 155 "compilador.y"
        {
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1503 "compilador.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 166 "compilador.y"
        {
		// cria os rotulos de entrada e saida
		char *inicio_while = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *fim_while = cria_rotulo(rotulo_print);
		rotulo_print++;
		// insere os rotulos na pilha de rotulos
		push_pilha_rotulo(&pilha_rotulos, inicio_while);
		push_pilha_rotulo(&pilha_rotulos, fim_while);

		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
	}
#line 1521 "compilador.tab.c"
    break;

  case 31: /* $@9: %empty  */
#line 180 "compilador.y"
        {
		char dsvf[100];
		// verificar desvio
		sprintf(dsvf, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
#line 1532 "compilador.tab.c"
    break;

  case 32: /* comando_while: WHILE $@8 expressao DO $@9 comando_composto  */
#line 187 "compilador.y"
        {
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
#line 1548 "compilador.tab.c"
    break;

  case 33: /* comando_if: if else  */
#line 203 "compilador.y"
        {
		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
#line 1558 "compilador.tab.c"
    break;

  case 34: /* $@10: %empty  */
#line 212 "compilador.y"
        {
		inicia_else(); //testar se tem else
		// Gera rotulos de entrada e saida do if
		char *RotIfInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *RotIfFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		push_pilha_rotulo(&pilha_rotulos, RotIfInicio);
		push_pilha_rotulo(&pilha_rotulos, RotIfFim);

		// imprime rotulo de entrada do if
		char rot[100];
		sprintf(rot, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, rot);
	}
#line 1579 "compilador.tab.c"
    break;

  case 36: /* $@11: %empty  */
#line 232 "compilador.y"
        {
		seta_else();//seta que ta no else

		char rot[100];
		sprintf(rot, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, rot);

		// imprime rotulo de entrada no fim do if
		geraCodigo(pega_rotulo(&pilha_rotulos, 1), "NADA");
	}
#line 1594 "compilador.tab.c"
    break;

  case 40: /* $@12: %empty  */
#line 249 "compilador.y"
        {

		// gera rotulos de entrada e saida
		char *RotInicioSubrotina = cria_rotulo(rotulo_print);
		rotulo_print++;

		rotulo_fim_subr = cria_rotulo(rotulo_print);
		rotulo_print++;
		push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
		push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
		nivel_lexico++;

		// imprime rotulo de entrada da subrotina
		char rotentrada[100];
		sprintf(rotentrada, "ENPR %d", nivel_lexico);
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);

		novaEntrada = cria_variavel_procedure(token, RotInicioSubrotina, nivel_lexico, 0);
		push(&tabelaSimbolos, novaEntrada);
		// Insere na pilha de nos
		push_pilha_no(&tabelaNode,  novaEntrada);
		procedimento_atual = novaEntrada;
	}
#line 1622 "compilador.tab.c"
    break;

  case 41: /* $@13: %empty  */
#line 272 "compilador.y"
        { novos_param = 0; }
#line 1628 "compilador.tab.c"
    break;

  case 42: /* $@14: %empty  */
#line 273 "compilador.y"
        {
		// Zera para ser utilizado na subrotina e salva para ser recuperado
		aux_var = numero_variaveis;
		numero_variaveis = 0;
		deslocamento = 0;
	}
#line 1639 "compilador.tab.c"
    break;

  case 43: /* declaracao_procedimento: PROCEDURE IDENT $@12 $@13 parametros_formais_vazio PONTO_E_VIRGULA $@14 bloco  */
#line 280 "compilador.y"
        {

		procedimento_atual = (type_info_tabela_simbolos*) pop_pilha_no(&tabelaNode);
		pop(&tabelaSimbolos, procedimento_atual->numero_procedimentos); // tira procedure de simbolos

		// DMEM nas variaveis do procedimento
		pop(&tabelaSimbolos, procedimento_atual->numero_variaveis);
		char dmem[100];
		sprintf(dmem, "DMEM %d", procedimento_atual->numero_variaveis);
		geraCodigo(NULL, dmem);
		pop(&tabelaSimbolos, procedimento_atual->numero_parametros); // tira parametros de simbolos


		destino = pega_topo(&tabelaSimbolos);
		if(destino == NULL) {
			printf("Tabela de simbolos: procedimento nao encontrado!\n");
			exit(1);
		}
		char command[100];
		sprintf(command, "RTPR %d, %d", nivel_lexico, procedimento_atual->numero_parametros);
		geraCodigo(NULL, command);

		novos_param = 0;
		nivel_lexico--;

		destino = NULL;
		numero_variaveis = aux_var;
		pop_pilha_rotulo(&pilha_rotulos, 2);

	}
#line 1674 "compilador.tab.c"
    break;

  case 44: /* $@15: %empty  */
#line 315 "compilador.y"
  {


	char *RotInicioSubrotina = cria_rotulo(rotulo_print);
	rotulo_print++;

	rotulo_fim_subr = cria_rotulo(rotulo_print);
	rotulo_print++;
	push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
	push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
	nivel_lexico++;


	char rotentrada[100];
	sprintf(rotentrada, "ENPR %d", nivel_lexico);
	geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);


	if (funcao_atual != NULL) {
		strcpy(funcao_atual, token);
		novaEntrada = cria_variavel_funcao(token, RotInicioSubrotina, nivel_lexico, 0, integer);
		push(&tabelaSimbolos, novaEntrada);
		push_pilha_no(&tabelaNode,  novaEntrada);
		procedimento_atual = novaEntrada;
	}
novos_param = 0;
  }
#line 1706 "compilador.tab.c"
    break;

  case 45: /* $@16: %empty  */
#line 342 "compilador.y"
  {

    aux_var = numero_variaveis;
    numero_variaveis = 0;
    deslocamento = 0;
  }
#line 1717 "compilador.tab.c"
    break;

  case 46: /* declaracao_funcao: FUNCTION IDENT $@15 parametros_formais_vazio DOIS_PONTOS tipo PONTO_E_VIRGULA $@16 bloco  */
#line 349 "compilador.y"
  {
	procedimento_atual = (type_info_tabela_simbolos*) pop_pilha_no(&tabelaNode);
	pop(&tabelaSimbolos, procedimento_atual->numero_procedimentos);


	pop(&tabelaSimbolos, procedimento_atual->numero_variaveis);
	char dmem[100];
	sprintf(dmem, "DMEM %d", procedimento_atual->numero_variaveis);
	geraCodigo(NULL, dmem);

	pop(&tabelaSimbolos, procedimento_atual->numero_parametros);


	destino = pega_topo(&tabelaSimbolos);
	if (destino == NULL) {
		printf("Tabela de simbolos: rocedimento não encontrado!\n");
		exit(1);
	}

	char command[100];
	sprintf(command, "RTPR %d, %d", nivel_lexico, numero_parametros);
	geraCodigo(NULL, command);

	novos_param = 0;
	nivel_lexico--;

	destino = NULL; // Libera variável destino
	numero_variaveis = aux_var;    // Restabelece número de variáveis no nível léxico



    pop_pilha_rotulo(&pilha_rotulos, 2);
  }
#line 1755 "compilador.tab.c"
    break;

  case 49: /* $@17: %empty  */
#line 387 "compilador.y"
                { numero_parametros = 0; }
#line 1761 "compilador.tab.c"
    break;

  case 50: /* parametros_formais: ABRE_PARENTESES $@17 lista_parametros_formais FECHA_PARENTESES  */
#line 390 "compilador.y"
        {
		atualiza_parametros(pega_posicao(&tabelaSimbolos, numero_parametros),
								&tabelaSimbolos, numero_parametros);
	}
#line 1770 "compilador.tab.c"
    break;

  case 52: /* $@18: %empty  */
#line 398 "compilador.y"
          { novos_param++; }
#line 1776 "compilador.tab.c"
    break;

  case 54: /* $@19: %empty  */
#line 402 "compilador.y"
            { novas_variaveis = 0; }
#line 1782 "compilador.tab.c"
    break;

  case 56: /* var_vazio: VAR  */
#line 406 "compilador.y"
            {por_ref = 1; }
#line 1788 "compilador.tab.c"
    break;

  case 57: /* var_vazio: nada  */
#line 406 "compilador.y"
                                   {por_ref = 0; }
#line 1794 "compilador.tab.c"
    break;

  case 72: /* $@20: %empty  */
#line 441 "compilador.y"
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimento_atual = destino;
		sprintf(rotuloPrint, "CHPR %s, %d", destino->rotulo, nivel_lexico);
		entra_procedimento = 1;

   	}
#line 1807 "compilador.tab.c"
    break;

  case 73: /* $@21: %empty  */
#line 449 "compilador.y"
                        {
		 novos_param = 0;
	}
#line 1815 "compilador.tab.c"
    break;

  case 74: /* $@22: %empty  */
#line 454 "compilador.y"
        {
		entra_procedimento = 0;
		geraCodigo(NULL, rotuloPrint);

	}
#line 1825 "compilador.tab.c"
    break;

  case 75: /* chama_procedimento: $@20 ABRE_PARENTESES $@21 lista_expressoes_ou_vazio FECHA_PARENTESES $@22  */
#line 459 "compilador.y"
        { destino = NULL; }
#line 1831 "compilador.tab.c"
    break;

  case 76: /* chama_procedimento: %empty  */
#line 461 "compilador.y"
        {

		entra_procedimento = 1;
		procedimento_atual = destino;
		// Imprime rotulo de entrada da subrotina
		char rotuloPrint[100];
		sprintf(rotuloPrint, "CHPR %s, %d", destino->rotulo, nivel_lexico);
		geraCodigo(NULL, rotuloPrint);
		destino = NULL;
		entra_procedimento = 0;
	}
#line 1847 "compilador.tab.c"
    break;

  case 77: /* $@23: %empty  */
#line 476 "compilador.y"
    {
    entra_procedimento = 1;
    // Imprime rotulo de entrada da subrotina
    procedimento_atual = destino;
    sprintf(rotuloPrint, "CHPR %s, %d", destino->rotulo, nivel_lexico);
    geraCodigo(NULL, "AMEM 1"); // making up space for the function return
    }
#line 1859 "compilador.tab.c"
    break;

  case 78: /* $@24: %empty  */
#line 483 "compilador.y"
                  { ; novos_param = 0; }
#line 1865 "compilador.tab.c"
    break;

  case 79: /* $@25: %empty  */
#line 486 "compilador.y"
  {
    entra_procedimento = 0;
    geraCodigo(NULL, rotuloPrint);

  }
#line 1875 "compilador.tab.c"
    break;

  case 80: /* chama_funcao: $@23 ABRE_PARENTESES $@24 lista_expressoes_ou_vazio FECHA_PARENTESES $@25  */
#line 491 "compilador.y"
  { destino = NULL; }
#line 1881 "compilador.tab.c"
    break;

  case 84: /* $@26: %empty  */
#line 505 "compilador.y"
                                        {num_params_chamada++;}
#line 1887 "compilador.tab.c"
    break;

  case 86: /* $@27: %empty  */
#line 508 "compilador.y"
        { novos_param++; }
#line 1893 "compilador.tab.c"
    break;

  case 89: /* relacao_exp_simples_ou_vazio: nada  */
#line 519 "compilador.y"
{
   printf("entrou nesse nada\n");
}
#line 1901 "compilador.tab.c"
    break;

  case 90: /* relacao: IGUAL  */
#line 524 "compilador.y"
              {
		strcpy(comparacao, "CMIG");
	}
#line 1909 "compilador.tab.c"
    break;

  case 91: /* relacao: DIFERENTE  */
#line 527 "compilador.y"
                    {
		strcpy(comparacao, "CMDG");
	}
#line 1917 "compilador.tab.c"
    break;

  case 92: /* relacao: MENOR  */
#line 530 "compilador.y"
                {
		strcpy(comparacao, "CMME");
	}
#line 1925 "compilador.tab.c"
    break;

  case 93: /* relacao: MENOR_IGUAL  */
#line 533 "compilador.y"
                      {
		strcpy(comparacao, "CMEG");
	}
#line 1933 "compilador.tab.c"
    break;

  case 94: /* relacao: MAIOR_IGUAL  */
#line 536 "compilador.y"
                      {
		strcpy(comparacao, "CMAG");
	}
#line 1941 "compilador.tab.c"
    break;

  case 95: /* relacao: MAIOR  */
#line 539 "compilador.y"
                {
		strcpy(comparacao, "CMMA");
	}
#line 1949 "compilador.tab.c"
    break;

  case 97: /* soma_ou_vazio: SOMA  */
#line 549 "compilador.y"
             {
		printf("soma ou vazio\n");
	}
#line 1957 "compilador.tab.c"
    break;

  case 102: /* $@28: %empty  */
#line 562 "compilador.y"
        {
		printf("Lista termo\n");
	}
#line 1965 "compilador.tab.c"
    break;

  case 103: /* $@29: %empty  */
#line 565 "compilador.y"
             {
		printf("soma\n");
	}
#line 1973 "compilador.tab.c"
    break;

  case 104: /* lista_termo: $@28 SOMA $@29 termo  */
#line 567 "compilador.y"
                {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 1981 "compilador.tab.c"
    break;

  case 105: /* lista_termo: SUBTRACAO termo  */
#line 570 "compilador.y"
                          {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");
		}
#line 1990 "compilador.tab.c"
    break;

  case 107: /* termo: fator  */
#line 578 "compilador.y"
                {
		printf("saiu de fator\n");
	}
#line 1998 "compilador.tab.c"
    break;

  case 108: /* lista_fator: MULTIPLICACAO fator  */
#line 584 "compilador.y"
                            {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 2006 "compilador.tab.c"
    break;

  case 109: /* lista_fator: DIVISAO fator  */
#line 587 "compilador.y"
                        {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 2014 "compilador.tab.c"
    break;

  case 110: /* lista_fator: DIV fator  */
#line 590 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 2022 "compilador.tab.c"
    break;

  case 111: /* fator: variavel  */
#line 597 "compilador.y"
        {
		if(carregada != NULL) {
			printf("variavel carregada: %s\n", carregada->rotulo);
			if(carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
			else {
				char comando[100];
				int cur_params, passagem;

				if (entra_procedimento == 2) {
					cur_params = procedimento_atual->numero_parametros - num_params_chamada + 1;
				} else {
					cur_params = novos_param;
				}

				if (entra_procedimento == 0) {
					passagem = carregada->passagem;
				} else {
					passagem = procedimento_atual->params[procedimento_atual->numero_parametros - cur_params].passagem;
				}

				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && carregada->passagem == REFERENCIA)) {
					sprintf(comando, "CRVL %d, %d", carregada->nivel_lexico, carregada->deslocamento);
				} else if (entra_procedimento >= 1 && passagem == REFERENCIA) {
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
				int passagem;

				if (entra_procedimento == 0) {
					passagem = destino->passagem;
				} else {
					passagem = procedimento_atual->params[procedimento_atual->numero_parametros - novos_param].passagem;
				}

				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && destino->passagem == REFERENCIA)) {
					sprintf(comando, "CRVL %d, %d", destino->nivel_lexico, destino->deslocamento);
				} else if (entra_procedimento == 1 && passagem == REFERENCIA) {
					sprintf(comando, "CREN %d, %d", destino->nivel_lexico, destino->deslocamento);
				} else {
					sprintf(comando, "CRVI %d, %d", destino->nivel_lexico, destino->deslocamento);
				}

				destino = NULL;
				geraCodigo(NULL, comando);

			}
		}
	}
#line 2096 "compilador.tab.c"
    break;

  case 112: /* $@30: %empty  */
#line 666 "compilador.y"
                   {
		printf("saiu de variave 2l\n");
	}
#line 2104 "compilador.tab.c"
    break;

  case 113: /* $@31: %empty  */
#line 670 "compilador.y"
        {
		entra_procedimento = 2;
		num_params_chamada = 0;

		if(carregada != NULL) {
			if(carregada->categoria == funcao) {
				procedimento_atual = carregada;
			}
		}
		else {
			if(destino->categoria == funcao) {
				procedimento_atual = destino;
			}
		}
		geraCodigo(NULL, "AMEM 1");

	}
#line 2126 "compilador.tab.c"
    break;

  case 114: /* fator: variavel $@30 ABRE_PARENTESES $@31 lista_expressoes FECHA_PARENTESES  */
#line 688 "compilador.y"
        {
		entra_procedimento = 0;
		num_params_chamada = 0;
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimento_atual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
#line 2138 "compilador.tab.c"
    break;

  case 121: /* atribuicao: ATRIBUICAO expressao  */
#line 710 "compilador.y"
        {
      printf("entrou em comando_atribuicao\n");

		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		if (destino->passagem == VALOR)

		{
			printf("entrou em VALOR\n");
				sprintf(varLexDisp, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);}
		else
		{
			printf("entrou em REFERENCIA\n");
				sprintf(varLexDisp, "ARMI %d, %d", destino->nivel_lexico, destino->deslocamento);}
		geraCodigo(NULL, varLexDisp);
		destino = NULL;
	}
#line 2160 "compilador.tab.c"
    break;

  case 122: /* variavel: IDENT  */
#line 730 "compilador.y"
              {
		if(destino == NULL) {
         printf("Variavel nao declarada: %s\n", token);

			destino = busca_pilha_simbolos(&tabelaSimbolos, token);
         printf("destino->torulo: %s\n", destino->rotulo) ;

			if(destino == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			printf("foi no tipo 1\n");
			push_pilha_tipo(&tabelaTipo, destino->tipo);
		}
		else {
			printf("variavel carregada desse aqui: %s\n", token);
			carregada = busca_pilha_simbolos(&tabelaSimbolos, token);
			if(carregada == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}

			push_pilha_tipo(&tabelaTipo, carregada->tipo);
		}
   	}
#line 2190 "compilador.tab.c"
    break;

  case 123: /* numero: NUMERO  */
#line 759 "compilador.y"
        {

		push_pilha_tipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
		printf("numero\n");
	}
#line 2203 "compilador.tab.c"
    break;

  case 127: /* simbolo_leitura: IDENT  */
#line 781 "compilador.y"
        {
		// Codigo leitura
		geraCodigo(NULL, "LEIT");

		// Procura por variavel na tabela de simbolos
		destino = busca_pilha_simbolos(&tabelaSimbolos, token);
		if(destino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

		// Armazena na variavel destino
    char varLexDisp[1000];
		sprintf(varLexDisp, "ARMZ %d, %d ", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, varLexDisp);
		destino = NULL;
	}
#line 2225 "compilador.tab.c"
    break;

  case 129: /* lista_escrita: lista_escrita VIRGULA expressao  */
#line 805 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 2231 "compilador.tab.c"
    break;

  case 130: /* lista_escrita: expressao  */
#line 806 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 2237 "compilador.tab.c"
    break;


#line 2241 "compilador.tab.c"

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

#line 809 "compilador.y"


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
   cria_pilha(&tabelaSimbolos);
   cria_pilha_tipo(&tabelaTipo);
   cria_pilha_rotulo(&pilha_rotulos);
   cria_pilha_no(&tabelaNode);

   funcao_atual = malloc(100);
   por_ref = 0;
   yyin=fp;
   yyparse();

   return 0;
}
