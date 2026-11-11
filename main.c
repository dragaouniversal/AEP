#include <stdio.h>
#include "menu.h"
#include "estruturas.h"
#include <string.h>
#include "aluno.h"

int main() {
    int opcao;
    int quantidadeAluno = 0;
    Aluno alunos[100];

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                quantidadeAluno = cadastrarAluno(alunos, quantidadeAluno);
                break;

            case 2:
                consultarAlunos(alunos, quantidadeAluno);
                break;

            case 3: {
                int opcaoGerenciamento;
                do {
                    opcaoGerenciamento = menuGerenciamento();

                switch (opcaoGerenciamento) {

                    case 1:
                        edicaoAlunos(alunos, quantidadeAluno);
                        break;

                    case 2:
                        inativarAluno(alunos, quantidadeAluno);
                        break;

                    case 0:
                        printf("\nVoltando ao menu principal...\n");
                        break;

                    case -1:
                        printf("\nEntrada invalida!\n");
                        break;

                    default:
                        printf("\nOpcao inexistente!\n");
                    }
                }
                while (opcaoGerenciamento != 0);
                break;
            } //Usamos as chaves para delimitar o escopo do case 3, pois ele possui um switch interno e uma variável local (opcaoGerenciamento).

            case 4:
                printf("\nAcompanhamento pedagogico em desenvolvimento!\n");
                break;

            case 5:
                printf("\nRelatorios em desenvolvimento!\n");
                break;

            case 6:
                printf("\nAgenda de reuniões em desenvolvimento!\n");
                break;

            case 0:
                printf("\nEncerrando o Nura...\n");
                break;

            case -1:
                printf("\nEntrada invalida! Digite um numero.\n");
                break;

            default:
                printf("\nOpcao inexistente! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}