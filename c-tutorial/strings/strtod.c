#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    char str1[] = "10.33";
    char str2[] = "94";
    char *ptr;
    double x = strtod(str1, &ptr);

    double res1 = atof(str1);
    int res2 = atoi(str2);
    long res3 = atol(str2);
    long long res4 = atoll(str2);
    
    char str3[16];
    sprintf(str3, "%d", res2);

    printf("%lf\n", x);
    
    printf("\nDone.\n");
    return 0;
}