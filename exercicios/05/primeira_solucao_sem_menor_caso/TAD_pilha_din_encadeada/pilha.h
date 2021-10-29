#ifndef PILHA_H
#define PILHA_H

#define TAM 100

#include <stdbool.h>

#include "../TAD_item/item.h"

typedef struct pilha PILHA;

PILHA *pilha_criar(void);
void pilha_apagar(PILHA **pilha);
int pilha_vazia(PILHA *pilha);
int pilha_cheia(PILHA *pilha);
int pilha_tamanho(PILHA *pilha);
ITEM *pilha_topo(PILHA *pilha);
bool pilha_empilhar(PILHA *pilha, ITEM *item);
ITEM *pilha_desempilhar(PILHA *pilha);
void pilha_print(PILHA *p);
void pilha_inverter(PILHA *p);
void pilha_inserir_em_baixo(PILHA *p, ITEM *item);

#endif
