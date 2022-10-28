#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert(Node **head, int e)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = e;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *t = *head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new_node;
    }
}

void display(Node *node)
{
    if (node == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        Node *t;
        ;
        t = node;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
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
            insert(&c, t->data);
            t = t->next;
        }

        t = b;
        while (t != NULL)
        {
            insert(&c, t->data);
            t = t->next;
        }
        return c;
    }
}

void sort(Node **a){
    if(*a == NULL){
        printf("List is Empty (Join the Lists to Continue)\n");
    }else{
        Node *i,*j = NULL;
        i = *a;
        while(i != NULL){
            j = i->next;
            while(j != NULL){
                if(j->data < i->data){
                    int temp = j->data;
                    j->data = i->data;
                    i->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        }       
    }
}

void main()
{
    Node *list1 = NULL, *list2 = NULL, *list3 = NULL;
    insert(&list1, 10);
    insert(&list1, 40);
    insert(&list1, 20);
    insert(&list1, 30);

    display(list1);

    insert(&list2, 70);
    insert(&list2, 50);
    insert(&list2, 80);
    insert(&list2, 60);

    display(list2);

    list3 = combine(list1,list2);

    display(list3);

    sort(&list3);    

    printf("List After Sorting is...\n");
    display(list3);

    free(list1);
    free(list2);
    free(list3);
}