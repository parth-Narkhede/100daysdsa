#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
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

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void dfsHelper(struct Graph* graph, int vertex, bool visited[], int stack[], int* stackIndex) {
    visited[vertex] = true;

    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->dest;
        if (!visited[connectedVertex]) {
            dfsHelper(graph, connectedVertex, visited, stack, stackIndex);
        }
        temp = temp->next;
    }

    stack[(*stackIndex)++] = vertex;
}

void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int stack[V];
    int stackIndex = 0; 
    
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsHelper(graph, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Sort Order: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    printf("--- Directed Acyclic Graph (DAG) Initialization ---\n");
    printf("Adding edges to the graph...\n");
    
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

    printf("\n--- Executing Topological Sort using DFS ---\n");
    
    topologicalSort(graph);

    return 0;
}
