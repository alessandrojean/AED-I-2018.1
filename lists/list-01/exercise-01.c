#include <stdio.h>
#include <stdlib.h>

void lerVetor (int * vet, int n);
void acharSubsequencias (int * vet, int n, int k);
void imprimirSubsequencia (int * vet, int n);


int main(int argc, char **argv) {
  int m, k;
  printf("Digite o tamanho M: ");
  scanf("%d", &m);
  printf("Digite o tamanho máximo k da sub-sequência: ");
  scanf("%d", &k);
  
  // Leitura de inteiros no vetor.
  int vet[m];
  lerVetor(vet, m);

  // Acha todas as subsequências.
  printf("\nSubsequências:\n");
  acharSubsequencias(vet, m, k);

  return EXIT_SUCCESS;
}

void lerVetor (int * vet, int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }
}

void acharSubsequencias (int * vet, int n, int k) {
  int subsequencias[n][k];
  int ultimoNumero, cont = 0;

  for (int i = 0, v = n - 1; i < v; i++) {
    for (int j = 0; j < k; j++) {
      subsequencias[i][j] = vet[i + j];
      cont++;

      if (vet[i + j] + 1 != vet[i + j + 1]) {
        break;
      }      
    }

    if (cont > 1 && subsequencias[i][cont - 1] != ultimoNumero) {
      imprimirSubsequencia(subsequencias[i], cont);
      ultimoNumero = subsequencias[i][cont - 1];
    }
    cont = 0;
  }
}

void imprimirSubsequencia (int * vet, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}