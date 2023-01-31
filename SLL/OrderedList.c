//A list in which the elements are arranged in some order is referred to as an ordered list.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}NODE;

//Insertion operation for ordered LL
NODE *Insert(NODE *first, int data){
    NODE *newnode, *temp, *prev;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    if(first == NULL || data < first->info){
        newnode->next = first;
        first = newnode;
    }
    else{
        temp = first;
        while(temp != NULL && data > temp->info){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL || data != temp->info){
            prev->next = newnode;
            newnode->next = temp;
        }
    }
    return first;
}