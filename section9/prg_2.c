#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i, t;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int i, t;
    for (i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        heapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void main()
{
    // int arr[] = {12, 11, 13, 5, 6, 7};
    // int n = 6;
    int arr[] = {44, 33, 77, 11, 55, 88, 66};
    int n = 7;

    display(arr, n);
    heapsort(arr, n);
    display(arr, n);
}