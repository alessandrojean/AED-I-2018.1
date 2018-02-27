#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  int line, column;
  LinkedNode * nextInColumn, * nextInLine;
};

typedef struct LinkedHead LinkedHead;
struct LinkedHead {
  int position;
  LinkedHead * next;
  LinkedNode * first;
};

// Para facilitar passar somente uma variável
// nos parâmetros das funções.
typedef struct SparseMatrix SparseMatrix;
struct SparseMatrix {
  LinkedHead * lines;
  LinkedHead * columns;
};

void printError(char * error) {
  fprintf(stderr, error);
  exit(1);
}

SparseMatrix * createMatrix () {
  SparseMatrix * matrix = malloc(sizeof(SparseMatrix));

  if (matrix == NULL)
    printError("Memória indisponível.\n");

  return matrix;
}

int main (int argc, char **argv) {
  SparseMatrix * matrix = createMatrix();  

  return EXIT_SUCCESS;
}
