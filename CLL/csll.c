#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

NODE *Ins_first(NODE *last, int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    
}