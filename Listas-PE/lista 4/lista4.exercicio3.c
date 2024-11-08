O que será impresso na tela pelo seguinte programa:
int main()
{
    int numbers[5];
    int *p;
    int n;
    p = numbers;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) = 50;
    for (n = 0; n < 5; n++)
        printf(“%d”, numbers[n]);


    resposta:
    numbers[0] = 10
    numbers[1] = 20
    numbers[2] = 30
    numbers[3] = 40
    numbers[4] = 50
    Portanto, o que será impresso na tela é:

        1020304050