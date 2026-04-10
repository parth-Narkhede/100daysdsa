#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
    int* inDegree;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    graph->inDegree = (int*)calloc(V, sizeof(int));
    
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    graph->inDegree[dest]++;
}

void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (graph->inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int* topoOrder = (int*)malloc(V * sizeof(int));

    while (front < rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            graph->inDegree[v]--;
            
            if (graph->inDegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != V) {
        printf("Cycle detected. Topological sort not possible.\n");
    } else {
        printf("Topological Sort Order: ");
        for (int i = 0; i < V; i++) {
            printf("%d ", topoOrder[i]);
        }
        printf("\n");
    }

    free(queue);
    free(topoOrder);
}

int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    printf("--- Initializing Graph for Kahn's Algorithm ---\n");
    
    addEdge(graph, 5, 2);
    printf("Added edge: 5 -> 2\n");
    addEdge(graph, 5, 0);
    printf("Added edge: 5 -> 0\n");
    addEdge(graph, 4, 0);
    printf("Added edge: 4 -> 0\n");
    addEdge(graph, 4, 1);
    printf("Added edge: 4 -> 1\n");
    addEdge(graph, 2, 3);
    printf("Added edge: 2 -> 3\n");
    addEdge(graph, 3, 1);
    printf("Added edge: 3 -> 1\n");

    printf("\n--- Executing Kahn's Algorithm (BFS) ---\n");
    topologicalSort(graph);

    return 0;
}
