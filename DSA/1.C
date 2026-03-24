#include<stdio.h>
#include<stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist* next;
};

struct linkedlist* createnode(int value){
    struct linkedlist* newnode = (struct linkedlist*)(malloc(sizeof(struct linkedlist)));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

int main(){
    struct linkedlist* head = NULL;
    struct linkedlist* temp = NULL;

    for(int i=1 ; i<=10 ; i++){
        struct linkedlist* newnode = createnode(i*10);

        if(head == NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    while(temp != NULL){
        printf
    }
}