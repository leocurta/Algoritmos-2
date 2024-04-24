#include <stdio.h>

int potencia(int a, int b){
    int pot = a;
    for(int i=1; i < b; i++){
        int aux = pot;
        for(int j=1; j < a; j++){
            pot += aux;
    }
    }
    return pot;
}

int main (){
    int a, b, x;
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("Digite o expoente: ");
    scanf("%d", &b);
    x = potencia(a, b);
    printf("%d com expoente %d resulta em: %d\n", a, b, x);
    return 0;
}