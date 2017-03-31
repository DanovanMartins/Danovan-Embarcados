#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"


int main(int argc, char *argv[])
{
    int i = 0;
    int  total = 0;
    while (i < argc){
    total += Num_Caracs(argv[i]);
    i++;
    }
    printf("Total de caracteres de entrada: %d", total);
    return 0;
}
