#ifndef __TABELASIMBOLOS_H__
#define __TABELASIMBOLOS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"
typedef enum tipo_passagem
{
    VALOR,
    REFERENCIA
} tipo_passagem;

typedef enum tipo_categoria
{
    var_simples,
    param_formal,
    procedimento,
    funcao,
} tipo_categoria;

typedef struct parametro_nao_conhecido
{
    char *identificador;
    tipo_pascal tipo;
    tipo_passagem passagem;
} parametro_nao_conhecido;

typedef struct type_info_tabela_simbolos
{
    char *identificador, *rotulo;
    int nivel_lexico, deslocamento, numero_parametros, numero_procedimentos, numero_variaveis;
    tipo_categoria categoria;
    tipo_pascal tipo;
    tipo_passagem passagem;
    parametro_nao_conhecido *params;
    struct type_info_tabela_simbolos *prox;
    int declarada;
} type_info_tabela_simbolos;

typedef struct pilha_simbolos
{
    int tamanho;
    type_info_tabela_simbolos *topo;
} pilha_simbolos;

typedef struct pilha_no
{
    int max, topo;
    type_info_tabela_simbolos **p;
} pilha_no;

// parte relacionada a pilha de nós
void cria_pilha_no(pilha_no *p_no);
void *pop_pilha_no(pilha_no *p_no);
void push_pilha_no(pilha_no *p_no, type_info_tabela_simbolos *infos);

void cria_pilha(pilha_simbolos *tabela_de_simbolos);
void push(pilha_simbolos *tabela_de_simbolos, type_info_tabela_simbolos *novo_simb);
type_info_tabela_simbolos *pega_topo(pilha_simbolos *tabela_de_simbolos);
type_info_tabela_simbolos *pega_posicao(pilha_simbolos *tabela_de_simbolos, int n);
type_info_tabela_simbolos *busca_pilha_simbolos(pilha_simbolos *tabela_de_simbolos, char *identificador);
void pop(pilha_simbolos *tabela_de_simbolos, int n);
type_info_tabela_simbolos *cria_variavel_simples(char *identificador, int nivel_lexico, int deslocamento);
type_info_tabela_simbolos *cria_variavel_funcao(char *identificador, char *rotulo, int nivel_lexico, int numero_parametros, tipo_pascal tipo_retorno);
type_info_tabela_simbolos *cria_variavel_procedure(char *identificador, char *rotulo, int nivel_lexico, int numero_parametros);
type_info_tabela_simbolos *cria_variavel_formal(char *identificador, int nivel_lexico, int deslocamento, tipo_passagem passagem);
void seta_tipos(pilha_simbolos *tabela_de_simbolos, tipo_pascal tipo, int n);

void imprime_tabela(pilha_simbolos *tabela_de_simbolos);

void atualiza_parametros(type_info_tabela_simbolos *p, pilha_simbolos *tabela_de_simbolos, int parametros_total);
void atualiza_num_procedimentos(pilha_simbolos *p, int nivel_lexico);
void atualiza_num_variaveis(pilha_simbolos *p, int vars, int nivel_lexico);

void seta_else();
void inicia_else();
#endif
