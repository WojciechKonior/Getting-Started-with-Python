#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char open_errors(FILE* file)
{
    if(file==NULL)
    {
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
        return errno;
    }
    return 0;
}

int main(int argc, char*argv[])
{
    FILE* file;
    file = fopen("io.txt", "w");
    if(!open_errors(file))
    {
        fputs("Wojtek Konior\njest fajny\ni gruby", file);
        fclose(file);
    }

    file = fopen("io.txt", "r");
    if(!open_errors(file))
    {
        fseek(file, 10, SEEK_SET);
        fseek(file, 1, SEEK_CUR);
        fseek(file, -10, SEEK_END);
        char buffer[256];
        // fgets(buffer, 14, file);
        int i = 0;
        while((buffer[i++] = fgetc(file))!=EOF)
        {
            if(i==24) rewind(file);
        }
        buffer[i] = '\0';
        printf("%s\n", buffer);
        fclose(file);
    }

    double PI = 3.14;
    char pi[16];
    sprintf(pi, "%lf", PI);
    printf("%s", pi);

    char *log_dir = getenv("LOG_DIR");
    system("ls");

    printf("\nDone.\n");
    return 0;
}