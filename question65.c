#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int n){

    visited[node] = 1;

    for(int i = 0; i < n; i++){

        if(graph[node][i]){

            if(!visited[i]){
                if(dfs(i, node, n))
                    return 1;
            }
            else if(i != parent){
                return 1;
            }
        }
    }

    return 0;
}

int hasCycle(int n){

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i, -1, n))
                return 1;
        }
    }

    return 0;
}

int main(){

    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            graph[i][j] = 0;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i=0;i<e;i++){
        int u, v;
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if(hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
