#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum logLevel{
    Info = 1, Wrn, Err
} LogLevel;

int main(int argc, char*argv[])
{
    enum{
        A = 10, B, C, D, E, F
    };

    printf("%X\n", A);

    LogLevel lev = Err;
    if(lev==Err){
        printf("there is some error\n");
    }

    printf("\nDone.\n");
    return 0;
}