#include <stdio.h>
#define N 5

// Circular Queue
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int ele){
    if((rear + 1)%N == front){
        printf("Queue is Full\n");
    }else{
        printf("Enqueuing %d\n",ele);
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1) % N;
        queue[rear] = ele;
    }
}

void dequeue(){
    if(front == -1){
        printf("Queue is Empty\n");
    }else{
        printf("Dequeuing %d\n",queue[front]);
        if(front == rear){
            front = - 1;
            rear = -1;
        }else{
            front = (front + 1) % N;
        }
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}