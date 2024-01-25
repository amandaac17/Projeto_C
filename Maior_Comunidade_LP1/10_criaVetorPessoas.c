#include "my_header.h"



int * criaVetorPessoas(int **lista){

    int *vetor_ordenado;
    vetor_ordenado = malloc(sizeof(int*)*totalPessoas);
    if(vetor_ordenado == NULL){
    printf("Erro alocando vetor ordenado");
    }


    //printf("vetor ordenado: \n");

    for (int i = 0; i < totalPessoas; i++){

            vetor_ordenado[i] = lista[i][0];
            //printf("%d ", vetor_ordenado[i]);

        }


    return vetor_ordenado;


}

