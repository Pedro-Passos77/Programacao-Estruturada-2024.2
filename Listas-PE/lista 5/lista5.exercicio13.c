#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, ";
    char str2[50] = "World!";
    char str3[50];

    strncat(str1, str2, 3);
    printf("Após strncat: %s\n", str1);

    char *ptr = strchr(str1, 'o');
    if (ptr != NULL) {
        printf("Primeira ocorrência de 'o': %s\n", ptr);
    } else {
        printf("Caractere 'o' não encontrado.\n");
    }

    char comparacao[] = "Hello, World!";
    size_t comprimento = strspn(str1, comparacao);
    printf("Número de caracteres iniciais em str1 que estão em comparacao: %zu\n", comprimento);

    return 0;
}
