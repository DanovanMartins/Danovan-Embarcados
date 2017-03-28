#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char *argv[])
{
    char mensagem[100];
    le_arq_texto("danovan.txt", mensagem);
    return 0;
}
