#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    char nome[81];      /* Nome do funcionário */
    float valor_hora;   /* Valor da hora de trabalho em Reais */
    int horas_mes;      /* Horas trabalhadas em um mês */
};

typedef struct funcionario Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE* arq = fopen(arquivo, "r");  // Abre o arquivo em modo leitura

    if (arq == NULL) {
        printf("ERRO\n");
        exit(1);  // Encerra o programa se o arquivo não for aberto
    }

    // Lê os dados e preenche o vetor de ponteiros
    for (int i = 0; i < n; i++) {
        vet[i] = (Funcionario*) malloc(sizeof(Funcionario));  // Aloca espaço para o funcionário

        // Lê o nome do funcionário (linha 1)
        fgets(vet[i]->nome, 81, arq);
        vet[i]->nome[strcspn(vet[i]->nome, "\n")] = 0;  // Remove a quebra de linha

        // Lê o valor da hora e o número de horas trabalhadas (linha 2)
        fscanf(arq, "%f %d", &vet[i]->valor_hora, &vet[i]->horas_mes);

        // Consome o caractere de nova linha que ficou no buffer após o fscanf
        fgetc(arq);
    }

    fclose(arq);  // Fecha o arquivo após a leitura
}

int main() {
    int n = 3;  // Supondo que há 3 funcionários no arquivo
    Funcionario* vet[n];  // Vetor de ponteiros para Funcionário

    // Chama a função carrega para preencher o vetor com dados do arquivo
    carrega(n, vet, "funcionarios.txt");

    // Exibe os dados para verificar se foi carregado corretamente
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", vet[i]->nome);
        printf("Valor Hora: %.2f\n", vet[i]->valor_hora);
        printf("Horas Mes: %d\n\n", vet[i]->horas_mes);

        free(vet[i]);  // Libera a memória alocada para cada funcionário
    }

    return 0;
}
