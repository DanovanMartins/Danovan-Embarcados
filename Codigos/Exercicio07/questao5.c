#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void alarme(int sig)
{
    system("ps");
    alarm(1);
}

int main(int argc, const char *argv[])
{
    signal(SIGALRM, alarme);
    alarm(1);
    printf("Aperte CTRL+C para acabar.\n");
    while(1);
    return 0;
}

