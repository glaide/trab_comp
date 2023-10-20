
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

#include "tabelaSimbolos.h"

int num_vars, novasVariaveis, deslocamento, nivel_lexico;

//ADICIONEI AS VARIAVEIS TABALA_SIMBOLOS PARA CHAMARMOS ELA, E A NOVA_ENTRADA COPIEI PQ FAZ SENTIDO,
//PQ PRECISAMOS SALVAR A NOVA VARIAVEL EM ALGUM LUGAR QUANDO MONTAMOS O NO.
TypeTabelaSimbolosPilha tabela_Simbolos;
type_infos_tabela_simbolos *nova_Entrada;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token NUMERO INTEGER

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
              }


              comando_composto
              ;



/* regra 8 */
parte_declara_vars:  var
;


var         : { } VAR declara_vars
            | declara_var
;

declara_vars: declara_vars declara_var
            | declara_var
;

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

              }
              PONTO_E_VIRGULA
;

tipo        : INTEGER {}
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
comando: numero_ou_nada;


numero_ou_nada: numero DOIS_PONTOS | nada;

numero: NUMERO {
	// add na tabela de tipos
	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}


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

   return 0;
}
