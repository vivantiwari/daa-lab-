#include <stdio.h>
#include "Program911a.c"
void read1(int a[20], int n){
	printf("Enter %d elements : ",n);
	for(int i=0; i<n; i++){
		scanf("%d ",&a[i]);
	}
}
int linearSearch(int a[20],int s, int n, int key){
	printf("\n");
	for(int i=s; i<=n; i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}
void main() {
	int a[20], n, pos, key;
	printf("Enter n value : ");
	scanf("%d", &n);
	read1(a, n);
	printf("Enter a key element : ");
	scanf("%d", &key);
	pos = linearSearch(a, 0, n - 1, key);
	if (pos == -1) {
		printf("The key element %d is not found\n", key);
	} else {
		printf("The key element %d is found at position : %d\n", key, pos);
	}
}