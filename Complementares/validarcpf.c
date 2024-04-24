#include <stdio.h>

int main (){
    char cpf[15];
    for(int i=0; i<15; i++){
        if (i ==3 || i ==7 || i == 11){
            scanf(" %c", &cpf[i+1]);
        }
    scanf(" %c", &cpf[i]);
    }
    cpf[3]='.';
    cpf[7]='.';
    cpf[11]='-';
    cpf[15]='\0';
    for(int i=0; i<15; i++){
        printf("%c", &cpf[i]);
    }
    return 0;
}