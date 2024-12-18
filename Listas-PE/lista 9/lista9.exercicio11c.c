void mediaMateria(Materia* m1) {
    for (int i = 0; i < m1->nAlunos; i++) {
        float soma = 0;
        for (int j = 0; j < 5; j++) {
            soma += m1->V[i].vNotas[j];
        }
        m1->media[i] = soma / 5;
    }
}
