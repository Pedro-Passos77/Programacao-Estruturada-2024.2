#include <stdio.h>

int main(void){

    int n;
    printf("digite a quantidade de segundos: ");
    scanf("%d", &n);
    int h, m, s;
    h = n / 3600;
    m = (n/ 60) - (h*60);
    s =  n % 60;
    printf("o numero escolhido tem %d horas, %d minutos e %d segundos. ", h, m, s);
    return 0;
}
