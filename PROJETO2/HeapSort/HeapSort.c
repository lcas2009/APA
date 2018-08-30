#include <stdio.h>
#include <stdlib.h>

int TamanhoEliminado = NULL;

int Pai(int i){
    if(i = 0){
        return 0;
}
    return (i - 1)/2;
}

int FilhoEsquerdo(int i){
    return 2*i + 1;
}

int FilhoDireito(int i){
    return 2*i + 2;
}

void MaxHeapify(int array[], int i){
    int E = FilhoEsquerdo(i);
    int D = FilhoDireito(i);

    int max = i;

    if(E < TamanhoEliminado && array[E] > array[max])
        max = E;
    
    if(D < TamanhoEliminado && array[D] > array[max])
        max = D;

    if(max != i){
        int aux = array[i];
        array[i] = array[max];
        array[max] = aux;
        MaxHeapify(array, max);
    }
}

void BuildMaxHeap(int array[],int comprimento){
    TamanhoEliminado = comprimento;
    for(int i = (comprimento - 1)/2; i >= 0; i--){
        MaxHeapify(array, i);
    }
}

void HeapSort(int array[],int comprimento){
    BuildMaxHeap(array, comprimento);

    for(int i = comprimento - 1; i > 0; i--){
        int aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        TamanhoEliminado--;
        MaxHeapify(array, 0);
    }
}


int main(int argc, char const *argv[])
{
    int array[] = {1 ,0 ,1 ,9 ,4 ,8 ,7 ,5 ,2 ,3};
   	int comprimento = sizeof(array)/sizeof(int);
    HeapSort(array, comprimento);

    for(int i = 0; i < comprimento; i++){
    	printf("%d\n", array[i]);
    }
  
    return 0;
}
