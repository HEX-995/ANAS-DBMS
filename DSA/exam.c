#include <stdio.h>
#define size 5
int top=-1;
struct stack{
    int A[size-1];
    int top;
};
int full(struct stack*p){
    return (p->top==size-1);
}
void push(int value,struct stack* p){
    if(full(p)){
        printf("nahi");
    }
    p->A[++(p->top)]=value;
    
}
void pop(struct stack* p)
{
    p->top--;
}
int main()
{
    struct stack s1;
    push(12,&s1);
    pop(&s1);
}