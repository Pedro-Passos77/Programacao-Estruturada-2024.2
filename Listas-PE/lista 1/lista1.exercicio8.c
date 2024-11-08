#include <stdio.h>

int total_de_notas(int valor) {
    int a, b, c, d , e, f, g, total;
    a = valor / 100;
    valor %= 100;
    b = valor / 50;
    valor %= 50;
    c = valor / 20;
    valor %= 20;
    d = valor / 10;
    valor %= 10;
    e = valor / 5;
    valor %= 5;
    f = valor / 2;
    valor %= 2;
    total = a + b + c + d + e + f+ valor;
    return total;
}

int main() {
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    printf("o menor número de notas é %d", total_de_notas(valor));

    return 0;
}