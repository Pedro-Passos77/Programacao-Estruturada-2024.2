#include <stdio.h>
#include <stdlib.h>

void calcula_media(char* nome_arquivo) {
    FILE* arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    float num, soma = 0.0;
    int count = 0;

    // Lê números reais até o final do arquivo
    while (fscanf(arq, "%f", &num) != EOF) {
        soma += num;
        count++;
    }

    if (count > 0) {
        printf("A média dos números lidos é: %.2f\n", soma / count);
    } else {
        printf("Nenhum número lido.\n");
    }

    fclose(arq);
}

int main() {
    char arquivo[] = "numeros.txt";  // Supondo que o arquivo se chame "numeros.txt"

    calcula_media(arquivo);

    return 0;
}
