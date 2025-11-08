EXPERIMENT-4
4. Implement Dijkstra‘s algorithm to compute the Shortest path through a network.
AIM: Implement Dijkstra‘s algorithm to compute the Shortest path.
DISCRIPTION:
1.	This C program implements Dijkstra’s algorithm to find the shortest paths from a source vertex to all other vertices in a weighted graph.
2.	The graph is represented using an adjacency matrix, and edge weights must be non-negative.
3.	It uses arrays to track distances, visited nodes, and the path (parent array) to reconstruct shortest routes.
4.	The program prints both the shortest distances and corresponding paths from the source to each vertex.
PROGRAM:
#include <stdio.h>
#include <limits.h>

#define V 100   // Maximum number of vertices

// Function to find the vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int n, int src, int dist[], int parent[]) {
    int visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

// Function to print the path from source to a vertex
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Function to print the shortest path and distance
void printSolution(int dist[], int parent[], int n, int src) {
    printf("Vertex\tDistance from Source\tPath");
    for (int i = 0; i < n; i++) {
        printf("\n%d -> %d\t\t%d\t\t%d", src, i, dist[i], src);
        printPath(parent, i);
    }
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    int dist[V], parent[V];

    dijkstra(graph, n, src, dist, parent);
    printSolution(dist, parent, n, src);

    return 0;
}
OUTPUT:
Enter number of vertices: 5
Enter the adjacency matrix (0 if no edge):
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Enter the source vertex: 0
Vertex  Distance from Source    Path
0 -> 0        0           0
0 -> 1        10          0 -> 1
0 -> 2        50          0 -> 3 -> 2
0 -> 3        30          0 -> 3
0 -> 4        60          0 -> 3 -> 2 -> 4
