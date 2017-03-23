#include <stdio.h>

int main(int argc, char *argv[])
{
    char arquivo[30];
    FILE *beta;

    sprintf(arquivo,"%s.txt", argv[1]);
    beta = fopen(arquivo,"w");
    if(!beta){
        printf("Erro ao criar o arquivo");
        return 1;
    }
    fprintf(beta, "Nome: %s Anos\n", argv[1]);
    fprintf(beta, "Idade: %s Anos\n", argv[2]);
    fclose(beta);
    return 0;
}
