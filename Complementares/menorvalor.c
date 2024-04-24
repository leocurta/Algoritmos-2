#include <stdio.h>

int menor(int a, int b){
    int menor;
    if (a < b){
        menor = a;
    } else {
        menor = b;
    }
    return menor;
}

int main (){
    int a, b;
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("Digite outro valor: ");
    scanf("%d", &b);
    printf("O menor valor entre %d e %d é %d\n", a, b, menor(a, b));
    return 0;
}