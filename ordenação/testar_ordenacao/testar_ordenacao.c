void testar_ordenacao(int *vetor, int *crescente, int *decrescente){
	int i = 0;

	for(i = 0; i < 4 ; i++){
		if(vetor[i] > vetor[i + 1]){
			*crescente = 0;
		}
		if(vetor[i] < vetor[i + 1]){
			*decrescente = 0;
		}
	}
}