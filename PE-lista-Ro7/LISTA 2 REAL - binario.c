#include <stdio.h>

int main(void){
    int a;
    int binario[32];
    int cont = 0;
    printf("escolha qual numero será transformado em binário: ");
    scanf("%d", &a);
    while(a > 0){
        binario[cont] = a % 2;
        a = a / 2;
        cont++;
    }
    printf("o resultado %d em binário é: ", a);
    for(int i = cont-1; i >= 0; i--){
        printf("%d", binario[i]);
    }
    return 0;
}
