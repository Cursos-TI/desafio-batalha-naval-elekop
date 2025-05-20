#include <stdio.h>
#include <stdlib.h>  // Corrige o erro de abs()
#define TAM_TAB 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Exemplo: colocar alguns navios (valor 3)
    tabuleiro[2][3] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][3] = 3;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar matriz de habilidade em forma de cone
void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade em cruz
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade em octaedro
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            if (linhaTab >= 0 && linhaTab < TAM_TAB && colunaTab >= 0 && colunaTab < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 5; // Marca área de efeito
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int habilidade[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Exemplo 1: cone
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 3);
    printf("Cone:\n");
    exibirTabuleiro(tabuleiro);

    // Resetar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Exemplo 2: cruz
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 3, 3);
    printf("Cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Resetar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Exemplo 3: octaedro
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 3, 3);
    printf("Octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
