#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void cleanup(){}

int main(int argc, char*argv[])
{
    atexit(cleanup); // do after exit;
    int x = 2;

    if(x==2 && x != 10){
        printf("x is equal to 2\n");
    }
    else if(x==3 || (x<4 && x>2)){
        printf("x is equal to 3\n");
    }
    else{
        printf("x is equal to something else\n");
    }

    printf("Ternary operator: x = %s\n", x==2 ? "two" : "other");

    switch(x){
        case 1:
            printf("x = 1\n");
            break;
        case 2:
            printf("x = 2\n");
            break;
        default:
            printf("something else\n");
            break;
    }

    int i = 0;
    while(i<10){
        printf("%d ", i++);
    }
    printf("\n");

    do{
        if(i++>15) continue;
        printf("*");
    } while (i<20);
    printf("\n");

    for(int i = 0; i<10; i++){
        printf("|");
    }
    printf("\n");

    int one = 10, two = 20;
    assert(one == two);
    abort(); // it exits without cleanup
    exit(1); // it exits with cleanup (can be also called in function)
    printf("\nDone.\n");
    return 0;
}