#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};


// Function to add a new node at the end of the list
void prepend(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Assign data to the new node and make its next as head_ref
    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;

    return;
}

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


// Function to reverse nodes in a given linked list
void RecursiveReverse(struct Node** head_ref) {
    struct Node* first;
    struct Node* rest;

    if (*head_ref == NULL) // Base case: empty list
        return;

    first = *head_ref; // Initialize first
    rest = first->next; // Initialize rest

    if (rest == NULL) // Base case: only one node
        return;

    // Recursively reverse the smaller {rest} list
    RecursiveReverse(&rest);

    // Put the first element at the end
    first->next->next = first;

    // Tricky step: fix the head pointer
    first->next = NULL;

    // Fix the head pointer to point to the new head
    *head_ref = rest;
}

// Function to print nodes in a given linked list
void printList(struct Node* node) {
    while (node != NULL) {
        // printf("Node address: %d \n", &node);
        printf("data: %d \n", node->data);
        node = node->next;
    }
}

void recursiveForwardPrint(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("data: %d \n", node->data);
    recursiveForwardPrint(node->next);
}

void recursiveReversePrint(struct Node* node) {
    if (node == NULL) {
        return;
    }
    recursiveReversePrint(node->next);
    printf("data: %d \n", node->data);

}

// Function to reverse nodes in a given linked list and return the new head
struct Node* RecursiveReverseNotInplace(struct Node* head) {
    // Base case: empty list or only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    struct Node* rest = RecursiveReverseNotInplace(head->next);

    // Put the first element at the end
    head->next->next = head;

    // Fix the head pointer
    head->next = NULL;

    // Return the new head of the reversed list
    return rest;
}


// Driver program to test above functions
int main() {
    // Start with the empty list
    struct Node* head = NULL;
    append(&head, 6);
    append(&head, 7);
    append(&head, 1);
    append(&head, 4);

    printf("Created Linked list is: \n");
    printList(head);
    printf("\n " );

    // remove 4 at the end. So linked list becomes 6->7->1->4->NULL
    removeNode(&head, 7);

    printf("Created Linked list is: \n");
    printList(head);
    printf("\n " );

    // Insert 4 at the end. So linked list becomes 6->7->1->4->NULL
    prepend(&head, 90);

    printf("Created Linked list is: \n");
    printList(head);
    printf("\n " );
    printf("Recursive print: \n");
    recursiveForwardPrint(head);
    printf("\n " );


     printf("Recursive print: \n");
    recursiveReversePrint(head);
    printf("\n " );


    printf("The list is: \n");
    printList(head);

    printf("REcurive reverse the list: \n");
    RecursiveReverse(&head);
    
    printList(head);

    printf("REcurive reverse the list not in place: \n");

    head  = RecursiveReverseNotInplace(head);
    printList(head);

    return 0;
}