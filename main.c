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

// Inicializa a lista
void inicializa(LISTA *l)
{
    l->inicio = NULL;
    l->qtde = 0;
}

// Insere um elemento na lista
void inserir(LISTA *l, void *chave)
{
    ITEM *novoItem = (ITEM *)malloc(sizeof(ITEM));
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

// Função para listar pacientes cadastrados
void listarPacientes(PACIENTE *p, int quantidade)
{
    if (p == NULL || quantidade == 0)
    {
        printf("Nenhum paciente cadastrado!\n");
        return;
    }

    printf("\nPacientes Cadastrados: \n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome: %s\n", p[i].nome);
        printf("Idade: %d\n", p[i].idade);
        printf("\n");
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

    printf("\nCADASTRO DE MEDICO\n");
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

    // Se os nomes são iguais, compare as especialidades
    return strcmp(medicoA->especialidade, medicoB->especialidade);
}

// Função para listar os médicos cadastrados
void listarMedicos(MEDICO *m, int quantidade)
{
    if (m == NULL || quantidade == 0)
    {
        printf("Nenhum medico cadastrado!\n");
        return;
    }

    printf("\nMedicos Cadastrados:\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome: %s\n", m[i].nome);
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
    char especialidade[50];
    int prioridade, opPaciente, opMedico;

    printf("\nRealizar atendimento\n");

    printf("\nPacientes cadastrados:\n");
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

    // Listar médicos cadastrados
    printf("Medicos cadastrados:\n");
    for (int i = 0; i < qtdeM; i++)
    {
        printf("%d - %s - %s\n", i + 1, m[i].nome, m[i].especialidade);
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

    printf("Motivo da consulta: ");
    fgets(motivo, sizeof(motivo), stdin);
    motivo[strcspn(motivo, "\n")] = '\0';

    printf("Prioridade (1 - Leve, 2 - Moderada, 3 - Grave): ");
    scanf("%d", &prioridade);
    getchar();

    //inicia um novo atendimento
    ATENDIMENTO *novo = (ATENDIMENTO *)malloc(sizeof(ATENDIMENTO));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    // Alocar memória para um novo paciente e copia os dados
    novo->paciente = (PACIENTE *)malloc(sizeof(PACIENTE));
    if (novo->paciente == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        free(novo);
        return;
    }

    memcpy(novo->paciente, &p[opPaciente - 1], sizeof(PACIENTE)); //copia os dados do paciente para o novo atendimento
    
    novo->medico = (MEDICO *)malloc(sizeof(MEDICO));
    if (novo->medico == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    // Copia os dados do médico selecionado para a estrutura alocada dinamicamente
    strcpy(novo->medico->nome, m[opMedico - 1].nome);
    strcpy(novo->medico->especialidade, m[opMedico - 1].especialidade);

    strcpy(novo->motivo, motivo);
    novo->prioridade = prioridade;

    //insere o atendimento na lista
    inserir(l, novo);

    // exibe as informações do atendimento
    printf("Atendimento:\n");
    printf("Paciente: %s\n", paciente);
    printf("Medico: %s %s\n", medico, especialidade);
    printf("Motivo da consulta: %s\n", motivo);
    printf("Prioridade: %s\n", (prioridade == 1 ? "Leve" : (prioridade == 2 ? "Moderada" : "Grave")));
}

void bubbleSortPrioridadeCrescente(LISTA *l)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("Lista vazia ou nao inicializada!\n");
        return;
    }

    int trocado;
    ITEM *atual;
    ATENDIMENTO *atendimentoAtual;
    void *temp;

    do
    {
        trocado = 0;
        atual = l->inicio;

        while (atual->prox != NULL)
        {
            ATENDIMENTO *atendimentoAtual = (ATENDIMENTO *)atual->chave;
            ATENDIMENTO *atendimentoProx = (ATENDIMENTO *)atual->prox->chave;

            if (atendimentoAtual->prioridade > atendimentoProx->prioridade)
            {
                // Troca os elementos na lista
                temp = atual->chave;
                atual->chave = atual->prox->chave;
                atual->prox->chave = temp;

                trocado = 1;
            }

            atual = atual->prox;
        }
    } while (trocado);
}

void bubbleSortMotivo(LISTA *l)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("Lista vazia ou nao inicializada!\n");
        return;
    }

    int trocado;
    ITEM *atual;
    void *temp;

    do
    {
        trocado = 0;
        atual = l->inicio;

        while (atual->prox != NULL)
        {
            ATENDIMENTO *atendimentoAtual = (ATENDIMENTO *)atual->chave;
            ATENDIMENTO *atendimentoProx = (ATENDIMENTO *)atual->prox->chave;

            if (strcmp(atendimentoAtual->motivo, atendimentoProx->motivo) > 0)
            {
                // Troca os elementos na lista
                temp = atual->chave;
                atual->chave = atual->prox->chave;
                atual->prox->chave = temp;

                trocado = 1;
            }

            atual = atual->prox;
        }
    } while (trocado);
}


void bubbleSortPrioridadeDecrescente(LISTA *l)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("Lista vazia ou nao inicializada!\n");
        return;
    }

    int trocado;
    ITEM *atual;
    ATENDIMENTO *atendimentoAtual;
    void *temp;

    do
    {
        trocado = 0;
        atual = l->inicio;

        while (atual->prox != NULL)
        {
            ATENDIMENTO *atendimentoAtual = (ATENDIMENTO *)atual->chave;
            ATENDIMENTO *atendimentoProx = (ATENDIMENTO *)atual->prox->chave;

            if (atendimentoAtual->prioridade < atendimentoProx->prioridade) // Alteração aqui
            {
                // Troca os elementos na lista
                temp = atual->chave;
                atual->chave = atual->prox->chave;
                atual->prox->chave = temp;

                trocado = 1;
            }

            atual = atual->prox;
        }
    } while (trocado);
}

void listarAtendimentos(LISTA *l)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("Nenhum atendimento realizado ainda!\n");
        return;
    }

    printf("\nLista de Atendimentos Realizados:\n");
    ITEM *atual = l->inicio;
    while (atual != NULL)
    {
        ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;
        if (atendimento != NULL)
        {
            printf("Paciente: %s\n", atendimento->paciente->nome); // Agora acessa a cópia independente do paciente
            printf("Medico: %s\n", atendimento->medico->nome);
            printf("Especialidade: %s\n", atendimento->medico->especialidade);
            printf("Motivo: %s\n", atendimento->motivo);
            printf("Prioridade: %s\n", (atendimento->prioridade == 1 ? "Leve" : (atendimento->prioridade == 2 ? "Moderada" : "Grave")));
            printf("\n");
            atual = atual->prox;
        }
    }
}

void editarAtendimento(LISTA *atendimentos)
{
    int id;
    printf("Digite o ID do atendimento que deseja editar: ");
    scanf("%d", &id);
    getchar(); // Limpa o buffer

    if (id < 1 || id > atendimentos->qtde)
    {
        printf("ID inválido!\n");
        return;
    }

    // Encontre o atendimento correspondente na lista
    ITEM *atual = atendimentos->inicio;
    for (int i = 1; i < id; i++)
    {
        atual = atual->prox;
    }

    ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;

    printf("Motivo atual: %s\n", atendimento->motivo);
    printf("Digite o novo motivo: ");
    fgets(atendimento->motivo, sizeof(atendimento->motivo), stdin);
    atendimento->motivo[strcspn(atendimento->motivo, "\n")] = '\0';

    printf("Prioridade atual: %d\n", atendimento->prioridade);
    printf("Digite a nova prioridade: ");
    scanf("%d", &atendimento->prioridade);
    getchar(); // Limpa o buffer
}

void alterarMedicoAtendimento(LISTA *atendimentos, MEDICO *medicos, int qtdeMedicos)
{
    if (atendimentos == NULL || atendimentos->inicio == NULL)
    {
        printf("Nenhum atendimento cadastrado!\n");
        return;
    }

    // Exibe todos os atendimentos para o usuário escolher
    printf("Atendimentos:\n");
    ITEM *atual = atendimentos->inicio;
    for (int i = 1; i <= atendimentos->qtde; i++)
    {
        ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;
        printf("%d - Paciente: %s, Medico: %s\n", i, atendimento->paciente->nome, atendimento->medico->nome);
        atual = atual->prox;
    }

    printf("Digite o número do atendimento que deseja alterar o medico: ");
    int id;
    scanf("%d", &id);
    getchar(); // Limpa o buffer

    if (id < 1 || id > atendimentos->qtde)
    {
        printf("Número de atendimento inválido!\n");
        return;
    }

    // Encontre o atendimento correspondente na lista
    atual = atendimentos->inicio;
    for (int i = 1; i < id; i++)
    {
        atual = atual->prox;
    }

    ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;

    // Exibe todos os médicos para o usuário escolher
    printf("Medicos:\n");
    for (int i = 0; i < qtdeMedicos; i++)
    {
        printf("%d - Nome: %s, Especialidade: %s\n", i + 1, medicos[i].nome, medicos[i].especialidade);
    }

    printf("Digite o número do novo medico: ");
    int idMedico;
    scanf("%d", &idMedico);
    getchar(); // Limpa o buffer

    if (idMedico < 1 || idMedico > qtdeMedicos)
    {
        printf("Número de medico inválido!\n");
        return;
    }

    atendimento->medico = &medicos[idMedico - 1];
    printf("O medico do atendimento foi alterado com sucesso!\n");
}

void encerrarConsulta(LISTA *atendimentos)
{
    int id;
    printf("Digite o ID do atendimento que deseja encerrar: ");
    scanf("%d", &id);
    getchar(); // Limpa o buffer

    if (id < 1 || id > atendimentos->qtde)
    {
        printf("ID inválido!\n");
        return;
    }

    // Encontre o atendimento correspondente na lista
    ITEM *atual = atendimentos->inicio;
    ITEM *anterior = NULL;
    for (int i = 1; i < id; i++)
    {
        anterior = atual;
        atual = atual->prox;
    }

    // Remova o atendimento da lista
    if (anterior == NULL)
    {
        atendimentos->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    // Libere a memória alocada para o atendimento
    free(atual->chave);
    free(atual);

    atendimentos->qtde--;

    printf("Atendimento encerrado com sucesso!\n");
}

void salvarAtendimentosEmArquivo(LISTA *atendimentos)
{
    FILE *arq = fopen("atendimentos.txt", "w"); // abre ou cria um arquivo txt para escrita.

    if (arq)
    {
        ITEM *atual = atendimentos->inicio;
        while (atual != NULL)
        {
            ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;
            fprintf(arq, "Paciente: %s\n", atendimento->paciente->nome);
            fprintf(arq, "Idade: %d\n", atendimento->paciente->idade);
            fprintf(arq, "Medico: %s\n", atendimento->medico->nome);
            fprintf(arq, "Especialidade: %s\n", atendimento->medico->especialidade);
            fprintf(arq, "Motivo: %s\n", atendimento->motivo);
            fprintf(arq, "Prioridade: %d\n\n", atendimento->prioridade);
            atual = atual->prox;
        }
        fclose(arq); // fecha o arquivo.
    }
    else
    {
        printf("ERRO: nao é possivel abrir o arquivo.");
    }
}

void imprimirConteudoDoArquivo(PACIENTE *novoPaciente)
{
    FILE *arq = fopen("atendimentos.txt", "r"); // Abre o arquivo em modo de leitura

    if (arq == NULL)
    {
        printf("ERRO: nao é possível abrir o arquivo.\n");
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

ITEM *buscaSequencialPrioridade(LISTA *atendimentos, int prioridade)
{
    if (atendimentos == NULL || atendimentos->inicio == NULL)
    {
        printf("Nenhum atendimento cadastrado!\n");
        return NULL;
    }

    ITEM *atual = atendimentos->inicio;
    while (atual != NULL)
    {
        ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;
        if (atendimento->prioridade == prioridade)
        {
            return atual;
        }
        atual = atual->prox;
    }

    printf("Atendimento com prioridade %d nao encontrado!\n", prioridade);
    return NULL;
}

ITEM *buscaSequencialMotivo(LISTA *atendimento, const char *motivo) 
{
    if (atendimento == NULL || atendimento->inicio == NULL)
    {
        printf("Nenhum atendimento cadastrado!\n");
        return NULL;
    }
    
    ITEM *atual = atendimento->inicio;
    while (atual != NULL)
    {
        ATENDIMENTO *atendimento = (ATENDIMENTO *)atual->chave;
        if (strcmp(atendimento->motivo, motivo) == 0)
        {
            return atual;
        }
        atual = atual->prox;
    }
    
    printf("Atendimento com o motivo '%s' nao encontrado no sistema!\n", motivo);
    return NULL;
}

// Libera a memória alocada para a lista de atendimentos
void liberarLista(LISTA *l)
{
    if (l == NULL)
        return;

    ITEM *atendimentoAtual = l->inicio;
    while (atendimentoAtual != NULL)
    {
        ATENDIMENTO *atendimento = (ATENDIMENTO *)atendimentoAtual->chave;
        free(atendimento->paciente); // Liberar a memória do paciente
        free(atendimento);           // Liberar o próprio atendimento
        ITEM *prox = atendimentoAtual->prox;
        free(atendimentoAtual); // Liberar o nó da lista
        atendimentoAtual = prox;
    }

    l->inicio = NULL;
    l->qtde = 0;
}

int main()
{
    LISTA atendimentos;
    inicializa(&atendimentos);

    PACIENTE *novoPaciente = NULL;
    MEDICO *novoMedico = NULL;

    int qtdePacientes = 0;
    int qtdeMedicos = 0;
    int op, aux_opc, aux_opc_edit;


    do
    {
        printf("\nSISTEMA DE PRONTO ATENDIMENTO\n");
        printf("1 - Cadastrar paciente/medico\n");
        printf("2 - Listar pacientes/medico\n");
        printf("3 - Gerenciar Atendimentos\n");
        printf("4 - Salvar ou Ler Arquivo\n");
        printf("5 - Ordenar atendimento\n");
        printf("6 - Busca\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &op);
        getchar(); // Limpa o buffer de entrada após o scanf

        switch (op)
        {
        case 1: //CADASTRO
            printf("1 - Cadastrar paciente\n");
            printf("2 - Cadastrar medico\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);
            getchar(); // Limpa o buffer

            switch (aux_opc)
            {
            case 1:
                // Cadastrar paciente
                if (qtdePacientes == 0)
                    novoPaciente = (PACIENTE *)malloc(sizeof(PACIENTE));
                else
                    novoPaciente = (PACIENTE *)realloc(novoPaciente, (qtdePacientes + 1) * sizeof(PACIENTE));
                if (novoPaciente == NULL)
                {
                    printf("Erro ao alocar memoria!\n");
                    break;
                }
                novoPaciente[qtdePacientes++] = *cadastrarPaciente();
                break;
            case 2:
                // Cadastrar médico
                if (qtdeMedicos == 0)
                    novoMedico = (MEDICO *)malloc(sizeof(MEDICO));
                else
                    novoMedico = (MEDICO *)realloc(novoMedico, (qtdeMedicos + 1) * sizeof(MEDICO));
                if (novoMedico == NULL)
                {
                    printf("Erro ao alocar memoria!\n");
                    break;
                }
                novoMedico[qtdeMedicos++] = *cadastrarMedico();
                break;
            default:
                break;
            }
            break;
        case 2: // LISTAGEM
            printf("\n1 - Listar Paciente\n");
            printf("2 - Listar Medico\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1:
                listarPacientes(novoPaciente, qtdePacientes);
                break;
            case 2:
                listarMedicos(novoMedico, qtdeMedicos);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            break;
        case 3: // GERENCIAR ATENDIMENTOS
            printf("\n1 - Realizar atendimento\n");
            printf("2 - Listar atendimento\n");
            printf("3 - Finalizar atendimento\n");
            printf("4 - Editar dados de atendimento\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1: //realiza atendimento
                consulta(novoPaciente, qtdePacientes, novoMedico, qtdeMedicos, &atendimentos);
                break;
            case 2:
                listarAtendimentos(&atendimentos);
                break;
            case 3:
                encerrarConsulta(&atendimentos);
                break;
            case 4: // ALTERAR
                printf("\nQual destes tipos de dados vc quer alterar:\n");
                printf("1 - Editar Motivo da Consulta e Prioridade.\n");
                printf("2 - Editar Consulta já agendado com medico.\n");
                printf("Digite uma opcao: ");
                scanf("%d", &aux_opc_edit);
                switch (aux_opc_edit)
                {
                case 1:
                    editarAtendimento(&atendimentos);
                    break;
                case 2:
                    alterarMedicoAtendimento(&atendimentos, novoMedico, qtdeMedicos);
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
                }
            default:
                printf("Opcao invalida\n");
                break;
            }
            break;
        case 4: // ARQUIVOS
            printf("\n1 - Salvar em Arquivo\n");
            printf("2 - Ler este Arquivo\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1:
                salvarAtendimentosEmArquivo(&atendimentos);
                break;
            case 2:
                imprimirConteudoDoArquivo(novoPaciente);
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }
            break;
        case 5: // ordenacao
            printf("\n1 - Ordenar por Prioridade Crescente\n");
            printf("2 - Ordenada por Prioridade Decrescente.\n");
            printf("3 - Ordenar por Motivo alfabeticamente.\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);
            switch (aux_opc)
            {
            case 1:
                bubbleSortPrioridadeCrescente(&atendimentos);
                break;
            case 2:
                bubbleSortPrioridadeDecrescente(&atendimentos);
                break;
            case 3:
                bubbleSortMotivo(&atendimentos);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            listarAtendimentos(&atendimentos);
            break;
        case 6:
            printf("\n1 - Busca sequencial por prioridade\n");
            printf("2 - Busca sequencial por motivo da consulta\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1:
                printf("\nDigite a prioridade buscada: ");
                scanf("%d", &aux_opc_edit); // vou usar a msm variavel p/ economizar
                ITEM *auxil;
                auxil = buscaSequencialPrioridade(&atendimentos, aux_opc_edit);
                ATENDIMENTO *atendimento = (ATENDIMENTO *)auxil->chave;
                
                printf("O primeiro atendimento da lista da prioridade desejada\n");
                printf("\nPaciente: %s\n", atendimento->paciente->nome);
                printf("Medico: %s\t", atendimento->medico->nome);
                printf("Especialidade: %s\n", atendimento->medico->especialidade);
                printf("Motivo da consulta: %s\n", atendimento->motivo);
                printf("Prioridade: %s\n", (atendimento->prioridade == 1 ? "Leve" : (atendimento->prioridade == 2 ? "Moderada" : "Grave")));
                break;
            case 2:
                //busca sequencial pelo motivo da consulta
                getchar();
                printf("\nDigite o motivo da consulta a ser buscado: ");
                char motivo[50];
                fgets(motivo, sizeof(motivo), stdin);
                motivo[strcspn(motivo, "\n")] = '\0';
                auxil = buscaSequencialMotivo(&atendimentos, motivo);
                if (auxil != NULL)
                {
                    ATENDIMENTO *atendimento = (ATENDIMENTO *)auxil->chave;
                    printf("Atendimento encontrado por motivo: \n");
                    printf("\nPaciente: %s\n", atendimento->paciente->nome);
                    printf("Medico: %s\t", atendimento->medico->nome);
                    printf("Especialidade: %s\n", atendimento->medico->especialidade);
                    printf("Motivo da consulta: %s\n", atendimento->motivo);
                    printf("Prioridade: %s\n", (atendimento->prioridade == 1 ? "Leve" : (atendimento->prioridade == 2 ? "Moderada" : "Grave")));
                }
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
        case 0:
            // Sair do programa
            liberarLista(&atendimentos);
            free(novoPaciente);
            free(novoMedico);
            printf("Saindo do sistema\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while (op != 0);

    return 0;
}
