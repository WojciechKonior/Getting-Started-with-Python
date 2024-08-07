#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
} node_t;

node_t* create_new_node(int value){
    node_t* result = malloc(sizeof(node_t));
    if(result != NULL){
        result->value = value;
        result->next = NULL;
        result->prev = NULL;
    }   
    return result;
}

node_t* insert_at_head(node_t** head_ptr, node_t* node_to_insert){
    node_t* head = *head_ptr;
    node_to_insert->next = head;
    if(head!=NULL) node_to_insert->next->prev = node_to_insert;
    head = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t* node_to_insert_after, node_t* new_node){
    new_node->next = node_to_insert_after->next;
    new_node->prev = node_to_insert_after;
    node_to_insert_after->next = new_node;
    if(new_node->next != NULL) new_node->next->prev = new_node;
}

node_t* find_node(node_t* head, int value){
    node_t* tmp = head;
    while(tmp!=NULL){
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void remove_node(node_t **head, node_t *node_to_remove){
    if(*head == node_to_remove){
        *head = node_to_remove->next;
        if(*head != NULL)
            (*head)->prev = NULL;
        return;
    } else {
        node_to_remove->prev->next = node_to_remove->next;
        if(node_to_remove->next != NULL){
            node_to_remove->next->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;
}

void printlist(node_t *head){
    node_t *temporary = head;

    while(temporary != NULL){
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

int main(void)
{
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    node_t n4;
    n4.value = 13;
    n4.next = &n3;

    head = &n4;

    insert_at_head(&head, create_new_node(10));
    insert_after_node(find_node(head, 13), create_new_node(75));
    remove_node(&head, find_node(head, 13));
    remove_node(&head, head);

    printlist(head);
    printf("Find 8: %d\n", (find_node(head, 8)->value));

    printf("Done.\n");
    return 0;
}