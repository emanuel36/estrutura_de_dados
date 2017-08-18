#include <stdio.h>
#include "main.h"

int main(){
	int tamanho, i, vetor[tamanho], soma = 0;

	printf("Tamanho: ");
	scanf("%d", &tamanho);

	for(i = 0; i < tamanho; i++){
		printf("Vetor[%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	soma = somar(vetor, tamanho, soma);

	printf("Soma: %d\n", soma);
}