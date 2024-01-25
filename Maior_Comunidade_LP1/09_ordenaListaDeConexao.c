#include "my_header.h"

 void ordenaListaDeConexao(int **lis){

 // ordenando a lista

    int aux_1 = 0;
    int aux_2 = 0;
    int max = 0;

    for (int i = 0 ; i < totalPessoas-1; i ++){  //itera até o penultimo valor da matriz

        max = i;  // tomamos o primeiro numero da coluna  como maior valor

        // compara o valor de i com o resto dos valores da coluna ate o fim da matriz
        for (int k = i+1; k < totalPessoas; k++){

            //compara se o proximo valor da coluna (i+1) é maior que o valor maximo, definido por hora como o primeiro (i).
            if (lis[k][1] > lis[max][1] ) {    //a coluna é a mesma, permanece 1 enquanto o k vai iterando nas linhas
                max = k;
                }
            }
        if (i != max){  // checa se o valor de max foi atualizado, se foi atualizado eh pq existe um numero maior. Entao atualiza o valor de max

        //atualiza valores das linhas e colunas
        aux_1 = lis[i][1];
        aux_2 = lis[i][0];

        lis[i][1] = lis[max][1];
        lis[i][0] = lis[max][0];

        lis[max][1] = aux_1;
        lis[max][0] = aux_2;


        }

    }
}
