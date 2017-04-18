#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int main()
{
    long int vetor_aleatorio[MAX];
    int aux, MAIOR = 0;
    int i, j;

    srand(time(NULL));

    for (i = 0; i < MAX; i++)
        vetor_aleatorio[i] = rand();

    for (j = 1; j < MAX; j++) {

        if (vetor_aleatorio[j] > vetor_aleatorio[j-1])
            aux = vetor_aleatorio[j];
        else
            aux = vetor_aleatorio[j-1];

        if (aux >= MAIOR)
            MAIOR = aux;
    }

    printf("O maior valor e: %d\n", MAIOR);

	return 0; // Termina a execução

}
