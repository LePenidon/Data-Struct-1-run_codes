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
    // criacao das variaveis
    NO *p, *proximo, *anterior, *achou;
    int i = 0, continuar = 1;
    ITEM *aux;

    // verifica se a lista e valida
    if (lista != NULL) {
        p = lista->inicio;
        // verifica se o destino e valido
        if (destino < 0) {
            return (true);
        }
        // percorre a lista ate achar o item com o titulo dado
        while (p != NULL) {
            if (strcmp(item_get_titulo(p->item), titulo) == 0) {
                proximo = p->proximo;
                anterior = p->anterior;
                achou = p;
                continuar = 0;
                break;
            }
            p = p->proximo;
            i++;
        }

        // verifica se achou o item em questo
        if (continuar) {
            return (false);
        }

        // verifica se o destino e o primeiro elemento da lista
        if (destino == 1) {
            // cria o item e insere no inicio
            aux = item_criar();
            item_set_valores(aux, item_get_titulo(p->item), item_get_url(p->item));

            lista_remover_item(lista, titulo);
            lista_inserir_inicio(lista, aux);
        } else {
            // cria o item e insere na posicao dada
            aux = item_criar();
            item_set_valores(aux, item_get_titulo(p->item), item_get_url(p->item));

            lista_remover_item(lista, titulo);
            lista_inserir_posicao(lista, aux, destino);

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
    // criacao das variaveis
    int i;
    NO *novo_no, *temp;

    // verifica se a lista e valida
    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return (FALSE);
    } else {
        temp = lista->inicio;
        i = 1;

        // percorre ate achar o NO na posicao dada
        while (i < posicao - 1 && temp != NULL) {
            temp = temp->proximo;
            i++;
        }
        // verifica a posicao dada
        if (posicao == 1) {
            // insere no inicio
            lista_inserir_inicio(lista, item);
        } else if (posicao >= lista->tamanho + 1) {
            // insere no fim
            lista_inserir_fim(lista, item);
        } else if (temp != NULL) {
            // cria o NO e ajusta os ponteiros
            novo_no = (NO *)malloc(sizeof(NO));

            novo_no->item = item;
            novo_no->proximo = temp->proximo;
            novo_no->anterior = temp;

            if (temp->proximo != NULL) {
                temp->proximo->anterior = novo_no;
            }

            temp->proximo = novo_no;
            return (TRUE);
        } else {
            return (FALSE);
        }
    }
}
