#include <stdio.h>
#include <stdlib.h>

// Normal Method

void main()
{
    int *arr, r, c, i, j;
    printf("Enter the No of Rows and Columns: ");
    scanf("%d %d", &r, &c);
    arr = (int *)malloc((c * r) * sizeof(int));
    for (i = 0; i < (r * c); i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i * c + j]);
        }
    }

    free(arr);
}