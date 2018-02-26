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

void printList (LinkedNode * first) {
  LinkedNode * curr = first;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void removeFirst (LinkedNode ** first) {
  if (first != NULL) {
    LinkedNode * next = (*first)->next;
    free(*first);
    *first = next;
  }
}

int main (int argc, char **argv) {
  LinkedNode * list = malloc(sizeof(LinkedNode));
  LinkedNode * last = list;

  list->data = 1;
  list->next = NULL;
  
  for (int i = 1; i < 10; i++) {
    // TODO: Verificar se o retorno não é NULL.
    last = appendNode(last, i + 1);
  }

  printList(list);

  removeFirst(&list);

  printList(list);

  return EXIT_SUCCESS;
}
