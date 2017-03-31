#include <stdio.h>
#include <stdlib.h>
typedef struct pilha{
	int top;
	int vetor[10];
 }pilha;

void push(pilha *pilha, int x){
	pilha->vetor[pilha->top] = x;
	pilha->top = pilha->top + 1;
}

int pop(pilha *pilha){

	pilha->top = pilha->top - 1;
	return pilha->vetor[pilha->top];
}


int main(){
	int x, leitor, i;
	pilha pilha;
	pilha.top = 0;

	for (i = 0; i < 10; ++i){
		scanf("%d", &x);
		push(&pilha, x);
	}

	for(i = 0; i < 10; ++i){
		leitor = pop(&pilha);
		printf("Valor do vetor[%d] = %d\n", pilha.top, leitor);
	}


	return 0;
}