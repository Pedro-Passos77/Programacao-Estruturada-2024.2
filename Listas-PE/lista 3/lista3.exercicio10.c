#include <stdio.h>

float media(int n, float *v);

int main() {
    int n, i;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    float v[n];
    printf("Digite os elementos:\n");
    for(i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &v[i]);
    }

    float resultado = media(n, v);
    printf("A média dos elementos é: %.2f\n", resultado);

    return 0;
}

float media(int n, float *v) {
    float soma = 0;
    for(int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}
