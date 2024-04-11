#include "funcoes.h"

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

/*void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int v[], int tam){
    for (int i = 0; i < tam - 1; i++){
        bool trocou = false;
        for (int j = 0; j < tam - i - 1; j++){
            if (v[j] > v[j + 1]){
                trocar(&v[j], &v[j+1]); 
                trocou = true;
            }
        }
        if(!trocou) break;
    }
}*/

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
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &op);
        getchar(); // Limpa o buffer de entrada após o scanf
        switch (op)
        {
        case 1: // CADASTRO
            printf("1 - Cadastrar paciente\n");
            printf("2 - Cadastrar medico\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1:
                novoPaciente = realloc(novoPaciente, (qtdePacientes + 1) * sizeof(PACIENTE));
                novoPaciente[qtdePacientes] = *cadastrarPaciente();
                qtdePacientes++; // CORRIGIR
                break;
            case 2:
                novoMedico = realloc(novoMedico, (qtdeMedicos + 1) * sizeof(MEDICO));
                novoMedico[qtdeMedicos] = *cadastrarMedico();
                qtdeMedicos++; // CORRIGIR
                break;
            default:
                break;
            }
            break;
        case 2: // LISTAGEM
            printf("1 - Listar Paciente\n");
            printf("2 - Listar Médico\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1:
                // qsort(novoPaciente, qtdePacientes, sizeof(PACIENTE), compararPacientes); VERIFICAR!!!!!
                listarPacientes(novoPaciente, qtdePacientes);
                break;
            case 2:
                // qsort(novoMedico, qtdeMedicos, sizeof(MEDICO), compararMedicos);
                listarMedicos(novoMedico, qtdeMedicos);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            break;

        case 3: // GERENCIAR ATENDIMENTOS
            printf("1 - Realizar atendimento\n");
            printf("2 - Listar atendimento\n");
            printf("3 - Finalizar atendimento\n");
            printf("4 - Editar dados de atendimento\n");
            printf("Digite uma opcao: ");
            scanf("%d", &aux_opc);

            switch (aux_opc)
            {
            case 1:
                consulta(novoPaciente, qtdePacientes, novoMedico, qtdeMedicos, &atendimentos);
                break;
            case 2:
                listarAtendimentos(&atendimentos);
                break;
            case 3:
                encerrarConsulta(&atendimentos);
                break;
            case 4://ALTERAR
                printf("\nQual destes tipos de dados vc quer alterar:\n");
                printf("1 - Editar Motivo da Consulta e Prioridade.\n");
                printf("2 - Editar Consulta já agendado com médico.\n");
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
        case 4: //ARQUIVOS
            printf("1 - Salvar em Arquivo\n");
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
        case 5://ordenacao
            printf("1 - Ordenar por Prioridade Crescente\n");
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
                //quickSortMotivo(&atendimentos, );
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            listarAtendimentos(&atendimentos);
            break;
        case 0:
            printf("Saindo do sistema\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);
    free(novoPaciente);
    free(novoMedico);

    // Libere também a memória utilizada pela lista de atendimentos
    ITEM *atual = atendimentos.inicio;
    while (atual != NULL)
    {
        ITEM *temp = atual;
        atual = atual->prox;
        free(temp->chave); // Libera o atendimento
        free(temp);        // Libera o item da lista
    }
    return 0;
}