#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <semaphore.h>

#define SEM_CONSUMER_FNAME "/myconsumer"
#define SEM_PRODUCER_FNAME "/myproducer"
void myproducer()
{

}

void myconsumer()
{

}

int main(int argc, char*argv[])
{
    sem_unlink(SEM_CONSUMER_FNAME);
    sem_unlink(SEM_PRODUCER_FNAME);

    sem_t *sem_prod = sem_open(SEM_PRODUCER_FNAME, IPC_CREAT, 0660, 0);
    if(sem_prod == SEM_FAILED){
        perror("sem_open/myproducer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONSUMER_FNAME, IPC_CREAT, 0660, 0);
    if(sem_cons == SEM_FAILED){
        perror("sem_open/myconsumer");
        exit(EXIT_FAILURE);
    }


    sem_close(sem_cons);
    sem_close(sem_prod);
    printf("\nDone.\n");
    return 0;
}