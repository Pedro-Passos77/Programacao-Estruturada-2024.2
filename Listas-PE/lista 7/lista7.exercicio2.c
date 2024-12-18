frase = "Otimo teste"
p = frase + strlen(frase) - 1:
O loop inverte a última palavra da string (teste) e a coloca em misterio.
Após o loop:

misterio = "etset"
Adiciona espaço após a palavra invertida:

misterio[5] = ' '.
Incrementa i.
O loop copia a primeira palavra (Otimo) de frase para misterio.
Após o loop:

misterio = "etset Otimo"
Finaliza a string:

misterio[11] = '\0' para indicar o fim da string.
Imprime misterio:

A função puts imprime:
Saída final:
etset Otimo