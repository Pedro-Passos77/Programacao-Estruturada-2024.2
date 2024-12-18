#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume;
    float preco;
} Livro;

typedef struct Biblioteca {
    Livro **V;
    int nLivros;
} Biblioteca;

Livro* fillLivro() {
    Livro* livro = (Livro*) malloc(sizeof(Livro));

    printf("Digite o ano de publicação: ");
    scanf("%d", &livro->ano);

    printf("Digite o título do livro: ");
    getchar();
    fgets(livro->titulo, 100, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = 0;

    printf("Digite o autor do livro: ");
    fgets(livro->autor, 100, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = 0;

    printf("Digite o número de exemplares: ");
    scanf("%d", &livro->nVolume);

    printf("Digite o preço do livro: ");
    scanf("%f", &livro->preco);

    return livro;
}

Biblioteca* fillBiblioteca(int numLivros) {
    Biblioteca* biblioteca = (Biblioteca*) malloc(sizeof(Biblioteca));
    biblioteca->nLivros = numLivros;
    biblioteca->V = (Livro**) malloc(numLivros * sizeof(Livro*));

    for (int i = 0; i < numLivros; i++) {
        biblioteca->V[i] = fillLivro();
    }

    return biblioteca;
}

void valorBiblioteca(Biblioteca* b1, int numLivros) {
    float total = 0;
    for (int i = 0; i < numLivros; i++) {
        total += b1->V[i]->nVolume * b1->V[i]->preco;
    }
    printf("Valor total gasto na biblioteca: R$ %.2f\n", total);
}

Livro* maiorBiblioteca(Biblioteca* b1, int numLivros) {
    Livro* maior = b1->V[0];

    for (int i = 1; i < numLivros; i++) {
        if (b1->V[i]->nVolume > maior->nVolume) {
            maior = b1->V[i];
        }
    }

    return maior;
}

int main() {
    int numLivros;

    printf("Digite o número de livros na biblioteca: ");
    scanf("%d", &numLivros);

    // Preenche a biblioteca com os livros
    Biblioteca* biblioteca = fillBiblioteca(numLivros);

    // Calcula e exibe o valor total gasto na biblioteca
    valorBiblioteca(biblioteca, numLivros);

    // Exibe o livro com o maior número de exemplares
    Livro* livroMaior = maiorBiblioteca(biblioteca, numLivros);
    printf("Livro com maior número de exemplares: %s, Autor: %s, Exemplares: %d\n", livroMaior->titulo, livroMaior->autor, livroMaior->nVolume);

    // Liberação de memória
    for (int i = 0; i < numLivros; i++) {
        free(biblioteca->V[i]);  // Libera cada livro
    }
    free(biblioteca->V);  // Libera o vetor de livros
    free(biblioteca);  // Libera a estrutura da biblioteca

    return 0;
}
