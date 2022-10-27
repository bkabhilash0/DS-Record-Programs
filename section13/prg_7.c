#include <stdio.h>
#include <stdlib.h>

// Linked Queue
typedef struct queue
{
    int data;
    struct queue *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

void enqueue(int a)
{
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    printf("Enqueuing %d\n", a);
    new_node->data = a;
    if (front == NULL)
    {
        front = new_node;
        rear = new_node;
        front->next = NULL;
        rear->next = NULL;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        rear->next = NULL;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("No Elements in the queue!\n");
    }
    else
    {
        // Point the front to the next element in the queue
        Queue *ptr = front;
        printf("Dequeuing %d...\n", ptr->data);
        front = front->next;
        free(ptr);
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
        Queue *tmp = front;
        while (tmp != NULL)
        {
            printf("%d\t", tmp->data);
            tmp = tmp->next;
        }
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
    {
        printf("Enter the Element to be Enqueued: ");
        scanf("%d", &ch);
        enqueue(ch);
    }
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

void main(){
    while(menu()){}

    printf("Exiting....");
}