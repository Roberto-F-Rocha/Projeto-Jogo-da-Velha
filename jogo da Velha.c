#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

typedef struct NO{

    char tabuleiro[SIZE][SIZE];
    struct NO* prox;

}no;

typedef struct Grafo{

    no* raiz;

}Grafo;

Grafo* criar_grafo() {

    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->raiz = NULL;

return (grafo);
}

void iniciar_tabuleiro(char tabuleiro[SIZE][SIZE]){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

bool tabuleiro_cheio(char tabuleiro[SIZE][SIZE]){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++) {
            if(tabuleiro[i][j] == ' '){
             return (false);
            }
        }
    }
 return(true);
}

void mostrar_tabuleiro(char tabuleiro[SIZE][SIZE]){
    int i, j;

    printf("\n");

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);

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

bool verificar_vitoria(char tabuleiro[SIZE][SIZE], char jogador) {
    int i;
    // Verificar linhas e colunas
    for(i = 0; i < SIZE; i++){
        if(tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador){
         return(true); // Uma linha completa
        }
        if(tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador){
         return(true); // Uma coluna completa
        }
    }

    // Verificar diagonais
    if(tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador){
     return(true); // Diagonal principal
    }
    if(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador){
     return(true); // Diagonal secundária
    }

return(false);
}

bool verificar_empate(char tabuleiro[SIZE][SIZE]){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(tabuleiro[i][j] == ' '){
             return(false); // Ainda existem espaços vazios no tabuleiro
            }
        }
    }
 return(true); // Tabuleiro cheio
}

no* adicionar_movimento(no* no_pai, char jogador, int linha, int coluna){
    int i, j;

    if(no_pai == NULL){ 
     return(NULL);
    }

    no* novo_no = (no*)malloc(sizeof(no));
    novo_no->prox = NULL;

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            novo_no->tabuleiro[i][j] = no_pai->tabuleiro[i][j];
        }
    }

    if(novo_no->tabuleiro[linha][coluna] == ' '){
        novo_no->tabuleiro[linha][coluna] = jogador;
        no_pai->prox = novo_no;
     return(novo_no);
    }

    free(novo_no);
 return (NULL);
}

bool jogar_contra_amigo(no* estado_atual, char jogador_atual){
    int linha, coluna;
    do{
        printf("Jogador %c, digite a linha e a coluna (por exemplo, 1 2): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;
    }while(linha < 0 || linha >= SIZE || coluna < 0 || coluna >= SIZE || estado_atual->tabuleiro[linha][coluna] != ' ');

    estado_atual = adicionar_movimento(estado_atual, jogador_atual, linha, coluna);
    mostrar_tabuleiro(estado_atual->tabuleiro);

    if(verificar_vitoria(estado_atual->tabuleiro, jogador_atual)){
        printf("Jogador %c venceu!\n", jogador_atual);
     return(true);
    } 
    else if(tabuleiro_cheio(estado_atual->tabuleiro)){
        printf("Empate!\n");
     return(true);
    }

    jogador_atual = (jogador_atual == 'X') ? 'O' : 'X'; // Alternar jogadores
 return(jogar_contra_amigo(estado_atual, jogador_atual));
}

bool jogar_contra_computador(no* estado_atual, char jogador_atual){
    int linha, coluna;
    if(jogador_atual == 'X'){
        do{
            printf("Jogador %c, digite a linha e a coluna (por exemplo, 1 2): ", jogador_atual);
            scanf("%d %d", &linha, &coluna);
            linha--;
            coluna--;
        }while(linha < 0 || linha >= SIZE || coluna < 0 || coluna >= SIZE || estado_atual->tabuleiro[linha][coluna] != ' ');

        estado_atual = adicionar_movimento(estado_atual, jogador_atual, linha, coluna);

    } 
    else{
        printf("Computador (Jogador O) está fazendo uma jogada...\n");

        bool fez_jogada = false;

        // verifica se pode ganhar em uma jogada
        for(linha = 0; linha < SIZE; linha++){
            for(coluna = 0; coluna < SIZE; coluna++){
                if(estado_atual->tabuleiro[linha][coluna] == ' '){
                    estado_atual = adicionar_movimento(estado_atual, jogador_atual, linha, coluna);
                    if(verificar_vitoria(estado_atual->tabuleiro, jogador_atual)){
                        fez_jogada = true;
                        break;
                    }
                    // Desfazer a jogada
                    estado_atual->tabuleiro[linha][coluna] = ' ';
                }
            }
            if(fez_jogada){
                break;
            }        
        }

        // Se não puder ganhar, tenta bloquear o jogador
        if(!fez_jogada){
            char jogador_oponente = (jogador_atual == 'X') ? 'O' : 'X';
            for(linha = 0; linha < SIZE; linha++){
                for(coluna = 0; coluna < SIZE; coluna++){
                    if(estado_atual->tabuleiro[linha][coluna] == ' '){
                        estado_atual = adicionar_movimento(estado_atual, jogador_oponente, linha, coluna);
                        if(verificar_vitoria(estado_atual->tabuleiro, jogador_oponente)){
                            estado_atual->tabuleiro[linha][coluna] = jogador_atual;
                            fez_jogada = true;
                            break;
                        }
                        // Desfazer a jogada
                        estado_atual->tabuleiro[linha][coluna] = ' ';
                    }
                }
                if (fez_jogada) break;
            }
        }

        // Se não puder ganhar ou bloquear, faz uma jogada aleatória
        if(!fez_jogada){
            do{
                linha = rand() % SIZE;
                coluna = rand() % SIZE;
            }while(estado_atual->tabuleiro[linha][coluna] != ' ');
            estado_atual = adicionar_movimento(estado_atual, jogador_atual, linha, coluna);
        }
    }

    mostrar_tabuleiro(estado_atual->tabuleiro);

    if(verificar_vitoria(estado_atual->tabuleiro, jogador_atual)){
        printf("Jogador %c venceu!\n", jogador_atual);
     return(true);
    } 
    else if(tabuleiro_cheio(estado_atual->tabuleiro)){
        printf("Empate!\n");
     return(true);
    }

    jogador_atual = (jogador_atual == 'X') ? 'O' : 'X'; // Alternar jogadores
 return(jogar_contra_computador(estado_atual, jogador_atual));
}

int main(){
    Grafo* jogo_da_velha = criar_grafo();

    no* estado_atual = (no*)malloc(sizeof(no));
    estado_atual->prox = NULL;

    iniciar_tabuleiro(estado_atual->tabuleiro);

    jogo_da_velha->raiz = estado_atual;

    srand(time(NULL));

    printf("Bem-vindo ao Jogo da Velha!\n");
    printf("Opções de jogo:\n");
    printf("1. Jogar contra um amigo\n");
    printf("2. Jogar contra o computador\n");

    int modo_de_jogo;
    scanf("%d", &modo_de_jogo);

    mostrar_tabuleiro(estado_atual->tabuleiro);

    if(modo_de_jogo == 1){
        if(jogar_contra_amigo(estado_atual, 'X')){
            // Jogo terminado
        }
    } 
    else if(modo_de_jogo == 2){
        if(jogar_contra_computador(estado_atual, 'X')){
            // Jogo terminado
        }
    } 
    else{
        printf("Opção de jogo inválida. Encerrando o programa.\n");
    }

    // Liberar a memória alocada
    no* atual = jogo_da_velha->raiz;

    while(atual != NULL){
        no* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(jogo_da_velha);

 return(0);
}
