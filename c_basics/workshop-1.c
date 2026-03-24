#include<stdio.h>
int main()
{
    int n,i;
    int fact=1;
    printf("enter:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    {
        printf("result=%d", fact);
    }
    return 0;
}
