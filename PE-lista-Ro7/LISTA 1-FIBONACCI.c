#include <stdio.h>

int sequencia_fibonacci(int n) {
    int fib[n];
    fib[0] = 1;
    fib[1] = 1;
    if (n < 2) 
        return fib[n];
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main(void){
    int n, y;
    while (1){
        printf("Escolha até qual termo da sequência de Fibonacci você deseja chegar: ");
    scanf("%d", &n);
    y = sequencia_fibonacci(n);
    printf("O valor do %dº termo da sequência de Fibonacci é: %d\n", n, y);
    }
    return 0;
}