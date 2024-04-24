#include <stdio.h>

int china(int n){
    int x = 1, aux=n, cont=0;
    while (aux > 0){
        aux -= x;
        x = x + 2;
        cont++;
    }
    return cont;
}

int main(){
    int n;
    printf("Digite um numero (quadrado perfeito): ");
    scanf("%d", &n);
    printf("A raiz quadrada de %d e: %d\n", n, china(n));
    return 0;
}