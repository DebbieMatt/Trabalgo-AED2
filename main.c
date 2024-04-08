#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    int prioridade; // 1 Azul 2 Amarelo 3 Vermelho
} PACIENTE;

typedef struct
{
    char nome[40];
    char especialidade[50];
    // PACIENTE *pacientes;
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

    printf("Prioridade: ");
    scanf("%d", &novoPaciente->prioridade);
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

void bubbleSortPrioridadeCrescente(PACIENTE v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j].prioridade > v[j + 1].prioridade)
            {
                // trocar prioridade
                int aux = v[j].prioridade;
                v[j].prioridade = v[j + 1].prioridade;
                v[j + 1].prioridade = aux;

                // trocar idades correspondente a prioridade
                aux = v[j].idade;
                v[j].idade = v[j + 1].idade;
                v[j + 1].idade = aux;

                // troca nomes correspondentes a prioridade
                char auxc[50];
                strcpy(auxc, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, auxc);
            }
        }
    }
}


int main()
{
    PACIENTE *novoPaciente;
    MEDICO *novoMedico;
    int op;
    int quant_paciente = 0;
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
        printf("0 - Sair\n");

        scanf("%d", &op);
        getchar(); // Limpa o buffer de entrada após o scanf

        switch (op)
        {
        case 1:
            novoPaciente = cadastrarPaciente();
            quant_paciente++;
            break;
        case 2:
            novoMedico = cadastrarMedico();
            break;
        case 3:
            printf("Lista de Pacientes: \n");
            // Função listar pacientes
            printf("Deseja Listar Paciente em ordem de 1-nome, 2-idade, 3-prioridade? ");
            int aux;
            scanf("%d", &aux);
            switch (aux)
            {
            case 1: // nome
                /* code */
                break;
            case 2: // idade
                break;
            case 3: // prioridade
                bubbleSortPrioridadeCrescente(novoPaciente, quant_paciente);
                for (int i = 0; i < quant_paciente; i++)
                {
                    printf("Prioridade: %d. Paciente: %s \n",novoPaciente->prioridade, novoPaciente->nome);
                }
                
                break;

            default:
                break;
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
        case 0:
            printf("Saindo do sistema\n");
            exit(0);
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);

    return 0;
}
