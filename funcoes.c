#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

char quadro[LINHAS][COLUNAS];

void inicializar_quadro()
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            quadro[i][j] = ' ';
        }
    }
}

void desenhar_bordas()
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (i == 0 || i == LINHAS - 1)
            {
                quadro[i][j] = '-'; // primeira e última linha
            }
            else if (j == 0 || j == COLUNAS - 1)
            {
                quadro[i][j] = '|'; // primeira e última coluna
            }
            else
            {
                quadro[i][j] = ' '; // espaço dentro do quadro
            }
        }
    }
}

void imprimir_quadro()
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            putchar(quadro[i][j]);
        }
        putchar('\n');
    }
}

void exibir_menu()
{

    int escolha;

    printf("PROGRAMA GERADOR DE OBRA DE ARTE: \n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra: \n");

    switch (escolha)
    {
    case 1:
        printf("*");
        break;

    default:
        break;
    }
}