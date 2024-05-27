#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char s[] = "some, data, in, commas";
    char* comma = strrchr(s, ',');
    char* firstcomma = strchr(s, ',');

    if(comma != NULL)
        printf("%s\n", comma);
    else
        printf("could not find the comma\n");

    if(firstcomma != NULL)
        printf("%s\n", firstcomma);
    else
        printf("could not find the comma\n");

    printf("\nDone.\n");
    return 0;
}