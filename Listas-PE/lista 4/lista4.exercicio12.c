#include <stdio.h>
#include <string.h>

int main() {
    char str[21];
    char charToRemove;
    char result[21];
    int j = 0;

    printf("Digite uma string (máx. 20 caracteres): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove o caractere de nova linha, se presente

    printf("Digite o caractere a ser removido: ");
    scanf(" %c", &charToRemove);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != charToRemove) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';  // Adiciona o terminador de string

    printf("String resultante: %s\n", result);

    return 0;
}
