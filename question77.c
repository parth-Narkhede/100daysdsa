#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **adj, int visited[])
{
    visited[v] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, n, adj, visited);
        }
    }
}

int main()
{
    int n, m, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc((n + 1) * sizeof(int *));
    for(int i = 0; i <= n; i++)
    {
        adj[i] = (int *)malloc((n + 1) * sizeof(int));
        for(int j = 0; j <= n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int visited[n + 1];
    for(int i = 1; i <= n; i++)
        visited[i] = 0;

    dfs(1, n, adj, visited);

    int connected = 1;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if(connected)
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");

    return 0;
}
