#include "ponto.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// definição do tipo PONTO, que possui dois FLOAT
struct ponto_ {
    float x, y;
};

PONTO *ponto_criar() {
    // criacao do ponteiro do tipo PONTO
    PONTO *ponto;

    // verifica se foi possivel alocar dinamicamente
    if ((ponto = (PONTO *)malloc(sizeof(PONTO))) == NULL)
        exit(1);

    // retorna o ponteiro
    return ponto;
}

void ponto_apagar(PONTO **p) {
    // verifica se o ponteiro é válido
    if (*p != NULL) {
        // apaga o ponteiro
        free(*p);
        *p = NULL;
    }
    // retorna
    return;
}

bool ponto_set(PONTO *p, float x, float y) {
    // verica se a ponteiro é válido
    if (p == NULL)
        return false;

    // atribui as coordenadas passadas aos campos do PONTO p
    p->x = x;
    p->y = y;

    // retorna um booleano
    return true;
}

float ponto_get_x(PONTO *p) {
    // retorna o valor da coordenada x do PONTO p
    return p->x;
}

float ponto_get_y(PONTO *p) {
    // retorna o valor da coordenada y do PONTO p
    return p->y;
}

void ponto_print(PONTO *p) {
    // imprime as coordenas (x,y) do PONTO p
    printf("%.2f %.2f", p->x, p->y);

    // retorna
    return;
}

float distancia(PONTO *pa, PONTO *pb) {
    // calcula a distância entre o PONTO p1 e o PONTO p2
    float distancia = sqrt(pow(ponto_get_x(pa) - ponto_get_x(pb), 2) + pow(ponto_get_y(pa) - ponto_get_y(pb), 2));

    // retorna o valor calculado
    return distancia;
}