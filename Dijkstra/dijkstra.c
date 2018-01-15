#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX], int n, int startnode);
 
int main()
{
	int G[MAX][MAX], i, j, n, u;
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		{
			printf("Enter the element of row %d and column %d: ",i,j);
			scanf("%d", &G[i][j]);
		}
	}
	printf("The entered matrix is:\n");
	for(i=0;i < n;i++)\
	{
		for(j=0;j<n;j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the starting node: ");
	scanf("%d", &u);
	dijkstra(G,n,u);
	return 0;
}
 
void dijkstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX],k=0,a[MAX],s;
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
		}
	}
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
		{
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
		{
			if(!visited[i])//When not visited
			{
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
 
	for(i=0;i<n;i++)
	{
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			j=i;
			printf("\nPath = ");
			do
			{
				j=pred[j];
				a[k++]=j;//Auxiliary storage to produce right sequence
			}while(j!=startnode);
			s=k-1;
			for(k=s;k>=0;k--)
			{
				printf("%d->",a[k]);//Producing right sequence from the storage
			}
			printf("%d", i);
			k=0;
		}
	}
}
