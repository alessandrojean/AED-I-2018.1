#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
  int k = 0, i, j, n = 7;
   for (i = n / 2; i < n; i++)
     for (j = 1; j <= n * n; j++)
       k = k + 1;

  printf("k = %d\n", k);
  printf("k = %d\n", (n - n / 2) * (n * n));

  // Falso, pois o custo de execução é
  // O(n^3), tornando a expressão
  // n^3 >= c * n^4 falsa.

  return EXIT_SUCCESS;
}
