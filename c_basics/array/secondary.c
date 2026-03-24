#include <stdio.h>
int main()
{
    int i, j, k, n, sum=0;
    printf("enter the order of the matrix A ");
    scanf("%d", &n);
    printf("\n");
    int A[n][n];
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
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(i+j==n-1)
            {
                sum+=A[i][j];
            }
        }
    }
    printf("%d",sum);

    return 0;
}
