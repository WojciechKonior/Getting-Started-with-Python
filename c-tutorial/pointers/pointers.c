#include <stdio.h>
#include <stdlib.h>

// value passed by refference
void increment(int *value)
{
    (*value)++;
}

// array passed by refference
void increment_arr(int **arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        (*arr)[i]++;
    }
}

int main(int argc, char*argv[])
{
    unsigned int a = 0x12234487;
    unsigned int *i32ptr = &a;
    unsigned char *i8ptr = (unsigned char*)i32ptr;
    printf("value %u is stored at %p address\n", *i32ptr, i32ptr);
    printf("each B of data stored int variable:\n1st: %x\n2nd: %x\n3rd: %x\n4th: %x\n",
        *i8ptr, *(i8ptr+1), *(i8ptr+2), *(i8ptr+3)
    );

    int b = 10;
    increment(&b);
    printf("b after increment: %d\n", b);

    int arr[] = {1, 2, 3, 4};
    int *arrptr = arr;
    increment_arr(&arrptr, 4);
    printf("arr after increment: %d %d %d %d\n", arr[0],arr[1],arr[2], arr[3]);

    int *arr2 = (int*)calloc(4,sizeof(int));
    increment_arr(&arr2, 4);
    printf("arr after increment: %d %d %d %d\n", arr2[0],arr2[1],arr2[2], arr2[3]);
    free(arr2);
    printf("\nDone.\n");
    return 0;
}