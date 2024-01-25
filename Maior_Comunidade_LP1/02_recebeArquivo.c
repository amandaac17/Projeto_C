#include "my_header.h"

void recebeArquivo(char nome[], int *pP, int *pA)
{
    FILE *pfile;
    pfile = fopen(nome, "r");

    if (pfile == NULL)
    {
                printf("Nao foi possivel abrir o arquivo\n");
                return;
    }

    fscanf(pfile,"%*s %*s %d %d", &*pP,&*pA);

    fclose(pfile);
}

