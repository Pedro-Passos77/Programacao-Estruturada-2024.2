#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo) {
    FILE* arq = fopen(nome_arquivo, "r");  // Abre o arquivo em modo leitura
    if (arq == NULL) {
        printf("ERRO\n");
        exit(1);  // Se não conseguir abrir o arquivo, encerra o programa
    }

    char matricula[10];  // Para armazenar a matrícula lida do arquivo
    float p1, p2, p3;    // Para armazenar as notas lidas do arquivo

    // Lê o arquivo linha por linha
    while (fscanf(arq, "%s %f %f %f", matricula, &p1, &p2, &p3) != EOF) {
        if (strcmp(matricula, mat) == 0) {
            fclose(arq);  // Fecha o arquivo antes de retornar
            return (p1 + p2 + p3) / 3.0;  // Retorna a média das notas
        }
    }

    fclose(arq);  // Fecha o arquivo se a matrícula não for encontrada
    return -1.0;   // Retorna -1.0 caso a matrícula não seja encontrada
}

int main() {
    char matricula[10];
    printf("Digite a matrícula do aluno: ");
    scanf("%s", matricula);

    float resultado = media(matricula, "notas.txt");  // Supondo que o arquivo se chame "notas.txt"

    if (resultado == -1.0) {
        printf("Matrícula não encontrada!\n");
    } else {
        printf("A média do aluno %s é: %.2f\n", matricula, resultado);
    }

    return 0;
}
