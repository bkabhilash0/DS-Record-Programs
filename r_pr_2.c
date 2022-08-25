// Display in reverse order
#include <stdio.h>

void print(int a[], int n)
{
    if (n == 1)
    {
        printf("%d\n", a[n - 1]);
    }
    else
    {
        printf("%d\n", a[n - 1]);
        print(a, n - 1);
    }
}

void main()
{
    int n = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr, n);
}