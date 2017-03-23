#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char nome[100];
    int i;
    fp = fopen("arquivo.txt","w");
    if (!fp) {
        printf ("Erro na abertura do arquivo ");
        exit(0);
    }
    printf("Entre com a string a ser gravada no arquivo: \n");
    gets(nome);
    for(i=0; nome[i]; i++) putc(nome[i], fp);

    fclose(fp);
    return 0;
}
