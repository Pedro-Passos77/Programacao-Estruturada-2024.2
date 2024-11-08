#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compactar(char *s)
{
    int contagemInicio = 0;

    while(s[contagemInicio] == ' ')
    {
        contagemInicio++;
    }

    int contagemFim = strlen(s) - 1;

    while(s[contagemFim] == ' ')
    {
        contagemFim--;
    }

    int tamanhoCompactado = contagemFim - contagemInicio + 1;
    char *compactado = (char*) malloc((tamanhoCompactado + 1) * sizeof(char));

    if(compactado == NULL)
    {
        printf("ERRO DE ALOCAÇÃO");
        exit(1);
    }

    int posicaoNovoVetor = 0;

    for (int i = contagemInicio; i <= contagemFim; i++)
    {
        compactado[posicaoNovoVetor] = s[i];
        posicaoNovoVetor++;
    }

    compactado[posicaoNovoVetor] = '\0';

    return compactado;
}

int main()
{
    char frase[100];
    scanf(" %99[^\n]", frase);

    char *novaFrase = compactar(frase);

    printf("%s", novaFrase);

    free(novaFrase);

    return 0;
}
