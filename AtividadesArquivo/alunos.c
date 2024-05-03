#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cpf[15];
    float coeficiente;
} Aluno;

void gravarAlunos(Aluno* alunos, const char* filename) {
    FILE *arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(arquivo, "%s %s %.2f\n", alunos[i].nome, alunos[i].cpf, alunos[i].coeficiente);
    }
    fclose(arquivo);
}

void encontrarEGravar(Aluno* alunos, const char* nomeArquivo, const char* nome) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            fprintf(arquivo, "%s %s %.2f\n", alunos[i].nome, alunos[i].cpf, alunos[i].coeficiente);
            break;
        }
    }
    fclose(arquivo);
}

int main() {
    Aluno alunos[5] = {
        {"Joao", "123.456.789-00", 8.5},
        {"Maria", "987.654.321-00", 7.8},
        {"Pedro", "456.789.123-00", 9.2},
        {"Ana", "321.654.987-00", 6.9},
        {"Lucas", "789.123.456-00", 8.0}
    };

    gravarAlunos(alunos, "alunos.txt");
    encontrarEGravar(alunos, "alunos_encontrado.txt", "Maria");

    return 0;
}