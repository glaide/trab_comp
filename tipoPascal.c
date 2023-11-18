#include "tipoPascal.h"

void cria_pilha_Tipo(pilha_Tipo *tabela_tipo){
    tabela_tipo->topo = NULL;
    tabela_tipo->tamanho = 0;
}

void push_pilha_Tipo(pilha_Tipo *tabela_tipo, tipo_Pascal tipo_Pascal, no_Tipo *no_Adicionar ){
    //no_Tipo *novo = (no_Tipo*) malloc(sizeof(no_Tipo));
    no_Adicionar->tipo = tipo_Pascal;

    no_Adicionar->prox = tabela_tipo->topo;
    tabela_tipo->topo = no_Adicionar;
    tabela_tipo->tamanho++;
}

tipo_Pascal pop_pilha_Tipo(pilha_Tipo *tabela_tipo){
    if(tabela_tipo->tamanho == 0){
        printf("Pilha vazia!");
        exit(1);
    }
    //aux recebe o topo
    no_Tipo *aux = tabela_tipo->topo;
    //pega o tipo do topo para comparar depois
    tipo_Pascal type = aux->tipo;
    //topo vira a prox
    tabela_tipo->topo = aux->prox;
    free(aux);
    //atualiza tamanho
    tabela_tipo->tamanho--;
    //retorna tipo do topo antigo
    return type;
}

void verifica_tipo(pilhaTipo *tabela_tipo, char* operation){
    tipo_Pascal type1 = pop_pilhaTipo(tabela_tipo);
    tipo_Pascal type2 = pop_pilhaTipo(tabela_tipo);
    if(type1 == type2) { 
        if(strcmp(operation, "atribuicao") != 0) {
            if(strcmp(operation, "soma") == 0 || strcmp(operation, "subtracao") == 0
                || strcmp(operation, "multiplicacao") == 0 || strcmp(operation, "divisao") == 0 || strcmp(operation, "div") == 0)
                push_pilhaTipo(tabela_tipo, integer);
            else
                push_pilhaTipo(tabela_tipo, boolean);
        }
    }
    else {
        printf("Variaveis possuem tipos diferentes.\n");
        printf("Operacao de %s com %s e %s\n", operation, define_tipo(type1), define_tipo(type2));
        exit(1);
    }
}