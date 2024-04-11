/*Considere um programa de cadastro (de produtos, clientes, veículos, etc) que contém, no mínimo, 10 registros alocados de forma estática na memória. Cada registro deve conter, no mínimo, três variáveis. O programa deve exibir um menu de opções ao usuário, com as seguintes funcionalidades:

Cadastrar um novo item

Listar por nome em ordem crescente

Listar por valor ou quantidade em ordem crescente

Listar por valor ou quantidade em ordem decrescente

Excluir um item*/

#include <stdio.h>
#include <string.h>
#define TAM 15
#define TAM_CHAR 50

typedef struct
{
    char nome[TAM_CHAR];
    int idade;
    int semestre;
} ALUNOS;

int particao(ALUNOS vet[], int inicio, int fim) {
    ALUNOS pivo = vet[(inicio + fim) / 2];
    int a = inicio - 1;
    int b = fim + 1;

    while (1) {
        do {
            a++;
        } while (strcmp(vet[a].nome, pivo.nome) < 0);

        do {
            b--;
        } while (strcmp(vet[b].nome, pivo.nome) > 0);

        if (a >= b)
            return b;

        // Troca os elementos
        ALUNOS temp = vet[a];
        vet[a] = vet[b];
        vet[b] = temp;
    }
}

void quickSort(ALUNOS vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = particao(vet, inicio, fim);
        quickSort(vet, inicio, meio);
        quickSort(vet, meio + 1, fim);
    }
}

void bubbleSortIdadeDecrescente(ALUNOS v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j].idade < v[j + 1].idade)
            {
                // trocar idades
                int aux = v[j].idade;
                v[j].idade = v[j + 1].idade;
                v[j + 1].idade = aux;

                // trocar semestres correspondente a idade
                aux = v[j].semestre;
                v[j].semestre = v[j + 1].semestre;
                v[j + 1].semestre = aux;

                // troca nomes correspondentes a idade
                char auxc[TAM_CHAR];
                strcpy(auxc, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, auxc);
            }
        }
    }
}

void bubbleSortSemestreCrescente(ALUNOS v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j].semestre > v[j + 1].semestre)
            {
                // trocar semestres
                int aux = v[j].semestre;
                v[j].semestre = v[j + 1].semestre;
                v[j + 1].semestre = aux;

                // trocar idades correspondente a semestres
                aux = v[j].idade;
                v[j].idade = v[j + 1].idade;
                v[j + 1].idade = aux;

                // troca nomes correspondentes a semestre
                char auxc[TAM_CHAR];
                strcpy(auxc, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, auxc);
            }
        }
    }
}

void bubbleSortNomes(ALUNOS f[], int tam)
{
    int ret;
    char palavra1[TAM_CHAR], palavra2[TAM_CHAR];
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            strcpy(palavra1, f[j].nome);
            strcpy(palavra2, f[j + 1].nome);
            ret = strcmp(palavra1, palavra2);
            if (ret > 0)
            {
                char auxc[TAM_CHAR];
                strcpy(auxc, f[j].nome);
                strcpy(f[j].nome, f[j + 1].nome);
                strcpy(f[j + 1].nome, auxc);

                // trocar idades corresponte a nome
                int aux = f[j].idade;
                f[j].idade = f[j + 1].idade;
                f[j + 1].idade = aux;

                // trocar semestres correspondente a nome
                aux = f[j].semestre;
                f[j].semestre = f[j + 1].semestre;
                f[j + 1].semestre = aux;
            }
        }
    }
}

void bubbleSortIdadeCrescente(ALUNOS v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j].idade > v[j + 1].idade)
            {
                // trocar idades
                int aux = v[j].idade;
                v[j].idade = v[j + 1].idade;
                v[j + 1].idade = aux;

                // trocar semestres correspondente a idade
                aux = v[j].semestre;
                v[j].semestre = v[j + 1].semestre;
                v[j + 1].semestre = aux;

                // troca nomes correspondentes a idade
                char auxc[TAM_CHAR];
                strcpy(auxc, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, auxc);
            }
        }
    }
}

void bubbleSortSemestreDecrescente(ALUNOS v[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j].semestre < v[j + 1].semestre)
            {
                // trocar semestres
                int aux = v[j].semestre;
                v[j].semestre = v[j + 1].semestre;
                v[j + 1].semestre = aux;

                // trocar idades correspondente a semestres
                aux = v[j].idade;
                v[j].idade = v[j + 1].idade;
                v[j + 1].idade = aux;

                // troca nomes correspondentes a semestre
                char auxc[TAM_CHAR];
                strcpy(auxc, v[j].nome);
                strcpy(v[j].nome, v[j + 1].nome);
                strcpy(v[j + 1].nome, auxc);
            }
        }
    }
}

void excluir_produtos(ALUNOS p[], int pos_exc, int *pos)
{
    for (int i = pos_exc; i < *pos - 1; i++)
    {
        p[i] = p[i + 1];
    }
    (*pos)--;
    printf("produto excluido com sucesso\n");
}

void adicionar(ALUNOS *FAENG)
{
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    gets(FAENG->nome);
    printf("Digite a idade: ");
    scanf("%d", &FAENG->idade);
    printf("Digite o semestre: ");
    scanf("%d", &FAENG->semestre);
}

int main(void)
{
    ALUNOS FAENG[TAM];
    int iTamanho = 10, opc, escolha;

    strcpy(FAENG[0].nome, "Brenda Olegario");
    strcpy(FAENG[1].nome, "Nicolly Lagassi");
    strcpy(FAENG[2].nome, "Nayelly Cristina");
    strcpy(FAENG[3].nome, "Vitoria Paula");
    strcpy(FAENG[4].nome, "Gabrieli Garanhani");
    strcpy(FAENG[5].nome, "Jeasmine Megan");
    strcpy(FAENG[6].nome, "Katriely Piedade");
    strcpy(FAENG[7].nome, "Thaliny de Paula");
    strcpy(FAENG[8].nome, "Vitor Rafael");
    strcpy(FAENG[9].nome, "Raissa Irma");

    FAENG[0].idade = 33;
    FAENG[1].idade = 29;
    FAENG[2].idade = 25;
    FAENG[3].idade = 18;
    FAENG[4].idade = 19;
    FAENG[5].idade = 37;
    FAENG[6].idade = 45;
    FAENG[7].idade = 46;
    FAENG[8].idade = 56;
    FAENG[9].idade = 17;

    FAENG[0].semestre = 3;
    FAENG[1].semestre = 9;
    FAENG[2].semestre = 5;
    FAENG[3].semestre = 8;
    FAENG[4].semestre = 9;
    FAENG[5].semestre = 7;
    FAENG[6].semestre = 5;
    FAENG[7].semestre = 4;
    FAENG[8].semestre = 6;
    FAENG[9].semestre = 1;

    do
    {
        printf("-1 - Sair\n");
        printf("1 - Cadastrar novo item\n");
        printf("2 - Listar por nome em ordem crescente\n");
        printf("3 - Listar por idade ou semestre em ordem crescente\n");
        printf("4 - Listar por idade ou semestre em ordem decrescente\n");
        printf("5 - Excluir um item\n");
        printf("6 - Ordenar quick por nome: ");

        scanf("%d", &opc);

        switch (opc)
        {
        case -1:
            printf("Tchau!");
            break;
        case 1: // CADASTRAR NOVO ITEM
            if (iTamanho < TAM)
            {
                adicionar(&FAENG[iTamanho]);
                iTamanho++;
            }
            else
            {
                printf("O Vetor esta cheio\n");
            }
            break;
        case 2: // lISTAR POR NOME EM ORDEM CRESCENTE
            bubbleSortNomes(FAENG, iTamanho);
            break;
        case 3: // LISTAR IDADE OU SEMESTRE EM ORDEM CRESCENTE
            printf("1-Idade ou 2-Semestre?\n");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1: // IDADE
                bubbleSortIdadeCrescente(FAENG, iTamanho);
                break;
            case 2: // SEMESTRE
                bubbleSortSemestreCrescente(FAENG, iTamanho);
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }
            break;
        case 4: // LISTAR IDADE OU SEMESTRE EM ORDEM DESCRESCENTE
            printf("1-Idade ou 2-Semestre?\n");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1: // IDADE
                bubbleSortIdadeDecrescente(FAENG, iTamanho);
                break;
            case 2: // SEMESTRE
                bubbleSortSemestreDecrescente(FAENG, 10);
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }

            break;
        case 5: // EXCLUIR ITEM
            printf("Qual posicao gostaria de excluir? ");
            scanf("%d", &escolha);
            if (escolha < iTamanho) // quer dizer q existe esse produto catalogado
            {
                excluir_produtos(FAENG, escolha, &iTamanho);
            }
            else
            {
                printf("indice invalido\n");
            }
            break;
        case 6:
            quickSort(FAENG, 0, iTamanho - 1);
            exibir(FAENG, iTamanho);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
        for (int i = 0; i < iTamanho; i++)
        {
            printf("posicao [%d], Nome: %s, Idade: %d, Semestre: %d\n", i, FAENG[i].nome, FAENG[i].idade, FAENG[i].semestre);
        }
    } while (opc != -1);
    return 0;
}
