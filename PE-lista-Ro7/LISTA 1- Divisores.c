#include <stdio.h>

int main(void) {
    int n, i;

    while (1) {
        printf("Escolha qual número você deseja saber os divisores: ");
        scanf("%d", &n);

        for (i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                printf("%d ", i); 
            }
        }
        printf("%d\n", n); 
    }

    return 0; 
}