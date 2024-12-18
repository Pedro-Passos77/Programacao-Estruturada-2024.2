#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo as estruturas
typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81];
    int sala;
} Local;

typedef struct notas {
    float geral;
    float especifica;
} Notas;

typedef struct candidato {
    int inscr;
    char nome[81];
    Data nasc;
    Local *loc;
    Notas nt;
} Candidato;

void alterarLocalDeProvas(Candidato *candidato) {
    printf("Digite o novo endereço do local de provas: ");
    getchar(); // Limpar o buffer de entrada
    fgets(candidato->loc->ender, 81, stdin);
    candidato->loc->ender[strcspn(candidato->loc->ender, "\n")] = '\0'; // Remover o '\n'

    printf("Digite o novo número da sala: ");
    scanf("%d", &candidato->loc->sala);
}

int main() {
    int n, candidatoIndex;
    printf("Digite o número de candidatos: ");
    scanf("%d", &n);

    Candidato *candidatos = (Candidato *)malloc(n * sizeof(Candidato)); // Alocando memória para os candidatos

    // Aqui você pode chamar as funções de leitura e impressão de dados, como no primeiro e segundo exemplos

    printf("Digite o índice do candidato para alterar o local de provas (1 a %d): ", n);
    scanf("%d", &candidatoIndex);
    if (candidatoIndex >= 1 && candidatoIndex <= n) {
        alterarLocalDeProvas(&candidatos[candidatoIndex - 1]);
        printf("Local de provas alterado com sucesso!\n");
    } else {
        printf("Índice inválido.\n");
    }

    // Liberando a memória alocada dinamicamente
    for (int i = 0; i < n; i++) {
        free(candidatos[i].loc); // Liberar a memória do local de prova
    }
    free(candidatos); // Liberar a memória do vetor de candidatos

    return 0;
}
