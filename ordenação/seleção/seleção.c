void ordena(int *vetor, int tamanho){
	int i, j, i2, posicao;

	for(i = 0; i < tamanho; i++){
		posicao = i;
		for(j = i + 1; j < tamanho; j++){
			if(vetor[j] < vetor[i]){
				posicao = j;

				swap(&vetor[posicao], &vetor[i]);
				printf("\n-------------\n");

				for(i2 = 0; i2 < tamanho; i2++){
				printf("%d ", vetor[i2]);
				}
			}
		}
		
	}
}