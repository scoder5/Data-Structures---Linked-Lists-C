//Stack using linked list
#include<stdio.h>
#include<stdlib.h>

//Representation of a node in Singly Linked List.
//A structure containing a member which is a pointer to the same structure is called self referential structure.
typedef struct node{
    int info;
    struct NODE *next;
}NODE;

//Allocating memory for a newnode
NODE *getNode(void){
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    return newnode; 
}

//Freeing memory for a node
void freeNode(NODE *temp){
    free(temp);
}

//To implement stack we use insertFirst and deleteFirst functions because,
//implementation of insertLast and deleteLast is quite complex(requires looping constructs).

//Implementation of inserting a newnode at the beginning of SLL
NODE *Ins_first(NODE *first, int data){
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = first;
    printf("Node with data %d is pushed on to the stack\n", data);
    return newnode;
}

//Implementation of deleting node at the beginning of SLL
NODE *Del_first(NODE *first){
    NODE * temp;
    if(first == NULL)
        printf("Stack Underflow");
    else{
        temp = first;
        first = first->next;
        printf("Node with data %d is popped from the stack\n", temp->info);
        free(temp);
    }
    return first;
}

//Displaying the contents of SLL
void display(NODE *first){
    
}