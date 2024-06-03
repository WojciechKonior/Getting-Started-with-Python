#include <stdio.h>
#include <unistd.h>
#include <time.h>
// #include <stdbool.h>

// typedef enum Bool {
//     false = 0,
//     true
// } bool;
// typedef unsigned char bool;
// #define true 1
// #define false 0

int main(int argc, char*argv[])
{
    // bool x = false;
    // bool y = true;

    time_t now = time(NULL);
    printf("Epoch: %ld\n", now);
    sleep(2);

    time_t two_secs = time(NULL);
    printf("Epoch: %d\n", two_secs);

    double diff = difftime(two_secs,now);
    printf("Diff: %lf\n", diff);

    char *str_now = ctime(&now);
    printf("%s\n", str_now);

    struct tm *gm_time = gmtime(&now);
    printf("tm_sec: %d\n", gm_time->tm_sec);

    struct tm *cur_time =localtime(&now);
    char *other_string = asctime(cur_time);
    printf("%s\n", other_string);

    time_t curr_time = mktime(cur_time);

    char s[100];
    strftime(s,100, "%A %B %d", cur_time);

    clock_t start, end;
    start = clock();
    for(int i = 0; i<1e6; i++){}
    end = clock();

    double total = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time: %fs\n", total);

    printf("\nDone.\n");
    return 0;
}