#include "my_header.h"


int** criaListaDeConexao(int **mat) {

    int **qtd_conex;
    qtd_conex = malloc(sizeof(int*)*totalPessoas); //alocando linha
    if(qtd_conex == NULL){
    		printf("Erro ao criar lista de conexão");
    }

    for (int i = 0; i < totalPessoas; i++) {
        qtd_conex[i] = malloc(sizeof(int)*COLUNAS); // alocando coluna
        if (qtd_conex[i]==NULL){
        	printf("Erro ao alocar colunas da lista de conexão");
        }
    }

    int conexao = 0;

    for (int i = 0; i < totalPessoas ; i ++){
        for (int j = 0; j < totalPessoas; j ++) {
            if (j > i) {  //para acessar apenas a matriz superior
                if (mat[i][j] == 1 ) {
                    conexao++;

                }

            }
        }
        qtd_conex[i][0] = i+1;
        qtd_conex[i][1] = conexao;

        conexao = 0;
    }



     return qtd_conex;

}

