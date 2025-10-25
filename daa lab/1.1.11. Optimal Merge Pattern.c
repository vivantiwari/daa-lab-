#include <stdio.h>
#include <stdlib.h>

// Function to Sort the files in ascending order, perform optimal file merging and return the minimum cost
int optimalMerge(int files[], int n) {
    
    // write your code here
	int cost=0;
	while (n>1){
		int i,j,temp;
		for(i=n-1; i>0; i--){
			for(j=0; j<i; j++){
				if(files[j]>files[j+1]){
					temp=files[j];
					files[j]=files[j+1];
					files[j+1]=temp;
				}
			}
		}
		int merged=files[0]+files[1];
		cost+=merged;
		files[0]=merged;
		for(i=1; i<n-1; i++){
			files[i]=files[i+1];
		}
		n--;
	}
	return cost;
}

int main() {
    int n;
    printf("Number of files: ");
    scanf("%d", &n);
    int *files = (int *)malloc(n * sizeof(int));
    printf("Enter the sizes of %d files: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }
    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging is: %d\n", minCost);
    free(files);
    return 0;
}
