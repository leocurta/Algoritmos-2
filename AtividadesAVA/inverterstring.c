#include <stdio.h>

void inverterString(char *str) {
    char *fim = str;
    while (*fim) {
        fim++;
    }
    fim--;

    while (str < fim) {
        char temp = *str;
        *str = *fim;
        *fim = temp;
        str++;
        fim--;
    }
}

int main() {
    do{
    printf("\nDigite uma string: ");
    char str[50];
    fgets (str, 50, stdin);
    inverterString(str);
    printf("%s\n", str);
    }while(1);

    return 0;
}