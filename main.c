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

<<<<<<< HEAD
=======
typedef struct 
{
    PACIENTE *paciente;
    MEDICO *medico;
    char motivo[50];
    int prioridade;
} ATENDIMENTO;

>>>>>>> a70cd20090c27b37d37c2788f61b74ca2b44133b
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

<<<<<<< HEAD
=======
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
        printf("Idade: %s\n", p->idade);
    }
}

>>>>>>> a70cd20090c27b37d37c2788f61b74ca2b44133b
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

<<<<<<< HEAD
=======
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

    printf("Paciente Cadastrados:\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome: %s\n", p[i].nome);
        printf("Idade: %d\n", p[i].idade);
    }
}

>>>>>>> a70cd20090c27b37d37c2788f61b74ca2b44133b
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

<<<<<<< HEAD
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
=======
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
    MEDICO *novoMedico = NULL;
    int qtdePacientes = 0;
    int qtdeMedicos = 0;
    int op;

>>>>>>> a70cd20090c27b37d37c2788f61b74ca2b44133b
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
            novoPaciente = realloc(novoPaciente, (qtdePacientes + 1) * sizeof(PACIENTE));
            novoPaciente[qtdePacientes] = *cadastrarPaciente();
            qtdePacientes++;
            break;

<<<<<<< HEAD
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
=======
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
>>>>>>> a70cd20090c27b37d37c2788f61b74ca2b44133b
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
<<<<<<< HEAD
=======
        case 8:
            salvarEmArquivo(novoPaciente, qtdePacientes);
            break;
        case 9:
            imprimirConteudoDoArquivo(novoPaciente, qtdePacientes);
            break;
>>>>>>> a70cd20090c27b37d37c2788f61b74ca2b44133b
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
