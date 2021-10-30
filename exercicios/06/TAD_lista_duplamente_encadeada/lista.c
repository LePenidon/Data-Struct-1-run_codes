#include "lista.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_ NO;

struct no_ {
    ITEM *item;
    NO *anterior;
    NO *proximo;
};

struct lista_ {
    NO *inicio;
    NO *fim;
    int tamanho; /*tamanho da lista*/
};

/*Cria	logicamente	uma	lista,	inicialmente	vazia*/
LISTA *lista_criar(void) {
    /*pré-condição: existir espaço na memória.*/
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return (lista);
}

boolean lista_inserir_inicio(LISTA *lista, ITEM *i) {
    if ((lista != NULL) && (!lista_cheia(lista))) {
        NO *pnovo = (NO *)malloc(sizeof(NO));
        pnovo->item = i;

        if (lista->inicio == NULL) {
            //lista->inicio = pnovo;
            lista->fim = pnovo;
            pnovo->proximo = NULL;
        } else {
            lista->inicio->anterior = pnovo;
            pnovo->proximo = lista->inicio;
        }
        pnovo->anterior = NULL;
        lista->inicio = pnovo;
        lista->tamanho++;

        return (TRUE);
    } else {
        return (FALSE);
    }
}

/*Insere um novo nó no fim da lista. PARA LISTAS NÃO ORDENADAS*/
boolean lista_inserir_fim(LISTA *lista, ITEM *item) {
    if ((lista != NULL) && (!lista_cheia(lista))) {
        NO *pnovo = (NO *)malloc(sizeof(NO));
        pnovo->item = item;
        if (lista->inicio == NULL) {
            lista->inicio = pnovo;
            pnovo->anterior = NULL;
        } else {
            lista->fim->proximo = pnovo;
            pnovo->anterior = lista->fim;
        }
        pnovo->proximo = NULL;
        lista->fim = pnovo;
        lista->tamanho++;
        return (TRUE);
    } else
        return (FALSE);
}

void lista_esvazia(NO *ptr) {
    if (ptr != NULL) {
        if (ptr->proximo != NULL)
            lista_esvazia(ptr->proximo);

        item_apagar(&ptr->item);
        ptr->anterior = NULL;
        free(ptr); /* apaga o nó*/
        ptr = NULL;
    }
}

void lista_apagar(LISTA **ptr) {
    if (*ptr == NULL)
        return;

    lista_esvazia((*ptr)->inicio);
    free(*ptr);
    *ptr = NULL;

    return;
}

boolean lista_busca(LISTA *lista, char *titulo) {
    NO *p;
    if (lista != NULL) {
        p = lista->inicio;
        while (p != NULL) {
            if (item_get_titulo(p->item) == titulo)
                return (TRUE);
            p = p->proximo;
        }
    }
    return (FALSE);
}

int lista_tamanho(LISTA *lista) {
    return ((lista != NULL) ? lista->tamanho : ERRO);
}

boolean lista_vazia(LISTA *lista) {
    if ((lista != NULL) && lista->inicio == NULL)
        return (TRUE);
    return (FALSE);
}

boolean lista_cheia(LISTA *lista) {
    return FALSE;
}

boolean lista_troca_posicoes(LISTA *lista, char *titulo, int destino) {
    NO *p, *proximo, *anterior, *achou;
    int i = 0, index, continuar = 1, destino_final;
    ITEM *aux;
    destino_final = destino - 1;

    if (lista != NULL) {
        p = lista->inicio;

        if (destino_final < 0) {
            return (true);
        }

        while (p != NULL) {
            if (strcmp(item_get_titulo(p->item), titulo) == 0) {
                proximo = p->proximo;
                anterior = p->anterior;
                achou = p;
                index = i;
                continuar = 0;
                break;
            }
            p = p->proximo;
            i++;
        }
        if (continuar || index == destino_final) {
            return (false);
        }
        if (destino_final >= lista_tamanho(lista) - 1) {
            aux = item_criar();
            item_set_valores(aux, item_get_titulo(p->item), item_get_url(p->item));

            lista_remover_item(lista, titulo);
            lista_inserir_fim(lista, aux);

            return (TRUE);
        } else if (destino_final == 0) {
            aux = item_criar();
            item_set_valores(aux, item_get_titulo(p->item), item_get_url(p->item));

            lista_remover_item(lista, titulo);
            lista_inserir_inicio(lista, aux);
        } else {
            aux = item_criar();
            item_set_valores(aux, item_get_titulo(p->item), item_get_url(p->item));

            lista_remover_item(lista, titulo);
            lista_inserir_posicao(lista, aux, destino_final);

            return (TRUE);
        }
    }
    return (FALSE);
}

boolean lista_remover_item(LISTA *lista, char *titulo) {
    NO *p = NULL;
    if ((lista != NULL) && (!lista_vazia(lista))) {
        p = lista->inicio;

        /*Percorre a lista em busca da chave*/
        while (p != NULL && (strcmp(item_get_titulo(p->item), titulo) != 0))
            p = p->proximo;

        if (p != NULL) {            /*Se a lista não acabou significa que encontrou a chave*/
            if (p == lista->inicio) /*Se é o 1º da lista basta acertar o ptr inicio*/
                lista->inicio = p->proximo;
            else /*Se não é o 1º da lista, há alguém antes dele para acertar o ptr*/
                p->anterior->proximo = p->proximo;
            if (p == lista->fim) /* Ideia do if/else anterior para o fim da lista */
                lista->fim = p->anterior;
            else
                p->proximo->anterior = p->anterior;
            p->proximo = NULL;
            p->anterior = NULL;
            free(p);
            lista->tamanho--;

            return (TRUE);
        }
    }

    return (FALSE); /*elemento (chave) não está na lista ou lista vazia*/
}

void lista_imprimir(LISTA *lista) {
    NO *no_aux;

    if ((lista == NULL) || (lista_vazia(lista))) {
        printf("Lista invalida!\n");
        return;
    }

    no_aux = lista->inicio;

    while (no_aux->proximo != NULL) {
        printf("%s %s\n", item_get_titulo(no_aux->item), item_get_url(no_aux->item));

        no_aux = no_aux->proximo;
    }

    printf("%s %s", item_get_titulo(no_aux->item), item_get_url(no_aux->item));

    printf("\n");
}

// funcao para inserir em uma posicao dada
boolean lista_inserir_posicao(LISTA *lista, ITEM *item, int posicao) {
    // declaracao das variaveis
    int i;
    NO *no_aux, *temp;
    char *titulo, *url;

    strcpy(titulo, item_get_titulo(item));
    strcpy(url, item_get_url(item));

    // verifica se a lista esta vazia
    if (lista->inicio == NULL) {
        printf("Lista invalida!\n");
        return FALSE;
    }

    temp = lista->inicio;
    i = 0;

    // roda ate a achar a posicao
    while (i < posicao - 1 && temp != NULL) {
        temp = temp->proximo;
        i++;
    }

    printf("\ntemp titulo: %s", item_get_titulo(temp->item));
    printf("\ntemp url: %s\n\n", item_get_url(temp->item));

    // verifica se esta null e insere o  item
    if (temp != NULL) {
        // no_aux->item = item_criar();
        // item_set_valores(no_aux->item, titulo, url);

        // no_aux->proximo = temp->proximo;
        // no_aux->anterior = temp;

        // if (temp->proximo != NULL) {
        //     temp->proximo->anterior = no_aux;
        // }

        // temp->proximo = no_aux;

        // lista->tamanho++;
    } else {
        // nao de certo
        printf("Posicao invalida\n");
        return FALSE;
    }

    return TRUE;
}
