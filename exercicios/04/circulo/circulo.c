#include "circulo.h"

#include <stdio.h>
#include <stdlib.h>

// definição do tipo CIRCULO, que possui um PONTO e um FLOAT
struct circulo_ {
    PONTO *centro;
    float raio;
};

CIRCULO *circulo_criar(PONTO *p, float raio) {
    // criacao do ponteiro do tipo CIRCULO
    CIRCULO *circulo;

    // verifica se foi possivel alocar dinamicamente
    if ((circulo = (CIRCULO *)malloc(sizeof(CIRCULO))) == NULL)
        exit(1);

    // atribui o centro e o raio do circulo ao CIRCULO criado
    circulo->centro = p;
    circulo->raio = raio;

    // retorna o ponteiro
    return circulo;
}

bool circulo_set_ponto(CIRCULO *c, PONTO *p) {
    // verica se a ponteiro é válido
    if (c == NULL)
        return false;

    // atribui o PONTO p como o centro do CIRCULO c
    c->centro = p;

    // retorna um booleano
    return true;
}

bool circulo_set_raio(CIRCULO *c, float raio) {
    // verifica se o ponteiro é válido
    if (c == NULL)
        return false;

    // atribui ao campo "raio" do CIRCULO o valor passado
    c->raio = raio;

    // retorna um booleano
    return true;
}

PONTO *circulo_get_ponto(CIRCULO *c) {
    // retorna o valor do centro do CIRCULO c
    return c->centro;
}

float circulo_get_raio(CIRCULO *c) {
    // retorna o valor do raio do CIRCULO c
    return c->raio;
}

void circulo_apagar(CIRCULO **circulo) {
    // verifica se o ponteiro é válido
    if (*circulo != NULL) {
        // apaga o ponteiro
        free(*circulo);
        *circulo = NULL;
    }
    // retorna
    return;
}