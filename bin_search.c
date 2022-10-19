#include <stdio.h>
#include <stdlib.h>

int size = 10;
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void binary_search(int start, int end, int mid, int key)
{
    // printf("Start = %d,Mid = %d, End = %d\n", start, mid, end);
    if (end >= start)
    {
        if (arr[mid] == key)
        {
            printf("Element Found at Position %d\n", mid);
            return;
        }
        if (arr[mid] > key)
        {
            binary_search(start, mid - 1, ((start + mid - 1) / 2), key);
        }
        else
        {
            binary_search(mid + 1, end, ((end + mid + 1) / 2), key);
        }
    }
    else
    {
        printf("Element Not Found!");
    }
}

void main()
{
    int *a, n;
    printf("Enter the Size of the Array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    binary_search(0, 9, (0 + 9) / 2, 10);
}