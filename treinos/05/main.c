#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

int main(int argc, char* argv[]) {
    PILHA* p = NULL;
    ITEM* it;
    int qtd = 0, num = 0;

    p = pilha_criar();

    /*Quantidade de dados a empilhar*/
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        scanf("%d", &num);
        pilha_empilhar(p, item_criar(num));
    }

    pilha_print(p);
    pilha_inverter(p);

    pilha_print(p);

    pilha_apagar(&p);

    return 0;
}
