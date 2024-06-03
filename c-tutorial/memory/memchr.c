#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    char data[] = "Wojtek Konior 1234";
    char *pos = memchr(data, 'K', 10);

    printf("\nDone.\n");
    return 0;
}