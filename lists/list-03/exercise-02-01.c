#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  int line, column;
  LinkedNode * next;
};

typedef struct LinkedHead LinkedHead;
struct LinkedHead {
  int position;
  LinkedHead * next;
  LinkedNode * first;
};

void printError() {
  fprintf(stderr, "Memória indisponível.\n");
  exit(1);
}

LinkedHead * createMatrix () {
  LinkedHead * tmp = malloc(sizeof(LinkedHead));

  if (tmp == NULL)
    printError();

  tmp->next = NULL;
  tmp->first = NULL;
  tmp->position = -1;

  return tmp;
}

int main (int argc, char **argv) {
  LinkedHead * head = createMatrix();

  return EXIT_SUCCESS;
}
