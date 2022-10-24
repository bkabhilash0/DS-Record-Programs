#include <stdio.h>
#include <stdlib.h>

// Basic Stack Operations

typedef struct stack
{
    int top;
    int capacity;
    int *data;
} Struct;

Struct myStruct = {.top = -1, .capacity = 5};
Struct *S = &myStruct;

void peek();

void push()
{
    int element;
    printf("Enter to Element to Push: ");
    scanf("%d", &element);
    if (S->top == S->capacity - 1)
    {
        printf("Stack is Full!\n");
        return;
    }
    S->top = S->top + 1;
    S->data[S->top] = element;
}

void pop()
{
    if (S->top == -1)
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Poping From Stack...\n");
    peek(*S);
    S->top = S->top - 1;
}

void peek()
{
    printf("%d is at the Top of the Stack\n", S->data[S->top]);
}

int menu()
{
    int ch;
    printf("******************Stack*******************\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        printf("Exiting...\n");
        return 0;
        break;
    defualt:
        printf("Enter a Valid Choice!\n");
    }
}

void main()
{
    int i;
    myStruct.data = (int *)calloc(5, sizeof(int));
    while(menu()){}
}