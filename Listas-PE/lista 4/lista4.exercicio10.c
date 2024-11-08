#include <stdio.h>

int main() {
    int idades[20];
    char opinioes[20];
    int i;
    int cont_otimo = 0;
    int cont_bom = 0;
    int cont_regular = 0;
    int cont_ruim = 0;
    int cont_pessimo = 0;
    int soma_idade_ruim = 0;
    int maior_idade_otimo = 0;
    int maior_idade_ruim = 0;

    for (i = 0; i < 20; i++) {
        printf("Digite a idade do espectador %d: ", i + 1);
        scanf("%d", &idades[i]);

        printf("Digite a opiniao (o - ótimo, b - bom, r - regular, u - ruim, p - péssimo): ");
        scanf(" %c", &opinioes[i]);  // O espaço antes de %c ignora espaços em branco

        if (opinioes[i] == 'o') {
            cont_otimo++;
            if (idades[i] > maior_idade_otimo) {
                maior_idade_otimo = idades[i];
            }
        } else if (opinioes[i] == 'b') {
            cont_bom++;
        } else if (opinioes[i] == 'r') {
            cont_regular++;
        } else if (opinioes[i] == 'u') {
            cont_ruim++;
            soma_idade_ruim += idades[i];
            if (idades[i] > maior_idade_ruim) {
                maior_idade_ruim = idades[i];
            }
        } else if (opinioes[i] == 'p') {
            cont_pessimo++;
        }
    }

    printf("\nQuantidade de respostas ótimo: %d\n", cont_otimo);

    if (cont_bom + cont_regular > 0) {
        float percentual_bom = (float)cont_bom / (cont_bom + cont_regular) * 100;
        float percentual_regular = (float)cont_regular / (cont_bom + cont_regular) * 100;
        float diferenca_percentual = percentual_bom - percentual_regular;
        printf("Diferença percentual entre respostas bom e regular: %.2f%%\n", diferenca_percentual);
    } else {
        printf("Não há respostas para bom ou regular para calcular a diferença percentual.\n");
    }

    if (cont_ruim > 0) {
        float media_idade_ruim = (float)soma_idade_ruim / cont_ruim;
        printf("Média de idade das pessoas que responderam ruim: %.2f\n", media_idade_ruim);
    } else {
        printf("Não há respostas para ruim para calcular a média de idade.\n");
    }

    if (cont_pessimo > 0) {
        float porcentagem_pessimo = (float)cont_pessimo / 20 * 100;
        printf("Porcentagem de respostas péssimo: %.2f%%\n", porcentagem_pessimo);
        printf("Maior idade que utilizou a opção péssimo: %d\n", maior_idade_ruim);
    } else {
        printf("Não há respostas para péssimo para calcular a porcentagem.\n");
    }

    if (cont_otimo > 0 && cont_ruim > 0) {
        int diferenca_idades = maior_idade_otimo - maior_idade_ruim;
        printf("Diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim: %d anos\n", diferenca_idades);
    } else {
        printf("Não há dados suficientes para calcular a diferença de idade entre ótimo e ruim.\n");
    }

    return 0;
}
