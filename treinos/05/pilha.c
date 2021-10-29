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

    if ((p == NULL) || (pilha_vazia(p))) {
        printf("Pilha invalida!\n");
        return;
    }

    no_aux = p->topo;

    while (no_aux->anterior != NULL) {
        printf("%d ", item_get_chave(no_aux->item));

        no_aux = no_aux->anterior;
    }

    printf("%d ", item_get_chave(no_aux->item));
    printf("\n");
}

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

void pilha_copiar(PILHA *copiar, PILHA *final) {
    NO *no_aux;

    if ((copiar == NULL || pilha_vazia(copiar)) || (final == NULL)) {
        printf("Pilha invalida!\n");
        return;
    }

    no_aux = copiar->topo;

    while (no_aux->anterior != NULL) {
        pilha_empilhar(final, no_aux->item);

        no_aux = no_aux->anterior;
    }

    pilha_empilhar(final, no_aux->item);
    pilha_inverter(final);
}