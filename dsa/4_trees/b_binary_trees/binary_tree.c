#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int value;
    struct TreeNode *left, *right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
struct TreeNode* insert(struct TreeNode* node, int value) {
    // If the tree is empty, return a new node
    if (node == NULL) return createNode(value);

    // Otherwise, recur down the tree
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    // Return the (unchanged) node pointer
    return node;
}

// Function to print the binary tree in in-order traversal
void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}


// Driver program to test above functions
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the binary tree is \n");
    inOrder(root);

    return 0;
}