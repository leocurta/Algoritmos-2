#include <stdio.h>

int mediaA(int x, int y, int z){
    float media = 0;
    media = (x + y + z)/ 3;
    return media;
}

int mediaP(int x, int y, int z){
    float media = 0;
    media = (5*x + 3*y + 2*z)/ 10;
    return media;
}

float mediaH(float x, float y, float z){
    float media = 0;
    media = 3/ (1/x + 1/y + 1/z);
    return media;
}

int main (){
    int x, y, z;
    float m;
    char op;
    do{
    printf("---------------------------------\n");
    printf("Escolha uma das opcoes a seguir:\n");
    printf("     (A) Media Aritmetica\n");
    printf("     (P) Media Ponderada\n");
    printf("     (H) Media Harmonica\n");
    printf("           (S) Sair\n");
    printf("---------------------------------\n");
    scanf(" %c", &op);
    if (op == 'S'){
        break;
    } if (op == 'P'){
        printf("A primeira nota tem peso 5, a segunda tem peso 3 e a terceira tem peso 4.\n");
        printf("\n");
    }

    printf("Digite a primeira nota:");
    scanf("%d", &x);
    printf("Digite a segunda nota:");
    scanf("%d", &y);
    printf("Digite a terceira nota:");
    scanf("%d", &z);
    printf("\n");
    
    switch (op){
        case 'A':
           m = mediaA(x, y, z);
           printf("A media aritmetica dos valores e: %.1f\n", m);
           break;
        case 'P':
           m = mediaP(x, y, z);
           printf("A media ponderada dos valores e: %.1f\n", m);
           break;
        case 'H':
           m = mediaH(x, y, z);
           printf("A media harmonica dos valores e: %.1f\n", m);
           break;
        default:
           printf("Opcao invalida.\n");
           break;
    }
    } while (1);
    return 0;
}