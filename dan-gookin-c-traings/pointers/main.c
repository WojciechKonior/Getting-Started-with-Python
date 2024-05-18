#include <stdio.h>
#include <stdlib.h>

struct Str{
    int age;
    char *name;
};

struct Str* make_person(){
    struct Str *person = (struct Str*)malloc(sizeof(struct Str)*1);
    person->name = (char*)malloc(sizeof(char)*32);
    return person;
}

int main()
{
    int a = 10;
    int *const b = &a;

    int *c = NULL;
    c = &a;

    char *d = (char*)&a;
    printf("Hello World %p %d\n", c, *c);
    printf(
        "%p->%d\n%p->%d\n%p->%d\n%p->%d\n",
        d, *d, d+1, *(d+1), d+2, *(d+2), d+3, *(d+3)
    );

    int tab[] = {1, 2, 3, 4};
    int *ptr = tab;
    printf(
        "%p->%d\n%p->%d\n%p->%d\n%p->%d\n",
        ptr, *ptr, ptr+1, *(ptr+1), ptr+2, *(ptr+2), ptr+3, *(ptr+3)
    );

    char *buffer = (char*)malloc(sizeof(char)*32);
    if(buffer==NULL){ printf("Cannot be allocated!\n"); exit(1); }

    // buffer = "Wojtek";
    printf("%s\n", buffer);
    free(buffer);

    char *veeps[5] = {
        "Adams",
        "Jefferson",
        "Burr",
        "Clinton",
        "Bush"
    };

    char* temp;
    temp = veeps[1];
    veeps[1] = veeps[4];
    veeps[4] = temp;

    printf("%c\n", **(veeps+1));



    struct Str* person = make_person();

    person->age = 33;
    char* woj = "Wotek Konior";
    strcpy(person->name, woj);

    printf("%s %d\n", person->name, person->age);

    free(person->name);
    free(person);

    return 0;
}