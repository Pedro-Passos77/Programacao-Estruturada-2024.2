#include <stdio.h>
int main(void){
    int n;
    printf("até quais números devemos achar primos? ");
    scanf("%d", &n);
    int numeros[n-1];
    for(int i = 0; i <= n - 1; i++){
        numeros[i] = i + 2;
    }
    for(int x = 0; x < n-1; x++)
        for(int y = x+1; y <= n - 1; y++)
            if(numeros[x] != 0 && numeros[y] % numeros[x] == 0){
                numeros[y] = 0;
            }
    for(int j=0; j <= n - 1; j++)
        if(numeros[j] != 0){
            printf("%d", numeros[j]);
        }
    return 0;
}