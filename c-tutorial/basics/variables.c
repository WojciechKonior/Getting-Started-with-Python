#include <stdio.h>

#define CONSTANT 10

typedef int int32;

typedef struct{
    char name[50];
    char id[10];
    int age;
    int grades[5];
} Student;

int main(int argc, char*argv[])
{
    int var1;
    var1 = 10;
    int var2 = 20;
    printf("int1 = %d\nint2 = %d\n", var1, var2);
    int x, y, z;
    x = 2;
    y = 3;
    z = 4;

    float mynum = 99.4f;
    printf("float = %f\n", mynum);

    double mydoub = 98.1111111;
    printf("double = %lf\n", mydoub);

    char c = 'A';
    printf("char = %c\n", c);
    
    unsigned ui;
    unsigned char uc;

    short sh;
    unsigned short ush;

    long lg;
    unsigned long ulg;

    long long llg;
    unsigned long long ullg;

    long double ld;

    printf("sizeof \"char\" = \t%lld\n", sizeof(char));
    printf("sizeof \"unsigned char\" = \t%lld\n", sizeof(unsigned char));

    printf("sizeof \"short\" = \t%lld\n", sizeof(short));
    printf("sizeof \"unsigned short\" = \t%lld\n", sizeof(unsigned short));

    printf("sizeof \"int\" = \t%lld\n", sizeof(int));
    printf("sizeof \"unsigned int\" = \t%lld\n", sizeof(unsigned int));

    printf("sizeof \"long\" = \t%lld\n", sizeof(long));
    printf("sizeof \"unsigned long\" = \t%lld\n", sizeof(unsigned long));

    printf("sizeof \"long long\" = \t%lld\n", sizeof(long long));
    printf("sizeof \"unsigned long long\" = \t%lld\n", sizeof(unsigned long long));

    printf("sizeof \"float\" = \t%lld\n", sizeof(float));
    printf("sizeof \"double\" = \t%lld\n", sizeof(double));
    printf("sizeof \"long double\" = \t%lld\n", sizeof(long double));

    printf(
        "%c  %i  %li  %lli %u %-10d %lu %llu %ld %lld  %f    %g    %e   %x  %X %s\n",
        'A', -1, -2l, -3ll, 1, 2, 3,   4,  5,   6, 10.0, 11.0, 11.0, 10, 11, "Wojtek"
    );

    // char *str1 = "Wojtek Konior";
    const char* str2 = "wojtek";

    //arrays
    int arr[3] = {1, 2, 3};

    //strings
    char test[7] = "Wojtek";
    char test2[] = "Wojtek Konior";
    const char* name = "Wojtek";

    //casting
    double a = 10.1;
    int b = (int)a;
    printf("%lf to int is %d\n", a, b);

    const int32 constant = 10;
    printf("compile-time constant: %d, runtime-constant: %d\n", CONSTANT, constant);

    Student st = {
        .name = "Wojtek",
        .id = "123",
        .age = 36,
        .grades = {5,5,5,5,5}
    };

    register int varreg = 10;
    int* ptrvar = &varreg;

    printf("\nDone.\n");
    return 0;
}