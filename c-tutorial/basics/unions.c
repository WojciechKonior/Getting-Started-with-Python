#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef union {
    unsigned a;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    };
} UInt;

typedef union{
    unsigned char states;
    struct {
        unsigned char s1 : 1;
        unsigned char s2 : 1;
        unsigned char s3 : 1;
        unsigned char s4 : 1;
        unsigned char s5 : 1;
        unsigned char s6 : 1;
        unsigned char s7 : 1;
        unsigned char s8 : 1;
    };
} States;

typedef union{
    unsigned a;
    unsigned char b[4];
} EU;

typedef struct {
    unsigned p : 1;
} Bit;

int main(int argc, char*argv[])
{
    EU eu;
    eu.a = 0x12131415;
    printf("%X -> %x, %x, %x, %x\n", eu.a, eu.b[0], eu.b[1], eu.b[2], eu.b[3]);
    States s;
    Bit b;
    printf("%d, %d\n", sizeof(s), sizeof(b));
    UInt A;
    A.a = 0xABCDEF21;
    printf("%X -> %x, %x, %x, %x\n", A.a, A.a4, A.a3, A.a2, A.a1);

    printf("\nDone.\n");
    return 0;
}