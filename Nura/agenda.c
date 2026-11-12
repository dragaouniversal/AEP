#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "agenda.h"

int registrarCompromisso(Agenda compromissos[], int quantidadeAgenda) {

    if (quantidadeAgenda >= 500){ // Verificação de espaço
        printf("\nLimite de compromissos atingido.\n");
        return quantidadeAgenda;
    }

    printf("\n================================\n");
    printf("REGISTRAR COMPROMISSO\n");
    printf("================================\n");

    compromissos[quantidadeAgenda].id = quantidadeAgenda + 1;

    printf("\nDigite a data (DD/MM/AAAA):");
    fgets(compromissos[quantidadeAgenda].dia, 11, stdin);
    compromissos[quantidadeAgenda].dia[strcspn(compromissos[quantidadeAgenda].dia, "\n")] = '\0';

    printf("Digite o horario (HH:MM): ");
    fgets(compromissos[quantidadeAgenda].horario, 6, stdin);
    compromissos[quantidadeAgenda].horario[strcspn(compromissos[quantidadeAgenda].horario, "\n")] = '\0';

    printf("Tipo de compromisso: ");
    fgets(compromissos[quantidadeAgenda].tipo, 50, stdin);
    compromissos[quantidadeAgenda].tipo[strcspn(compromissos[quantidadeAgenda].tipo, "\n")] = '\0';

    printf("Descricao: ");
    fgets(compromissos[quantidadeAgenda].descricao, 200, stdin);
    compromissos[quantidadeAgenda].descricao[strcspn(compromissos[quantidadeAgenda].descricao, "\n")] = '\0';

    printf("Participante: ");
    fgets(compromissos[quantidadeAgenda].participante, 100, stdin);
    compromissos[quantidadeAgenda].participante[strcspn(compromissos[quantidadeAgenda].participante, "\n")] = '\0';

    compromissos[quantidadeAgenda].ativo = 1;

    quantidadeAgenda++;

    printf("\nCompromisso registrado com sucesso!\n");

    return quantidadeAgenda;
}

void consultarCompromissos(Agenda compromissos[], int quantidadeAgenda){
    int encontrados = 0;

    printf("\n================================\n");
    printf("COMPROMISSOS DA AGENDA\n");
    printf("================================\n");

    if (quantidadeAgenda == 0){
        printf("\nNenhum compromisso agendada.\n");
        printf("\nPrecione ENTER para voltar.");
        return;
    }

    for (int i = 0; i<quantidadeAgenda; i++){

        if (compromissos[i].ativo == 1){

            printf("\nID: %d\n", compromissos[i].id);
            printf("Data: %s\n", compromissos[i].dia);
            printf("Horario: %s\n", compromissos[i].horario);
            printf("Tipo: %s\n", compromissos[i].tipo);
            printf("Descricao: %s\n", compromissos[i].descricao);
            printf("Participante: %s\n", compromissos[i].participante);

            printf("--------------------------------\n");

            encontrados++;
        }
    }
    if (encontrados == 0){
        printf("\nNao existe nenhum compromisso no momento");
        printf("\nPrecione ENTER para voltar.");
    }
}

void pesquisarCompromissosPorDia(
    Agenda compromissos[],
    int quantidadeAgenda
) {
    char dia[11];
    int encontrados = 0;

    if (quantidadeAgenda == 0) {
        printf("\nNenhum compromisso cadastrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return;
    }

    printf("\n================================\n");
    printf("PESQUISAR COMPROMISSOS POR DATA\n");
    printf("================================\n");

    getchar();

    printf("\nDigite a data (DD/MM/AAAA): ");
    fgets(dia, sizeof(dia), stdin); // Sizedof informa ao fgets() o tamanho disponivel dentro de "dia".
    dia[strcspn(dia, "\n")] = '\0';

    for (int i = 0; i < quantidadeAgenda; i++) {

        if (compromissos[i].ativo == 1 && strcmp(compromissos[i].dia, dia) == 0){ // Caso a comparação das strings seja verdadeira, o valor será 0.

            printf("\nID: %d\n", compromissos[i].id);
            printf("Data: %s\n", compromissos[i].dia);
            printf("Horario: %s\n", compromissos[i].horario);
            printf("Tipo: %s\n", compromissos[i].tipo);
            printf("Descricao: %s\n", compromissos[i].descricao);
            printf("Participante: %s\n", compromissos[i].participante);

            printf("--------------------------------\n");

            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum compromisso ativo encontrado nessa data.\n");
        printf("\nPrecione ENTER para voltar.");
    }
}

void cancelarCompromisso(Agenda compromissos[], int quantidadeAgenda) {

    int id;
    int encontrado = 0;

    if (quantidadeAgenda == 0) {
        printf("\nNenhum compromisso cadastrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return;
    }

    printf("\n================================\n");
    printf("CANCELAR COMPROMISSO\n");
    printf("================================\n");

    printf("\nDigite o ID do compromisso: ");

    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("\nEntrada invalida!\n");
        printf("\nPrecione ENTER para voltar.");
        return;
    }

    while (getchar() != '\n');

    for (int i = 0; i < quantidadeAgenda; i++) {

        if (compromissos[i].id == id) {

            encontrado = 1;

            if (compromissos[i].ativo == 0) {
                printf("\nEste compromisso ja esta cancelado.\n");
                printf("\nPrecione ENTER para voltar.");
                return;
            }

            printf("\nCompromisso encontrado:\n");
            printf("Data: %s\n", compromissos[i].dia);
            printf("Horario: %s\n", compromissos[i].horario);
            printf("Tipo: %s\n", compromissos[i].tipo);

            compromissos[i].ativo = 0;

            printf("\nCompromisso cancelado com sucesso!\n");
            printf("\nPrecione ENTER para voltar.");

            break;
        }
    }

    if (encontrado == 0) {
        printf("\nCompromisso nao encontrado.\n");
        printf("\nPrecione ENTER para voltar.");
    }
}