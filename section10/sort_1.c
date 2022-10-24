#include <stdio.h>
#include <stdlib.h>

// Binary Search

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    // We reach here when element is not present in array
    return -1;
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
    int *a, n, i, k;
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
    scanf("%d", &k);
    int index = binarySearch(a, 0, n - 1, k);
    (index == -1) ? printf("Element is not present in array")
                  : printf("Element is present at index %d\n", index);
}