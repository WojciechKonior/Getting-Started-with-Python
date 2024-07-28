#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person* next;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i<length; i++){
        hash_value += name[i];
        hash_value = (hash_value*name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool init_hash_table(){
    for(int i = 0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

void print_table(){
    for(int i = 0; i<TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        } else {
            person* next = hash_table[i];
            printf("\t%i\t", i);
            while(next != NULL){
                printf("%s --- ", next);
                next = next->next;
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(person *p)
{
    if(p==NULL)return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person* hash_table_lookup(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    while(tmp !=NULL && strncmp(tmp->name, name, MAX_NAME) !=0){
        tmp = tmp->next;
    }
    return tmp;
}

person* hash_table_delete(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while(tmp !=NULL && strncmp(tmp->name, name, MAX_NAME) !=0){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp==NULL) return NULL;
    if(prev==NULL){
        hash_table[index] = tmp->next;
    }
    else{
        prev->next = tmp->next;
    }
    return tmp;
}

int main(void)
{
    init_hash_table();
    // print_table();

    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person mpho1 = {.name="Mpho1", .age=14};
    person mpho2 = {.name="Mpho2", .age=14};
    person mpho3 = {.name="Mpho3", .age=14};
    person mpho4 = {.name="Mpho4", .age=14};
    person mpho5 = {.name="Mpho5", .age=14};
    person mpho6 = {.name="Mpho6", .age=14};
    person mpho7 = {.name="Mpho7", .age=14};
    person mpho8 = {.name="Mpho8", .age=14};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&mpho1);
    hash_table_insert(&mpho3);
    hash_table_insert(&mpho2);
    hash_table_insert(&mpho4);
    hash_table_insert(&mpho5);
    hash_table_insert(&mpho6);
    hash_table_insert(&mpho7);
    hash_table_insert(&mpho8);
    hash_table_delete("Mpho");
    print_table();

    person *tmp = hash_table_lookup("Mpho");
    if(tmp == NULL){
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("George");
    if(tmp == NULL){
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }    


    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Wojtek => %u\n", hash("Wojtek"));
    // printf("Kuba => %u\n", hash("Kuba"));
    // printf("Monika => %u\n", hash("Monika"));
    // printf("Done.\n");
    return 0;
}