#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    char source[] = "wojciech.konior@gmail.com";
    char dest[20];
    memccpy(dest, source, '@', 20);
    printf("%s\n", dest);

    printf("\nDone.\n");
    return 0;
}