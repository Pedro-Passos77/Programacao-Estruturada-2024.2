Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado) {
    Assalariados *novo = (Assalariados *)malloc(sizeof(Assalariados)); // Aloca memória para um novo assalariado

    // Preenche os dados do assalariado
    strncpy(novo->nome, nome, 50);
    novo->nome[50] = '\0';  // Garante que o nome estará corretamente terminado em '\0'
    novo->sexo = sexo;
    novo->idade = idade;
    novo->salario = salario;
    strncpy(novo->estado, estado, 2);  // Atribui a sigla do estado
    novo->estado[2] = '\0'; // Garante a terminação correta do estado

    return novo; // Retorna o ponteiro para a estrutura alocada
}
