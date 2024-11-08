#include <stdio.h>
#include <stdlib.h>

float *acima_media(int n, float *vetor, int *tamanho)
{
    int i, soma = 0, contador = 0, contadorVetor = 0;
    float *vetorTemporario;
    float media;

    for (i = 0; i < n; i++)
    {
        soma += vetor[i];
    }
    media = soma / n;

    for (i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            contador++;
        }
    }

    *tamanho = contador;
    vetorTemporario = (float *)malloc((*tamanho) * sizeof(float));
    if (vetorTemporario == NULL)
        exit(1);

    for (i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            vetorTemporario[contadorVetor] = vetor[i];
            contadorVetor++;
        }
    }
    return vetorTemporario;
}

int main()
{
    int i, n;
    float *v;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (float *)malloc(n * sizeof(float));
    if (v == NULL)
        exit(1);

    for (i = 0; i < n; i++)
    {
        printf("Digite o valor do índice %d do vetor: ", i);
        scanf("%f", &v[i]);
    }

    float *vetorAcimaMedia = acima_media(n, v, &tamanho);

    printf("O vetor final é: ");
    for (i = 0; i < tamanho; i++)
        printf("%g ", vetorAcimaMedia[i]);

    free(v);
    free(vetorAcimaMedia);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

float *acima_media(int n, float *vetor, int *tamanho)
{
    int i, soma = 0, contador = 0, contadorVetor = 0;
    float *vetorTemporario;
    float media;

    for (i = 0; i < n; i++)
    {
        soma += vetor[i];
    }
    media = soma / n;

    for (i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            contador++;
        }
    }

    *tamanho = contador;
    vetorTemporario = (float *)malloc((*tamanho) * sizeof(float));
    if (vetorTemporario == NULL)
        exit(1);

    for (i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            vetorTemporario[contadorVetor] = vetor[i];
            contadorVetor++;
        }
    }
    return vetorTemporario;
}

int main()
{
    int i, n;
    float *v;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (float *)malloc(n * sizeof(float));
    if (v == NULL)
        exit(1);

    for (i = 0; i < n; i++)
    {
        printf("Digite o valor do índice %d do vetor: ", i);
        scanf("%f", &v[i]);
    }

    float *vetorAcimaMedia = acima_media(n, v, &tamanho);

    printf("O vetor final é: ");
    for (i = 0; i < tamanho; i++)
        printf("%g ", vetorAcimaMedia[i]);

    free(v);
    free(vetorAcimaMedia);

    return 0;
}
