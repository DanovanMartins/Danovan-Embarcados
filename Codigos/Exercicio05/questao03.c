#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{

    int beta;
    char arquivo[30];
    char nome[30];
    char idade[30];

    sprintf(arquivo, "%s.txt", argv[1]);
    beta = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);
    if (beta == -1) {
        printf("Dolynho triste, arqivo nao foi aberto");
        exit(1);
    }
    sprintf(nome, "Nome: %s \n", argv[1]);
    sprintf(idade, "Idade: %s anos\n", argv[2]);

    write(beta, &nome, strlen(nome));
    write(beta, &idade, strlen(idade));
    close(beta);

    return 0;
}
