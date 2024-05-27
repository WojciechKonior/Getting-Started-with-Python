#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char s1[] = "This is string";

    char *s2 = strpbrk(s1, "is");

    printf("s2 = %s\n", s2);

    printf("\nDone.\n");
    return 0;
}