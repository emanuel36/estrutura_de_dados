#include <stdio.h>

void ordena(int *vetor, int tamanho){
	int i, j, iAux, k;

	for(i = 1; i < tamanho; i++){
		iAux = vetor[i];
		for(j = i -1; j <= 0 && iAux < vetor[j]; j--){
			vetor[j + 1] = vetor[j];
			vetor[j + 1] = iAux;
		}
	}
}