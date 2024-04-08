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

// Função para cadastrar paciente
PACIENTE *cadastrarPaciente()
{
    PACIENTE *novoPaciente = (PACIENTE *)malloc(sizeof(PACIENTE)); // Alocando memória
    if (novoPaciente == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    printf("CADASTRO DE PACIENTE\n");
    printf("Nome: ");
    fgets(novoPaciente->nome, sizeof(novoPaciente->nome), stdin);
    novoPaciente->nome[strcspn(novoPaciente->nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &novoPaciente->idade);
    getchar(); // Limpa o buffer

    return novoPaciente;
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
    PACIENTE *novoPaciente = NULL;
    int quantidade = 0;
    MEDICO *novoMedico;
    int op;

    do
    {
        printf("----- SISTEMA DE PRONTO ATENDIMENTO -----\n");
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
            novoPaciente = realloc(novoPaciente, (quantidade + 1) * sizeof(PACIENTE));
            novoPaciente[quantidade] = *cadastrarPaciente();
            quantidade++;
            break;

        case 2:
            novoMedico = cadastrarMedico();
            quantidade++;
            break;
        case 3:
            qsort(novoPaciente, quantidade, sizeof(PACIENTE), compararPacientes);
            for (int i = 0; i < quantidade; i++)
            {
                printf("Nome: %s, Idade: %d\n", novoPaciente[i].nome, novoPaciente[i].idade);
            }
            break;
        case 4:
            printf("Lista de Medicos: \n");
            // Função para listar médicos
            break;
        case 5:
            // Realizar atendimentos
            break;
        case 6:
            // listar atendimentos
            break;
        case 7:
            // cancelar atendimentos
            break;
        case 8:
            salvarEmArquivo(novoPaciente, quantidade);
            break;
        case 9:
            imprimirConteudoDoArquivo(novoPaciente, quantidade);
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
    return 0;
}
