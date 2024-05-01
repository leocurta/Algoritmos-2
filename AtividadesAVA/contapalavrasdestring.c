#include <stdio.h>

int contarPalavras(char *str) {
    int cont = 0;
    while (*str) {
        if (*str == ' ' || *str == '\n') {
            cont++;
        }
        str++;
    }

    return cont;
}

int main() {
    char str[50];
    fgets (str, 50, stdin);
    int n = contarPalavras(str);

    printf("Número de palavras: %d\n", n);

    return 0;
}