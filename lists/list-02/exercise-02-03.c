#include <stdio.h>
#include <stdlib.h>

void preencher (int * vet, int n);
void mostrarVetor(int * vet, int n);
void dividir (int * vet, int ** vetPos, int ** vetNeg, int n, int * nPos, int * nNeg);

int main (int argc, char **argv) {
  int n = 10, nPos = 0, nNeg = 0;
  int * vet = NULL, * vetPos = NULL, * vetNeg = NULL;

  vet = (int *) malloc(n * sizeof(int));
  preencher(vet, n);
  mostrarVetor(vet, n);

  dividir(vet, &vetPos, &vetNeg, n, &nPos, &nNeg);
  mostrarVetor(vetPos, nPos);
  mostrarVetor(vetNeg, nNeg);

  return EXIT_SUCCESS;
}

void dividir (int * vet, int ** vetPos, int ** vetNeg, int n, int * nPos, int * nNeg) {
  // Conta quantos elementos positivos e
  // negativos o vetor possui.
  for (int i = 0; i < n; i++) {
    if (vet[i] > 0) (*nPos)++;
    else if (vet[i] < 0) (*nNeg)++;
  }

  *vetPos = (int *) malloc(*nPos * sizeof(int));
  *vetNeg = (int *) malloc(*nNeg * sizeof(int));

  if (*vetPos == NULL || *vetNeg == NULL) {
    *nPos = *nNeg = 0;
    return;
  }

  // Adiciona cada número em seu respectivo
  // vetor, seja positivo ou negativo.
  int iPos = 0, iNeg = 0;
  for (int i = 0; i < n; i++) {
    if (vet[i] > 0) (*vetPos)[iPos++] = vet[i];
    else if (vet[i] < 0) (*vetNeg)[iNeg++] = vet[i];
  }
}

void preencher (int * vet, int n) {
  for (int i = 0; i < n; i++) {
    vet[i] = (i & 1) ? i + 1 : - (i + 1);
  }
}

void mostrarVetor (int * vet, int n) {
  printf("(");
  for (int i = 0; i < n; i++) {
    printf("%d%s", vet[i], (i == n - 1) ? ")\n" : ", ");
  }
}