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

typedef enum tipo_Pascal
{
    integer,
    boolean,
    desconhecido
} tipo_Pascal;
typedef struct no_Tipo
{
    tipo_Pascal tipo;
    struct no_Tipo *prox;
} no_Tipo;
typedef struct type_param_conhecido
{
    tipo_Pascal tipo;
    type_passagem_parametro passagem_parametro;
} type_param_conhecido; // tipo e passagem de parametro para vetor em caso de procedimento ou funcao

typedef struct type_param_desc
{
    char *identificador;
    tipo_Pascal tipo;
    type_passagem_parametro tipo_passado;
} type_param_desc;
typedef struct type_infos_tabela_simbolos
{
    int nivel_lexico, deslocamento, qnt_variaveis; // nivel_lexico = profundidade da tabela de simbolos
    // deslocamento = endereco relativo ao nivel lexico
    // qnt_variaveis = quantidade de variaveis declaradas na tabela de simbolos
    char *rotulo, *identificador; // rotulo para chamada de func/proc, identificador para variaveis
    tipo_Pascal type;             // inteiro, real, booleano, caractere, desconhecido
    type_categoria categoria;     // variavel_simples, parametro_formal, procedimento, funcao
    // type_param_conhecido *parametros_formais; TODO: rever se necessário
    type_passagem_parametro passagem_parametro; // valor ou referencia
    type_param_desc *parametros;                // vetor de parametros formais
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
void criar_tabela_simbolos(TypeTabelaSimbolosPilha *tabelaSimbolos);
// funcao para adicionar um novo elemento na tabela de simbolos

type_infos_tabela_simbolos *criaVariavelSimples(char *indentificador, int nivelLexico, int descolocamento);
type_infos_tabela_simbolos *criaVariavelSimplesProcedimento(char *identificador, int nivelLexico, int totalParametros, char *rotulo);

// void adicionar_elemento_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos);
//   Virou push_tabela_simbolos
void push_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos);
void imprime_tabela_simbolos(TypeTabelaSimbolosPilha *pilha);
void imprime_tabela_simbolos_topo(type_infos_tabela_simbolos *aux);
void atualizaNumeroVariaveis(TypeTabelaSimbolosPilha *p, int vars, int nivel_lexico);
void setaTipo(TypeTabelaSimbolosPilha *tabela_simbolos, tipo_Pascal tipo, int n);
type_infos_tabela_simbolos *busca_tabela_simbolos(TypeTabelaSimbolosPilha *tabela_simbolos, char *identificador);

// ---------------------------------------//

typedef struct pilha_Tipo
{
    int tamanho;
    no_Tipo *topo;
} pilha_Tipo;

void cria_pilha_Tipo(pilha_Tipo *tabela_tipo);
void push_pilha_Tipo(pilha_Tipo *tabela_tipo, tipo_Pascal tipo);
void verifica_tipo(pilha_Tipo *tabela_tipo, char *operation);
char *define_tipo(tipo_Pascal type);

tipo_Pascal pop_pilha_Tipo(pilha_Tipo *tabela_tipo);

#endif
