//Queue using Singly Linked List
#include<stdio.h>
#include<stdlib.h>

//Representation of a node in SLL
//A structure containing a member which is a pointer to the same structure is called self referential structure.
typedef struct node{
    int info;
    struct node *next;
}NODE;

//Ins_last() and Delete_first() routines are used to show FIFO
NODE *Ins_last(NODE *first, int data){
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = NULL;
    if(first == NULL)
        first = newnode;
    else{
        temp = first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node with data %d is inserted\n", data);
    return first;
}

//Delete_first()
NODE *Del_first(NODE *first){
    NODE *temp;
    if(first == NULL)
        printf("Queue Underflow");
    else{
        temp = first;
        first = first->next;
        printf("Node with data %d got deleted\n", temp->info);
        free(temp);
    }
    return first;
}

//Display Nodes
void display(NODE *first){
    if(first == NULL)
        printf("Empty Queue\n");
    else{
        printf("Queue Contents\n");
        while(first != NULL){
            printf("%d->", first->info);
            first = first->next;
        }
    }
}

int main(){
    NODE *first = NULL;
    int choice, data;
    while(1){
        printf("\n1 : Insert\n2 : Delete\n3 : Display\n4 : Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1 : printf("Enter the data\n");
                     scanf("%d", &data);
                     first = Ins_last(first, data);
                     break;
            case 2 : first = Del_first(first);
                     break;
            case 3 : display(first);
                     break;
            case 4 : exit(0);
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}