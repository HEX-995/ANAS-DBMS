#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*left;
    int data;
    struct node*right;
};
struct node* insert(int x,struct node*root){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if (root==NULL){
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->data=x;
        return newnode;
    }
    if(x<root->data){
        root->left= insert(x,root->left);
    }
    else{
        root->right=insert(x,root->right);
    }
    return root;
    
}
struct node*search(int x, struct node*root){
    if(x<root->data){
        search(x,root->left);
    }
    else if(x>root->data){
        search(x,root->right);
    }
    else{
        printf("found at %p",root);
        return root;
    }
    printf("not found");
    return root;
}
int main() {
    struct node* root=NULL;
    root=insert(1,root);
    insert(7,root);
    insert(2,root);
    insert(3,root);
    insert(4,root);
    insert(9,root);
    insert(6,root);
    insert(8,root);
    search(1,root);
}
