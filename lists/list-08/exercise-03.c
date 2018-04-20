#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void orderedArray (int * v, int n);
void shuffleArray (int * v, int n);
void printArray (int * v, int n);
void merge (int * v, int lo, int mid, int hi);
void MergeSort (int * v, int lo, int hi);
void mergeSort (int * v, int n);

int main (int argc, char **argv) {
  srand(time(NULL));
  int n = 8;
  int v[n];

  orderedArray(v, n);
  shuffleArray(v, n);
  printArray(v, n);

  mergeSort(v, n);
  printArray(v, n);

  return EXIT_SUCCESS;
}

/**
 * Ordena em ordem crescente o vetor 
 * v utilizando o algoritmo MergeSort.
 **/
void mergeSort (int * v, int n) {
  return MergeSort(v, 0, n - 1);
}

/**
 * Efetua o algoritmo de ordenação
 * MergeSort no vetor v[lo..hi].
 **/
void MergeSort (int * v, int lo, int hi) {
  if (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    MergeSort(v, lo, mid);
    MergeSort(v, mid + 1, hi);
    merge(v, lo, mid, hi);
  }
}

/**
 * Dado dois sub-vetores [lo..mid] e [mid + 1..hi]
 * ordenados de um vetor v, faz a intercalação
 * destes em v, gerando um vetor [lo..hi] ordenado.
 * 
 * Variante que utiliza apenas metade do tamanho do
 * vetor original para o auxiliar.
 **/
void merge (int * v, int lo, int mid, int hi) {
  int i = 0, j = mid + 1, k = lo, n = (hi - lo) / 2 + 1;
  int aux[n];

  // Copia o primeiro sub-vetor para o temporário.
  while (k <= mid)
    aux[i++] = v[k++];

  i = 0;
  k = lo;

  while (i < n && j <= hi) {
    v[k++] = (aux[i] <= v[j]) ? aux[i++] : v[j++];
  }

  while (i < n)
    v[k++] = aux[i++];
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
