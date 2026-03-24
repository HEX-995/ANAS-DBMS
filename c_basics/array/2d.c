#include <stdio.h>

#define ROWS 3
#define COLS 4

int main()
{
    int array_2d[ROWS][COLS] = {0};

    printf("Initial 2D Array:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", array_2d[i][j]);
        }
        printf("\n");
    }

    // Modify some elements
    array_2d[0][1] = 5;
    array_2d[1][3] = 8;
    array_2d[2][0] = 3;

    // Print the modified 2D array
    printf("\nModified 2D Array:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", array_2d[i][j]);
        }
        printf("\n");
    }

    int row_index = 1, col_index = 3;
    printf("\nElement at (%d, %d): %d\n", row_index, col_index, array_2d[row_index][col_index]);

    int transposed[COLS][ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            transposed[j][i] = array_2d[i][j];
        }
    }

    printf("\nTransposed 2D Array:\n");
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}
