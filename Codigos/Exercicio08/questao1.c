#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int i, numeros[10];

void* print_num(void* numeros)
{
    int j;
    int *var = (int*) numeros;
    printf("Recebido!\n");

    if (var[i] == 10) {
        for (j = 0; j < 10; j++) {
            printf("%d\n", var[j]);
            sleep(1);
        }
    }
}

int main()
{
    pthread_t thread_id1;
    for (i = 0; i < 10; i++) {
        numeros[i] = i+1;
        printf("Enviando --> %d\n", i+1);
        pthread_create (&thread_id1, NULL, &print_num, &numeros);
        sleep(1);
    }
    pthread_join (thread_id1, NULL);

    printf(">> A thread foi finalizada! \n");

	sleep(1); // Espera 1 segundo

	printf(">> Programa finalizado! \n");

	return 0; // Termina a execução

}
