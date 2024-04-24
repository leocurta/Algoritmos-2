#include <stdio.h>
void inverte(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    
}

int main(){
    int a, b;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite um numero: ");
    scanf("%d", &b);
    inverte(&a,&b);
    printf("O primeiro numero é %d e o segundo numero é %d\n", a, b);
    return 0;
}