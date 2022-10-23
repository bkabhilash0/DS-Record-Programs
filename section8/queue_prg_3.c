#include <stdio.h>
#define N 5

int queue[N], front, rear;
front = -1;
rear = -1;

void enqueueRear(int ele)
{
    if (rear == N - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enqueuing %d\n", ele);
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = ele;
    }
}

void enqueueFront(int ele)
{
    if (rear == N - 1)
    {
        pritnf("Queue is Full\n");
    }
    else
    {
        printf("Enqueuing %d\n", ele);
        if (front == -1)
        {
            front = 0;
        }
        int i;
        for (i = rear; i >= 0; i--)
        {
            queue[i + 1] = queue[i];
        }
        queue[0] = ele;
    }
}

void dequeueFront()
{
    if (front == -1)
    {
        pritnf("Queue is Empty\n");
    }
    else
    {
        printf("Dequeing %d\n", queue[front]);
        int i;
        for (i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear = rear - 1;
        if (rear == -1)
        {
            front = -1;
        }
    }
}

void dequeueRear()
{
    if (front == -1)
    {
        pritnf("Queue is Empty\n");
    }
    else
    {
        printf("Dequeing %d\n", queue[rear]);
        rear = rear - 1;
        if (rear == -1)
        {
            front = -1;
        }
    }
}

void main(){
    
}