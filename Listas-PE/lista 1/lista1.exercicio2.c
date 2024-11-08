#include  <stdio.h>

int main() {
    int a,b,c, media, M, m;
    printf("Digite os valores a verificar: ");
    scanf("%d" "%d" "%d", &a, &b, &c);
    media = (a + b + c) / 3;
    if(a >= b && a >= c) M = a;
    else if(b >= a && b >= c) M = b;
    else if(c >= a && c >= b) M = c;

    if (a <= b && a <= c) m = a;
    else if (b <= a && b <= c) m = b;
    else if (c <= a && c <= b) m = c;
    printf("o maior numero é: %d, o menor é: %d e a media é: %d", M, m, media);
    return 0;
}