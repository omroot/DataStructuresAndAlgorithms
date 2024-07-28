#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct ListNode {
    int dest;
    struct ListNode* next;
};

// Structure to represent an adjacency list
struct List {
    struct ListNode* head;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct List* array;
};

// Function to create a new graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists. Size of array will be numVertices
    graph->array = (struct List*)malloc(numVertices * sizeof(struct List));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->dest = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->dest = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform BFS traversal of the graph starting from a given vertex
void BFS(struct Graph* graph, int startVertex) {
    // Create a boolean array to track visited vertices
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; ++i)
        visited[i] = false;

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Traverse all adjacent vertices of currentVertex
        struct ListNode* temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    // Free dynamically allocated memory
    free(visited);
    free(queue);
}

// Function to deallocate memory used by the graph
void destroyGraph(struct Graph* graph) {
    if (graph) {
        for (int i = 0; i < graph->numVertices; ++i) {
            struct ListNode* temp = graph->array[i].head;
            while (temp != NULL) {
                struct ListNode* prev = temp;
                temp = temp->next;
                free(prev);
            }
        }
        free(graph->array);
        free(graph);
    }
}

int main() {
    // Create a graph with 6 vertices
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Breadth First Traversal starting from vertex 0: ");
    BFS(graph, 0);

    // Deallocate memory used by the graph
    destroyGraph(graph);

    return 0;
}
