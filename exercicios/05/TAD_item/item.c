#include "item.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct item_ {
    int x;
    int y;
    /*outros componentes*/
};

ITEM *item_criar(int x, int y) {
    ITEM *item;

    item = (ITEM *)malloc(sizeof(ITEM));

    if (item != NULL) {
        item->x = x;
        item->y = y;
        return (item);
    }
    return (NULL);
}

bool item_apagar(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL; /*Boa pr�tica!*/
        return (true);
    }
    return (false);
}

int item_get_chave_x(ITEM *item) {
    if (item != NULL)
        return (item->x);
    exit(1);
}

int item_get_chave_y(ITEM *item) {
    if (item != NULL)
        return (item->y);
    exit(1);
}

bool item_set_chave_x(ITEM *item, int x) {
    if (item != NULL) {
        item->x = x;
        return (true);
    }
    return (false);
}
bool item_set_chave_y(ITEM *item, int y) {
    if (item != NULL) {
        item->y = y;
        return (true);
    }
    return (false);
}

void item_imprimir(ITEM *item) {
    if (item != NULL)
        printf("(\n-->item: %d %d\n)", item->x, item->y);
}
