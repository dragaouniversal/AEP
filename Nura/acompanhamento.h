#ifndef ACOMPANHAMENTO_H
#define ACOMPANHAMENTO_H
#include "estruturas.h"

int registrarAcompanhamento(
    Aluno alunos[],
    int quantidadeAlunos,
    Acompanhamento acompanhamentos[],
    int quantidadeAcompanhamentos
);

void consultarAcompanhamentos(
    Aluno alunos[],
    int quantidadeAlunos,
    Acompanhamento acompanhamentos[],
    int quantidadeAcompanhamentos
);

void salvarAcompanhamentos(
    Acompanhamento acompanhamentos[],
    int quantidadeAcompanhamentos
);

int carregarAcompanhamentos(
    Acompanhamento acompanhamentos[],
    int limite
);

#endif