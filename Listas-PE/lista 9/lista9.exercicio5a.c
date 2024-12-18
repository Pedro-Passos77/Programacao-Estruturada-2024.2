Aluno ** alocaAlunos(int n) {
    Aluno **a = (Aluno **) malloc(n * sizeof(Aluno *));  // Aloca memória para o vetor de ponteiros

    for (int i = 0; i < n; i++) {
        a[i] = (Aluno *) malloc(sizeof(Aluno));           // Aloca memória para cada estrutura Aluno
        a[i]->end = (Endereco *) malloc(sizeof(Endereco)); // Aloca memória para o endereço de cada aluno
    }

    return a;
}