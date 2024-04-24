#include <stdio.h>

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    
    int primo = 1;
    
    if (num <= 1) {
        primo = 0;
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                primo = 0;
                break;
            }
        }
    }
    
    if (primo) {
        printf("%d é um número primo.\n", num);
    } else {
        printf("%d não é um número primo.\n", num);
    }
    
    return 0;
}