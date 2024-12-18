#include <stdio.h>

int soma_impares(int vetor[], int tamanho, int indice) {
    // Caso base: se o índice for igual ao tamanho do vetor, retorna 0
    if (indice == tamanho) {
        return 0;
    }

    // Se o elemento no índice atual for ímpar, soma esse valor
    if (vetor[indice] % 2 != 0) {
        return vetor[indice] + soma_impares(vetor, tamanho, indice + 1);
    }

    // Se o elemento não for ímpar, apenas faz a chamada recursiva para o próximo índice
    return soma_impares(vetor, tamanho, indice + 1);
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int resultado = soma_impares(vetor, tamanho, 0);
    printf("Soma dos números ímpares: %d\n", resultado);

    return 0;
}
