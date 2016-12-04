#include<stdio.h>
#include<stdlib.h>
int p[10][10];
void path(int i, int j)
{
	int k;
	k= p[i][j];
	if (k!=0)
	{
		path(i,k);
		printf("%d -->",k);
		path(k,j);
	}
}

int main()
{
	int a[10][10],i,j,k,n,ch;
	printf("Enter the no of nodes: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			p[i][j]=0;
		}

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(a[i][k]+a[k][j]<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
					p[i][j]=k;
				}
			}

			printf("\nShortest path between the nodes: ");
			for (i=1;i<=n;i++)
			{
				printf("\nRouting table for node %d",i);
				printf("\nTo-node distance next hop \n");
				for(j=1;j<=n;j++)
					printf("%d \t %d \t %d \n",j,a[i][j],p[i][j]);
			}
			
			do
			{
				printf("\nEnter the source and destination :\n");
				scanf("%d %d",&i,&j);
				printf("Weight is %d and Path is \n%d -->", a[i][j], i);
				
				path (i,j);
				printf("%d",j);
				printf("\nTo repeat ,Press 1\n");
				scanf("%d",&ch);
			}while(ch==1);
			
			return 0;
}