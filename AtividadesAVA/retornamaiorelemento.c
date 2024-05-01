#include <stdio.h>

int encontraMaior(int *v, int n) {
    int maior = *v;
    for (int i = 1; i < n; i++) {
        if (*(v + i) > maior) {
            maior = *(v + i);
        }
    }
    return maior;
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &v[i]);
    }
    int maior = encontraMaior(v, n);
    printf("O maior valor do vetor é: %d\n", maior);
    return 0;
}
