#include <stdio.h>
int fat(int n){
    if (n==0){
        return 1;
    } else {
        return n*fat(n-1);
    }
}
int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);
    printf("O fatorial de %d é %d\n", n, fat(n));
}