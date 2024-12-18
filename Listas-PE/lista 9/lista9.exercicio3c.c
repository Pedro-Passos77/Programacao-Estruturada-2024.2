#include <stdio.h>
#include <string.h>

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

// Função para gerar o relatório
void relatorio(Assalariados *cadastrados, int n) {
    // Vetor para contar homens por estado com mais de 40 anos e salário > 1000
    int contagemEstados[27] = {0};  // Há 27 estados/DF

    // Mapeando os estados
    char *estados[27] = {"AC", "AL", "AM", "AP", "BA", "CE", "DF", "ES", "GO", "MA", "MG", "MS", "MT", "PA",
                         "PB", "PE", "PI", "PR", "RJ", "RN", "RO", "RR", "RS", "SC", "SE", "SP", "TO"};

    // Percorrer o array de assalariados
    for (int i = 0; i < n; i++) {
        // Verificar as condições: sexo 'M', idade > 40, salário > 1000
        if (cadastrados[i].sexo == 'M' && cadastrados[i].idade > 40 && cadastrados[i].salario > 1000) {
            // Encontrar o índice do estado no vetor de estados
            int estadoIndex = -1;
            for (int j = 0; j < 27; j++) {
                if (strcmp(cadastrados[i].estado, estados[j]) == 0) {
                    estadoIndex = j;
                    break;
                }
            }

            // Se o estado foi encontrado, incrementar a contagem
            if (estadoIndex != -1) {
                contagemEstados[estadoIndex]++;
            }
        }
    }

    // Imprimir os resultados para os estados com pelo menos 1 homem que atenda às condições
    for (int i = 0; i < 27; i++) {
        if (contagemEstados[i] > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salário maior que R$ 1000,00\n", estados[i], contagemEstados[i]);
        }
    }
}

int main() {
    // Exemplo de dados de assalariados
    Assalariados cadastrados[5] = {
        {"Carlos", 'M', 45, 1200.0, "SP"},
        {"João", 'M', 50, 900.0, "RJ"},
        {"Pedro", 'M', 35, 1500.0, "MG"},
        {"Lucas", 'M', 41, 2000.0, "SP"},
        {"Marcos", 'M', 60, 1100.0, "SP"}
    };

    // Chamada da função relatorio
    relatorio(cadastrados, 5);

    return 0;
}
