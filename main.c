// main.c
#include <stdio.h>
#include "funcoes.h"

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int n;

    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);

    // Verifica se o número de pessoas é válido
    while (n <= 0) {
        printf("Numero invalido. Digite um numero positivo: ");
        scanf("%d", &n);
    }

    // Ler os dados das pessoas
    lerDados(pessoas, &n);

    // Imprimir o relatorio com os dados
    imprimirRelatorio(pessoas, n);

    return 0;
}
