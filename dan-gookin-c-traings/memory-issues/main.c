#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define new(t,x) (t*)malloc(sizeof(t)*x)
#define delete(x) free(x)

typedef struct __attribute((packed)) node {
    unsigned isvalid : 1;
    unsigned size : 15;
    struct node *next;
} node_t;

#define SIZE 64
//static
int my_variable = 80;

int main(int argc, char* argv[])
{
    node_t n = {.isvalid = 1, .size = 256, .next = NULL};
    node_t n2;
    // n2 = n;
    memcpy(&n2, &n, sizeof(node_t));
    
    char *buffer[SIZE];
    memset(buffer, 0, SIZE);

    printf("Size of struct: %ld\n", sizeof(node_t));

    char* y = new(char, 10);
    delete(y);

    int *x = malloc(sizeof(int));
    int *arr = malloc(sizeof(int)*100);

    *x = 120;
    arr[10] = 0xFEEDBEEF;

    free(arr);
    arr = NULL;
    double *darr;
    darr = calloc(sizeof(double), 100);

    darr = realloc(darr, sizeof(double)*500);
    
    printf("\nDone.\n");
    return 0;
}