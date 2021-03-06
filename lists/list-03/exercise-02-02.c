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

LinkedHead * createHead (int position) {
  LinkedHead * tmp = malloc(sizeof(LinkedHead));
  if (tmp == NULL)
    printError();

  tmp->position = position;
  tmp->next = NULL;
  tmp->first = NULL;

  return tmp;
}

LinkedNode * createNode (int line, int column, int data) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL) 
    printError();

  tmp->line = line;
  tmp->column = column;
  tmp->data = data;
  tmp->next = NULL;

  return tmp;
}

LinkedHead * createHeadWithNode (int line, int column, int data) {
  LinkedHead * tmpHead = createHead(line);
  LinkedNode * tmpNode = createNode(line, column, data);

  tmpHead->first = tmpNode;

  return tmpHead;
}

void setValue (LinkedHead ** matrix, int i, int j, int data) {
  if (*matrix == NULL)
    return;

  // Se não há nenhuma linha.
  if ((*matrix)->next == NULL) {
    LinkedHead * tmpHead = createHeadWithNode(i, j, data);
    (*matrix)->next = tmpHead;

    return;
  }

  LinkedHead * curr = (*matrix)->next, * prev = NULL;
  for (; curr != NULL && curr->position < i; prev = curr, curr = curr->next);

  // Significa que acabou a lista.
  if (curr == NULL) {
    LinkedHead * tmpHead = createHeadWithNode(i, j, data);
    prev->next = tmpHead;

    return;
  }

  // Senão, existe uma linha i, e é preciso
  // inserir o elemento nela.
  LinkedNode * currNode = curr->first, * prevNode = NULL;
  for (; currNode != NULL && currNode->column < j; prevNode = currNode, currNode = currNode->next);

  if (currNode == NULL) {
    LinkedNode * tmpNode = createNode(i, j, data);
    prevNode->next = tmpNode;

    return;
  }

  currNode->data = data;
}

int main (int argc, char **argv) {
  LinkedHead * head = createMatrix();

  setValue(&head, 0, 3, 5);
  setValue(&head, 1, 1, 9);
  setValue(&head, 2, 0, 4);
  setValue(&head, 2, 3, 6);
  setValue(&head, 4, 1, 7);

  return EXIT_SUCCESS;
}
