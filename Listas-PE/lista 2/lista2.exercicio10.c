#include <stdio.h>

int MDC(int x, int y){
  int r;
  while(y!=0){
    r =  x % y;
    x = y;
    y = r;

  }
  return x;
 }
int main(){
  int a, b, mdc;
  printf("digite dois valores para verificar mdc: ");
  scanf("%d %d", &a, &b);
  mdc = MDC(a, b);
  printf("o mdc é %d", mdc);
  return 0;
 }