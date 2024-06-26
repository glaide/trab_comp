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
#include "tabelaSimbolos.h"
#include "pilha.h"

int por_ref, numero_variaveis, numero_parametros, aux_var, novas_variaveis, novos_param, nivel_lexico, deslocamento,numero_parametros_chamada,entra_procedimento;
int rotulo_print = 0;
int subrt = 0;
int declarado = 0;
char comparacao[100],chama_proc[100], *funcao_atual, *rotulo_fim_subr;
pilha_simbolos tabelaSimbolos;
type_info_tabela_simbolos *novaEntrada, *variavelDestino, *variavel_carregada, *procedimentoAtual, *verifica_forward;
tipo_pilha tabelaTipo;
pilha_rotulo pilha_rotulos;
pilha_no pilhano;


#line 93 "compilador.tab.c"

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
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_THEN = 21,                      /* THEN  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_MAIOR = 23,                     /* MAIOR  */
  YYSYMBOL_MENOR = 24,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 25,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 26,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 27,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 28,                 /* DIFERENTE  */
  YYSYMBOL_SOMA = 29,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 30,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 31,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 32,                   /* DIVISAO  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_NUMERO = 34,                    /* NUMERO  */
  YYSYMBOL_READ = 35,                      /* READ  */
  YYSYMBOL_WRITE = 36,                     /* WRITE  */
  YYSYMBOL_PROCEDURE = 37,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 38,                  /* FUNCTION  */
  YYSYMBOL_T_FORWARD = 39,                 /* T_FORWARD  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_programa = 41,                  /* programa  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_parametros_ou_vazio = 43,       /* parametros_ou_vazio  */
  YYSYMBOL_parametros = 44,                /* parametros  */
  YYSYMBOL_tipo = 45,                      /* tipo  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_parte_declara_vars = 49,        /* parte_declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 50, /* parte_declara_sub_rotinas  */
  YYSYMBOL_opcoes_sub_rotinas = 51,        /* opcoes_sub_rotinas  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_var = 54,                       /* var  */
  YYSYMBOL_declara_vars = 55,              /* declara_vars  */
  YYSYMBOL_declara_var = 56,               /* declara_var  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_lista_id_var = 59,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 60,              /* lista_idents  */
  YYSYMBOL_declaracao_procedimento = 61,   /* declaracao_procedimento  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_declaracao_funcao = 66,         /* declaracao_funcao  */
  YYSYMBOL_67_12 = 67,                     /* $@12  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_69_14 = 69,                     /* $@14  */
  YYSYMBOL_parametros_formais_vazio = 70,  /* parametros_formais_vazio  */
  YYSYMBOL_parametros_formais = 71,        /* parametros_formais  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_lista_parametros_formais = 73,  /* lista_parametros_formais  */
  YYSYMBOL_74_16 = 74,                     /* $@16  */
  YYSYMBOL_secao_parametros_formais = 75,  /* secao_parametros_formais  */
  YYSYMBOL_76_17 = 76,                     /* $@17  */
  YYSYMBOL_var_vazio = 77,                 /* var_vazio  */
  YYSYMBOL_comando_composto = 78,          /* comando_composto  */
  YYSYMBOL_comandos = 79,                  /* comandos  */
  YYSYMBOL_comando = 80,                   /* comando  */
  YYSYMBOL_numero_ou_vazio = 81,           /* numero_ou_vazio  */
  YYSYMBOL_comando_vazio = 82,             /* comando_vazio  */
  YYSYMBOL_comando_sem_rotulo = 83,        /* comando_sem_rotulo  */
  YYSYMBOL_desvio = 84,                    /* desvio  */
  YYSYMBOL_comando_condicional = 85,       /* comando_condicional  */
  YYSYMBOL_if_then = 86,                   /* if_then  */
  YYSYMBOL_87_18 = 87,                     /* $@18  */
  YYSYMBOL_cond_else = 88,                 /* cond_else  */
  YYSYMBOL_89_19 = 89,                     /* $@19  */
  YYSYMBOL_else_multiplo_unico = 90,       /* else_multiplo_unico  */
  YYSYMBOL_chama_procedimento = 91,        /* chama_procedimento  */
  YYSYMBOL_92_20 = 92,                     /* $@20  */
  YYSYMBOL_93_21 = 93,                     /* $@21  */
  YYSYMBOL_94_22 = 94,                     /* $@22  */
  YYSYMBOL_95_23 = 95,                     /* $@23  */
  YYSYMBOL_chama_funcao = 96,              /* chama_funcao  */
  YYSYMBOL_97_24 = 97,                     /* $@24  */
  YYSYMBOL_98_25 = 98,                     /* $@25  */
  YYSYMBOL_99_26 = 99,                     /* $@26  */
  YYSYMBOL_lista_expressoes_ou_vazio = 100, /* lista_expressoes_ou_vazio  */
  YYSYMBOL_comando_repetitivo = 101,       /* comando_repetitivo  */
  YYSYMBOL_102_27 = 102,                   /* $@27  */
  YYSYMBOL_103_28 = 103,                   /* $@28  */
  YYSYMBOL_lista_expressoes = 104,         /* lista_expressoes  */
  YYSYMBOL_105_29 = 105,                   /* $@29  */
  YYSYMBOL_expressao = 106,                /* expressao  */
  YYSYMBOL_107_30 = 107,                   /* $@30  */
  YYSYMBOL_relacao_exp_simples_ou_vazio = 108, /* relacao_exp_simples_ou_vazio  */
  YYSYMBOL_relacao = 109,                  /* relacao  */
  YYSYMBOL_expressao_simples = 110,        /* expressao_simples  */
  YYSYMBOL_soma_ou_vazio = 111,            /* soma_ou_vazio  */
  YYSYMBOL_expressao_lista_termo = 112,    /* expressao_lista_termo  */
  YYSYMBOL_lista_termo = 113,              /* lista_termo  */
  YYSYMBOL_termo = 114,                    /* termo  */
  YYSYMBOL_lista_fator = 115,              /* lista_fator  */
  YYSYMBOL_fator = 116,                    /* fator  */
  YYSYMBOL_117_31 = 117,                   /* $@31  */
  YYSYMBOL_atribuicao_procedimento = 118,  /* atribuicao_procedimento  */
  YYSYMBOL_atribuicao_funcao = 119,        /* atribuicao_funcao  */
  YYSYMBOL_atribuicao = 120,               /* atribuicao  */
  YYSYMBOL_variavel = 121,                 /* variavel  */
  YYSYMBOL_numero = 122,                   /* numero  */
  YYSYMBOL_leitura = 123,                  /* leitura  */
  YYSYMBOL_lista_leitura = 124,            /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 125,          /* simbolo_leitura  */
  YYSYMBOL_escrita = 126,                  /* escrita  */
  YYSYMBOL_lista_escrita = 127,            /* lista_escrita  */
  YYSYMBOL_regra_forward_ou_bloco = 128,   /* regra_forward_ou_bloco  */
  YYSYMBOL_129_32 = 129                    /* $@32  */
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
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    41,    62,    62,    64,    68,    76,    81,
      76,    89,    97,    98,   102,   102,   105,   105,   108,   112,
     113,   116,   117,   120,   124,   120,   131,   136,   144,   150,
     160,   162,   197,   198,   160,   240,   242,   282,   240,   321,
     321,   325,   325,   335,   336,   336,   340,   340,   344,   344,
     348,   352,   353,   357,   361,   362,   365,   368,   369,   370,
     371,   372,   373,   374,   375,   379,   383,   393,   392,   414,
     413,   425,   429,   435,   443,   446,   435,   453,   453,   468,
     475,   478,   468,   487,   488,   494,   507,   493,   529,   529,
     529,   532,   532,   536,   542,   546,   547,   548,   549,   550,
     551,   555,   559,   559,   559,   563,   564,   568,   571,   574,
     580,   581,   585,   588,   591,   594,   600,   648,   647,   672,
     673,   677,   678,   682,   682,   686,   700,   721,   732,   736,
     737,   741,   762,   766,   767,   770,   778,   778
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
  "INTEGER", "OR", "AND", "WHILE", "DO", "IF", "THEN", "ELSE", "MAIOR",
  "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "SOMA",
  "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "DIV", "NUMERO", "READ",
  "WRITE", "PROCEDURE", "FUNCTION", "T_FORWARD", "$accept", "programa",
  "$@1", "parametros_ou_vazio", "parametros", "tipo", "bloco", "$@2",
  "$@3", "parte_declara_vars", "parte_declara_sub_rotinas",
  "opcoes_sub_rotinas", "$@4", "$@5", "var", "declara_vars", "declara_var",
  "$@6", "$@7", "lista_id_var", "lista_idents", "declaracao_procedimento",
  "$@8", "$@9", "$@10", "$@11", "declaracao_funcao", "$@12", "$@13",
  "$@14", "parametros_formais_vazio", "parametros_formais", "$@15",
  "lista_parametros_formais", "$@16", "secao_parametros_formais", "$@17",
  "var_vazio", "comando_composto", "comandos", "comando",
  "numero_ou_vazio", "comando_vazio", "comando_sem_rotulo", "desvio",
  "comando_condicional", "if_then", "$@18", "cond_else", "$@19",
  "else_multiplo_unico", "chama_procedimento", "$@20", "$@21", "$@22",
  "$@23", "chama_funcao", "$@24", "$@25", "$@26",
  "lista_expressoes_ou_vazio", "comando_repetitivo", "$@27", "$@28",
  "lista_expressoes", "$@29", "expressao", "$@30",
  "relacao_exp_simples_ou_vazio", "relacao", "expressao_simples",
  "soma_ou_vazio", "expressao_lista_termo", "lista_termo", "termo",
  "lista_fator", "fator", "$@31", "atribuicao_procedimento",
  "atribuicao_funcao", "atribuicao", "variavel", "numero", "leitura",
  "lista_leitura", "simbolo_leitura", "escrita", "lista_escrita",
  "regra_forward_ou_bloco", "$@32", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -166,    10,    30,  -166,    46,    58,    65,    61,  -166,  -166,
    -166,    59,    67,  -166,    69,  -166,    72,  -166,  -166,    70,
    -166,    75,  -166,    70,  -166,  -166,  -166,  -166,    20,    29,
    -166,    76,    78,  -166,  -166,    74,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,    77,    81,    51,  -166,    84,    88,    89,
    -166,  -166,  -166,     5,  -166,     1,  -166,    90,  -166,  -166,
    -166,  -166,    93,    51,  -166,  -166,  -166,  -166,  -166,    95,
      96,  -166,  -166,  -166,  -166,    79,  -166,    99,  -166,  -166,
    -166,     9,  -166,  -166,  -166,    93,  -166,    97,  -166,  -166,
    -166,  -166,    42,  -166,  -166,    91,  -166,  -166,  -166,  -166,
    -166,  -166,   102,  -166,  -166,  -166,   101,  -166,    78,  -166,
    -166,  -166,    21,     4,    92,    94,  -166,    68,  -166,  -166,
      71,     1,   104,  -166,  -166,    53,    98,   105,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,    42,  -166,    13,     8,
    -166,   109,  -166,  -166,     1,  -166,    91,  -166,  -166,  -166,
    -166,  -166,   111,  -166,   108,   104,    80,  -166,    98,  -166,
    -166,  -166,  -166,  -166,  -166,   113,     4,     4,     4,  -166,
       4,     4,     4,     4,  -166,  -166,    74,  -166,  -166,  -166,
    -166,   114,   117,  -166,  -166,    67,  -166,    65,    80,  -166,
       8,     8,     8,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,    55,  -166,   118,  -166,  -166,    78,  -166,
    -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,    56,     0,     0,     4,     5,
      29,     0,    23,     6,     0,    23,     0,     8,    11,    20,
      22,     0,    28,    19,     3,    56,    21,    27,     0,     9,
      13,     0,     0,    30,    35,     0,    12,    14,    16,    18,
      26,     7,    24,     0,     0,    56,    10,     0,     0,     0,
      31,    36,   127,     0,    52,    65,    55,     0,    15,    17,
      25,    32,    56,    56,    50,   126,    91,    85,    91,     0,
       0,    60,    53,    59,    61,    56,   124,     0,    62,    58,
     123,    77,    63,    64,    54,    56,    41,     0,    39,    40,
      51,   125,    56,    91,    67,     0,    91,    69,    71,    66,
      80,   122,     0,    78,    57,   121,     0,    44,     0,   102,
     103,   104,    56,     0,     0,     0,   131,     0,   130,   134,
       0,    65,    91,    74,    33,     0,    56,     0,   100,    97,
      99,    98,    95,    96,    94,    92,    56,    91,   101,   106,
     111,   116,   119,    86,    65,   128,     0,   132,    91,    72,
      70,    84,     0,    83,    88,    91,   136,    42,    56,    48,
      45,    46,    49,    37,    93,     0,     0,     0,     0,   105,
       0,     0,     0,     0,   110,   117,     0,    68,   129,   133,
      81,     0,     0,   135,    34,    23,    43,     0,   136,   120,
     109,   107,   108,   115,   112,   113,   114,    91,    87,    82,
      91,    75,   137,     0,    38,     0,    90,    76,     0,   118,
      47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,  -166,  -106,   -61,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,   110,    -1,  -166,  -166,  -166,
     -60,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
      41,  -166,  -166,  -166,  -166,   -30,  -166,  -166,   -34,  -166,
      66,  -166,    -5,  -114,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
     -25,  -166,  -166,  -166,  -165,  -166,   -62,  -166,  -166,  -166,
      -4,  -166,  -166,  -166,  -112,  -166,  -120,  -166,  -166,  -166,
      52,   -52,   -36,  -166,  -166,   -12,  -166,  -166,   -53,  -166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    42,    16,    25,    35,    17,
      29,    36,    47,    48,    18,    19,    20,    21,    49,    28,
      11,    37,    43,    61,    85,   156,    38,    44,    62,   188,
      87,    88,   107,   125,   126,   160,   187,   161,    71,    53,
      54,    55,    56,    72,    73,    74,    75,   115,    99,   121,
     150,   101,   102,   155,   207,   103,    76,    77,   122,   199,
     152,    78,    93,   176,   153,   181,   154,    92,   135,   136,
     112,   113,   138,   169,   139,   174,   140,   197,   104,    79,
      80,   141,   142,    82,   117,   118,    83,   120,   184,   185
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    46,   127,    81,    91,   -79,    94,   149,   137,    57,
       3,    45,    63,   -73,    65,    66,    64,    65,    26,    67,
      30,    68,    26,    66,    39,   170,    31,    57,    32,   166,
     177,   114,   205,     4,   119,   206,    69,    70,    52,   171,
     172,   173,   167,   168,   128,   129,   130,   131,   132,   133,
     193,   194,   195,   196,   190,   191,   192,    89,   157,     5,
     158,    14,     6,   208,    13,    14,    33,    34,    12,    81,
      98,   109,   110,   145,   146,   165,   147,   148,    10,    15,
      89,    24,    22,   -23,    45,    52,   179,   111,    27,    40,
      50,    58,    81,    41,    51,    59,    60,    86,    84,    95,
      96,    97,   210,   100,   116,   108,   123,   134,   124,   -56,
     159,   143,   163,   175,   -89,   144,   180,   151,   189,   183,
     200,   162,   201,   209,   202,    23,   106,   203,   186,    90,
     182,   111,   164,   105,   178,   204,     0,     0,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,     0,
     151,     0,     0,   162
};

static const yytype_int16 yycheck[] =
{
       5,    35,   108,    55,    66,     4,    68,   121,     4,    45,
       0,    10,     7,     4,    13,    14,    11,    13,    19,    18,
      25,    20,    23,    14,    29,    17,     6,    63,     8,    16,
     144,    93,   197,     3,    96,   200,    35,    36,    34,    31,
      32,    33,    29,    30,    23,    24,    25,    26,    27,    28,
     170,   171,   172,   173,   166,   167,   168,    62,     5,    13,
       7,     6,     4,     8,     5,     6,    37,    38,     7,   121,
      75,    29,    30,     5,     6,   137,     5,     6,    13,    12,
      85,     9,    13,    13,    10,    34,   148,    92,    13,    13,
      13,     7,   144,    15,    13,     7,     7,     4,     8,     4,
       4,    22,   208,     4,    13,     8,     4,   112,     7,     5,
      12,    19,     7,     4,     6,    21,     5,   122,     5,    39,
       6,   126,     5,     5,   185,    15,    85,   187,   158,    63,
     155,   136,   136,    81,   146,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,    -1,   158
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,    13,     4,    43,    44,    82,
      13,    60,     7,     5,     6,    12,    46,    49,    54,    55,
      56,    57,    13,    55,     9,    47,    56,    13,    59,    50,
      82,     6,     8,    37,    38,    48,    51,    61,    66,    82,
      13,    15,    45,    62,    67,    10,    78,    52,    53,    58,
      13,    13,    34,    79,    80,    81,    82,   122,     7,     7,
       7,    63,    68,     7,    11,    13,    14,    18,    20,    35,
      36,    78,    83,    84,    85,    86,    96,    97,   101,   119,
     120,   121,   123,   126,     8,    64,     4,    70,    71,    82,
      80,   106,   107,   102,   106,     4,     4,    22,    82,    88,
       4,    91,    92,    95,   118,   120,    70,    72,     8,    29,
      30,    82,   110,   111,   106,    87,    13,   124,   125,   106,
     127,    89,    98,     4,     7,    73,    74,    45,    23,    24,
      25,    26,    27,    28,    82,   108,   109,     4,   112,   114,
     116,   121,   122,    19,    21,     5,     6,     5,     6,    83,
      90,    82,   100,   104,   106,    93,    65,     5,     7,    12,
      75,    77,    82,     7,   110,   106,    16,    29,    30,   113,
      17,    31,    32,    33,   115,     4,   103,    83,   125,   106,
       5,   105,   100,    39,   128,   129,    75,    76,    69,     5,
     114,   114,   114,   116,   116,   116,   116,   117,    78,    99,
       6,     5,    46,    60,   128,   104,   104,    94,     8,     5,
      45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    44,    45,    47,    48,
      46,    49,    50,    50,    52,    51,    53,    51,    51,    54,
      54,    55,    55,    57,    58,    56,    59,    59,    60,    60,
      62,    63,    64,    65,    61,    67,    68,    69,    66,    70,
      70,    72,    71,    73,    74,    73,    76,    75,    77,    77,
      78,    79,    79,    80,    81,    81,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    85,    87,    86,    89,
      88,    88,    90,    92,    93,    94,    91,    95,    91,    97,
      98,    99,    96,   100,   100,   102,   103,   101,   104,   105,
     104,   107,   106,   108,   108,   109,   109,   109,   109,   109,
     109,   110,   111,   111,   111,   112,   112,   113,   113,   113,
     114,   114,   115,   115,   115,   115,   116,   117,   116,   116,
     116,   118,   118,   119,   119,   120,   121,   122,   123,   124,
     124,   125,   126,   127,   127,   128,   129,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     1,     0,     0,
       5,     1,     2,     1,     0,     3,     0,     3,     1,     2,
       1,     2,     1,     0,     0,     6,     3,     1,     3,     1,
       0,     0,     0,     0,     9,     0,     0,     0,    10,     1,
       1,     0,     4,     3,     0,     2,     0,     5,     1,     1,
       3,     3,     1,     2,     2,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     5,     0,
       3,     1,     1,     0,     0,     0,     6,     0,     1,     0,
       0,     0,     6,     1,     1,     0,     0,     6,     1,     0,
       4,     0,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     0,     5,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     4,     3,
       1,     1,     4,     3,     1,     1,     0,     2
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
#line 41 "compilador.y"
             {
             	geraCodigo (NULL, "INPP");
            	char * RotInicioSubrotina = cria_rotulo(rotulo_print);
				rotulo_print++;
				push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
				procedimentoAtual = cria_variavel_procedure("main", RotInicioSubrotina, 0, 0);
				push(&tabelaSimbolos, procedimentoAtual);
				push_pilha_no(&pilhano, procedimentoAtual);
			}
#line 1380 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_ou_vazio PONTO_E_VIRGULA bloco PONTO  */
#line 51 "compilador.y"
                        {
				procedimentoAtual = pop_pilha_no(&pilhano);
            	pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis + procedimentoAtual->numero_procedimentos);
            	char dmem[1000];

            	sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
            	geraCodigo(NULL, dmem);
            	geraCodigo (NULL, "PARA");
            }
#line 1394 "compilador.tab.c"
    break;

  case 7: /* tipo: INTEGER  */
#line 68 "compilador.y"
                {
		seta_tipos(&tabelaSimbolos, integer, novas_variaveis);
	}
#line 1402 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 76 "compilador.y"
                           {
			char rotsaida[100];
			sprintf(rotsaida, "DSVS %s", pega_rotulo(&pilha_rotulos,0));
			geraCodigo(NULL, rotsaida);
		}
#line 1412 "compilador.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 81 "compilador.y"
                                          {
			char rotsaida[100];
     		sprintf(rotsaida, "%s", pega_rotulo(&pilha_rotulos,0));
     		geraCodigo(rotsaida, "NADA");
		}
#line 1422 "compilador.tab.c"
    break;

  case 11: /* parte_declara_vars: var  */
#line 89 "compilador.y"
                         {
    	char amem[100];
		sprintf(amem, "AMEM %d", numero_variaveis);
		atualiza_num_variaveis(&tabelaSimbolos, numero_variaveis, nivel_lexico);
		geraCodigo(NULL, amem);
}
#line 1433 "compilador.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 102 "compilador.y"
                                {
		atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);
	}
#line 1441 "compilador.tab.c"
    break;

  case 16: /* $@5: %empty  */
#line 105 "compilador.y"
                            {
		atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);
	}
#line 1449 "compilador.tab.c"
    break;

  case 23: /* $@6: %empty  */
#line 120 "compilador.y"
              {
        		novas_variaveis = 0;
			}
#line 1457 "compilador.tab.c"
    break;

  case 24: /* $@7: %empty  */
#line 124 "compilador.y"
                     {
                numero_variaveis += novas_variaveis;
            }
#line 1465 "compilador.tab.c"
    break;

  case 26: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 131 "compilador.y"
                                         { /* insere �ltima vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
#line 1475 "compilador.tab.c"
    break;

  case 27: /* lista_id_var: IDENT  */
#line 136 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
#line 1486 "compilador.tab.c"
    break;

  case 28: /* lista_idents: lista_idents VIRGULA IDENT  */
#line 144 "compilador.y"
                                        {
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1497 "compilador.tab.c"
    break;

  case 29: /* lista_idents: IDENT  */
#line 151 "compilador.y"
        {
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1508 "compilador.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 160 "compilador.y"
                  { subrt = 1; }
#line 1514 "compilador.tab.c"
    break;

  case 31: /* $@9: %empty  */
#line 162 "compilador.y"
        {
		verifica_forward = busca_pilha_simbolos(&tabelaSimbolos, token);
		if (verifica_forward==NULL){
			// segue a vida normal
			declarado = 0;
			// Gera rotulos de entrada e saida
			char *RotInicioSubrotina = cria_rotulo(rotulo_print);
			rotulo_print++;

			rotulo_fim_subr = cria_rotulo(rotulo_print);
			rotulo_print++;
			push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
			push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
			nivel_lexico++;

			// Imprime rotulo de entrada da subrotina
			char rotentrada[100];
			sprintf(rotentrada, "ENPR %d", nivel_lexico);
			geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);

			novaEntrada = cria_variavel_procedure(token, RotInicioSubrotina, nivel_lexico, 0);
			push(&tabelaSimbolos, novaEntrada);
			push_pilha_no(&pilhano,  novaEntrada);
			procedimentoAtual = novaEntrada;
		}
		else if(verifica_forward->declarada){
			char print[100];
			sprintf(print,"procedimento '%s' ja foi declarado!\n",token);
			exit(1);
		}
		else {
			declarado=1;
			procedimentoAtual = verifica_forward; //testar para ver se esta certo
		}
	}
#line 1554 "compilador.tab.c"
    break;

  case 32: /* $@10: %empty  */
#line 197 "compilador.y"
        { novos_param = 0; }
#line 1560 "compilador.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 198 "compilador.y"
        {
		// Zera para ser utilizado na subrotina
		// Mas salva VALOR para ser recuperado
		aux_var = numero_variaveis;
		numero_variaveis = 0;
		deslocamento = 0;
	}
#line 1572 "compilador.tab.c"
    break;

  case 34: /* declaracao_procedimento: PROCEDURE $@8 IDENT $@9 $@10 parametros_formais_vazio PONTO_E_VIRGULA $@11 regra_forward_ou_bloco  */
#line 206 "compilador.y"
        {
		procedimentoAtual = (type_info_tabela_simbolos*) pop_pilha_no(&pilhano);
		pop(&tabelaSimbolos, procedimentoAtual->numero_procedimentos); // Remove procedimentos da tabela de simbolos

		// DMEM nas variaveis do procedimento
		pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis);
		char dmem[100];
		sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
		geraCodigo(NULL, dmem);
		pop(&tabelaSimbolos, procedimentoAtual->numero_parametros); // Remove parametros da tabela de simbolos

		// Pega procedimento para printar infos da saida dele
		variavelDestino = pega_topo(&tabelaSimbolos);
		if(variavelDestino == NULL) {
			printf("Procedimento nao encontrado na tabela de simbolos.\n");
			exit(1);
		}
		char command[100];
		sprintf(command, "RTPR %d, %d", nivel_lexico, procedimentoAtual->numero_parametros);
		geraCodigo(NULL, command);

		novos_param = 0;
		nivel_lexico--;

		variavelDestino = NULL; // Libera variavel destino
		numero_variaveis = aux_var;    // Restabelece numero de variaveis no nivel lexico
		subrt = 0;
		pop_pilha_rotulo(&pilha_rotulos, 2);


	}
#line 1608 "compilador.tab.c"
    break;

  case 35: /* $@12: %empty  */
#line 240 "compilador.y"
          { subrt = 1; }
#line 1614 "compilador.tab.c"
    break;

  case 36: /* $@13: %empty  */
#line 242 "compilador.y"
  {
	// indica que ainda nao foi declarado pelo forward
	declarado = 0;
    // Gera rotulos de entrada e saida

	verifica_forward = busca_pilha_simbolos(&tabelaSimbolos, token);
	if(verifica_forward==NULL){
		// segue a vida normal
		char *RotInicioSubrotina = cria_rotulo(rotulo_print);
		rotulo_print++;

		rotulo_fim_subr = cria_rotulo(rotulo_print);
		rotulo_print++;
		push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
		push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
		nivel_lexico++;

		// Imprime rotulo de entrada da subrotina
		char rotentrada[100];
		sprintf(rotentrada, "ENPR %d", nivel_lexico);
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);

		sprintf(funcao_atual, "%s", token);
		novaEntrada = cria_variavel_funcao(token, RotInicioSubrotina, nivel_lexico, 0, integer);
		push(&tabelaSimbolos, novaEntrada);
		push_pilha_no(&pilhano,  novaEntrada);
		procedimentoAtual = novaEntrada;
		novos_param = 0;
	}
	else if(verifica_forward->declarada){
		char print[100];
		sprintf(print,"funcao '%s' ja foi declarada!\n",token);
		exit(1);
	}
	else {
		declarado=1;
		procedimentoAtual = verifica_forward; //testar para ver se esta certo
	}
  }
#line 1658 "compilador.tab.c"
    break;

  case 37: /* $@14: %empty  */
#line 282 "compilador.y"
  {
    // Zera para ser utilizado na subrotina
    // Mas salva VALOR para ser recuperado
    aux_var = numero_variaveis;
    numero_variaveis = 0;
    deslocamento = 0;
  }
#line 1670 "compilador.tab.c"
    break;

  case 38: /* declaracao_funcao: FUNCTION $@12 IDENT $@13 parametros_formais_vazio DOIS_PONTOS tipo PONTO_E_VIRGULA $@14 regra_forward_ou_bloco  */
#line 290 "compilador.y"
  {
    procedimentoAtual = (type_info_tabela_simbolos*)pop_pilha_no(&pilhano);
    pop(&tabelaSimbolos, procedimentoAtual->numero_procedimentos); // Remove procedimentos da tabela de simbolos

    // DMEM nas variaveis do procedimento
    pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis);
    char dmem[100];
    sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
    geraCodigo(NULL, dmem);
    pop(&tabelaSimbolos, procedimentoAtual->numero_parametros); // Remove parametros da tabela de simbolos

    // Pega procedimento para printar infos da saida dele
    variavelDestino = pega_topo(&tabelaSimbolos);
    if(variavelDestino == NULL) {
      printf("Procedimento nao encontrado na tabela de simbolos.\n");
      exit(1);
    }
    char command[100];
    sprintf(command, "RTPR %d, %d", nivel_lexico, numero_parametros);
    geraCodigo(NULL, command);

    novos_param = 0;
    nivel_lexico--;

    variavelDestino = NULL; // Libera variavel destino
    numero_variaveis = aux_var;    // Restabelece numero de variaveis no nivel lexico
    subrt = 0;
    pop_pilha_rotulo(&pilha_rotulos, 2);
  }
#line 1704 "compilador.tab.c"
    break;

  case 41: /* $@15: %empty  */
#line 325 "compilador.y"
                { numero_parametros = 0; }
#line 1710 "compilador.tab.c"
    break;

  case 42: /* parametros_formais: ABRE_PARENTESES $@15 lista_parametros_formais FECHA_PARENTESES  */
#line 328 "compilador.y"
        {
		atualiza_parametros(pega_posicao(&tabelaSimbolos, numero_parametros),
								&tabelaSimbolos, numero_parametros);
	}
#line 1719 "compilador.tab.c"
    break;

  case 44: /* $@16: %empty  */
#line 336 "compilador.y"
          { novos_param++; }
#line 1725 "compilador.tab.c"
    break;

  case 46: /* $@17: %empty  */
#line 340 "compilador.y"
            { novas_variaveis = 0; }
#line 1731 "compilador.tab.c"
    break;

  case 48: /* var_vazio: VAR  */
#line 344 "compilador.y"
            {por_ref = 1; }
#line 1737 "compilador.tab.c"
    break;

  case 49: /* var_vazio: comando_vazio  */
#line 344 "compilador.y"
                                            {por_ref = 0; }
#line 1743 "compilador.tab.c"
    break;

  case 65: /* desvio: %empty  */
#line 379 "compilador.y"
   { }
#line 1749 "compilador.tab.c"
    break;

  case 66: /* comando_condicional: if_then cond_else  */
#line 384 "compilador.y"
        {
		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
#line 1759 "compilador.tab.c"
    break;

  case 67: /* $@18: %empty  */
#line 393 "compilador.y"
        {
		inicia_else(); //inicializa se necessario, incrementa o iterador
		// Gera rotulos de entrada e saida do IF
		char *RotIfInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *RotIfFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		push_pilha_rotulo(&pilha_rotulos, RotIfInicio);
		push_pilha_rotulo(&pilha_rotulos, RotIfFim);
		//push_pilha_rotulo(&pilha_rotulos, RotIfInicio);

		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, rot);
	}
#line 1781 "compilador.tab.c"
    break;

  case 69: /* $@19: %empty  */
#line 414 "compilador.y"
        {
		seta_else(); //marca pro iterador que a iésima cláusula tem else
		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, rot);

		// Imprime rotulo de entrada no fim do if
		geraCodigo(pega_rotulo(&pilha_rotulos, 1), "NADA");
	}
#line 1796 "compilador.tab.c"
    break;

  case 73: /* $@20: %empty  */
#line 435 "compilador.y"
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimentoAtual = variavelDestino;
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		entra_procedimento = 1;
		//geraCodigo(NULL, chama_proc);
   	}
#line 1809 "compilador.tab.c"
    break;

  case 74: /* $@21: %empty  */
#line 443 "compilador.y"
                        {   novos_param = 0; }
#line 1815 "compilador.tab.c"
    break;

  case 75: /* $@22: %empty  */
#line 446 "compilador.y"
        {
		entra_procedimento = 0;
		geraCodigo(NULL, chama_proc);

	}
#line 1825 "compilador.tab.c"
    break;

  case 76: /* chama_procedimento: $@20 ABRE_PARENTESES $@21 lista_expressoes_ou_vazio FECHA_PARENTESES $@22  */
#line 451 "compilador.y"
        { variavelDestino = NULL; }
#line 1831 "compilador.tab.c"
    break;

  case 77: /* $@23: %empty  */
#line 453 "compilador.y"
        {
		entra_procedimento = 1;
		procedimentoAtual = variavelDestino;
		// Imprime rotulo de entrada da subrotina
		char chama_proc[100];
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
		variavelDestino = NULL;
	}
#line 1845 "compilador.tab.c"
    break;

  case 78: /* chama_procedimento: $@23  */
#line 462 "compilador.y"
        {
		entra_procedimento = 0;
	}
#line 1853 "compilador.tab.c"
    break;

  case 79: /* $@24: %empty  */
#line 468 "compilador.y"
    {
    entra_procedimento = 1;
    // Imprime rotulo de entrada da subrotina
    procedimentoAtual = variavelDestino;
    sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
    geraCodigo(NULL, "AMEM 1"); // making up space for the function return
    }
#line 1865 "compilador.tab.c"
    break;

  case 80: /* $@25: %empty  */
#line 475 "compilador.y"
                  {   novos_param = 0; }
#line 1871 "compilador.tab.c"
    break;

  case 81: /* $@26: %empty  */
#line 478 "compilador.y"
  {
    entra_procedimento = 0;
    geraCodigo(NULL, chama_proc);

  }
#line 1881 "compilador.tab.c"
    break;

  case 82: /* chama_funcao: $@24 ABRE_PARENTESES $@25 lista_expressoes_ou_vazio FECHA_PARENTESES $@26  */
#line 483 "compilador.y"
  { variavelDestino = NULL; }
#line 1887 "compilador.tab.c"
    break;

  case 85: /* $@27: %empty  */
#line 494 "compilador.y"
        {
		char *RotWhileInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *RotWhileFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		push_pilha_rotulo(&pilha_rotulos, RotWhileInicio);
		push_pilha_rotulo(&pilha_rotulos, RotWhileFim);

		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
	}
#line 1904 "compilador.tab.c"
    break;

  case 86: /* $@28: %empty  */
#line 507 "compilador.y"
        {
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
#line 1914 "compilador.tab.c"
    break;

  case 87: /* comando_repetitivo: WHILE $@27 expressao DO $@28 comando_composto  */
#line 513 "compilador.y"
        {
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
#line 1930 "compilador.tab.c"
    break;

  case 89: /* $@29: %empty  */
#line 529 "compilador.y"
                                        {numero_parametros_chamada++;}
#line 1936 "compilador.tab.c"
    break;

  case 91: /* $@30: %empty  */
#line 532 "compilador.y"
        { novos_param++; }
#line 1942 "compilador.tab.c"
    break;

  case 93: /* relacao_exp_simples_ou_vazio: relacao expressao_simples  */
#line 537 "compilador.y"
        {

		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	}
#line 1952 "compilador.tab.c"
    break;

  case 95: /* relacao: IGUAL  */
#line 546 "compilador.y"
              { strcpy(comparacao, "CMIG"); }
#line 1958 "compilador.tab.c"
    break;

  case 96: /* relacao: DIFERENTE  */
#line 547 "compilador.y"
                    { strcpy(comparacao, "CMDG"); }
#line 1964 "compilador.tab.c"
    break;

  case 97: /* relacao: MENOR  */
#line 548 "compilador.y"
                { strcpy(comparacao, "CMME"); }
#line 1970 "compilador.tab.c"
    break;

  case 98: /* relacao: MENOR_IGUAL  */
#line 549 "compilador.y"
                      { strcpy(comparacao, "CMEG"); }
#line 1976 "compilador.tab.c"
    break;

  case 99: /* relacao: MAIOR_IGUAL  */
#line 550 "compilador.y"
                      { strcpy(comparacao, "CMAG"); }
#line 1982 "compilador.tab.c"
    break;

  case 100: /* relacao: MAIOR  */
#line 551 "compilador.y"
                { strcpy(comparacao, "CMMA"); }
#line 1988 "compilador.tab.c"
    break;

  case 107: /* lista_termo: SOMA termo  */
#line 568 "compilador.y"
                   {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 1996 "compilador.tab.c"
    break;

  case 108: /* lista_termo: SUBTRACAO termo  */
#line 571 "compilador.y"
                          {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
#line 2004 "compilador.tab.c"
    break;

  case 109: /* lista_termo: OR termo  */
#line 574 "compilador.y"
                   {
		verifica_tipo(&tabelaTipo, "or");
		geraCodigo(NULL, "DISJ");}
#line 2012 "compilador.tab.c"
    break;

  case 112: /* lista_fator: MULTIPLICACAO fator  */
#line 585 "compilador.y"
                            {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 2020 "compilador.tab.c"
    break;

  case 113: /* lista_fator: DIVISAO fator  */
#line 588 "compilador.y"
                        {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 2028 "compilador.tab.c"
    break;

  case 114: /* lista_fator: DIV fator  */
#line 591 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 2036 "compilador.tab.c"
    break;

  case 115: /* lista_fator: AND fator  */
#line 594 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "and");
		geraCodigo(NULL, "CONJ"); }
#line 2044 "compilador.tab.c"
    break;

  case 116: /* fator: variavel  */
#line 601 "compilador.y"
        {
		if(variavel_carregada != NULL) {
			if(variavel_carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavel_carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
			else {
				char comando[100];
				int param_atual = entra_procedimento == 2 ?
												(procedimentoAtual->numero_parametros - numero_parametros_chamada + 1) : novos_param;
				int passagem = entra_procedimento == 0 ? variavel_carregada->passagem :
																				 procedimentoAtual->params[procedimentoAtual->numero_parametros - param_atual].passagem;

				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && variavel_carregada->passagem == REFERENCIA))
					sprintf(comando, "CRVL %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				else if (entra_procedimento >= 1 && passagem == REFERENCIA)
          sprintf(comando, "CREN %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				variavel_carregada = NULL;
				geraCodigo(NULL, comando);
			}
		}
		else {
			if(variavelDestino->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				int passagem = entra_procedimento == 0 ? variavelDestino->passagem :
									procedimentoAtual->params[procedimentoAtual->numero_parametros - novos_param].passagem;
				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && variavelDestino->passagem == REFERENCIA))
					sprintf(comando, "CRVL %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else if (entra_procedimento == 1 && passagem == REFERENCIA)
					sprintf(comando, "CREN %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				variavelDestino = NULL;
				geraCodigo(NULL, comando);
			}
		}
	}
#line 2095 "compilador.tab.c"
    break;

  case 117: /* $@31: %empty  */
#line 648 "compilador.y"
        {
		entra_procedimento = 2;
		numero_parametros_chamada = 0;
		if(variavel_carregada != NULL) {
			if(variavel_carregada->categoria == funcao) {
				procedimentoAtual = variavel_carregada;
			}
		}
		else {
			if(variavelDestino->categoria == funcao) {
				procedimentoAtual = variavelDestino;
			}
		}
		geraCodigo(NULL, "AMEM 1");

	}
#line 2116 "compilador.tab.c"
    break;

  case 118: /* fator: variavel ABRE_PARENTESES $@31 lista_expressoes FECHA_PARENTESES  */
#line 665 "compilador.y"
        {
		entra_procedimento = 0;
		numero_parametros_chamada = 0;
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
#line 2128 "compilador.tab.c"
    break;

  case 125: /* atribuicao: ATRIBUICAO expressao  */
#line 687 "compilador.y"
        {
		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		if (variavelDestino->passagem == VALOR)
			sprintf(varLexDisp, "ARMZ %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		else
			sprintf(varLexDisp, "ARMI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp);
		variavelDestino = NULL;
	}
#line 2143 "compilador.tab.c"
    break;

  case 126: /* variavel: IDENT  */
#line 700 "compilador.y"
              {
		if(variavelDestino == NULL) {
			variavelDestino = busca_pilha_simbolos(&tabelaSimbolos, token);
			if(variavelDestino == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			push_pilha_tipo(&tabelaTipo, variavelDestino->tipo);
		}
		else {
			variavel_carregada = busca_pilha_simbolos(&tabelaSimbolos, token);
			if(variavel_carregada == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			push_pilha_tipo(&tabelaTipo, variavel_carregada->tipo);
		}
   	}
#line 2166 "compilador.tab.c"
    break;

  case 127: /* numero: NUMERO  */
#line 722 "compilador.y"
        {
		push_pilha_tipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
	}
#line 2177 "compilador.tab.c"
    break;

  case 131: /* simbolo_leitura: IDENT  */
#line 742 "compilador.y"
        {
		// Codigo leitura
		geraCodigo(NULL, "LEIT");

		// Procura por variavel na tabela de simbolos
		variavelDestino = busca_pilha_simbolos(&tabelaSimbolos, token);
		if(variavelDestino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

		// Armazena na variavel destino
    char varLexDisp[1000];
		sprintf(varLexDisp, "ARMZ %d, %d ", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp);
		variavelDestino = NULL;
	}
#line 2199 "compilador.tab.c"
    break;

  case 133: /* lista_escrita: lista_escrita VIRGULA expressao  */
#line 766 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 2205 "compilador.tab.c"
    break;

  case 134: /* lista_escrita: expressao  */
#line 767 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 2211 "compilador.tab.c"
    break;

  case 135: /* regra_forward_ou_bloco: T_FORWARD  */
#line 770 "compilador.y"
                                  {
	// verifica ja foi declarado
	char print[100];
	if (declarado) {
			sprintf(print,"'%s' ja foi declarado!\n",procedimentoAtual->identificador);
			yyerror(print); //necessario?
			exit(1);
	}}
#line 2224 "compilador.tab.c"
    break;

  case 136: /* $@32: %empty  */
#line 778 "compilador.y"
          {
		// indicar que ja foi implementado
		procedimentoAtual->declarada = 1;
		char print[100];
		sprintf(print, procedimentoAtual->rotulo, nivel_lexico);
		geraCodigo(procedimentoAtual->rotulo, print);

	}
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

#line 787 "compilador.y"


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
   cria_pilha_no(&pilhano);

   funcao_atual = malloc(100);
   por_ref = 0;
   yyin=fp;
   yyparse();

   return 0;
}
