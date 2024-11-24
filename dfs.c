#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// Function to perform Depth-First Search (DFS) using a stack
void dfs(int adj[MAX][MAX], int V, int start) {
    int stack[MAX];        // Stack for DFS
    int top = -1;          // Initialize stack as empty
    bool visited[MAX] = { false }; // Track visited vertices

    // Push the starting vertex onto the stack
    stack[++top] = start;

    while (top != -1) {  // While stack is not empty
        int curr = stack[top--]; // Pop the top element

        if (!visited[curr]) {  // If the vertex has not been visited
            printf("%d ", curr); // Print the vertex
            visited[curr] = true; // Mark it as visited
        }

        // Push all unvisited adjacent vertices onto the stack
        for (int i = V - 1; i >= 0; i--) { // Reverse order for consistent traversal
            if (adj[curr][i] == 1 && !visited[i]) {
                stack[++top] = i; // Push onto the stack
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

    printf("DFS starting from vertex 0:\n");
    dfs(adj, V, 0);  // Perform DFS starting from vertex 0

    return 0;
}