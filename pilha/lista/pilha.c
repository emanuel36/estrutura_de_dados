#include <stdio.h>
#include <stdlib.h>

typedef struct Lista lista;
typedef struct Pilha pilha;

struct lista{
	int info;
	lista* next;
};

struct pilha{
	lista* topo;
};

pilha* new_pilha(){
	pilha* p = (pilha*) malloc(sizeof(pilha));
	p->topo = NULL;
	return p;
}

void push(pilha* p, int num){
	lista* l = (lista*) malloc(sizeof(lista));
	l->info = num;
	l->next = p->topo;
	p->topo = l; 
}

int pop(pilha* p){
	if(p->topo == NULL){
		printf("Lista vazia!");
	}else{
		lista* l = p->topo;
		int n;

		n = l->info;
		p->topo = l->next;
		free(l);
		return n;
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