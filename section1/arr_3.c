#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int getChoice()
{
    int ch;
    printf("Enter your Choice\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Sort\n");
    printf("5. Display Array\n");
    printf("6. Exit\n");

    printf("> ");
    scanf("%d", &ch);
    return ch;
}

void insertElements(int *pointer,int *arr,int n)
{
    int i;
    if (*pointer == -1)
    {
        printf("Enter the Limit of the Array: ");
        scanf("%d", &n);
        arr = (int *)calloc(n, sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d Element ", i + 1);
        *pointer = *pointer + 1;
        scanf("%d", (arr+i));
    }
    printf("Successfully Added Elements into the Array!\n");
}

void search(int n,int *arr)
{
    int key;
    printf("Enter the Element to be found: ");
    scanf("%d", &key);
    int i = 0;
    _Bool isFound = 0;
    for (i = 0; i < n; i++)
    {
        printf("Search => %d\n", arr[i]);
        if (arr[i] == key)
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
    {
        printf("The Element %d is found at position %d\n", key, i + 1);
    }
    else
    {
        printf("The Element %d is not found in the array!\n", key);
    }
}

void deleteIndex(int *pointer,int n,int *arr)
{
    int index, i;
    printf("Enter an Index between 0 and %d\n", *pointer + 1);
    scanf("%d", &index);
    if (index < 0 || index > *pointer)
    {
        printf("Out of Bound - Enter a Value in the range!\n");
    }
    else
    {
        for (i = index + 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        *pointer--;
    }
}

void sort(int pointer,int *arr)
{
    int i, j, tmp;
    for (i = 0; i < pointer + 1; i++)
    {
        for (j = 0; j < pointer - i; j++)
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

void main()
{
    int pointer = -1;
    int n = 5;
    int *arr;
    int ch;
    for (ch = getChoice(); ch != 6; ch = getChoice())
    {
        printf("Array Strength => %d out of %d\n", pointer + 1, SIZE);
        switch (ch)
        {
        case 1:
        {
            if (pointer == (n - 1))
            {
                int c, new_size;
                printf("Array is Full!\n");
                printf("Do you want to add More Elements ?");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &c);
                if (c == 1)
                {
                    printf("Enter the size to extend:");
                    scanf("%d", &new_size);
                    realloc(arr, n + new_size);
                }
            }
            else
            {
                insertElements(&pointer,arr,n);
            }
        }
        break;
        case 2:
            search(n,arr);
            break;
        case 3:
            deleteIndex(&pointer,n,arr);
            break;
        case 4:
            sort(pointer,arr);
            break;
        case 5:
        {
            int i;
            printf("[");
            for (i = 0; i < pointer + 1; i++)
            {
                printf("%d,", arr[i]);
            }
            printf("]\n");
        }
        break;
        default:
            continue;
        }
    }
    free(arr);
}
