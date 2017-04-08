/*	Nome: Eric do Vale de Castro		Nome: Vinicius Aguiar Monteiro
	Matrícula: 15/0124236				Matricula: 16/0072727
	


	Codigo implementado:
	 Batalha Naval*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PORTAAVIOES 'P' /*Porta-Aviões com 5 peças*/
#define ENCORACADO 'E' /*Encoraçado com 4 peças*/
#define FRAGATA 'F' /*Fragata com 3 peças*/
#define CORVETA 'C' /*Corveta com 2 peças*/
#define SUBMARINO 'S' /*Submarino com 1 peça*/
#define AGUA ' '
#define NAOJOGADO '+'


typedef struct naval{
	int tam;
	int jogador1[21][20], jogador2[21][20], jogando1[21][20], jogando2[21][20]; 

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
 /*-------------------------------------------------------não jogado-------------------------------------------------*/


void naojogado(int tam, int jogador1[20][20]){
	int i, j;
	for(i=0;i<tam+1;++i){
		for(j=0;j<tam;++j){
			jogador1[i][j] = NAOJOGADO;
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

			else if(jogador[i][j] == NAOJOGADO){
				printf(" %c|", NAOJOGADO);
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
	srand((unsigned) time(NULL));



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
			srand(time(NULL));
				
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

/*--------------------------------------------------------Ganhadores--------------------------------------------------------------*/

void ganhador1(){
	limparTela();
	printf("						PARABENS! JOGADOR 1 Você acaba de DESTRUIR TODAS\n");
	printf("								As EMBARCAÇÕES do seu Adversario!!\n");
	sleep(5);
}

void ganhador2(){
	limparTela();
	printf("						PARABENS! JOGADOR 2 Você acaba de DESTRUIR TODAS\n");
	printf("								As EMBARCAÇÕES do seu Adversario!!\n");
	sleep(5);
}

/*-----------------------------------------------------------GANHAR---------------------------------------------------------*/

int ganhar(naval *naval){
	int i, j, score=0;
	
	for(i=0; i<naval->tam; i++){
		for(j=0; j<naval->tam; j++){
			if(naval->jogando1[i][j] != NAOJOGADO){
				if(naval->jogando1[i][j] == naval->jogador1[i][j] && (naval->jogando1[i][j] == PORTAAVIOES || naval->jogando1[i][j] == ENCORACADO || naval->jogando1[i][j] == FRAGATA || naval->jogando1[i][j] == CORVETA || naval->jogando1[i][j] == SUBMARINO)){
					score++;
				}
			}

		}
	}
	if(naval->tam == 10){
		if(score == 35){
			ganhador2();
			return 1;
		}
	}
	if(naval->tam == 20){
		if(score == 70){
			ganhador2();
			return 1;
		}
	}

	score = 0;

	for(i=0; i<naval->tam; i++){
		for(j=0; j<naval->tam; j++){
			if(naval->jogando2[i][j] != NAOJOGADO){
				if(naval->jogando2[i][j] == naval->jogador2[i][j] && (naval->jogando1[i][j] == PORTAAVIOES || naval->jogando1[i][j] == ENCORACADO || naval->jogando1[i][j] == FRAGATA || naval->jogando1[i][j] == CORVETA || naval->jogando1[i][j] == SUBMARINO)){
					score++;
				}
			}

		}
	}
	if(naval->tam == 10){
		if(score == 35){
			ganhador1();
			return 1;
		}
	}
	if(naval->tam == 20){
		if(score == 70){
			ganhador1();
			return 1;
		}
	}

		return 0;	
}
/*------------------------------------------------------Jogar----------------------------------------------------*/

void jogar(naval *naval){
	int linhajogador1, colunajogador1, linhajogador2, colunajogador2;
	
	zerandomatrizes(naval->tam, naval->jogador1);
	zerandomatrizes(naval->tam, naval->jogador2);
	distribuicaoArmas(naval->tam, naval->jogador1);
	srand((unsigned) time(NULL));
	distribuicaoArmas(naval->tam, naval->jogador2);
	
	naojogado(naval->tam, naval->jogando1);
	naojogado(naval->tam, naval->jogando2);

	while(!ganhar(naval)){
		
		limparTela();
		printf("\n P = Porta-Aviões\n E = Encoraçado\n F = Fragata\n C = Corveta\n S = Submarino\n\n");
		tabuleiro(naval->tam, naval->jogando2);
		printf("Qual Posição Linha você deseja Jogador 1: ");
		scanf("%d", &linhajogador1);
		printf("Qual Posição Coluna você deseja jogador 1: ");
		scanf("%d", &colunajogador1);
		naval->jogando2[linhajogador1][colunajogador1-1] = naval->jogador2[linhajogador1][colunajogador1-1];
		limparTela();
		tabuleiro(naval->tam, naval->jogando2);
		sleep(3);
/*------------------------------------------------------------------------------------------------------------------------*/
		limparTela();
		printf("\n P = Porta-Aviões\n E = Encoraçado\n F = Fragata\n C = Corveta\n S = Submarino\n\n");
		tabuleiro(naval->tam, naval->jogando1);
		printf("Qual Posição Linha você deseja Jogador 2: ");
		scanf("%d", &linhajogador2);
		printf("Qual Posição Coluna você deseja jogador 2: ");
		scanf("%d", &colunajogador2);
		naval->jogando1[linhajogador2][colunajogador2-1] = naval->jogador1[linhajogador2][colunajogador2-1];
		limparTela();
		tabuleiro(naval->tam, naval->jogando1);
		sleep(3);
		

		
	}

}


int main(){
	int menu;
	naval naval;
	naval.tam = 10;
	srand(time(NULL));
	

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