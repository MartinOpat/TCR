#include "header.h"
void printArray(int p[], int n) {
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
}

void printAllUniqueParts(int n) {
	int p[n];	// array to store a partition
	int k = 0;	// idx of last element in a partition
	p[k] = n;

	// The loop stops when the current partition has all 1s
	while (true) {
		printArray(p, k + 1);
		int rem_val = 0;
		while (k >= 0 && p[k] == 1) {
			rem_val += p[k];
			k--;
		}
		// no more partitions
		if (k < 0) return;

		p[k]--;
		rem_val++;

		// sorted order is violated (fix)
		while (rem_val > p[k]) {
			p[k + 1] = p[k];
			rem_val = rem_val - p[k];
			k++;
		}

		p[k + 1] = rem_val;
		k++;
	}
}
