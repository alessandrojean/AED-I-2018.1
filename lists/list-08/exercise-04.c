#include <stdio.h>
#include <stdlib.h>

void printArray (int * v, int n);
int partition (int * v, int lo, int hi);
int * largestElements (int * v, int n, int k);
void LargestElements (int * v, int lo, int hi);

int main (int argc, char **argv) {
  int v[] = { 7, 1, 3, 10, 17, 2, 21, 9 };
  int k = 3, n = sizeof(v) / sizeof(v[0]);

  printArray(v, n);

  int * largests = largestElements(v, n, k);
  printArray(v, n);
  printArray(largests, k);

  return EXIT_SUCCESS;
}

int * largestElements (int * v, int n, int k) {
  int * ret = malloc(sizeof(int) * k);
  LargestElements(v, 0, n - 1);

  for (int i = n - k, j = 0; i < n; i++, j++)
    ret[j] = v[i];

  return ret;
}

void LargestElements (int * v, int lo, int hi) {
  if (lo < hi) {
    int mid = partition(v, lo, hi);
    LargestElements(v, mid + 1, hi);
  }
}

int partition (int * v, int lo, int hi) {
  int mid = lo, i = lo + 1, key = v[lo], aux;

  for (; i <= hi; i++) {
    if (v[i] < key) {
      mid++;
      aux = v[mid];
      v[mid] = v[i];
      v[i] = aux;
    }
  }

  v[lo] = v[mid];
  v[mid] = key;

  return mid;
}

/**
 * Imprime um vetor de inteiros
 * v[0..n - 1].
 **/
void printArray (int * v, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}
