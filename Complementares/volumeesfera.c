#include <stdio.h>
#include <math.h>

float vol(float r){
    float v, pi = 3.1415;
    v = (4*pi*pow(r, 3))/3;
    return v;
}

int main (){
    float v, r;
    do{
    printf("Digite o raio da esfera em centímetros, para calcular seu volume: \n");
    scanf("%f", &r);

    v = vol(r);
    printf("O volume da esfera é: %.3fcm³\n³", v);
    } while (1);
    return 0;
}