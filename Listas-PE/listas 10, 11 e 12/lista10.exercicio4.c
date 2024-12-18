#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_comentarios(char* arquivo_entrada, char* arquivo_saida) {
    FILE *entrada = fopen(arquivo_entrada, "r");
    if (entrada == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    FILE *saida = fopen(arquivo_saida, "w");
    if (saida == NULL) {
        printf("ERRO\n");
        fclose(entrada);
        exit(1);
    }

    char linha[256];  // Buffer para armazenar cada linha do arquivo

    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), entrada)) {
        // Verifica se a linha contém um comentário (inicia com "//")
        if (linha[0] == '/' && linha[1] == '/') {
            continue;  // Se for comentário, ignora a linha
        }
        fprintf(saida, "%s", linha);  // Escreve a linha no arquivo de saída
    }

    fclose(entrada);
    fclose(saida);
}

int main() {
    char arquivo_entrada[] = "codigo.c";  // Arquivo de entrada com código fonte
    char arquivo_saida[] = "codigo_sem_comentarios.c";  // Arquivo de saída

    remove_comentarios(arquivo_entrada, arquivo_saida);

    printf("Comentários removidos e novo arquivo gerado!\n");

    return 0;
}
