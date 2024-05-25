#include <stdio.h>
#include <stdlib.h>

void printHello(void){
    printf("Hello World\n");
}

void printHelloTo(const char* name){
    printf("Hello %s\n", name);
}

int addInts(int a, int b)
{
    return a + b;
}

int* allocIntArr(int size)
{
    int* a = (int*)malloc(sizeof(int)*size);
    return a;
}

void changeValue(int *value){
    (*value)+=10;
}

int main(int argc, char*argv[])
{
    printHello();
    printHelloTo("Wojtek");
    printf("1 + 2 = %d\n", addInts(1,2));

    int* a =  allocIntArr(10);
    free(a);

    int b = 10;
    int* ptr = &b;
    changeValue(&b);
    printf("Value is: %d\n", b);

    printf("\nDone.\n");
    return 0;
}