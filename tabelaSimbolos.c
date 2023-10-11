typedef enum type_passagem_parametro
{
    VALOR,
    REFERENCIA
} TypePassagemParametro;

typedef enum type_categoria
{
    variavel_simples,
    parametro_formal,
    procedimento,
    funcao
} TypeCategoria;

typedef enum type_pascal
{
    inteiro,
    real,
    booleano,
    caractere,
    desconhecido
} TypePascal;

typedef struct type_param_conhecido
{
    TypePascal tipo;
    TypePassagemParametro passagem_parametro;
} TPConhecido; // tipo e passagem de parametro para vetor em caso de procedimento ou funcao

typedef struct type_infos
{
    int nivel_lexico, deslocamento, qnt_variaveis; // nivel_lexico = profundidade da tabela de simbolos
    // deslocamento = endereco relativo ao nivel lexico
    // qnt_variaveis = quantidade de variaveis declaradas na tabela de simbolos
    char *rotulo, *identificador;    // rotulo para chamada de func/proc, identificador para variaveis
    TypePascal type;                 // inteiro, real, booleano, caractere, desconhecido
    TypeCategoria categoria;         // variavel_simples, parametro_formal, procedimento, funcao
    TPConhecido *parametros_formais; // tamanho do vetor = numero de parametros
    // possiveis outros campos: numero de parametros, numero de procedimentos, numero de funcoes (se necessario)
    struct TypeInfosTabelaSimbolos *prox; // ponteiro para proximo elemento da tabela de simbolos

} TypeInfosTabelaSimbolos;

typedef struct type_tabela_simbolos_pilha
{
    int tamanho_pilha;
    TypeInfosTabelaSimbolos **infos; // vetor de ponteiros para tabela de simbolos
} TypeTabelaSimbolosPilha;
