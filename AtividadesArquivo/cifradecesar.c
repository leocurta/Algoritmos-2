#include <stdio.h>
#include <stdlib.h>


void criptografar(char frase[], int chave) {
    for (int i = 0; frase[i] != '\0';i++){
        if (frase[i] >= 'A' && frase[i] <= 'Z') {
            frase[i] = (frase[i] - 'A' + chave) % 26 + 'A';
        } else if (frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = (frase[i] - 'a' + chave) % 26 + 'a';
        }
    }
}

void descriptografar(char frase[], int chave) {
    criptografar(frase, 26 - chave);
}

int main() {
    char frase[100];
    int chave;

    printf("Digite a frase a ser criptografada: ");
    fgets(frase, 100, stdin);
    printf("digite a chave:");
    scanf("%d", &chave);

    if (frase[strlen(frase) - 1] == '\n') {
        frase[strlen(frase) - 1] = '\0';
    }
    criptografar(frase, chave);

    FILE *arquivo = fopen("mensagem_cifrada.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(arquivo, "%s", frase);
    fclose(arquivo);

    printf("Frase criptografada e salva no arquivo 'mensagem_cifrada.txt'.\n");
    printf("Frase criptografada: %s\n", frase);
    descriptografar(frase, chave);
    printf("Frase descriptografada: %s\n", frase);
    return 0;
}