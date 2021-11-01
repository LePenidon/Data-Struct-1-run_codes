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

// cria a lista
LISTA *lista_criar(void);
// insere um item no inicio da lista
boolean lista_inserir_inicio(LISTA *lista, ITEM *i);
// insere um item no fim da lista
boolean lista_inserir_fim(LISTA *lista, ITEM *i);
// apaga a lista
void lista_apagar(LISTA **ptr);
// remove um item dado um titulo
boolean lista_remover_item(LISTA *lista, char *titulo);
// busca um item na lista
boolean lista_busca(LISTA *lista, char *titulo);
// retorna o tamanho da lista
int lista_tamanho(LISTA *lista);
// verifica se a lista esta vazia
boolean lista_vazia(LISTA *lista);
// verifica se a lista esta cheia
boolean lista_cheia(LISTA *lista);
// troca um item de posicao
boolean lista_troca_posicoes(LISTA *lista, char *titulo, int destino);
// imprime a lista
void lista_imprimir(LISTA *lista);
// insere um item em uma dada posicao
boolean lista_inserir_posicao(LISTA *lista, ITEM *item, int posicao);

#endif