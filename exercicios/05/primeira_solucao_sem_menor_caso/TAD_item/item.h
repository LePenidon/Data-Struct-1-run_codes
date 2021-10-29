#ifndef ITEM_H
#define ITEM_H

#define TRUE 1 /*define valor booleano � n�o existe na linguagem C*/
#define FALSE 0
#define boolean int /*define um tipo booleano*/
#define ERRO -32000

#include <stdbool.h>

typedef struct item_ ITEM;

ITEM *item_criar(int x, int y);
bool item_apagar(ITEM **item);
void item_imprimir(ITEM *item);
int item_get_chave_x(ITEM *item);
int item_get_chave_y(ITEM *item);
bool item_set_chave_x(ITEM *item, int x);
bool item_set_chave_y(ITEM *item, int y);

#endif
