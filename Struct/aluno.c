#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    int coeficiente;
} Aluno;

void bubble_sort(Aluno aluno[], int n) {
    int k, j;
    int aux, aux1;
    char aux2[50];
    for (k = 0; k<n-1; k++){
        for (j=0; j<n-k-1; j++){
            if (aluno[j].coeficiente < aluno[j+1].coeficiente){
                aux = aluno[j].coeficiente;
                aluno[j].coeficiente = aluno[j+1].coeficiente;
                aluno[j+1].coeficiente = aux;
                aux1= aluno[j].matricula;
                aluno[j].matricula = aluno[j+1].matricula;
                aluno[j+1].matricula = aux1;
                strcpy(aux2,aluno[j].nome);
                strcpy(aluno[j].nome,aluno[j+1].nome);
                strcpy(aluno[j+1].nome , aux2);

            }
        }
    }
}

int main(){
   int n = 3;
   Aluno aluno[n];
   for (int i=0; i<n; i++){
     printf("Digite o nome do aluno %d: \n",i+1);
     scanf("%s", aluno[i].nome);
     printf("Digite a matricula do aluno %d: \n",i+1);
     scanf("%d", &aluno[i].matricula);
     printf("Digite o coeficiente do aluno %d: \n",i+1);
     scanf("%d", &aluno[i].coeficiente);
   }

   bubble_sort(aluno, n);
   printf("Alunos em ordem decrescente: \n");
   for (int i = 0; i< n; i++ ){
       printf("Nome: %s, Matricula: %d, Coeficiente: %d\n", aluno[i].nome, aluno[i].matricula, aluno[i].coeficiente);
   }
   return 0;
}