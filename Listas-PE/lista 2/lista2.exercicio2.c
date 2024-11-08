#include <stdio.h>

int soma_Nimpares(int n);

int main(void) {
    int n;
    printf("Digite a quantidade de ímpares a somar: ");
    scanf("%d", &n);
    printf("A soma dos %d primeiros ímpares é %d\n", n, soma_Nimpares(n));
    return 0;
}

int soma_Nimpares(int n) {
    int soma = 0, primo = 1;

    for (int i = 1; i <= n; i++) {
        soma += primo;
        primo += 2;
    }

    return soma;
}
