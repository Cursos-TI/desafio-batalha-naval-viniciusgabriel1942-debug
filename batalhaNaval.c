#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int navioH[TAM_NAVIO] = {3, 3, 3}; // Navio horizontal
    int navioV[TAM_NAVIO] = {3, 3, 3}; // Navio vertical

    // 1. Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir coordenadas iniciais
    int linhaH = 2, colunaH = 4; // navio horizontal (linha 2, colunas 4 a 6)
    int linhaV = 5, colunaV = 7; // navio vertical (colunas 7, linhas 5 a 7)

    // 3. Posicionar o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    // 4. Posicionar o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    // 5. Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
