#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./TAD_item/item.h"
#include "./TAD_pilha_din_encadeada/pilha.h"

// definicao do tipo coords
typedef struct {
    int x;
    int y;
} coords;

// declaracao das funcoes
void *mallocSafe(int nBytes);
void freeMatrizInt(int **matriz, int linhas);
bool dentroMatriz(int **matriz, int tamMatriz[2], int atual_x, int atual_y);
bool solucao(int **matriz, int tamMatriz[2], coords inicial, coords destino);
bool resolver(int **matriz, int tamMatriz[2], int **solucao, PILHA *p, coords destino, int atual_x, int atual_y);

// declaracao da funcao que aloca os espacos desejados, com seguranca
void *mallocSafe(int nBytes) {
    // declaracao do ponteiro a ser retornado
    void *ptr;

    // aloca os espacos
    ptr = malloc(nBytes);

    // caso o ponteiro tenha valor "NULL", a alocacao deu errado e o programa de encerra
    if (ptr == NULL) {
        printf("Socorro! malloc retornou null!\n");
        exit(EXIT_FAILURE);
    }

    // retorna o ponteiro
    return ptr;
}

// declaracao da funcao que libera os espacos de uma matriz alocada
void freeMatrizInt(int **matriz, int linhas) {
    // declaracao da variavel
    int i;

    // percorre a matriz e libera suas linhas
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
        matriz[i] = NULL;
    }

    // libera a matriz (vetor de vetores)
    free(matriz);
    matriz = NULL;

    return;
}

// funcao que verifica se a posicao atual x e y pertence a um ponto interno
// da matriz
bool dentroMatriz(int **matriz, int tamMatriz[2], int atual_x, int atual_y) {
    if (atual_x >= 0 && atual_x < tamMatriz[0] && atual_y >= 0 && atual_y < tamMatriz[0] && matriz[atual_x][atual_y] == 0)
        return true;

    return false;
}

// funcao que chama a resolucao e printa o resultado
bool solucao(int **matriz, int tamMatriz[2], coords inicial, coords destino) {
    // declaracao das variaveis
    PILHA *p = NULL;
    ITEM *it;
    int **solucao;
    int i, j;

    // cria a pilha
    p = pilha_criar();

    // aloca dinamicamente a matriz "solucao"
    solucao = mallocSafe(tamMatriz[0] * sizeof(int *));
    for (i = 0; i < tamMatriz[0]; i++) {
        solucao[i] = mallocSafe(tamMatriz[1] * sizeof(int));
    }

    // atribui 1 (paredes) a todas as posicoes da matriz "solucao"
    for (i = 0; i < tamMatriz[0]; i++) {
        for (j = 0; j < tamMatriz[1]; j++) {
            solucao[i][j] = 1;
        }
    }

    // chama a funcao recursiva que de fato resolve o problema
    if (resolver(matriz, tamMatriz, solucao, p, destino, inicial.x, inicial.y) == false) {
        // caso o problema nao possa ser resolvido, imprime isso
        printf("caminho nao existe\n");

        return false;
    }

    printf("\n");

    // cria o item (ponto destino) e empilha na pilha
    it = item_criar(destino.x, destino.y);
    pilha_empilhar(p, it);
    pilha_inverter(p);

    // imprime a solucao
    pilha_print(p);

    return true;
}

// funcao que resolve o problema recursivamente
bool resolver(int **matriz, int tamMatriz[2], int **solucao, PILHA *p, coords destino, int atual_x, int atual_y) {
    // criacao do item
    ITEM *it;

    // verifica se a posicao atual e igual a posicao destino
    if ((atual_x == destino.x) && (atual_y == destino.y) && matriz[atual_x][atual_y] == 0) {
        // atribui 0 na matriz, empilha na pilha e retorna true
        solucao[atual_x][atual_y] = 0;
        it = item_criar(atual_x, atual_y);

        pilha_empilhar(p, it);
        return true;
    }

    // verifica se a posicao atual esta dentro da matriz
    if (dentroMatriz(matriz, tamMatriz, atual_x, atual_y) == true) {
        // verifica se a posicao ja foi percorrida
        if (solucao[atual_x][atual_y] == 0) {
            return false;
        }

        // atribui 0 na posicao atual e empilha na lista
        solucao[atual_x][atual_y] = 0;
        it = item_criar(atual_x, atual_y);

        pilha_empilhar(p, it);

        // verifica se a posicao da esquerda pode resolver o problema
        if (resolver(matriz, tamMatriz, solucao, p, destino, atual_x, atual_y - 1) == true) {
            return true;
        }

        // verifica se a posicao de cima pode resolver o problema
        if (resolver(matriz, tamMatriz, solucao, p, destino, atual_x - 1, atual_y) == true) {
            return true;
        }
        // verifica se a posicao de baixo pode resolver o problema
        if (resolver(matriz, tamMatriz, solucao, p, destino, atual_x + 1, atual_y) == true) {
            return true;
        }
        // verifica se a posicao da direita pode resolver o problema
        if (resolver(matriz, tamMatriz, solucao, p, destino, atual_x, atual_y + 1) == true) {
            return true;
        }

        // atrubui 1 a matriz solucao, novamente
        solucao[atual_x][atual_y] = 1;

        // desempilha
        pilha_desempilhar(p);

        return false;
    }
    return false;
}

// funcao principal do programa
int main(void) {
    // criacao das variaveis
    coords inicial, destino;
    int **matriz;
    int tamMatriz[2];
    int i, j;

    // recebe os valores:
    //      - ponto inicial
    //      - ponto destino
    scanf("%d %d", &inicial.x, &inicial.y);
    scanf("%d %d", &destino.x, &destino.y);

    // recebe o tamanho da matriz
    scanf("%d %d", &tamMatriz[0], &tamMatriz[1]);

    // atribui o tamanho desejado a matriz, pela funcao mallocSafe()
    matriz = mallocSafe(tamMatriz[0] * sizeof(int *));
    for (i = 0; i < tamMatriz[0]; i++) {
        matriz[i] = mallocSafe(tamMatriz[1] * sizeof(int));
    }

    // recebe o labirinto de fato
    for (i = 0; i < tamMatriz[0]; i++) {
        for (j = 0; j < tamMatriz[1]; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // chama a funcao que produz a solucao do problema
    solucao(matriz, tamMatriz, inicial, destino);

    // chama a funcao para liberar o espaco alocado pela matriz
    freeMatrizInt(matriz, tamMatriz[0]);

    return (0);
}