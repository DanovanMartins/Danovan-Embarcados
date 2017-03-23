#include <stdio.h>
#include <string.h>
#include "bib_arqs.h"


void le_arq_texto(char *nome_arquivo, char *conteudo){

    int i = 0;
    int j;
    int ocorrencias = 0;
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
    for (j = 0; j < i; j++) {

       if(conteudo[j] == 'O' || conteudo[j] == 'o')
            if(((conteudo[j] == 'O' && conteudo[j+1] == 'l' && conteudo[j+2] == 'a' ) || (conteudo[j] == 'o' && conteudo[j+1] == 'l' && conteudo[j+2] == 'a')) && (conteudo[j+3] == ' ' || conteudo[j+3] == EOF) && conteudo[j-1] == ' ')
                ocorrencias += 1;


       if(j == 0)
            if(conteudo[j] == 'O' || conteudo[j] == 'o')
                 if(((conteudo[j] == 'O' && conteudo[j+1] == 'l' && conteudo[j+2] == 'a' ) || (conteudo[j] == 'o' && conteudo[j+1] == 'l' && conteudo[j+2] == 'a')) && conteudo[j+3] == ' ')
                    ocorrencias += 1;


       if(j == i-4){
            if(conteudo[j] == 'O' || conteudo[j] == 'o')
                 if(((conteudo[j] == 'O' && conteudo[j+1] == 'l' && conteudo[j+2] == 'a' ) || (conteudo[j] == 'o' && conteudo[j+1] == 'l' && conteudo[j+2] == 'a' )) && conteudo[j-1] == ' ')
                    ocorrencias += 1;
       }

    }
    fclose(beta_leitura);
    printf("'Ola' ocorre %d vezes no arquivo '%s'\n", ocorrencias, nome_arquivo);
}
