#include "stdio.h"
#include "math.h"

int b (int n) {
  int i, j, k, count = 0;
  for (i = n / 2; i <= n; i++)
    for (j = 1; j <= n; j *= 2)
      for (k = 1; k <= n; k *= 2)
        count++;
  return count;
}

int main(void) {
  int n = 10;
  printf("n = %d\n", n);
  
  printf("count = %d\n", b(n));
  
  int logn2 = log(n)/log(2);
  int i = ((n + 3) / 2) * (logn2 + 1) * (logn2 + 1);
  printf("complexidade = (n+3)/2 * (log_2(n) + 1)^2 = %d\n", i);
  
  return 0;
}
