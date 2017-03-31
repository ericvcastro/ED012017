#include <stdio.h>
#include <stdlib.h>
typedef struct fila{
	
	int vetor[10];
	int tail, head;

}fila;

void inserir(fila *fila, int x){
	fila->vetor[fila->tail] = x;
	fila->tail = fila->tail+1;
}

int remover(fila*fila){
	int x;

	x = fila->vetor[fila->head];
	fila->vetor[fila->head] = 0;

	if(fila->head == fila->tail){
		fila->head = 0;
	}
	else
		fila->head += 1;
	return x; 
}

int main(){
	int x, leitor, i;
	fila fila;
	fila.tail = -1;
	fila.head = -1;

	for(i=0;i< 10; i++){
		scanf("%d", &x);
		inserir(&fila, x);
	}
	for (i=0;i<10;++i){
		leitor = remover(&fila);
		printf("o vetor[%d] = %d\n",fila.head, leitor);
	}


	return 0;
}