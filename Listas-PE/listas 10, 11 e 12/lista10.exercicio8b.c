#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    char nome[81];
    float nota1, nota2;
} ALUNO;

// Função para incluir um aluno no arquivo
void incluir(FILE *arquivo) {
    ALUNO aluno;
    fseek(arquivo, 0, SEEK_END);  // Vai para o final do arquivo

    // Recebe os dados do aluno
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 81, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';  // Remove o '\n' da string

    printf("Digite a nota 1: ");
    scanf("%f", &aluno.nota1);

    printf("Digite a nota 2: ");
    scanf("%f", &aluno.nota2);

    // Grava o aluno no arquivo
    fwrite(&aluno, sizeof(ALUNO), 1, arquivo);
    printf("Aluno incluído com sucesso!\n");
}

// Função para alterar um aluno no arquivo
void alterar(FILE *arquivo) {
    ALUNO aluno;
    char matricula[9];
    int encontrado = 0;

    // Solicita a matrícula do aluno
    printf("Digite a matrícula do aluno a ser alterado: ");
    scanf("%s", matricula);
    getchar(); // Consome o caractere de nova linha

    // Busca o aluno pelo nome (simulando matrícula como nome)
    fseek(arquivo, 0, SEEK_SET);  // Posiciona no início do arquivo
    while (fread(&aluno, sizeof(ALUNO), 1, arquivo)) {
        // Se encontrou o aluno, altera os dados
        if (strcmp(aluno.nome, matricula) == 0) {
            printf("Aluno encontrado. Digite os novos dados.\n");
            printf("Novo nome: ");
            fgets(aluno.nome, 81, stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

            printf("Nova nota 1: ");
            scanf("%f", &aluno.nota1);

            printf("Nova nota 2: ");
            scanf("%f", &aluno.nota2);

            // Volta o ponteiro para o início da posição do aluno e grava os novos dados
            fseek(arquivo, -sizeof(ALUNO), SEEK_CUR);
            fwrite(&aluno, sizeof(ALUNO), 1, arquivo);
            printf("Aluno alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

// Função para consultar os dados de um aluno
void consultar(FILE *arquivo) {
    ALUNO aluno;
    char matricula[9];
    int encontrado = 0;

    // Solicita a matrícula ou nome do aluno
    printf("Digite a matrícula do aluno a ser consultado: ");
    scanf("%s", matricula);
    getchar(); // Consome o caractere de nova linha

    fseek(arquivo, 0, SEEK_SET);  // Posiciona no início do arquivo
    while (fread(&aluno, sizeof(ALUNO), 1, arquivo)) {
        // Verifica se a matrícula corresponde
        if (strcmp(aluno.nome, matricula) == 0) {
            printf("Nome: %s\n", aluno.nome);
            printf("Nota 1: %.2f\n", aluno.nota1);
            printf("Nota 2: %.2f\n", aluno.nota2);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

// Função para excluir um aluno
void excluir(FILE *arquivo) {
    FILE *tempArquivo;
    ALUNO aluno;
    char matricula[9];
    int encontrado = 0;

    // Cria um arquivo temporário
    tempArquivo = fopen("temp.dat", "wb");
    if (tempArquivo == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        return;
    }

    // Solicita a matrícula do aluno
    printf("Digite a matrícula do aluno a ser excluído: ");
    scanf("%s", matricula);
    getchar();  // Consome o caractere de nova linha

    fseek(arquivo, 0, SEEK_SET);  // Posiciona no início do arquivo
    while (fread(&aluno, sizeof(ALUNO), 1, arquivo)) {
        // Se o aluno não for o que está sendo excluído, grava no arquivo temporário
        if (strcmp(aluno.nome, matricula) != 0) {
            fwrite(&aluno, sizeof(ALUNO), 1, tempArquivo);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);

    // Substitui o arquivo original pelo arquivo temporário
    remove("alunos.dat");
    rename("temp.dat", "alunos.dat");

    if (encontrado) {
        printf("Aluno excluído com sucesso!\n");
    } else {
        printf("Aluno não encontrado.\n");
    }
}

// Função principal com o menu de opções
int main() {
    FILE *arquivo;
    int opcao;

    // Abre o arquivo de dados dos alunos
    arquivo = fopen("alunos.dat", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo alunos.dat\n");
        return 1;
    }

    do {
        // Exibe o menu
        printf("\nMenu de Opções:\n");
        printf("1. Incluir aluno\n");
        printf("2. Alterar aluno\n");
        printf("3. Consultar aluno\n");
        printf("4. Excluir aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consome o caractere de nova linha

        switch (opcao) {
            case 1:
                incluir(arquivo);
                break;
            case 2:
                alterar(arquivo);
                break;
            case 3:
                consultar(arquivo);
                break;
            case 4:
                excluir(arquivo);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 5);

    fclose(arquivo);
    return 0;
}
