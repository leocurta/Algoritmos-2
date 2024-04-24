#include <stdio.h>

int main() {
    char v[20];

    for (int i = 0; i < 20; i++) {
        v[i] = 'a' + i;
        printf("%c ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++) {
        v[i] = v[i] - 32;
    }

    for (int i = 0; i < 20; i++) {
        printf("%c ", v[i]);
    }

    return 0;
}