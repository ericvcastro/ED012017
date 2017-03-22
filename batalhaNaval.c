/*	Nome: Eric do Vale de Castro	
	Matrícula: 15/0124236
	Codigo implementado:
	 Batalha Naval*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define enc = 4;
#define sub = 1;
#define agua = 0;


typedef struct naval{
	int tam;
	int jogador1[20][20], jogador2[20][20]; 

}naval;

void limparTela(){
	system("clear");
}

/*-----------------------------------------------------Dificuldade-----------------------------------------------*/

void dificuldade(naval *naval){
	int dificuldade;
	limparTela();

	do{
		printf("Opções:\n\n");
		printf("	1- Fácil\n");
		printf("	2- Dificil\n\n");
		printf("Qual a sua Dificuldade: ");
		scanf("%d", &dificuldade);
	}while(dificuldade<=0 || dificuldade >=3);
	
	naval->tam = 10 * dificuldade;
	
	return;
	
	
}

/*--------------------------------------------------------Tabuleiro---------------------------------------------*/

void tabuleiro(int tam, int jogador[20][20]){
	int i, j;
	for (i = 0; i < tam+1; ++i){
		if (i < 10){
		printf("0%d|", i);
		}
		else
			printf("%d|", i);
		for (j = 0; j < tam; ++j){
			if(i == 0){
				if ( (j+1) < 10){
				printf("0%d|", j+1);
				}
				else
					printf("%d|", j+1);
			}
			else 
				printf(" *|");
		}
		printf("\n");
	}

}
/*--------------------------------------------------Distribuição de Armas----------------------------------------*/

void distribuicaoArmas(int tam, int jogados[20][20]){
	int i, j;

}

/*------------------------------------------------------Jogar----------------------------------------------------*/

void jogar(naval *naval){
	int i;
	tabuleiro(naval->tam, naval->jogador1);
	scanf("%d", &i);
}


int main(){
	int menu;
	naval naval;
	naval.tam = 10;
	

	do{
		menu = 0;
		limparTela();
		printf("Opções:\n\n");
		printf("	1-jogar\n");
		printf("	2-Dificuldade\n");
		printf("	3-Sair\n\n");
		printf("Qual você Deseja: ");
		scanf("%d", &menu);	

		if(menu == 1){
				jogar(&naval);				
			}				
		if(menu == 2){
				dificuldade(&naval);
			}
		if(menu == 3){
				return 0;
		}
	}while(menu >=1 && menu <= 3);
	


	return 0; 
}