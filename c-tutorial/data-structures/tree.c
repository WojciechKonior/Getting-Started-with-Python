#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createnode(int value){
    treenode* result = malloc(sizeof(treenode));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs){
    for(int i = 0; i<numtabs; i++){
        printf("\t");
    }
}

void printtree_rec(treenode *root, int level){
    if(root == NULL){
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }

    printtabs(level);
    printf("value = %d\n", root->value);

    printtabs(level);
    printf("left: \n");
    printtree_rec(root->left, level+1);

    printtabs(level);
    printf("right: \n");
    printtree_rec(root->right, level+1);

    printtabs(level);
    printf("done\n");

}

void printtree(treenode* root){
    printtree_rec(root, 0);
}

bool insertnumber(treenode **rootptr, int value){
    treenode *root = *rootptr;
    if(root == NULL)
    {
        //tree empty
        (*rootptr) = createnode(value);
        return true;
    }

    if(value == root->value){
        //do nothing
        return false;
    }

    if(value < root->value){
        return insertnumber(&(root->left), value);
    } else {
        return insertnumber(&(root->right), value);
    }
}

bool findnumber(treenode *root, int value)
{
    if(root == NULL) return false;

    if(root->value == value) return true;

    if(value < root->value) return findnumber(root->left, value);
    else return findnumber(root->right, value);
}

int main(void)
{
    treenode *n1 = createnode(10);
    treenode *n2 = createnode(11);
    treenode *n3 = createnode(12);
    treenode *n4 = createnode(13);
    treenode *n5 = createnode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    insertnumber(&n1, 24);
    insertnumber(&n1, 19);
    insertnumber(&n1, 16);

    

    printtree(n1);


    printf("Is there 16?: %d\n", findnumber(n1, 16));
    printf("Done.\n");
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}