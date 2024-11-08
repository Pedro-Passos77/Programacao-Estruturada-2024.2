#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    while (n != 0) {
        int numeros[n], i, posição[n];
        
        for (i = 0; i < n; i++) {
            scanf("%d", &numeros[i]);
            posição[i] = i; // Atribui a posição de cada elemento no vetor
        }
        
        int j, temp;
        for (i = 0; i < n - 1; i++) { // Ajustado o limite do loop externo
            for (j = 0; j < n - i - 1; j++) { // Ajustado o limite do loop interno
                if (numeros[j] > numeros[j + 1]) { // Verifica se o elemento atual é maior que o próximo
                    // Troca de elementos
                    temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                    // Troca de posições
                    temp = posição[j];
                    posição[j] = posição[j + 1];
                    posição[j + 1] = temp;
                }
            }
        }
        
        printf("%d\n", posição[n - 2] + 1); // Imprime a posição do segundo maior elemento
        scanf("%d", &n); // Lê o próximo número total de elementos
    }
    
    return 0;
}
