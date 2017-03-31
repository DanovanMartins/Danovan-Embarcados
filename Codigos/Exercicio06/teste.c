#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int k = 1;
    pid_t pid_filho;

            char *lista_de_argumento[10] = {argv[1], NULL};
            execvp(argv[1], lista_de_argumento);
            printf("testando exec sem fork");
    return 0;
}
