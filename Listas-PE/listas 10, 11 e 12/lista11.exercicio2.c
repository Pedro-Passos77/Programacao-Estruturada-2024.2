Elemento* copia(Elemento* lst) {
    if (lst == NULL) return NULL;

    Elemento *novaLista = NULL, *temp = NULL, *ultimo = NULL;

    while (lst != NULL) {
        temp = (Elemento*)malloc(sizeof(Elemento));
        if (temp == NULL) {
            printf("Erro ao alocar memória.\n");
            return NULL;
        }
        temp->info = lst->info;
        temp->prox = NULL;

        if (novaLista == NULL) {
            novaLista = temp; // A nova lista começa com o primeiro elemento
        } else {
            ultimo->prox = temp; // Insere o novo elemento no final da lista
        }
        ultimo = temp;
        lst = lst->prox; // Avança para o próximo elemento
    }

    return novaLista;
}
