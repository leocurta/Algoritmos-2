#include <stdio.h>

int contaVogais(char *str) {
    if (*str == '\0') {
        return 0;
    }
    
    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
        *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {

        return 1 + contaVogais
    (str + 1);
    } else {

        return contaVogais
    (str + 1);
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);
    
    int numeroDeVogais = contaVogais
(str);
    printf("Número de vogais: %d\n", numeroDeVogais);
    
    return 0;
}