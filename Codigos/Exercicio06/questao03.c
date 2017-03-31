#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int k = 1;
    pid_t pid_filho;

    while(k < argc){
        pid_filho = fork();
        if (pid_filho == 0){
            char *lista_de_argumento[10] = {argv[k], NULL};
            execvp(argv[k], lista_de_argumento);
            }else{
                sleep(1);
         }
    k++;
   }
    return 0;
}
