#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int value)
{
    struct node *newnode = (struct node *)(malloc(sizeof(struct node)));

    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("%d has been pushed\n", value);
}

int pop()
{
    if (top == NULL)
    {
        printf("underflow");
    }
    int popped = top->data;
    top = top->next;
    return popped;
}
void display()
{
    printf("Elements are:\n");
    struct node *a=NULL;
    while (top!=NULL)
    {
        int v = top->data;
        printf("%d\n",v);
        top = top->next;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();
}