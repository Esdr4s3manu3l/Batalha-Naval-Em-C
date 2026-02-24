#include <stdio.h>

#define TAM 10
#define TAM_HAB 5   // Tamanho das matrizes de habilidade (5x5)

// =====================================================
// FUNÇÃO PARA INICIALIZAR TABULEIRO COM ÁGUA
// =====================================================
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
}

// =====================================================
// FUNÇÃO PARA EXIBIR TABULEIRO
// =====================================================
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTABULEIRO BATALHA NAVAL - NIVEL MESTRE\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tab[i][j] == 0)
                printf("~ ");        // Água
            else if (tab[i][j] == 3)
                printf("N ");        // Navio
            else if (tab[i][j] == 5)
                printf("* ");        // Área de habilidade
        }
        printf("\n");
    }
}

// =====================================================
// FUNÇÃO PARA CRIAR HABILIDADE CONE
// =====================================================
void criarCone(int hab[TAM_HAB][TAM_HAB]) {

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (j >= centro - i && j <= centro + i)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// =====================================================
// FUNÇÃO PARA CRIAR HABILIDADE CRUZ
// =====================================================
void criarCruz(int hab[TAM_HAB][TAM_HAB]) {

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (i == centro || j == centro)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// =====================================================
// FUNÇÃO PARA CRIAR HABILIDADE OCTAEDRO (LOSANGO)
// =====================================================
void criarOctaedro(int hab[TAM_HAB][TAM_HAB]) {

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if ( (i + j >= centro) &&
                 (i + j <= centro * 3) &&
                 (i - j <= centro) &&
                 (j - i <= centro) )
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// =====================================================
// FUNÇÃO PARA SOBREPOR HABILIDADE NO TABULEIRO
// =====================================================
void aplicarHabilidade(int tab[TAM][TAM],
                       int hab[TAM_HAB][TAM_HAB],
                       int origemLinha,
                       int origemColuna) {

    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (hab[i][j] == 1) {

                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                // Validação de limites
                if (linhaTab >= 0 && linhaTab < TAM &&
                    colunaTab >= 0 && colunaTab < TAM) {

                    if (tab[linhaTab][colunaTab] != 3)
                        tab[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// =====================================================
// FUNÇÃO PRINCIPAL
// =====================================================
int main() {

    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    // Posicionando alguns navios fixos
    for (int i = 2; i < 5; i++)
        tabuleiro[1][i] = 3;

    for (int i = 3; i < 6; i++)
        tabuleiro[i][6] = 3;

    // Criando matrizes de habilidade
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicando habilidades em pontos estratégicos
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    aplicarHabilidade(tabuleiro, octaedro, 2, 8);

    exibirTabuleiro(tabuleiro);

    return 0;
}