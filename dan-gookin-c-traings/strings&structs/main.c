#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* construct_array_int(int size)
{
    return (int*)malloc(sizeof(int)*size);
}

struct AB{
    struct A{
        int a;
        int b;
    } a;
    struct B{
        int a;
        int b;
    } b;
} ab = {1, 2, 3, 4};

void printStruct(struct AB* abc)
{
    printf("%d %d %d %d\n", abc->a.a, abc->a.b, abc->b.a, abc->b.b);
}

struct AB* func(struct AB* abc)
{
    struct AB* abcd = (struct AB*)malloc(sizeof(struct AB));
    abcd->a.a = abc->a.a + 1;
    abcd->a.b = abc->a.b + 1;
    abcd->b.a = abc->b.a + 1;
    abcd->b.b = abc->b.b + 1;
}

int main()
{

    union storage {
        char a : 4;
        short b : 4;
    } str;

    printf("size = %d\n", sizeof(str));

    struct AB abc = {1, 2, 3, 4};
    struct AB *abcd = func(&abc);
    printStruct(abcd);
    free(abcd);
    printf("%d %d %d %d\n", ab.a.a, ab.a.b, ab.b.a, ab.b.b);

    srand((unsigned)time(NULL));
    int a = rand();

    float scores[5] = {1.1, 2.1, 3.5, 5.4, 3.4}; //stack allocated

    float *scores2 = (float*)malloc(sizeof(float)*5); //heap allocated
    if(scores2 ==NULL){
        printf("Insufficient memory available\n");
    }
    else{
        for(int i = 0; i<5; i++) scores2[i] = i*0.11+0.1;
        for(int i = 0; i<5; i++) printf("%.2f\n", scores2[i]);
    }
    free(scores2);

    for(int i = 0; i<5; i++)
    {
        printf("%d: %.2f\n", i+1, scores[i]);
    }

    int ch1, ch2;

    printf("Type a character: ");
    // // ch1 = getchar();
    // ch1 = getc(stdin);

    // printf("Type a character: ");
    // // ch2 = getchar();
    // ch2 = getc(stdin);

    // printf("You typed: %c %c\n", ch1, ch2);

    while(1){
        ch1 = getchar();
        if(ch1==EOF) break;
        if(isalpha((char)ch1))
            putchar(ch1);
        if(isdigit((char)ch1))
            putchar(ch2);
    }

    char napis[] = "Wojtek Konior";
    char napis2[] = {'W', 'o', 'j', '\0'};
    const char* literal = "wojtek KOnior";

    printf("%s %d\n%s %d\n%s %d\n",
        napis, strlen(napis),
        napis2, strlen(napis2),
        literal, strlen(literal)
    );


    return 0;
}