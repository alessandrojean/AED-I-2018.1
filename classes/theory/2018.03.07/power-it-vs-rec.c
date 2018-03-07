#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double powerI (float base, unsigned int n) {
  double pow = 1;
  for(int i=0; i<n; i++)
    pow *= base;
  return pow;
}

double powerR (float base, unsigned int n) {
  if (n == 0)
    return 1;
  else
    return base * powerR(base, n-1);
}

double powerDC (float base, unsigned int n) {
  if (n == 0)
    return 1;
  else
    return powerDC(base * base, n/2) * ( n%2 ) ? base : 1;
}

int main (int argc, char ** argv) {
  float x; 
  unsigned int n;

  printf("Enter x e n\n");
  scanf("%f %d", &x, &n);
  printf("\nx=%f n=%d\n", x, n);

  clock_t start = clock();
  printf("Iterative power x^n= %f\n", powerI(x,n));
  clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);
  
  start = clock();
  printf("Recursive power x^n= %f\n", powerR(x,n));
  stop = clock();
  elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);

  start = clock();
  printf("Divide & conquer power x^n= %f\n", powerR(x,n));
  stop = clock();
  elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);
  
  return EXIT_SUCCESS;
}