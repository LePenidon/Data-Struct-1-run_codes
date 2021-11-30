#include "arvore.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No NO;

struct No {
    ITEM *item;
    NO *esq;
    NO *dir;
};

struct arv_bin {
    NO *raiz;
    int profundidade;
};

AB *ab_criar(void) {
    AB *r = (AB *)malloc(sizeof(AB));
    if (r != NULL) {
        r->raiz = NULL;
        r->profundidade = -1;
    }
    return (r);
}

NO *ab_cria_no(ITEM *item) {
    NO *no = (NO *)malloc(sizeof(NO));

    if (no != NULL) {
        no->dir = NULL;
        no->esq = NULL;
        no->item = item;
    }

    return no;
}

void ab_preordem(NO *raiz) {
    if (raiz != NULL) {
        item_imprimir(raiz->item);
        ab_preordem(raiz->esq);
        ab_preordem(raiz->dir);
    }
}

void ab_emordem(NO *raiz) {
    if (raiz != NULL) {
        ab_emordem(raiz->esq);
        item_imprimir(raiz->item);
        ab_emordem(raiz->dir);
    }
}

void ab_posordem(NO *raiz) {
    if (raiz != NULL) {
        ab_posordem(raiz->esq);
        ab_posordem(raiz->dir);
        item_imprimir(raiz->item);
    }
}

void ab_imprimir_pre_ordem(AB *T) {
    if (T != NULL) {
        ab_preordem(T->raiz);

        return;
    }
    printf("Arvore invalida\n");
}

void ab_imprimir_em_ordem(AB *T) {
    if (T != NULL) {
        ab_emordem(T->raiz);

        return;
    }

    printf("Arvore invalida\n");
}
void ab_imprimir_pos_ordem(AB *T) {
    if (T != NULL) {
        ab_posordem(T->raiz);

        return;
    }
    printf("Arvore invalida\n");
}

NO *ab_inserir_no(NO *raiz, ITEM *item, int lado, int chave) {
    if (raiz != NULL) {
        raiz->esq = ab_inserir_no(raiz->esq, item, lado, chave);
        raiz->dir = ab_inserir_no(raiz->dir, item, lado, chave);
        if (chave == item_get_chave(raiz->item)) {
            if (lado == FILHO_ESQ)
                raiz->esq = ab_cria_no(item);
            else if (lado == FILHO_DIR)
                raiz->dir = ab_cria_no(item);
        }
    }
    return (raiz);
}

boolean ab_inserir(AB *T, ITEM *item, int lado, int chave) {
    if (T->raiz == NULL)
        return ((T->raiz = ab_cria_no(item)) != NULL);
    else
        return ((T->raiz = ab_inserir_no(T->raiz, item, lado, chave)) != NULL);
}

int ab_profundidade_2(NO *no) {
    if (no == NULL) return -1;
    int e = ab_profundidade_2(no->esq);
    int d = ab_profundidade_2(no->dir);

    return ((e > d) ? e : d) + 1;
}

int ab_profundidade(AB *T) {
    if (T == NULL) {
        printf("Arvore invalida!\n");
        return ERRO;
    }

    return (ab_profundidade_2(T->raiz));
}

void apagar_arvore(NO **raiz) {
    if (*raiz != NULL) {
        apagar_arvore(&(*raiz)->esq);
        apagar_arvore(&(*raiz)->dir);
        item_apagar(&(*raiz)->item);
        free(*raiz);
        *raiz = NULL;
    }
}

void ab_apagar_arvore(AB **T) {
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

bool ab_ehabb_aux(NO *raiz) {
    if (raiz == NULL) {
        return true;
    }

    if (raiz->dir == NULL && raiz->esq == NULL) {
        return TRUE;
    } else if (raiz->dir == NULL && raiz->esq != NULL) {
        if ((item_get_chave(raiz->item) < item_get_chave(raiz->esq->item))) {
            return false;
        }
    } else if (raiz->dir != NULL && raiz->esq == NULL) {
        if ((item_get_chave(raiz->item) > item_get_chave(raiz->dir->item))) {
            return false;
        }
    }

    if ((item_get_chave(raiz->item) < item_get_chave(raiz->esq->item)) || (item_get_chave(raiz->item) > item_get_chave(raiz->dir->item))) {
        return false;
    }

    ab_ehabb_aux(raiz->esq);
    ab_ehabb_aux(raiz->dir);

    return true;
}

bool ab_ehabb(AB *T) {
    if (T != NULL) {
        if (T->raiz->dir == NULL && T->raiz->esq == NULL) {
            return TRUE;
        } else if (T->raiz->dir == NULL && T->raiz->esq != NULL) {
            if ((item_get_chave(T->raiz->item) < item_get_chave(T->raiz->esq->item))) {
                return false;
            }
        } else if (T->raiz->dir != NULL && T->raiz->esq == NULL) {
            if ((item_get_chave(T->raiz->item) > item_get_chave(T->raiz->dir->item))) {
                return false;
            }
        }

        if ((item_get_chave(T->raiz->item) > item_get_chave(T->raiz->esq->item)) && (item_get_chave(T->raiz->item) < item_get_chave(T->raiz->dir->item))) {
            return ab_ehabb_aux(T->raiz);
        } else {
            return FALSE;
        }
    }

    return FALSE;
}