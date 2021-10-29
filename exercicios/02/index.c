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

// declaracao da funcao que realiza a busca binaria no vetor
int buscaBinaria(int *vetor, int variavel, int inicio, int fim) {
    // declaracao da variavel
    int posicaoMeio;

    // descobre o meio do vetor
    posicaoMeio = (inicio + fim) / 2;

    // verifica se o inicio e maior que o fim, ou seja, a busca acabou
    if (inicio > fim)
        return 0;

    // verifica se o vetor na posicao "posicaMeio" e igual a variavel que se procura
    if (vetor[posicaoMeio] == variavel)
        return 1;

    // caso a variavel seja maior que o item no meio do vetor, se procura do meio+1 para a frente
    // caso contrario, se procura do inicio ate o meio -1
    if (vetor[posicaoMeio] < variavel) {
        return buscaBinaria(vetor, variavel, ++posicaoMeio, fim);
    } else {
        return buscaBinaria(vetor, variavel, inicio, --posicaoMeio);
    }

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
    if (buscaBinaria(vetor, variavel, 0, tamanhoVetor))
        printf("\nEncontrado!\n");
    else
        printf("\nNão Encontrado!\n");

    return (0);
}