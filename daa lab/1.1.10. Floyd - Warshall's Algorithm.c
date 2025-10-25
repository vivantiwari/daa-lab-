#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N

//write your code here..
void printMatrix(int matrix[MAX_N][MAX_N], int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if (matrix[i][j]==INF){
				printf("  INF");
			}
			else{
				printf("%5d",matrix[i][j]);
			}
		}
		printf("\n");
	}
}

void floydwarshall(int graph[MAX_N][MAX_N] ,int n){
	int dist[MAX_N][MAX_N];
	int i,j,k;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			dist[i][j]=graph[i][j];
		}
	}
	
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	printMatrix(dist,n);
}


int main(){
	int n,e;
	int graph[MAX_N][MAX_N];
	int source,dest,weight;
	
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the number of edges : ");
	scanf("%d",&e);
	int i,j;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			graph[i][j]= (i==j)?0:INF;
		}
	}
	
	for(i=0; i<e; i++){
		printf("Enter source : ");
		scanf("%d",&source);
		printf("Enter destination : ");
		scanf("%d",&dest);
		printf("Enter weight : ");
		scanf("%d",&weight);
		graph[source-1][dest-1]=weight;
	}
	
	floydwarshall(graph,n);
	
	return 0;
}