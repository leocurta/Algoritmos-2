#include <stdio.h>

void imprimirDados(FILE *arquivo) {
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    char nome[50];
    char cpf[12];
    float coeficiente;

    fscanf(arquivo, "Nome: %s\n", nome);
    fscanf(arquivo, "CPF: %s\n", cpf);
    fscanf(arquivo, "Coeficiente: %f\n", &coeficiente);
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Coeficiente: %.2f\n", coeficiente);
}

int main() {
    char nome[50];
    char cpf[12];
    float coeficiente;

    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    printf("Digite o coeficiente: ");
    scanf("%f", &coeficiente);


    FILE *arquivo = fopen("dados.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    fprintf(arquivo, "Nome: %s\n", nome);
    fprintf(arquivo, "CPF: %s\n", cpf);
    fprintf(arquivo, "Coeficiente: %.2f\n", coeficiente);
    fclose(arquivo);

    printf("Dados gravados com sucesso no arquivo dados.txt.\n");
    arquivo = fopen("dados.txt", "r");
    imprimirDados(arquivo);
    fclose(arquivo);

    return 0;
}
