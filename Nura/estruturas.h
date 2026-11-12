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

typedef struct {
    int id;
    char dia[11];
    char horario[6];
    char tipo[50];
    char descricao[200];
    char participante[100];
    int ativo;
} Agenda;

#endif