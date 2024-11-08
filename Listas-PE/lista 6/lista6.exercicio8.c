#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool contem(int *v, int n, int x)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
            return true;
    }

    return false;
}

int *repeticoes(int *vetor, int tamanho, int *n)
{
    int i, j, cont = 0;
    int *vf = (int *) malloc(tamanho * sizeof(int));
    if (vf == NULL)
    {
        exit(1);
    }

    for (i = 0; i < tamanho; i++)
    {
        for (j = (i + 1); j < tamanho; j++)
        {
            if ((vetor[i] == vetor[j]) && (!contem(vf, cont, vetor[j])))
            {
                vf[cont] = vetor[j];
                cont++;
            }
        }
    }

    *n = cont;

    return vf;
}

int main()
{
    int i, n, nFinal;
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
        while ((v[i] > 9) || (v[i] < 0))
        {
            printf("Erro! Digite um número entre 0 e 9: ");
            scanf("%d", &v[i]);
        }
    }

    int *vetorFinal = repeticoes(v, n, &nFinal);

    printf("O vetor final é: ");
    for (i = 0; i < nFinal; i++)
    {
        printf("%d ", vetorFinal[i]);
    }

    free(v);
    free(vetorFinal);

    return 0;
}
