#include <stdio.h>
#define INF 2000000000

int main(void) {
    int n, m, i, j;
    printf("A partir de qual número devemos buscar os primos? ");
    scanf("%d", &n);
    m = 1;
    if (n == 1) {
        printf("%d ", n);
        m++;
    }
    for (i = n; m <= n; i++) {
        for (j = 2; j <= i; j++) {
            if (i % j == 0 && i > j) 
                break;
            if (i % j == 0 && i == j) {
                printf("%d ", i);
                m++;
            }
        }
    }
    return 0;
}
