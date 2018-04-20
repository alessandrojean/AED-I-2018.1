#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void orderedArray (int * v, int n);
void shuffleArray (int * v, int n);
void printArray (int * v, int n);
void insertionSort (int * v, int n);
int binarySearch (int * v, int left, int right, int key);

int main (int argc, char **argv) {
  srand(time(NULL));
  int n = 10;
  int v[n];

  orderedArray(v, n);
  shuffleArray(v, n);
  printArray(v, n);

  insertionSort(v, n);
  printArray(v, n);

  return EXIT_SUCCESS;
}

void insertionSort (int * v, int n) {
  int j, key, b;
  
  for (int i = 1; i < n; i++) {
    key = v[i];
    j = i - 1;

    b = binarySearch(v, 0, j, key);
    while (j >= b) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

/**
 * Binary search to find the index on the
 * array v[left...right] where key should be inserted.
 **/
int binarySearch (int * v, int left, int right, int key) {
  if (left > right)
    return (key > v[left]) ? left + 1 : left;

  int mid = left + (right - left) / 2;

  if (v[mid] < key)
    return binarySearch(v, mid + 1, right, key);

  if (v[mid] > key)
    return binarySearch(v, left, mid - 1, key);

  return mid + 1;
}

/**
 * Gera um vetor v[0..n - 1], com
 * elementos em ordem crescente.
 **/
void orderedArray (int * v, int n) {
  for (int i = 0; i < n; i++)
    v[i] = i;
}

/**
 * Embaralha um vetor v[0..n - 1]
 **/
void shuffleArray (int * v, int n) {
  for (int i = n - 1; i > 0; i--) {
    // Gera um número randômico entre 0...i
    int r = rand() % (i + 1);
    // Efetua a troca entre r e i.
    int aux = v[i];
    v[i] = v[r];
    v[r] = aux;
  }
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
