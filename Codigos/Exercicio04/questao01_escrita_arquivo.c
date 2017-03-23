#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *beta;

    beta = fopen ("ola.txt","w");
    if (beta == NULL){
    printf("Houve um erro ao criar o arquivo!");
    return 1;
    }
    fprintf(beta,"Ola mundo");
    fclose(beta);
    return 0;
}
