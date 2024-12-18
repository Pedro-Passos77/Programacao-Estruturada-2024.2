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

void lerDadosCandidato(Candidato *candidato) {
    printf("Digite o número de inscrição: ");
    scanf("%d", &candidato->inscr);
    getchar(); // Limpar o buffer de entrada

    printf("Digite o nome do candidato: ");
    fgets(candidato->nome, 81, stdin);
    candidato->nome[strcspn(candidato->nome, "\n")] = '\0'; // Remover o '\n'

    printf("Digite a data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &candidato->nasc.dia, &candidato->nasc.mes, &candidato->nasc.ano);

    candidato->loc = (Local *)malloc(sizeof(Local)); // Alocando memória dinamicamente para o local
    printf("Digite o endereço do local de provas: ");
    getchar(); // Limpar o buffer de entrada
    fgets(candidato->loc->ender, 81, stdin);
    candidato->loc->ender[strcspn(candidato->loc->ender, "\n")] = '\0'; // Remover o '\n'

    printf("Digite o número da sala: ");
    scanf("%d", &candidato->loc->sala);

    printf("Digite a nota geral: ");
    scanf("%f", &candidato->nt.geral);

    printf("Digite a nota específica: ");
    scanf("%f", &candidato->nt.especifica);
}

int main() {
    int n;
    printf("Digite o número de candidatos: ");
    scanf("%d", &n);

    Candidato *candidatos = (Candidato *)malloc(n * sizeof(Candidato)); // Alocando memória para os candidatos

    for (int i = 0; i < n; i++) {
        printf("\nDigite os dados do %dº candidato:\n", i + 1);
        lerDadosCandidato(&candidatos[i]);
    }

    // Liberando a memória alocada dinamicamente
    for (int i = 0; i < n; i++) {
        free(candidatos[i].loc); // Liberar a memória do local de prova
    }
    free(candidatos); // Liberar a memória do vetor de candidatos

    return 0;
}
