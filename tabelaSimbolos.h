#ifndef __TABELASIMB_H__
#define __TABELASIMB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum type_passagem_parametro
{
    VALOR,
    REFERENCIA
} type_passagem_parametro;

typedef enum type_categoria
{
    variavel_simples,
    parametro_formal,
    procedimento,
    funcao
} type_categoria;

typedef enum type_pascal
{
    inteiro,
    real,
    booleano,
    caractere,
    desconhecido
} type_pascal;

typedef struct type_param_conhecido
{
    type_pascal tipo;
    type_passagem_parametro passagem_parametro;
} type_param_conhecido; // tipo e passagem de parametro para vetor em caso de procedimento ou funcao

typedef struct type_infos_tabela_simbolos
{
    int nivel_lexico, deslocamento, qnt_variaveis; // nivel_lexico = profundidade da tabela de simbolos
    // deslocamento = endereco relativo ao nivel lexico
    // qnt_variaveis = quantidade de variaveis declaradas na tabela de simbolos
    char *rotulo, *identificador;             // rotulo para chamada de func/proc, identificador para variaveis
    type_pascal type;                         // inteiro, real, booleano, caractere, desconhecido
    type_categoria categoria;                 // variavel_simples, parametro_formal, procedimento, funcao
    type_param_conhecido *parametros_formais; // tamanho do vetor = numero de parametros
    // possiveis outros campos: numero de parametros, numero de procedimentos, numero de funcoes (se necessario)
    struct type_infos_tabela_simbolos *prox; // ponteiro para proximo elemento da tabela de simbolos

} type_infos_tabela_simbolos;

typedef struct type_tabela_simbolos_pilha
{
    int tamanho_pilha;
    type_infos_tabela_simbolos **infos; // vetor de ponteiros para tabela de simbolos
} TypeTabelaSimbolosPilha;

// funcao para criar uma nova tabela de simbolos
TypeTabelaSimbolosPilha *criar_tabela_simbolos();
// funcao para montar as informacoes para add na tabela de simbolos para cada parametro
type_infos_tabela_simbolos cria_var_simples(char *identificador, int nivel_lexico, int deslocamento);

void adicionar_elemento_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos);

#endif
