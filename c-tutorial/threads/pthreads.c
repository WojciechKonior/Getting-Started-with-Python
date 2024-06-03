#include <stdio.h>
#include <pthread.h>

void *function(void* val){
    printf("%ld thread\n", *((long*)val));
    return NULL;
}

int main(int argc, char*argv[])
{
    long value1 = 1, value2 = 2;
    pthread_t thr1, thr2;
    pthread_create(&thr1, NULL, function, (void*)&value1);
    pthread_create(&thr2, NULL, function, (void*)&value2);
    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);
    printf("\nDone.\n");
    return 0;
}