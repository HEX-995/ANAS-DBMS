#include <stdio.h>
void swap(int, int);
int main()
{
    int a, b;
    swap(a, b);
    printf("enter a and b: ");
    scanf("%d %d", &a, &b);
}
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("after swapping= %d %d", a, b);
}