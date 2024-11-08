#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("digite os coeficientes a, b e c: ");
    scanf("%d %d %d", &a, &b, &c);
    int delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("a raiz é um numero imaginário");
        return 0;
    }
    int r1, r2;
    r1 = (-b + sqrt(delta)) / (2 * a);
    r2 = (-b - sqrt(delta)) / (2 * a);
    printf("as raizes do polinômio %dx^2 + %dx + %d = 0 são: %d e %d", a, b, c, r1, r2);

    return 0;

}