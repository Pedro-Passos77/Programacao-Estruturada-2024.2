#include <stdio.h>

int main() {
    float r1, r2; char op;
    printf("Insira a operação: ");
    scanf("%f %c %f", &r1, &op, &r2);
    switch (op) {
        case '+': r1 += r2; break;
        case '-': r1 -= r2; break;
        case '*': r1 *= r2; break;
        case '/': r1 /= r2; break;
        default: printf("operação inválida\n");
        return 1;
    }
    printf("o resultado da operação é: %g", r1);

    return 0;
}