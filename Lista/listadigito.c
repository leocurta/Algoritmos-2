#include <stdio.h>
#include <stdlib.h>

typedef struct digito {
    int digito;
    struct digito *prox;
} Digito;

Digito* inicializar() {
    return NULL;
}

Digito* inserirFinal(Digito *lista, int valor) {
    Digito *novo = (Digito*) malloc(sizeof(Digito));
    novo->digito = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        lista = novo;
    } else {
        Digito *temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }

    return lista;
}

void imprimir(Digito *lista) {
    Digito *temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->digito);
        temp = temp->prox;
    }
    printf("\n");
}

Digito* removerFinal(Digito *lista) {
    if (lista == NULL) {
        return NULL;
    }

    Digito *ultimo = lista;
    Digito *penultimo = NULL;

    while (ultimo->prox != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }

    if (penultimo != NULL) {
        penultimo->prox = NULL;
    } else {
        lista = NULL;
    }

    free(ultimo);
    return lista;
}

int main() {
    Digito *lista = inicializar();

    lista = inserirFinal(lista, 1);
    lista = inserirFinal(lista, 2);
    lista = inserirFinal(lista, 3);

    printf("Lista inicial: ");
    imprimir(lista);

    lista = removerFinal(lista);

    printf("Lista apos remover o ultimo elemento: ");
    imprimir(lista);

    return 0;
}