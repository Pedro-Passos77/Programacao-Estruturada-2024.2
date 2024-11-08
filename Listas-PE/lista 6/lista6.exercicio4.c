#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tamanho);

int main(){
    int n, p1, p2, tamanho;
    int *inscr, *class;
    float *t1, *t2;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número de participantes: ");
    scanf("%d", &n);

    inscr = (int*) malloc(n * sizeof(int));
    t1 = (float*) malloc(n * sizeof(float));
    t2 = (float*) malloc(n * sizeof(float));

    if( inscr == NULL || t1 == NULL || t2 == NULL){
        printf("ERRO ALLOC");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Digite o número da inscrição %d: ", i);
        scanf("%d", &inscr[i]);
    }

    for (int i = 0; i < n; i++){
        printf("I%d\n", inscr[i]);
    }

    printf("Digite o peso para T1: ");
    scanf("%d", &p1);
    printf("Digite o peso para T2: ");
    scanf("%d", &p2);

    for (int i = 0; i < n; i++){
        printf("Digite a nota do teste 1 do participante %d: ", i);
        scanf("%f", &t1[i]);
        printf("Digite a nota do teste 2 do participante %d: ", i);
        scanf("%f", &t2[i]);
    }

    class = premiados(n, inscr, t1, p1, t2, p2, &tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", class[i]);
    }
    printf("\n");

    free(inscr);
    free(t1);
    free(t2);
    free(class);

    return 0;
}

int *premiados(int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tamanho){

    int* premiados;
    int cont_premiado = 0;
    float *media;

    media = (float*) malloc(n * sizeof(float));
    if( media == NULL ){
        printf("ERRO ALLOC");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        media[i] = (t1[i]*p1 + t2[i]*p2) / (p1 + p2);
    }

    float mediaGeral = 0;
    for (int i = 0; i < n; i++) {
        mediaGeral += media[i];
    }
    mediaGeral /= n;

    for (int i = 0; i < n; i++){
        if(media[i] >= mediaGeral){
            cont_premiado++;
        }
    }
    *tamanho = cont_premiado;

    premiados = (int*) malloc(cont_premiado * sizeof(int));

    if ( premiados == NULL ){
        printf("ERRO ALLOC");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        if(media[i] >= mediaGeral){
            premiados[index] = inscr[i];
            index++;
        }
    }

    free(media);

    return premiados;
}
