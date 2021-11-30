#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ab_ehabb_aux(NO *raiz);
bool ab_ehabb(AB *T);

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