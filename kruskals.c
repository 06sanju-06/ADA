#include<stdio.h>
#define INF 9999
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    printf("\nEnter the no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }
    }
    printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
    while(ne<n)
    {
        min=INF;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("edge(%d,%d)  Cost=%d\n",a,b,min);
            mincost +=min;
            ne++;
        }
        cost[a][b]=cost[b][a]=INF;
    }
    printf("\n\tMinimum cost = %d\n",mincost);
    return 0;
}
