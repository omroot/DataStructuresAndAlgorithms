#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a Min Heap
struct MinHeap {
    int* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // current number of elements in min heap
};

// Function to create a Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->heap_size = 0;
    minHeap->capacity = capacity;
    minHeap->harr = (int*) malloc(capacity * sizeof(int));
    return minHeap;
}

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree with root at given index
void MinHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->heap_size && minHeap->harr[left] < minHeap->harr[smallest])
        smallest = left;
    if (right < minHeap->heap_size && minHeap->harr[right] < minHeap->harr[smallest])
        smallest = right;
    if (smallest != idx) {
        swap(&minHeap->harr[idx], &minHeap->harr[smallest]);
        MinHeapify(minHeap, smallest);
    }
}

// Function to insert a new key to Min Heap
void insertKey(struct MinHeap* minHeap, int key) {
    if (minHeap->heap_size == minHeap->capacity) {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    // First insert the new key at the end
    int i = minHeap->heap_size++;
    minHeap->harr[i] = key;

    // Fix the min heap property if it is violated
    while (i != 0 && minHeap->harr[(i - 1) / 2] > minHeap->harr[i]) {
        swap(&minHeap->harr[i], &minHeap->harr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the root which is the minimum element
int extractMin(struct MinHeap* minHeap) {
    if (minHeap->heap_size <= 0)
        return INT_MAX;
    if (minHeap->heap_size == 1) {
        minHeap->heap_size--;
        return minHeap->harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = minHeap->harr[0];
    minHeap->harr[0] = minHeap->harr[minHeap->heap_size - 1];
    minHeap->heap_size--;
    MinHeapify(minHeap, 0);

    return root;
}

// A utility function to get minimum element from the heap
int getMin(struct MinHeap* minHeap) {
    return minHeap->harr[0];
}

// Driver program to test above functions
int main() {
    struct MinHeap* minHeap = createMinHeap(11);
    insertKey(minHeap, 3);
    insertKey(minHeap, 2);
    deleteKey(minHeap, 1);
    insertKey(minHeap, 15);
    insertKey(minHeap, 5);
    insertKey(minHeap, 4);
    insertKey(minHeap, 45);

    printf("Extracted min is %d\n", extractMin(minHeap));
    printf("Minimum element is %d\n", getMin(minHeap));
    insertKey(minHeap, 2);
    printf("Minimum element is %d\n", getMin(minHeap));

    return 0;
}