// TARIFA = 10 REAIS POR HORA
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char placa[8];
    char marca[8];
    char modelo[8];
    char cor[8];
    int num_horas_estac;
} Estacionamento;

void entrada_veiculos(Estacionamento *Est)
{
    printf("Digite a placa: ");
    fflush(stdin);
    gets(Est->placa);
    printf("Digite a marca: ");
    fflush(stdin);
    gets(Est->marca);
    printf("Digite o modelo: ");
    fflush(stdin);
    gets(Est->modelo);
    printf("Digite a cor: ");
    fflush(stdin);
    gets(Est->cor);
    printf("Digite as horas estacionado: ");
    scanf("%d", &Est->num_horas_estac);
}

void calculo_custo(Estacionamento *Est)
{
    printf("Custo de %d horas: R$%.2f\n", Est->num_horas_estac, Est->num_horas_estac * 10.0);
}

void saida_carro(Estacionamento Est[], int *pos, int *pos_exc)
{
    for (int i = *pos_exc; i < *pos - 1; i++)
    {
        Est[i] = Est[i + 1];
    }
    (*pos)--;
    printf("carro excluido com sucesso\n");
}

void listar_produtos(Estacionamento Est[], int *pos)
{
    printf("\nLista de carros:\n");
    for (int i = 0; i < *pos; i++)
    {
        printf("%d. Placa:%s | Marca: %s| Modelo: %s | Cor: %s | Numero de horas estacionado:%d\n", i, Est[i].placa, Est[i].marca, Est[i].modelo, Est[i].cor, Est[i].num_horas_estac);
    }
}

int main(void)
{
    int pos = 0;
    int opcao;
    do
    {
        Estacionamento e[5];

        printf("\n-1 - sair\n");
        printf("1 - Entrada de veiculos\n");
        printf("2 - Custo do estacionamento pelas horas estacionadas (tarifa R$10,00 p/ hr)\n");
        printf("3 - Registrar a saida dos veiculos\n");
        printf("4 - Listagem de veiculos\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        int pos_aux;
        switch (opcao)
        {
        case 1:
            if (pos < 5)
            {
                entrada_veiculos(&e[pos]);
                pos++;
            }
            else
            {
                printf("O estacionamento esta cheio\n");
            }
            break;
        case 2:
            if (pos != 0) // se o inventario tem algum item
            {
                printf("Qual posicao gostaria de calcular o custo do estacionamento? ");
                scanf("%d", &pos_aux);
                if (pos_aux < pos) // quer dizer q existe esse produto catalogado
                {
                    calculo_custo(&e[pos_aux]);
                }
                else
                {
                    printf("indice invalido\n");
                }
            }
            else
            {
                printf("O estacionamento esta vazio\n");
            }
            break;
        case 3:
            if (pos != 0) // se o est tem algum item
            {
                printf("Qual carro ira sair? ");
                scanf("%d", &pos_aux);
                if (pos_aux < pos) // quer dizer q existe esse produto catalogado
                {
                    saida_carro(e, &pos, &pos_aux);
                }
                else
                {
                    printf("indice invalido\n");
                }
            }
            else
            {
                printf("O estacionamento esta vazio\n");
            }

            break;
        case 4:
            if (pos != 0)
            {
                listar_produtos(e, &pos);
            }
            else
            {
                printf("O estacionamento esta vazio\n");
            }
            break;
        case -1:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != -1);

    return 0;
}
