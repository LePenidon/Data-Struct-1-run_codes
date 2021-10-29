#include "pilha.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;

struct no {
    ITEM *item;
    NO *anterior;
};

struct pilha {
    NO *topo;
    int tamanho;
};

PILHA *pilha_criar(void) {
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));

    if (pilha != NULL) {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }

    return (pilha);
}

void pilha_apagar(PILHA **pilha) {
    NO *paux;

    if (((*pilha) != NULL) && (!pilha_vazia(*pilha))) {
        while ((*pilha)->topo != NULL) {
            paux = (*pilha)->topo;
            (*pilha)->topo = (*pilha)->topo->anterior;
            item_apagar(&paux->item);
            paux->anterior = NULL;
            free(paux);
            paux = NULL;
        }
    }

    free(*pilha);
    *pilha = NULL;

    return;
}

int pilha_vazia(PILHA *pilha) {
    return ((pilha != NULL) ? pilha->tamanho == 0 : ERRO);
}

int pilha_cheia(PILHA *pilha) {
    NO *n = (NO *)malloc(sizeof(NO));

    if (n != NULL) {
        free(n);
        n = NULL;

        return 0;
    }

    return 1;
}

int pilha_tamanho(PILHA *pilha) {
    return ((pilha != NULL) ? pilha->tamanho : ERRO);
}

ITEM *pilha_topo(PILHA *pilha) {
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        return (pilha->topo->item);
    }
    return (NULL);
}

bool pilha_empilhar(PILHA *pilha, ITEM *item) {
    NO *pnovo = (NO *)malloc(sizeof(NO));

    if (pnovo != NULL) {
        pnovo->item = item;
        pnovo->anterior = pilha->topo;
        pilha->topo = pnovo;
        pilha->tamanho++;
        return (TRUE);
    }

    return (FALSE);
}

ITEM *pilha_desempilhar(PILHA *pilha) {
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        NO *pno = pilha->topo;
        ITEM *item = pilha->topo->item;

        pilha->topo = pilha->topo->anterior;
        pno->anterior = NULL;
        free(pno);
        pno = NULL;
        pilha->tamanho--;

        return (item);
    }

    return (NULL);
}

void pilha_print(PILHA *p) {
    NO *no_aux;
    int tam;
    int count;

    if ((p == NULL) || (pilha_vazia(p))) {
        printf("Pilha invalida!\n");
        return;
    }

    no_aux = p->topo;
    count = pilha_tamanho(p) - 1;

    while (no_aux->anterior != NULL) {
        count--;
        if (count) {
            printf("(%d, %d) -> ", item_get_chave_x(no_aux->item), item_get_chave_y(no_aux->item));
        } else {
            printf("(%d, %d)", item_get_chave_x(no_aux->item), item_get_chave_y(no_aux->item));
        }

        no_aux = no_aux->anterior;
    }
    printf("\n");
}

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
