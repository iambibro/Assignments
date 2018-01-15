#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX], int n, int startnode);
 
int main()
{
	int G[MAX][MAX], i, j, n, u;
	printf("Enter the no. of vertices: ");
	scanf("%d", &n);
    if(n < 2){
        printf("\nNumber of vertices must be >= 2!");
        return 1;
    }
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		{
			printf("Enter the element of row %d and column %d: ",(i+1),(j+1));
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
    if(u < 1 || u > n){
        printf("\nBad starting vertex : %d\nShould be between 1 and %d!", u, n);
        return 1;
    }
	dijkstra(G,n,u-1);
	return 0;
}

// Test
/*int main(){
    int G[MAX][MAX] = {{0, 1, 6, 0, 0},
                        {1, 0, 2, 3, 5},
                        {6, 2, 0, 4, 2},
                        {0, 3, 4, 0, 2},
                        {0, 5, 2, 2, 0}};
    dijkstra(G, 5, 0);
    return 0;
}*/
 
void dijkstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
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
			if(!visited[i])
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
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d from %d = %d", i+1, startnode+1, distance[i]);
			printf("\nPath = %d", i+1);
			j=i;
			do
			{
				j=pred[j];
				printf(" <- %d", j+1);
			}
			while(j!=startnode);
		}
}
