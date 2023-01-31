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

//Freeing memory for a node
void freeNode(NODE *temp){
    free(temp);
}

//Inserting a new node at the beginning
NODE *Ins_first(NODE *first, int data){
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = first;
    printf("%d got inserted\n", data);
    return newnode;
}

//Inserting a new node at the end
NODE *Ins_end(NODE *first, int data){
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
    printf("%d got inserted\n", data);
    return first;
}

//Deleting the first node
NODE *del_first(NODE *first){
    NODE *temp;
    if(first == NULL)
        printf("Empty List\n");
    else{
        temp = first;
        first = first->next;
        printf("Node with data : %d is deleted\n", temp->info);
        free(temp);
    }
    return first;
}

//Deleting the last node
NODE *del_last(NODE *first){
    NODE *temp, *prev = NULL;
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
    NODE *temp;
    if(first == NULL){
        printf("Empty List\n");
        return;
    }
    else{
        temp = first;
        printf("Elements of SLL :\n");
        while(temp->next != NULL){
            printf("%d->", temp->info);
            temp = temp->next;
        }
    }
} 

int main(){
    NODE *first = NULL;
    int choice, data;
    while(1){
        printf("\n\n1:Ins@first\n2:Ins@last\n3:Del@first\n4:Del@last\n5:Display\n6:Exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the data\n");
                    scanf("%d", &data);
                    first = Ins_first(first, data);
                    break;
            case 2: printf("Enter the data\n");
                    scanf("%d", &data);
                    first = Ins_end(first, data);
                    break;
            case 3: first = del_first(first);
                    break;
            case 4: first = del_last(first);
                    break;
            case 5: display(first);
                    break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}