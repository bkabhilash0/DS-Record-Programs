#include <stdio.h>
#include <stdlib.h>

int *a;
int n, i;

void bubbleSort()
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void selectionSort()
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }
}

void insertionSort()
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        k = a[i];
        j = i - 1;
        while (k < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

void display()
{
    int i;
    printf("[");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("]\n");
}

int menu()
{
    int ch;
    printf("Sorting Algorithms...\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n");
    printf("Enter your choice...\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        bubbleSort();
        break;
    case 2:
        selectionSort();
        break;
    case 3:
        insertionSort();
        break;
    case 4:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Enter a Valid choice...\n");
    }
}

void main()
{
    // int a[5] = {3, 2, 7, 5, 1}, n, i;
    // n = 5;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the Array Elements\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    display();
    while(menu()){
        display();
    };
}