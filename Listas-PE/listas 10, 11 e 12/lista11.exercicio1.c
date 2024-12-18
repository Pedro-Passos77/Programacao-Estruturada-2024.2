Elemento* filtra(Elemento *lst, float min, float max) {
    Elemento *ant = NULL, *atual = lst;

    while (atual != NULL) {
        if (atual->info < min || atual->info > max) {
            // Elemento a ser removido
            if (ant == NULL) { // Remover o primeiro elemento
                lst = atual->prox;
            } else { // Remover um elemento no meio
                ant->prox = atual->prox;
            }
            Elemento *temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            // Avançar para o próximo elemento
            ant = atual;
            atual = atual->prox;
        }
    }
    return lst;
}
