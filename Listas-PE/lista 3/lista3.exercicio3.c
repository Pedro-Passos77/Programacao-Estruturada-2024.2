Qual é a saída deste programa supondo que i ocupa o endereço 4094 na memória?
main() {
int i=5, *p;
p = &i;
printf("%x %d %d \n", p, *p+2, 3**p);

Primeiro argumento (%x): p

p == &i, que é 4094.
exibido em formato hexadecimal, p = FFE
Segundo argumento (%d): *p + 2

*p == valor de i, que é 5.
*p + 2 é 5 + 2 = 7.
Terceiro argumento (%d): 3 * *p

*p é 5.
3 * *p é 3 * 5 = 15.

saída:
ffe 7 15