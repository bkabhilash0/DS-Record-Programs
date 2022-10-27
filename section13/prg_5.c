#include <stdio.h>
#include <stdlib.h>

// Linked Stack
typedef struct stack
{
    int data;
    struct stack *next;
} Stack;

Stack *top = NULL;
Stack *head = NULL;

void push(int e)
{
    if (head == NULL)
    {
        head = (Stack *)malloc(sizeof(Stack));
        head->data = e;
        head->next = top;
        top = head;
    }
    else
    {
        Stack *new_node = (Stack *)malloc(sizeof(Stack));
        new_node->data = e;
        new_node->next = top;
        top = new_node;
    }
    printf("Pushed Into the Stack Successfully!\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        top = top->next;
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("The Element at the top of the stack is %d\n", top->data);
    }
}

void displayStack()
{
    if (head == NULL || top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    Stack *temp = top;
    printf("The Elements in the Stack are\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int menu()
{
    printf("***********************************\n");
    printf("\tLinked Stack\n");
    printf("***********************************\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Exit\n");
    printf("Enter your Choice: ");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        printf("Enter the Element to be Pushed Into the Stack: ");
        scanf("%d", &ch);
        push(ch);
    }
    return 1;
    case 2:
        pop();
        return 1;
    case 3:
        peek();
        return 1;
    case 4:
        displayStack();
        return 1;
    case 5:
        return 0;
    default:
        printf("Enter a Vald Choice\n");
    }
}

void main()
{
    while (menu())
    {
    }
    printf("Exiting......\n");
    free(head);
    free(top);
}