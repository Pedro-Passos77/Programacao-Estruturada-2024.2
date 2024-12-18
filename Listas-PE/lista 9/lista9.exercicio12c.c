void valorBiblioteca(Biblioteca* b1, int numLivros) {
    float total = 0;

    // Calcula o total gasto com todos os livros
    for (int i = 0; i < numLivros; i++) {
        total += b1->V[i]->nVolume * b1->V[i]->preco;
    }

    printf("Valor total gasto na biblioteca: R$ %.2f\n", total);
}
