int partition(int *vetor, int left,int right,int pivot){
    
    int pos, i;
    swap(&vetor[pivot], &vetor[right]);
    pos = left;
    for(i = left; i < right; i++){
        if (vetor[i] < vetor[right]){
            swap(&vetor[i], &vetor[pos]);
            pos++;
        }
    }
    swap(&vetor[right], &vetor[pos]);
    return pos;
}
