#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int peso;
    float custoBeneficio;
} Item;

int comparar(const void *a, const void *b) {
    return (((Item*)b)->custoBeneficio - ((Item*)a)->custoBeneficio);
}

void mochilaFracionaria(Item itens[], int n, int W) {
    qsort(itens, n, sizeof(Item), comparar);

    int i;
    float totalValor = 0.0;
    int totalPeso = 0;

    for (i = 0; i < n; i++) {
        if (totalPeso + itens[i].peso <= W) {
            totalPeso += itens[i].peso;
            totalValor += itens[i].valor;
        } else {
            int restante = W - totalPeso;
            totalValor += itens[i].valor * ((double) restante / itens[i].peso);
            break;
        }
    }

    printf("O valor total na mochila é %.2f\n", totalValor);
}

int main() {
    Item itens[] = {{400, 40, 6.0}, {300, 30, 5.0}, {200, 20, 4.0}, {100, 10, 2.5}};
    int n = sizeof(itens) / sizeof(itens[0]);
    int W = 50;

    mochilaFracionaria(itens, n, W);

    return 0;
}