#include <stdio.h>

int main() {
    int limS;

    printf("Digite o limite superior para encontrar números primos: ");
    scanf("%d", &limS);

    int primo[limS + 1];

    for (int i = 2; i <= limS; i++) {
        primo[i] = 1;
    }

    for (int p = 2; p * p <= limS; p++) {
        if (primo[p] == 1) {
            for (int i = p * 2; i <= limS; i += p) {
                primo[i] = 0;
            }
        }
    }

    printf("Números primos entre 2 e %d:\n", limS);
    for (int p = 2; p <= limS; p++) {
        if (primo[p] == 1) {
            printf("%d ", p);
        }
    }
    printf("\n");

    return 0;
}
