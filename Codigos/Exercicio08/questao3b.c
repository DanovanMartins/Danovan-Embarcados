#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000
#define MAX_DIV 50000/4

//variavel para pegar o maior numero de cada thread
int SOMA[4] = {0,0,0,0};

//funcao que vai calcular o maior numero em cada thread
void selecao_do_maior (int n, long int *vetor_aleatorio)
{
    int i;

    for (i = (((n-1)*MAX_DIV) + 1); i < (n*MAX_DIV); i++)
        SOMA[n-1] += vetor_aleatorio[i];
}
//primeira thread
void* calcula_maior_parte1(void* vetor_aleatorio)
{
    //convertando valor do void para long int e armazenando vetor na variavel var
    long int *var = (long int*) vetor_aleatorio;
    //chamando funcao dentro da thread
    selecao_do_maior(1, var);
}
//segunda thread
void* calcula_maior_parte2(void* vetor_aleatorio)
{
    long int *var = (long int*) vetor_aleatorio;

    selecao_do_maior(2, var);
}
//terceira thread
void* calcula_maior_parte3(void* vetor_aleatorio)
{
    long int *var = (long int*) vetor_aleatorio;

    selecao_do_maior(3, var);
}
//quarta thread
void* calcula_maior_parte4(void* vetor_aleatorio)
{
    long int *var = (long int*) vetor_aleatorio;

    selecao_do_maior(4, var);
}

//funcao principal
int main()
{
    //definindo vetor
    long int vetor_aleatorio[MAX];
    int SOMA_DE_TODOS = 0;
    int i;
    double media;

    //funcao para que a rand nao fique presa ao valor do relogio
    srand(time(NULL));

    for (i = 0; i < MAX; i++)
        vetor_aleatorio[i] = rand();

    //declarando thread
    pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_t thread_id3;
    pthread_t thread_id4;

    //executando thread
    pthread_create (&thread_id1, NULL, &calcula_maior_parte1, &vetor_aleatorio);
    pthread_create (&thread_id2, NULL, &calcula_maior_parte2, &vetor_aleatorio);
    pthread_create (&thread_id3, NULL, &calcula_maior_parte3, &vetor_aleatorio);
    pthread_create (&thread_id4, NULL, &calcula_maior_parte4, &vetor_aleatorio);

    //esperando ate que todas as threads sejam finalizadas
    pthread_join (thread_id1, NULL);
    pthread_join (thread_id2, NULL);
    pthread_join (thread_id3, NULL);
    pthread_join (thread_id4, NULL);

    printf(">> A thread foi finalizada! \n");

    //verificando qual é o maior entre as 4 threads
    for (i = 0; i < 4; i++)
        SOMA_DE_TODOS += SOMA[i];

    media = SOMA_DE_TODOS / MAX;

	sleep(1); // Espera 1 segundo

	printf("A media e: %.2f \n", media);

    printf("programa finalizado! \n");
	return 0; // Termina a execução

}
