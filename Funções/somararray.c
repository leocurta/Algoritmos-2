#include <stdio.h>
#include <math.h>
#include <string.h>

int somarelementosarray(int array[], int n){
     if (n == 0) {
        return 0;
     } else {
        return array[n-1] + somarelementosarray(array, n-1);
    }
}
  
int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    printf("%d\n", somarelementosarray(array, n));
    return 0;
}