#include <stdio.h>
int main()
{
    int n;
    printf("Enter the value:");
    scanf("%d", &n);
    printf("enter array elements");
    int ar[n], largest = ar[0];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > largest)
        {
            largest = ar[i];
        }
    }
    printf("largest=%d", largest);
}