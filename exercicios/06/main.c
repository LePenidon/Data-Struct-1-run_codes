#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./TAD_lista_duplamente_encadeada/TAD_item/item.h"
#include "./TAD_lista_duplamente_encadeada/lista.h"

// função que le o titulo
char *le_titulo() {
    // malloca com a quantidade necessaria
    char *string = (char *)malloc(sizeof(char) * 40);
    char *final = (char *)malloc(sizeof(char) * 40);
    int i = 0;

    // le o input
    fgets(string, 40, stdin);

    // transforma o input em uma string melhor
    while (string[i] != '\n') {
        final[i] = string[i];
        i++;
        if (string[i] == '\n') {
            final[i] = '\0';
            break;
        }
    }

    // retorna a string
    return final;
}

// função que le a url
char *le_url() {
    // malloca com a quantidade necessaria
    char *string = (char *)malloc(sizeof(char) * 512);
    char *final = (char *)malloc(sizeof(char) * 512);
    int i = 0;

    // le o input
    fgets(string, 512, stdin);

    // transforma o input em uma string melhor
    while (string[i] != '\n') {
        final[i] = string[i];
        i++;
        if (string[i] == '\n') {
            final[i] = '\0';
            break;
        }
    }

    // retorna a string
    return final;
}

// opcao 01 do menu
void f01(LISTA *lista, char *titulo, char *url) {
    // cria um item
    ITEM *item = item_criar();

    // seta os valores do item
    item_set_valores(item, titulo, url);

    // insere o item no fim da lista
    lista_inserir_fim(lista, item);

    return;
}

// funcao 02 do menu
void f02(LISTA *lista, char *titulo, int posicao) {
    // verifica se a posicao desejada e 0
    if (posicao == 0) {
        return;
    }

    // troca um item de posicao
    lista_troca_posicoes(lista, titulo, posicao);

    return;
}

// opcao 03 do menu
void f03(LISTA *lista) {
    // imprime a lista
    lista_imprimir(lista);

    return;
}

// opcao 04 do menu
void f04(void) {
    // sai do programa
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

    // while infinito (acaba quando valor_menu == 4)
    do {
        // le a opcao do usuario
        scanf(" %d", &valor_menu);
        getchar();

        // chama a funcao respectiva que o usuario deseja
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
            // sai do programa
            f04();
        }
    } while (1);

    return (0);
}