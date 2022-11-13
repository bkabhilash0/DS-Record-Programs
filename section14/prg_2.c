// BST Iterative Method
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct stack
{
    Node *node;
    struct stack *next;
} LStack;

typedef struct poststack
{
    Node *node;
    int count;
    struct poststack *next;
} Poststack;

LStack *top = NULL;
LStack *head = NULL;

Poststack *ptop = NULL;
Poststack *phead = NULL;

Node *tree = NULL;

void insert(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (tree == NULL)
    {

        tree = new_node;
    }
    else
    {

        Node *t = tree, *x = NULL;
        while (t != NULL)
        {
            x = t;
            if (data < t->data)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }
        if (data < x->data)
        {
            x->left = new_node;
        }
        else
        {
            x->right = new_node;
        }
    }
}

void push(Node *t)
{
    LStack *new_node = (LStack *)malloc(sizeof(LStack));
    new_node->node = t;
    if (head == NULL)
    {
        head = new_node;
        head->next = top;
        top = head;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

Node *pop()
{
    if (top != NULL)
    {
        Node *x = top->node;
        top = top->next;
        return x;
    }
    else
    {
        return NULL;
    }
}

void postStackPush(Node *t)
{
    Poststack *new_node = (Poststack *)malloc(sizeof(Poststack));
    new_node->node = t;
    new_node->count = 1;
    if (phead == NULL)
    {
        new_node->next = ptop;
        phead = new_node;
        ptop = phead;
    }
    else
    {
        new_node->next = ptop;
        ptop = new_node;
    }
}

Node *postStackPop()
{
    if (ptop != NULL)
    {
        Node *x = ptop->node;
        ptop = ptop->next;
        return x;
    }
    else
    {
        return NULL;
    }
}

void postOrder()
{
    if (tree == NULL)
    {
        return;
    }
    Node *current = tree;
    while (current != NULL)
    {
        postStackPush(current);
        current = current->left;
    }

    Poststack *i = ptop;
    Node *c;
    for (i = ptop; i != NULL; i = ptop)
    {
        if (i->count == 2)
        {
            c = postStackPop();
            printf("%d\t", c->data);
        }
        else
        {
            i->count = 2;
            if (i->node->right != NULL)
            {
                current = i->node->right;
                while (current != NULL)
                {
                    postStackPush(current);
                    current = current->left;
                }
            }
        }
    }
}

void inorder()
{
    if (tree == NULL)
    {
        return;
    }
    Node *current = tree;
    while (current != NULL)
    {
        push(current);
        current = current->left;
    }
    for (Node *i = pop(); i != NULL; i = pop())
    {
        current = i;
        printf("%d\t", current->data);
        if (current->right != NULL)
        {
            current = current->right;
            while (current != NULL)
            {
                push(current);
                current = current->left;
            }
        }
    }
    printf("\n");
}

void preorder()
{
    // Print and then Push to the Stack
    if (tree == NULL)
    {
        return;
    }
    Node *current = tree, *i;
    while (current != NULL)
    {
        printf("%d\t", current->data);
        push(current);
        current = current->left;
    }

    // Now Pop and check the right of the Stack
    for (i = pop(); i != NULL; i = pop())
    {
        current = i;
        if (current->right != NULL)
        {
            current = current->right;
            while (current != NULL)
            {
                printf("%d\t", current->data);
                push(current);
                current = current->left;
            }
        }
    }
    printf("\n");
}


void main()
{
    insert(20);
    insert(10);
    insert(5);
    insert(100);
    insert(50);
    insert(150);
    insert(6);
    insert(13);
    printf("Inorder\n");
    inorder();
    printf("Preorder\n");
    preorder();
    printf("Postorder\n");
    postOrder();
    free(head);
    free(top);
    free(tree);
}

// BST

/*
        20
       /  \
     10   100
    /  \  / \
   5   13 50 150
    \
     6
*/

