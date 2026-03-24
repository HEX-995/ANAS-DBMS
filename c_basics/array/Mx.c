#include <stdio.h>
int main()
{
    int i, j, k, n;
    printf("enter the order of the matrix A and matrix B: ");
    scanf("%d", &n);
    printf("\n");
    int A[n][n], B[n][n], C[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("enter the element (%d,%d): ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("enter the element (%d,%d): ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s = 0;
            for (int k = 0; k < n; k++)
            {
                s += A[i][k] * B[k][j];
                C[i][j] = s;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
