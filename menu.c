#include <stdio.h>
#include "menu.h"

int exibirMenu(void) {
    int opcao;

    printf("\n");
    printf("====================================\n");
    printf("               NURA                 \n");
    printf("    Sistema de Acompanhamento       \n");
    printf("             Pedagogico             \n");
    printf("====================================\n");

    printf("\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Consultar alunos\n");
    printf("3 - Gerenciar alunos\n");
    printf("4 - Acompanhamento pedagogico\n");
    printf("5 - Relatorios\n");
    printf("6 - Agenda de reunioes\n");
    printf("0 - Sair\n");

    printf("\nEscolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n');
        return -1;
    }

    return opcao;
}
