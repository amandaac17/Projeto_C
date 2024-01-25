#include "my_header.h"


int **criaMatriz()
{
     int **matriz;
    matriz = calloc(totalPessoas,sizeof(int*));
    if(matriz==NULL){
        printf("Erro ao criar matriz");

    }

    for (int linha = 0; linha < totalPessoas; linha++) {
        matriz[linha] = calloc(totalPessoas,sizeof(int));
        	if(matriz[linha] == NULL) {
        		printf("Erro ao alocar colunas da matriz");
        	}
    }

    return matriz;
}

