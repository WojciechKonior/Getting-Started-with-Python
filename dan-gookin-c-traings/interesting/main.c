#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(int argc, char *argv[]){

    srand((unsigned)time(NULL));
    printf("Rand = %d\n", rand());
    printf("The square root of 2 = %.2f\n", sqrt(2));

    time_t now;
    struct tm *timestamp;
    time(&now);
    timestamp = localtime(&now);
    printf("%s\n", ctime(&now));
    printf("%d %d %d\n", timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec);

    int arr[8] = {1, 10, 2, 44, 3, 4, 8, 4};
    qsort(arr, 8, sizeof(int), compare);
    for(int i = 0; i<8; i++) printf("%d ", arr[i]);

    printf("\n%d\n", __LINE__);

    return 0;
}