#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    int V;
    Edge** head;
} Graph;

typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* array;
    int size;
    int capacity;
} MinHeap;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->head = (Edge**)malloc(V * sizeof(Edge*));
    for (int i = 0; i < V; ++i) {
        graph->head[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->head[src];
    graph->head[src] = newEdge;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int vertex, int dist) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->array = (HeapNode*)realloc(heap->array, heap->capacity * sizeof(HeapNode));
    }
    int i = heap->size++;
    heap->array[i].vertex = vertex;
    heap->array[i].dist = dist;
    while (i > 0 && heap->array[i].dist < heap->array[(i - 1) / 2].dist) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* heap) {
    if (heap->size == 0) {
        HeapNode empty = {-1, -1};
        return empty;
    }
    if (heap->size == 1) {
        return heap->array[--heap->size];
    }
    HeapNode root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    int i = 0;
    while (2 * i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (heap->array[left].dist < heap->array[smallest].dist) {
            smallest = left;
        }
        if (right < heap->size && heap->array[right].dist < heap->array[smallest].dist) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        swap(&heap->array[i], &heap->array[smallest]);
        i = smallest;
    }
    return root;
}

void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = V * 2;
    heap->size = 0;
    heap->array = (HeapNode*)malloc(heap->capacity * sizeof(HeapNode));

    push(heap, src, 0);

    while (heap->size > 0) {
        HeapNode minNode = pop(heap);
        int u = minNode.vertex;
        int d = minNode.dist;

        if (d > dist[u]) continue;

        Edge* curr = graph->head[u];
        while (curr != NULL) {
            int v = curr->dest;
            int weight = curr->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(heap, v, dist[v]);
            }
            curr = curr->next;
        }
    }

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }

    free(dist);
    free(heap->array);
    free(heap);
}

int main() {
    int V = 6;
    Graph* graph = createGraph(V);

    printf("Initializing Weighted Graph...\n");
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 3, 5, 2);
    addEdge(graph, 4, 5, 3);
    printf("Edges added successfully.\n\n");

    printf("Executing Dijkstra's Algorithm...\n");
    dijkstra(graph, 0);

    return 0;
}
