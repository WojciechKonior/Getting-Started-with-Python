#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
    char str[] = "WojciechKonior56789";
    char num[] = "1234567";

    size_t init = strcspn(str, num);
    printf("Result: %lld\n", init);

    init = strspn(str, num);
    printf("Result: %lld\n", init);
    printf("\nDone.\n");
    return 0;
}