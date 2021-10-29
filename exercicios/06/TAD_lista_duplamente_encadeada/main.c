#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./TAD_item/item.h"
#include "lista.h"

int main(void) {
    LISTA *lista;
    ITEM *it;

    lista = lista_criar();

    it = item_criar(1);
    lista_inserir_fim(lista, it);
    it = item_criar(2);
    lista_inserir_fim(lista, it);
    it = item_criar(3);
    lista_inserir_fim(lista, it);

    lista_imprimir(lista);
    printf("%d\n", lista_tamanho(lista));

    it = item_criar(5);
    lista_inserir_posicao(lista, it, 1);

    lista_imprimir(lista);
    printf("%d\n", lista_tamanho(lista));

    // if (lista_busca(lista, 3)) {
    //     printf("temmmmmmmmmm\n");
    // } else {
    //     printf("Nao tem esse item\n");
    // }

    lista_apagar(&lista);

    return (0);
}