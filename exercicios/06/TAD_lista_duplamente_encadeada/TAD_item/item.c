#include "item.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_ {
    char *titulo;
    char *url;
};

ITEM *item_criar() {
    ITEM *item;

    item = (ITEM *)malloc(sizeof(ITEM));

    if (item != NULL) {
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

char *item_get_titulo(ITEM *item) {
    if (item != NULL)
        return (item->titulo);
    exit(1);
}
char *item_get_url(ITEM *item) {
    if (item != NULL)
        return (item->url);
    exit(1);
}

bool item_set_titulo(ITEM *item, char *titulo) {
    if (item != NULL) {
        item->titulo = titulo;
        return (true);
    }
    return (false);
}

bool item_set_url(ITEM *item, char *url) {
    if (item != NULL) {
        item->url = url;
        return (true);
    }
    return (false);
}

bool item_set_valores(ITEM *item, char *titulo, char *url) {
    if (item != NULL) {
        item->titulo = titulo;
        item->url = url;

        return (true);
    }
    return (false);
}

void item_imprimir(ITEM *item) {
    if (item != NULL)
        printf("%s %s\n", item->titulo, item->url);
}
