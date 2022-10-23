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

// Function to get cofactor of mat[p][q] in temp[][]. n is
// current dimension of mat[][]
void getCofactor(int mat[SIZE][SIZE], int temp[SIZE][SIZE], int p,
                 int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[SIZE][SIZE], int n)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];

    int temp[SIZE][SIZE]; // To store cofactors

    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

void determinant(int a[SIZE][SIZE])
{
    int i, j, result;
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
    printf("%d",determinantOfMatrix(matrix_1,SIZE));
}