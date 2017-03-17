#include <stdio.h>


int main(){
	int i;
	float vetor[10];

	for(i=0;i<10;i++){
		scanf("%f", &vetor[i]);
	}
	for (i=0;i<10;++i){
		printf("vetor[%d] = %f\n",i, vetor[i]);
	}	

	return 0;
}