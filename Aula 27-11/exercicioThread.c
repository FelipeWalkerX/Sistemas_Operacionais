#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NUM_THREADS 5

int saldo = 1000;
pthread_mutex_t mutex;

void *AtualizaSaldo(void *n) {
    int num = (intptr_t)n; 
    
    int meu_saldo = saldo;
    int novo_saldo = meu_saldo + (num * 100); 

    printf("Sou a Thread %d. Novo saldo: %d\n", num, novo_saldo);
    
    int *saldoptr = malloc(sizeof(int));
    *saldoptr = novo_saldo;
    
    pthread_exit(saldoptr);    
    
}

int main() {
    void *status;
    int resultado = 0;    
    int num_thread = 1;
   
    pthread_t threads[NUM_THREADS];
    //Criar as threads 
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads, NULL, AtualizaSaldo(num_thread), NULL);      //pthead_create(&threads, NULL, funcao)
        num_thread++;   
            }
    
    
    //Coletar os resultados para somar o saldo final 
    printf("Saldo Final: %d\n", resultado);     //O printf tambem é compartilhado, entao é bom proteger ele tambem
    return 0;
}

//Primeira coisa, verificar aonde é a regiao critica
