#include<stdio.h>
#define INF 9999
void main()
{
    int n,i,j,k;
    int c[9][9];
    printf("Enter no of vertices:");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&c[i][j]);
				if(i!=j && c[i][j]==0)
                    			c[i][j]=INF;
			}
		}

    	for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
				    if(c[i][j]>(c[i][k]+c[k][j]))
                        			c[i][j] = c[i][k]+c[k][j];
				}
			}
		}
        printf("The least distance matrix is \n" );
        for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%4d",c[i][j]);

			}
			printf("\n");
		}
}
