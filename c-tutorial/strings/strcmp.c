#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char s1[] = "This is string";
    char s2[] = "This is string";
    char s3[] = "This is also string";

    if(!strcmp(s1,s2))
        printf("s1 is equal to s2\n");

    if(strcmp(s2, s3))
        printf("s2 is not equal to s3\n");

    printf("\nDone.\n");
    return 0;
}