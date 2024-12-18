Livro* maiorBiblioteca(Biblioteca* b1, int numLivros) {
    Livro* maior = b1->V[0];  // Inicializa com o primeiro livro

    for (int i = 1; i < numLivros; i++) {
        if (b1->V[i]->nVolume > maior->nVolume) {
            maior = b1->V[i];  // Atualiza se encontrar um livro com mais exemplares
        }
    }

    return maior;
}
