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

void f01(LISTA *lista, char *titulo, char *url) {
    ITEM *item = item_criar();

    item_set_valores(item, titulo, url);
    lista_inserir_fim(lista, item);

    return;
}

void f02(LISTA *lista, char *titulo, int posicao) {
    if (posicao == 0) {
        return;
    }

    lista_troca_posicoes(lista, titulo, posicao);

    return;
}

void f03(LISTA *lista) {
    lista_imprimir(lista);

    return;
}

void f04(void) {
    exit(EXIT_SUCCESS);
}

// funcao principal do programa
int main(void) {
    // criacao das variaveis
    int valor_menu;
    int posicao_futura;
    char *titulo;
    char *url;
    LISTA *lista = lista_criar();

    do {
        scanf(" %d", &valor_menu);
        getchar();

        if (valor_menu == 1) {
            titulo = le_titulo();
            url = le_url();

            f01(lista, titulo, url);
        } else if (valor_menu == 2) {
            titulo = le_titulo();
            scanf("%d", &posicao_futura);

            f02(lista, titulo, posicao_futura);
        } else if (valor_menu == 3) {
            f03(lista);

        } else if (valor_menu == 4) {
            f04();
        }
    } while (1);

    return (0);
}