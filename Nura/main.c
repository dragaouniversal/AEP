#include <stdio.h>
#include "menu.h"
#include "estruturas.h"
#include <string.h>
#include "aluno.h"
#include "acompanhamento.h"
#include "desempenho.h"
#include "agenda.h"

int main() {
    int opcao;
    int quantidadeAluno = 0;
    Aluno alunos[100];
    int quantidadeAcompanhamentos = 0;
    Acompanhamento acompanhamentos[500];
    int quantidadeDesempenho = 0;
    Desempenho desempenhos[500];
    int quantidadeAgenda = 0;
    Agenda compromissos[500];

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                quantidadeAluno = cadastrarAluno(alunos, quantidadeAluno);
                break;

            case 2:
                int fecha;
                getchar();
                    do{consultarAlunos(alunos, quantidadeAluno);  
                    }
                    while(getchar() != '\n');
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
                    
                    case 3:
                        pesquisarAluno(alunos, quantidadeAluno);
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

            case 4:{
                int opcaoAcompanhamento;
                do {
                    printf("\n===== ACOMPANHAMENTO PEDAGOGICO =====\n");
                    printf("1 - Registrar acompanhamento\n");
                    printf("2 - Consultar historico\n");
                    printf("0 - Voltar ao menu principal\n");
                    printf("Escolha uma opcao: ");
                    if (scanf("%d", &opcaoAcompanhamento) != 1) {
                        while (getchar() != '\n');
                        printf("\nEntrada invalida!\n");
                        continue;
                    }

                    switch (opcaoAcompanhamento){
                        case 1:
                            quantidadeAcompanhamentos = registrarAcompanhamento(
                                alunos,
                                quantidadeAluno,
                                acompanhamentos,
                                quantidadeAcompanhamentos);
                            break;
                        case 2:
                            consultarAcompanhamentos(alunos,
                                quantidadeAluno,
                                acompanhamentos,
                                quantidadeAcompanhamentos);
                            break;
                        case 0:
                            printf("\nVoltando ao menu principal...\n");
                            break;
                        default:
                            printf("\nOpcao invalida!\n");
                    }
                } while (opcaoAcompanhamento != 0);
                break;
            }
            case 5:
                int opcaoDesempenhos;
                do{
                    printf("\n===== DESEMPENHO ACADEMICO =====\n");
                    printf("1 - Registrar desemepnho\n");
                    printf("2 - Consultar desempenho\n");
                    printf("3 - Analisar desempenho\n");
                    printf("0 - Voltar\n");
                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &opcaoDesempenhos) != 1){
                        while(getchar() != '\n');
                        printf("\nEntrada invalida.\n");
                    }
                while(getchar() != '\n');

                switch (opcaoDesempenhos){
                    case 1:
                    quantidadeDesempenho = registrarDesempenho(
                        alunos,
                        quantidadeAluno,
                        desempenhos,
                        quantidadeDesempenho);
                    break;

                    case 2:
                        consultarDesempenho(
                        alunos,
                        quantidadeAluno,
                        desempenhos,
                        quantidadeDesempenho);
                    break;

                    case 3:
                        avaliarDesempenho( alunos, quantidadeAluno, desempenhos, quantidadeDesempenho);
                        break;
                }
                } while(getchar(), opcaoDesempenhos != 0);
                break;

            case 6:
                int opcaoAgenda;
                do{
                    printf("\n================================\n");
                    printf("AGENDA\n");
                    printf("================================\n");
                    printf("1 - Registrar compromisso\n");
                    printf("2 - Consultar compromissos\n");
                    printf("3 - Pesquisar por compromissos\n");
                    printf("4 - Cancelar compromisso\n");
                    printf("0 - Voltar\n");
                    printf("Escolha uma opcao: ");


                    if (scanf("%d", &opcaoAgenda) != 1){
                        while(getchar() != '\n');
                        opcaoAgenda = -1;
                        continue;
                    }

                    while(getchar() != '\n');

                    switch (opcaoAgenda){
                        case 1:
                            quantidadeAgenda = registrarCompromisso(compromissos, quantidadeAgenda);
                            break;
                        case 2:
                            consultarCompromissos(compromissos, quantidadeAgenda);
                            break;
                        case 0:
                            printf("\nVoltando ao menu principal.\n");
                            printf("\nPrecione ENTER para voltar.");
                            break;
                        case 3:
                            pesquisarCompromissosPorDia(compromissos, quantidadeAgenda);
                            break;
                        case 4:
                            cancelarCompromisso(compromissos, quantidadeAgenda);
                            break;
                        case -1:
                            printf("\nDigite um numero inteiro.\n");
                            printf("\nAperte ENTER para inserir novamente.\n");
                            break;
                        default:
                            printf("\nOpcao invalida.\n");
                            printf("\nAperte ENTER para inserir novamente.\n");                            
                            break;
                    }
                
                } while(getchar(), opcaoAgenda != 0);
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
