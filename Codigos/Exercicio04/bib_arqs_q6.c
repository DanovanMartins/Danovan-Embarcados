#include <stdio.h>
#include <string.h>
#include "bib_arqs.h"


void le_arq_texto(char *nome_arquivo, char *conteudo){

    int i = 0;
    char c;

    FILE *beta_leitura;
    beta_leitura = fopen(nome_arquivo,"r");

    if(!beta_leitura){
        printf("Erro ao realizar leitura");
    }

    while((c = getc(beta_leitura)) != EOF){
        conteudo[i] = c;
        i++;
    }

    fclose(beta_leitura);
    printf("%s\n", conteudo);
}
