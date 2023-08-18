#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n;

bool isSafe(int **arr, int x, int y)
{
    int row, col;

    for (row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    for (row = x, col = y; row >= 0 && col >= 0; row--, col--)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
    }
    for (row = x, col = y; row >= 0 && col < n; row--, col++)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
    }

    return true;
}

bool nQueen(int **arr, int x)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col))
        {
            arr[x][col] = 1;

            if (nQueen(arr, x + 1))
            {
                return true;
            }

            arr[x][col] = 0;
        }
    }

    return false;
}

int main(void)
{
    printf("Enter the size of board: ");
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int *));

    int i, j;
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0))
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nSolution does not exist!");
    }
}
