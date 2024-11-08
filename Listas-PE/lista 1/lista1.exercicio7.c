#include <math.h>
#include <stdio.h>

int main() {
    float a;
    printf("digite o numero que você deseja arredondar: ");
    scanf("%f", &a);

    printf("%f arrendondado para o par mais próximo = %.1f\n", a, round(a));
    printf("%f arrendondado para cima = %.1f\n", a, ceil(a));
    printf("%f arrendondado para baixo = %.1f\n", a, floor(a));
    printf("%f truncado = %g\n", a, trunc(a));
    return 0;
}