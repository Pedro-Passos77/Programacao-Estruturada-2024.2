#include <stdio.h>
int main(void){
    int h1, m1, h2, m2, mh1, mh2, temp;
    printf("escreva o horário atual e o horário que deseja acordar: ");
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    if (h1 < 0 || h1 > 23 || h2 < 0 || h2 > 23 || m1 < 0 || m1 > 59 || m2 < 0 || m2 > 59) {
        printf("Horário inválido.\n");
        return 1;
    }
    mh1 = (h1*60) + m1;
    mh2 = (h2*60) + m2;
    if(mh2>=mh1){
        temp = mh2 - mh1;
        printf("%d", temp);
    } 
    if(mh2 < mh1){
    temp = -1*(mh1-(24*60)) + mh2;
    printf("%d", temp);
    }
    return 0;
}