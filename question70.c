#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge* edges, int source) {
    int dist[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool updated = false; 
        
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                updated = true;
            }
        }
        
        if (!updated) {
            break; 
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return; 
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int n1 = 5; 
    int m1 = 8; 

    struct Edge edges1[] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int source1 = 0;

    printf("--- Test Case 1: Standard Graph ---\n");
    printf("Running Bellman-Ford on a graph with %d vertices and %d edges.\n", n1, m1);
    printf("Source vertex: %d\n", source1);
    bellmanFord(n1, m1, edges1, source1);


    int n2 = 4;
    int m2 = 4;
    
    struct Edge edges2[] = {
        {0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 1, -1} 
    };
    int source2 = 0;

    printf("\n--- Test Case 2: Graph with Negative Cycle ---\n");
    printf("Running Bellman-Ford on a graph with %d vertices and %d edges.\n", n2, m2);
    printf("Source vertex: %d\n", source2);
    bellmanFord(n2, m2, edges2, source2);

    return 0;
}
