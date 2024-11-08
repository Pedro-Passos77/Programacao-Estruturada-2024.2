#include <stdio.h>
int eh_palindromo(int a){
    int r;
    r = 0;
    while( a > 0){
    r = r * 10 + (a%10);
    a = a / 10;
    }
    return r;
}
int main(void){
    int x, y;
    while(1) {
    printf("escolha uma sequencia a ser verificada: ");
    scanf("%d", &x);
    y = eh_palindromo(x);
    if(y == x) {
        printf("VERDADEIRO\n");
    }
    else {
        printf("FALSO\n");
        break;
    } 
    }
    return 0;
}