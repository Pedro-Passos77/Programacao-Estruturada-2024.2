#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    char endereco[100];
    char telefone[20];
    char informacoes[200];

    printf("Digite o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o endereço: ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    sprintf(informacoes, "Nome: %s, Endereço: %s, Telefone: %s", nome, endereco, telefone);

    printf("Informações concatenadas: %s\n", informacoes);

    return 0;
}
