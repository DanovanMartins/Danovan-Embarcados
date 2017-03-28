#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"


int tam_arq_texto(char *nome_arquivo){

    int i = 0;
    char c;

    int beta_leitura;
    beta_leitura = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);

    if(beta_leitura == -1){
        printf("Dolynho modo Bolado, Erro ao abrir arquivo");
        exit(1);
    }

    while(read(beta_leitura, &c, 1) != 0)
         i++;
    close(beta_leitura);
    return i;
}

void le_arq_texto(char *nome_arquivo, char *conteudo){

    int i = 0;
    char c;

    int beta_leitura;
    beta_leitura = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);

    if(beta_leitura == -1){
        printf("Erro ao realizar leitura, Dolynho encontra-se chateado");
    }

    while(read(beta_leitura, &c, 1) != 0){
        conteudo[i] = c;
        i++;
    }

    close(beta_leitura);
    printf("O arquivo possui o segunte texto: \n%s\n", conteudo);
}
