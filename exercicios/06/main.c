#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./TAD_lista_duplamente_encadeada/TAD_item/item.h"
#include "./TAD_lista_duplamente_encadeada/lista.h"

// funcao principal do programa
int main(void) {
    // criacao das variaveis
    int i;
    char *titulo = (char *)malloc(sizeof(char) * 40);
    char *url = (char *)malloc(sizeof(char) * 512);

    fgets(titulo, 40, stdin);
    fgets(url, 512, stdin);

    printf("titulo: %s", titulo);
    printf("url: %s", url);

    return (0);
}