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
                quadro[i][j] = '-';
            }
            else if (j == 0 || j == COLUNAS - 1)
            {
                quadro[i][j] = '|';
            }
            else
            {
                quadro[i][j] = ' ';
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

void desenho_simples(int linha, int col)
{
    if (linha > 0 && linha < LINHAS - 1 && col > 0 && col < COLUNAS - 1)
    {
        quadro[linha][col] = '*';
    }
}

void desenho_soma(int linha, int col)
{
    if (linha > 0 && linha < LINHAS - 1 && col > 0 && col < COLUNAS - 1)
    {
        quadro[linha][col + 1] = '*';
        quadro[linha + 1][col] = '*';
        quadro[linha + 1][col + 1] = '*';
        quadro[linha + 1][col + 2] = '*';
        quadro[linha + 2][col + 1] = '*';
    }
}

void desenho_x(int linha, int col)
{
    if (linha > 0 && linha < LINHAS - 1 && col > 0 && col < COLUNAS - 1)
    {
        quadro[linha][col] = '*';
        quadro[linha][col + 2] = '*';
        quadro[linha + 1][col + 1] = '*';
        quadro[linha + 2][col] = '*';
        quadro[linha + 2][col + 2] = '*';
    }
}

void LetraJ(int linha, int col)
{
    if (linha >= 1 && linha <= LINHAS - 4 && col >= 1 && col <= COLUNAS - 4)
    {
        quadro[linha][col] = '*';
        quadro[linha][col + 1] = '*';
        quadro[linha][col + 2] = '*';
        quadro[linha + 1][col + 2] = '*';
        quadro[linha + 2][col] = '*';
        quadro[linha + 2][col + 2] = '*';
    }
}

int VerificaArea(int linha, int col, int tipo)
{
    switch (tipo)
    {
    case 1:
        if (linha >= 1 && linha < LINHAS - 1 && col >= 1 && col < COLUNAS - 1)
            return (quadro[linha][col] == ' ') ? 1 : 0;
        break;

    case 2:
        if (linha >= 1 && linha < LINHAS - 3 && col >= 1 && col < COLUNAS - 3)
        {
            if (quadro[linha][col + 1] == ' ' &&
                quadro[linha + 1][col] == ' ' &&
                quadro[linha + 1][col + 1] == ' ' &&
                quadro[linha + 1][col + 2] == ' ' &&
                quadro[linha + 2][col + 1] == ' ')
                return 1;
        }
        break;

    case 3:
        if (linha >= 1 && linha < LINHAS - 3 && col >= 1 && col < COLUNAS - 3)
        {
            if (quadro[linha][col] == ' ' &&
                quadro[linha][col + 2] == ' ' &&
                quadro[linha + 1][col + 1] == ' ' &&
                quadro[linha + 2][col] == ' ' &&
                quadro[linha + 2][col + 2] == ' ')
                return 1;
        }
        break;

    case 5:
        if (linha >= 1 && linha < LINHAS - 3 && col >= 1 && col < COLUNAS - 3)
        {
            if (quadro[linha][col] == ' ' &&
                quadro[linha][col + 1] == ' ' &&
                quadro[linha][col + 2] == ' ' &&
                quadro[linha + 1][col + 2] == ' ' &&
                quadro[linha + 2][col] == ' ' &&
                quadro[linha + 2][col + 2] == ' ')
                return 1;
        }
        break;
    }
    return 0;
}
