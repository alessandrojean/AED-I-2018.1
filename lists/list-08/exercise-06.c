#include <stdio.h>
#include <stdlib.h>

#define MAX_COMBINATIONS 60000
#define MAX_NUMBERS 6

int ** generateNumbers (int * n);
int checkSumOfSquares (int a1, int a2, int a3, int a4, int a5, int a6);
int compareArrays (int * v, int * w, int n);
void copyArrays (int * from, int * to, int n);
void printArray (int * v, int n);

/* Insertion sort. */
void insertionSort (int * v, int n);

/* Merge sort */
void merge (int ** v, int lo, int mid, int hi);
void MergeSort (int ** v, int lo, int hi);
void mergeSort (int ** v, int n);

/* Remove duplicates */
void removeDuplicates (int ** v, int * n);

int main (int argc, char **argv) {
  printf("Gerando todas as combinações...\n");
  int n;
  int ** combinations = generateNumbers(&n);

  printf("Ordenando usando MergeSort...\n");
  mergeSort(combinations, n);

  printf("Removendo duplicados...\n");
  removeDuplicates(combinations, &n);

  for (int i = 0; i < n; i++) {
    printArray(combinations[i], MAX_NUMBERS / 2);
    printf(" ");
    printArray(combinations[i] + MAX_NUMBERS / 2, MAX_NUMBERS / 2);
    printf("\n");
  }

  for (int i = 0; i < MAX_COMBINATIONS; i++)
    free(combinations[i]);
  free(combinations);

  return EXIT_SUCCESS;
}

int ** generateNumbers (int * n) {
  int a1 = 1, a2 = 1, a3 = 1, a4 = 1, a5 = 1, a6 = 1, i = 0;
  // Allocate the matrix.
  int ** combinations = malloc(MAX_COMBINATIONS * sizeof(int *));

  while (a3 <= 20) {
    while (a6 <= 20) {
      if (a1 < a4 && checkSumOfSquares(a1, a2, a3, a4, a5, a6)) {
        // Create one temp array to check if are the same numbers.
        int v[MAX_NUMBERS] = { a1, a2, a3, a4, a5, a6 };

        int * arr = malloc(MAX_NUMBERS * sizeof(int));
        copyArrays(v, arr, MAX_NUMBERS);
        combinations[i++] = arr;
      }

      if (++a4 > 20) {
        a4 = 1;
        if (++a5 > 20) {
          a5 = 1;
          a6++;
        }
      }
    }

    if (++a1 > 20) {
      a1 = 1;
      if (++a2 > 20) {
        a2 = 1;
        a3++;
      }
    }
    a4 = a5 = a6 = 1;
  }

  *n = i;
  return combinations;
}

int checkSumOfSquares (int a1, int a2, int a3, int a4, int a5, int a6) {
  int a = ((a1 * a1) + (a2 * a2) + (a3 * a3)) == ((a4 * a4) + (a5 * a5) + (a6 * a6));
  return a;
}

void insertionSort (int * v, int n) {
  for (int i = 1; i < n; i++) {
    int key = v[i], j = i - 1;
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

int compareArrays (int * v, int * w, int n) {
  int v1[n], w1[n];
  copyArrays(v, v1, n);
  copyArrays(w, w1, n);

  insertionSort(v1, n);
  insertionSort(w1, n);

  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (v1[i] != w1[i]) {
      return (v1[i] > w1[i]) ? 1 : -1;
    }
  }

  return 0;
}

void mergeSort (int ** v, int n) {
  return MergeSort(v, 0, n - 1);
}

void MergeSort (int **v, int lo, int hi) {
  if (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    MergeSort(v, lo, mid);
    MergeSort(v, mid + 1, hi);
    merge(v, lo, mid, hi);
  }
}

void merge (int ** v, int lo, int mid, int hi) {
	int i = lo, j = mid + 1, k = 0;
	int * aux[hi - lo + 1];

	while (i <= mid && j <= hi) {
		// aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    int cmp = compareArrays(v[i], v[j], MAX_NUMBERS);
    aux[k++] = cmp <= 0 ? v[i++] : v[j++];
	}

	while (i <= mid)
		aux[k++] = v[i++];

	while (j <= hi)
		aux[k++] = v[j++];

	for (i = lo, k = 0; i <= hi; i++)
		v[i] = aux[k++];
}

void removeDuplicates (int ** v, int * n) {
  /*int * aux[*n], j = 0;
  for (int i = 0; i < *n - 1; i++) {
    if (compareArrays(v[i], v[i + 1], MAX_NUMBERS))
      aux[j++] = v[i];
  }

  aux[j++] = v[*n - 1];

  for (int i = 0; i < j; i++)
    v[i] = aux[i];

  *n = j;*/
  int r = 0;
  for (int i = 1; i < *n; i++) {
    if (compareArrays(v[r], v[i], MAX_NUMBERS) != 0) {
      v[++r] = v[i];
    }
  }
  *n = r + 1;
}

void copyArrays (int * from, int * to, int n) {
  for (int i = 0; i < n; i++)
    to[i] = from[i];
}

void printArray (int * v, int n) {
  printf("[");
  for (int i = 0; i < n; i++)
    printf("%2d%s", v[i], i < n - 1 ? ", " : "]");
}
