#include <stdio.h>
#include <math.h>

int main() {
    int base, expoente, resultado;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    resultado = pow(base, expoente);
    printf("%d elevado a %d é igual a %d", base, expoente, resultado);
    return 0;
}