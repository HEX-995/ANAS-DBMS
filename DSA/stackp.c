#include <stdio.h>
#define size 5
int top = -1;
struct stack
{
    int arr[size];
    int top;
};
void push(struct stack *p, int val)
{
    p->top = top + 1;
    p->arr[p->top] = val;
}
void display(struct stack *p)
{
    while (p->top != -1)
    {
        printf("%d", p->arr[p->top]);
        p->top = top - 1;
    }
}
int main()
{
    struct stack s1;
    push(&s1, 10);
    display(&s1);
}