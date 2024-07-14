#include<stdio.h>
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
            }
		}

    	for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
				    if((c[i][k]&&c[k][j]))
                        c[i][j] = 1;
				}
			}
		}
        printf("The Transitive Closure matrix is \n" );
        for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%4d",c[i][j]);

			}
			printf("\n");
		}
}
