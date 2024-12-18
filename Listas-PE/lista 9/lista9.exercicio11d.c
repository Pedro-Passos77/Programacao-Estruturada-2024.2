void mostraMateria(Materia* m1) {
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("Aluno: %s, Matrícula: %d\n", m1->V[i].nome, m1->V[i].mat);
        printf("Notas: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", m1->V[i].vNotas[j]);
        }
        printf("\nMédia: %.2f\n", m1->media[i]);
    }
}
