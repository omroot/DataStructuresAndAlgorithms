#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a priority queue
struct PriorityQueue {
    int* data; // Array of elements in priority queue
    int capacity; // Maximum possible size of priority queue
    int size; // Current number of elements in priority queue
};

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->data = (int*) malloc(capacity * sizeof(int));
    return pq;
}

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree with the root at given index
void heapify(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->data[left] < pq->data[smallest])
        smallest = left;
    if (right < pq->size && pq->data[right] < pq->data[smallest])
        smallest = right;
    if (smallest != idx) {
        swap(&pq->data[idx], &pq->data[smallest]);
        heapify(pq, smallest);
    }
}

// Function to insert a new key into the priority queue
void insert(struct PriorityQueue* pq, int key) {
    if (pq->size == pq->capacity) {
        printf("\nOverflow: Could not insert key\n");
        return;
    }

    pq->size++;
    int i = pq->size - 1;
    pq->data[i] = key;

    while (i != 0 && pq->data[(i - 1) / 2] > pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element (highest priority) from the priority queue
int extractMin(struct PriorityQueue* pq) {
    if (pq->size <= 0)
        return INT_MAX;
    if (pq->size == 1) {
        pq->size--;
        return pq->data[0];
    }

    int root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapify(pq, 0);

    return root;
}

// Function to get the minimum element from the priority queue without removing it
int getMin(struct PriorityQueue* pq) {
    if (pq->size <= 0)
        return INT_MAX;
    return pq->data[0];
}

// Driver program to test the priority queue functions
int main() {
    struct PriorityQueue* pq = createPriorityQueue(11);
    insert(pq, 3);
    insert(pq, 2);
    insert(pq, 15);
    insert(pq, 5);
    insert(pq, 4);
    insert(pq, 45);

    printf("Extracted min is %d\n", extractMin(pq));
    printf("Minimum element is %d\n", getMin(pq));
    insert(pq, 2);
    printf("Minimum element is %d\n", getMin(pq));

    return 0;
}