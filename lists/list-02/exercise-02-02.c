#include <stdio.h>
#include <stdlib.h>

void preencher (int * vet, int n);
int * inserirNaPosicao (int * vet, int i, int e, int * n, int * t);
int * aumentarTamanho (int * vet, int * n, int m);
void mostrarVetor (int * vet, int n);

int main (int argc, char **argv) {
  int n = 3, t = 5;
  int * vet = (int *) malloc(t * sizeof(int));
  preencher(vet, 3);
  
  mostrarVetor(vet, n);
  vet = inserirNaPosicao(vet, 1, 6, &n, &t);
  mostrarVetor(vet, n);
  vet = inserirNaPosicao(vet, 1, 7, &n, &t);
  mostrarVetor(vet, n);
  vet = inserirNaPosicao(vet, 1, 8, &n, &t);
  mostrarVetor(vet, n);
  vet = inserirNaPosicao(vet, 8, 9, &n, &t);
  mostrarVetor(vet, n);

  return EXIT_SUCCESS;
}

void preencher (int * vet, int n) {
  for (int i = 0; i < n; i++) {
    vet[i] = i + 1;
  }
}

int * inserirNaPosicao (int * vet, int i, int e, int * n, int * t) {
  if (i > *t - 1 || (*n + 1 > *t)) {
    int w = (i > *t - 1) ? i + 1 - *t : 1;
    vet = aumentarTamanho(vet, t, *t + w);
    if (vet == NULL) {
      *n = 0;
      *t = 0;
      return NULL;
    }
  }

  // Se a posição para inserir é maior que o
  // número de elementos, preencher com zero
  // os elementos intermediários.
  if (i > *n) {
    vet[i] = e;

    for (int j = *n; j < i; j++) {
      vet[j] = 0;
    }

    *n = i + 1;
  } 
  // Senão, deslocar os elementos após a posição
  // em mais um no índice.
  else {
    for (int j = *t - 1; j >= i - 1; j--) {
      vet[j + 1] = vet[j];
    }

    vet[i] = e;
    (*n)++;
  }

  return vet;
}

int * aumentarTamanho (int * vet, int * n, int m) {
  int * nVet = (int *) malloc(m * sizeof(int));
  if (nVet == NULL) {
    *n = 0;
    return NULL;
  }

  for (int i = 0; i < *n; i++) {
    nVet[i] = vet[i];
  }

  free(vet);
  *n = m;

  return nVet;
}

void mostrarVetor (int * vet, int n) {
  printf("(");
  for (int i = 0; i < n; i++) {
    printf("%d%s", vet[i], (i == n - 1) ? ")\n" : ", ");
  }
}