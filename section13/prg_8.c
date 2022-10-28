#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sort a Linked List of Names
typedef struct node
{
    char name[20];
    struct node *next;
} Node;

void display(Node **node);

void insert(Node **node)
{
    char name[20];
    printf("Enter the Name to be inserted into the linked List: ");
    scanf("%s", name);
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    if (*node == NULL)
    {
        *node = new_node;
    }
    else
    {
        Node *t = *node;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new_node;
    }
    printf("Element %s inserted into the linked List\n", name);
}

void display(Node **node)
{
    if (*node == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        Node *t;
        ;
        t = *node;
        while (t != NULL)
        {
            printf("%s\t", t->name);
            t = t->next;
        }
        printf("\n");
    }
}

int getNumOfNodes(Node *list)
{
    if (list == NULL)
    {
        return 0;
    }
    else if (list->next == NULL)
    {
        return 1;
    }
    else
    {
        int c = 0;
        Node *t = list;
        while (t != NULL)
        {
            c++;
            t = t->next;
        }
        return c;
    }
}

Node *swap(Node *a, Node *b)
{
    Node *tmp = b->next;
    b->next = a;
    a->next = tmp;
    return b;
}

void sort(Node **list)
{
    printf("Sorting the Linkes List\n");
    int count = getNumOfNodes(*list);
    printf("The Number of Nodes is %d\n", count);
    int i, j, swapped = 0;
    Node **h;

    for (i = 0; i <= count; i++)
    {
        h = list;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            Node *p1 = *h;
            Node *p2 = p1->next;

            if (strcmp(p1->name, p2->name) > 0)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }
        if (swapped == 0)
        {
            break;
        }
    }
    printf("Linked List Sorted Successfully\n");
}

int menu(Node **list)
{
    int ch;
    printf("*********************Linked List Bubble Sort*********************\n");
    printf("1. Insert\n2. Display\n3. Sort Using Bubble Sort\n4. Exit\n");
    printf("*****************************************************************\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        insert(list);
        return 1;
    case 2:
        display(list);
        return 1;
    case 3:
        sort(list);
        return 1;
    case 4:
        return 0;
    default:
        printf("Enter a Valid Choice!\n");
    }
}

void main()
{
    Node *list = NULL;

    while (menu(&list))
    {
    }
    printf("Exiting...\n");

    free(list);
}