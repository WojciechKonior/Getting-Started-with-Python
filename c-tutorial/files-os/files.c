#include <stdio.h>

int main(int argc, char*argv[])
{
    FILE* file;
    file = fopen("io.txt", "w");
    fputs("Wojtek Konior", file);
    fclose(file);

    file = fopen("io.txt", "r");
    char buffer[14];
    fgets(buffer, 14, file);
    fclose(file);
    printf("\nDone.\n");
    return 0;
}