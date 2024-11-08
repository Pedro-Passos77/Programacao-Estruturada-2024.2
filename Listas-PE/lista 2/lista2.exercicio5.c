#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int z, x, controle = 0, soma = 0, qnumeros = 0;

    srand(time(NULL));
    z = 1 + rand() % 100;  // Gera X entre 1 e 100
    int numeros[100];

    do {
        printf("Digite o valor de x: ");
        scanf("%d", &x);
        numeros[qnumeros] = x;
        qnumeros++;
        soma += x;
    } while (soma < z);
    if(qnumeros == 1) {
        printf("%d (%d = %d)", qnumeros, numeros[qnumeros-1], soma);
        return 0;
    }
    printf("%d (", qnumeros);
    for(int i = 0; i < qnumeros - 1; i++) {
        printf("%d+", numeros[i]);

    }
    printf("%d = %d)",numeros[qnumeros-1], soma);

    return 0;
}
