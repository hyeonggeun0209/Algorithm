#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 100000
int B[MAX_SIZE];

void merge(int A[], int p, int q, int r) {
	int i = p; int j = q + 1;
	int k = p; int n;
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	if (i > q) {
		for (n = j; n <= r; n++) {
			B[k++] = A[n];
		}
	}
	else {
		for (n = i; n <= q; n++) {
			B[k++] = A[n];
		}
	}

	for (n = p; n <= r; n++) {
		A[n] = B[n];
	}
}
void mergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	int n;
	for (int j = p; j < r; j++) {
		if (A[j] < x) {
			i++;
			n = A[i];
			A[i] = A[j];
			A[j] = n;
		}
	}
	n = A[i + 1];
	A[i + 1] = A[r];
	A[r] = n;
	return i + 1;
}
void quickSort(int A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main() {
	time_t start, end;
	float gap1,gap2;
	srand((unsigned)time(0));
	int mergeInput[MAX_SIZE], quickInput[MAX_SIZE];
	for (int i = 0; i < 10; i++) {
		quickInput[i] = mergeInput[i] = rand();
	}
	mergeSort(mergeInput, 0, 9);
	quickSort(quickInput, 0, 9);

	printf("Merge Sort: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", mergeInput[i]);
	}

	printf("\nQuick Sort: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", quickInput[i]);
	}

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < MAX_SIZE; i++) {
			quickInput[i] = mergeInput[i] = rand();
		}

		start = clock();
		mergeSort(mergeInput, 0, MAX_SIZE - 1);
		end = clock();
		gap1 = (float)(end - start) / (CLOCKS_PER_SEC);

		start = clock();
		quickSort(quickInput, 0, MAX_SIZE - 1);
		end = clock();
		gap2 = (float)(end - start) / (CLOCKS_PER_SEC);

		printf("\nMerge Sort: %fsec Quick Sort: %fsec", gap1, gap2);
	}
}