#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main()
{
    int tipo, qtd;
    printf("PROGRAMA GERADOR DE OBRA DE ARTE: \n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra: \n");
    printf("1 - asterisco simples\n");
    printf("2 - simbolo de soma com asteriscos\n");
    printf("3 - letra X com asteriscos\n");
    printf("4 - figuras aleatorias\n");
    printf("5 ou qualquer outro numero - Estrela de Davi\n");
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
    printf("\nValores escolhidos: tipo = %d | quantidade = %d\n", tipo, qtd);

    inicializar_quadro();
    desenhar_bordas();

    srand(time(NULL));
    int figuras_colocadas = 0;

    // Para cada figura
    for (int i = 0; i < qtd; i++)
    {
        int tentativas = 0;
        int figura_desenhada = 0;

        // Repetir até desenhar a figura ou desistir
        while (!figura_desenhada && tentativas <= 100)
        {
            int linha, col, tipo_figura;

            // Determina o tipo de figura a ser desenhada
            if (tipo == 4)
            {
                int aleatorio = rand() % 4 + 1; // 1, 2, 3 ou 4 para figuras aleatórias
                if (aleatorio == 4)
                {
                    tipo_figura = 5; // Estrela de Davi
                }
                else
                {
                    tipo_figura = aleatorio; // 1, 2 ou 3
                }
            }
            else
            {
                tipo_figura = tipo;
            }

            // Gerar posição aleatória baseada no tipo de figura
            switch (tipo_figura)
            {
            case 1:                                // Asterisco simples
                linha = rand() % (LINHAS - 2) + 1; // Entre 1 e 18
                col = rand() % (COLUNAS - 2) + 1;  // Entre 1 e 78
                break;

            case 2:                                // Símbolo de soma
                linha = rand() % (LINHAS - 4) + 1; // Entre 1 e 16
                col = rand() % (COLUNAS - 4) + 1;  // Entre 1 e 76
                break;

            case 3:                                // Letra X
                linha = rand() % (LINHAS - 4) + 1; // Entre 1 e 16
                col = rand() % (COLUNAS - 4) + 1;  // Entre 1 e 76
                break;

            case 5: // Estrela de Davi
            default:
                linha = rand() % (LINHAS - 6) + 1; // Entre 1 e 14
                col = rand() % (COLUNAS - 8) + 1;  // Entre 1 e 72
                tipo_figura = 5;
                break;
            }

            // Se área está livre
            if (VerificaArea(linha, col, tipo_figura))
            {
                // Desenhar figura
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
                    EstrelaDeDavi(linha, col);
                    break;
                }
                figura_desenhada = 1; // Sair do loop
                figuras_colocadas++;
            }
            else
            {
                // Senão: tentativas++
                tentativas++;
            }

            // Se tentativas > 100: desistir desta figura
            if (tentativas > 100)
            {
                break; // Desiste desta figura e vai para a próxima
            }
        }
    }

    printf("Figuras colocadas com sucesso: %d de %d solicitadas\n", figuras_colocadas, qtd);

    imprimir_quadro();
    return 0;
}