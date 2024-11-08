#include <stdio.h>

int inverte_Numero(int a){
  int troca = 0;
  while(a > 0){
       troca += a % 10;
       troca *= 10;
       a /= 10;
       }
   troca /= 10;
  return troca;
  }
int main(void){
  unsigned int a;
  printf("qual numero para inverter?: ");
  scanf("%d", &a);
  int y;
  y = inverte_Numero(a);
  printf("%d", y);
  return 0;
 }