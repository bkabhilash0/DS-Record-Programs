#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int row;
    int col;
    int value;
    struct node *next;
} Node;

void insert(Node **start, int row, int col, int value)
{
    Node *temp, *r;
    temp = *start;

    if (temp == NULL)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->row = row;
        temp->col = col;
        temp->value = value;
        temp->next = NULL;
        *start = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        r = (Node *)malloc(sizeof(Node));
        r->row = row;
        r->col = col;
        r->value = value;
        r->next = NULL;
        temp->next = r;
    }
}

void main()
{
    int arr[5][5] = {{0, 0, 3, 0, 4},
                     {0, 0, 5, 7, 0},
                     {0, 0, 0, 0, 0},
                     {0, 2, 6, 0, 0}};

    int i, j;

    printf("The Matrix is\n");
    for(i=0; i<5;i++){
        for(j= 0; j < 5; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("************************** \n");
    Node *node = NULL;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("%d\t%d\t%d\n", i, j, arr[i][j]);
                insert(&node, i, j, arr[i][j]);
            }
        }
    }
}