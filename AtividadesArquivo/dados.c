#include <stdio.h>

int main(){

FILE *f = fopen("C:\\Users\\uchih\\OneDrive\\Documents\\dados.txt", "w");
if(f == NULL){
    printf("Erro na abertura!\n");
}

return 0;
}