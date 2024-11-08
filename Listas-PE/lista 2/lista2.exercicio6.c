#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int z,tentativas= 0, x = 10000;

    srand(time(NULL));
    z =  rand() % 100;
    while(x!=z) {
        printf("escolha um valor: ");
        scanf("%d", &x);
        tentativas++;
        if( x > z) printf("o numero secreto é menor\n");
        if( x < z) printf("o numero secreto é maior\n");
    }
    printf("você digitou %d e o numero secreto é %d, portanto, acertou. o numero de tentativas foi: %d", x, z, tentativas);
    return 0;
}