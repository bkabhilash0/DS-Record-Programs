#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void getCofactor(int arr[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n)
{
    int row, col;
    int i = 0, j = 0;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = arr[row][col];
                if (j == n - 1)
                {
                    i++;
                    j = 0;
                }
            }
        }
    }
}

int determinantOfMatrix(int arr[SIZE][SIZE], int n)
{
    if (n == 1)
    {
        return arr[0][0];
    }

    int temp[SIZE][SIZE];
    int result = 0;

    int i, sign = 1;
    for (i = 0; i < n; i++)
    {
        getCofactor(arr, temp, 0, i, n);
        result += sign * arr[0][i] * determinantOfMatrix(temp, n - 1);
        sign = -1 * sign;
    }
    return result;
}

void main()
{
    int matrix_2[SIZE][SIZE] = {{3, -1, -2}, {0, 0, -1}, {3, -5, 0}};
    printf("Determinant is ");
    printf("%d", determinantOfMatrix(matrix_2, SIZE));
}