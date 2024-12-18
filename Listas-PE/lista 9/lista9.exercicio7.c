int compara(Prova* p1, Prova* p2) {
    float soma1 = p1->q1 + p1->q2 + p1->q3 + p1->q4;
    float soma2 = p2->q1 + p2->q2 + p2->q3 + p2->q4;

    if (soma1 < soma2) {
        return 1;  // p1 deve vir depois de p2
    } else if (soma1 > soma2) {
        return 0;  // p1 já está na ordem correta
    }

    // Caso as somas sejam iguais, comparar alfabeticamente pelo nome do aluno
    return strcmp(p1->a.nome, p2->a.nome) > 0;
}
void troca(Prova** p1, Prova** p2) {
    Prova* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}