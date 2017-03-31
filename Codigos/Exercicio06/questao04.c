#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int v_global =0;

void Incrementa_Variavel_Global(pid_t id_atual){
    v_global++;
    printf("ID do processo que executou esta funcao = %d\n", id_atual);
    printf("v_global = %d\n", v_global);
}

int main(int argc, char * argv[])
{
    pid_t pid_filho[2];

        pid_filho[0] = fork();
        if (pid_filho[0] == 0){
            Incrementa_Variavel_Global(pid_filho[0]);
        }else{
            return(0);
        }
        pid_filho[1] = fork();
        if (pid_filho[1] == 0){
            Incrementa_Variavel_Global(pid_filho[1]);
        }else{
            return(0);
        }
        pid_filho[2] = fork();
        if (pid_filho[2] == 0){
            Incrementa_Variavel_Global(pid_filho[2]);
        }else{
            return(0);
        }
    return 0;
}
