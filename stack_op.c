#include <stdio.h>
#include <stdlib.h>

// Basic Stack Operations

typedef struct stack{
    int top;
    int capacity;
    int *data;
} Struct;

void peek(Struct S);

void push(Struct *S,int element){
    if(S->top == S->capacity - 1){
        printf("Stack is Full!\n");
        return;
    }
    S->top = S->top + 1;
    S->data[S->top] = element;
}

void pop(Struct *S){
    if(S->top == -1){
        printf("Stack is Empty!\n");
        return;
    }
    peek(*S);
    S->top = S->top - 1;
}

void peek(Struct S){
    printf("%d is at the Top of the Stack\n",S.data[S.top]);
}

void main(){
    Struct myStruct = {.top= -1,.capacity=5,.data=(int*)calloc(5,sizeof(int))};
    int i;
    for(i=0;i<5;i++){
        push(&myStruct,i+1);
    }

    for(i=0;i<5;i++){
        pop(&myStruct);
    }
}