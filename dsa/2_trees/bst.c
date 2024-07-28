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

// Function to search for a given value in a binary search tree
struct TreeNode* search(struct TreeNode* root, int value) {
    // Base cases: root is null or value is present at root
    if (root == NULL || root->value == value)
       return root;

    // Value is greater than root's value
    if (root->value < value)
       return search(root->right, value);

    // Value is smaller than root's value
    return search(root->left, value);
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct TreeNode* node)
{
    if (node == NULL)
        return;

    // First recur on left child
    printInorder(node->left);

    // Then print the data of node
    printf("%d ", node->value);

    // Now recur on right child
    printInorder(node->right);
}


// Given a binary tree, print its nodes in pre-order
void printPreorder(struct TreeNode* node)
{
    if (node == NULL)
        return;

    // First  Visit the root node.
    printf("%d ", node->value);

    // Then Recursively perform pre-order traversal of the left subtree.
    printPreorder(node->left);
    // Now recursively perform pre-order traversal of the right subtree.
    printPreorder(node->right);
}


void printPostorder(struct TreeNode* node) {
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->value);
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
    printInorder(root);
    printf("\n");

    printf("Pre-order traversal of the binary tree is \n");
    printPreorder(root);
    printf("\n");

    printf("Post-order traversal of the binary tree is \n");
    printPostorder(root);
    printf("\n");


    struct TreeNode* searched_tree   = search( root,   20)  ;
    printf("The searched value is  %d \n",searched_tree->value );


    return 0;
}