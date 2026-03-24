#include <stdio.h>
#include <math.h>
void swapv(int *, int *);
int main()
{
    int a = 5, b = 10;
    swapv(&a, &b);
    printf("a=%d, b=%d\n", a, b);
}
void swapv(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("a=%d, b=%d\n", *a, *b);
}