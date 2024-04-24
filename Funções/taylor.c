#include <stdio.h>

double calcularnumerador(double base, int expo){
    if (expo == 0){
        return 1;
    } if (expo == 1) {
        return base;
    } if(expo > 1){
        return base * calcularnumerador(base, expo-1);
    }  
}

double calculardeno(double expo){
    if (expo < 2){
        return 1;
    } else{
        return expo * calculardeno(expo-1);
    }
}

double calculartermo(double base, int expo){
    double numerador = calcularnumerador(base, expo);
    double denominador = calculardeno(expo);
    return numerador/ denominador;
}

double calcularseq(double base, int n){
    double r = 0;
    for (int i = 0; i<n; i++){
        int expo = 2*i+1;
       r += calculartermo(base, expo);
    }
    return r;
}

int main (){
    double base;
    int n;

    printf("Digite o valor de x: ");
    scanf("%lf", &base);

    printf("Digite o numero de termos da sequencia: ");
    scanf("%d", &n);

    double resultado = calcularseq(base, n);
    printf("O resultado da sequência para x = %.2lf e %d termos é %.6lf\n", base, n, resultado);
    return 0;
}