#include <stdio.h>
#define pi 3.14159265

void calc_circulo(float r, float *circunferencia, float *area) {
    *circunferencia = 2 * pi * r;
    *area = pi * r * r;
}

int main() {
    float r;
    printf("Qual o raio do círculo?: ");
    scanf("%f", &r);

    float circunferencia, area;
    calc_circulo(r, &circunferencia, &area);

    printf("O círculo tem área %g e circunferência de %g\n", area, circunferencia);
    return 0;
}
