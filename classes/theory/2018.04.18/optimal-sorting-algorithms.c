#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shufflingArr (int * v, int n) {
	for (int i = n - 1; i > 0; i--) {
		int r = rand() % (i + 1);    // Random int between 0...i.
		int aux = v[i];
		v[i] = v[r];
		v[r] = aux;                  // Swap.
	}
}

void orderedArr (int * v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = i;
	}
}

void orderedRevArr (int * v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = n - 1 - i;
	}
}

void copyArr (int * from, int * to, int n) {
	for (int i = 0; i < n; i++) {
		to[i] = from[i];
	}
}

void printArr (int * v, int n) {
	printf("( ");
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf(" )\n");
}

/******************* MergeSort ***********************/

long int merge (int * v, int lo, int mid, int hi) {
	int i = lo, j = mid + 1, k = 0;
	int aux[hi - lo + 1];
	long int comp = 0;

	while (i <= mid && j <= hi) {
		aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
		comp++;
	}

	while (i <= mid)
		aux[k++] = v[i++];

	while (j <= hi)
		aux[k++] = v[j++];

	for (i = lo, k = 0; i <= hi; i++)
		v[i] = aux[k++];

	return comp;
}

long int MergeSort (int * v, int lo, int hi) {
	long int comp = 0;

	if (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		comp = MergeSort(v, lo, mid);
		comp += MergeSort(v, mid + 1, hi);
		comp += merge(v, lo, mid, hi);
	}

	return comp;
}

long int mergeSort (int * v, int n) {
	return MergeSort(v, 0, n - 1);
}

/******************* QuickSort ***********************/

int partition (int * v, int lo, int hi, int * comp) {
	int key = v[lo],				// Pivot element.
		mid = lo,							// Last element < key.
		i = lo + 1, aux;

	for (; i <= hi; i++) {
		if (v[i] < key) { 		// Swap with v[mid].
			mid++;
			aux = v[mid];
			v[mid] = v[i];
			v[i] = aux;
		}
		(*comp)++;
	}

	v[lo] = v[mid];
	v[mid] = key; 				// Put the key in its place.

	return mid;
}

int QuickSort (int * v, int lo, int hi) {
	int comp = 0;
	if (lo < hi) {
		int mid = partition(v, lo, hi, &comp);
		comp += QuickSort(v, lo, mid - 1);
		comp += QuickSort(v, mid + 1, hi);
	}
	return comp;
}

long int quickSort (int * v, int n) {
	return QuickSort(v, 0, n - 1);
}

// --------------------------------------------------- //
int main (int argc, char ** argv) {
	srand(time(NULL));

	int i, tests = 3, n = 30;
	int v1[n], v2[n];
	long int c;
	clock_t start, stop;
	double elapsed;

	for (i = 1; i <= tests; i++) {
		printf("\n\n************* Test %d *************\n", i);
		orderedArr(v1, n);
		shufflingArr(v1, n);
		copyArr(v1, v2, n);

		printArr(v1, n);

		printf("\n--------- mergeSort ---------\n");

		start = clock();
		c = mergeSort(v1, n);
		stop = clock();

		printArr(v1, n);
		printf("Comparisons: %d\n", c);
		elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
		printf("Time elapsed in ms: %f\n", elapsed);

		printf("\n--------- quickSort ---------\n");

		start = clock();
		c = quickSort(v2, n);
		stop = clock();

		printArr(v2, n);
		printf("Comparisons: %d\n", c);
		elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
		printf("Time elapsed in ms: %f\n", elapsed);
	}

	printf("\n--------- Ordered Test 1 ---------\n");
	orderedArr(v1, n);
	copyArr(v1, v2, n);

	printArr(v1, n);

	printf("\n--------- mergeSort  ---------\n");

	start = clock();
	c = mergeSort(v1, n);
	stop = clock();

	printArr(v1, n);
	printf("Comparisons: %d\n", c);
	elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);

	printf("\n--------- quickSort ---------\n");

	start = clock();
	c = quickSort(v2, n);
	stop = clock();

	printArr(v2, n);
	printf("Comparisons: %d\n", c);
	elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);

	printf("\n--------- Ordered Test 2 ---------\n");
	orderedRevArr(v1, n);
	copyArr(v1, v2, n);

	printArr(v1, n);

	printf("\n--------- mergeSort ---------\n");

	start = clock();
	c = mergeSort(v1, n);
	stop = clock();

	printArr(v1, n);
	printf("Comparisons: %d\n", c);
	elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);

	printf("\n--------- quickSort ---------\n");

	start = clock();
	c = quickSort(v2, n);
	stop = clock();

	printArr(v2, n);
	printf("Comparisons: %d\n", c);
	elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed in ms: %f\n", elapsed);

	return 0;
}