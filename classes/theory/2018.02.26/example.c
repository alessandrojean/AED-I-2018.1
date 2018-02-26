#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};

LinkedNode * appendNode (LinkedNode * last, int num) {
  if (last == NULL || last->next != NULL)
    return NULL;

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

int main (int argc, char **argv) {
  LinkedNode * first = malloc(sizeof(LinkedNode));
  LinkedNode * last = NULL;
  first->data = 5;
  first->next = NULL;
  last = first;

  LinkedNode * second = malloc(sizeof(LinkedNode));
  second->data = 6;
  second->next = NULL;
  first->next = second;
  last = second;

  LinkedNode * addedItem = appendNode(last, 9);
  if (addedItem != NULL)
    last = addedItem;

  appendNode(last, 46);
  last = last->next;

  printList(first);

  return EXIT_SUCCESS;
}
