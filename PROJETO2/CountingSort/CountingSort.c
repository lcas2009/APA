#include <stdio.h>
#include <stdlib.h>

void CountingSort(int array[],int TAMANHO,int max){
	
	int arrayc[max+1];
	int arrayo[TAMANHO];

	for(int i = 0; i < max + 1; i++){
	arrayc[i] = 0;
	}
	
	for(int i = 0; i < TAMANHO; i++){
		arrayc[array[i]]++;
	}

	for(int i = 1; i <= max; i++){
		arrayc[i] += arrayc[i-1];
	}

	for(int i = TAMANHO - 1; i >= 0; i--){
        arrayo[--arrayc[array[i]]] = array[i];
    }

    for (int i = 0; array[i]; ++i)
        array[i] = arrayo[i];

}


int main(){

	int max = 0;
 	int array[] = {1 ,0 ,1 ,9 ,4 ,8 ,7 ,5 ,2 ,3};
 	int tamanho = sizeof(array)/sizeof(int);

 	for(int i = 0; i < tamanho; i++){
 		if(array[i] > max){
 			max = array[i];
 		}
 	}

 	CountingSort(array, tamanho, max);

 	for(int i = 0; i < tamanho; i++){
 		printf("%d\n", array[i]);
 	}

	
	return 0;
}
