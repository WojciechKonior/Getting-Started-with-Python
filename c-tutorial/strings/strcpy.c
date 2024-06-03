#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char src[] = "Wojtek Konior";
    char dest[256];
    char dst[10];

    strcpy(dest, src);
    printf("src: %s -> dest: %s\n", src, dest);

    strncpy(dst, src, 9);
    dst[9] = '\0';
    printf("src: %s -> dest: %s\n", src, dst);

    printf("\nDone.\n");
    return 0;
}