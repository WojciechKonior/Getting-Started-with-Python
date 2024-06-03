#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void myprint(char *str, ...)
{
    va_list args;
    va_start(args, str);

    for(char *c=&str[0]; *c!='\0'; c++){
        if((*c)=='d'){
            int x = va_arg(args, int);
            printf("%d ", x);
        }
        else if((*c)=='f'){
            double x = va_arg(args, double);
            printf("%lf ", x);
        }
    }
    printf("\n");
    va_end(args);
}

void printHello(void){
    printf("Hello World\n");
}

void printHelloTo(const char* name){
    printf("Hello %s\n", name);
}

int addInts(int a, int b)
{
    static int n = 0;
    n++;
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
    myprint("dddfdf", 1, 2, 3, 10.99, 4, 2.22);
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