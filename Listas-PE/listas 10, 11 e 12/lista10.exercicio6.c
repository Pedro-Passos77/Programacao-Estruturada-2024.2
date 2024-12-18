#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        char nome_arquivo[20];
        sprintf(nome_arquivo, "teste%02d.txt", i);  // Formata o nome do arquivo, ex: "teste01.txt"

        FILE* arquivo = fopen(nome_arquivo, "w");  // Cria e abre o arquivo para escrita
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo %s\n", nome_arquivo);
            return 1;  // Encerra se houver erro
        }

        fprintf(arquivo, "Texto do arquivo %d\n", i);  // Escreve o conteúdo no arquivo
        fclose(arquivo);  // Fecha o arquivo
    }

    printf("Arquivos gerados com sucesso!\n");
    return 0;
}
