#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    printf("Este processo é o Pai. pid = %d \n", (int) getpid());
    system("\n");
    system("ps");
    system("\n");

    pid_t child_pid01;

    child_pid01 = fork();
    if (child_pid01 != 0) {
        printf("Este processo é o Pai. pid = %d \n", (int) getpid());
        printf("O filho 01 possui a seguinte pid: %d \n", child_pid01);

        child_pid01 = fork();
        if (child_pid01 != 0) {
            printf("Este processo é o Pai. pid = %d \n", (int) getpid());
            printf("O filho 02 possui a seguinte pid: %d \n", child_pid01);
 
            child_pid01 = fork();
            if (child_pid01 != 0) {
                printf("Este processo é o Pai. pid = %d \n", (int) getpid());
                printf("O filho 03 possui a seguinte pid: %d \n", child_pid01);
            }
        }
    }
    return 0;
}
