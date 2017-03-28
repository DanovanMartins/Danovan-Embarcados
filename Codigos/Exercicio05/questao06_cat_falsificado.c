#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char *argv[])
{
    char conteudo[100];
    le_arq_texto(argv[1], conteudo); 
    return 0;
}
