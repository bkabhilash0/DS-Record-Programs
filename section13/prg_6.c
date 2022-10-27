#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverse a Name Using Linked Stack
typedef struct stack
{
    char letter;
    struct stack *next;
} Stack;

Stack *head = NULL;
Stack *top = NULL;

void push(char e)
{
    if (e == '\n')
    {
        printf("Letter \\n Pushed into the Stack Successfully\n");
        return;
    }
    if (head == NULL)
    {
        head = (Stack *)malloc(sizeof(Stack));
        head->letter = e;
        head->next = top;
        top = head;
    }
    else
    {
        Stack *new_node = (Stack *)malloc(sizeof(Stack));
        new_node->letter = e;
        new_node->next = top;
        top = new_node;
    }

    printf("Letter %c Pushed into the Stack Successfully\n", e);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
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
        printf("Stack is Empty\n");
    }
    else
    {
        printf("%c", top->letter);
    }
}

void reverse(char *name)
{
    int l = strlen(name);

    // Push it to Stack
    while (*name != '\0')
    {
        push(*name);
        name = name + 1;
    }

    // Setting the Pointer to the start of the Memory
    name = name - l;

    // Peek and Pop from the Stack which is Reversing
    printf("The Reversed Word is ");
    while (top != NULL)
    {
        peek();
        pop();
    }
    printf("\n");
}

void main()
{
    char name[20];
    printf("Enter a Word to Reverse: ");
    fgets(name, 20, stdin);
    printf("The Enterted Word is \n", name);
    reverse(name);
}