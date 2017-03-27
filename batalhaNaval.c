/*	Nome: Eric do Vale de Castro	
	Matrícula: 15/0124236
	Codigo implementado:
	 Batalha Naval*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PORTAAVIOES 'P' /*Porta-Aviões com 5 peças*/
#define ENCORACADO 'E' /*Encoraçado com 4 peças*/
#define FRAGATA 'F' /*Fragata com 3 peças*/
#define CORVETA 'C' /*Corveta com 2 peças*/
#define SUBMARINO 'S' /*Submarino com 1 peça*/
#define AGUA ' '


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

/*------------------------------------------------Zerando as matrizes-------------------------------------------*/

void zerandomatrizes(int tam, int jogador[20][20]){
	int i, j;

	for (i = 0; i < tam+1; ++i){
		for (j = 0; j < tam; ++j){
			jogador[i][j] = AGUA;
		}
	}
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
			else if(jogador[i][j] == AGUA){
				printf(" %c|", AGUA);
			}
			else if(jogador[i][j] == PORTAAVIOES){ 
				printf(" %c|", PORTAAVIOES);
			}
			else if(jogador[i][j] == ENCORACADO){
				printf(" %c|", ENCORACADO);
			}
			else if(jogador[i][j] == FRAGATA){
				printf(" %c|", FRAGATA);
			}
			else if(jogador[i][j] == CORVETA){
				printf(" %c|", CORVETA);
			}
			else if(jogador[i][j] == SUBMARINO){
				printf(" %c|", SUBMARINO);
			}
		}
		printf("\n");
	}

}
/*---------------------------------------------------------Distribuição de Armas---------------------------------------------*/

void distribuicaoArmas(int tam, int jogador[20][20]){
	int aleatoriolinha, aleatoriocoluna, aleatoriovizinho, contportavioes = 0, contencoracado = 0;
	int contfragata = 0, contcorveta = 0, contsubmarino = 0;
	srand(time(NULL));


	if(tam == 10){	/*Modo Facil*/
	/*------------------------------------------------------------------Porta-Avioes---------------------------------------------------------*/
			do{
				aleatoriocoluna = rand()%tam;
				aleatoriolinha = rand()%tam+1;
				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){	
					aleatoriovizinho = rand()%4;
					if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-3] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-4] == AGUA && aleatoriocoluna >= 5){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-1] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-2] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-3] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-4] = PORTAAVIOES;
						contportavioes++;
					}
					if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-3][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-4][aleatoriocoluna] == AGUA && aleatoriolinha >= 5){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-1][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-2][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-3][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-4][aleatoriocoluna] = PORTAAVIOES;
						contportavioes++;
					}
					if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+3] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+4] == AGUA &&	 aleatoriocoluna <= (tam-5)){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+1] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+2] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+3] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+4] = PORTAAVIOES;
						contportavioes++;
					}
					if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+3][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+4][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-4)){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+1][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+2][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+3][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+4][aleatoriocoluna] = PORTAAVIOES;
						contportavioes++;
					}
				}
			}while(contportavioes < 1);
			
	/*-----------------------------------------------------------------Encoraçado----------------------------------------------------------------------*/
			
			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;
				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){
					aleatoriovizinho = rand()%4;
						if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-3] == AGUA && aleatoriocoluna >= 4){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna-1] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna-2] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna-3] = ENCORACADO;
							contencoracado++;
						}
						if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-3][aleatoriocoluna] == AGUA && aleatoriolinha >= 4){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha-1][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha-2][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha-3][aleatoriocoluna] = ENCORACADO;
							contencoracado++;
						}
						if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+3] == AGUA && aleatoriocoluna <=(tam-4)){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna+1] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna+2] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna+3] = ENCORACADO;
							contencoracado++;
						}
						if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+3][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-3)){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha+1][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha+2][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha+3][aleatoriocoluna] = ENCORACADO;
							contencoracado++;
						}
				}
			}while(contencoracado < 2);

	/*---------------------------------------------------------Fragata---------------------------------------------------------------*/		

			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;
					if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){
						aleatoriovizinho = rand()%4;
							if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-2] == AGUA && aleatoriocoluna >= 3){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna-1] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna-2] = FRAGATA;
								contfragata++;							
							}
							if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-2][aleatoriocoluna] == AGUA && aleatoriolinha >= 3){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-1][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-2][aleatoriocoluna] = FRAGATA;
								contfragata++;							
							}
							if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+2] == AGUA && aleatoriocoluna <= (tam-3)){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna+1] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna+2] = FRAGATA;
								contfragata++;							
							}
							if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+2][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-2)){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-1][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-2][aleatoriocoluna] = FRAGATA;
								contfragata++;							
							}
					}
			}while(contfragata < 3);

	/*----------------------------------------------------------CORVETA-------------------------------------------------------------*/

			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;
				
				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){
					aleatoriovizinho = rand()%4;
						if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && aleatoriocoluna >= 2){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha][aleatoriocoluna-1] = CORVETA;
							contcorveta++;
						}
						if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && aleatoriolinha >= 2){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha-1][aleatoriocoluna] = CORVETA;
							contcorveta++;
						}
						if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && aleatoriocoluna <= (tam-2)){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha][aleatoriocoluna+1] = CORVETA;
							contcorveta++;
						}
						if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-1)){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha+1][aleatoriocoluna] = CORVETA;
							contcorveta++;
						}


				}

			}while(contcorveta < 4);

	/*------------------------------------------------------SUBMARINOS------------------------------------------------------------*/

			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;

				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA && aleatoriolinha <= tam && aleatoriocoluna < tam){
					jogador[aleatoriolinha][aleatoriocoluna] = SUBMARINO;
					contsubmarino++;
				}

			}while(contsubmarino < 5);

		}	/*Modo facil*/

	/*____________________________________________________HARD_____________________________________________________________________*/

		if(tam == 20){	/*Modo Dificil*/
	/*---------------------------------------------------------------------Porta-Avioes----------------------------------------------------*/
			do{
				aleatoriocoluna = rand()%tam;
				aleatoriolinha = rand()%tam+1;
				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){	
					aleatoriovizinho = rand()%4;
					if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-3] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-4] == AGUA && aleatoriocoluna >= 5){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-1] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-2] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-3] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna-4] = PORTAAVIOES;
						contportavioes++;
					}
					if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-3][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-4][aleatoriocoluna] == AGUA && aleatoriocoluna >= 5){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-1][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-2][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-3][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha-4][aleatoriocoluna] = PORTAAVIOES;
						contportavioes++;
					}
					if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+3] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+4] == AGUA && aleatoriocoluna <= (tam-5)){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+1] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+2] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+3] = PORTAAVIOES;
						jogador[aleatoriolinha][aleatoriocoluna+4] = PORTAAVIOES;
						contportavioes++;
					}
					if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+3][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+4][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-5)){
						jogador[aleatoriolinha][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+1][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+2][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+3][aleatoriocoluna] = PORTAAVIOES;
						jogador[aleatoriolinha+4][aleatoriocoluna] = PORTAAVIOES;
						contportavioes++;
					}
				}
			}while(contportavioes < 2);
			
	/*---------------------------------------------------------------Encoraçado--------------------------------------------------------------------*/
			
			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;
				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){
					aleatoriovizinho = rand()%4;
						if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-3] == AGUA && aleatoriocoluna >= 4){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna-1] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna-2] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna-3] = ENCORACADO;
							contencoracado++;
						}
						if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-3][aleatoriocoluna] == AGUA && aleatoriolinha >= 4){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha-1][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha-2][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha-3][aleatoriocoluna] = ENCORACADO;
							contencoracado++;
						}
						if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+2] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+3] == AGUA && aleatoriocoluna <= (tam-4)){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna+1] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna+2] = ENCORACADO;
							jogador[aleatoriolinha][aleatoriocoluna+3] = ENCORACADO;
							contencoracado++;
						}
						if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+2][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+3][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-4)){
							jogador[aleatoriolinha][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha+1][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha+2][aleatoriocoluna] = ENCORACADO;
							jogador[aleatoriolinha+3][aleatoriocoluna] = ENCORACADO;
							contencoracado++;
						}
				}
			}while(contencoracado < 4);

	/*---------------------------------------------------------Fragata---------------------------------------------------------------*/		

			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;
					if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA){
						aleatoriovizinho = rand()%4;
							if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna-2] == AGUA && aleatoriocoluna >= 2){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna-1] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna-2] = FRAGATA;
								contfragata++;							
							}
							if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha-2][aleatoriocoluna] == AGUA && aleatoriolinha >= 2){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-1][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-2][aleatoriocoluna] = FRAGATA;
								contfragata++;							
							}
							if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA && jogador[aleatoriolinha][aleatoriocoluna+2] == AGUA && aleatoriocoluna <= (tam-2)){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna+1] = FRAGATA;
								jogador[aleatoriolinha][aleatoriocoluna+2] = FRAGATA;
								contfragata++;							
							}
							if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA && jogador[aleatoriolinha+2][aleatoriocoluna] == AGUA && aleatoriolinha <= (tam-2)){
								jogador[aleatoriolinha][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-1][aleatoriocoluna] = FRAGATA;
								jogador[aleatoriolinha-2][aleatoriocoluna] = FRAGATA;
								contfragata++;							
							}
					}
			}while(contfragata < 6);

	/*----------------------------------------------------------CORVETA-------------------------------------------------------------*/

			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;
				
				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA ){
					aleatoriovizinho = rand()%4;
						if(aleatoriovizinho == 0 && jogador[aleatoriolinha][aleatoriocoluna-1] == AGUA){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha][aleatoriocoluna-1] = CORVETA;
							contcorveta++;
						}
						if(aleatoriovizinho == 1 && jogador[aleatoriolinha-1][aleatoriocoluna] == AGUA){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha-1][aleatoriocoluna] = CORVETA;
							contcorveta++;
						}
						if(aleatoriovizinho == 2 && jogador[aleatoriolinha][aleatoriocoluna+1] == AGUA){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha][aleatoriocoluna+1] = CORVETA;
							contcorveta++;
						}
						if(aleatoriovizinho == 3 && jogador[aleatoriolinha+1][aleatoriocoluna] == AGUA){
							jogador[aleatoriolinha][aleatoriocoluna] = CORVETA;
							jogador[aleatoriolinha+1][aleatoriocoluna] = CORVETA;
							contcorveta++;
						}


				}

			}while(contcorveta < 8);

	/*------------------------------------------------------SUBMARINOS------------------------------------------------------------*/

			do{
				aleatoriolinha = rand()%tam+1;
				aleatoriocoluna = rand()%tam;

				if(jogador[aleatoriolinha][aleatoriocoluna] == AGUA && aleatoriolinha < tam && aleatoriocoluna < tam){
					jogador[aleatoriolinha][aleatoriocoluna] = SUBMARINO;
					contsubmarino++;
				}

			}while(contsubmarino < 10);

		}	/*Modo Dificil*/
} 

/*-----------------------------------------------------------GANHAR---------------------------------------------------------*/

int ganhar(){
	return 0;	
}
/*------------------------------------------------------Jogar----------------------------------------------------*/

void jogar(naval *naval){
	int i, linhajogador1, colunajogador1, linhajogador2, colunajogador2;
	zerandomatrizes(naval->tam, naval->jogador1);
	zerandomatrizes(naval->tam, naval->jogador2);
	
	distribuicaoArmas(naval->tam, naval->jogador1);
	distribuicaoArmas(naval->tam, naval->jogador2);
	
	while(!ganhar()){
		limparTela();
		printf(" P = Porta-Aviões\n E = Encoraçado\n F = Fragata\n C = Corveta\n S = Submarino\n");
		tabuleiro(naval->tam, naval->jogador1);
		printf("Qual Posição Linha você deseja Jogador 1: ");
		scanf("%d", &linhajogador1);
		printf("Qual Posição Coluna você deseja jogador 1: ");
		scanf("%d", &colunajogador1);
	}

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