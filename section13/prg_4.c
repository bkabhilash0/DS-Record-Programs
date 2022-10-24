#include <stdio.h>
#include <stdlib.h>

// Two Linked List

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert_node(Node **head)
{
    int data;
    printf("Enter the Element to be Inserted: ");
    scanf("%d", &data);
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

Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
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
    switch (ch)
    {
    case 1:
        insert_node(list1);
        break;
    case 2:
        insert_node(list2);
        break;
    case 3:
        printf("Linked List 1: \n");
        displayList(list1);
        break;
    case 4:
        printf("Linked List 2: \n");
        displayList(list2);
        break;
    case 5:
        printf("Combining Two Lists...\n");
        *list3 = SortedMerge(*list1, *list2);
        // joinList((*list1), (*list2), list3);
        break;
    case 6:
        printf("Sorting Combined List....\n");
        *list3 = sortList(*list3);
        break;
    case 7:
        printf("Combined List is \n");
        displayList(list3);
        break;
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