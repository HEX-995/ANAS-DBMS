#include <stdio.h>
#define size 10
int stack[size], top = -1;
void push(int n)
{
    top++;
    if (top > size - 1)
    {
        printf("stack overflow");
        return;
    }
    stack[top] = n;
}
int pop()
{
    if (top == -1)
    {
        printf("stack underflow");
    }
    return stack[top--];
}
int main()
{
    for (int i = 1; i <= 11; i++)
    {
        push(i);
    }

    for (int i = 1; i <= 11; i++)
    {
        pop();
    }
}