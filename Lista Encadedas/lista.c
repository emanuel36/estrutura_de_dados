#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista lista;

struct Lista{
	char nome[50];
	int matricula;
	int media;
	lista *next;
};

int contador = 1;

void *insert(lista* l, char nome[50], int media){
	lista* newList = (lista*)malloc(sizeof(lista));

	strcpy(newList->nome, nome);
	newList->matricula = contador;
	newList->media = media;
	newList->next = l;

	printf("---Aluno adicionado!---\n");
	contador++;
	return newList;
}

lista* deleta(lista* l, char nomeAux[50]){
	lista* anterior = NULL; 
	lista* atual = l;

	while(atual != NULL && (strcmp(atual->nome, nomeAux)) != 0){
		anterior = atual;
		atual = atual->next;
	}

	if(atual == NULL){
		printf("Aluno não encontrado!\n\n");
		return l;
	}
	if(anterior == NULL){
		l = atual->next;
		printf("Aluno deletado!\n\n");
	}else{
		anterior->next = atual->next;
		printf("Aluno deletado!\n\n");
	}
	free(atual);
	return l;
}

void print(lista *l){
	lista* printL = l;

	if(printL == NULL){
		printf("\n\n---FIM DA LISTA---\n");
	}else{
		printf("\nNome do Aluno: %s\n", printL->nome);
		printf("Matricula:     %d\n", printL->matricula);
		printf("Media:         %d\n", printL->media);

		print(printL->next);
	}
}

void printMenu(){
	printf("\n-----------MENU------------\n");
	printf("\n1- Adicionar Aluno;\n");
	printf("2- Imprimir lista de alunos;\n");
	printf("3- Buscar aluno;\n");
	printf("4- Apagar aluno;\n");
	printf("5- Apagar lista;\n");
	printf("6 - Sair do programa;\n");
}

void printMenu2(){
	printf("\n	1.1- Continuar;");
	printf("\n	1.2- Adicionar mais um aluno;");
}

void printMenu3(){
	printf("	3.1- Buscar por nome;\n");
	printf("	3.2- Buscar por matricula;\n");
	printf("	3.3- Buscar alunos que passaram;\n");
}

void comparaNome(lista *l, char nomeAux[50]){
	int encontrei = 0;
	for(; l != NULL; l = l->next){
		if(strcmp(nomeAux, l->nome) == 0){
			printf("\n\nAluno: %s\n", l->nome);
			printf("Matricula: %d\n", l->matricula);
			printf("Media: %d\n", l->media);
			encontrei = 1;
		}	
	}
	if(encontrei == 0){
		printf("---Aluno não encontrado!---\n");
	}
}

void comparaMatricula(lista* l, int matriculaAux){
	int encontrou = 0;
	for(; l != NULL; l = l->next){
		if(matriculaAux == l->matricula){
			printf("\nAluno: %s\n", l->nome);
			printf("Matricula: %d\n", l->matricula);
			printf("Media: %d\n", l->media);
			encontrou = 1;
		}
	}
	if(encontrou == 0){
		printf("\n---Aluno nao encontrado!---\n");
	}
}

void comparaPassou(lista* l){
	int encontrei = 0;
	for(; l != NULL; l = l->next){
		if(l->media >= 7){
			printf("\nAluno: %s\n", l->nome);
			printf("Matricula: %d\n", l->matricula);
			printf("Media: %d\n", l->media);
			encontrei =1;
		}
	}
	if(encontrei == 0){
		printf("\n---Nenhum aluno passou!---\n");
	}
}

void *recebeDados(char nome[50], int media, lista* l){
	printf("\nNome: ");
	scanf("%s", nome);

	printf("Media: ");
	scanf("%d", &media);

	l = insert(l, nome, media);

	return l;
}

int main(){
	lista* l = NULL;
	int opcao = 0, opcao2 = 0, media, matricula, matriculaAux;
	char nome[50], nomeAux[50];

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLISTA DE ALUNOS - ESTRUTURA DE DADOS\n");

	while(opcao != 6){
		printMenu();

		printf("\nDigite uma opcao: ");
		scanf("%d", &opcao);

		if(opcao == 1){
			l = recebeDados(nome, media, l);
			printMenu2();
			printf("\n	Digite a opcao 2: ");
			scanf("%d", &opcao2);
			while(opcao2 != 1){
				l = recebeDados(nome, media, l);
				printMenu2();
				printf("\n	Digite a opcao 2: ");
				scanf("%d", &opcao2);	
			}
		}
		else if (opcao == 2){
			print(l);
		}
		else if(opcao == 3){
			printMenu3();

			printf("	Digite a segunda opcao: ");
			scanf("%d", &opcao2);

			if(opcao2 == 1){
				printf("Aluno: ");
				scanf("%s", nomeAux);
				comparaNome(l, nomeAux);
			}
			if(opcao2 == 2){
				printf("	Matricula: ");
				scanf("%d", &matriculaAux);
				comparaMatricula(l, matriculaAux);
			}
			if(opcao2 == 3){
				comparaPassou(l);
			}
		}
		else if(opcao == 4){
    		printf("Nome do aluno: ");
    		scanf("%s", nomeAux);

    		l = deleta(l, nomeAux);
		}
		else if(opcao == 5){
			//FUNÇÂO PARA APAGAR LISTA
		}

		else if(opcao == 6){
			printf("\n---PROGRAMA ENCERRADO---\n\n");
		}
		else{
			printf("Opcao invalida\n");
		}
	}
	return 0;
}