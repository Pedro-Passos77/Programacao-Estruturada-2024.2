Livro* fillLivro() {
    Livro* livro = (Livro*) malloc(sizeof(Livro));

    // Preenchendo os campos do livro
    printf("Digite o ano de publicação: ");
    scanf("%d", &livro->ano);

    printf("Digite o título do livro: ");
    getchar();  // Limpa o buffer do teclado
    fgets(livro->titulo, 100, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = 0;  // Remove a quebra de linha

    printf("Digite o autor do livro: ");
    fgets(livro->autor, 100, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = 0;  // Remove a quebra de linha

    printf("Digite o número de exemplares: ");
    scanf("%d", &livro->nVolume);

    printf("Digite o preço do livro: ");
    scanf("%f", &livro->preco);

    return livro;
}
