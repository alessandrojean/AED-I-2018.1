#include <stdio.h>
#include <stdlib.h>

void printArray (int * v, int n);
void elementsMoreThanThird (int * v, int n);

int main (int argc, char ** argv) {
  int v[] = { 4, 5, 5, 7, 5, 4, 4 };
  int n = sizeof(v) / sizeof(v[0]);

  printArray(v, n);
  elementsMoreThanThird(v, n);

  return EXIT_SUCCESS;
}

/**
 * Imprime todos os elementos que aparecem
 * pelo menos n / 3 vezes no vetor v[0..n-1].
 * 
 * Utiliza o algoritmo de Tetris, com complexidade
 * O(nk), onde k = 3 neste caso.
 * 
 * Adaptado de:
 * https://bit.ly/2Jbsj9G
 **/
void elementsMoreThanThird (int * v, int n) {
  int a = 0, i, j, l, elements[2][2] = {0};

  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      if (elements[j][0] == v[i]) {
        elements[j][1]++;
      }
    }

    if (j == 2) {
      for (l = 0; l < 2; l++) {
        if (elements[l][1] == 0) {
          elements[l][0] = v[i];
          elements[l][1] = 1;
          break;
        }
      }
    }

    if (l == 2)
      for (l = 0; l < 3; l++)
        elements[l][1]--;
  }

  for (i = 0; i < 2; i++) {
    for (j = 0; j < n; j++)
      if (v[j] == elements[i][0])
        a++;

    if (a >= n / 3)
      printf("%d ", elements[i][0]);
  }

  printf("\n");
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
