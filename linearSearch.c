#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct NODE *next;
}NODE;

NODE *search(NODE *first, int key){
    if(first == NULL)
        printf("Empty List\n");
    else{
        while(first != NULL && first->info != key)
            first = first->next;
        if(first == NULL)
            printf("Key %d not found\n", key);
        else
            printf("Node with key %d found\n", key);
    }
}