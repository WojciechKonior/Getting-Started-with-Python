#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#define BIG 10000000UL
_Atomic uint64_t counter = 0;
// pthread_mutex_t mtx;

//some definitions of bit fields
#define BIT1 0x01
#define BIT2 0x02
#define BIT3 0x04
#define BIT4 0x08

typedef struct __attribute__((packed)) counters {
    unsigned little : 2;
    unsigned medium : 4;
    unsigned large : 6;
} counters;

void count_to_big()
{
    for(int i = 0; i<BIG; i++)
    {
        // pthread_mutex_lock(&mtx);
        counter += i;
        // pthread_mutex_unlock(&mtx);
    }
}

void *threadfunc(void *arg){
    count_to_big();
    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, threadfunc, NULL);
    pthread_create(&t2, NULL, threadfunc, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("The result is %lu\n", counter);
    int result = BIT1 | BIT2;
    result = BIT1 & BIT2;
    printf("bit 1 | bit 2 = %d\n", result);

    int bit = 0x01;
    for(int i = 0; i<10; i++)
        printf("%d ", bit^=BIT1);
    printf("\n");
    

    counters counts = {
        .little = 0,
        .medium = 0,
        .large = 0
    };

    printf("size = %ld", sizeof(counters));

    printf("\nDone\n");
    return 0;
}