// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
// definindo o tamanho do vetor
#define tamanhoVetor 10

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

// declaracao da funcao que realiza a busca sequencial no vetor
int buscaSequencial(int *vetor, int variavel) {
    // declaracao da variavel
    int i;

    // procura a variavel em cada casa, sequencialmente, do vetor
    for (i = 0; i < tamanhoVetor; i++) {
        // caso ache a variavel, retorna 1
        if (vetor[i] == variavel) {
            return 1;
        }
    }

    // caso nao ache a variavel, retorna 0
    return 0;
}

// funcao principal
int main(void) {
    // declaracao das variaveis
    int *vetor, i, variavel;

    // atribui o tamanho desejado ao vetor, pela funcao mallocSafe()
    vetor = mallocSafe(tamanhoVetor * sizeof(int));

    // recebe todos os valores do vetor
    for (i = 0; i < tamanhoVetor; i++) {
        scanf("%d", &vetor[i]);
    }

    // recebe a variavel a ser procurada
    scanf("%d", &variavel);

    // caso buscaSequencial retorne 1, imprime que achou a variavel
    // caso contrario, imprime que nao achou
    if (buscaSequencial(vetor, variavel))
        printf("\nEncontrado!\n");
    else
        printf("\nNão Encontrado!\n");

    return (0);
}