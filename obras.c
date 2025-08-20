#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main()
{
    int tipo, qtd;
    char refazer;

    printf("PROGRAMA GERADOR DE OBRA DE ARTE: \n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra: \n");
    printf("1 - asterisco simples\n");
    printf("2 - simbolo de soma com asteriscos\n");
    printf("3 - letra X com asteriscos\n");
    printf("4 - figuras aleatorias\n");
    printf("5 ou qualquer outro numero - Letra J\n");
    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", &tipo);

    printf("Digite a quantidade de figuras  (<= 0 para aleatorio): ");
    scanf("%d", &qtd);

    if (qtd <= 0)
    {
        srand(time(NULL));
        qtd = (rand() % 100) + 1;
    }
    else if (qtd > 100)
    {
        qtd = 100;
    }

    srand(time(NULL));

    do
    {
        printf("\nValores escolhidos: tipo = %d | quantidade = %d\n", tipo, qtd);

        inicializar_quadro();
        desenhar_bordas();

        int figuras_colocadas = 0;

        for (int i = 0; i < qtd; i++)
        {
            int tentativas = 0;
            int figura_desenhada = 0;

            while (!figura_desenhada && tentativas < 50)
            {
                int linha, col, tipo_figura;

                if (tipo == 4)
                {
                    int aleatorio = rand() % 4 + 1;
                    tipo_figura = (aleatorio == 4) ? 5 : aleatorio;
                }
                else
                {
                    tipo_figura = tipo;
                }

                switch (tipo_figura)
                {
                case 1:
                    linha = rand() % 18 + 1;
                    col = rand() % 78 + 1;
                    break;
                case 2:
                    linha = rand() % 16 + 2;
                    col = rand() % 76 + 2;
                    break;
                case 3:
                    linha = rand() % 16 + 2;
                    col = rand() % 76 + 2;
                    break;
                case 5:
                default:
                    linha = rand() % 16 + 2;
                    col = rand() % 76 + 2;
                    tipo_figura = 5;
                    break;
                }

                if (VerificaArea(linha, col, tipo_figura))
                {
                    switch (tipo_figura)
                    {
                    case 1:
                        desenho_simples(linha, col);
                        break;
                    case 2:
                        desenho_soma(linha, col);
                        break;
                    case 3:
                        desenho_x(linha, col);
                        break;
                    case 5:
                        LetraJ(linha, col);
                        break;
                    }
                    figura_desenhada = 1;
                    figuras_colocadas++;
                }
                else
                {
                    tentativas++;
                }
            }
        }

        printf("Figuras colocadas: %d de %d solicitadas\n", figuras_colocadas, qtd);

        imprimir_quadro();

        printf("\nDeseja gerar um novo quadro com os mesmos parametros? (s/n): ");
        scanf(" %c", &refazer);

    } while (refazer == 's' || refazer == 'S');

    printf("\nObrigado por usar o gerador de obras de arte!\n");
    return 0;
}
