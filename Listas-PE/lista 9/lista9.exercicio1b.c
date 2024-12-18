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

void imprimirDadosCandidato(Candidato *candidato) {
    printf("\nNúmero de Inscrição: %d\n", candidato->inscr);
    printf("Nome: %s\n", candidato->nome);
    printf("Data de Nascimento: %02d/%02d/%d\n", candidato->nasc.dia, candidato->nasc.mes, candidato->nasc.ano);
    printf("Local de Prova: %s\n", candidato->loc->ender);
    printf("Número da Sala: %d\n", candidato->loc->sala);
    printf("Nota Geral: %.2f\n", candidato->nt.geral);
    printf("Nota Específica: %.2f\n", candidato->nt.especifica);
}

int main() {
    int n;
    printf("Digite o número de candidatos: ");
    scanf("%d", &n);

    Candidato *candidatos = (Candidato *)malloc(n * sizeof(Candidato)); // Alocando memória para os candidatos

    // Aqui você pode chamar a função de leitura de dados, que já foi definida no primeiro código

    for (int i = 0; i < n; i++) {
        printf("\nDados do %dº candidato:\n", i + 1);
        imprimirDadosCandidato(&candidatos[i]);
    }

    // Liberando a memória alocada dinamicamente
    for (int i = 0; i < n; i++) {
        free(candidatos[i].loc); // Liberar a memória do local de prova
    }
    free(candidatos); // Liberar a memória do vetor de candidatos

    return 0;
}
