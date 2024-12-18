void le(ALUNO turma[]) {
    for (int i = 0; i < MAX; i++) {
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &turma[i].mat);
        printf("Digite o nome do aluno %d: ", i + 1);
        getchar();  // Limpa o buffer
        fgets(turma[i].nome, 81, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = 0;  // Remove a quebra de linha
    }
}
void imprime(ALUNO turma[]) {
    for (int i = 0; i < MAX; i++) {
        printf("Matrícula: %d, Nome: %s\n", turma[i].mat, turma[i].nome);
    }
}
