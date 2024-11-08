#include <stdio.h>

int main(){
  float p1, p2, p3, media;
  printf("Insira as notas das provas: ");
  scanf("%f %f %f", &p1, &p2, &p3);
  while(p1 > 10 || p2 > 10 || p3 > 10 || p1 < 0 || p2 < 0 || p3 < 0){
    printf("insira notas válidas: ");
     scanf("%f %f %f", &p1, &p2, &p3);
  }
  media = (p1 + p2 + p3) / 3;
  if(media >= 6) printf("Aprovado com média: %g", media);
  else if(media < 6 && media >= 4) printf("Aluno com direito a VS, com média: %g", media);
  else printf("Reprovado com média: %g", media);

  return 0;
 }