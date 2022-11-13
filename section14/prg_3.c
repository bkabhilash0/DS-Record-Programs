#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[20];
    struct node *left;
    struct node *right;
} Node;

Node *tree = NULL;

Node *createNode(char *name)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert(Node *t, char *name)
{
    if (t == NULL)
    {
        t = createNode(name);
        return t;
    }
    if (strcmp(t->name, name) > 0)
    {
        t->left = insert(t->left, name);
    }
    else
    {
        t->right = insert(t->right, name);
    }
    return t;
}

void inorder(Node *myTree)
{
    if (myTree == NULL)
    {
        return;
    }
    inorder(myTree->left);
    printf("%s\t", myTree->name);
    inorder(myTree->right);
}

void preorder(Node *myTree){
    if(myTree == NULL){
        return;
    }
    printf("%s\t",myTree->name);
    preorder(myTree->left);
    preorder(myTree->right);
}

void postorder(Node *myTree){
    if(myTree == NULL){
        return;
    }
    postorder(myTree->left);
    postorder(myTree->right);
    printf("%s\t",myTree->name);
}

int menu(){
    printf("***********BST with Strings***********\n");
    printf("1. Insert a Name\n");
    printf("2. Inorder\n");
    printf("3. Preorder\n");
    printf("4. Postorder\n");
    printf("5. Exit\n");
    printf("Enter your Choice: ");
    int ch,l;
    char name[20];
    scanf("%d", &ch);
    switch(ch){
        case 1: {
            printf("Enter a Name (Max 20 chars): ");
            getc(stdin);
            fgets(name,20,stdin);
            l = strlen(name);
            name[l-1] = '\0';
            tree = insert(tree,name);
        }
        return 1;
        case 2: printf("Inorder Traversal\n");
                inorder(tree);
                printf("\n");
                return 1;
        case 3: printf("Preorder Traversal\n");
                preorder(tree);
                printf("\n");
                return 1;
        case 4: printf("Postorder Traversal\n");
                postorder(tree);
                printf("\n");
                return 1;
        case 5: return 0;
        default: printf("Enter a Valid Choice!\n");
    }
}

void main(){
    while(menu()){}

    printf("Exiting....");
}