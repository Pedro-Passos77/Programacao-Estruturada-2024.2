#include <stdio.h>
#include <string.h>

#define MAX_ESPECTADORES 100

void coletarDados(int idades[], char opnioes[][10], int n);
int contarOpinioesOtimo(char opnioes[][10], int n);
float calcularDiferencaPercentual(char opnioes[][10], int n);
float calcularMediaIdadeRuim(int idades[], char opnioes[][10], int n);
float calcularPorcentagemPessimo(int idades[], char opnioes[][10], int n, int* maiorIdadePessimo);
int calcularDiferencaIdadeOtimo(int idades[], char opnioes[][10], int n);

int main() {
    int idades[MAX_ESPECTADORES];
    char opnioes[MAX_ESPECTADORES][10];
    int n;

    printf("Quantas pessoas responderam o questionário (máx. 100): ");
    scanf("%d", &n);

    if (n > MAX_ESPECTADORES) {
        printf("Número de espectadores não pode ser maior que %d.\n", MAX_ESPECTADORES);
        return 1;
    }

    coletarDados(idades, opnioes, n);

    int qtdOtimo = contarOpinioesOtimo(opnioes, n);
    float diferencaPercentual = calcularDiferencaPercentual(opnioes, n);
    float mediaIdadeRuim = calcularMediaIdadeRuim(idades, opnioes, n);
    int maiorIdadePessimo = 0;
    float porcentagemPessimo = calcularPorcentagemPessimo(idades, opnioes, n, &maiorIdadePessimo);
    int diferencaIdadeOtimo = calcularDiferencaIdadeOtimo(idades, opnioes, n);

    printf("Quantidade de respostas 'ótimo': %d\n", qtdOtimo);
    printf("Diferença percentual entre respostas 'bom' e 'regular': %.2f%%\n", diferencaPercentual);
    printf("Média de idade das pessoas que responderam 'ruim': %.2f\n", mediaIdadeRuim);
    printf("Porcentagem de respostas 'péssimo': %.2f%%\n", porcentagemPessimo);
    printf("Maior idade que respondeu 'péssimo': %d\n", maiorIdadePessimo);
    printf("Diferença de idade entre a maior idade que respondeu 'ótimo' e a maior idade que respondeu 'péssimo': %d\n", diferencaIdadeOtimo);

    return 0;
}

void coletarDados(int idades[], char opnioes[][10], int n) {
    for (int i = 0; i < n; i++) {
        printf("Idade do espectador %d: ", i + 1);
        scanf("%d", &idades[i]);
        printf("Opinião do espectador %d (ótimo, bom, regular, ruim, péssimo): ", i + 1);
        scanf("%s", opnioes[i]);
    }
}

int contarOpinioesOtimo(char opnioes[][10], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(opnioes[i], "ótimo") == 0) {
            count++;
        }
    }
    return count;
}

float calcularDiferencaPercentual(char opnioes[][10], int n) {
    int countBom = 0, countRegular = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(opnioes[i], "bom") == 0) {
            countBom++;
        } else if (strcmp(opnioes[i], "regular") == 0) {
            countRegular++;
        }
    }
    if (countRegular == 0) {
        return countBom > 0 ? 100.0 : 0.0;
    }
    return ((float)countBom - countRegular) / countRegular * 100.0;
}

float calcularMediaIdadeRuim(int idades[], char opnioes[][10], int n) {
    int count = 0;
    float somaIdade = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(opnioes[i], "ruim") == 0) {
            somaIdade += idades[i];
            count++;
        }
    }
    return count > 0 ? somaIdade / count : 0.0;
}

float calcularPorcentagemPessimo(int idades[], char opnioes[][10], int n, int* maiorIdadePessimo) {
    int countPessimo = 0;
    int countTotal = n;
    for (int i = 0; i < n; i++) {
        if (strcmp(opnioes[i], "péssimo") == 0) {
            countPessimo++;
            if (idades[i] > *maiorIdadePessimo) {
                *maiorIdadePessimo = idades[i];
            }
        }
    }
    return (countTotal > 0) ? ((float)countPessimo / countTotal) * 100 : 0.0;
}

int calcularDiferencaIdadeOtimo(int idades[], char opnioes[][10], int n) {
    int maiorIdadeOtimo = 0, maiorIdadePessimo = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(opnioes[i], "ótimo") == 0 && idades[i] > maiorIdadeOtimo) {
            maiorIdadeOtimo = idades[i];
        } else if (strcmp(opnioes[i], "péssimo") == 0 && idades[i] > maiorIdadePessimo) {
            maiorIdadePessimo = idades[i];
        }
    }
    return maiorIdadeOtimo - maiorIdadePessimo;
}
