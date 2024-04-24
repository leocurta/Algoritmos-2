#include <stdio.h>
#include <math.h>

typedef struct{
    int x, y;
} ponto;

float dist(ponto p1, ponto p2){
    float d;
    d = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return d;
}

int main (){
    ponto p1, p2;
    float d;
        printf("Digite o x do ponto 1:\n");
        scanf("%d", &p1.x);
        printf("Digite o y do ponto 1:\n");
        scanf("%d", &p1.y);
        printf("Digite o x do ponto 2:\n");
        scanf("%d", &p2.x);
        printf("Digite o y do ponto 2:\n" );
        scanf("%d", &p2.y);
    d = dist(p1, p2);
    printf("A distância entre os pontos é igual a: %f", d);
    return 0;
}