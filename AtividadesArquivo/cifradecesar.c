#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void criptografar(char* message, int shift) {
    char ch;
    for(int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + shift;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}

void decrypt(char* message, int shift) {
    char ch;
    for(int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - shift;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - shift;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

void write_file(const char* filename, const char* message) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file %s", filename);
        return;
    }
    fprintf(file, "%s", message);
    fclose(file);
}

char* read_file(const char* filename) {
    char* buffer = 0;
    long length;
    FILE *file = fopen(filename, "r");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, file);
        }
        fclose(file);
    }
    return buffer;
}

int main() {
    char message[MAX];
    int shift;

    printf("Entre com a mensagem para ser criptografada: ");
    fgets(message, MAX, stdin);
    printf("Digite a chave: ");
    scanf("%d", &shift);

    criptografar(message, shift);
    printf("Mensagem criptografada: %s", message);
    write_file("encrypted.txt", message);

    char* encrypted_message = read_file("encrypted.txt");
    decrypt(encrypted_message, shift);
    printf("Mensagem descriptografada: %s", encrypted_message);

    return 0;
}