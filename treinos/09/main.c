#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./TAD_item/item.h"
#include "arvore.h"

int main(int argc, char *argv[]) {
    AB *T;
    int qtd_nos = 0, num = 0, lado = 0, pai = 0;
    ITEM *item;

    T = ab_criar();

    scanf("%d", &qtd_nos);
    int i = 0;
    while (i < qtd_nos) {
        scanf("%d", &num);
        scanf("%d", &lado);
        scanf("%d", &pai);
        item = item_criar(num);
        ab_inserir(T, item, lado, pai);
        i++;
    }

    ab_imprimir_pre_ordem(T);

    if (ab_ehabb(T))
        printf("Sim.");
    else
        printf("Não.");

    ab_apagar_arvore(&T);

    return 0;
}