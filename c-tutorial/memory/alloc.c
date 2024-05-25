#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[])
{
    void* mem = malloc(4);
    int* i = (int*)mem;
    *i = 10;
    printf("The value: %d\n", *i);
    free(i);

    double* mem2 = (double*)calloc(10, sizeof(double));
    for(int i = 0; i<10; i++) printf("mem[%d]=%lf\n", i, mem2[i]);

    mem2 = (double*)realloc(mem2, 20*sizeof(double));
    free(mem2);


    time_t tic2 = clock();
    int *array2 = (int*)malloc(1e6*sizeof(int));
    time_t toc2 = clock();
    printf("Time of malloc 1e8 ints: %lfs\n", (double)(toc2-tic2)/CLOCKS_PER_SEC);
    free(array2);

    time_t tic1 = clock();
    int *array1 = (int*)calloc(1e6, sizeof(int));
    time_t toc1 = clock();
    printf("Time of calloc 1e8 ints: %lfs\n", (double)(toc1-tic1)/CLOCKS_PER_SEC);
    free(array1);

    printf("\nDone.\n");
    return 0;
}