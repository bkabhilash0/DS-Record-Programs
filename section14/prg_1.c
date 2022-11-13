#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert(Node *myTree, int data)
{
    if (myTree == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data < myTree->data)
        {
            myTree->left = insert(myTree->left, data);
        }
        else
        {
            myTree->right = insert(myTree->right, data);
        }
    }
    return myTree;
}

void inorder(Node *myTree){
    if(myTree == NULL){
        return;
    }
    inorder(myTree->left);
    printf("%d\t",myTree->data);
    inorder(myTree->right);
}

void preorder(Node *myTree){
    if(myTree == NULL){
        return;
    }
    printf("%d\t",myTree->data);
    preorder(myTree->left);
    preorder(myTree->right);
}

void postorder(Node *myTree){
    if(myTree == NULL){
        return;
    }
    postorder(myTree->left);
    postorder(myTree->right);
    printf("%d\t",myTree->data);
}

void main() {
    Node *tree = NULL;
    tree = insert(tree,10);
    insert(tree,50);
    insert(tree,40);
    insert(tree,30);
    insert(tree,90);
    inorder(tree);
    printf("\n");
    preorder(tree);
    printf("\n");
    postorder(tree);
    printf("\n");
    free(tree);
}