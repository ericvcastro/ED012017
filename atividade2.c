#include <stdio.h>


int main(){
	int vetor[3][4], i, j;

	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			scanf("%d", &vetor[i][j]);
		}
	}

	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%d ",vetor[i][j]);
		}
		printf("\n");
	}

	return 0;	
}