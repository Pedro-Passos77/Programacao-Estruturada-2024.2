Aluno* fillAluno() {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

    printf("Digite a matrícula: ");
    scanf("%d", &aluno->mat);

    printf("Digite o nome do aluno: ");
    getchar();  // Limpa o buffer
    fgets(aluno->nome, 100, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = 0;  // Remove a quebra de linha

    aluno->vNotas = (float*) malloc(5 * sizeof(float));
    for (int i = 0; i < 5; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &aluno->vNotas[i]);
    }

    return aluno;
}
