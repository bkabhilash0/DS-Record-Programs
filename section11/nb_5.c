#include <stdio.h>
#include <stdlib.h>

// 2D Array using array of Pointers
void main()
{
    int r = 3;
    int *arr[3], c = 4, i, j;
    for (i = 0; i < 3; i++)
    {
        arr[i] = (int *)malloc(4 * sizeof(int));
    }
    int count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);

    for (int i = 0; i < r; i++)
        free(arr[i]);
}