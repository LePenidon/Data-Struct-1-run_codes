#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pilha_inverter(PILHA *p);

void pilha_inverter(PILHA *p) {
    NO *antes, *atual, *depois;

    antes = p->topo;
    atual = p->topo->anterior;

    antes->anterior = NULL;

    while (atual != NULL) {
        depois = atual->anterior;
        atual->anterior = antes;
        antes = atual;
        atual = depois;
    }

    p->topo = antes;
}