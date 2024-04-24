#include <stdio.h>

int fibo(int n){
    if (n<2){
        return n;
    } else {
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){
    int n, fib;
    do{
    scanf("%d", &n);

    fib = fibo(n);
    printf("%d\n", fib);
    } while (n != -1);
    return 0;
}