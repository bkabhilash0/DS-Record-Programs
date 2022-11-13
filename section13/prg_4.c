#include <stdio.h>
#include <stdlib.h>

// Two Linked List

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert_node(Node **head, int data)
{
    Node *t;
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    // Check if this is the first Node
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        t = *head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new_node;
    }
    printf("Insertion Successsful\n");
}

void displayList(Node **head)
{
    Node *t;
    if (*head == NULL)
    {
        printf("Linked List Empty\n");
        return;
    }
    t = *head;
    while (t != NULL)
    {
        printf("----------------\n");
        printf("| %d | %p |\n", t->data, t->next);
        t = t->next;
        printf("----------------\n");
    };
}

void joinList(Node *head, Node *tail, Node **list)
{
    Node *new_nodes = (Node *)malloc(sizeof(Node));
    if (head == NULL && tail == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        // Concat the second List beind the first List
        new_nodes = head;
        while (new_nodes->next != NULL)
        {
            new_nodes = new_nodes->next;
        }
        new_nodes->next = tail;
        printf("Last Node is %d\n", new_nodes->data);
        displayList(&new_nodes);

        // *list = new_nodes;
    }
}

Node *combine(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    else
    {
        Node *c = NULL;
        Node *t = a;
        while (t != NULL)
        {
            insert_node(&c, t->data);
            t = t->next;
        }

        t = b;
        while (t != NULL)
        {
            insert_node(&c, t->data);
            t = t->next;
        }
        return c;
    }
}

Node *sortList(Node *list)
{
    if (list == NULL)
    {
        printf("List is Empty\n");
        printf("Merge Both the List First!!\n");
        return NULL;
    }
    Node *i = list;
    Node *j = NULL;
    int temp;

    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (j->data < i->data)
            {
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return list;
}

int menu(Node **list1, Node **list2, Node **list3)
{
    int ch;
    printf("********************************\n\n");
    printf("1. Enter Element into List 1\n");
    printf("2. Enter Element into List 2\n");
    printf("3. Display Element in List 1\n");
    printf("4. Display Element in List 2\n");
    printf("5. Coimbine Both the Lists\n");
    printf("6. Sort the Combined List\n");
    printf("7. Display Combined Lists\n");
    printf("0. Exit\n");
    printf("\n*******************************\n\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);
    int data;
    switch (ch)
    {
    case 1:
        printf("Enter the Element to be Inserted: ");
        scanf("%d", &data);
        insert_node(list1, data);
        return 1;
    case 2:
        printf("Enter the Element to be Inserted: ");
        scanf("%d", &data);
        insert_node(list2,data);
        return 1;
    case 3:
        printf("Linked List 1: \n");
        displayList(list1);
        return 1;
    case 4:
        printf("Linked List 2: \n");
        displayList(list2);
        return 1;
    case 5:
        printf("Combining Two Lists...\n");
        *list3 = combine(*list1, *list2);
        return 1;
    case 6:
        printf("Sorting Combined List....\n");
        *list3 = sortList(*list3);
        return 1;
    case 7:
        printf("Combined List is \n");
        displayList(list3);
        return 1;
    case 0:
        printf("Exiting.....");
        return 0;
    default:
        printf("Enter a Valid Option\n");
    }
}

void main()
{
    Node *list_1_head = NULL;
    Node *list_2_head = NULL;
    Node *list = NULL;
    displayList(&list_1_head);
    displayList(&list_2_head);

    while (menu(&list_1_head, &list_2_head, &list))
    {
    }
}