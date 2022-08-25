// Two 2D Matrix

#include <stdio.h>

#define SIZE 3

void display(int mat[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void add(int a[SIZE][SIZE], int b[SIZE][SIZE])
{
    int i, j, sum[SIZE][SIZE];

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    display(sum);
}

void subtract(int a[SIZE][SIZE], int b[SIZE][SIZE])
{
    int i, j, difference[SIZE][SIZE];

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            difference[i][j] = a[i][j] - b[i][j];
        }
    }

    display(difference);
}

void multiplication(int a[SIZE][SIZE], int b[SIZE][SIZE])
{
    int i, j, k, product[SIZE][SIZE] = {0};

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    display(product);
}

void transpose(int a[SIZE][SIZE])
{
    int i, j, result[SIZE][SIZE];

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            result[i][j] = a[j][i];
        }
    }

    display(result);
}

void determinant(int a[SIZE][SIZE]){
    int i,j,result;
}

void main()
{
    int matrix_1[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_2[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    add(matrix_1, matrix_2);
    printf("-------------------\n");
    subtract(matrix_1, matrix_2);
    printf("-------------------\n");
    multiplication(matrix_1, matrix_2);
    printf("-------------------\n");
    transpose(matrix_1);
    printf("-------------------\n");
    determinant(matrix_1);
}