#include <stdio.h>
#include <stdlib.h>

// Binary Search

void binarySearch(int *a, int start, int end, int key)
{
    int mid = (start + end) / 2;
    if (start > end)
    {
        printf("Element Not Found!\n");
        return;
    }
    if (a[mid] == key)
    {
        printf("Element Found at index %d\n", mid);
        return;
    }
    if (a[mid] > key)
    {
        binarySearch(a, start, mid - 1, key);
    }
    else
    {
        binarySearch(a, mid + 1, end, key);
    }
}

void sort(int *a, int n)
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

void display(int *a, int n)
{
    int i;
    printf("[");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("]\n");
}

void main()
{
    int *a, n, i,k;
    printf("Enter the size of the Array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    sort(a, n);
    display(a, n);
    printf("Enter the Element to be Searched: ");
    scanf("%d",&k);
    binarySearch(a, 0, n, 5);
}