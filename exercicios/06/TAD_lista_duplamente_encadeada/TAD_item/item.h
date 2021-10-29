#ifndef ITEM_H
#define ITEM_H

#define TRUE 1 /*define valor booleano � n�o existe na linguagem C*/
#define FALSE 0
#define boolean int /*define um tipo booleano*/
#define ERRO -32000

#include <stdbool.h>

typedef struct item_ ITEM;

ITEM *item_criar(char *titulo, char *url);
bool item_apagar(ITEM **item);
void item_imprimir(ITEM *item);
char *item_get_titulo(ITEM *item);
char *item_get_url(ITEM *item);
bool item_set_titulo(ITEM *item, char *titulo);
bool item_set_url(ITEM *item, char *titulo);

#endif
