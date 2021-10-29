#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int menor(int *vetor, int tamanho, int posicao, int valorAtual);
int maior(int *vetor, int tamanho, int posicao, int valorAtual);
float media(int *vetor, int tamanho, int posicao, int valorAtual);
void *mallocSafe(int nBytes);

int menor(int *vetor, int tamanho, int posicao, int valorAtual) {
    if (posicao == tamanho) {
        return valorAtual;
    } else {
        if (posicao == 0) {
            valorAtual = vetor[posicao];
        } else if (vetor[posicao] < valorAtual) {
            valorAtual = vetor[posicao];
        }

        return menor(vetor, tamanho, ++posicao, valorAtual);
    }
}

int maior(int *vetor, int tamanho, int posicao, int valorAtual) {
    if (posicao == tamanho) {
        return valorAtual;
    } else {
        if (posicao == 0) {
            valorAtual = vetor[posicao];
        } else if (vetor[posicao] > valorAtual) {
            valorAtual = vetor[posicao];
        }

        return maior(vetor, tamanho, ++posicao, valorAtual);
    }
}

float media(int *vetor, int tamanho, int posicao, int valorAtual) {
    float soma = 0.0;

    if (posicao == tamanho) {
        soma = valorAtual;
        return soma / tamanho;
    } else {
        valorAtual += vetor[posicao];

        return media(vetor, tamanho, ++posicao, valorAtual);
    }
}

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

int main(void) {
    int n, *vetor, i;

    scanf("%d", &n);

    // alococa dinamicamente o vetor de postos
    vetor = mallocSafe(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("%d ", menor(vetor, n, 0, 0));
    printf("%d ", maior(vetor, n, 0, 0));
    printf("%.2f\n", media(vetor, n, 0, 0));

    return (0);
}