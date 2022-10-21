#include <stdio.h>
#include <stdlib.h>

// Circular Linked List

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert_node(Node **head)
{
    int data;
    printf("Enter the Element to Insert: ");
    scanf("%d", &data);
    Node *t;
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    // Check if this is the first Node
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        t = *head;
        while (t->next != *head)
        {
            t = t->next;
        }
        t->next = new_node;
        t->next->next = *head;
    }
    printf("Insertion Successfull\n");
    printf("*****************************\n");
}

void displayList(Node *node)
{
    Node *t;
    if (node == NULL)
    {
        printf("Linked List Empty\n");
        return;
    }
    t = node;
    do
    {
        printf("----------\n");
        printf("| %d | Addr |\n", t->data);
        t = t->next;
        printf("----------\n");
    } while (t != node);
}

int menu(Node **head){
    int ch;
    printf("*************************\n");
    printf("Circular Linked List\n");
    printf("*************************\n");
    printf("1. Insert Elements\n");
    printf("2. Display Elements\n");
    printf("3. Exit\n");
    printf("*************************\n");
    printf("Enter your Choice: ");
    scanf("%d",&ch);

    switch(ch){
        case 1: insert_node(head);
                break;
        case 2: displayList((*head));
                break;
        case 3: return 0;
        default: printf("Enter a Valid Choice!\n");
    }
    
}

void main()
{
    Node *head = NULL;
    while(menu(&head)){}
}