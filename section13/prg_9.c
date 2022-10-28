#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

void enqueue()
{
    int e;
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    printf("Enter the Element to be Enqueued: ");
    scanf("%d", &e);
    new_node->data = e;
    if (front == NULL)
    {
        new_node->next = new_node;
        front = new_node;
        rear = new_node;
    }
    else
    {
        // Change the Current rear node
        rear->next = new_node;
        rear = new_node;
        rear->next = front;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Dequeuing %d....\n", front->data);
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
    }
}

void displayQueue()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        Queue *temp = front;
        do
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int menu()
{
    printf("***********************************\n");
    printf("\tLinked Queue\n");
    printf("***********************************\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your Choice: ");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        enqueue();
        return 1;
    case 2:
        dequeue();
        return 1;
    case 3:
        displayQueue();
        return 1;
    case 4:
        return 0;
    default:
        printf("Enter a Vald Choice\n");
    }
}

void main() {
    while(menu()){}

    printf("Exiting....\n");
    free(front);
    free(rear);
}