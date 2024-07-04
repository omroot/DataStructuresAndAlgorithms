#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the end of the list
void append(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref; // Used to traverse till the last node

    // Assign data to the new node and make its next as NULL
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;
    return;
}

// Function to remove a node with the given key from the list
void removeNode(struct Node** head_ref, int key) {
    // Store head node
    struct Node* temp = *head_ref, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    // as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

// Function to print nodes in a given linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    // Start with the empty list
    struct Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the end. So linked list becomes 6->7->NULL
    append(&head, 7);

    // Insert 1 at the end. So linked list becomes 6->7->1->NULL
    append(&head, 1);

    // Insert 4 at the end. So linked list becomes 6->7->1->4->NULL
    append(&head, 4);

    printf("Created Linked list is: ");
    printList(head);


    // Insert 4 at the end. So linked list becomes 6->7->1->4->NULL
    removeNode(&head, 7);

    printf("Created Linked list is: ");
    printList(head);

    return 0;
}