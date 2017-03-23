#include <stdio.h>
#include <string.h>
#include "bib_arqs.h"


void compara_palavras_arquivo(char *nome_arquivo, char *conteudo, char *palavra_chave){

    int i = 0, j = 0, k = 1;
    int contador = 0;
    int aux_j;
    int tamanho_palavra;
    int ocorrencias = 0;
    char var_aux, var_aux_maiuscula, var_aux_minuscula;
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

    tamanho_palavra = strlen(palavra_chave);
    var_aux = palavra_chave[0];
    var_aux_maiuscula = toupper(var_aux);
    var_aux_minuscula = tolower(var_aux);
    for (; j < i; j++) {

       if(j == 0)
             if(conteudo[j] == var_aux_maiuscula || conteudo[j] == var_aux_minuscula){
             aux_j = j+1;
             for (; aux_j < (j + tamanho_palavra); aux_j++) {
                if (palavra_chave[k] == conteudo[aux_j])
                    contador++;
                k++;
             }
             if(conteudo[aux_j] == ' ')
                contador++;
             if(contador == (tamanho_palavra))
                ocorrencias++;

             contador = 0;
             k = 1;
             }

       if(conteudo[j] == var_aux_maiuscula || conteudo[j] == var_aux_minuscula){
           aux_j = j+1;
           for (; aux_j < (j + tamanho_palavra); aux_j++) {
                if (palavra_chave[k] == conteudo[aux_j])
                    contador++;
                k++;
            }
            if(conteudo[aux_j] == ' ' && conteudo[j-1] == ' ')
                contador++;
            if(contador == (tamanho_palavra))
                ocorrencias++;

            contador = 0;
            k = 1;
       }
       if(j == i - tamanho_palavra - 1 )
             if(conteudo[j] == var_aux_maiuscula || conteudo[j] == var_aux_minuscula){
             aux_j = j+1;
             for (; aux_j < (j + tamanho_palavra); aux_j++) {
                if (palavra_chave[k] == conteudo[aux_j])
                    contador++;
                k++;
             }
             if(conteudo[j-1] == ' ')
                contador++;
             if(contador == (tamanho_palavra))
                ocorrencias++;

             contador = 0;
             k = 1;
             }

    }
    printf("'%s' ocorre %d vezes no arquivo '%s'",palavra_chave, ocorrencias, nome_arquivo);
    fclose(beta_leitura);
}
