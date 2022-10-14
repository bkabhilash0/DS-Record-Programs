#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    int top;;
    int capacity;
    int *data;
}Struct;

void peek(Struct *S);

void pop(Struct *S){
    if(S->top == -1){
        printf("The Stack is Empty");
        return;
    }
    peek(S);
    S->top = (S->top) - 1;
}

void push(Struct *S,char ch){
    if(S->top == S->capacity - 1){
        printf("The Stack is Full!");
        return;
    }
    S->top = S->top+1;
    S->data[S->top] = ch;
}

void peek(Struct *S){
    printf("%c",S->data[S->top]);
}

void main(){
    char str[30] = "EAS*YQUE***ST***IO*N***",ch;
    int l,i;
    Struct S = {.top = -1};
    // printf("Enter a String: ");
    // getchar();
    // gets(str);
    // scanf("%s",str);
    l = strlen(str);
    S.capacity = l;
    S.data = (int*)calloc(l,sizeof(char));
    if(S.data ==  NULL){
        printf("Memory Not Available!\n");
    }
    for(i=0;i<l;i++){
        ch = str[i];
        if(ch == '*'){
            pop(&S);
        }else{
            push(&S,ch);
        }
    }
    free(S.data);
}