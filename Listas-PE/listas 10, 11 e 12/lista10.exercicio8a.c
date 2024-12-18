#include <stdio.h>
#include <stdlib.h>

typedef struct _ALUNO {
    char nome[81];
    float nota1, nota2;
} ALUNO;

// Função para mostrar alunos com média maior que 6.0
void mostrar_alunos(FILE* arquivo) {
    ALUNO aluno;
    fseek(arquivo, 0, SEEK_SET);  // Posiciona no início do arquivo

    printf("Alunos com média maior que 6.0:\n");

    // Lê os alunos do arquivo e verifica a média
    while (fread(&aluno, sizeof(ALUNO), 1, arquivo)) {
        float media = (aluno.nota1 + aluno.nota2) / 2.0;
        if (media > 6.0) {
            printf("Nome: %s, Nota 1: %.2f, Nota 2: %.2f, Média: %.2f\n",
                   aluno.nome, aluno.nota1, aluno.nota2, media);
        }
    }
}

int main() {
    // Abre o arquivo de dados dos alunos
    FILE* arquivo = fopen("alunos.dat", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo alunos.dat\n");
        return 1;
    }

    // Chama a função para mostrar os alunos com média maior que 6.0
    mostrar_alunos(arquivo);

    fclose(arquivo);
    return 0;
}
