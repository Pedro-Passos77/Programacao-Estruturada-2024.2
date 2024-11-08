#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nome[100];
    char abreviacao[100] = "";
    char *preposicoes[] = {"do", "de", "da", "dos", "das", "e", "ou", "com", "em"};
    int i, ehPreposicao;

    printf("Digite o nome completo: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    char *token = strtok(nome, " ");

    while (token != NULL) {
        ehPreposicao = 0;

        for (i = 0; i < sizeof(preposicoes) / sizeof(preposicoes[0]); i++) {
            if (strcmp(token, preposicoes[i]) == 0) {
                ehPreposicao = 1;
                break;
            }
        }

        if (!ehPreposicao) {
            char inicial = toupper(token[0]);
            char temp[3];
            sprintf(temp, "%c.", inicial);
            strcat(abreviacao, temp);
        }

        token = strtok(NULL, " ");
    }

    printf("Abreviatura: %s\n", abreviacao);

    return 0;
}
