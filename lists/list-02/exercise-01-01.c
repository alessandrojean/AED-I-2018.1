#include <stdio.h>
#include <stdlib.h>

void f ();

int main (int argc, char **argv) {
  f();

  return EXIT_SUCCESS;
}

void f () {
  int x, y, z, *p, **pp;
  y = 0;
  p = &y;
  pp = &p;
  x = *p;                 // Variável x pega o valor de y, 0.
  x += 4;                 // Variável x tem o valor de 4.
  (*p)++;                 // Variável y tem o valor de 1.
  --x;                    // Variável x tem o valor de 3.
  (*p) += x;              // Variável y tem o valor de 4.
  p--;                    // Variável p agora é um dangling pointer.
  (*p) += x;              // Variável ? é incrementada com o valor de x, 3.
  p++;                    // Variável p agora aponta para y novamente.
  (**pp) += 3 * x;        // Variável y tem o valor de 13.

  printf("x = %d, y = %d, z = %d\n", y, y, z);
  printf("p = %p, *p = %d, pp = %p, **pp = %d", p, *p, pp, **pp);
}