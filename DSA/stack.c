#include <stdio.h>
#define MAX 5  

int stack[MAX], top = -1; 

int isEmpty() {
    return top == -1;
}


void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", x);
        return;
    }
    stack[++top] = x;
    printf("Pushed %d onto the stack\n", x);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;  
    }
    return stack[top--];
}


int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); 

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    
    for(top=0;top<MAX;top++){
        printf("%d\n",stack[top]);
    }

    return 0;
}
