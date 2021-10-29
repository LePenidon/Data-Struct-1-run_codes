#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

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

int main(int argc, char *argv[]) {
    PILHA *p = NULL;
    ITEM *it;
    int qtd = 0, num = 0;

    p = pilha_criar();

    /*Quantidade de dados a empilhar*/
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        scanf("%d", &num);
        pilha_empilhar(p, item_criar(num));
    }

    pilha_inverter(p);

    pilha_print(p);

    pilha_apagar(&p);

    return 0;
}
