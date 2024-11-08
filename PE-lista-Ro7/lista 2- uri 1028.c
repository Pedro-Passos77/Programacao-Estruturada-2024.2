#include <stdio.h>
int mdc(int f1, int f2){
    int rest;
    rest = f1 % f2;
        while(rest!=0){
            f1 = f2;
            f2 = rest;
            rest = f1 % f2;
        } 
    return f2;
}


int main(void){
    int n, f1, f2, i, rest, y;
    printf("quantas rodadas?: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("quantas figurinhas tem cada um?: ");
        scanf("%d %d", &f1, &f2);  
        y = mdc(f1, f2);
        printf("%d\n", y);
        }
     
    







    return 0;
}