#include <stdio.h>
#include <conio.h>

int main() {
    char frase[81];
    int i = 0;

    printf("Digite uma frase (máx. 80 caracteres):\n");

    while (i < 80) {
        char ch = getch();
        if (ch == '\r') {
            break;
        }
        frase[i++] = ch;
        printf("%c", ch);
    }
    frase[i] = '\0';

    printf("\n\nPalavras da frase:\n");

    char *palavra = frase;

    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == ' ' || frase[i+1] == '\0') {
            frase[i] = '\0';
            printf("%s\n", palavra);
            palavra = &frase[i + 1];
        }
    }

    return 0;
}
