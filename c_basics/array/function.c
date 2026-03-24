#include <stdio.h>
int main()
{
    int n, k;
    printf("enter n and k");
    scanf("%d%d", &n, &k);
    int ar[n];
    int low = 0, high = n - 1, mid = 0, pos, f = -1;
    printf("enter array elements");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ar[mid] == k)
        {
            pos = mid;
            f = 1;
            break;
        }
        else if (ar[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (f == 1)
        printf("element found at index %d", pos);
    else
        printf("element not found");
    return 0;
}