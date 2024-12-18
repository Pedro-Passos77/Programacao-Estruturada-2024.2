Pessoa* busca(int n, Pessoa** vet, int codigo) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vet[meio]->codigo == codigo) {
            return vet[meio];  // Código encontrado, retorna o ponteiro para a pessoa
        }
        else if (vet[meio]->codigo < codigo) {
            inicio = meio + 1;  // Procura na metade direita
        }
        else {
            fim = meio - 1;  // Procura na metade esquerda
        }
    }

    return NULL;  // Código não encontrado
}
