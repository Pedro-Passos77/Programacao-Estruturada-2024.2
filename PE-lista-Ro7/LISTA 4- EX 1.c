#include <stdio.h>
#include <stdlib.h>

void shift_troca_string(char *str) {
    while (*str != '\0') {
        if (*str == 'A')
            *str = 'z';
        else if (*str == 'a')
            *str = 'Z';
        else if (*str >= 65 && *str <= 90)
            *str = *str + 31; 
        else if (*str >= 97 && *str <= 122) 
            *str = *str - 33; 
        else
            *str = '!'; 
        str++;
    }
}

int main(void) {
    char *str = (char *)malloc(sizeof(char) * 99);
    printf("Qual a string que será modificada?: ");
    scanf("%98s", str);
    shift_troca_string(str);
    printf("%s\n", str);
    free(str);
    return 0;
}
