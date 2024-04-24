#include <stdio.h>
#include <string.h>

typedef struct{
    float n1, n2,n3;
    char nome[50];
    int matricula;
} Pessoa;

int main(){
    Pessoa aluno[5], maiornota1, maiormedia, menormedia;
    float media, maiormedianota = 0, menormedianota =10;

    for (int i=0; i<5; i++){
        printf("\nDigite o nome do aluno %d: ", i+1);
        scanf("%s", aluno[i].nome);
        printf("\nDigite a nota 1 do aluno: ");
        scanf("%f", &aluno[i].n1);
        printf("\nDigite a nota 2 do aluno: ");
        scanf("%f", &aluno[i].n2);
        printf("\nDigite a nota 3 do aluno: ");
        scanf("%f", &aluno[i].n3);

        media = (aluno[i].n3 + aluno[i].n2 + aluno[i].n1)/3;
        
        if(aluno[i].n1 > maiornota1.n1){
            maiornota1 = aluno[i];
        }

        if (media > maiormedianota){
            maiormedianota = media;
            maiormedia = aluno[i];
        }
        if (media < maiormedianota){
            menormedianota = media;
            menormedia = aluno[i];
        }
    }
    printf("\nAluno com maior nota na primeira prova: %s\n", maiornota1.nome);
    printf("Aluno com maior media geral: %s\n", maiormedia.nome);
    printf("Aluno com menor media geral: %s\n", menormedia.nome);
    return 0;
}
    