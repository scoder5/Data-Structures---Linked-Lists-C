//A list in which the elements are arranged in some order is referred to as an ordered list.
#include<stdio.h>
#include<stdlib.h>

//Representation of a node in SLL
typedef struct node{
    int info;
    struct node *next;
}NODE;

//Ascending ordered List Construction
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
            temp->next = newnode;
            newnode->next = temp;
        }
    }
    return first;
}