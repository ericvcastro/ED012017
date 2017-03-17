#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void desvio(){
	int i, desvio=0, media, numeroTermos=10, cadaPonto[10], somaPonto=0;

	for(i=0; i<numeroTermos;i++){
		scanf("%d", &cadaPonto[i]);
		somaPonto += cadaPonto[i];
	}
	
	media = somaPonto/numeroTermos;

	for(i=0;i<numeroTermos;i++){
		desvio += ((cadaPonto[i]-media)*(cadaPonto[i]-media)); 
	}
	desvio /= numeroTermos;
	desvio = sqrt(desvio);
	printf("O desvio é: %d\n", desvio);
}

int main(){
	desvio();
	return 0;
}