#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)
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
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p)
{
    if(p==NULL)return false;
    int index = hash(p->name);
    for(int i = 0; i<TABLE_SIZE; i++){
        int try = (i+index)%TABLE_SIZE;
        if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            hash_table[try]=p;
            return true;
        }
    }
    return false;
}

person* hash_table_lookup(char *name)
{
    int index = hash(name);
    for(int i = 0; i<TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false;
        }
        if(hash_table[try]==DELETED_NODE) continue;
        if(strncmp(hash_table[try]->name, name, TABLE_SIZE)==0){
            return hash_table[try];
        }
    }
    return NULL;
}

person* hash_table_delete(char *name)
{
    int index = hash(name);
    for(int i = 0; i<TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try]== NULL) return NULL;
        if(hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try]->name, name, TABLE_SIZE)==0){
            person* tmp = hash_table[try];
            hash_table[try] = NULL;
            return tmp;
        }
    }
    return NULL;
}

int main(void)
{
    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
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