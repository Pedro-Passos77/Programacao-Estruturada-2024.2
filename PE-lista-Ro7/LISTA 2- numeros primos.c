#include <stdio.h>

int main(void) {
    int u, n, i, j, d;

    while (1) {
        printf("Deseja saber os números primos entre 1 e qual número?: ");
        scanf("%d", &n);
        
        if (n < 1) {
            break;
        }
        u = 1;
        printf("%d ", u);
        for (i = 2; i <= n; i++) {
            for (j = 2; j <= i; j++) {
                if (i % j == 0 && i > j) { 
                    break;
                }
                if (i % j == 0 && i == j) printf("%d ", i);
            }  
        }
        printf("\n");
    }
    
    return 0;
}
