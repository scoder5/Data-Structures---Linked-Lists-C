#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct NODE *next;
}NODE;

//Allocating memory to a node
NODE *getNode(void){
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    return temp;
}

//Freeing memory
void freeNode(NODE *temp){
    free(temp);
}

//Inserting a node at the beginning of a linked list
NODE *ins_first(NODE *first, int data){
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = first;
    return newnode;
}