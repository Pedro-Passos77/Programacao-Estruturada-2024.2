#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char letraUsuario, letra;

    srand(time(NULL));
    letra = 'a' + (rand() % 26);

    do {
        printf("Digite sua letra: ");
        scanf(" %c", &letraUsuario);

        if (letraUsuario > letra) {
            printf("A letra é menor que a escolhida\n");
        } else if (letraUsuario < letra) {
            printf("A letra é maior que a escolhida\n");
        }
    } while (letraUsuario != letra);

    printf("Exatamente, a letra escolhida é %c\n", letra);

    return 0;
}
