#include <stdio.h>
#include <stdlib.h>

int quebrar_final(int a) {
    return a % 100;
}

int quebrar_inicio(int a) {
    while (a >= 100) {
        a /= 10;
    }
    return a;
}

int main(void) {
    int x, z, y, calc, verif;
    printf("escolha: ");
    scanf("%d", &y);
    if (y < 1000) {
        printf("0");
        return 0; 
    }
    x = quebrar_final(y);
    z = quebrar_inicio(y);
    calc = (x + z) * (x +z);
    verif = (z * 100) + x;
    if (calc == verif) printf("1");
    else printf("0");
    
    return 0;
}