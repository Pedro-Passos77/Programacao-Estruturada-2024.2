#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int *aprovados(int n, int *matricula, float *notas, int *tamanho);

int main(){
    int tamanho = 1, quantidade_geral;
    int* matricula;
    float* notas;
    int* aprovados_list;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de alunos matriculados: ");
    scanf("%d", &quantidade_geral);

    matricula = (int*) malloc(quantidade_geral * sizeof(int));
    notas = (float*) malloc(quantidade_geral * sizeof(float));

    if(matricula == NULL || notas == NULL){
        printf("ERRO DE ALLOCAÇÃO");
        exit(1);
    }

    for(int i = 0; i < quantidade_geral; i++){
        printf("Digite a matrícula: ");
        scanf("%d", &matricula[i]);
        printf("Digite a nota: ");
        scanf("%f", &notas[i]);
    }


    aprovados_list = aprovados(quantidade_geral, matricula, notas, &tamanho);


    free(matricula);
    free(notas);
    free(aprovados_list);

    return 0;
}

int *aprovados(int n, int *matricula, float *notas, int *tamanho){
    int* aprovados_list;
    int contador = 0;

    for(int j = 0; j < n; j++){
        if(notas[j] >= 5.0){
            contador++;
        }
    }

    *tamanho = contador;

    aprovados_list = (int*) malloc(contador * sizeof(int));

    if( aprovados_list == NULL ){
        printf("ERRO DE ALLOCAÇÃO");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        if(notas[i] >= 5.0){
            aprovados_list[i] = matricula[i];
        }
    }

    return aprovados_list;
}
