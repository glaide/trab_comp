#include "tabelaSimbolos.h"

// funcao para criar uma nova tabela de simbolos
void criar_tabela_simbolos(TypeTabelaSimbolosPilha *tabelaSimbolos)
{
    // PRECISA DESSE MALLOC?
    // TypeTabelaSimbolosPilha *tabela = (TypeTabelaSimbolosPilha *)malloc(sizeof(TypeTabelaSimbolosPilha));
    tabelaSimbolos->tamanho_pilha = 0; // Inicializa o tamanho da pilha como 0
    tabelaSimbolos->infos = NULL;      // Inicializa o vetor de ponteiros como NULL (sem elementos ainda)
    tabelaSimbolos->topo = NULL;
}
// preenche os valores da varialvel simples e retorna o "No" com as informações, após ele chama a pushPilha
type_infos_tabela_simbolos *criaVariavelSimples(char *identificador, int nivelLexico, int deslocamento)
{
    // aloca espaço para infosVariavel
    type_infos_tabela_simbolos *infosVariavel = (type_infos_tabela_simbolos *)malloc(sizeof(type_infos_tabela_simbolos));

    // aloca espaço para a string Identificador e copia ela para InfosVariavel
    infosVariavel->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(infosVariavel->identificador, identificador);

    // atribuições normais
    infosVariavel->nivel_lexico = nivelLexico;
    infosVariavel->deslocamento = deslocamento;
    infosVariavel->type = desconhecido;
    infosVariavel->categoria = variavel_simples;
    infosVariavel->prox = NULL;

    return infosVariavel;
}

type_infos_tabela_simbolos *criaVariavelSimplesProcedimento(char *identificador, int nivelLexico, int totalParametros, char *rotulo)
{
    // aloca espaço para infosVariavel
    type_infos_tabela_simbolos *infosVariavel = (type_infos_tabela_simbolos *)malloc(sizeof(type_infos_tabela_simbolos));

    // aloca espaço para a string Identificador e copia ela para InfosVariavel
    infosVariavel->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(infosVariavel->identificador, identificador);
    infosVariavel->nivel_lexico = nivelLexico;
    infosVariavel->categoria = procedimento;
    infosVariavel->rotulo = (char *)malloc(strlen(rotulo) * sizeof(char));
    strcpy(infosVariavel->rotulo, rotulo);
    infosVariavel->numero_parametros = totalParametros;

    infosVariavel->prox = NULL;
    infosVariavel->numero_funcoes = 0;
    infosVariavel->numero_procedimentos = 0;
    infosVariavel->parametros_formais = NULL;
    infosVariavel->type = desconhecido;
    infosVariavel->deslocamento = 0;

    return infosVariavel;
}
// Push normal, o info->prox recebe o topo e o topo vira o novo "No", aumenta tamanho da pilha
void push_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos)
{
    infos->prox = pilha->topo;
    pilha->topo = infos;
    pilha->tamanho_pilha++;
    printf("simbolo inserido %s", infos->identificador);
    printf("Tamanho atual da pilha: %d", pilha->tamanho_pilha);
}

void imprime_tabela_simbolos(TypeTabelaSimbolosPilha *pilha)
{
    type_infos_tabela_simbolos *aux = pilha->topo;
    while (aux != NULL)
    {
        printf("Identificador: %s\n", aux->identificador);
        printf("Nivel Lexico: %d\n", aux->nivel_lexico);
        printf("Deslocamento: %d\n", aux->deslocamento);
        printf("Categoria: %d\n", aux->categoria);
        printf("Tipo: %d\n", aux->type);
        printf("Prox: %p\n", aux->prox);
        printf("\n");
        aux = aux->prox;
    }
}

void imprime_tabela_simbolos_topo(type_infos_tabela_simbolos *aux)
{

    while (aux != NULL)
    {
        printf("Identificador: %s\n", aux->identificador);
        printf("Nivel Lexico: %d\n", aux->nivel_lexico);
        printf("Deslocamento: %d\n", aux->deslocamento);
        printf("Categoria: %d\n", aux->categoria);
        printf("Tipo: %d\n", aux->type);
        printf("Prox: %p\n", aux->prox);
        printf("\n");
        aux = aux->prox;
    }
}

void atualizaNumeroVariaveis(TypeTabelaSimbolosPilha *p, int vars, int nivel_lexico)
{

    type_infos_tabela_simbolos *aux = p->topo;
    while (aux->nivel_lexico != nivel_lexico)
    {
        aux = aux->prox;
    }
    while (aux->categoria != funcao && aux->categoria != procedimento && aux->prox->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->qnt_variaveis = vars;
}

void setaTipo(TypeTabelaSimbolosPilha *tabela_simbolos, tipo_Pascal tipo, int n)
{

    if (tabela_simbolos->tamanho_pilha == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    int i = 0;
    type_infos_tabela_simbolos *aux = tabela_simbolos->topo;
    while ((i < n) && (aux != NULL))
    {
        aux->type = tipo;
        aux = aux->prox;
        i++;
    }
}

void cria_pilha_Tipo(pilha_Tipo *tabela_tipo)
{
    tabela_tipo->topo = NULL;
    tabela_tipo->tamanho = 0;
}

void push_pilha_Tipo(pilha_Tipo *tabela_tipo, tipo_Pascal tipo_Pascal)
{
    no_Tipo *novo = (no_Tipo *)malloc(sizeof(no_Tipo));
    novo->tipo = tipo_Pascal;

    novo->prox = tabela_tipo->topo;
    tabela_tipo->topo = novo;
    tabela_tipo->tamanho++;
}

tipo_Pascal pop_pilha_Tipo(pilha_Tipo *tabela_tipo)
{
    if (tabela_tipo->tamanho == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    // aux recebe o topo
    no_Tipo *aux = tabela_tipo->topo;
    // pega o tipo do topo para comparar depois
    tipo_Pascal type = aux->tipo;
    // topo vira a prox
    tabela_tipo->topo = aux->prox;
    free(aux);
    // atualiza tamanho
    tabela_tipo->tamanho--;
    // retorna tipo do topo antigo
    return type;
}
char *define_tipo(tipo_Pascal type)
{
    switch (type)
    {
    case integer:
        return "integer";
    case boolean:
        return "booleano";
    default:
        return "tipo indefinido";
    }
}

void verifica_tipo(pilha_Tipo *tabela_tipo, char *operation)
{
    tipo_Pascal type1 = pop_pilha_Tipo(tabela_tipo);
    tipo_Pascal type2 = pop_pilha_Tipo(tabela_tipo);
    if (type1 == type2)
    {
        if (strcmp(operation, "atribuicao") != 0)
        {
            if (strcmp(operation, "soma") == 0 || strcmp(operation, "subtracao") == 0 || strcmp(operation, "multiplicacao") == 0 || strcmp(operation, "divisao") == 0 || strcmp(operation, "div") == 0)
                push_pilha_Tipo(tabela_tipo, integer);
            else
                push_pilha_Tipo(tabela_tipo, boolean);
        }
    }
    else
    {
        printf("Variaveis possuem tipos diferentes.\n");
        printf("Operacao de %s com %s e %s\n", operation, define_tipo(type1), define_tipo(type2));
        exit(1);
    }
}
