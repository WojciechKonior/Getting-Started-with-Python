#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32

struct item{
    int id;
    char name[SIZE];
    float price;
    struct item *next;
};

// /* read standard input, discard newline */
// char *input(void)
// {
//     static char buffer[SIZE];
//     char *r;
//     int x;

//     buffer[0] = '\0';

//     r = fgets(buffer, SIZE, stdin);
//     if(r==NULL){
//         fprintf(stderr, "Input error\n");
//         exit(1);
//     }

//     for(x = 0; x<SIZE; x++){
//         if(buffer[x]=='\n'){
//             buffer[x] = '\0';
//             break;
//         }
//     }

//     return buffer;
// }

struct item* allocate(void)
{
    struct item *p;
    p = (struct item*)malloc(sizeof(struct item)*1);
    if(p==NULL){
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    return p;
}

void fill(struct item *s, int i)
{
    // char temp[SIZE];

    // s->id = i;
    // printf("Record %d Fruit: ", i);
    // strcpy(s->name, input());
    // printf("Price: ");
    // strcpy(temp, input());
    // s->price = strtof(temp, NULL);

    static const char *fruit[] = {"apples", "bananas", "grapes", "strawberry", "plums"};
    static float prices[] = {1.20, 2.58, 2.09, 2.40, 0.51};

    s->id = i+1;
    s->price = prices[i];
    strcpy(s->name, fruit[i]);
}

void update_ids(struct item* begin)
{
    struct item* current = begin;
    int i = 1;
    while(current->next!=NULL)
    {
        current->id = i++;
        current = current->next;
    }
}

void insert_item(struct item *begin, int id, const char* name, float price)
{
    printf("adding the %d record...\n", id);
    struct item *current = begin;
    struct item *previous = NULL;
    while(current->id != id)
    {
        previous = current;
        current = current->next;
        if(current == NULL)
        {
            fprintf(stderr, "Structure out of bounds\n");
            exit(1);
        }
    }

    struct item* new = allocate();
    new->id = current->id;
    new->price = current->price;
    strcpy(new->name, current->name);
    new->next = current->next;

    current->id = id;
    current->next = new;
    current->price = price;
    strcpy(current->name, name);
    
    update_ids(begin);
}

void delete(struct item *begin, int id)
{
    printf("Removing the %d record...\n", id);
    struct item *current = begin;
    struct item *previous = NULL;
    while(current->id != id)
    {
        previous = current;
        current = current->next;
        if(current == NULL)
        {
            fprintf(stderr, "Structure out of bounds\n");
            exit(1);
        }
    }

    if(current->next != NULL){
        struct item *next = current->next;
        strcpy(current->name, next->name);
        current->price = next->price;
        current->next = next->next;
        free(next);
    }
    else{
        previous->next = NULL;
        free(current);
    }

    update_ids(begin);
}

void output(struct item *s)
{
    while(s!=NULL)
    {
        printf("%d: %s for %.2f/pound\n",
            s->id,
            s->name,
            s->price
        );
        s = s->next;
    }
}

int main(int argc, char* argv[])
{
    struct item *first, *current, *temp;
    int x;

    for(x = 0; x<5; x++)
    {
        if(x==0){
            first = allocate();
            current = first;
        }
        else{
            current->next = allocate();
            current = current->next;
        }
        fill(current, x);
    }
    
    current->next = NULL;

    puts("Original List:");
    output(first);

    delete(first, 1);
    delete(first, 5);

    insert_item(first, 2, "apples", 4.40);


    puts("Updated List:");
    output(first);

    puts("\nDone.");
    return 0;
}