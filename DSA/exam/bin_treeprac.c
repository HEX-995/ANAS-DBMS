#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(int x , struct node*root){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    if(root == NULL){
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->data = x;
        return newnode;
    }

    if(x < root->data){
        root->left = insert(x, root->left);  
    }
    else if (x > root->data){
        root->right = insert(x, root->right);
    }
    return root;
}