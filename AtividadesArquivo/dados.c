#include <stdio.h>

void imprimirDados(FILE *arquivo) {
    char nome[50];
    char cpf[12];
    float coeficiente;

    fscanf(arquivo, "%s\n", nome);
    fscanf(arquivo, "%s\n", cpf);
    fscanf(arquivo, "%f\n", &coeficiente);
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

    FILE *arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    fprintf(arquivo, "%s\n", nome);
    fprintf(arquivo, "%s\n", cpf);
    fprintf(arquivo, "%.2f\n", coeficiente);

    fclose(arquivo);

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    imprimirDados(arquivo);

    fclose(arquivo);

    return 0;
}