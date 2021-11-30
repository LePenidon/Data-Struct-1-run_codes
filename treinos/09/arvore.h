#ifndef ABDINAMICA_H
#define ABDINAMICA_H
#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
#define FALSE 0
#define boolean int  //define um tipo booleano
#define inicial 0
#define ERRO -32000
#define FILHO_ESQ 0
#define FILHO_DIR 1

#include <stdbool.h>

#include "./TAD_item/item.h"

typedef struct arv_bin AB;

AB *ab_criar(void);
void ab_imprimir_pre_ordem(AB *T);
void ab_imprimir_em_ordem(AB *T);
void ab_imprimir_pos_ordem(AB *T);
boolean ab_inserir(AB *T, ITEM *item, int lado, int chave);
int ab_profundidade(AB *T);
void ab_apagar_arvore(AB **T);
bool ab_ehabb(AB *T);

#endif