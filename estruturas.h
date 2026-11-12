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

typedef struct{
    int idAluno;
    char data[11];
    char dificuldade[200];
    char estrategia[200];
    char observacao[200];
} Acompanhamento;

typedef struct {
    int idAluno;
    char disciplina[50];
    char periodo[30];
    float nota;
    float frequencia;
} Desempenho;

#endif