#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int linha, colunas, i, j, x;

	do{
		printf("numero de linhas: ");
		scanf("%d", &linha);

	}while(linha <= 0);

	do{
		printf("numero de colunas: ");
		scanf("%d", &colunas);

	}while(colunas <= 0);
	srand(time(NULL));
	for(i=0;i<linha;++i){
		for(j=0;j<colunas;++j){
			//srand(time(NULL));
			x = rand() %1000;			
			printf("| %d ",x);
		}
		//srand(time(NULL));

		printf("\n");
	}

	


	return 0;
}