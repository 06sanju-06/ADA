  #include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n;
int adj[MAX][MAX];
int visited[MAX]={0};
int index;
int topo[MAX];

void toposort(int v)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] && !visited[i])
        {
            toposort(i);
        }
    }
    topo[(index)--] = v;
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    index = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposort(i);
        }
    }

    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", topo[i]);
    }
    return 0;
}
