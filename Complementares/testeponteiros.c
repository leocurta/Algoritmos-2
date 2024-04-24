#include <stdio.h>

int main(void){




    int x = 15;
    int *pont = &x;
    int oi = x;

    printf("o conteudo da variavel x e: %d\n", x);
    printf("o endereco da variavel x e: %d\n", &x);
    printf("o endereco que a variavel pont aponta e: %d\n", pont);
    printf("o conteudo do endereco que o ponteiro pont aponta e: %d\n", *pont);
    printf("o endereco do ponteiro pont e: %d\n", &pont);
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    x = 6;


    printf("o conteudo da variavel x e: %d\n", x);
    printf("o conteudo da variavel oi e: %d\n", oi);
    printf("o conteudo do endereco que o ponteiro pont aponta e: %d\n", *pont);
    
    return 0;
}