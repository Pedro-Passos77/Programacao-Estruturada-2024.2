#include <stdio.h>

int main() {
    int a = 3;
    float b = (float) a/2;
    float c = b + 3.1;

    printf("Valores possíveis para ‘c’?\n1. c = %g\n", c);

    b = a/2;
    c = b + 3.1;
    printf("2. c = %g\n3. c = %.0f\n", c, c);

    return 0;
}