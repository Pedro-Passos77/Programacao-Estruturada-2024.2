#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[81];
    float nota1, nota2;
    struct aluno *prox;
};

typedef struct aluno Aluno;

// Função para imprimir a lista de alunos
void imprimir(Aluno *lst) {
    Aluno *atual = lst;
    while (atual != NULL) {
        printf("Nome: %s, Nota1: %.2f, Nota2: %.2f\n", atual->nome, atual->nota1, atual->nota2);
        atual = atual->prox;
    }
}

// Função para incluir um aluno no final da lista
Aluno* incluir(Aluno *lst, const char *nome, float nota1, float nota2) {
    Aluno *novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno == NULL) {
        printf("Erro ao alocar memória.\n");
        return lst;
    }
    strcpy(novoAluno->nome, nome);
    novoAluno->nota1 = nota1;
    novoAluno->nota2 = nota2;
    novoAluno->prox = NULL;

    if (lst == NULL) {
        return novoAluno; // Lista vazia, o novo aluno é o primeiro
    }

    Aluno *atual = lst;
    while (atual->prox != NULL) {
        atual = atual->prox; // Avança até o último elemento
    }
    atual->prox = novoAluno; // Adiciona o novo aluno no final
    return lst;
}

// Função para excluir um aluno da lista
Aluno* excluir(Aluno *lst, const char *nome) {
    Aluno *ant = NULL, *atual = lst;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (ant == NULL) {
                lst = atual->prox; // Remove o primeiro elemento
            } else {
                ant->prox = atual->prox; // Remove o elemento no meio
            }
            free(atual);
            return lst;
        }
        ant = atual;
        atual = atual->prox;
    }

    printf("Aluno não encontrado.\n");
    return lst;
}

// Função para alterar as notas de um aluno
Aluno* alterar(Aluno *lst, const char *nome, float novaNota1, float novaNota2) {
    Aluno *atual = lst;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            atual->nota1 = novaNota1;
            atual->nota2 = novaNota2;
            printf("Notas do aluno %s alteradas.\n", nome);
            return lst;
        }
        atual = atual->prox;
    }

    printf("Aluno não encontrado.\n");
    return lst;
}

// Função para carregar a lista de alunos a partir de um arquivo
Aluno* carregarListaDeArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Aluno *lst = NULL;
    char nome[81];
    float nota1, nota2;

    while (fscanf(arquivo, "%80[^\n]%*c %f %f", nome, &nota1, &nota2) == 3) {
        lst = incluir(lst, nome, nota1, nota2);
    }

    fclose(arquivo);
    return lst;
}

int main() {
    Aluno *lista = NULL;

    // Carregar alunos do arquivo
    lista = carregarListaDeArquivo("alunos.txt");

    // Menu de operações
    int opcao;
    char nome[81];
    float nota1, nota2;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Imprimir lista de alunos\n");
        printf("2. Incluir aluno\n");
        printf("3. Alterar aluno\n");
        printf("4. Excluir aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere '\n'

        switch (opcao) {
            case 1:
                imprimir(lista);
                break;
            case 2:
                printf("Digite o nome do aluno: ");
                fgets(nome, 81, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove '\n' no final
                printf("Digite a nota 1: ");
                scanf("%f", &nota1);
                printf("Digite a nota 2: ");
                scanf("%f", &nota2);
                lista = incluir(lista, nome, nota1, nota2);
                break;
            case 3:
                printf("Digite o nome do aluno a ser alterado: ");
                fgets(nome, 81, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite a nova nota 1: ");
                scanf("%f", &nota1);
                printf("Digite a nova nota 2: ");
                scanf("%f", &nota2);
                lista = alterar(lista, nome, nota1, nota2);
                break;
            case 4:
                printf("Digite o nome do aluno a ser excluído: ");
                fgets(nome, 81, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                lista = excluir(lista, nome);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
