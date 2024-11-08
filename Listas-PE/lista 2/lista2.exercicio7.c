#include <stdio.h>

int main(void) {
    float horas, valor, total;
    printf("digite o numero de horas trabalhadas na semana: ");
    scanf("%f", &horas);
    printf("digite o valor da hora trabalhada: ");
    scanf("%f", &valor);
    if(horas <= 40) {
        total = horas * valor;
        printf("o total a receber é: %g", total);
    }
    else if(horas >= 41 && horas <= 60 ) {
        total = ((horas - 40) * valor) * 1.5 + valor * 40;
        printf("o total a receber é: %g", total);

    }
    else if(horas >= 61) {
        total = ((horas- 60) * valor) * 2 + 20 * valor *1.5 + 40 * valor;
        printf("o total a receber é: %g", total);
    }

    return 0;
}