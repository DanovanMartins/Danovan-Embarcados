#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int main()
{
    long int vetor_aleatorio[MAX];
    int soma = 0;
    double media;
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX; i++)
        vetor_aleatorio[i] = rand();

    for (i = 0; i < MAX; i++)
        soma += vetor_aleatorio[i];

    media = soma/MAX;

    printf("O maior valor e: %.2f\n", media);

	return 0; // Termina a execução

}
