// importar as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// funcao que calcula o fatorial por recursividade
int calcularFatorial(int D) {
    // verifica se D e menor que 0. Senao, calcula o fatorial
    if (D < 0) {
        // retorna -1
        return -1;
    } else if (D == 0) {
        // retorna 1 quando D vale 0
        return 1;
    } else {
        // retorna a multiplicacao de D por D-1, sucessivamente, ate chegar em 0, onde entra no if acima
        return D * calcularFatorial(D - 1);
    }
}

// funcao main
int main(void) {
    // declarar as variaveis
    int D, V;

    // receber o valor para calcular fatorial
    scanf("%d", &D);

    // V receber o valor retornado pela funcao calcularFatorial()
    V = calcularFatorial(D);

    // verificar o valor de V e imprime o resultado esperado
    if (V == -1) {
        printf("erro\n");
    } else {
        printf("%d\n", V);
    }

    // retornar valor 0;
    return 0;
}