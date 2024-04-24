#include <stdio.h>
#include <math.h>
#include <string.h>

struct Veiculo{
    char modelo[100], marca[100], cor[100];
    int ano, valor;
};

typedef struct Veiculo Veiculo;

int verificarmaiscaro(Veiculo veiculo[10], int *veic){
    int maiscaro = veiculo[0].valor;
    *veic =0;
    for(int i=1; i<3; i++){
        if (veiculo[i].valor > maiscaro){
            maiscaro = veiculo[i].valor;
            *veic = i;
        }
    }
    return maiscaro;
}

int main(){
    Veiculo veiculo[3];
    int veic;
    for (int i=0; i<3; i++){
       printf("Insira os dados dos veiculo %d: \n", i+1);
       printf("Modelo: ");
       scanf("%s", veiculo[i].modelo);
       fflush(stdin);

       printf("Marca: ");
       scanf("%s", veiculo[i].marca);
       fflush(stdin);

       printf("Cor: ");
       scanf("%s", veiculo[i].cor);
       fflush(stdin);

      printf("Ano: ");
      scanf("%d", &veiculo[i].ano);
      fflush(stdin);

      printf("Valor: ");
      scanf("%d", &veiculo[i].valor);
      fflush(stdin);
    } 
    int maior= verificarmaiscaro(veiculo, &veic);
    printf("\n");
    printf("O veiculo mais caro custa: %d\n", maior);
    printf("Marca: %s\nModelo: %s\nAno: %d\nCor: %s\n", veiculo[veic].marca, veiculo[veic].modelo, veiculo[veic].ano, veiculo[veic].cor);
    return 0;
}