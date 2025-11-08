EXPERIMENT-6
DISTANCE VECTOR ROUTING:
Aim: Implement distance vector routing algorithm for obtaining routing table at each node.
Description: The program implements Distance Vector Routing Algorithm to compute shortest paths in a network. It takes the cost matrix of the network as input, where each entry represents the cost between nodes. Using iterative updates, it calculates the minimum distance and next hop for each destination node. Finally, it prints the routing table for every node, showing destination, next hop, and distance.
PROGRAM:
#include <stdio.h>
#define INF 999
#define MAX 10

struct node {
    int dist[MAX];
    int from[MAX];
} rt[MAX];

int main() {
    int costmat[MAX][MAX];
    int nodes, i, j, k, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter cost matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] = 0;
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }

    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    for (i = 0; i < nodes; i++) {
        printf("\nRouting table for Node %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n");
        for (j = 0; j < nodes; j++) {
            printf("%d\t\t%d\t\t%d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    return 0;
}
