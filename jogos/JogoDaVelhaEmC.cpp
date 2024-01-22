#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void exibir(void);
void jogo(void);
int verificando_X();
int verificando_O();

const int Linha = 3,Coluna = Linha;
char listaTeste[Linha][Coluna] = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};

int ponto1,ponto2;

int main(){
    setlocale(LC_ALL,"portuguese");
    int op = 1;
    int alt;
    while(op == 1){
            printf("Escolha:\n1-jogar\n0-Sair\nAlternativa:");
            scanf("%i",&alt);
            if(alt == 1){
                jogo();
            }else if (alt != 1){
                printf("Saindo...");
                break;
            }
    }

    return 0;
};

void exibir(){
    for(int y = 0;y < 3;y++){
        for(int x = 0;x < 3;x++){
            printf(" %c ",listaTeste[y][x]);
            };
        printf("\n");
}
}

void jogo(){
    int loopjogador =1,rodada = 1,jogador = 1,jogando = 1;

    while(jogando == 1){
        if (jogador == 1){
            while(loopjogador == 1){
                printf("Jogador X rodada = %i\n",rodada);
                exibir();

                printf("\nLinha:");
                scanf("%d",&ponto1);
                printf("Coluna:");
                scanf("%d",&ponto2);

                if(listaTeste[ponto1-1][ponto2-1] == '_'){
                    listaTeste[ponto1-1][ponto2-1] = 'X';
                    rodada += 1;
                    break;
                }else{
                    printf("\nlocal já Ocupado\n");
                }
            }
            verificando_X();
            if(verificando_X() == 1){
                exibir();
                printf("o jogador X ganhou depois de %i rodadas",rodada);
                jogando = 666;
            }else if(rodada == 9){
                exibir();
                printf("Sem movimentos Validos\nPortando Empate");
                jogando = 666;
            }
            jogador = 2;
        }
        else if(jogador ==2){
            while(loopjogador == 1){
                printf("Jogador O rodada = %i\n",rodada);
                exibir();

                printf("\nLinha:");
                scanf("%d",&ponto1);
                printf("Coluna:");
                scanf("%d",&ponto2);

                if(listaTeste[ponto1-1][ponto2-1] == '_'){
                    listaTeste[ponto1-1][ponto2-1] = 'O';
                    rodada +=1;
                    break;
                }else{
                    printf("\nlocal já Ocupado\n");}
            }
            verificando_O();
            if(verificando_O() == 1){
                exibir();
                printf("o Jogador O Ganhou Depois de %i rodadas",rodada);
                jogando = 666;
            }else if (rodada == 9){
                exibir();
                printf("Sem movimentos Validos\nPortando Empate");
                jogando = 666;
            }
            jogador = 1;
        }
    }
    
    
}

int verificando_X(){
    if(listaTeste[0][0] == 'X' && listaTeste[1][1] == 'X' && listaTeste[2][2] == 'X'){
        return 1;
    }else if(listaTeste[0][2] == 'X' && listaTeste[1][1] == 'X' && listaTeste[2][0] == 'X'){
        return 1;}

     else if(listaTeste[0][0] == 'X' && listaTeste[0][1] == 'X' && listaTeste[0][2] == 'X'){
        return 1;
    }else if(listaTeste[1][0] == 'X' && listaTeste[1][1] == 'X' && listaTeste[1][2] == 'X'){
        return 1;
    }else if(listaTeste[2][0] == 'X' && listaTeste[2][1] == 'X' && listaTeste[2][2] == 'X'){
        return 1;}
        
     else if(listaTeste[0][0] == 'X' && listaTeste[1][0] == 'X' && listaTeste[2][0] == 'X'){
        return 1;
    }else if(listaTeste[0][1] == 'X' && listaTeste[1][1] == 'X' && listaTeste[2][1] == 'X'){
        return 1;
    }else if(listaTeste[0][2] == 'X' && listaTeste[1][2] == 'X' && listaTeste[2][2] == 'X'){
        return 1;
    }
    return 0;
}

int verificando_O(){
    if(listaTeste[0][0] == 'O' && listaTeste[1][1] == 'O' && listaTeste[2][2] == 'O'){
        return 1;
    }else if(listaTeste[0][2] == 'O' && listaTeste[1][1] == 'O' && listaTeste[2][0] == 'O'){
        return 1;}

     else if(listaTeste[0][0] == 'O' && listaTeste[0][1] == 'O' && listaTeste[0][2] == 'O'){
        return 1;
    }else if(listaTeste[1][0] == 'O' && listaTeste[1][1] == 'O' && listaTeste[1][2] == 'O'){
        return 1;
    }else if(listaTeste[2][0] == 'O' && listaTeste[2][1] == 'O' && listaTeste[2][2] == 'O'){
        return 1;}
        
     else if(listaTeste[0][0] == 'O' && listaTeste[1][0] == 'O' && listaTeste[2][0] == 'O'){
        return 1;
    }else if(listaTeste[0][1] == 'O' && listaTeste[1][1] == 'O' && listaTeste[2][1] == 'O'){
        return 1;
    }else if(listaTeste[0][2] == 'O' && listaTeste[1][2] == 'O' && listaTeste[2][2] == 'O'){
        return 1;
    }
    return 0;
}