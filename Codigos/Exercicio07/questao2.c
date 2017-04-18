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
    int i, j;
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
        if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
            fprintf(stderr, "Error na leitura!");
        else{
            printf("%s", mensagem);
            sprintf(mensagem, "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.\n");
            if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na escrita!");
        }
        sleep(2);
        if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
            fprintf(stderr, "Error na leitura!");
        else{
            printf("%s", mensagem);
            sprintf(mensagem, "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...\n");
            if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na escrita!");
        }
        sleep(1);
    }
    if (pid == 0){
        sprintf(mensagem,"Pai, qual é a verdadeira essência da sabedoria?\n");
        if(write(fd[1], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na escrita do pipe\n");
		else{
            sleep(1);
            if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na leitura!");
            printf("%s",mensagem);
        }
            sprintf(mensagem, "Mas até uma criança de três anos sabe disso!\n");
            if( write(fd[1], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na escrita!");
            else{
            sleep(1);
            if(read(fd[0], mensagem, sizeof(mensagem)) < 0)
                fprintf(stderr, "Error na leitura!");
            printf("%s",mensagem);
		}
    }
    return 0;
}
