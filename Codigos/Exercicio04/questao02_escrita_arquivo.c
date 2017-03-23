#include <stdio.h>

int main(int argc, const char *argv[])
{
    char nome[30];
    char arquivo[30];
    int idade;

    FILE *beta;

    printf("insira o seu nome: ");
    scanf("%s", &nome);
    printf("Insira a sua idade: ");
    scanf("%d", &idade);

    sprintf(arquivo,"%s.txt", nome);
    beta = fopen(arquivo,"w");
    if(!beta){
        printf("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(beta, "Idade: %d Anos", idade);
    fclose(beta);
    return 0;
}
