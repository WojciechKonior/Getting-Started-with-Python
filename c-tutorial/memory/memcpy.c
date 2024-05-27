#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    char buffer[10];
    memset(buffer, 'c', sizeof(char)*10);

    printf("%s\n", buffer);

    char another[10];
    memcpy(another, buffer, sizeof(char)*10);

    printf("%s\n", another);

    exit(EXIT_FAILURE);
    exit(EXIT_SUCCESS);

    printf("\nDone.\n");
    return 0;
}