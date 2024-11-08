#include <stdio.h>

 
 int main(void){
    int a, b;
    printf("quais numeros deseja verificar se são permutações?: ");
    scanf("%d %d", &a, &b);
    int cont1 = 0, vetA[32];
    while(a > 0){
        vetA[cont1] = a % 10;
        a = a / 10;
        cont1++;
    }
    int cont2 = 0, vetB[32];
    while(b > 0){
        vetB[cont2] = b % 10;
        b = b / 10;
        cont2++;
    }
    if(cont1 != cont2){
        printf("não é permutação");
        return 0;
    }
    for(int x = 0; x < cont1; x++)
        for(int y = 0; y < cont1; y++){
            if(vetA[x] == vetB[y]){
                vetB[y] = 0;
            }
        }
    for(int z = cont1 - 1; z >= 0; z--){
        if(vetB[z] == 0){
            cont1--;
            if(cont1 == 0){
                printf("é permutação");
                return 0;
            }   else{
                printf("não é permutação"); return 0;
            }
        }
        
    }
    return 0;

 }
