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
    char mensagem[30];

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
			for(i = 1; i <= 10; i++){
				printf("Pai escreve: %d\n", mensagem[i] );
                sleep(1);
			}
		}
            write(fd[1], mensagem, sizeof(mensagem));
            sleep (1);
    }

    if (pid == 0){
        sleep(11);
        if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else{
			//printf("%d\n", mensagem);
			for(j = 1; j <= 10; j++)
				printf("Filho leu: %d\n", mensagem[j]);
		}
    }

    return 0;
}
