#include <stdio.h>

void selectionSort(int A[], int n) {
	if (n == 1) return;
	int max = A[0];
	int j = 0;
	for (int i = 1; i < n - 2; i++) {
		if (A[i] > max) {
			max = A[i];
			j = i;
		}
	}
	if (max > A[n - 1]) {
		A[j] = A[n - 1];
		A[n - 1] = max;
	}
	selectionSort(A, n - 1);
}

void bubbleSort(int A[], int n) {
	if (n == 1) return;
	int max;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] > A[i + 1]) {
			max = A[i];
			A[i] = A[i + 1];
			A[i + 1] = max;
		}
	}
	bubbleSort(A, n - 1);
}

void insertionSort(int A[], int s, int n) {
	if (s == n) return;
	int min = A[s];
	for (int i = s; i > 0; i--) {
		if (A[i - 1] > min) {
			A[i] = A[i - 1];
		}
		else {
			A[i] = min;
			break;
		}
	}
	insertionSort(A, s + 1, n);
}

int main() {
	int d1[10] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	int d2[10] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	int d3[10] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	selectionSort(d1, 10);
	bubbleSort(d2, 10);
	insertionSort(d3, 1, 10);

	printf("selectionSort : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", d1[i]);
	}
	printf("\n");
	printf("bubbleSort    : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", d1[i]);
	}
	printf("\n");
	printf("insertionSort : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", d1[i]);
	}

}