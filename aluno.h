#ifndef ALUNO_H
#define ALUNO_H
#include "estruturas.h"

int cadastrarAluno(Aluno alunos[], int quantidadeAluno);

void consultarAlunos(Aluno alunos[], int quantidadeAluno);

int menuGerenciamento(void);

void inativarAluno(Aluno alunos[], int quantidadeAluno);

void edicaoAlunos(Aluno alunos[], int quantidadeAluno);

#endif