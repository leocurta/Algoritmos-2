#include <stdio.h>
int potencia(int a, int b){
   int pot;
   pot = a;
   for (int i= 1; i<b; i++){
       pot *= a;
   }
    return pot;
}
int main(){
    int a, b, pot;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite um numero: ");
    scanf("%d", &b);
    pot = potencia(a, b);
    printf("%d com expoente %d resulta em: %d\n", a,b, pot);
    return 0;
}