#include <stdio.h>
#define MAX_N 200000

int price[MAX_N];
int total = 0;
int N = 0;

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

void countPrice(int p, int r) {
	quickSort(price, p, r);
	int a = N % 3;
	for (int i = 0; i < N; i++) {
		if (i % 3 == a)
			continue;
		else
			total += price[i];
	}
}

int main() {
	int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		total = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &price[j]);

		}
		countPrice(0, N - 1);
		printf("%d\n", total);
	}
}
