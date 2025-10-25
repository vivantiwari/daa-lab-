#include <stdio.h>
#include "Program912a.c"
void main() {
	int a[20], n, key, flag;
	printf("Enter value of n : ");
	scanf("%d", &n);
	read1(a, n);
	bubbleSort(a, n);
	printf("After sorting the elements are : ");
	display(a, n);
	printf("Enter key element : ");
	scanf("%d", &key);
	flag = binarySearch(a, 0, n - 1, key);
	if (flag == -1) {
		printf("The given key element %d is not found\n", key);
	} else {
		printf("The given key element %d is found at position : %d\n", key, flag);
	}
}
void read1(int a[20], int n){
	printf("Enter %d elements : ",n);
	for(int i=0; i<n; i++){
		scanf("%d ",&a[i]);
	}
}
void display(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void bubbleSort(int a[20], int n){
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int binarySearch(int a[], int s, int n, int key){
	printf("\n");
	int low=s;
	int high=n;
	int mid=(low+high)/2;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}