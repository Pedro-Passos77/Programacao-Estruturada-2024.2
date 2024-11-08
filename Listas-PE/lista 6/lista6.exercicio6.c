#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n;
    int *v;
    int *vf;
    int cont = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));
    if (v == NULL)
    {
        exit(1);
    }

    vf = (int *) malloc(n * sizeof(int));
    if (vf == NULL)
    {
        free(v);
        exit(1);
    }

    printf("Preencha o vetor:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        while (v[i] > 9 || v[i] < 0)
        {
            printf("Erro! Digite um número entre 0 e 9: ");
            scanf("%d", &v[i]);
        }
    }

    // Encontra os números duplicados
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i] == v[j] && i != j && !contem(vf, cont, v[i]))
            {
                vf[cont] = v[i];
                cont++;
                break; // Encontra a primeira duplicata e vai para o próximo elemento
            }
        }
    }

    printf("O vetor final é: ");
    for (i = 0; i < cont; i++)
    {
        printf("%d ", vf[i]);
    }
    printf("\n");

    free(v);
    free(vf);
    return 0;
}

bool contem(int *v, int n, int x)
{
    for (int i = 0; i < n; i
