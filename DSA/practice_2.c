#include<stdio.h>
#define max 5
struct stack{
    int top;
    int arr[max];
};
void initialize(struct stack *s){
    s->top=-1;
}
int full(struct stack *s){
    return (s->top==max-1);
}
int empty(struct stack *s){
    return (s->top==-1);
}
void push(int value,struct stack *s){
    if (full(&s))
    {
        printf("overflow");
        return;
    }
    s->arr[++(s->top)]=value;
}
int pop(struct stack *s)
{
    if(empty(&s)){
        printf("underflow");
        return -1;
    }
    s->top--;

}
int main()
{
    struct stack s1;
    initialize(&s1);
    push(10,&s1);
    push(20,&s1);
    pop(&s1);
    display(&s1);
}