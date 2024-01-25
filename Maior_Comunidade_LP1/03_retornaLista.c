#include "my_header.h"

int **retornaLista(char nome[]) {

    char linhaIgnorada[20];
    int linha = 0;
    char linhaTexto[20];

    // Alocando a lista
    int **lista;
    lista = malloc(sizeof(int*)*totalAmizades);  // alocando linhas
    if (lista == NULL){
    		printf("Erro ao criar a lista");

    }

    for (int i = 0; i < totalAmizades; i++) {
        lista[i] = malloc(sizeof(int)*COLUNAS); // alocando colunas


        }

    // Abrindo arquivo
    FILE *arquivo;
    arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        }


    // Ignora a linha 0 do arquivo
    fgets(linhaIgnorada, sizeof(linhaIgnorada), arquivo);


    // Populando a lista com os dados do arquivo
    while (linha < totalAmizades && fgets(linhaTexto, sizeof(linhaTexto), arquivo) != NULL) {
                sscanf(linhaTexto, "%*c %d %d", &lista[linha][0], &lista[linha][1]);
                    linha++;


                }

    fclose(arquivo);
    return lista;


}
