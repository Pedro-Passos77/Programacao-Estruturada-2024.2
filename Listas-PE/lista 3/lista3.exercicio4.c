#include <stdio.h>

int divs(int n, int *min, int *max) {
    int is_prime = 1;

    *min = n;
    *max = 2;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            is_prime = 0;
            if (i < *min) *min = i;
            if (i > *max) *max = i;
        }
    }

    if (is_prime) {
        *min = 0;
        *max = 0;
        return 0;
    }

    return 1;
}

int main() {
    int n, min, max;

    printf("Digite um número: ");
    scanf("%d", &n);

    if (divs(n, &min, &max) == 0) {
        printf("%d é primo.\n", n);
    } else {
        printf("%d não é primo.\n", n);
        printf("Menor divisor: %d\n", min);
        printf("Maior divisor: %d\n", max);
    }

    return 0;
}
