Biblioteca* fillBiblioteca(int numLivros) {
    Biblioteca* biblioteca = (Biblioteca*) malloc(sizeof(Biblioteca));
    biblioteca->nLivros = numLivros;

    // Alocando espaço para os livros
    biblioteca->V = (Livro**) malloc(numLivros * sizeof(Livro*));

    // Preenchendo os livros com dados fornecidos pelo usuário
    for (int i = 0; i < numLivros; i++) {
        biblioteca->V[i] = fillLivro();  // Chama a função fillLivro para preencher os dados de cada livro
    }

    return biblioteca;
}
