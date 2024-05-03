#include <stdio.h>
#include <string.h>

void removeCaracter(char *str, char caracter){
    char *fim = str;
    while (*fim) {
        fim++;
    }
    fim--;
    while (str < fim) {
        if(*str == caracter){
            char *temp = str;
            while(*temp){
                *temp = *(temp+1);
                temp++;
            }
            fim--;
        }else{
            str++;
        }
    }
}

int main() {
    do{
    char str[50];
    char caracter;
    fgets (str, 50, stdin);
    scanf("%c", &caracter);
    removeCaracter(str, caracter);
    printf("%s\n", str);
    }while(1);

    return 0;
}
    