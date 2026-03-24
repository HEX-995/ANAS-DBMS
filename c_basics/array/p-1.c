#include <stdio.h>
#define row 3
#define column 3
int main()
{
    int array[row][column] = {0}, sum;
    array[0][0] = 1;
    array[0][1] = 2;
    array[0][2] = 3;
    array[1][0] = 4;
    array[2][0] = 5;
    array[1][1] = 6;
    array[2][1] = 7;
    array[2][2] = 8;
    array[1][2] = 9;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            sum += array[i][j];
            printf("%d\n", sum);
        }
    }
    return 0;
}