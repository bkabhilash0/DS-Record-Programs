#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

void insert(Node **node)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (*node == NULL)
        {
            *node = (Node *)malloc(sizeof(Node));
            (*node)->value = i + 1;
        }
        else
        {
            Node *temp = *node;
            while (temp != NULL)
            {
                temp = temp->next;
            }
            temp->next = (Node *)malloc(sizeof(Node));
            temp->next->value = i + 1;
        }
    }
}

void sort(Node **head)
{
    Node *i = *head;
    Node *j = NULL;
    int temp;

    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (j->value < i->value)
            {
                temp = j->value;
                j->value = i->value;
                i->value = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void display(Node *N)
{
    while (N != NULL)
    {
        printf("%d\t", N->value);
        N = N->next;
    }
    printf("\n");
}

void reverse(Node **N){
    
}

void main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->value = 3;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->value = 1;
    head->next->next = NULL;
    // insert(&head);
    sort(&head);
    display(head);
    free(head);
}