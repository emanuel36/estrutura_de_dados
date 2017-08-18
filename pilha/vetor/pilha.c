#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Pilha pilha;

struct Pilha{
	int posicao;
	int vetor[N];
};

pilha* new_pilha(){
	pilha* p = (pilha*)malloc(sizeof(pilha));
	p->posicao = 0;
	return p;
}

void push(pilha* p, int n){
	if(p->posicao == N){
		printf("Pilha cheia!\n");
	}else{
		p->vetor[p->posicao] = n;
		p->posicao++;
	}
}

int pop(pilha* p){
	int num;
	if(p->posicao == 0){
		printf("Pilha vazia!\n");
	}else{
		num = p->vetor[p->posicao - 1];
		p->posicao--;
		return num;
	}
}

void print_menu(){
	printf("\n-----MENU-----\n");
	printf("1- Criar pilha;\n");
	printf("2- Push;\n");
	printf("3- Pop;\n");
}

int main(){
	int posicao, opcao, n;
	pilha *p;

	while(opcao != 4){
		print_menu();
		
		printf("\nOPCAO: ");
		scanf("%d", &opcao);

		if(opcao == 1){
			p = new_pilha();
		}
		else if(opcao == 2){
			printf("\nNumero: ");
			scanf("%d", &n);

			push(p, n);
		}
		else if(opcao == 3){
			printf("\nNumero: %d\n", pop(p));

		}
		else if(opcao == 4){
			printf("\nPROGRAMA ENCERRADO!");

		}else{
			printf("\nOpcao inválida!\n");
		}
	}
}