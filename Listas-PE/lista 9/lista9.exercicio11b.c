Materia* fillMateria(int numAlunos) {
    Materia* materia = (Materia*) malloc(sizeof(Materia));
    materia->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    materia->nAlunos = numAlunos;

    for (int i = 0; i < numAlunos; i++) {
        materia->V[i] = *fillAluno();  // Preenche cada aluno com a função fillAluno
    }

    return materia;
}
