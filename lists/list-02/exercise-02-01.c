#include <stdio.h>
#include <stdlib.h>

void inverterVetor (int * vet, int n);
void mostrarVetor (int * vet, int n);

int main (int argc, char **argv) {
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  mostrarVetor(vet, 9);
  inverterVetor(vet, 9);
  mostrarVetor(vet, 9);

  return EXIT_SUCCESS;
}

void inverterVetor (int * vet, int n) {
  int tmp;
  for (int i = 0; i < n / 2; i++) {
    tmp = vet[i];
    vet[i] = vet[n - i - 1];
    vet[n - i - 1] = tmp;
  }
}

void mostrarVetor (int * vet, int n) {
  printf("(");
  for (int i = 0; i < n; i++) {
    printf("%d%s", vet[i], (i == n - 1) ? ")\n" : ", ");
  }
}