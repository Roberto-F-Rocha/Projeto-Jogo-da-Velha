#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct NO{

    char valor; 
    struct NO* prox;

}no;

no* cria_no(char valor){

    no* novo_no = (no*) malloc(sizeof(no));
    novo_no->valor = valor;
    novo_no->prox = NULL;

 return(novo_no);
}

void iniciar_tabuleiro(no* tabuleiro[3][3]){

    int i, j;

    for(i = 0; i < 3; i++){

        for(j = 0; j < 3; j++){

            tabuleiro[i][j] = cria_no(' ');
        }
    }
}

void mostrar_tabuleiro(no* tabuleiro[3][3]){

    int i, j;

    printf("\n");

    for(i = 0; i < 3; i++){

        for(j = 0; j < 3; j++){

            printf(" %c ", tabuleiro[i][j]->valor);

            if(j < 2){

                printf("|");
            }
        }
        printf("\n");

        if(i < 2){

            printf("---+---+---\n");
        }
    }

    printf("\n");
}

void fazer_jogada(no* tabuleiro[3][3], char jogador, int linha, int coluna){

    if(tabuleiro[linha][coluna]->valor == ' '){

        tabuleiro[linha][coluna]->valor = jogador;
    }
}

void movimentos_computador(no* tabuleiro[3][3]){

    int linha, coluna;

    do{

        linha = rand() % 3;
        coluna = rand() % 3;

    }while (tabuleiro[linha][coluna]->valor != ' ');

    tabuleiro[linha][coluna]->valor = 'O';
}

bool Game_Over(no* tabuleiro[3][3]){
    
    int i;

    //verificação linha coluna

    for(i = 0; i < 3; i++){

        if(tabuleiro[i][0]->valor != ' ' && tabuleiro[i][0]->valor == tabuleiro[i][1]->valor && tabuleiro[i][0]->valor == tabuleiro[i][2]->valor){

         return(true); 
        }

        if(tabuleiro[0][i]->valor != ' ' && tabuleiro[0][i]->valor == tabuleiro[1][i]->valor && tabuleiro[0][i]->valor == tabuleiro[2][i]->valor){

         return(true);
        }
    }

    //firificação diagonais

        if(tabuleiro[0][0]->valor != ' ' && tabuleiro[0][0]->valor == tabuleiro[1][1]->valor && tabuleiro[0][0]->valor == tabuleiro[2][2]->valor){

         return(true); 
        }

        if(tabuleiro[0][2]->valor != ' ' && tabuleiro[0][2]->valor == tabuleiro[1][1]->valor && tabuleiro[0][2]->valor == tabuleiro[2][0]->valor){

         return(true); 
        }

 return(false);
}

bool empate(no* tabuleiro[3][3]){
   
    int i, j;

    for(i = 0; i < 3; i++){

        for(j = 0; j < 3; j++){

            if(tabuleiro[i][j]->valor == ' '){
        
             return(false);
            }
        }
    }

 return(true);
}


int main() {
    no* tabuleiro[3][3];
    iniciar_tabuleiro(tabuleiro);

    int jogador;
    int modo_de_jogo; 
    int movimentos = 0;
    int linha, coluna;
    char simbolo_jogador;

    printf("Bem-vindo ao Jogo da Velha!\n");
    printf("Escolha o modo de jogo:\n");
    printf("[1] -> Jogar contra um amigo\n");
    printf("[2] -> Jogar contra o computador\n");
    scanf("%d", &modo_de_jogo);

    if(modo_de_jogo == 1){

        jogador = 0; // Jogador X começa
    } 

    else if(modo_de_jogo == 2){

        jogador = 0; // Jogador X começa contra o computador
    } 

    else{

        printf("Modo de jogo inválido. Encerrando o programa.\n");

     return(0);
    }

    srand(time(NULL)); // Inicializar a semente para números aleatórios

    while(!Game_Over(tabuleiro)){

        mostrar_tabuleiro(tabuleiro);

        if(jogador == 0){

            simbolo_jogador = 'X';
        } 

        else{

            simbolo_jogador = 'O';
        }

        if((modo_de_jogo == 1) || (modo_de_jogo == 2 && jogador == 0)){

            do{

                printf("Jogador %c, digite a linha e a coluna (por exemplo, 1 2): ", simbolo_jogador);
                scanf("%d %d", &linha, &coluna);

            }while(linha < 1 || linha > 3 || coluna < 1 || coluna > 3);

            fazer_jogada(tabuleiro, simbolo_jogador, linha - 1, coluna - 1);

            movimentos++;

            // Verificar se o jogo terminou
            if(Game_Over(tabuleiro)){

                mostrar_tabuleiro(tabuleiro);

                if(empate(tabuleiro)){

                    printf("O jogo empatou!\n");
                } 

                else{

                    printf("O jogador %c venceu!\n", simbolo_jogador);
                }

                break;
            }
        } 

        else if(modo_de_jogo == 2 && jogador == 1){

            printf("Computador (Jogador O) está fazendo uma jogada...\n");
            movimentos_computador(tabuleiro);

            movimentos++;

            // Verificar se o jogo terminou
            if(Game_Over(tabuleiro)){

                mostrar_tabuleiro(tabuleiro);

                if(empate(tabuleiro)){

                    printf("O jogo empatou!\n");
                } 

                else{

                    printf("O computador (Jogador O) venceu!\n");
                }

                break;
            }
        }

        // Alternar para o próximo jogador
        jogador = (jogador == 0) ? 1 : 0;

    }

 return(0);
}


