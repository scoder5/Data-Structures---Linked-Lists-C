//Construction of Binary Search Tree and the Three Traversals.
#include<stdio.h>
#include<stdlib.h>

//Representation of a node in Doubly Linked List
typedef struct node{
    int info;
    struct node *lchild, *rchild;
}NODE;

//Insert function
NODE *Insert(NODE *root, int data){
    NODE *newnode, *temp, *parent;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->lchild = newnode->rchild = NULL;
    if(root == NULL)
        root = newnode;
    else{
        temp = root;
        while(temp != NULL){
            parent = temp;
            if(data > temp->info)
                temp = temp->rchild;
            else if(data < temp->info)
                temp = temp->lchild;
            else{
                printf("Data %d already exists in the tree\n", data);
                return root;
            }
        }
        if(data > parent->info)
            parent->rchild = newnode;
        else
            parent->lchild = newnode;
    }
    printf("Node with data %d is inserted into the BST\n", data);
    return root;
}

//Inorder Traversal
void Inorder(NODE *root){
    if(root == NULL)
        return;
    Inorder(root->lchild);
    printf("%d \n", root->info);
    Inorder(root->rchild);
}

//Preorder Traversal
void Preorder(NODE *root){
    if(root == NULL)
        return;
    printf("%d \n", root->info);
    Preorder(root->lchild);
    Preorder(root->rchild);
}

//Postorder Traversal
void Postorder(NODE *root){
    if(root == NULL)
        return;
    Postorder(root->lchild);
    Postorder(root->rchild);
    printf("%d \n", root->info);
}

//Main function
int main(){
    int choice, data;
    NODE *root = NULL;
    while(1){
        printf("1:Insert\n2:Inorder\n3:Preorder\n4:Postorder\n5:Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter the data\n");
                     scanf("%d", &data);
                     root = Insert(root, data);
                     break;
            case 2 : printf("Inorder Traversal\n");
                     Inorder(root);
                     break;
            case 3 : printf("Preorder Traversal\n");
                     Preorder(root);
                     break;
            case 4 : printf("Postorder Traversal\n");
                     Postorder(root);
                     break;
            case 5 : exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}