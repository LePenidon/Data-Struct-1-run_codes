#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pilha_inverter(PILHA *p);
void pilha_inserir_em_baixo(PILHA *p, ITEM *item);

void pilha_inserir_em_baixo(PILHA *p, ITEM *item) {
    if (pilha_vazia(p)) {
        pilha_empilhar(p, item);
    } else {
        ITEM *temp = pilha_desempilhar(p);
        pilha_inserir_em_baixo(p, item);

        pilha_empilhar(p, temp);
    }
}

void pilha_inverter(PILHA *p) {
    if (!pilha_vazia(p)) {
        ITEM *temp = pilha_desempilhar(p);
        pilha_inverter(p);

        pilha_inserir_em_baixo(p, temp);
    }
}