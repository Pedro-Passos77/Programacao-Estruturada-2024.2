#include  <stdio.h>

int main() {
    int a, div = 0;
    printf("Digite um numero para verificar: ");
    scanf("%d", &a);
    for(int i = 1; i <= a; i++) {
        if(a % i == 0) {
            div++;
        }
    }
        if(div == 2) printf("%d é primo", a);
        else printf("%d não é primo", a);
    return 0;
}