#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int main()
{
    long double vetor_aleatorio[MAX];
    double soma = 0, variancia = 0;
    double media;
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX; i++)
        vetor_aleatorio[i] = (double)rand()/1000;

    for (i = 0; i < MAX; i++)
        soma += vetor_aleatorio[i];

    media = soma/(double)MAX;


    for (i = 0; i < MAX; i++)
        variancia += (vetor_aleatorio[i] - media) * (vetor_aleatorio[i] - media);

    variancia /= (double)MAX;
    printf("O maior valor e: %.2f\n", variancia);

	return 0; // Termina a execução

}
