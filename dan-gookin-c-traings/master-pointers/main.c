#include <stdio.h>
#include <stdlib.h>

void some_func(int a){
    printf("The number is: %d\n", a);
}

int main(int argc, char* argv[])
{
    char a = 'A';
    char *ptr = &a;
    void(*func_ptr)(int) = some_func;
    func_ptr(10);

    printf("Value: %d = %d\n", a, *ptr);
    printf("Address: %p = %p\n", &a, ptr);
    printf("Size: a=%ld, ptr=%ld, *ptr=%ld\n", sizeof(a), sizeof(ptr), sizeof(*ptr));

    //malloc allocates uninitialized storage
    void *stor1 = malloc(10);
    // free(stor1);
    
    //realloc dynamically resizes an existing buffer
    stor1 = realloc(stor1, 20);
    free(stor1);

    //calloc allocates and initializes storage (zeros or null characters)
    void *stor2 = calloc(10, 1);
    free(stor2);

    struct Str{
        int a;
        int b;
    } src = {1, 2}, dst;

    FILE *f = fopen("src.raw", "w");
    if(f!=NULL){
        fwrite(&src, sizeof(struct Str), 1, f);
        fclose(f);
    }

    f = fopen("src.raw", "r");
    if(f!=NULL){
        fread(&dst, sizeof(struct Str), 1, f);
        fclose(f);
    }

    printf("\nDone.\n");
    return 0;
}