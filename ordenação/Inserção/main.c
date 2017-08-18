#include <stdio.h>
#include "main.h"

int main(){

	int tamanho, i, vetor[tamanho];

	printf("Tamanho: ");
	scanf("%d", &tamanho);

	for(i = 0; i < tamanho; i++){
		printf("Vetor[%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	ordena(vetor, tamanho);
	printf("\n");
}