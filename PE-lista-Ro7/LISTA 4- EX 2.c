#include <stdio.h>
#include <stdlib.h>

void codifica (char *str){
    while(*str != '\0'){
        if(*str >= 97 && *str <= 122){
            *str = '?';
        }
        str++;
    }
}
int main(void){
    char *senha = (char *)malloc(sizeof(char) * 99); 
    printf("qual sua senha?: ");
    scanf("%98s", senha);
    codifica(senha);
    printf("%s", senha);
    free(senha);
    return 0;

}