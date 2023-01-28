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

//Displaying the contents of Stack
void display(NODE *first){
    if(first == NULL)
        printf("Stack is empty\n");
    else{
        printf("Contents of stack\n");
        while(first != NULL){
            printf("%d -> ", first->info);
            first = first->next;
        }
    }
}

int main(){
    NODE *first = NULL;
    int data, choice;
    while(1){
        printf("\n1:PUSH\n2:POP\n3:Display\n4:Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1  :printf("Enter the data to be pushed\n");
                     scanf("%d", &data);
                     first = Ins_first(first, data);
                     break;
            case 2  :first = Del_first(first);
                     break;
            case 3  :display(first);
                     break;
            case 4  :exit(0);
            default :printf("Invalid Choice\n");
        }
    }
    return 0;
}