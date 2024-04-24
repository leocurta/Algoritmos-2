#include <stdio.h>

int main() {
    int m[6][6];
    int valor = 2;

    for (int i = 0; i < 6; i++) {
        m[i][i] = 0;
    }
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < i; j++) {
            m[i][j] = valor;
            valor += 2;
        }
    }
    valor = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            m[i][j] = valor;
            valor += 2;
        }
    }
    for (int i = 0; i < 6; i++) {
        m[i][5 - i] = 0;
    }
    printf("Matriz 6x6:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}