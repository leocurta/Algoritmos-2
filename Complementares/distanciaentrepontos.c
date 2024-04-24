#include <stdio.h>
#include <math.h>

float dist(int xA, int yA, int xB, int yB){
    float d;
    d = sqrt(pow((xB - xA), 2) + pow((yB - yA), 2));
    return d;
}

int main (){
    int xA, yA, xB, yB;
    float d;
    printf("Digite as coordenadas do ponto A (x y): ");
    scanf("%d %d", &xA, &yA);
    printf("Digite as coordenadas do ponto B (x y): ");
    scanf("%d %d", &xB, &yB);
    d = dist(xA, yA, xB, yB);
    printf("A distancia entre os pontos A e B é %.5f\n", d);
    return 0;
}