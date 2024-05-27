#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char buffer[100];

    // scanf("%s\n", buffer);
    // fgets(buffer, 100, stdin);

    printf("Give me some letters: ");
    char c;
    int i = 0;
    while((buffer[i++]=fgetc(stdin)) != '\n'){}

    printf("String is: %s", buffer);

    printf("\nDone.\n");
    return 0;
}