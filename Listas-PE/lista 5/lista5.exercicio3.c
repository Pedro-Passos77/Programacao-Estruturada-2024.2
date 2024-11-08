#include <stdio.h>

int contarOcorrencias(char *cadeia, char caractere) {
    int contador = 0;
    for (int i = 0; i < 20; i++) {
        if (cadeia[i] == caractere) {
            contador++;
        }
    }
    return contador;
}

int main() {
    char cadeia[20];
    char caractere;

    printf("Digite uma cadeia de até 20 caracteres: ");
    fgets(cadeia, sizeof(cadeia), stdin);

    printf("Digite um caractere para contar: ");
    scanf(" %c", &caractere);

    int resultado = contarOcorrencias(cadeia, caractere);

    printf("O caractere '%c' aparece %d vez(es) na cadeia.\n", caractere, resultado);

    return 0;
}
