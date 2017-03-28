#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int beta;

    char nome[30];
    char arquivo[30];
    char mensagem[30];
    int idade;

    printf("insira o seu nome: ");
    scanf("%s", &nome);
    printf("Insira a sua idade: ");
    scanf("%d", &idade);

    sprintf(arquivo,"%s.txt", nome);
    sprintf(mensagem, "Idade: %d Anos\0", idade);

    beta = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);

    if(beta == -1){
        printf("Erro ao criar o arquivo");
        exit(1);
    }
    write(beta, &mensagem, strlen(mensagem));
    close(beta);

    return 0;
}
