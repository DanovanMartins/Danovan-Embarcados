#include <stdio.h>
#include <stdlib.h>

    char nome[30];

int main(int argc, const char *argv[])
{
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Olá %s \n", nome);
    return 0;
}
