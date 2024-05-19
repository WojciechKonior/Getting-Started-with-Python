#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

struct item{
    int id;
    char name[SIZE];
    float price;
    struct item *next;
};

/* read standard input, discard newline */
char *input(void)
{
    static char buffer[SIZE];
    char *r;
    int x;

    buffer[0] = '\0';

    r = fgets(buffer, SIZE, stdin);
    if(r==NULL){
        fprintf(stderr, "Input error\n");
        exit(1);
    }

    for(x = 0; x<SIZE; x++){
        if(buffer[x]=='\n'){
            buffer[x] = '\0';
            break;
        }
    }

    return buffer;
}

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

    char *fruit[] = {"apples", "bananas", "grapes", "strawberry", "plums"};
    float prices[] = {1.20, 2.58, 2.09, 2.40, 0.51};

    s->id = i;
    strcpy(s->name, fruit[i]);
    s->price = prices[i];
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
    struct item *first, *current;
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
        fill(current, x+1);
    }
    
    current->next = NULL;

    puts("Original <List:");
    output(first);

    puts("Removing the fourth record...");
    current = first;

    puts("\nDone.");
    return 0;
}