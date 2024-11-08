#include <stdio.h>

int main() {
    int jump[]={2,3,5,7,11,13,17};
    printf("%d \n", (jump + 2));
    printf("(jump+2) is equal to the value of the index 2 (or third element) of the vector jump \n");
    return 0;
}
A afirmativa d é falsa.

Justificativa:
pti[1] equivale a *(pti + 1), que aponta para o segundo elemento de veti, cujo valor é 7, e não 10.