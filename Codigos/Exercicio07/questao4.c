#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int pid,
        fd[2],
        estado;
    char nome[50];
    int nome_inserido = 0;
    char mensagem[200];

    if (pipe(fd) < 0) {
        printf("erro na criação do pipe \n");
        exit(1);
    }
    if ((pid = fork()) < 0) {
        printf("erro na criação do fork \n");
        exit(1);
    }
    if (pid != 0) {
        printf("Insira o nome: ");
        gets(nome);
        nome_inserido = 1;
        strcpy(mensagem, nome);
        if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
            fprintf(stderr, "Error na escrita!");
        sleep(1);
    }
    if (pid == 0){
        while(!nome_inserido);
            sleep(1);
            if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na leitura!");
            printf("%s \n",mensagem);
    }
    return 0;
}
