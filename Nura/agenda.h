#ifndef AGENDA_H
#define AGENDA_H
#include "estruturas.h"

int registrarCompromisso(
    Agenda compromissos[],
    int quantidadeAgenda
);

void consultarCompromissos(Agenda compromissos[], int quantidadeAgenda);

void pesquisarCompromissosPorDia(Agenda compromissos[], int quantidadeAgenda);

void cancelarCompromisso(Agenda compromissos[], int quantidadeAgenda);

#endif