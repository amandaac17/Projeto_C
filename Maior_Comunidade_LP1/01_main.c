#include "my_header.h"

int totalPessoas;
int totalAmizades;

int main()
{

    char nomeDoArquivo[] = {"data2.txt"};
    int *ponteiroTotalPessoas = &totalPessoas;
    int *ponteiroTotalAmizades = &totalAmizades;
    int **matriz;
    int **lista_do_arquivo; //igual ao arquivo txt
    int **lista_qtd_conexao;
    int *vetor_pessoas_ordenado;
    int *maior_comunidade;
    int **lista_qtd_conexao_nao_ordenada;
    int qtd_pessoas_na_maior_comunidade = 0;


    /*************** Tratando Dados do Arquivo e criando lista do arquivo ***************/

    recebeArquivo(nomeDoArquivo, ponteiroTotalPessoas,ponteiroTotalAmizades);

    lista_do_arquivo = retornaLista(nomeDoArquivo);

    //imprimeLista(lista_do_arquivo,0,0);
   //printf("Total pessoas: %d \t Total Amizades: %d\n", totalPessoas,totalAmizades);
    //printf("\n");




    /*************** Criando e Populando a Matriz de Adjacencia ***************/

    matriz = criaMatriz();
    populaMatrizDeAdjacencia(matriz,lista_do_arquivo);
    //imprimeMatriz(matriz);



   /*************** Criando lista ordenada com a quantidade de conexões que cada pessoa tem ***************/

     lista_qtd_conexao = criaListaDeConexao(matriz);

     ordenaListaDeConexao(lista_qtd_conexao);

     lista_qtd_conexao_nao_ordenada = criaListaDeConexao(matriz);





    /*************** Imprimindo Lista Ordenada ***************/

    //printf("\n");
    //printf("Pessoa -> qtd de conexoes na matriz superior\n");
    //printf("\n");
    //imprimeLista(lista_qtd_conexao,0,0);
    //printf("\n");




    /*************** Criando um vetor ordenado apenas com as pessoas ***************/

    vetor_pessoas_ordenado = criaVetorPessoas(lista_qtd_conexao);







    /*************** Encontrando a maior comunidade ***************/

    maior_comunidade = criaVetorMaiorComunidade(matriz,vetor_pessoas_ordenado);







   /*************** Contando quantas pessoas existem na maior comunidade ***************/

    for(int i = 0; i < totalPessoas; i++){

        if(maior_comunidade[i] == 1)   qtd_pessoas_na_maior_comunidade++;

    }





    /*************** Inicializando array de structs ***************/

    MaiorComunidade * array_de_comunidade;

    array_de_comunidade = criaStructComunidade(qtd_pessoas_na_maior_comunidade, maior_comunidade, lista_qtd_conexao_nao_ordenada,matriz);








   /*************** Imprimindo as pessoas da comunidade e quantas conexões possuem ***************/

    printf("A maior comunidade, de um total de %d pessoas é formada por:\n", totalPessoas);
    for(int i = 0; i < qtd_pessoas_na_maior_comunidade; i++){

       printf("\n Pessoa: %d  com  %d  amizades \n ", array_de_comunidade[i].pessoa,array_de_comunidade[i].qtd_conexoes);

    }

    criaArquivoSaida(array_de_comunidade,qtd_pessoas_na_maior_comunidade);










    /*************** Liberando ponteiros ***************/

    //matriz
    for(int i = 0; i < totalPessoas; i++)
    {
       free(matriz[i]);
     }
    free(matriz);


    //lista_do_arquivo
    for(int i = 0; i < totalAmizades; i++)
    {
       free(lista_do_arquivo[i]);
     }
    free(lista_do_arquivo);


    //lista_qtd_conexao
    for(int i = 0; i < totalPessoas; i++)
    {
       free(lista_qtd_conexao[i]);
     }
    free(lista_qtd_conexao);

    //vetor_pessoas_ordenado
    free(vetor_pessoas_ordenado);

    //maior_comunidade
    free(maior_comunidade);

    //array de struct
    free(array_de_comunidade);



    return 0;

}
