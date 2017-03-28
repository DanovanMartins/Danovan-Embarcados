#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"


void le_arq_texto(char *nome_arquivo, char *conteudo){

    int i = 0;
    char c;

    int beta_leitura;
    beta_leitura = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);

    if(beta_leitura == -1){
        printf("Erro ao realizar leitura, Dolynho nao encontra Falsiane");
    }

    while(read(beta_leitura, &c, 1) != 0){
        conteudo[i] = c;
        i++;
    }

    close(beta_leitura);
    printf("%s\n", conteudo);
}
