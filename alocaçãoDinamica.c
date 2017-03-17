#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int numeroVetor, i, soma=0;
	scanf("%d", &numeroVetor)	;

	int *vetor = (int*)malloc(numeroVetor*sizeof(int));

	for (i = 0; i < numeroVetor; ++i){
		scanf("%d", &vetor[i]);
		soma += vetor[i];
	}
	for (i=0;i<numeroVetor;++i){
		printf("%d ", vetor[i]);
	}
	printf("\n");

	printf("Media = %d\n", (soma/numeroVetor));	


	return 0;
}