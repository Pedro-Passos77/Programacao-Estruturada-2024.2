#include <stdio.h>

int get_mdc(int a, int b) {
    int r;
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int a, b, y;
    while (1) {
        printf("Entre dois valores para A e B (ou 0 0 para sair): ");
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        y = get_mdc(a, b);
        printf("O MDC dos números é: %d\n", y);
    }
    return 0;
}
