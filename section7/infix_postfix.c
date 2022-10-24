#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack
{
    int capacity;
    int top;
    char *data;
} Stack;

void push(Stack *stack, char ch);
void pop(Stack *stack);
void popTillBracket(Stack *stack);
void checkPrecedence(Stack *stack, char ch);
int getPrecedence(char ch);

void push(Stack *stack, char ch)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("stack Full!\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->data[stack->top] = ch;
}

void pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("stack Empty!\n");
        return;
    }
    printf("%c", stack->data[stack->top]);
    stack->top = stack->top - 1;
}

void popTillBracket(Stack *stack)
{
    if (stack->data[stack->top] != '(')
    {
        printf("%c", stack->data[stack->top]);
        stack->top = stack->top - 1;
        popTillBracket(stack);
    }
}

void checkPrecedence(Stack *stack, char ch)
{
    if (stack->top == -1)
    {
        push(stack, ch);
        return;
    }
    int curr = stack->data[stack->top];
    // printf("Elem is %c\n",ch);
    if (ch == '(' || curr == '(')
    {
        push(stack, ch);
        return;
    }
    if (ch == ')')
    {
        popTillBracket(stack);
        stack->top = stack->top - 1;
        return;
    }
    // printf("Precedence => %d\n",getPrecedence(curr) > getPrecedence(ch));
    if (getPrecedence(ch) > getPrecedence(curr))
    {
        push(stack, ch);
    }
    else
    {
        pop(stack);
        checkPrecedence(stack, ch);
    }
}

int getPrecedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void displayStack(Stack stack)
{
    int i;
    if (stack.top == -1)
    {
        return;
    }
    printf("----------\n");
    for (i = stack.top; i >= 0; i--)
    {
        printf("|\t%c\t|\n", stack.data[i]);
        printf("----------\n");
    }
}

void main()
{
    char str[] = "(A+B/C*(D+E)-F)";
    printf("Infix Form is %s\n", str);
    Stack myStack = {.top = -1};
    myStack.capacity = strlen(str);
    myStack.data = (char *)malloc(strlen(str) * sizeof(char));
    int i;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9')
        {
            printf("%c", str[i]);
        }
        else
        {
            checkPrecedence(&myStack, str[i]);
        }

        // displayStack(myStack);
    }
}