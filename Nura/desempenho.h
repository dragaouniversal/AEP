#ifndef DESEMPENHO_H
#define DESEMPENHO_H

#include "estruturas.h"
int registrarDesempenho(
    Aluno alunos[],
    int quantidadeAlunos,
    Desempenho desempenhos[],
    int quantidadeDesempenhos
);

void consultarDesempenho(
    Aluno alunos[],
    int quantidadeAlunos,
    Desempenho desempenhos[],
    int quantidadeDesempenhos
);

void avaliarDesempenho(
    Aluno alunos[],
    int quantidadeAlunos,
    Desempenho desempenhos[],
    int quantidadeDesempenhos
);

void salvarDesempenhos(
    Desempenho desempenhos[],
    int quantidadeDesempenhos
);

int carregarDesempenhos(
    Desempenho desempenhos[],
    int limite
);

#endif