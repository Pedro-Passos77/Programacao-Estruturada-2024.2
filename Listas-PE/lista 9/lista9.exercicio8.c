Compromisso* busca(int n, Compromisso** vet, int d, int m, int a) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        // Compara as datas
        if (vet[meio]->dta.dd == d && vet[meio]->dta.mm == m && vet[meio]->dta.aa == a) {
            return vet[meio];  // Compromisso encontrado
        } else if (vet[meio]->dta.aa < a || (vet[meio]->dta.aa == a && vet[meio]->dta.mm < m) || (vet[meio]->dta.aa == a && vet[meio]->dta.mm == m && vet[meio]->dta.dd < d)) {
            inicio = meio + 1;  // Procura na metade direita
        } else {
            fim = meio - 1;  // Procura na metade esquerda
        }
    }

    return NULL;  // Compromisso não encontrado
}


