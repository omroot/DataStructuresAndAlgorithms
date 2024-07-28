#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void InsertAtHead(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Assign data to the new node and make its next as head_ref
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;

    return;
}
void printList(struct Node* node) {
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main() {
    struct Node* head = NULL;

    InsertAtHead(&head, 1);
    InsertAtHead(&head, 2);
    InsertAtHead(&head, 3);
    InsertAtHead(&head, 4);
    InsertAtHead(&head, 5);
    
    printList(head);

    return 0;
}