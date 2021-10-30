#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./TAD_lista_duplamente_encadeada/TAD_item/item.h"
#include "./TAD_lista_duplamente_encadeada/lista.h"

char *le_titulo() {
    char *string = (char *)malloc(sizeof(char) * 40);
    char *final = (char *)malloc(sizeof(char) * 40);
    int i = 0;

    fgets(string, 40, stdin);

    while (string[i] != '\n') {
        final[i] = string[i];
        i++;
        if (string[i] == '\n') {
            final[i] = '\0';
            break;
        }
    }

    return final;
}

char *le_url() {
    char *string = (char *)malloc(sizeof(char) * 512);
    char *final = (char *)malloc(sizeof(char) * 512);
    int i = 0;

    fgets(string, 512, stdin);

    while (string[i] != '\n') {
        final[i] = string[i];
        i++;
        if (string[i] == '\n') {
            final[i] = '\0';
            break;
        }
    }

    return final;
}

// funcao principal do programa
int main(void) {
    // criacao das variaveis
    int i;
    char *titulo;
    char *url;
    ITEM *item = item_criar();
    LISTA *lista = lista_criar();

    titulo = le_titulo();
    url = le_url();

    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);

    titulo = le_titulo();
    url = le_url();

    item = item_criar();
    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);
    titulo = le_titulo();
    url = le_url();

    item = item_criar();
    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);
    titulo = le_titulo();
    url = le_url();

    item = item_criar();
    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);
    titulo = le_titulo();
    url = le_url();

    item = item_criar();
    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);

    lista_imprimir(lista);

    printf("\n---------------\n");
    lista_troca_posicoes(lista, "5", 1);
    lista_imprimir(lista);
    printf("\n---------------\n");

    titulo = le_titulo();
    url = le_url();
    item = item_criar();
    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);

    lista_imprimir(lista);

    return (0);
}