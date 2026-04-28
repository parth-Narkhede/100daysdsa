#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, min_index;

    for(int v = 1; v <= n; v++)
    {
        if(mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int main()
{
    int n, m, u, v, w;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int parent[n + 1];
    int key[n + 1];
    int mstSet[n + 1];

    for(int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int count = 1; count <= n - 1; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for(int v = 1; v <= n; v++)
        {
            if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;

    for(int i = 2; i <= n; i++)
    {
        totalWeight += graph[i][parent[i]];
    }

    printf("Total weight of MST: %d", totalWeight);

    return 0;
}
