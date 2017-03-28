#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fp;
    char mensagem[100] = "Ola mundo";

    fp = open("ola_mundo.txt",O_WRONLY | O_CREAT, S_IRWXU);
    if (fp == -1){
        printf("Erro na criacao do arquivo");
        exit(1);
    }
    write(fp, &mensagem, sizeof(mensagem));
    close(fp);
    return 0;
}
