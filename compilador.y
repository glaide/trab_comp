
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "rotulos.h"
#include "tabelaSimbolos.h"

int num_vars, novasVariaveis, deslocamento, nivel_lexico;
int num_Rotulos;
TypeTabelaSimbolosPilha tabela_Simbolos;
type_infos_tabela_simbolos *nova_Entrada;
char *rotuloAtual;
pilha_rotulo pilhaRotulo;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token NUMERO INTEGER PROCEDURE WHILE DO
%token IGUAL DIFERENTE MENOR MENOR_IGUAL MAIOR_IGUAL MAIOR
%token SOMA SUBTRACAO

%%
/* regra 1 */
programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT parametros_ou_nada PONTO_E_VIRGULA
             bloco PONTO {
         imprime_tabela_simbolos(&tabela_Simbolos);
             geraCodigo (NULL, "PARA");
             }
;

parametros_ou_nada: parametros
                  | nada;

parametros: ABRE_PARENTESES lista_idents FECHA_PARENTESES;

nada: ;
/* regra 2 */
bloco       :
              parte_declara_vars
              {
               // momento em que é feita a parte do desvio
               // cria um novo rotulo
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo_atual(&pilhaRotulo);
               sprintf(rotuloPrint, "DSVS %s", rotuloAtual);
               geraCodigo(NULL, rotuloPrint);
              }
              parte_declara_sub_rotinas
              {
               // momento que é feito a volta do desvio
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo_atual(&pilhaRotulo);
               sprintf(rotuloPrint, "%s", rotuloAtual);
               geraCodigo(rotuloPrint, "NADA");

              }


              comando_composto
              ;



/* regra 8 */
parte_declara_vars:  var //TODO: implementar

;


var         : { } VAR declara_vars
            | declara_var
;

declara_vars: declara_vars declara_var
            | declara_var
;

/* regra 11 */
/* pode ter mais de uma subrotila */
parte_declara_sub_rotinas: parte_declara_sub_rotinas regra_sub_rotina | regra_sub_rotina ;

regra_sub_rotina:  declara_procedimento  | nada; //TODO: implementar

/* regra 12 */
declara_procedimento: PROCEDURE IDENT {
   // faz alguma coisa aqui, pensar
} parametros_formais_ou_nada PONTO_E_VIRGULA bloco;

parametros_formais_ou_nada: parametros_formais | nada;

/* regra 14 */
parametros_formais: ABRE_PARENTESES parametros_formais PONTO_E_VIRGULA secao_parametros_formais | secao_parametros_formais;

/* regra 15 */
/* <seção de parâmetros formais> =::
[var] <lista de identificadores>: <identificador>
*/
secao_parametros_formais: var_ou_nada lista_idents DOIS_PONTOS tipo;

var_ou_nada: VAR | nada;

/* complementar */
/* TODO: implementar */
/* declara_funcao: nada; */


/* regra 9 */
declara_var : {
   novasVariaveis= 0;
}
              lista_id_var DOIS_PONTOS
              tipo
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;
               printf("num de variaveis %d\n", num_vars);
               //para usar amem tem que saber qual deslocamento
               //TODO: implementar
              }
              PONTO_E_VIRGULA
;

tipo        : INTEGER {} //TODO: implementar
/* TODO: colocar o tipo que será salvo na tabela de simbolos */
;

/* regra 10 conta quantas variaveis tem */
lista_id_var: lista_id_var VIRGULA IDENT
              { /* insere ultima vars na tabela de s�mbolos */
                novasVariaveis++;
                deslocamento++;
               //  add na tabela de simbolos

               nova_Entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_Simbolos, nova_Entrada);

               //  no futuro setar o valor de deslocamento tb
                }
            | IDENT { /* insere vars na tabela de s�mbolos */
              novasVariaveis++;
                deslocamento++;

               nova_Entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_Simbolos, nova_Entrada);

               //  no futuro setar o valor de deslocamento tb
               }
;

lista_idents: lista_idents VIRGULA IDENT
//aqui entram os parametros formais
            | IDENT
;

/* regra 16 */
comando_composto: T_BEGIN comandos T_END
comandos:
	comandos PONTO_E_VIRGULA comando
	| comando
;

/* regra 17 */
comando: numero_ou_nada; //TODO: implementar

/* regra 32 */
numero_ou_nada: numero DOIS_PONTOS | nada;

/* regra 18 */
comando_sem_rotulo: comando_atribuicao
                  /* | comando_chama_procedimento */
                  | comando_composto
                  /* | comando_if */
                  | comando_while
                  | nada;

/* regra 19 */
comando_atribuicao:

numero: NUMERO {
	//TODO: add na tabela de tipos
	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}


/* regra 23 */
comando_while: WHILE {
   //Cria rotulos do inicio e fim do While e adiciona eles na pilha de rotulos
      char *ROTwhile_ini = cria_rotulo(num_Rotulos);
      num_Rotulos++;
      char *ROTwhile_fim = cria_rotulo(num_Rotulos);
      num_Rotulos++;

      push_tabela_rotulos(pilhaRotulo, ROTwhile_ini);
      push_tabela_rotulos(pilhaRotulo, ROTwhile_fim);

      geraCodigo(getRotulo(&pilhaRotulo, 2), "NADA");
   } expressao {}
   DO{
      char dsvf[100];
		sprintf(dsvf, "DSVF %s", getRotulo(&pilhaRotulo, 1));
		geraCodigo(NULL, dsvf)
   }

/* regra 25 */
expressao: expressao_simples relacao_expressao_simples;


relacao_expressao_simples: relacao expressao_simples | nada;

/* regra 26 */
relacao:
	IGUAL {
      // TODO: implementar
    }
	| DIFERENTE {  }
	| MENOR {  }
	| MENOR_IGUAL {  }
	| MAIOR_IGUAL {  }
	| MAIOR {  }
;

/* regra 27 */
expressao_simples: mais_ou_menos termo expressao_mais_menos_termo;

mais_ou_menos: SOMA| SUBTRACAO ;

/* regra 28 */
/* <fator> {(*|div|and) <fator> } */
termo: nada; //TODO: implementar

expressao_mais_menos_termo: nada; //TODO: implementarrt5;p4 c

%%

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
   cria_pilha_rotulo(&pilhaRotulo);

   return 0;
}
