#include<stdio.h>
int main()
{
    int x;
    printf("enter the value:");
    scanf("%d",&x);
    printf("%d", (x>9) && (x<100));
}