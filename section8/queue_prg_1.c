#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

int queue[N];
int rear = -1;

void enqueue(int ele){
    if(rear == N-1){
        printf("Queue is Full\n");
    }else{
        printf("Enqueuing %d\n", ele);
        rear = rear + 1;
        queue[rear] = ele;
    }
}

void pushElements(){
    int i;
    for(i=0;i<rear;i++){
        queue[i] = queue[i+1];
    }
}

void dequeue(){
    if(rear == -1){
        printf("Queue is Empty\n");
    }else{
        printf("Dequeuing %d\n", queue[0]);
        pushElements();
        rear =rear - 1;
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    dequeue();
    dequeue();
    dequeue();
}

