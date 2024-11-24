#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 5  // Number of nodes (A-E)

// A function to find the node with the minimum fCost
int findMinFCost(int fCost[], bool visited[]) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < N; i++) {
        if (!visited[i] && fCost[i] < min) {
            min = fCost[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// A function to print the path from start to goal
void printPath(int parent[], int goal) {
    if (parent[goal] == -1) {
        printf("%d ", goal);
        return;
    }
    printPath(parent, parent[goal]);
    printf("%d ", goal);
}

// A* search algorithm
void aStarSearch(int graph[N][N], int heuristics[N], int start, int goal) {
    int gCost[N];  // Distance from the start node to the current node
    int fCost[N];  // fCost = gCost + heuristics
    int parent[N];  // To store the path
    bool visited[N];  // To mark nodes that have already been visited

    // Initialize all nodes
    for (int i = 0; i < N; i++) {
        gCost[i] = INT_MAX;
        fCost[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    // Starting node setup
    gCost[start] = 0;
    fCost[start] = heuristics[start];

    for (int count = 0; count < N; count++) {
        int currentNode = findMinFCost(fCost, visited);

        // If no node is found with the minimum fCost
        if (currentNode == -1) {
            printf("No path found.\n");
            return;
        }

        // If we reach the goal node, print the path
        if (currentNode == goal) {
            printf("Path found: ");
            printPath(parent, goal);
            printf("\nCost: %d\n", gCost[goal]);
            return;
        }

        visited[currentNode] = true;

        // Explore the neighbors of the current node
        for (int neighbor = 0; neighbor < N; neighbor++) {
            if (graph[currentNode][neighbor] && !visited[neighbor]) {
                int tentativeGCost = gCost[currentNode] + graph[currentNode][neighbor];

                if (tentativeGCost < gCost[neighbor]) {
                    parent[neighbor] = currentNode;
                    gCost[neighbor] = tentativeGCost;
                    fCost[neighbor] = gCost[neighbor] + heuristics[neighbor];
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    // Graph represented by an adjacency matrix (undirected graph)
    int graph[N][N] = {
        {0, 1, 0, 4, 0},  // A
        {1, 0, 3, 0, 0},  // B
        {0, 3, 0, 0, 2},  // C
        {4, 0, 0, 0, 5},  // D
        {0, 0, 2, 5, 0}   // E
    };

    // Heuristic values for each node (estimated cost to goal E)
    int heuristics[N] = {6, 4, 2, 3, 0};  // Goal is E (node 4)

    int start = 0;  // Starting node (A)
    int goal = 4;   // Goal node (E)

    aStarSearch(graph, heuristics, start, goal);

    return 0;
}
