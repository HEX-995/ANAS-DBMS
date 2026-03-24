#include<stdio.h>
#define max 3
struct stack{
    int top;
    int arr[max];
};
void initialize(struct stack *s){
    s->top=-1;
}
int isfull(struct stack *s)
{
    return (s->top==max-1);
}
int isempty(struct stack *s)
{
    return (s->top==-1);
}
void push(struct stack *s,int value){
    if (isfull(s)){
        printf("overflow\n");
        return;
    }
    s->arr[++(s->top)]=value;
    printf("%d\n",value);
}
void pop(struct stack *s)
{
    if(isempty(s)){
        printf("underflow");
        return;
    }
    printf("popped %d\n",s->arr[s->top]);
    (s->top)--;
}

int main()
{
    struct stack s1;
    initialize(&s1);
    push(&s1,10);
    push(&s1,20);
    push(&s1,30);
    pop(&s1);
    push(&s1,40);
    push(&s1,50);
    for (int i=0;i<4;i++){
        printf("%d\n",s1.arr[i]);
    }
}
