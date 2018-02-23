#include <stdio.h>
#include <stdlib.h>

int * ocorrencias (char * str, char letra, int * n);
void mostrarVetor (int * vet, int n);

int main (int argc, char **argv) {
  char * str = "linguagem c\0";
  int n = 0, * indices = ocorrencias(str, 'g', &n);

  mostrarVetor(indices, n);

  return EXIT_SUCCESS;
}

int * ocorrencias (char * str, char letra, int * n) {
  int nStr;
  for (nStr = 0; str[nStr] != '\0'; nStr++);

  // Conta quantas ocorrências tem.
  for (int i = 0; i < nStr; *n += (str[i] == letra) ? 1 : 0, i++);

  // Aloca o vetor para listar as ocorrencias.
  int * indices = (int *) malloc(*n * sizeof(int));
  if (indices == NULL) {
    *n = 0;
    return NULL;
  }

  // Armazena as ocorrências.
  int p = 0;
  for (int i = 0; i < nStr; i++) {
    if (str[i] == letra) {
      indices[p++] = i;
    }
  }

  return indices;
}

void mostrarVetor (int * vet, int n) {
  printf("(");
  for (int i = 0; i < n; i++) {
    printf("%d%s", vet[i], (i == n - 1) ? ")\n" : ", ");
  }
}