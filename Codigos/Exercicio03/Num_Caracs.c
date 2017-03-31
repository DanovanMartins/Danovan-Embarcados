#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int Num_Caracs(char *nome){

int contador = 1;
int i = 0;
int tamanho_da_string;

while(contador){
    if(nome[i] == '\0'){
    contador = !contador;
    tamanho_da_string = i;
    }
    i++;
}
return tamanho_da_string;
}

