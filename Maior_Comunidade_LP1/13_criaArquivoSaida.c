#include "my_header.h"



void criaArquivoSaida(MaiorComunidade *array, int qtd_pessoas)
{
    FILE* pfile;
    pfile = fopen("arquivo_de_saida.txt", "w+");

    if(pfile == NULL){
        printf("erro ao criar arquivo de saida");
    }


    for (int i = 0; i < qtd_pessoas; i++) {

        fprintf(pfile,"Pessoa %d com %d amizades \n", array[i].pessoa,array[i].qtd_conexoes);
        //fwrite(&array[i], sizeof(MaiorComunidade), 1, parq);

    }

    fclose(pfile);
}
