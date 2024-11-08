#include <stdio.h>

int main(){
    int p, b, soma;
    for( int i = 1000; i <= 9999; i++){
        p = i / 100;
        b = i % 100;
        soma = p + b;
        if(soma * soma == i) printf("%d\n", i);
    }

    return 0;
}
