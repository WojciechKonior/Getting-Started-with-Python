#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{

    char haystack[] = "This is the way.";
    char needle[] = "e";

    // strstr searches the needle string in haystack string
    char *the = strtok(haystack, needle);
    printf("the: %s\n", the);
    printf("\nDone.\n");
    return 0;
}