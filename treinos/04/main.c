#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

char *le_string() {
    char *string = (char *)malloc(sizeof(char) * 100);
    char *letras = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;

    fgets(string, 100, stdin);

    while (string[i] != '\n') {
        if (isalpha(string[i])) {
            if (string[i] >= 'a' && string[i] <= 'z')
                letras[j] = string[i];
            if (string[i] >= 'A' && string[i] <= 'Z')
                letras[j] = tolower(string[i]);
            j++;
        }
        i++;
        if (string[i] == '\n') {
            letras[j] = '\0';
            break;
        }
    }

    return letras;
}

int main() {
    /*string é um vetor de caracteres que armazena a frase a ser analisada*/
    char *string = le_string();
    int i = 0;
    ITEM *item;
    PILHA *pilha;

    pilha = pilha_criar();

    while (string[i] != '\0') {
        item = item_criar(string[i]);
        pilha_empilhar(pilha, item);

        i++;
    }

    i = 0;

    while (string[i] != '\0') {
        item = pilha_desempilhar(pilha);

        if (item_get_chave(item) != string[i]) {
            printf("Não é palíndromo.\n");
            exit(EXIT_SUCCESS);
        }

        i++;
    }

    printf("É palíndromo.\n");

    free(string);

    return EXIT_SUCCESS;
}