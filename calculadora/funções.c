void printMenu(){
	printf("--Digite o numero da operacao desejada--\n");
	printf("1 - Soma;\n");
	printf("2 - Subtracao;\n");
	printf("3 - Multiplicação;\n");
	printf("4 - Divisão;\n");
	printf("5 - Fatorial;\n");	
}

void soma(float *n1, float *n2, float *operacao){
	*operacao  = *n1 + *n2;
}

void subtracao(float *n1, float *n2, float *operacao){
	*operacao = *n1 - *n2;
}

void multiplicacao(float *n1, float *n2, float *operacao){
	*operacao = (*n1) * (*n2);
}

void divisao(float *n1, float *n2, float *operacao){
	if(*n2 == 0){
		printf("\n---Divisao Impossivel!---\n");
	}else{
		*operacao  = *n1 / *n2;
	}
}

void fatorial(float *n, float *fat){
	int i;

	for(i = 0; i < n; i++){
		(*fat) = (*fat) * i;
	}
}