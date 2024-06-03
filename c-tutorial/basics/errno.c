#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main(int argc, char*argv[])
{
    printf("Errno before: %d\n", errno);
    FILE *fh = fopen("dne.txt", "r");
    if(fh == NULL){
        fprintf(stderr, "Errno after: %d\nError msg: %s\n", errno, strerror(errno));
        perror("Error msg");
    }
    else{
        fclose(fh);
    }
    printf("\nDone.\n");
    return 0;
}