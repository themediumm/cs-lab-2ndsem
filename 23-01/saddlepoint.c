#include <stdio.h>
#include <stdbool.h>

#define MAX 100
bool findSaddlePoint(int mat[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_row = mat[i][0], col_ind = 0;
        for (int j = 1; j < n; j++)
        {
            if (min_row > mat[i][j])
            {
                min_row = mat[i][j];
                col_ind = j;
            }
        }
        int k;
        for (k = 0; k < n; k++)

            if (min_row < mat[k][col_ind])
                break;

        if (k == n)
        {
        printf("Value of Saddle Point %d\n",min_row);
        return true;
        }
    }
    return false;
}

int main()
{
    int mat[MAX][MAX] = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    int n = 3;
    if (findSaddlePoint(mat, n) == false)
    printf("No Saddle Point ");
    return 0;
}