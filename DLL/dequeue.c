#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *lptr, *rptr;
}NODE;

NODE *Ins_first(NODE *first, int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->lptr = NULL;
    newnode->rptr = first;
    if(first != NULL)
        first->lptr = newnode;
    printf("Node with info %d is inserted\n", data);
    return newnode;
}

NODE *Ins_last(NODE *first, int data)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->rptr = NULL;
    if(first == NULL)
    {
        newnode->lptr = NULL;
        first = newnode;
    }
    else
    {
        temp = first;
        while(temp->rptr != NULL)
            temp = temp->rptr;
        temp->rptr = newnode;
        newnode->lptr = temp;
    }
    printf("Node with info %d is inserted\n", data);
    return first;
}

NODE *Del_first(NODE *first)
{
    NODE *temp;
    if(first == NULL)
        printf("Dequeue underflow\n");
    else
    {
        temp = first;
        first = first->rptr;
        if(first != NULL)
            first->lptr = NULL;
        printf("Node with data %d is deleted\n", temp->info);
        free(temp);
    }
    return first;
}

NODE *Del_last(NODE *first)
{
    NODE *temp;
    if(first == NULL)
        printf("Dequeue underflow\n");
    else
    {
        temp = first;
        while(temp->rptr != NULL)
            temp = temp->rptr;
        if(temp->lptr == NULL)
            first = NULL;
        else
            temp->lptr->rptr = NULL;
        printf("Node with data %d is deleted\n", temp->info);
        free(temp);
    }
    return first;
}

void Display(NODE *first)
{
    if(first == NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Dequeue contents\n");
    while(first != NULL)
    {
        printf("%d<->", first->info);
        first = first->rptr;
    }
    printf("END");
}

int main()
{
    NODE *first = NULL;
    int choice, data;
    while(1)
    {
        printf("\n1:Ins@first\n2:Ins@last\n3:Del@first\n4:Del@last\n5:Display\n6:Exit");
        printf("Enter your choice");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the data\n");
                    scanf("%d", &data);
                    first = Ins_first(first, data);
                    break;
            case 2: printf("Enter the data\n");
                    scanf("%d", &data);
                    first = Ins_last(first, data);
                    break;
            case 3: first = Del_first(first);
                    break;
            case 4: first = Del_last(first);
                    break;
            case 5: Display(first);
                    break;
            case 6: exit(0);
            default:printf("Invalid choice");
        }
    }
    return 0;
}