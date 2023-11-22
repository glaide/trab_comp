#include "pilha.h"

void cria_pilha_tipo(tipo_pilha *tabela_tipos)
{
    tabela_tipos->topo = NULL;
    tabela_tipos->tamanho = 0;
}

tipo_pascal pop_pilha_tipo(tipo_pilha *tabela_tipos)
{
    if (tabela_tipos->tamanho == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    tipo_no *aux = tabela_tipos->topo;
    tipo_pascal tipo = aux->tipo;
    tabela_tipos->topo = aux->prox;
    free(aux);
    tabela_tipos->tamanho--;
    return tipo;
}

void push_pilha_tipo(tipo_pilha *tabela_tipos, tipo_pascal tipo)
{
    tipo_no *aux = (tipo_no *)malloc(sizeof(tipo_no));
    aux->tipo = tipo;
    aux->prox = tabela_tipos->topo;
    tabela_tipos->topo = aux;
    tabela_tipos->tamanho++;
}

char *seta_tipo(tipo_pascal tipo)
{
    if (tipo == integer)
    {
        return "integer";
    }
    else
    {
        return "desconhecido";
    }
}
void verifica_tipo(tipo_pilha *tabela_tipos, char *operacao)
{
    tipo_pascal tipo1 = pop_pilha_tipo(tabela_tipos);
    tipo_pascal tipo2 = pop_pilha_tipo(tabela_tipos);
    if (tipo1 == tipo2)
    {
        // Verifica se a operação não é "atribuicao"
        if (strcmp(operacao, "atribuicao") != 0)
        {
            int verifica_operacao = strcmp(operacao, "soma") == 0 || strcmp(operacao, "subtracao") == 0 ||
                                    strcmp(operacao, "multiplicacao") == 0 || strcmp(operacao, "divisao") == 0 ||
                                    strcmp(operacao, "div") == 0;
            // Verifica se a operação é uma das operações que envolvem inteiros
            if (verifica_operacao)
            {
                // Chama a função push_pilha_tipo() com o tipo integer
                push_pilha_tipo(tabela_tipos, integer);
            }
        }
    }
    else
    {
        printf("Variaveis diferentes\n");
        printf("Operacao de %s com %s e %s nao é possivel\n", operacao, seta_tipo(tipo1), seta_tipo(tipo1));
        exit(1);
    }
}

void imprime_tabela_simbolo(tipo_pilha *tabela_tipos)
{
    tipo_no *aux = tabela_tipos->topo;
    while (aux != NULL)
    {
        printf("%s ", seta_tipo(aux->tipo));
        aux = aux->prox;
    }
}
void cria_pilha_rotulo(pilha_rotulo *pilha_rot)
{
    pilha_rot->topo = NULL;
    pilha_rot->tamanho = 0;
}
char *cria_rotulo(int numero_rotulo)
{
    char *rotulo = (char *)malloc(10 * sizeof(char));
    sprintf(rotulo, "R%02d", numero_rotulo);
    return rotulo;
}

void push_pilha_rotulo(pilha_rotulo *pilha_rot, char *novo_rotulo)
{
    no_rotulo *novo = (no_rotulo *)malloc(sizeof(no_rotulo));
    novo->rot = (char *)malloc(strlen(novo_rotulo) * sizeof(char));
    strcpy(novo->rot, novo_rotulo);
    novo->prox = pilha_rot->topo;
    pilha_rot->topo = novo;
    pilha_rot->tamanho++;
}

void pop_pilha_rotulo(pilha_rotulo *pilha_rot, int n)
{
    if (pilha_rot->tamanho == 0)
    {
        printf("Rotulos: Pilha vazia!");
        exit(1);
    }

    no_rotulo *aux;
    int i = 0;
    // percorre toda a pilha para achar o nó que será removido
    while (i < n)
    {

        aux = pilha_rot->topo;
        pilha_rot->topo = aux->prox;
        free(aux);
        pilha_rot->tamanho--;
        i++;
    }
}

char *pega_rotulo(pilha_rotulo *pilha_rot, int posicao)
{
    if (pilha_rot->tamanho == 0)
    {
        printf("Rotulos: pilha de vazia!");
        exit(1);
    }

    no_rotulo *aux = pilha_rot->topo;
    // verifica se esta vazio
    if (posicao == 0)
    {
        posicao++;
    }
    while (--posicao)
    {
        aux = aux->prox;
    }
    return aux->rot;
}
