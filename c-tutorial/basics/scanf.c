#include <stdio.h>

int main(int argc, char*argv[])
{
    long double n = 0;
    printf("Enter a number: ");
    scanf("%llf", &n);
    printf("You entered %llf\n", n);

    char buffer[50];
    printf("Enter a string: ");
    scanf("%s", buffer);
    printf("You entered: %s", buffer);
    printf("\nDone.\n");
    return 0;
}