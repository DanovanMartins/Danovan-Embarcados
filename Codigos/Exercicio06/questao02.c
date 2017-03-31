#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int i;
    char comando[10];

    for (i =1; i < argc; i++){
        strcpy(comando, argv[i]);

        if (!strcmp(comando, "ls") )
            system("ls");
        if (!strcmp(comando, "pwd") )
            system("pwd");
        if (!strcmp(comando, "echo") )
            system("echo");
        if (!strcmp(comando, "cal") )
            system("cal");
    }
    return 0;
}
