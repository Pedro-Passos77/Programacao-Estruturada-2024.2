#include <stdio.h>

// Função para inicializar o vetor com as letras minúsculas do alfabeto
void inicializarAlfabeto(char vetor[]) {
    for (int i = 0; i < 26; i++) {
        vetor[i] = 'a' + i; // Preenche o vetor com as letras 'a' até 'z'
    }
}

// Função para imprimir o conteúdo do vetor
void imprimirVetor(char vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", vetor[i]); // Imprime cada letra com um espaço
    }
    printf("\n"); // Nova linha após imprimir todas as letras
}

int main() {
    char alfabeto[26]; // Declaração do vetor de tamanho 26

    // Inicializa o vetor com as letras do alfabeto
    inicializarAlfabeto(alfabeto);

    // Imprime o conteúdo do vetor
    imprimirVetor(alfabeto, 26);

    return 0;
}
