#include <stdio.h>
#include <stdlib.h>

int comparacao(const void* a, const void* b) {
    float num1 = *((float*)a);
    float num2 = *((float*)b);
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main() {
    FILE* arq_texto = fopen("numeros.txt", "r");
    if (arq_texto == NULL) {
        printf("Erro ao abrir o arquivo numeros.txt\n");
        return 1;
    }

    // Contando quantos números reais existem no arquivo
    int count = 0;
    float temp;
    while (fscanf(arq_texto, "%f", &temp) != EOF) {
        count++;
    }

    // Volta para o início do arquivo
    rewind(arq_texto);

    // Cria um vetor para armazenar os números
    float* numeros = (float*)malloc(count * sizeof(float));
    if (numeros == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(arq_texto);
        return 1;
    }

    // Lê os números no vetor
    for (int i = 0; i < count; i++) {
        fscanf(arq_texto, "%f", &numeros[i]);
    }

    // Ordena os números
    qsort(numeros, count, sizeof(float), comparacao);

    // Grava os números ordenados no arquivo binário
    FILE* arq_binario = fopen("numeros.bin", "wb");
    if (arq_binario == NULL) {
        printf("Erro ao criar o arquivo numeros.bin\n");
        free(numeros);
        fclose(arq_texto);
        return 1;
    }

    fwrite(numeros, sizeof(float), count, arq_binario);  // Grava os números binários
    fclose(arq_texto);
    fclose(arq_binario);
    free(numeros);  // Libera a memória alocada

    printf("Números ordenados e gravados em numeros.bin\n");
    return 0;
}
