#include <stdio.h>
#include <string.h>

int main() {
    char str[51];
    int count[256] = {0};
    char chars[51]; // Para armazenar os caracteres encontrados
    int charIndex = 0;

    printf("Digite uma string (máx. 50 caracteres): ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 0) {
            chars[charIndex++] = str[i]; // Armazena o caractere se for a primeira ocorrência
        }
        count[(unsigned char)str[i]]++;
    }

    printf("Estatística dos caracteres:\n");
    for (int i = 0; i < charIndex; i++) {
        printf("'%c' = %d\n", chars[i], count[(unsigned char)chars[i]]);
    }

    return 0;
}
