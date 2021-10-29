#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void preenche(int **matriz, int coords[2]) {
    int prox_coords[2];

    matriz[coords[0]][coords[1]] = 1;

    // cima
    if (matriz[coords[0] - 1][coords[1]] == 0) {
        prox_coords[0] = coords[0] - 1;
        prox_coords[1] = coords[1];

        preenche(matriz, prox_coords);
    }
    // baixo
    if (matriz[coords[0] + 1][coords[1]] == 0) {
        prox_coords[0] = coords[0] + 1;
        prox_coords[1] = coords[1];

        preenche(matriz, prox_coords);
    }

    // esquerda
    if (matriz[coords[0]][coords[1] - 1] == 0) {
        prox_coords[0] = coords[0];
        prox_coords[1] = coords[1] - 1;

        preenche(matriz, prox_coords);
    }

    // direita
    if (matriz[coords[0]][coords[1] + 1] == 0) {
        prox_coords[0] = coords[0];
        prox_coords[1] = coords[1] + 1;

        preenche(matriz, prox_coords);
    }
}

int main() {
    // declaracao das variaveis
    int **matriz;
    int n, m, i, j;
    int coords[2];

    // recebe o tamanho da matriz
    scanf("%d %d", &n, &m);

    // atribui o tamanho desejado a matriz, pela funcao mallocSafe()
    matriz = mallocSafe(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = mallocSafe(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    scanf("%d %d", &coords[0], &coords[1]);

    preenche(matriz, coords);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return (0);
}