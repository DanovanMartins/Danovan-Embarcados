#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char *argv[])
{
    char conteudo[100];
    compara_palavras_arquivo(argv[2], conteudo, argv[1]); 
    return 0;
}
