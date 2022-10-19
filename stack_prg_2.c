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

int getPrecedence(char ch);

Stack charStack = {.top = -1};
int result = 0;

// Expression Evaluation Using Stack

void calc(char ch)
{
    int top = charStack.top;
    int o1 = (int)charStack.data[top];
    if(result == 0){
        result = o1;
    }
    int o2 = (int)charStack.data[top - 1];
    charStack.top = charStack.top - 2;

    switch (ch)
    {
    case '+':
        result = result + o1;
        return;
    case '-':
        result = result - o1;
    }
}

void pushOperator(Stack *stack, char op)
{
    stack->top = stack->top + 1;
    stack->data[stack->top] = op;
}

void popOperator(Stack *stack)
{
    if (stack->top > -1)
    {
        printf("%c", stack->data[stack->top]);
        stack->top = stack->top - 1;
    }
}

void popTillBracket(Stack *stack)
{
    int top = stack->top;
    char curr = stack->data[top];
    if (curr != '(')
    {
        printf("%c", curr);
        stack->top = stack->top - 1;
        popTillBracket(stack);
    }
}

void pushOperand(Stack *stack, char opnd)
{
    stack->top = stack->top + 1;
    stack->data[stack->top] = opnd;
}

void popOperand(Stack *stack)
{
    if (stack->top > -1)
    {
        printf("%c", stack->data[stack->top]);
        stack->top = stack->top - 1;
    }
}

void checkPrecedence(Stack *stack, char ch)
{
    int top = stack->top;
    char current = stack->data[stack->top];
    if (top == -1 || ch == '(' || current == '(')
    {
        pushOperator(stack, ch);
        return;
    }
    if (ch == ')')
    {
        popTillBracket(stack);
        stack->top = stack->top - 1;
        return;
    }
    if (getPrecedence(ch) > getPrecedence(current))
    {
        printf("Pushing %c\n", ch);
        pushOperator(stack, ch);
    }
    else
    {
        // printf("%c", current);
        popOperator(stack);
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

void popAll(Stack *stack)
{
    int top = stack->top;
    int i;
    for (i = top; i > -1; i--)
    {
        printf("%c", stack->data[i]);
    }
}

void display(Stack *stack)
{
    int i, top = stack->top;
    int current = stack->data[top];
    printf("-----------\n");
    for (i = top; i >= 0; i--)
    {
        printf("|\t%c\t|\n", stack->data[i]);
        printf("-----------\n");
    }
}

void main()
{
    char xp[] = "1+(5*2)-2";
    int l = strlen(xp);
    Stack symStack = {.top = -1, .capacity = l};
    symStack.data = (char *)malloc(l * sizeof(char));

    charStack.capacity = l;
    charStack.data = (char *)malloc(l * sizeof(char));

    int i;
    char ch;
    for (i = 0; i < l; i++)
    {
        ch = xp[i];
        if (isdigit(ch))
        {
            pushOperand(&charStack, ch);
        }
        else
        {
            checkPrecedence(&symStack, ch);
        }
        // display(&symStack);
        display(&charStack);
    }
    popAll(&symStack);
}