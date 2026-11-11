#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    int id;
    char nome[100];
    char matricula[20];
    char turma[30];
    char serie[30];
    float frequencia;
    int ativo;
} Aluno;

#endif