#include <stdio.h>

int main(int argc, char* argv[])
{
    char a = 'A';
    char *ptr = &a;

    printf("Value: %d = %d\n", a, *ptr);
    printf("Address: %p = %p\n", &a, ptr);
    printf("Size: a=%ld, ptr=%ld, *ptr=%ld\n", sizeof(a), sizeof(ptr), sizeof(*ptr));


    printf("\nDone.\n");
    return 0;
}