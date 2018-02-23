#include <stdio.h>
#include <stdlib.h>

// Item a)
void trocaMin (int * i, int * j) {
  if (*i < *j) return;             // Para acessar os valores dos ponteiros,
                                   // é preciso dereferenciá-los primeiro.
  int temp;                        // temp não precisa necessariamente ser
                                   // um ponteiro, pode ser uma variável normal.
  temp = *i;                       
  *i = *j;
  *j = temp;
}

void xxx (char * v, int n, int k);

// Item b)
int main (int argc, char **argv) {
  char * a = "trem", * b = "carro";
  if (a[0] < b[0])                 // É necessário verificar a primeira posição,
                                   // e não a posição de memória onde o ponteiro aponta.
    printf("%s vem antes de %s no dicionário\n", a, b);
  else
    printf("%s vem depois de %s no dicionário\n", a, b);

  xxx(a, 4, 2);

  return EXIT_SUCCESS;
}

// Item c)
void xxx (char * v, int n, int k) {
  char * c;
  for (c = v; c < v + n; c += k)   // A variável v sempre estará sendo incrementada,
                                   // e como a condição de parada depende dela,
                                   // o loop nunca vai ter fim.
    printf("%c", *c);
}