#include<stdio.h>
#define INF 9999
void main()
{
    int n,src;
    int u=0,i,j,min;
	int c[9][9];
    int vis[9],dist[9];
	int count;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&c[i][j]);
				if(c[i][j]==0)
                    c[i][j]=INF;
			}
		}
    printf("Enter Source vertex:");
	scanf("%d",&src);

		for(j=1;j<=n;j++)
		{
			dist[j]=c[src][j];
		}
		dist[src]=0;
		vis[src]=1;
		count=1;
		while(count!=n)
        {
			min=INF;
			for(j=1;j<=n;j++)
			{
				if(dist[j]<min &&vis[j]!=1)
				{
					min=dist[j];
					u=j;
				}
			}
			vis[u]=1; count++;
			for(j=1;j<=n;j++)
			{
				if((min + c[u][j] <dist[j]) &&vis[j]!=1)
				{
					dist[j]=min+c[u][j];
				}
			}
		}
		printf("The shortest distance from:");
		for(j=1;j<=n;j++)
		{
			printf("%d ---> %d = %d \n",src,j,dist[j]);
		}
}
