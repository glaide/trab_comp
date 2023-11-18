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
    char *rotulo, *identificador; // rotulo para chamada de func/proc, identificador para variaveis
    type_pascal type;             // inteiro, real, booleano, caractere, desconhecido
    type_categoria categoria;     // variavel_simples, parametro_formal, procedimento, funcao
    type_param_conhecido *parametros_formais;
    // possiveis outros campos: numero de parametros, numero de procedimentos, numero de funcoes (se necessario)
    int numero_parametros, numero_procedimentos, numero_funcoes;
    struct type_infos_tabela_simbolos *prox; // ponteiro para proximo elemento da tabela de simbolos

} type_infos_tabela_simbolos;

typedef struct type_tabela_simbolos_pilha
{
    int tamanho_pilha;
    // ADICIONEI O TOPO PQ VAI PRECISAR

    type_infos_tabela_simbolos *topo;

    type_infos_tabela_simbolos **infos; // vetor de ponteiros para tabela de simbolos
} TypeTabelaSimbolosPilha;

// funcao para criar uma nova tabela de simbolos, fiz VOID pq criamos uma varivael do tipo tabela no comp.y
// e passamos ela para criar_tabela_simbolo
void *criar_tabela_simbolos(TypeTabelaSimbolosPilha *tabelaSimbolos);
// funcao para adicionar um novo elemento na tabela de simbolos

type_infos_tabela_simbolos *criaVariavelSimples(char *indentificador, int nivelLexico, int descolocamento);
type_infos_tabela_simbolos *criaVariavelSimplesProcedimento(char *identificador, int nivelLexico, int totalParametros, char *rotulo);

// void adicionar_elemento_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos);
//   Virou push_tabela_simbolos
void push_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos);
void imprime_tabela_simbolos(TypeTabelaSimbolosPilha *pilha);

#endif
