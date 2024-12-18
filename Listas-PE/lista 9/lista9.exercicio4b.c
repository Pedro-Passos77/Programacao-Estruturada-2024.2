char * get_sobrenome(char *nome) {
    char *sobrenome = strrchr(nome, ' ');  // Encontra a última ocorrência de espaço
    if (sobrenome != NULL) {
        return sobrenome + 1;  // Retorna a parte após o espaço (o sobrenome)
    }
    return nome;  // Caso não haja espaço, o nome inteiro é considerado o sobrenome
}
