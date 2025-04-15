#include <stdio.h>
#include <stdlib.h>  // Para a função abs()

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define BOARD_SIZE 10  // Tamanho do tabuleiro: 10x10
#define SHIP_SIZE 3    // Tamanho fixo dos navios

// Dimensões das matrizes de habilidade (usando 3 linhas x 5 colunas, conforme exemplo)
#define ABILITY_ROWS 3
#define ABILITY_COLS 5

int main() {
    int tabuleiro[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    
    // ====================================================
    // 1. Inicialização do Tabuleiro
    // ====================================================
    // Preenche o tabuleiro com 0 (água) em todas as posições.
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            tabuleiro[i][j] = 0;
        }
    }
    
    // ====================================================
    // 2. Posicionamento dos Navios (exemplo com 4 navios)
    // ====================================================
    // --- Navio 1: Horizontal ---
    int navioH_lin = 2;
    int navioH_col = 3;
    if (navioH_col + SHIP_SIZE <= BOARD_SIZE) {
        int k;
        for(k = 0; k < SHIP_SIZE; k++){
            if(tabuleiro[navioH_lin][navioH_col + k] != 0){
                printf("Erro: Sobreposição no navio horizontal na posição (%d, %d).\n", 
                        navioH_lin, navioH_col + k);
                return 1;
            }
            tabuleiro[navioH_lin][navioH_col + k] = 3; // Marca o navio com 3
        }
    } else {
        printf("Erro: O navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }
    
    // --- Navio 2: Vertical ---
    int navioV_lin = 5;
    int navioV_col = 7;
    if (navioV_lin + SHIP_SIZE <= BOARD_SIZE) {
        int k;
        for(k = 0; k < SHIP_SIZE; k++){
            if(tabuleiro[navioV_lin + k][navioV_col] != 0){
                printf("Erro: Sobreposição no navio vertical na posição (%d, %d).\n", 
                        navioV_lin + k, navioV_col);
                return 1;
            }
            tabuleiro[navioV_lin + k][navioV_col] = 3;
        }
    } else {
        printf("Erro: O navio vertical não cabe no tabuleiro.\n");
        return 1;
    }
    
    // --- Navio 3: Diagonal (Down-Right) ---
    int navioD1_lin = 0;
    int navioD1_col = 0;
    if ((navioD1_lin + SHIP_SIZE <= BOARD_SIZE) && (navioD1_col + SHIP_SIZE <= BOARD_SIZE)) {
        int k;
        for(k = 0; k < SHIP_SIZE; k++){
            if(tabuleiro[navioD1_lin + k][navioD1_col + k] != 0){
                printf("Erro: Sobreposição no navio diagonal (down-right) na posição (%d, %d).\n", 
                        navioD1_lin + k, navioD1_col + k);
                return 1;
            }
            tabuleiro[navioD1_lin + k][navioD1_col + k] = 3;
        }
    } else {
        printf("Erro: O navio diagonal (down-right) não cabe no tabuleiro.\n");
        return 1;
    }
    
    // --- Navio 4: Diagonal (Down-Left) ---
    int navioD2_lin = 0;
    int navioD2_col = BOARD_SIZE - 1; // Inicia na última coluna
    if ((navioD2_lin + SHIP_SIZE <= BOARD_SIZE) && (navioD2_col - (SHIP_SIZE - 1) >= 0)) {
        int k;
        for(k = 0; k < SHIP_SIZE; k++){
            if(tabuleiro[navioD2_lin + k][navioD2_col - k] != 0){
                printf("Erro: Sobreposição no navio diagonal (down-left) na posição (%d, %d).\n", 
                        navioD2_lin + k, navioD2_col - k);
                return 1;
            }
            tabuleiro[navioD2_lin + k][navioD2_col - k] = 3;
        }
    } else {
        printf("Erro: O navio diagonal (down-left) não cabe no tabuleiro.\n");
        return 1;
    }
    
    // ====================================================
    // 3. Criação das Matrizes de Habilidade
    // ====================================================
    int cone[ABILITY_ROWS][ABILITY_COLS];
    int cruz[ABILITY_ROWS][ABILITY_COLS];
    int octaedro[ABILITY_ROWS][ABILITY_COLS];
    
    // --------- Matriz Cone (forma de cone para baixo) ---------
    // Regra: para cada linha i, as colunas afetadas vão de (centro - i) até (centro + i).
    // O ponto de origem da habilidade (topo do cone) é a célula (0, ABILITY_COLS/2)
    for(i = 0; i < ABILITY_ROWS; i++){
        for(j = 0; j < ABILITY_COLS; j++){
            if(j >= (ABILITY_COLS/2 - i) && j <= (ABILITY_COLS/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
    
    // --------- Matriz Cruz (formando um "+") ---------
    // Regra: se a linha é a central ou a coluna é a central, então está afetada.
    for(i = 0; i < ABILITY_ROWS; i++){
        for(j = 0; j < ABILITY_COLS; j++){
            if(i == ABILITY_ROWS/2 || j == ABILITY_COLS/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
    
    // --------- Matriz Octaedro (forma de losango) ---------
    // Usando a fórmula: se |i - centro| + |j - centro| <= 1, então está afetada.
    int centroLinha = ABILITY_ROWS/2;  // Para ABILITY_ROWS=3, centroLinha = 1
    int centroCol = ABILITY_COLS/2;      // Para ABILITY_COLS=5, centroCol = 2
    for(i = 0; i < ABILITY_ROWS; i++){
        for(j = 0; j < ABILITY_COLS; j++){
            if( abs(i - centroLinha) + abs(j - centroCol) <= 1 )
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
    
    // ====================================================
    // 4. Sobreposição das Habilidades no Tabuleiro
    // ====================================================
    // Usaremos o valor 5 para marcar a área de efeito da habilidade.
    // Note: a sobreposição poderá sobrescrever informações de navios (valor 3) para fins de visualização.
    
    // ---- Habilidade Cone ----
    // Para o Cone, o ponto de origem da habilidade é o topo central da matriz (linha 0, coluna ABILITY_COLS/2)
    // No tabuleiro, definimos o ponto de origem desejado para o cone.
    int cone_orig_row = 1;  // Exemplo: linha 1
    int cone_orig_col = 2;  // Exemplo: coluna 2
    for(i = 0; i < ABILITY_ROWS; i++){
        for(j = 0; j < ABILITY_COLS; j++){
            // Mapeamento: como a origem na matriz do cone é (0, ABILITY_COLS/2),
            // a posição no tabuleiro é (cone_orig_row + i, cone_orig_col + (j - ABILITY_COLS/2)).
            int linTab = cone_orig_row + i;
            int colTab = cone_orig_col + (j - (ABILITY_COLS/2));
            // Verifica se a posição calculada está dentro dos limites do tabuleiro.
            if(linTab >= 0 && linTab < BOARD_SIZE && colTab >= 0 && colTab < BOARD_SIZE){
                if(cone[i][j] == 1)
                    tabuleiro[linTab][colTab] = 5;
            }
        }
    }
    
    // ---- Habilidade Cruz ----
    // Para a Cruz, a origem é o centro da matriz (linha ABILITY_ROWS/2, coluna ABILITY_COLS/2)
    // Definimos o ponto de origem desejado no tabuleiro.
    int cruz_orig_row = 7;  // Exemplo: linha 7
    int cruz_orig_col = 7;  // Exemplo: coluna 7
    for(i = 0; i < ABILITY_ROWS; i++){
        for(j = 0; j < ABILITY_COLS; j++){
            int linTab = cruz_orig_row + i - (ABILITY_ROWS/2);
            int colTab = cruz_orig_col + j - (ABILITY_COLS/2);
            if(linTab >= 0 && linTab < BOARD_SIZE && colTab >= 0 && colTab < BOARD_SIZE){
                if(cruz[i][j] == 1)
                    tabuleiro[linTab][colTab] = 5;
            }
        }
    }
    
    // ---- Habilidade Octaedro ----
    // Para o Octaedro, a origem é também o centro da matriz.
    int oct_orig_row = 8;  // Exemplo: linha 8
    int oct_orig_col = 2;  // Exemplo: coluna 2
    for(i = 0; i < ABILITY_ROWS; i++){
        for(j = 0; j < ABILITY_COLS; j++){
            int linTab = oct_orig_row + i - (ABILITY_ROWS/2);
            int colTab = oct_orig_col + j - (ABILITY_COLS/2);
            if(linTab >= 0 && linTab < BOARD_SIZE && colTab >= 0 && colTab < BOARD_SIZE){
                if(octaedro[i][j] == 1)
                    tabuleiro[linTab][colTab] = 5;
            }
        }
    }
    
    // ====================================================
    // 5. Exibição Final do Tabuleiro
    // ====================================================
    // O tabuleiro apresenta: 
    //   0 -> Água, 
    //   3 -> Navio, 
    //   5 -> Área afetada pela habilidade
    printf("Tabuleiro com Navios e Habilidades:\n");
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
