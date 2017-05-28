/*ALUNOS:						Matricula: 
	VINICIUS AGUIAR MONTEIRO 		16/0072727
	ERICK DE CASTRO 				15/0124236*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

struct Node{
	char nome[100];
	char email [100];
	char telefone [20];
	struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereInicio (node *LISTA);
void exibe (node *LISTA);
void libera (node *LISTA);
void insere (node *LISTA);
void altera (node *LISTA);
void procura(node *LISTA);
void ordenar(node *LISTA);

int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int menu(void)
{
	int opt;
	printf("\nEscolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar agenda\n");
	printf("2. Exibir agenda\n");
	printf("3. Adicionar contato\n");
	printf("4. Alterar contato\n");
    printf("5. Procura contato\n");
	printf("Opcao: ");
	scanf("%d", &opt);

	return opt;
}

void opcao(node *LISTA, int op)
{
	switch(op){
		case 0:
			libera(LISTA);
			break;

		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;

		case 2:
		    ordenar(LISTA);
			exibe(LISTA);
			break;

		case 3:
			insereInicio(LISTA);
			break;

		case 4:
		    altera(LISTA);
			break;

		case 5:
		    procura(LISTA);
			break;
		default:
			printf("\n\n COMANDO INVALIDO !\n\n");
			system(CLEAR);
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL){
        printf("\n\n AGENDA TELEFONICA VAZIA!\n\n");
        system("pause");
		return 1;
    }
	else
		return 0;
}

node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
        else{
            setbuf(stdin, NULL);
            printf("\nNovo contato: \n Nome: ");
            scanf("%[^\n]",novo->nome);
            setbuf(stdin, NULL);
            printf("Email: ");
            scanf("%[^\n]",novo->email);
            setbuf(stdin, NULL);
            printf("Telefone: ");
            scanf("%[^\n]",novo->telefone);
            setbuf(stdin, NULL);
            printf("\nCADASTRO REALIZADO COM SUCESSO!\n");
            system("pause");
            system(CLEAR);
            return novo;
        }
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();
	node *oldHead = LISTA->prox;
	LISTA->prox = novo;
	novo->prox = oldHead;
	tam++;
}
void ordenar(node *LISTA) {
node *aux1, *aux2;
        char copiar[100];
        aux1 = LISTA;
        while (aux1 != NULL) {
            aux2 = aux1->prox;
            while (aux2 != NULL) {
                if(strcmp(aux1->nome, aux2->nome) > 0) {
                    strcpy(copiar, aux1->nome);
                    strcpy(aux1->nome, aux2->nome);
                    strcpy(aux2->nome, copiar);
                    strcpy(copiar, aux1->email);
                    strcpy(aux1->email, aux2->email);
                    strcpy(aux2->email, copiar);
                    strcpy(copiar, aux1->telefone);
                    strcpy(aux1->telefone, aux2->telefone);
                    strcpy(aux2->telefone, copiar);
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
        getchar();
}
void exibe(node *LISTA)
{
	system("cls");
		/*ordenar(LISTA);*/
		
		if(vazia(LISTA)){
			printf("Lista vazia!\n\n");
			return ;
		}
		
		node *tmp;
		tmp = LISTA;
		
		printf("Lista de contatos: \n");
		
		while( tmp != NULL){
			printf("NOME: %s\n", tmp->nome);
			printf("EMAIL: %s\n", tmp->email);
			printf("TELEFONE: %s\n\n", tmp->telefone);
			tmp = tmp->prox;
		}
		
		system("pause");
		system("cls");
		printf("\n");
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
        *atual;
		atual = LISTA->prox;
            while(atual != NULL){
                proxNode = atual->prox;
                free(atual);
                atual = proxNode;
            }
	}
printf("\n LISTA TELEFONICA ZERADA COM SUCESSO!\n");
system("pause");
system(CLEAR);
}

void altera(node *LISTA)
{
system(CLEAR);
char nome[100];
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
setbuf(stdin, NULL);
printf("Qual nome do contato deseja alterar:");
scanf("%[^\n]",nome);
setbuf(stdin, NULL);
        while (LISTA!= NULL){
                if(strcmp(nome,LISTA->nome)== 0){
                printf("O contato a ser alterado e: %s\n",LISTA->nome);
                printf("Novo email: ");
                scanf("%[^\n]s",LISTA->email);
                setbuf(stdin, NULL);
                printf("Novo telefone: ");
                scanf("%[^\n]s",LISTA->telefone);
                setbuf(stdin, NULL);
                printf("\n\nContato alterado com sucesso!\n");
        }
        LISTA = LISTA->prox;
        }
}
void procura(node *LISTA)
{
system("cls");
char nome[100];
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
setbuf(stdin, NULL);
printf("Qual o nome do contato deseja procurar: ");
scanf("%[^\n]",nome);
 setbuf(stdin, NULL);
    while (LISTA!= NULL){
        if(strcmp(nome,LISTA->nome)== 0){
        printf("\n\nCONTATO ENCONTRADO!\nNome: %s\n",LISTA->nome);
        printf("Email: %s\n",LISTA->email);
        printf("Telefone: %s\n",LISTA->telefone);
      }
      LISTA = LISTA->prox;
      }
}