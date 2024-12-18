O código dado parece ter um erro de sintaxe, mais especificamente na declaração e inicialização da variável aniversarios.

Aqui está a parte relevante do código:

Data aniversarios[3] 
{4,2,"FEVEREIRO"},{10,3,"MAIO"} };
A sintaxe correta para inicializar um array de structs no C seria usar as chaves corretamente para cada elemento dentro do array. De acordo com a sintaxe de inicialização de arrays em C, a maneira correta seria:


Data aniversarios[3] = {
    {4, 2, "FEVEREIRO"},
    {10, 3, "MAIO"},
    {5, 1, "JANEIRO"}  // Terceiro elemento que faltava
};