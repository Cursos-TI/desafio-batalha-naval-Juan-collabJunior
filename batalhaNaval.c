#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define BOARD_SIZE 10  // Tamanho do tabuleiro: 10x10
#define SHIP_SIZE 3    // Tamanho fixo dos navios

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    
    // Inicializa o tabuleiro com 0 (água) em todas as posições.
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            tabuleiro[i][j] = 0;
        }
    }
    
    // -----------------------------------------
    // Posicionamento do navio horizontal
    // -----------------------------------------
    // Definindo as coordenadas iniciais do navio horizontal.
    // Neste exemplo, o navio horizontal iniciará na linha 2, coluna 3.
    int navioH_lin = 2;
    int navioH_col = 3;
    
    // Verifica se o navio horizontal cabe dentro do tabuleiro.
    if (navioH_col + SHIP_SIZE <= BOARD_SIZE) {
        int k;
        // Posiciona o navio, garantindo que não haja sobreposição.
        for(k = 0; k < SHIP_SIZE; k++){
            if(tabuleiro[navioH_lin][navioH_col + k] != 0){
                // Caso alguma posição já esteja ocupada, emite mensagem de erro.
                printf("Erro: Sobreposição detectada para o navio horizontal na posição (%d, %d).\n", navioH_lin, navioH_col + k);
                return 1;
            }
            tabuleiro[navioH_lin][navioH_col + k] = 3; // Marca a posição do navio com 3.
        }
    } else {
        printf("Erro: O navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }
    
    // -----------------------------------------
    // Posicionamento do navio vertical
    // -----------------------------------------
    // Definindo as coordenadas iniciais do navio vertical.
    // Neste exemplo, o navio vertical iniciará na linha 5, coluna 7.
    int navioV_lin = 5;
    int navioV_col = 7;
    
    // Verifica se o navio vertical cabe dentro do tabuleiro.
    if (navioV_lin + SHIP_SIZE <= BOARD_SIZE) {
        int k;
        // Posiciona o navio vertical, garantindo que não haja sobreposição.
        for(k = 0; k < SHIP_SIZE; k++){
            if(tabuleiro[navioV_lin + k][navioV_col] != 0){
                printf("Erro: Sobreposição detectada para o navio vertical na posição (%d, %d).\n", navioV_lin + k, navioV_col);
                return 1;
            }
            tabuleiro[navioV_lin + k][navioV_col] = 3; // Marca a posição do navio com 3.
        }
    } else {
        printf("Erro: O navio vertical não cabe no tabuleiro.\n");
        return 1;
    }
    
    // -----------------------------------------
    // Exibição do tabuleiro
    // -----------------------------------------
    // Através de laços aninhados, o tabuleiro é impresso na tela.
    // 0 representa água e 3 representa as partes dos navios.
    printf("Tabuleiro:\n");
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
