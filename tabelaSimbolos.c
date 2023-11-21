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
    infosVariavel->numero_parametros = totalParametros;

    infosVariavel->rotulo = (char *)malloc(strlen(rotulo) * sizeof(char));
    strcpy(infosVariavel->rotulo, rotulo);
    infosVariavel->type = desconhecido;
    infosVariavel->deslocamento = 0;
    infosVariavel->prox = NULL;
    infosVariavel->qnt_variaveis = 0;
    infosVariavel->numero_procedimentos = 0;

    return infosVariavel;
}
// Push normal, o info->prox recebe o topo e o topo vira o novo "No", aumenta tamanho da pilha
void push_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos)
{
    infos->prox = pilha->topo;
    pilha->topo = infos;
    pilha->tamanho_pilha++;
}
void pop_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, int qnt)
{
    if (pilha->tamanho_pilha == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    type_infos_tabela_simbolos *aux;
    int i = 0;
    while (i < qnt)
    {
        aux = pilha->topo;
        pilha->topo = aux->prox;
        free(aux);
        pilha->tamanho_pilha--;
        i++;
    }
}

// type_infos_tabela_simbolos pega_topo(TypeTabelaSimbolosPilha *pilha)
// {
//     if (pilha->tamanho_pilha == 0)
//     {
//         printf("Pilha vazia!");
//         exit(1);
//     }
//     return pilha->topo;
// }
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

type_infos_tabela_simbolos *busca_tabela_simbolos(TypeTabelaSimbolosPilha *tabela_simbolos, char *identificador)
{
    type_infos_tabela_simbolos *aux = tabela_simbolos->topo;
    while (aux != NULL)
    {
        if (strcmp(aux->identificador, identificador) == 0)
        {
            printf("Identificador: %s\n", aux->identificador);
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

type_infos_tabela_simbolos *pega_posicao(TypeTabelaSimbolosPilha *tabela_simbolos, int posicao)
{
    if (tabela_simbolos->tamanho_pilha == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    type_infos_tabela_simbolos *aux = tabela_simbolos->topo;
    int i = 0;
    while (i < posicao)
    {
        aux = aux->prox;
        i++;
    }
    return aux;
}

void atualizaNumeroVariaveis(TypeTabelaSimbolosPilha *p, int vars, int nivel_lexico)
{
    type_infos_tabela_simbolos *aux = p->topo;
    while (aux->nivel_lexico != nivel_lexico)
    {
        aux = aux->prox;
    }
    printf("Valor de aux->categoria%d\n", aux->categoria);
    while (aux->categoria != procedimento && aux->categoria != funcao && aux->prox->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->qnt_variaveis = vars;
    printf("Valor de aux->qnt_variaveis%d\n", aux->qnt_variaveis);
}

void atualizaNumProcedimento(TypeTabelaSimbolosPilha *p, int nivel_lexico)
{
    printf("entrou no atualizaNumProcedimento\n");
    type_infos_tabela_simbolos *aux = p->topo;
    while (aux->nivel_lexico != nivel_lexico)
        aux = aux->prox;
    while (aux->categoria != funcao && aux->categoria != procedimento && aux->prox->prox != NULL)
        aux = aux->prox;
    aux->numero_procedimentos++;
}
void atualizaNumeroParametros(type_infos_tabela_simbolos *infos, TypeTabelaSimbolosPilha *p, int vars)
{

    if (p->tamanho_pilha == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    if (p->tamanho_pilha < vars)
    {
        printf("Quantidade de variaveis declaradas maior que o tamanho da pilha!");
        exit(1);
    }
    infos->numero_parametros = vars;
    infos->parametros = (type_param_desc *)malloc(vars * sizeof(type_param_desc));
    type_infos_tabela_simbolos *aux = p->topo;
    int i = 0;
    while (i < vars)
    {
        infos->parametros[i].identificador = (char *)malloc((strlen(aux->identificador) + 1) * sizeof(char));
        strcpy(infos->parametros[i].identificador, aux->identificador);
        infos->parametros[i].tipo = aux->type;
        infos->parametros[i].tipo_passado = aux->passagem_parametro;
        aux->deslocamento = -4 - i;
        aux = aux->prox;
        i++;
    }
    //   verificar se é funcao
    if (infos->categoria == funcao)
    {
        infos->deslocamento -= 2;
    }
    aux->numero_parametros = vars;
}
void cria_pilha_no_procedimento(pilha_no_procedimento *p)
{
    printf("entrou no cria_pilha_no_procedimento\n");
    int aux = 8;
    printf("Valor de aux: %d\n", aux);
    p->max = aux;
    p->p = malloc(sizeof(type_infos_tabela_simbolos *) * p->max);
    p->topo = 0;
    printf("Valor de p->topo: %d\n", p->topo);
    printf("Valor de p->max: %d\n", p->max);
}

void *pop_pilha_no_procedimento(pilha_no_procedimento *p)
{
    p->topo--;
    return (p->p[p->topo + 1]);
}

void push_pilha_no_procedimento(pilha_no_procedimento *p, type_infos_tabela_simbolos *x)
{
    printf("entrou no push_pilha_no_procedimento\n");
    printf("Valor de p->topo: %d\n", p->topo);
    printf("Valor de p->max: %d\n", p->max);
    if (p->topo == p->max - 1)
    {
        printf("entrou no if do push_pilha_no_procedimento\n");
        p->max *= 2;
        p->p = realloc(p->p, sizeof(type_infos_tabela_simbolos *) * p->max);
    }
    p->topo++;
    p->p[p->topo] = x;
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
    printf("entrou no cria_pilha_Tipo\n");
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
            printf("Variaveis possuem o mesmo tipo.\n");
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
