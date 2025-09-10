#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HAB 5  // tamanho fixo das matrizes de habilidade

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                // Garantir que está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    // Só marca habilidade se não for navio (3)
                    if (tabuleiro[linhaTab][colunaTab] == 0) {
                        tabuleiro[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // === NAVIOS ===
    // Navio Horizontal
    int linhaH = 2, colunaH = 4;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio Vertical
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio Diagonal Principal ↘
    int linhaD1 = 0, colunaD1 = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio Diagonal Secundária ↙
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // === MATRIZES DE HABILIDADE ===
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    int centro = TAM_HAB / 2;

    // Cone (triângulo apontando para baixo)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= centro - i && j <= centro + i && i <= centro) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro (losango baseado em distância Manhattan)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // === APLICAR HABILIDADES AO TABULEIRO ===
    aplicarHabilidade(tabuleiro, cone, 1, 1);      // Cone em (1,1)
    aplicarHabilidade(tabuleiro, cruz, 4, 4);      // Cruz em (4,4)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);  // Octaedro em (7,2)

    // === EXIBIR TABULEIRO ===
    printf("=== TABULEIRO BATALHA NAVAL COM HABILIDADES ===\n\n");

    // Cabeçalho (colunas)
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // índice da linha
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" . ");  // água
            else if (tabuleiro[i][j] == 3)
                printf(" N ");  // navio
            else if (tabuleiro[i][j] == 5)
                printf(" * ");  // habilidade
        }
        printf("\n");
    }

    return 0;
}