#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};

LinkedNode * appendNode (LinkedNode * last, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}

void printListCircular (LinkedNode * first) {
  if (first == NULL)
    return;

  LinkedNode * curr = first;
  while (curr->next != first) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void removeLastCircular (LinkedNode ** first) {
  if (*first == NULL)
    return;

  // Se a lista só possui um elemento, remova-o.
  if ((*first)->next == *first) {
    free(*first);
    *first = NULL;
    return;
  }

  LinkedNode * curr = *first;
  for (; curr->next->next != *first; curr = curr->next);
  free(curr->next);
  curr->next = *first;
}

int main (int argc, char **argv) {
  LinkedNode * list = malloc(sizeof(LinkedNode));
  LinkedNode * last = list;

  list->data = 1;
  list->next = NULL;
  
  for (int i = 1; i < 11; i++) {
    // TODO: Verificar se o retorno não é NULL.
    last = appendNode(last, i + 1);
  }

  last->next = list;

  printListCircular(list);

  removeLastCircular(&list);

  printListCircular(list);

  return EXIT_SUCCESS;
}
