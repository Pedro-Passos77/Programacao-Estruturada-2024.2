Aqui, a função strlen(sobrenome) está verificando o comprimento do sobrenome. Se o comprimento do sobrenome for maior que 5, o valor de i será impresso; caso contrário, será impresso 0.

Vamos analisar os sobrenomes de cada nome armazenado:

"Fulano Silva": O sobrenome é "Silva", com 5 caracteres, então strlen(sobrenome) não é maior que 5, logo será impresso 0.
"Maria do Carmo": O sobrenome é "Carmo", com 5 caracteres, logo será impresso 0.
"Beltrano Belmonte": O sobrenome é "Belmonte", com 8 caracteres, logo será impresso o valor de i, que é 2.
"Pedro dos Santos": O sobrenome é "Santos", com 6 caracteres, logo será impresso o valor de i, que é 3.
Portanto, o segundo printf imprimirá:


0 0 2 3