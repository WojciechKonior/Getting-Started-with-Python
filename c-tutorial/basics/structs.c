#include <stdio.h>

typedef struct{
    char name[50];
    char id[10];
    int age;
    int grades[5];
} Student;

void printStudent(Student *student)
{
    printf("name: %s\nid: %s\nage: %d\ngrades: %d,%d,%d,%d,%d\n",
        student->name, student->id, student->age, student->grades[0],
        student->grades[1], student->grades[2],
        student->grades[3], student->grades[5]
    );
}

int main(int argc, char*argv[])
{
    Student st = {
        .name = "Wojtek",
        .id = "123",
        .age = 36,
        .grades = {5,5,5,5,5}
    };

    printStudent(&st);

    printf("\nDone.\n");
    return 0;
}