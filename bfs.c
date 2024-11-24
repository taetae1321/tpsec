#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// Function to perform Breadth-First Search (BFS) using a queue
void bfs(int adj[MAX][MAX], int V, int start) {
    int queue[MAX];             // Queue for BFS
    int front = -1, rear = -1;  // Initialize front and rear pointers for queue
    bool visited[MAX] = { false }; // Track visited vertices

    // Enqueue the starting vertex
    queue[++rear] = start;
    visited[start] = true;

    while (front != rear) {  // While the queue is not empty
        int curr = queue[++front];  // Dequeue the front element

        printf("%d ", curr);  // Print the vertex

        // Enqueue all unvisited adjacent vertices
        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                queue[++rear] = i;  // Enqueue the vertex
                visited[i] = true;   // Mark it as visited
            }
        }
    }
    printf("\n");
}

int main() {
    int adj[MAX][MAX] = {0}; // Initialize adjacency matrix with 0
    int V = 5;  // Number of vertices (hardcoded)

    // Hardcoded edges
    adj[0][1] = adj[1][0] = 1; // Edge 0-1
    adj[0][2] = adj[2][0] = 1; // Edge 0-2
    adj[1][3] = adj[3][1] = 1; // Edge 1-3
    adj[1][4] = adj[4][1] = 1; // Edge 1-4
    adj[2][3] = adj[3][2] = 1; // Edge 2-3

    printf("BFS starting from vertex 0:\n");
    bfs(adj, V, 0);  // Perform BFS starting from vertex 0

    return 0;
}
