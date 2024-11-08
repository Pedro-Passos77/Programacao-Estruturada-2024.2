#include <stdio.h>
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int bt[m-1];
    for(int i = 0; i < m; i++ ){
        scanf("%d", &bt[i]);
    }
    
    int verdadeiro = n, falso = 0;
    for(int x = 0; x < m; x++)
        for(int y = x+1; y < m; y++){
            if(bt[x] == bt[y] && bt[x] != 0){
                bt[y] = 0;
                falso++;
            }
        }
    verdadeiro = verdadeiro - falso;
    printf("%d\n", falso); printf("%d\n", verdadeiro);
    
    return 0;
}