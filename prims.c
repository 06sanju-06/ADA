#include <stdio.h>

#define MAX 100
#define INF 9999
int n,i,j;
int c[MAX][MAX];

void solvePrims()
{
    int i,j,u, v, min;
    int ne = 0, mincost = 0;
    int visit[MAX] = {0}; // To represent the set of vertices included in MST
    visit[1] = 1; // Start from vertex 1

    while (ne != n - 1)
    {
        min = INF;
        u = 0;
        v = 0;
        for (i = 1; i <=n; i++)
        {
            if (visit[i] == 1)
            {
                for (j = 1; j <=n; j++)
                {
                    if (c[i][j] < min && visit[j] == 0)
                    {
                        min = c[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (v != 0)
        { // Check if a valid edge was found
            printf("edge(%d,%d)  Cost=%d\n", u, v, min);
            visit[v] = 1; // Include vertex v in the MST
            ne++;
            mincost += min;
        }

        c[u][v] = c[v][u] = INF; // Mark the edge u-v as processed
    }

    printf("\nMinimum cost = %d\n", mincost);
}

void read()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0)
            {
                c[i][j] = INF;
            }
        }
    }
}
int main()
{
    read();
    printf("The Spanning Tree is:\n");
    solvePrims();
    return 0;
}
