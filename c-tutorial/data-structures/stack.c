#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define STACK_LENGTH 5
#define EMPTY (-1)

// int mystack[STACK_LENGTH];
// int top = EMPTY;

// int push(int value)
// {
//     if (top >= STACK_LENGTH - 1)
//         return false;

//     top++;
//     mystack[top] = value;
//     return true;
// }

// int pop()
// {
//     if (top == EMPTY)
//         return INT_MIN;

//         int result = mystack[top];
//         top--;
//         return result;
// }



// int main(void)
// {
//     push(56);
//     push(78);
//     push(13);

//     int t;
//     while((t=pop()) != INT_MIN) {
//         printf("t=%d\n",t);
//     }

//     printf("Done.\n");
//     return 0;
// }

typedef struct node {
    int value;
    struct node *next;
} node;

typedef node* stack;


int push(stack* mystack, int value)
{
    node *newnode = malloc(sizeof(node));
    if(newnode == NULL) return false;

    newnode->value = value;
    newnode->next = *mystack;
    *mystack = newnode;
    return true;
}

int pop(stack* mystack)
{
    if(*mystack==NULL) return INT_MIN;
    int result = (*mystack)->value;
    node *tmp = *mystack;
    *mystack = (*mystack)->next;
    free(tmp);
    return result;
}



int main(void)
{
    stack *st;
    push(st, 56);
    push(st, 78);
    push(st, 13);

    int t;
    while((t=pop(st)) != INT_MIN) {
        printf("t=%d\n",t);
    }

    printf("Done.\n");
    return 0;
}