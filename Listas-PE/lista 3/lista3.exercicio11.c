#include <stdio.h>

int main() {
    int n, i;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    int idades[n];
    float alturas[n];
    char sexos[n]; // Armazenando sexo como um vetor de caracteres

    int contMulheres = 0;
    int contHomensAltos = 0;
    float somaAlturas = 0.0;

    for (i = 0; i < n; i++) {
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idades[i]);
        printf("Digite a altura da pessoa %d: ", i + 1);
        scanf("%f", &alturas[i]);
        printf("Digite o sexo da pessoa %d (M/F): ", i + 1);
        scanf(" %c", &sexos[i]); // O espaço antes de %c é importante para ignorar espaços em branco

        if (sexos[i] == 'F' || sexos[i] == 'f') {
            if (idades[i] >= 20 && idades[i] <= 35) {
                contMulheres++;
            }
        } else if (sexos[i] == 'M' || sexos[i] == 'm') {
            if (alturas[i] > 1.80) {
                contHomensAltos++;
            }
        }

        somaAlturas += alturas[i];
    }

    float mediaAltura = somaAlturas / n; // Cálculo da média
    float somaVariancia = 0.0;

    for (i = 0; i < n; i++) {
        somaVariancia += (alturas[i] - mediaAltura) * (alturas[i] - mediaAltura);
    }

    float variancia = somaVariancia / n; // Cálculo da variância

    printf("Número de mulheres entre 20 e 35 anos: %d\n", contMulheres);
    printf("Número de homens com altura maior que 1,80m: %d\n", contHomensAltos);
    printf("Variância das alturas: %.4f\n", variancia); // Exibição da variância

    return 0;
}
