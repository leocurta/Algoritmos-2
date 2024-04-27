#include <stdio.h>

int maiorElemento(int vet[], int n) {
    int max = vet[0];
    int *ptr = &max;
    for (int i = 1; i < n; i++) {
        if (vet[i] > max) {
            max = vet[i];
        }
    }
    return *ptr;
}

int main (){
    int vet[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Maior elemento do vetor: %d\n", maiorElemento(vet, n));
    
    return 0;
}