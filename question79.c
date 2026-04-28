#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

struct HeapNode {
    int v, dist;
};

struct Heap {
    int size;
    struct HeapNode arr[MAX * MAX];
};

void swap(struct HeapNode* a, struct HeapNode* b)
{
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct Heap* h, int i)
{
    while(i > 0 && h->arr[(i - 1)/2].dist > h->arr[i].dist)
    {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(struct Heap* h, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;

    if(r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if(smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct Heap* h, int v, int dist)
{
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct Heap* h)
{
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

void addEdge(int u, int v, int w)
{
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->v = v;
    n1->w = w;
    n1->next = adj[u];
    adj[u] = n1;

    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->v = u;
    n2->w = w;
    n2->next = adj[v];
    adj[v] = n2;
}

int main()
{
    int n, m, u, v, w, source;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("Enter source: ");
    scanf("%d", &source);

    int dist[n + 1];
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct Heap h;
    h.size = 0;

    dist[source] = 0;
    push(&h, source, 0);

    while(h.size > 0)
    {
        struct HeapNode node = pop(&h);
        int u = node.v;

        for(struct Node* temp = adj[u]; temp != NULL; temp = temp->next)
        {
            int v = temp->v;
            int wt = temp->w;

            if(dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                push(&h, v, dist[v]);
            }
        }
    }

    printf("Distances: ");
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}
