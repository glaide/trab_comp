
// Testar se funciona corretamente o empilhamento de par�metros
// passagemados por VALOR ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabelaSimbolos.h"
#include "pilha.h"

int por_ref, numero_variaveis, numero_parametros, aux_var, novas_variaveis, novos_param, nivel_lexico, deslocamento,numero_parametros_chamada;
unsigned int temElse, it_temElse;
int entra_procedimento;
char chama_proc[100];
char *rotulo_fim_subr;
int rotulo_print = 0;
int subrt = 0;
char comparacao[100], *funcao_atual;
pilha_simbolos tabelaSimbolos;
type_info_tabela_simbolos *novaEntrada, *variavelDestino, *variavel_carregada, *procedimentoAtual;
tipo_pilha tabelaTipo;
pilha_rotulo pilha_rotulos;
pilha_no pilhano;




%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token INTEGER
%token WHILE DO IF THEN ELSE
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO DIV
%token NUMERO READ WRITE
%token OR AND NOT
%token PROCEDURE FUNCTION


%%

programa    :{
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(rotulo_print);
						 rotulo_print++;
						 push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
						 procedimentoAtual = cria_variavel_procedure("main", RotInicioSubrotina, 0, 0);
						 push(&tabelaSimbolos, procedimentoAtual);
						 push_pilha_no(&pilhano, procedimentoAtual);
						}
             PROGRAM IDENT
			 			 parametros_ou_vazio PONTO_E_VIRGULA
             bloco PONTO {
							 procedimentoAtual = pop_pilha_no(&pilhano);
               pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis + procedimentoAtual->numero_procedimentos);
               char dmem[1000];

               sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
;

parametros_ou_vazio:
	parametros
	| comando_vazio
;

parametros:
	ABRE_PARENTESES lista_idents FECHA_PARENTESES
;

tipo:
	INTEGER { seta_tipos(&tabelaSimbolos, integer, novas_variaveis); }
;



bloco       :
        parte_declara_vars
				{
					char rotsaida[100];
      		sprintf(rotsaida, "DSVS %s", pega_rotulo(&pilha_rotulos,0));
					geraCodigo(NULL, rotsaida);
				}
			  parte_declara_sub_rotinas
			  {
				char rotsaida[100];
     		sprintf(rotsaida, "%s", pega_rotulo(&pilha_rotulos,0));
     		geraCodigo(rotsaida, "NADA");
				}
        comando_composto
;

parte_declara_vars:  var {
    char amem[100];
		sprintf(amem, "AMEM %d", numero_variaveis);
		atualiza_num_variaveis(&tabelaSimbolos, numero_variaveis, nivel_lexico);
		geraCodigo(NULL, amem);
}
;

parte_declara_sub_rotinas:
	parte_declara_sub_rotinas {} opcoes_sub_rotinas
	| comando_vazio
;

opcoes_sub_rotinas:
	declaracao_procedimento {atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);} PONTO_E_VIRGULA
	| declaracao_funcao {atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);} PONTO_E_VIRGULA
	| comando_vazio
;


var         : VAR declara_vars
            | declara_vars
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : {
              novas_variaveis = 0;
}
              lista_id_var DOIS_PONTOS
              tipo
              {
                numero_variaveis += novas_variaveis;
              }
              PONTO_E_VIRGULA
;


lista_id_var: lista_id_var VIRGULA IDENT
              { /* insere �ltima vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
            | IDENT { /* insere vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
;

lista_idents: lista_idents VIRGULA IDENT{
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
   	| IDENT
	{
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
;

declaracao_procedimento:
	PROCEDURE { subrt = 1; }
	IDENT
	{

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
	{ novos_param = 0; } parametros_formais_vazio PONTO_E_VIRGULA
	{
		// Zera para ser utilizado na subrotina
		// Mas salva VALOR para ser recuperado
		aux_var = numero_variaveis;
		numero_variaveis = 0;
		deslocamento = 0;
	}
	bloco
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
;

declaracao_funcao:
  FUNCTION{ subrt = 1; }
  IDENT
  {

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

		sprintf(funcao_atual, "%s", token);
    novaEntrada = cria_variavel_funcao(token, RotInicioSubrotina, nivel_lexico, 0, integer);
    push(&tabelaSimbolos, novaEntrada);
    push_pilha_no(&pilhano,  novaEntrada);
    procedimentoAtual = novaEntrada;
  }
  { novos_param = 0; } parametros_formais_vazio DOIS_PONTOS tipo PONTO_E_VIRGULA
  {
    // Zera para ser utilizado na subrotina
    // Mas salva VALOR para ser recuperado
    aux_var = numero_variaveis;
    numero_variaveis = 0;
    deslocamento = 0;
  }
  bloco
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
;

parametros_formais_vazio:
	parametros_formais
	| comando_vazio;
;

parametros_formais:
ABRE_PARENTESES { numero_parametros = 0; }
	lista_parametros_formais
	FECHA_PARENTESES
	{

		atualiza_parametros(pega_posicao(&tabelaSimbolos, numero_parametros),
								&tabelaSimbolos, numero_parametros);
	}
;

lista_parametros_formais:
	lista_parametros_formais PONTO_E_VIRGULA secao_parametros_formais
	| { novos_param++; } secao_parametros_formais
;

secao_parametros_formais:
  var_vazio { novas_variaveis = 0; } lista_idents DOIS_PONTOS tipo
;

var_vazio:
	VAR {por_ref = 1; } | comando_vazio {por_ref = 0; }
;

comando_composto:
   T_BEGIN comandos T_END
;

comandos:
	comandos PONTO_E_VIRGULA comando
	| comando
;

comando:
   	numero_ou_vazio comando_sem_rotulo
;

numero_ou_vazio:
	numero DOIS_PONTOS
	| comando_vazio
;

comando_vazio:;

comando_sem_rotulo:
	variavel atribuicao_procedimento
	| atribuicao_funcao
	| desvio
	| comando_composto
	| comando_condicional
	| comando_repetitivo
	| leitura
	| escrita
;

desvio:
   { }
;

comando_condicional:
	if_then cond_else
	{
		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
;

if_then:
	IF expressao
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
	} THEN comando_sem_rotulo
;

cond_else:
	ELSE
	{
		seta_else(); //marca pro iterador que a iésima cláusula tem else
		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, rot);

		// Imprime rotulo de entrada no fim do if
		geraCodigo(pega_rotulo(&pilha_rotulos, 1), "NADA");
	}
	else_multiplo_unico
	| comando_vazio
;

else_multiplo_unico:
	comando_sem_rotulo
;



chama_procedimento:
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimentoAtual = variavelDestino;
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		entra_procedimento = 1;
		//geraCodigo(NULL, chama_proc);
   	}
	ABRE_PARENTESES {   novos_param = 0; }
	lista_expressoes_ou_vazio
	FECHA_PARENTESES
	{
		entra_procedimento = 0;
		geraCodigo(NULL, chama_proc);

	}
	{ variavelDestino = NULL; }
	|
	{
		entra_procedimento = 1;
		procedimentoAtual = variavelDestino;
		// Imprime rotulo de entrada da subrotina
		char chama_proc[100];
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
		variavelDestino = NULL;
	}
	{
		entra_procedimento = 0;
	}
;

chama_funcao:
    {
    entra_procedimento = 1;
    // Imprime rotulo de entrada da subrotina
    procedimentoAtual = variavelDestino;
    sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
    geraCodigo(NULL, "AMEM 1"); // making up space for the function return
    }
  ABRE_PARENTESES {   novos_param = 0; }
  lista_expressoes_ou_vazio
  FECHA_PARENTESES
  {
    entra_procedimento = 0;
    geraCodigo(NULL, chama_proc);

  }
  { variavelDestino = NULL; }
;

lista_expressoes_ou_vazio:
	lista_expressoes
	| comando_vazio
;


comando_repetitivo:
	WHILE
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
	expressao DO
	{
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
	comando_composto
	{
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
;




lista_expressoes: expressao | expressao {numero_parametros_chamada++;} VIRGULA lista_expressoes;

expressao:
   	{ novos_param++; } expressao_simples  relacao_exp_simples_ou_vazio
;

relacao_exp_simples_ou_vazio:
	relacao expressao_simples
	{

		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	}
	| comando_vazio
;

relacao:
	IGUAL { strcpy(comparacao, "CMIG"); }
	| DIFERENTE { strcpy(comparacao, "CMDG"); }
	| MENOR { strcpy(comparacao, "CMME"); }
	| MENOR_IGUAL { strcpy(comparacao, "CMEG"); }
	| MAIOR_IGUAL { strcpy(comparacao, "CMAG"); }
	| MAIOR { strcpy(comparacao, "CMMA"); }
;

expressao_simples:
   	soma_ou_vazio expressao_lista_termo
;

soma_ou_vazio:
	SOMA| SUBTRACAO | comando_vazio;
;

expressao_lista_termo:
	expressao_lista_termo lista_termo
	| termo
;

lista_termo:
	SOMA termo {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
	| SUBTRACAO termo {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
	| OR termo {
		verifica_tipo(&tabelaTipo, "or");
		geraCodigo(NULL, "DISJ");}
;

termo:
	termo lista_fator
	| fator
;

lista_fator:
	MULTIPLICACAO fator {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
	| DIVISAO fator {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
	| DIV fator {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
	| AND fator {
		verifica_tipo(&tabelaTipo, "and");
		geraCodigo(NULL, "CONJ"); }
;

fator:
	variavel
	{
		if(variavel_carregada != NULL) {
			if(variavel_carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavel_carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
			else {
				char comando[100];
				int cur_params = entra_procedimento == 2 ?
												(procedimentoAtual->numero_parametros - numero_parametros_chamada + 1) : novos_param;
				int passagem = entra_procedimento == 0 ? variavel_carregada->passagem :
																				 procedimentoAtual->params[procedimentoAtual->numero_parametros - cur_params].passagem;

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
	| variavel ABRE_PARENTESES
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
	lista_expressoes FECHA_PARENTESES
	{
		entra_procedimento = 0;
		numero_parametros_chamada = 0;
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
	| numero
	| ABRE_PARENTESES expressao FECHA_PARENTESES
	| NOT fator
;

atribuicao_procedimento:
	atribuicao
	| chama_procedimento
;

atribuicao_funcao:
	atribuicao | chama_funcao
;

atribuicao:
	ATRIBUICAO expressao
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
;

variavel:
   	IDENT {
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
;

numero:
	NUMERO
	{
		push_pilha_tipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
	}
;

// Comandos sem regra --> leitura e escrita
leitura:
  	READ ABRE_PARENTESES lista_leitura FECHA_PARENTESES
;

lista_leitura:
   	lista_leitura VIRGULA simbolo_leitura
   	| simbolo_leitura
;

simbolo_leitura:
	IDENT
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
;

escrita:
   	WRITE ABRE_PARENTESES lista_escrita FECHA_PARENTESES
;

lista_escrita:
	lista_escrita VIRGULA expressao { geraCodigo (NULL, "IMPR"); }
	| expressao { geraCodigo (NULL, "IMPR"); }
;

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
