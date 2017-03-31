#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"


int main(int argc, char *argv[])
{
    int i = 0;
    while (i < argc){
    printf("%s / Numero de caracteres: %d \n",argv[i], Num_Caracs(argv[i]));
    i++;
    }
    return 0;
}
