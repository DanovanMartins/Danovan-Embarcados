#include <stdio.h>
#include <string.h>
#include "bib_arqs.h"


int tam_arq_texto(char *nome_arquivo){

    int i = 0;
    char c;

    FILE *beta_leitura;
    beta_leitura = fopen(nome_arquivo,"r");

    if(!beta_leitura){
        printf("Erro ao realizar leitura");
        return 1;
    }

    while((c = getc(beta_leitura)) != EOF)
         i++;
    fclose(beta_leitura);
    return i;
}

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
    printf("O arquivo possui o segunte texto: \n%s\n", conteudo);
}
