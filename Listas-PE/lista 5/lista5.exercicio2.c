#include<stdio.h>
#include<string.h>

main(void) {
    char texto[] = "foi muito facil"; // Declara um array de caracteres (string) inicializado com "foi muito facil"
    int i; // Declara uma variável inteira i

    // Este laço encontra o primeiro espaço na string
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ' ') break; // Se encontrar um espaço, sai do loop
    }
    i++; // Incrementa i para passar o espaço encontrado

    // Este laço imprime os caracteres a partir do primeiro espaço encontrado até o final da string
    for (; texto[i] != '\0'; i++) {
        printf("%c", texto[i]); // Imprime o caractere atual
    }
}
Primeiro Loop:

Percorre a string texto até encontrar um espaço.
Iterações:
texto[0] é 'f'
texto[1] é 'o'
texto[2] é 'i'
texto[3] é ' ' (encontra o espaço e interrompe).
Valor de i após o loop: 3.
i é incrementado para 4 (primeiro caractere após o espaço).
Segundo Loop:

Imprime os caracteres a partir do índice 4 até o final da string.
Caracteres:
texto[4] é 'm'
texto[5] é 'u'
texto[6] é 'i'
texto[7] é 't'
texto[8] é 'o'
texto[9] é ' ' (espaço)
texto[10] é 'f'
texto[11] é 'a'
texto[12] é 'c'
texto[13] é 'i'
texto[14] é 'l'
O loop termina ao encontrar '\0' em texto[15].
A saída do programa é:

    muito facil

