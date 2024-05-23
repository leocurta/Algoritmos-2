#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tMAX 1024
#define ASCII_SIZE 128
#define MAX_CODE_LENGTH 128

typedef struct noArvore {
    char valor;
    int freq;
    struct noArvore* esquerda;
    struct noArvore* direita;
} noArvore;

typedef struct ListNode {
    noArvore* dados;
    struct ListNode* proximo;
} ListNode;

char* lerArquivoTexto(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Nao foi possível abrir o arquivo: '%s'\n", nomeArquivo);
        return NULL;
    }
    char* conteudo = (char*) malloc(tMAX * sizeof(char));
    if (conteudo == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(arquivo);
        return NULL;
    }
    fread(conteudo, sizeof(char), tMAX, arquivo);
    conteudo[tMAX - 1] = '\0';
    fclose(arquivo);
    return conteudo;
}

int* frequenciaCaracter(const char* texto) {
    int* freq = (int*)calloc(256, sizeof(int));
    if (freq == NULL) {
        printf("Erro ao alocar memória para a frequência dos caracteres.\n");
        return NULL;
    }
    while (*texto != '\0') {
        freq[(int)*texto]++;
        texto++;
    }
    return freq;
}

noArvore* criarNoArvoreHuffman(char valor, int freq) {
    noArvore* no = (noArvore*)malloc(sizeof(noArvore));
    if (no == NULL) {
        printf("Erro ao alocar memória para o nó da árvore de Huffman.\n");
        return NULL;
    }
    no->valor = valor;
    no->freq = freq;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void adicionarNaListaOrdenada(ListNode** cabeca, noArvore* no) {
    ListNode* novoNo = (ListNode*)malloc(sizeof(ListNode));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó da lista encadeada.\n");
        return;
    }
    novoNo->dados = no;
    novoNo->proximo = NULL;
    if (*cabeca == NULL || (*cabeca)->dados->freq >= no->freq) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    } else {
        ListNode* atual = *cabeca;
        while (atual->proximo != NULL && atual->proximo->dados->freq < no->freq) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

noArvore* construirArvoreHuffman(int* freq) {
    ListNode* cabeca = NULL;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            noArvore* no = criarNoArvoreHuffman((char)i, freq[i]);
            adicionarNaListaOrdenada(&cabeca, no);
        }
    }
    while (cabeca->proximo != NULL) {
        noArvore* esquerda = cabeca->dados;
        noArvore* direita = cabeca->proximo->dados;
        noArvore* pai = criarNoArvoreHuffman('\0', esquerda->freq + direita->freq);
        pai->esquerda = esquerda;
        pai->direita = direita;
        cabeca = cabeca->proximo->proximo;
        adicionarNaListaOrdenada(&cabeca, pai);
    }
    return cabeca->dados;
}

char** comprimirtexto(noArvore* raiz, const char* texto) {
    char** codigosHuffman = (char**)calloc(256, sizeof(char*));
    if (codigosHuffman == NULL) {
        printf("Erro ao alocar memória para os códigos de Huffman.\n");
        return NULL;
    }
    char codigo[256] = {0};
    int indice = 0;
    printf("Dicionario de frequencias: \n");
    printf("------------\n");
    recursividade(raiz, codigo, &indice, codigosHuffman);
    printf("------------\n");
    return codigosHuffman;
}

void recursividade(noArvore* no, char* codigo, int* indice, char** codigosHuffman) {
    if (no->esquerda == NULL && no->direita == NULL) {
        codigo[*indice] = '\0';
        codigosHuffman[(int)no->valor] = strdup(codigo);
        printf("%c: %s\n", no->valor, codigosHuffman[(int)no->valor]);
        return;
    }
    codigo[(*indice)++] = '0';
    recursividade(no->esquerda, codigo, indice, codigosHuffman);
    codigo[(*indice)--] = '0';
    codigo[(*indice)++] = '1';
    recursividade(no->direita, codigo, indice, codigosHuffman);
    codigo[(*indice)--] = '1';
}

void salvarBinario(const char* nomeArquivo, char* textoCodificado, size_t tamanhoTextoCodificado) {
    FILE* arquivoBinario = fopen(nomeArquivo, "wb");
    if (arquivoBinario == NULL) {
        printf("Erro ao abrir o arquivo binário.\n");
        return;
    }
    fwrite(textoCodificado, 1, tamanhoTextoCodificado, arquivoBinario);
    printf("Texto comprimido salvo em %s\n", nomeArquivo);
    printf("Texto comprimido: %s\n", textoCodificado);
    fclose(arquivoBinario);
}

void descomprimirArquivo(const char* nomeArquivo, noArvore* arvoreHuffman) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }
    noArvore* atual = arvoreHuffman;
    char bite;
    while (fread(&bite, sizeof(char), 1, arquivo)) {
        if (bite == '0') {
            atual = atual->esquerda;
        } else if (bite == '1') {
            atual = atual->direita;
        }
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("%c", atual->valor);
            atual = arvoreHuffman;
        }
    }
    fclose(arquivo);
}

int main() {
    const char* nomeArquivoEntrada = "C:\\Users\\uchih\\Documents\\arquivo.txt";
    const char* nomeArquivoBinario = "C:\\Users\\uchih\\Documents\\binario.txt";

    char* texto = lerArquivoTexto(nomeArquivoEntrada);
    if (texto == NULL) {
        return 1;
    } else {
        printf("Texto lido com sucesso: %s\n", texto);
        printf("\n");
    }
    int* freq = frequenciaCaracter(texto);
    if (freq == NULL) {
        free(texto);
        return 1;
    }
    noArvore* raiz = construirArvoreHuffman(freq);
    char** codigosHuffman = comprimirtexto(raiz, texto);
    if (codigosHuffman == NULL) {
        free(texto);
        free(freq);
        return 1;
    }
    char textoCodificado[100000];
    size_t tamanhoTextoCodificado = 0;
    for (size_t i = 0; i < strlen(texto); i++) {
        strcat(textoCodificado, codigosHuffman[(int)texto[i]]);
        tamanhoTextoCodificado += strlen(codigosHuffman[(int)texto[i]]);
    }
    salvarBinario(nomeArquivoBinario, textoCodificado, tamanhoTextoCodificado);
    free(texto);
    free(freq);
    for (int i = 0; i < 256; i++) {
        free(codigosHuffman[i]);
    }
    free(codigosHuffman);
    descomprimirArquivo(nomeArquivoBinario, codigosHuffman);

    return 0;
}