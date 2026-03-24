#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node*next;
}

struct node*head=NULL;

void create(int value){
    struct node *newnode=struct node*(malloc(sizeof(struct node)));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
int main()
{

}