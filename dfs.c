#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];  // Adjacency matrix
int visited[MAX];     // Visited array
int n;                // Number of vertices
int goalNode;         // Goal node

void DFS(int startVertex) {
    int stack[MAX], top = -1;  // Stack and top pointer

    stack[++top] = startVertex; // Push the start vertex onto the stack
    visited[startVertex] = 1;   // Mark the start vertex as visited

    printf("DFS traversal starting from vertex %d:\n", startVertex);

    while (top >= 0) {
        int currentVertex = stack[top--]; // Pop from the stack
        printf("%d ", currentVertex);

        // Check if we have reached the goal node
        if (currentVertex == goalNode) {
            printf("\nGoal node %d found!\n", goalNode);
            return; // Exit the DFS if goal is found
        }

        // Explore adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;  // Push adjacent unvisited vertices onto the stack
                visited[i] = 1;    // Mark as visited
            }
        }
    }
    printf("\nGoal node %d not found.\n", goalNode);
}

int main() {
    int edges, u, v;

    // Input for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input for the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Since the graph is undirected
    }

    // Input the starting vertex for DFS
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Input the goal node
    printf("Enter the goal node: ");
    scanf("%d", &goalNode);

    // Call DFS
    DFS(startVertex);

    return 0;
}
