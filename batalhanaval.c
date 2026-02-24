#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ==========================================
    // 1️⃣ Criando e inicializando o tabuleiro
    // ==========================================
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // 0 = água
        }
    }

    // ==========================================
    // 2️⃣ Definição das coordenadas iniciais
    // ==========================================

    // Navio Horizontal
    int linhaH = 1;
    int colunaH = 2;

    // Navio Vertical
    int linhaV = 4;
    int colunaV = 0;

    // Navio Diagonal Principal (↘)
    int linhaD1 = 0;
    int colunaD1 = 0;

    // Navio Diagonal Secundária (↙)
    int linhaD2 = 0;
    int colunaD2 = 9;

    // ==========================================
    // 3️⃣ Validação de limites
    // ==========================================

    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    if (linhaD1 + TAM_NAVIO > TAM || colunaD1 + TAM_NAVIO > TAM) {
        printf("Erro: Navio diagonal principal fora do tabuleiro!\n");
        return 1;
    }

    if (linhaD2 + TAM_NAVIO > TAM || colunaD2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal secundaria fora do tabuleiro!\n");
        return 1;
    }

    // ==========================================
    // 4️⃣ Validação de sobreposição
    // ==========================================

    for (int i = 0; i < TAM_NAVIO; i++) {

        if (tabuleiro[linhaH][colunaH + i] == 3 ||
            tabuleiro[linhaV + i][colunaV] == 3 ||
            tabuleiro[linhaD1 + i][colunaD1 + i] == 3 ||
            tabuleiro[linhaD2 + i][colunaD2 - i] == 3) {

            printf("Erro: Sobreposição detectada!\n");
            return 1;
        }
    }

    // ==========================================
    // 5️⃣ Posicionando os navios
    // ==========================================

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;               // Horizontal
        tabuleiro[linhaV + i][colunaV] = 3;              // Vertical
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;        // Diagonal ↘
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;        // Diagonal ↙
    }

    // ==========================================
    // 6️⃣ Exibindo o tabuleiro
    // ==========================================

    printf("\nTABULEIRO BATALHA NAVAL - NIVEL AVENTUREIRO\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}