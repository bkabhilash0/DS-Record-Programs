// Sort the Array in Ascending Order

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void read(int arr[SIZE])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Succesfully added the Elements to the Array!\n");
}

void display(int arr[SIZE])
{
    int i;
    printf("[");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d", arr[i]);
        if (i != SIZE - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void sort(int arr[SIZE])
{
    int i, j, tmp = 0;

    display(arr);
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    display(arr);
}

void main()
{
    int i, arr[SIZE];
    printf("Enter an array of %d Elements\n", SIZE);
    read(arr);
    display(arr);
    sort(arr);
}