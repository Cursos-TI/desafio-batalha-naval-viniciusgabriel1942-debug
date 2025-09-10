#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // === NAVIOS ===
    // Navio 1 - Horizontal
    int linhaH = 2, colunaH = 4;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio 2 - Vertical
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio 3 - Diagonal principal (↘)
    int linhaD1 = 0, colunaD1 = 0; // começa no canto superior esquerdo
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio 4 - Diagonal secundária (↙)
    int linhaD2 = 0, colunaD2 = 9; // começa no canto superior direito
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // === EXIBIR TABULEIRO ===
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    // Índices das colunas
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // índice da linha
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
