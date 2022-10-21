#include <stdio.h>
#include <stdlib.h>

// Circular Doubly Linked List

typedef struct node
{
    struct node *prev;
    int value;
    struct node *next;
} Node;

void insert_node(Node **head)
{
    int data;
    printf("Enter the Element to Insert: ");
    scanf("%d", &data);

    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *temp;
    new_node->value = data;

    if (*head == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;;
        *head = new_node;
    }
    else
    {
        temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        new_node->next = *head;
        new_node->next->prev = new_node;
        temp->next = new_node;
    }
    printf("Element Inserted Successfully\n");
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
        printf("%d => | %d | %d | %d |\n", t, t->prev, t->value, t->next);
        t = t->next;
        printf("----------\n");
    }while (t != node);
}

int menu(Node **head)
{
    int ch;
    printf("*************************\n");
    printf("Circular Doubly Linked List\n");
    printf("*************************\n");
    printf("1. Insert Elements\n");
    printf("2. Display Elements\n");
    printf("3. Exit\n");
    printf("*************************\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        insert_node(head);
        break;
    case 2:
        displayList((*head));
        break;
    case 3:
        return 0;
    default:
        printf("Enter a Valid Choice!\n");
    }
}

void main()
{
    Node *head;
    while (menu(&head))
        ;
}