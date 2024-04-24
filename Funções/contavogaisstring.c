#include <stdio.h>

int countVowels(char *str) {
    // Caso base: a string está vazia
    if (*str == '\0') {
        return 0;
    }
    
    // Verifica se o primeiro caractere é uma vogal
    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
        *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
        // Se for uma vogal, retorna 1 + o número de vogais na substring restante
        return 1 + countVowels(str + 1);
    } else {
        // Se não for uma vogal, retorna o número de vogais na substring restante
        return countVowels(str + 1);
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);
    
    int numVowels = countVowels(str);
    printf("Número de vogais: %d\n", numVowels);
    
    return 0;
}