#include "my_header.h"


void imprimeLista(int **lis, int linha_atual,int coluna_atual) {



    // condição de parada: atingindo a ultima linha e ultima coluna
    if (linha_atual == totalPessoas - 1 && coluna_atual == COLUNAS - 1) {
        printf("%d\n", lis[linha_atual][coluna_atual]);
        return;
    }
    // imprimindo o elemento atual lista[0][0],
    printf("%d ", lis[linha_atual][coluna_atual]);


    // atingindo a coluna (2-1) = 1, ou seja, a segunda e ultima coluna, vai para a próxima linha
    if (coluna_atual == COLUNAS - 1) {
        printf("\n");
        imprimeLista(lis, linha_atual + 1, 0);
    } else {
        // do contrario, imprime a coluna , que pelo exemplo acima, seria [0][1]
        imprimeLista(lis, linha_atual, coluna_atual + 1);
    }



}

