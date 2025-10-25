#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define INF 9999

typedef struct {
    int src, dest, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void union1(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compareEdges(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    if (e1->weight != e2->weight)
        return e1->weight - e2->weight;
    if (e1->src != e2->src)
        return e1->src - e2->src;
    return e1->dest - e2->dest;
}




void kruskalMST(int **cost, int V) {
    Edge *edges = (Edge *)malloc(V * V * sizeof(Edge));
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] != INF) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
	}
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
    int *parent = (int *)malloc(V * sizeof(int));
    int *rank = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int e = 0, i = 0, minCost = 0;

    while (e < V - 1 && i < edgeCount) {
        Edge next_edge = edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            printf("Edge %d:(%d, %d) cost:%d\n", e, next_edge.src, next_edge.dest, next_edge.weight);
            minCost += next_edge.weight;
            union1(parent, rank, x, y);
            e++;
		}
    }

    printf("Minimum cost= %d\n", minCost);
    free(edges);
    free(parent);
    free(rank);
}






int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}