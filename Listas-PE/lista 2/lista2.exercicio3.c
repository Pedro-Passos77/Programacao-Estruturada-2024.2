#include <stdio.h>

int main(void) {
    int n, termo1 = 1, termo2 = 1, termoN;

    printf("Digite o número de termos da série de Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um número positivo.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == 2) {
            printf("%d ", 1);
        } else {
            termoN = termo1 + termo2;
            printf("%d ", termoN);
            termo1 = termo2;
            termo2 = termoN;
        }
    }
    printf("\n");
    return 0;
}
