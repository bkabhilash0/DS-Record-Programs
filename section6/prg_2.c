// Reverse a string using stack
#include <stdio.h>
#define N 10

char stack[N];
int top = -1;

void push(char *name)
{
    if (top == N - 1)
    {
        printf("Stack Full!\n");
        return;
    }
    while (*name != '\0')
    {
        top = top + 1;
        stack[top] = *name;
        name = name + 1;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        top = top - 1;
    }
}

void peek(){
    printf("%c", stack[top]);
}

void reverse()
{
    while (top != -1)
    {
        peek();
        pop();
    }
    printf("\n");
}

void main()
{
    char name[N];
    printf("Enter a Name: ");
    scanf("%s", name);
    push(name);
    reverse(name);
}