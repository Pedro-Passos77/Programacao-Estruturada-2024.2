#include <stdio.h>

int main() {
    int vetor1[20], vetor2[20], resultados[20];
    char operacoes[20];
    int i;

    for (i = 0; i < 20; i++) {
        printf("Digite o elemento %d do vetor 1: ", i + 1);
        scanf("%d", &vetor1[i]);
        printf("Digite o elemento %d do vetor 2: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    for (i = 0; i < 20; i++) {
        printf("Digite a operação para o elemento %d ( +, -, *, / ): ", i + 1);
        scanf(" %c", &operacoes[i]);
    }

    for (i = 0; i < 20; i++) {
        switch (operacoes[i]) {
            case '+':
                resultados[i] = vetor1[i] + vetor2[i];
            break;
            case '-':
                resultados[i] = vetor1[i] - vetor2[i];
            break;
            case '*':
                resultados[i] = vetor1[i] * vetor2[i];
            break;
            case '/':
                if (vetor2[i] != 0) {
                    resultados[i] = vetor1[i] / vetor2[i];
                } else {
                    printf("Erro: Divisão por zero no elemento %d.\n", i + 1);
                    resultados[i] = 0;
                }
            break;
            default:
                printf("Operação inválida para o elemento %d.\n", i + 1);
            resultados[i] = 0;
            break;
        }
    }

    printf("\nResultados das operações:\n");
    for (i = 0; i < 20; i++) {
        printf("Resultado[%d]: %d\n", i + 1, resultados[i]);
    }

    return 0;
}
