#include <string.h>

void atribui(Aluno **a, int indice, int matricula, char *nome, float nota1, float nota2, float nota3, char *nomeRua, int numero) {
    // Preenche os dados do aluno
    a[indice]->mat = matricula;
    strcpy(a[indice]->nome, nome);  // Copia o nome para a estrutura
    a[indice]->nota.p1 = nota1;      // Atribui a nota 1
    a[indice]->nota.p2 = nota2;      // Atribui a nota 2
    a[indice]->nota.p3 = nota3;      // Atribui a nota 3

    // Preenche o endereço do aluno
    strcpy(a[indice]->end->rua, nomeRua);  // Copia o nome da rua
    a[indice]->end->numero = numero;       // Atribui o número da casa
}
