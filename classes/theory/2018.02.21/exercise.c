#include <stdio.h>
#include <stdlib.h> // Para usarmos malloc, free etc.

int cmp (int * seq1, int * seq2, int n1, int n2);
int * dobrarSeq (int * seq, int * nseq);
int * lerSeq (int * n);
void printSeq (int * seq, int n);

int main (int argc, char ** argv) {
  int * seq1, * seq2;
  int n1, n2;

  printf("Entre com a primeira sequência:\n");
  seq1 = lerSeq(&n1);
  printSeq(seq1, n1);

  printf("\nEntre com a segunda sequência:\n");
  seq2 = lerSeq(&n2);
  printSeq(seq2, n2);

  int n = cmp(seq1, seq2, n1, n2);

  // Saída.
  switch (n) {
    case -1:
      printf("A primeira sequência é maior.\n");
      break;
    case 0:
      printf("As sequências são iguais.\n");
      break;
    case 1:
      printf("A segunda sequência é maior.\n");
      break;
  }

  free(seq1);
  free(seq2);

  return EXIT_SUCCESS;
}

int cmp (int * seq1, int * seq2, int n1, int n2) {
  int m = (n1 < n2) ? n1 : n2;
  for (int i = 0; i < m; i++) {
    if (seq1[i] != seq2[n2 - i - 1]) {
      return (seq1[i] > seq2[n2 - i - 1]) ? 1 : -1;
    }
  }

  return (n1 == n2) ? 0 : ((n1 > n2) ? 1 : -1);
}

// Crie uma versão usando realloc.
int * dobrarSeq (int * seq, int * nseq) {
  int * tmp = (int *) malloc(2 * (*nseq) * sizeof(int));
  if (tmp == NULL) {
    *nseq = 0;
    return NULL;
  }

  for (int i = 0; i < *nseq; i++) {
    tmp[i] = seq[i];
  }

  free(seq);
  *nseq *= 2;

  return tmp;
}

int * lerSeq (int * n) {
  *n = 2;                   // Começando em 2 para checar se funciona.

  int * seq = (int *) malloc((*n) * sizeof(int));

  if (seq == NULL) {        // Há memória disponível?
    *n = 0;
    return NULL;
  }

  scanf("%d", &seq[0]);
  scanf("%d", &seq[1]);

  int num;
  for (int i = 1; ; i++) {
    scanf("%d", &num);

    // Tente usar uma condição mais enxuta.
    if (num == 0 && seq[i] == 0 && seq[i - 1] == 0) {
      *n = i - 1;           // IMPORTANTE: Aqui o tamanho do vetor é i - 1,
                            // i - 2 que é o último elemento.
      return seq;
    }

    if (i == (*n) - 1) {    // Precisamos de mais espaço.
      seq = dobrarSeq(seq, n);
      // Tente usar uma condição mais enxuta.
      if (seq == NULL) {
        return NULL;
      }
    }

    seq[i + 1] = num;
  }
}

// Imprimindo bonitinho.
void printSeq (int * seq, int n) {
  printf("(");
  for (int i = 0; i < n; i++) {
    printf("%d%s", seq[i], (i == n - 1) ? ")\n" : ", ");
  }
}