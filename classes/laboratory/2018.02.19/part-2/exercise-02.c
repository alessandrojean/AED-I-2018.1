#include <stdlib.h>
#include <stdio.h>

void lerVetor (float * vet, int n);
float produto (float * vet, int n);
float soma (float * vet, int n);

int main (int argc, char **argv) {
  int n, m;
  scanf("%d %d", &n, &m);
  float seqA[n], seqB[m];

  // Leitura das sequências.
  lerVetor(seqA, n);
  lerVetor(seqB, m);

  int max = n > m ? m : n;
  int comparador = -1;
  for (int i = 0; i < max; i++) {
    comparador = (seqA[i] == seqB[i])
      ? -1
      : seqA[i] > seqB[i];

    if (comparador >= 0) {
      break;
    }
  }

  if (comparador == -1 && n == m) {
    printf("As sequências são iguais.\n");
    printf("Soma de A: %.1f\nSoma de B: %.1f\n", soma(seqA, n), soma (seqB, m));
    printf("Produto de A: %.1f\nProduto de B: %.1f\n", produto(seqA, n), produto(seqB, m));
  } else if (comparador) {
    printf("A sequência A é maior que a B.\n");
    printf("Soma de A: %.1f\n", soma(seqA, n));
    printf("Produto de B: %.1f\n", produto(seqB, m));
  } else {
    printf("A sequência A é menor que a B.\n");
    printf("Soma de B: %.1f\n", soma(seqB, m));
    printf("Produto de A: %.1f\n", produto(seqA, n));
  }

  return EXIT_SUCCESS;
}

void lerVetor (float * vet, int n) {
  for (int i = 0; i < n; i++) {
    scanf("%f", &vet[i]);
  }
}

float produto (float * vet, int n) {
  int ret = 1;
  for (int i = 0; i < n; i++) {
    ret *= vet[i];
  }

  return ret;
}

float soma (float * vet, int n) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += vet[i];
  }

  return ret;
}