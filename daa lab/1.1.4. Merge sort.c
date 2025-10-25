#include <stdio.h>

void printArray(int a[],int l, int n) {
	for (int i = l; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort(int a[], int l, int m, int h) {
	int n1 = m - l + 1;
	int n2 = h - m;
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}

	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++];
	printf("Pass: ");
	for(int i=l; i<=h; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void mergesort(int a[], int low, int high, int n) {
	if (low < high) {
		int mid = (low + high) / 2;

		mergesort(a, low, mid, n);
		mergesort(a, mid + 1, high, n);
		sort(a, low, mid, high);

	}
}

int main() {
	int n;
	printf("no of elements: ");
	scanf("%d", &n);
	int a[n];
	printf("elements: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("Given array:\n");
	printArray(a, 0, n);

	mergesort(a, 0, n - 1, n);
	
	printf("Sorted array:\n");
	printArray(a, 0, n);
	
	return 0;
}