#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

#define LINHAS 20
#define COLUNAS 80

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
    printf("5 ou qualquer outro numero - opcao criada pelo aluno\n");
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
    imprimir_quadro();

    return 0;
}