#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula) {
    FILE* arq = fopen(arquivo, "r");  // Abre o arquivo em modo leitura

    if (arq == NULL) {
        printf("ERRO\n");
        exit(1);  // Encerra o programa caso o arquivo não seja aberto
    }

    char mat[20];  // Para armazenar a matrícula do arquivo
    float cr;      // Para armazenar o CR do arquivo

    // Lê o arquivo linha por linha
    while (fscanf(arq, "%s %f", mat, &cr) != EOF) {
        if (strcmp(mat, matricula) == 0) {
            fclose(arq);  // Fecha o arquivo antes de retornar
            return cr;    // Retorna o CR se a matrícula for encontrada
        }
    }

    fclose(arq);  // Fecha o arquivo se não encontrar a matrícula
    return -1.0;   // Retorna -1.0 se a matrícula não for encontrada
}

int main() {
    // Teste da função busca
    char matricula[20];
    printf("Digite a matrícula do aluno: ");
    scanf("%s", matricula);

    float cr = busca("alunos.txt", matricula);  // Supondo que o arquivo se chame "alunos.txt"

    if (cr == -1.0) {
        printf("Matrícula não encontrada!\n");
    } else {
        printf("O CR do aluno %s é: %.2f\n", matricula, cr);
    }

    return 0;
}
