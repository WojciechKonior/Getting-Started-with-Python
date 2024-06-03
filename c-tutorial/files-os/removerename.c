#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    FILE* file;
    file = fopen("io.txt", "w");
    fputs("Wojtek Konior", file);
    fclose(file);

    if(rename("io.txt", "io2.txt")!=0){
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
    }
    else {
        printf("io.txt renamed to io2.txt\n");
    }

    if(remove("io2.txt")!=0){
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
    }
    else
        printf("io2.txt deleted.\n");
    printf("\nDone.\n");
    return 0;
}