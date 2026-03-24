#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct Node *root) {
    if(root==NULL)
        return ;
    else{
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }

}
int main() {
    // Create all nodes
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->right->right = createNode(7);
    root->right->right->left = NULL;
    root->right->right->right->left = createNode(8);
    root->right->right->right->right = createNode(9);
    root->right->right->right->right->right = createNode(10);
    inorder(root);
    printf("Binary Tree created successfully!\n");

    return 0;
}