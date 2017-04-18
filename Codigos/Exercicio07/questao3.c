#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int pid[1],
        fd[2],
        estado;
    int i, j;
    char mensagem[200];

    if (pipe(fd) < 0) {
        printf("erro na criação do pipe \n");
        exit(1);
    }

    pid[0] = fork();
    if (pid[0] != 0) {
       sprintf(mensagem, "FILHO1: Quando o vento passa, é a bandeira que se move.\n");
       if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
           fprintf(stderr, "Error na escrita!");

        pid[1] = fork();

        if (pid[1] != 0) {
            sleep(1);
            if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na leitura!");
            printf("%s", mensagem);
            sprintf(mensagem, "FILHO2: Não, é o vento que se move.\n");
            if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na escrita!");
            }else{
                return(0);
            }
        sleep(2);
    }
    if (pid[0] == 0){
        sleep(2);
            if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
	            printf("Erro na leitura do pipe\n");
            printf("%s", mensagem);
            sprintf(mensagem, "PAI: Os dois se enganam. É a mente dos senhores que se move.\n");
            if( write(fd[1], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na escrita!");
            else{
                sleep(1);
                if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na leitura!");
                printf("%s",mensagem);
	        }
        return(0);
    }
}
