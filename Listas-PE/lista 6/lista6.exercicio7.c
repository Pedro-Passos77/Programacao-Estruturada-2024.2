#include <stdio.h>
#include <stdlib.h>

void repeticoes(int *vet, int tamanho)
{
    int i, j;
    int *vf;
    int cont = 0;

    vf = (int *) malloc(tamanho * sizeof(int));
    if (vf == NULL)
    {
        exit(1);
    }

    for (i = 0; i < tamanho; i++)
    {
        vf[i] = -1; // Usamos -1 para indicar que a posição está vazia
    }

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            if ((vet[i] == vet[j]) && (i != j) && !contem(vf, cont, vet[i]))
            {
                vf[cont] = vet[i];
                cont++;
            }
        }
    }

    printf("O vetor final é: ");
    for (i = 0; i < cont; i++)
    {
        if (vf[i] != -1) // Imprime apenas valores válidos
            printf("%d ", vf[i]);
    }
    printf("\n");

    free(vf);
}

bool contem(int *v, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            return true;
    }
    return false;
}

int main()
{
    int i, n;
    int *v;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));
    if (v == NULL)
    {
        exit(1);
    }

    printf("Preencha o vetor: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        while (v[i] > 9 || v[i] < 0)
        {
            printf("Erro! Digite um número entre 0 e 9: ");
            scanf("%d", &v[i]);
        }
    }

    repeticoes(v, n);

    free(v);
    return 0;
}
