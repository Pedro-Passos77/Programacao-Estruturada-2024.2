#include <stdio.h>

int main() {
    int a, b, c, d;
    float e, f, g, h;
    char v[10];
    int x;

    int *ptr = &a;

    printf("Endereço de a: %p\n", (void*)&a);
    printf("Endereço de b: %p\n", (void*)&b);
    printf("Endereço de c: %p\n", (void*)&c);
    printf("Endereço de d: %p\n", (void*)&d);
    printf("Endereço de e: %p\n", (void*)&e);
    printf("Endereço de f: %p\n", (void*)&f);
    printf("Endereço de g: %p\n", (void*)&g);
    printf("Endereço de h: %p\n", (void*)&h);
    printf("Endereço de v: %p\n", (void*)v);
    printf("Endereço de x: %p\n", (void*)&x);

    ptr++;
    printf("Endereço do ponteiro após incremento: %p\n", (void*)ptr);
    printf("Conteúdo do endereço apontado: %d\n", *ptr); // Pode resultar em comportamento indefinido

    if (ptr == &b) {
        printf("O ponteiro coincide com o endereço de b.\n");
    } else if (ptr == &c) {
        printf("O ponteiro coincide com o endereço de c.\n");
    } else if (ptr == &d) {
        printf("O ponteiro coincide com o endereço de d.\n");
    } else if (ptr == (int*)&e) {
        printf("O ponteiro coincide com o endereço de e.\n");
    } else if (ptr == (int*)&f) {
        printf("O ponteiro coincide com o endereço de f.\n");
    } else if (ptr == (int*)&g) {
        printf("O ponteiro coincide com o endereço de g.\n");
    } else if (ptr == (int*)&h) {
        printf("O ponteiro coincide com o endereço de h.\n");
    } else if (ptr == (int*)v) {
        printf("O ponteiro coincide com o endereço do vetor v.\n");
    } else if (ptr == &x) {
        printf("O ponteiro coincide com o endereço de x.\n");
    } else {
        printf("O ponteiro não coincide com o endereço de nenhuma outra variável.\n");
    }

    return 0;
}
