#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H
#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
#define FALSE 0
#define boolean int  //define um tipo booleano
#define inicial 0
#define ERRO -32000

#include <stdbool.h>

#include "./TAD_item/item.h"

typedef struct lista_ LISTA;

LISTA *lista_criar(void);
boolean lista_inserir_inicio(LISTA *lista, ITEM *i);
boolean lista_inserir_fim(LISTA *lista, ITEM *i);
void lista_apagar(LISTA **ptr);
boolean lista_remover_item(LISTA *lista, char *titulo);
boolean lista_busca(LISTA *lista, char *titulo);
int lista_tamanho(LISTA *lista);
boolean lista_vazia(LISTA *lista);
boolean lista_cheia(LISTA *lista);
boolean lista_troca_posicoes(LISTA *lista, char *titulo, int destino);
void lista_imprimir(LISTA *lista);
boolean lista_inserir_posicao(LISTA *lista, ITEM *item, int posicao);

#endif