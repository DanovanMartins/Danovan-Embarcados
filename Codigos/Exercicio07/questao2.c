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
    char mensagem[80];

    if (pipe(fd) < 0) {
        printf("erro na criação do pipe \n");
        exit(1);
    }
    if ((pid = fork()) < 0) {
        printf("erro na criação do fork \n");
        exit(1);
    }
    if (pid != 0) {
        for (i = 1; i < 11; i++) {
            mensagem[i] = i;
        }
        if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Error na escrita\n");
        else{
            sleep(1);
            sprintf(mensagem, "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
            write(fd[1], mensagem, sizeof(mensagem));
        }
    }
    if (pid == 0){
        sleep(11);
        if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else{
            printf("%s \n", mensagem);
            sprintf(mensagem,"Pai, qual é a verdadeira essência da sabedoria?");
		}
    }

    return 0;
}
