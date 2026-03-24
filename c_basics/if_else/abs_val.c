#include <stdio.h>
int main()
{
    int a1, a2, b1, b2, c1, c2;
    float m1, m2;
    printf("Enter point a:\n");
    scanf("%d %d", &a1, &a2);
    printf("Enter point b:\n");
    scanf("%d %d", &b1, &b2);
    printf("Enter point c:\n");
    scanf("%d %d", &c1, &c2);
    m1 = (b2 - a2) / (b1 - a1);
    m2 = (c2 - b2) / (c1 - b1);
    if (m1 == m2)
    {
        printf("points (%d,%d), (%d,%d) and (%d,%d) lie on the same line", a1, a2, b1, b2, c1, c2);
    }
    else
    {
        printf("points (%d,%d), (%d,%d) and (%d,%d) do not lie on the same line", a1, a2, b1, b2, c1, c2);
    }
    return 0;
}