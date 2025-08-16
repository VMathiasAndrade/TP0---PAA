#ifndef FUNCOES_H
#define FUNCOES_H

#define LINHAS 20
#define COLUNAS 80

extern char quadro[LINHAS][COLUNAS];

void inicializar_quadro();
void desenhar_bordas();
void imprimir_quadro();
void desenho_simples(int linha, int col);
void desenho_soma(int linha, int col);
void desenho_x(int linha, int col);

#endif
