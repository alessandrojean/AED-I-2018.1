#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shufflingArr (int * v, int n);
void orderedArr (int * v, int n);
void orderedRevArr (int * v, int n);
void copyArr (int * from, int * to, int n);
void printArr (int * v, int n);
int selectionSort (int * v, int n);
int insertionSort (int * v, int n);

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

    printf("\n--------- Insertion Sort ---------\n");

    start = clock();
    c = insertionSort(v1, n);
    stop = clock();

    printArr(v1, n);
    printf("Comparisons: %d\n", c);
    elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n", elapsed);

    printf("\n--------- Selection Sort ---------\n");

    start = clock();
    c = selectionSort(v2, n);
    stop = clock();

    printArr(v2, n);
    printf("Comparisons: %d\n", c);
    elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n", elapsed);
  }

  printf("\n--------- Ordered Test ---------\n");
  orderedArr(v1, n);
  copyArr(v1, v2, n);
    
  printArr(v1, n);
    
  printf("\n--------- Insertion Sort 1 ---------\n");
    
  start = clock();
  c = insertionSort(v1, n);
  stop = clock();

  printArr(v1, n);
  printf("Comparisons: %d\n", c);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);

  printf("\n--------- Selection Sort ---------\n");
    
  start = clock();
  c = selectionSort(v2, n);
  stop = clock();
    
  printArr(v2, n);
  printf("Comparisons: %d\n", c);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);

  printf("\n--------- Ordered Test 2 ---------\n");
  orderedRevArr(v1, n);
  copyArr(v1, v2, n);
    
  printArr(v1, n);
    
  printf("\n--------- Insertion Sort ---------\n");
    
  start = clock();
  c = insertionSort(v1, n);
  stop = clock();

  printArr(v1, n);
  printf("Comparisons: %d\n", c);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);

  printf("\n--------- Selection Sort ---------\n");
    
  start = clock();
  c = selectionSort(v2, n);
  stop = clock();
    
  printArr(v2, n);
  printf("Comparisons: %d\n", c);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);

  return EXIT_SUCCESS;
}

void shufflingArr (int * v, int n) {
  for (int i = n - 1; i > 0; i--) {
    int r = rand() % (i + 1);  // Random int between 0...i.
    int aux = v[i];            // Swap.
    v[i] = v[r];
    v[r] = aux;
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

int selectionSort (int * v, int n) {
  int i, j, min, aux;
  long int comp = 0;
  
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (v[min] > v[j])
        min = j;
      comp++;
    }
    
    if (min != i) {
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;
    }
  }
  
  return comp;
}

int insertionSort (int * v, int n) {
  int i, j, key;
  long int comp = 0;
    
  for (i = 1; i < n; i++) {
    key = v[i];
    j = i - 1; 
    while(j>=0 && ++comp && v[j] > key) {
      v[j +1 ] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
  
  return comp;
}
