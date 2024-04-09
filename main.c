#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
} PACIENTE;

typedef struct
{
    char nome[40];
    char especialidade[50];
} MEDICO;

typedef struct 
{
    PACIENTE *paciente;
    MEDICO *medico;
    char motivo[50];
    int prioridade;
} ATENDIMENTO;

// Estrutura para uma lista encadeada
typedef struct ITEM
{
    void *chave;
    struct ITEM *prox;
} ITEM;

typedef struct
{
    ITEM *inicio;
    int qtde;
} LISTA;

//Inicializa a lista
void inicializa(LISTA *l)
{
    l->inicio = NULL;
    l->qtde = 0;
}

//Insere um elemento na lista
void inserir(LISTA *l, void *chave)
{
    ITEM *novoItem = (ITEM*)malloc(sizeof(ITEM));
    if (novoItem == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novoItem->chave = chave;
    novoItem->prox = l->inicio;
    l->inicio = novoItem;
    l->qtde++;
}

//Imprime os dados do paciente
void imprimirPaciente(void *chave)
{
    if (chave != NULL)
    {
        PACIENTE *p = (PACIENTE*)chave;
        printf("Nome: %s\n", p->nome);
        printf("Idade: %d\n", p->idade);
    }
}

// Função para cadastrar paciente
PACIENTE *cadastrarPaciente()
{
    PACIENTE *novoPaciente = (PACIENTE *)malloc(sizeof(PACIENTE)); // Alocando memória
    if (novoPaciente == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    printf("\nCADASTRO DE PACIENTE\n");
    printf("Nome: ");
    fgets(novoPaciente->nome, sizeof(novoPaciente->nome), stdin);
    novoPaciente->nome[strcspn(novoPaciente->nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &novoPaciente->idade);
    getchar(); // Limpa o buffer

    return novoPaciente;
}

// Função de comparação para qsort
int compararPacientes(const void *a, const void *b)
{
    PACIENTE *pacienteA = (PACIENTE *)a;
    PACIENTE *pacienteB = (PACIENTE *)b;

    // Primeiro, compare os nomes
    int nomeComparacao = strcmp(pacienteA->nome, pacienteB->nome);
    if (nomeComparacao != 0)
    {
        return nomeComparacao; // Se os nomes são diferentes, retorne o resultado da comparação de nomes
    }

    // Se os nomes são iguais, compare as idades
    return pacienteA->idade - pacienteB->idade;
}

//Função para listar pacientes cadastrados
void listarPacientes(PACIENTE *p, int quantidade)
{
    if (p == NULL || quantidade == 0)
    {
        printf("Nenhum paciente cadastrado!\n");
        return;
    }

    printf("\nPaciente Cadastrados: ");
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nNome: %s\n", p[i].nome);
        printf("Idade: %d\n", p[i].idade);
    }
}

void imprimirMedico(void *chave)
{
    if (chave != NULL)
    {
        MEDICO *m = (MEDICO*)chave;
        printf("Nome: %s\n", m->nome);
        printf("Especialidade: %s\n", m->especialidade);
    }
}

// Função para cadastrar médico
MEDICO *cadastrarMedico()
{
    MEDICO *novoMedico = (MEDICO *)malloc(sizeof(MEDICO)); // Alocando memória
    if (novoMedico == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    printf("CADASTRO DE MEDICO\n");
    printf("Nome: ");
    fgets(novoMedico->nome, sizeof(novoMedico->nome), stdin);
    novoMedico->nome[strcspn(novoMedico->nome, "\n")] = '\0';

    printf("Especialidade: ");
    fgets(novoMedico->especialidade, sizeof(novoMedico->especialidade), stdin);
    novoMedico->especialidade[strcspn(novoMedico->especialidade, "\n")] = '\0';

    return novoMedico;
}

// Função de comparação para qsort
int compararMedicos(const void *a, const void *b)
{
    MEDICO *medicoA = (MEDICO *)a;
    MEDICO *medicoB = (MEDICO *)b;

    // Primeiro, compare os nomes
    int nomeComparacao = strcmp(medicoA->nome, medicoB->nome);
    if (nomeComparacao != 0)
    {
        return nomeComparacao; // Se os nomes são diferentes, retorne o resultado da comparação de nomes
    }

    // Se os nomes são iguais, compare as idades
    return medicoA->especialidade - medicoB->especialidade;
}

//Função para listar os médicos cadastrados
void listarMedicos(MEDICO *m, int quantidade)
{
    if (m == NULL || quantidade == 0)
    {
        printf("Nenhum medico cadastrado!\n");
        return;
    }

    printf("\nMedicos Cadastrados:");
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nNome: %s\n", m[i].nome);
        printf("Especialidade: %s\n", m[i].especialidade);
    }
}

void consulta(PACIENTE *p, int qtdeP, MEDICO *m, int qtdeM, LISTA *l) 
{
    if (p == NULL || qtdeP == 0 || m == NULL || qtdeM == 0 || l == NULL)
    {
        printf("Nao ha nenhum cadastro no sistema!\n");
        return;
    }
    
    char paciente[40];
    char medico[40];
    char motivo[50];
    int prioridade, opPaciente, opMedico;


    printf("\nRealizar atendimento");

    printf("Pacientes cadastrados:\n");
    for (int i = 0; i < qtdeP; i++)
    {
        printf("%d - %s\n", i + 1, p[i].nome);
    }
    
    printf("Informe o paciente: ");
    scanf("%d", &opPaciente);
    getchar();

    if (opPaciente < 1 || opPaciente > qtdeP)
    {
        printf("Opcao invalida!\n");
        return;
    }
    strcpy(paciente, p[opPaciente - 1].nome);
    
    //Listar médicos cadastrados
    printf("Medicos cadastrados:\n");
    for (int i = 0; i < qtdeM; i++)
    {
        printf("%d - %s\n", i + 1, m[i].nome);
    }
    
    printf("Informe o medico: ");
    scanf("%d", &opMedico);
    getchar();

    if (opMedico < 1 || opMedico > qtdeM)
    {
        printf("Opcao invalida!\n");
        return;
    }
    strcpy(medico, m[opMedico - 1].nome);

    printf("Motivo da consulta ");
    fgets(motivo, sizeof(motivo), stdin);
    motivo[strcspn(motivo, "\n")] = '\0';

    printf("Prioridade (1 - leve, 2 - moderada, 3 - grave): ");
    scanf("%d", &prioridade);
    getchar();

    //inicia um novo atendimento
    ATENDIMENTO *novo = (ATENDIMENTO*)malloc(sizeof(ATENDIMENTO));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    novo->paciente = &p[opPaciente - 1];
    novo->medico = &m[opMedico - 1];
    strcpy(novo->motivo, motivo);
    novo->prioridade = prioridade;

    //insere o atendimento na lista
    inserir(l, novo);

    //exibe as informações do atendimento
    printf("Atendimento:\n");
    printf("Paciente: %s\n", paciente);
    printf("Medico: %s\n", medico);
    printf("Motivo da consulta: %s\n", motivo);
    printf("Prioridade: %s\n", (prioridade == 1 ? "Leve" : (prioridade == 2 ? "Moderada" : "Grave")));
}

void listarAtendimentos(LISTA *l)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("Nenhum atendimento realizado!\n");
        return;
    }

    printf("\nAtendimentos Realizados: ");
    ITEM *atual = l->inicio;
    while (atual != NULL)
    {
        ATENDIMENTO *atendimento = (ATENDIMENTO*)atual->chave;
        if (atendimento != NULL)
        {
            printf("\nPaciente: %s\n", atendimento->paciente->nome);
            printf("Medico: %s\n", atendimento->medico->nome);
            printf("Motivo da consulta: %s\n", atendimento->motivo);
            printf("Prioridade: %s\n", (atendimento->prioridade == 1 ? "Leve" : (atendimento->prioridade == 2 ? "Moderada" : "Grave")));
        }
        atual = atual->prox;
    }
}

void salvarEmArquivo(PACIENTE *novoPaciente, int quantidade)
{
    FILE *arq = fopen("arquivo.txt", "w"); // abri ou cria um arq txt e escreve.

    if (arq)
    {
        for (int i = 0; i < quantidade; i++)
        {
            fprintf(arq, "Paciente: %s ", novoPaciente[i].nome);
            fprintf(arq, "Idade: %d\n ", novoPaciente[i].idade);
        }
        fclose(arq); // fecha o arq.
    }
    else
    {
        printf("ERRO: não é possivel abrir o arquivo.");
    }
}

void imprimirConteudoDoArquivo(PACIENTE *novoPaciente, int quantidade)
{
    FILE *arq = fopen("arquivo.txt", "r"); // Abre o arquivo em modo de leitura

    if (arq == NULL)
    {
        printf("ERRO: não é possível abrir o arquivo.\n");
        return;
    }

    char linha[100]; // Buffer para armazenar cada linha do arquivo

    // Lê cada linha do arquivo até o final
    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        printf("%s", linha); // Imprime a linha
    }

    fclose(arq); // Fecha o arquivo
}

int main()
{
    LISTA atendimentos;
    inicializa(&atendimentos);
    
    PACIENTE *novoPaciente = NULL;
    MEDICO *novoMedico = NULL;
    int qtdePacientes = 0;
    int qtdeMedicos = 0;
    int op;

    do
    {
        printf("\nSISTEMA DE PRONTO ATENDIMENTO\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Cadastrar medico\n");
        printf("3 - Listar pacientes\n");
        printf("4 - Listar medicos\n");
        printf("5 - Realizar atendimento\n");
        printf("6 - Listar atendimento\n");
        printf("7 - Cancelar atendimento\n");
        printf("8 - Salvar em Arquivo\n");
        printf("9 - Ler este Arquivo\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        getchar(); // Limpa o buffer de entrada após o scanf
        switch (op)
        {
        case 1:
            novoPaciente = realloc(novoPaciente, (qtdePacientes + 1) * sizeof(PACIENTE));
            novoPaciente[qtdePacientes] = *cadastrarPaciente();
            qtdePacientes++;
            break;

        case 2:
            novoMedico = realloc(novoMedico, (qtdeMedicos + 1) * sizeof(MEDICO));
            novoMedico[qtdeMedicos] = *cadastrarMedico();
            qtdeMedicos++;
            break;
        case 3:
            qsort(novoPaciente, qtdePacientes, sizeof(PACIENTE), compararPacientes);
            listarPacientes(novoPaciente, qtdePacientes);
            break;
        case 4:
            qsort(novoMedico, qtdeMedicos, sizeof(MEDICO), compararMedicos);
            listarMedicos(novoMedico, qtdeMedicos);
            break;
        case 5:
            consulta(novoPaciente, qtdePacientes, novoMedico, qtdeMedicos, &atendimentos);
            break;
        case 6:
            listarAtendimentos(&atendimentos);
            break;
        case 7:
            // cancelar atendimentos
            break;
        case 8:
            salvarEmArquivo(novoPaciente, qtdePacientes);
            break;
        case 9:
            imprimirConteudoDoArquivo(novoPaciente, qtdePacientes);
            break;
        case 0:
            printf("Saindo do sistema\n");
            exit(0);
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);
    free(novoPaciente);
    free(novoMedico);
    return 0;
}
