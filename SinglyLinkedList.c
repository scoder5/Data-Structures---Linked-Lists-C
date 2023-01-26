#include<stdio.h>
#include<stdlib.h>

//Representation of a node in Singly Linked List.
//A structure containing a member which is a pointer to the same structure is called self referential structure.
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

//Freeing the memory of a node
NODE *freeNode(NODE *temp){
    free(temp);
} 

//Inserting a new node at the beginning
NODE *Ins_first(NODE *first, int data){
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = first;
    printf("%d is inserted\n", data);
    return first;
}

//Inserting a new node at the end
NODE *Ins_last(NODE *first, int data){
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    if(first == NULL)
        first = newnode;
    else{
        temp = first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("%d is inserted\n", data);
    return first;
}

//Deleting the first node
NODE *del_first(NODE *first){
    NODE *temp;
    if(first == NULL)
        printf("Empty list\n");
    else{
        temp = first;
        first = first->next;
        printf("The node with data: %d is deleted\n", temp->info);
        free(temp);
    }
    return first;
}

//Deleting the last node
NODE *del_last(NODE *first){
    NODE *prev = NULL, *temp;
    if(first == NULL)
        printf("Empty List\n");
    else{
        temp = first;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL)
            first = NULL;
        else
            prev->next = NULL;
        printf("Node with data %d is deleted\n", temp->info);
        free(temp);
    }
    return first;
}

//Displaying the elements of SLL
void display(NODE *first){
    if(first == NULL)
        printf("Empty list\n");
    else{
        printf("Contents of the list are\n");
        while(first != NULL){
            printf("%d->", first->info);
            first = first->next;
        }
    }
}