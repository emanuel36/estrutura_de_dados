#include <stdio.h>
#include <string.h>

typedef struct nomes Nomes;

struct nomes{
	char nome[20];
};

int main(){	
	int n, i, j;
	char aux[20];

	scanf("%d", &n);

	Nomes vetor[n];

	for(i = 0; i < n; i++){
		scanf("%s", vetor[i].nome);
	}
	
	for(i = 0; i < n; i++){
		for (j = i + 1; i < n; j++){
			if(strcmp(vetor[i].nome, vetor[j].nome) > 0){
				strcpy(aux, vetor[i].nome);
				strcpy(vetor[j].nome, vetor[i].nome);
				strcpy(vetor[i].nome, aux);
			}
		}
	}

	for(i = 0; i < n; i++){
		printf("%s\n", vetor[i].nome);
	}
}