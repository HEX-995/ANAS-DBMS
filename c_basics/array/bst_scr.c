#include <stdio.h>
int main()
{
    int arr[2][6] = {{1, 2, 3, 4, 5, 6}, {2, 3, 2, 5, 7, 3}};
    int i, c;
    int sum2, sum1 = 0, w = 0;
    for (c = -1; c < 6; ++c)
    {
        int sum2 = 0;
        for (i = 0; i < 6; i++)
        {
            if (i != c && arr[0][i] == arr[0][c])
            {

                if (arr[1][i] < arr[1][c])
                {
                    w = arr[1][i];
                }
                else
                {
                    w = arr[1][c];
                }
                sum1 += w;
            }
            sum2 += arr[1][i];
            printf("y\n");
        }
        sum2 += arr[1][c];
    }
    printf("%d", sum2);
}