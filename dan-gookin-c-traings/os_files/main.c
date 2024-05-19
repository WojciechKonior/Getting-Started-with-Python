#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int u = unlink("test.txt.old");
    if(u==0) puts("File deleted");
    
    FILE *handle = fopen("test.txt", "r");
    if (handle) {
        while(1){
            char c = fgetc(handle);
            if(c==EOF) break;
            putchar(c);
        }
        fclose(handle);
    }
    else 
        printf("File doesn't exist\n");

    handle = fopen("test.txt", "a");
    if (handle) {
        char src[] = "\nSome text";
        fwrite(src, sizeof(char), 10, handle);
        fprintf(handle, "\nSome other text");
        fputc('a', handle);
        fputs("\nWojtek", handle);
        fclose(handle);
    }
    else 
        printf("File doesn't exist\n");

    struct A{
        int a;
        int b;
    } some_raw_data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    handle = fopen("rawdata", "w");
    if (handle) {
        fwrite(&some_raw_data, sizeof(struct A), 4, handle);
        fclose(handle);
    }
    else 
        printf("File doesn't exist\n");

    handle = fopen("rawdata", "r");
    struct A some_dst_data;
    if (handle) {
        fseek(handle, sizeof(struct A)*3, SEEK_SET);
        fread(&some_dst_data, sizeof(struct A), 1, handle);
        printf("data is: %d %d\n", some_dst_data.a, some_dst_data.b);
        fclose(handle);
    }
    else 
        printf("File doesn't exist\n");

    int r = rename("test.txt", "test.txt.old");
    if(r==0) puts("File renamed");

    char path[512];
    chdir("..");
    getcwd(path, 512);
    printf("%s\n", path);


    DIR *dir = opendir(".");
    struct dirent *file;
    if(dir==NULL){
        puts("Unable to open current directory\n");
    }
    else{
        while((file = readdir(dir))!=NULL){
            printf("%s\n", file->d_name);
        }
        closedir(dir);
    }

    struct stat fstat;
    const char* filename = "test.txt.old";
    stat(filename, &fstat);
    printf("%s %ld\n", filename, fstat.st_blocks);

    for(int i = 0; i<argc; i++){
        printf("%s\n", argv[i]);
    }

    system("ls");

    FILE *p;
    int C;
    p = popen("uname", "r");
    if(p==NULL){
        puts("Unable to create process");
    }
    else{
        while((C=fgetc(p))!=EOF){
            putchar(C);
        }
        pclose(p);
    }

    return 0;
}