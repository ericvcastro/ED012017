/*Usará a biblioteca Math.h;*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int desvio(int *vetor, int numeroTermos){
	int i, desvio, somadetermos, media;

	for(i=0; i<numeroTermos; i++){
		somadetermos += vetor[i];
	}
	
	media = somadetermos/numeroTermos;

	for (i=0;i<numeroTermos;++i){
		desvio += (vetor[i] - media)*(vetor[i] - media);
		printf("desvio %d = %d\n", i, desvio);	
	}
	
	desvio /= numeroTermos;
	
	desvio = sqrt(desvio);
	
	return desvio;
}


int main(){

	int i, numeroTermos, somaPonto=0, Padrao;
	int vetor[numeroTermos];

	do{
		printf("Numero de termos = ");
		scanf("%d", &numeroTermos);

	}while(numeroTermos <= 0);

	for(i=0;i<numeroTermos;i++){
		printf("vetor[%d] = ", i);
		scanf("%d", &vetor[i]);
	}

	Padrao = desvio(vetor, numeroTermos);

	printf("Desvio Padrão = %d\n", Padrao);

	return 0;
}