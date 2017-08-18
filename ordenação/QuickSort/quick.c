void ordena(int *vetor, int left, int right){
	
    if (left < right){
        int pivot = (left + right) / 2;
 		int pos = partition(vetor, left, right, pivot);
 		ordena(vetor, left, pos - 1);
	    ordena(vetor, pos + 1, right);
    }
}
