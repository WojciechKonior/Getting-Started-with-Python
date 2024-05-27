#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char str1[] = "Wojtek";
    char str2[] = " Konior";
    char *ptr = strcat(str1, str2);
    ptr = strncat(str1, str2, 2);
    printf("%s\n", str1);
    printf("\nDone.\n");
    return 0;
}