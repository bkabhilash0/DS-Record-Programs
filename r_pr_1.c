// Print array elements in order
#include <stdio.h>

void print(int a[], int start, int n)
{
    if (start == n - 1)
    {
        printf("%d\n", a[start]);
    }
    else
    {
        printf("%d\n", a[start]);
        print(a, start + 1, n);
    }
}

void main()
{
    int n = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr, 0, n);
}