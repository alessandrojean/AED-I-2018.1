#include "stdio.h"
#include "math.h"

int a (int n) {
  int i, j, count = 0;
  for (i = n; i >= 1; i /= 2)
    for (j = 1; j <= n * n; j++) 
      count++;
  return count;
}

int main(void) {
  int n = 5;
  printf("n = %d\n", n);
  
  printf("count = %d\n", a(n));
  
  int logn2 = log(n)/log(2);
  printf("log_2(n) = %d\n", logn2);
  int i = (logn2 + 1) * n * n;
  printf("complexidade = (log_2(n) + 1) * n^2 = %d\n", i);
  return 0;
}
