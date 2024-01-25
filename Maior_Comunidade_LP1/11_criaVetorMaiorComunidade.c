#include "my_header.h"


int  *criaVetorMaiorComunidade(int **mat, int *pessoas_ordenadas_conexao){

    int candidato = 0;
    int k = 0; //armazena indice da pessoa atual
    int *comunidade; //vetor para representar a comunidade
    bool pode_adicionar = true; //variavel bool pode ter valores true ou false
    comunidade = calloc(totalPessoas,sizeof(int*));  //armazenando espaço suficiente para a comunidade - pq CALLOC?

    if(comunidade==NULL){
        printf("erro ao criar comunidade");
    }


    candidato = pessoas_ordenadas_conexao[k] -1;
    //inicializando comunidade com a pessoa de maior conexao

    comunidade[candidato] = 1;


    while (k < totalPessoas){

        candidato = pessoas_ordenadas_conexao[k]-1;
        pode_adicionar = true;


        for (int i = 0; i < totalPessoas; i ++){ //checar se k se conecta com todos da comunidade formada ate o momento

            if (candidato == i) continue;  // se for a mesma pessoa, continua para o próximo i (próxima pessoa a ser comparada com k)

            if (comunidade[i] == 0) continue; // se nao há conexão, continua para o próximo i

            if (mat[i][candidato] == 0) { // k nao se conecta com pessoa i da comunidade, então não adiciona e passa para o próximo valor de k (próximo candidato)
                 pode_adicionar = false;
                    break;
                }
            }

        if (pode_adicionar == true){ // altera o vetor comunidade apenas se houver conexao
            comunidade[candidato] = 1;
            }
                 k++;
    }

    printf("\n");

    return comunidade;
}

