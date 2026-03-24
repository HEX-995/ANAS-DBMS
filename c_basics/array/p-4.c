#include <stdio.h>
int main()
{
    int i, n;
    for (i = 0; i <= 10; i++)
    {
        for (n = 1; n < i + 1; n++)
        {
            printf("%d", n);
        }
        printf("\n");
    }
}