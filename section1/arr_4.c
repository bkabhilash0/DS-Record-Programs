// Search for all the occurences of an element in in array

#include <stdio.h>
#include <stdlib.h>

void read(int *arr, int n)
{
    int i;
    printf("Enter the elements of the array: ");

    for (i = 0; i < n; i++)
    {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", (arr + i));
    }
}

void display(int *arr, int n)
{
    int i;
    printf("The array is\n");

    printf("[");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void sort(int *arr, int n)
{
    int i, j, tmp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void searchOccurances(int *arr, int n)
{
    int i, c = 0;
    int prev = arr[0];

    for (i = 0; i <= n ; i++)
    {  
        if(i == n){
            printf("The element %d is repeated %d times\n", prev, c);
            break;
        }
        if (arr[i] == prev)
        {
            c++;
            continue;
        }
        else
        {
            printf("The element %d is repeated %d times\n", prev, c);
            prev = arr[i];
            c = 1;
        }
    }
}

void main()
{
    int n, *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    read(arr, n);
    display(arr, n);
    sort(arr, n);
    display(arr, n);
    searchOccurances(arr, n);

    free(arr);
}